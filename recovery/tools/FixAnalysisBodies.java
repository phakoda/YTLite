// Analysis-only repair. Synthetic branch islands are parts of their original
// functions, not tail-called functions. Original Mach-O LC_FUNCTION_STARTS,
// rather than Ghidra's post-obfuscation guesses, define the source boundaries.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import com.google.gson.*;
import java.nio.file.*;
import java.util.*;

public class FixAnalysisBodies extends GhidraScript {
    long number(String text) { return Long.parseUnsignedLong(text.replace("0x", ""), 16); }
    public void run() throws Exception {
        Path root = Paths.get(getScriptArgs()[0]);
        JsonObject layout = JsonParser.parseString(Files.readString(root.resolve("function-layout.json"))).getAsJsonObject();
        JsonArray functions = layout.getAsJsonArray("functions");
        HashSet<Long> entries = new HashSet<>();
        for (JsonElement value : functions) entries.add(number(value.getAsJsonObject().get("start").getAsString()));
        FunctionManager manager = currentProgram.getFunctionManager();
        ArrayList<Address> remove = new ArrayList<>();
        JsonArray removed = new JsonArray();
        for (Function function : manager.getFunctions(true)) {
            long pc = function.getEntryPoint().getOffset();
            if ((pc >= 0x8000 && pc < 0x280000 && !entries.contains(pc)) || (pc >= 0x4000000 && pc < 0x4010000)) {
                remove.add(function.getEntryPoint());
                JsonObject item = new JsonObject();
                item.addProperty("address", "0x" + Long.toHexString(pc));
                item.addProperty("name", function.getName());
                removed.add(item);
            }
        }
        for (Address entry : remove) manager.removeFunction(entry);
        // Shrink first to avoid collisions with previously overgrown bodies.
        for (Long value : entries) {
            Function function = getFunctionAt(toAddr(value));
            if (function != null) function.setBody(new AddressSet(function.getEntryPoint()));
        }
        int repaired = 0;
        for (JsonElement value : functions) {
            monitor.checkCancelled();
            JsonObject spec = value.getAsJsonObject();
            Address entry = toAddr(number(spec.get("start").getAsString()));
            Address end = toAddr(number(spec.get("end").getAsString()) - 1);
            AddressSet body = new AddressSet(entry, end);
            for (JsonElement islandValue : spec.getAsJsonArray("islands")) {
                JsonObject island = islandValue.getAsJsonObject();
                Address begin = toAddr(number(island.get("start").getAsString()));
                Address last = begin.add(island.get("bytes").getAsInt() - 1);
                body.addRange(begin, last);
                disassemble(begin);
            }
            for (Instruction instruction : currentProgram.getListing().getInstructions(body, true)) {
                if (instruction.getFlowOverride() != FlowOverride.NONE) instruction.setFlowOverride(FlowOverride.NONE);
            }
            disassemble(entry);
            Function function = getFunctionAt(entry);
            if (function == null) function = manager.createFunction("FUN_" + entry.toString(), entry, new AddressSet(entry), SourceType.ANALYSIS);
            function.setBody(body);
            setPlateComment(entry, "Recovery analysis: original LC_FUNCTION_STARTS boundary; synthetic branch islands are owned by this function. See function-layout.json.");
            repaired++;
        }
        JsonObject report = new JsonObject();
        report.addProperty("repaired_functions", repaired);
        report.add("removed_false_function_entries", removed);
        Files.writeString(root.resolve("function-body-repair.json"), new GsonBuilder().setPrettyPrinting().create().toJson(report) + "\n");
        println("Repaired " + repaired + " original function bodies; removed " + removed.size() + " false/synthetic function entries.");
    }
}
