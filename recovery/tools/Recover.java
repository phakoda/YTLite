// Ghidra headless exporter. Output is decompiler evidence, not compilable source.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.util.*;
import com.google.gson.*;

public class Recover extends GhidraScript {
    public void run() throws Exception {
        File out = new File(getScriptArgs()[0]);
        long rangeStart = getScriptArgs().length >= 3 ? Long.decode(getScriptArgs()[1]) : 0;
        long rangeEnd = getScriptArgs().length >= 3 ? Long.decode(getScriptArgs()[2]) : 0x280000L;
        out.mkdirs();
        Set<Long> methodAddresses=new HashSet<>();
        JsonArray classes=JsonParser.parseString(Files.readString(out.toPath().getParent().resolve("evidence/arm-classes.json"))).getAsJsonArray();
        for(JsonElement cls:classes) for(JsonElement method:cls.getAsJsonObject().getAsJsonArray("methods"))
            methodAddresses.add(Long.parseLong(method.getAsJsonObject().get("address").getAsString().substring(2),16));
        Path hooksPath=out.toPath().getParent().resolve("evidence/hooks.json");
        if(Files.exists(hooksPath)) for(JsonElement item:JsonParser.parseString(Files.readString(hooksPath)).getAsJsonArray()) {
            String value=item.getAsJsonObject().get("implementation").getAsString();
            if(!value.startsWith("0x"))continue;
            long addr=Long.parseLong(value.substring(2),16);
            if(getFunctionAt(toAddr(addr))==null) {
                disassemble(toAddr(addr));
                createFunction(toAddr(addr),String.format("recovered_hook_%08x",addr));
            }
        }
        // The binary has many compiler-generated call/return wrappers. Tell the
        // decompiler their targets so calls resolve to useful method/import names.
        int wrappers = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (f.isExternal() || f.isThunk() || f.getBody().getNumAddresses() != 16) continue;
            Instruction a = getInstructionAt(f.getEntryPoint());
            if (a == null || !a.getMnemonicString().equals("stp")) continue;
            Instruction b = a.getNext(), c = b == null ? null : b.getNext(), d = c == null ? null : c.getNext();
            if (b == null || c == null || d == null || !b.getMnemonicString().equals("bl") || !c.getMnemonicString().equals("ldp") || !d.getMnemonicString().equals("ret")) continue;
            for (Reference ref : b.getReferencesFrom()) if (ref.getReferenceType().isCall()) {
                Function target = getFunctionAt(ref.getToAddress());
                if (target != null && target != f) {
                    try { f.setThunkedFunction(target); wrappers++; } catch (IllegalArgumentException ignored) {}
                }
            }
        }
        println("Resolved " + wrappers + " call wrappers");
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        int count = 0;
        try (PrintWriter index = new PrintWriter(new File(out, "index.tsv"))) {
            index.println("address\tname\tbytes\tstatus\tfile");
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                if (monitor.isCancelled()) break;
                long addr = f.getEntryPoint().getOffset();
                if (addr < rangeStart || addr >= rangeEnd) continue;
                // The first-party Objective-C implementation precedes bundled codecs.
                // Export all substantial functions in this range, including anonymous blocks.
                if (addr >= 0x280000L || f.isExternal() || (f.isThunk() && !methodAddresses.contains(addr))) continue;
                Instruction first=getInstructionAt(f.getEntryPoint());
                boolean boolWrapper=f.getBody().getNumAddresses()==20 && first!=null && first.getMnemonicString().equals("stp") && first.getNext()!=null && first.getNext().getMnemonicString().equals("bl") && first.getNext().getNext()!=null && first.getNext().getNext().getMnemonicString().equals("and");
                if(boolWrapper && !methodAddresses.contains(addr)) continue;
                String filename = String.format("%08x.c", addr);
                DecompileResults result = decompiler.decompileFunction(f, 45, monitor);
                boolean ok = result.decompileCompleted();
                index.printf("%x\t%s\t%d\t%s\t%s%n", addr, f.getName(), f.getBody().getNumAddresses(), ok ? "ok" : result.getErrorMessage().replace('\n',' '), filename);
                if (ok) try (PrintWriter w = new PrintWriter(new File(out, filename))) {
                    w.printf("/* Decompiled from supplied 5.2.2 arm package. VA 0x%x. %s */%n", addr, f.getName());
                    w.println(result.getDecompiledFunction().getC());
                }
                else Files.deleteIfExists(new File(out,filename).toPath());
                index.flush();
                if (++count % 100 == 0) println("Exported " + count + " functions, through " + f.getEntryPoint());
            }
        } finally { decompiler.dispose(); }
        println("Export complete: " + count);
    }
}
