// Apply reversible analysis annotations. This never modifies the input package.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import ghidra.app.cmd.function.CreateFunctionCmd;
import com.google.gson.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class Improve extends GhidraScript {
    long number(String s) { return Long.parseUnsignedLong(s.replace("0x", ""),16); }
    public void run() throws Exception {
        Path root=Paths.get(getScriptArgs()[0]);
        JsonArray initializers=JsonParser.parseString(Files.readString(root.resolve("initializers.json"))).getAsJsonArray();
        Map<Long,Integer> folded=new HashMap<>();
        for(JsonElement item:initializers) {
            JsonObject p=item.getAsJsonObject();
            folded.put(number(p.get("address").getAsString()),(int)number(p.get("replacement").getAsString()));
        }
        JsonArray patches=JsonParser.parseString(Files.readString(root.resolve("branches.json"))).getAsJsonArray();
        if (currentProgram.getMemory().getBlock(toAddr(0x4000000))==null) {
            MemoryBlock b=currentProgram.getMemory().createInitializedBlock("recovery_branch_islands",toAddr(0x4000000),0x10000,(byte)0,monitor,false);
            b.setExecute(true);
        }
        for (JsonElement item:patches) {
            JsonObject p=item.getAsJsonObject();
            Address addr=toAddr(number(p.get("address").getAsString()));
            JsonArray old=p.getAsJsonArray("original"), replacement=p.getAsJsonArray("replacement");
            for(int i=0;i<old.size();i++) {
                int actual=getInt(addr.add(i*4));
                long delta=((long)(actual&0x3ffffff)<<38)>>36;
                long priorTarget=addr.getOffset()+delta;
                boolean priorIsland=(actual&0xfc000000)==0x14000000 && priorTarget>=0x4000000 && priorTarget<0x4010000;
                if(actual!=(int)number(old.get(i).getAsString()) && actual!=(int)number(replacement.get(i).getAsString()) && !Objects.equals(actual,folded.get(addr.getOffset())) && !priorIsland) throw new Exception("Original bytes differ at "+addr);
            }
            clearListing(addr,addr.add(replacement.size()*4-1));
            for(int i=0;i<replacement.size();i++) setInt(addr.add(i*4),(int)number(replacement.get(i).getAsString()));
            if(p.has("island")) {
                Address island=toAddr(number(p.get("island").getAsString()));
                JsonArray words=p.getAsJsonArray("island_words");
                clearListing(island,island.add(words.size()*4-1));
                for(int i=0;i<words.size();i++) setInt(island.add(i*4),(int)number(words.get(i).getAsString()));
            }
            setEOLComment(addr,"Recovery: resolved original indirect branch; both outcomes retained. See branches.json.");
        }
        List<String> byteLines=Files.readAllLines(root.resolve("decoded-bytes.tsv"));
        for(String line:byteLines.subList(1,byteLines.size())) {
            String[] fields=line.split("\t");
            setByte(toAddr(number(fields[0])),(byte)number(fields[1]));
        }
        for(JsonElement item:initializers) {
            JsonObject p=item.getAsJsonObject();
            Address addr=toAddr(number(p.get("address").getAsString()));
            clearListing(addr,addr.add(3));
            setInt(addr,(int)number(p.get("replacement").getAsString()));
            setEOLComment(addr,"Recovery analysis after constant string initialization. All byte stores recorded in decoded-bytes.tsv.");
        }
        JsonArray strings=JsonParser.parseString(Files.readString(root.resolve("decoded-strings.json"))).getAsJsonArray();
        for(JsonElement item:strings) {
            JsonObject p=item.getAsJsonObject();
            Address addr=toAddr(number(p.get("address").getAsString()));
            byte[] bytes=(p.get("value").getAsString()+"\0").getBytes(StandardCharsets.UTF_8);
            clearListing(addr,addr.add(bytes.length-1));
            setBytes(addr,bytes);
            try { createAsciiString(addr,bytes.length); } catch(Exception ignored) {}
            setPlateComment(addr,"Recovered runtime-decoded bytes. Instruction provenance: decoded-strings.json");
        }
        // Regenerate first-party function bodies after adding their branch edges.
        ArrayList<Address> entries=new ArrayList<>();
        for(Function f:currentProgram.getFunctionManager().getFunctions(true)) {
            if(f.getEntryPoint().getOffset()>=0x280000L) break;
            if(!f.isThunk() && f.getBody().getNumAddresses()>24) entries.add(f.getEntryPoint());
        }
        for(JsonElement item:patches) disassemble(toAddr(number(item.getAsJsonObject().get("address").getAsString())));
        for(Address addr:entries) {
            Function f=getFunctionAt(addr);
            if(f!=null) {
                AddressSetView body=CreateFunctionCmd.getFunctionBody(currentProgram,addr,monitor);
                try { f.setBody(body); } catch(Exception ignored) {}
            }
        }
        println("Applied "+patches.size()+" branch resolutions and "+strings.size()+" decoded strings.");
    }
}
