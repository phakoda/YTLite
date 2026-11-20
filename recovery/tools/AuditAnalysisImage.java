// Read-only audit: compare the analysis project's actual memory with the
// supplied package plus the explicitly recorded analysis-only modifications.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import com.google.gson.*;
import java.nio.file.*;
import java.util.*;

public class AuditAnalysisImage extends GhidraScript {
    long number(String value) { return Long.decode(value); }
    public void run() throws Exception {
        Path manifestPath = Paths.get(getScriptArgs()[0]);
        JsonObject manifest = JsonParser.parseString(Files.readString(manifestPath)).getAsJsonObject();
        byte[] original = Files.readAllBytes(Paths.get(manifest.get("binary").getAsString()));
        HashMap<Long, Byte> overrides = new HashMap<>();
        for (JsonElement value : manifest.getAsJsonArray("overrides")) {
            JsonObject entry = value.getAsJsonObject();
            long address = number(entry.get("address").getAsString());
            long word = Long.parseUnsignedLong(entry.get("word").getAsString().replace("0x", ""), 16);
            for (int offset = 0; offset < 4; offset++) overrides.put(address + offset, (byte)(word >> (offset * 8)));
        }
        long differences = 0, compared = 0;
        JsonArray examples = new JsonArray();
        for (JsonElement value : manifest.getAsJsonArray("sections")) {
            JsonObject section = value.getAsJsonObject();
            long base = number(section.get("address").getAsString());
            int size = section.get("size").getAsInt(), offset = section.get("file_offset").getAsInt();
            byte[] actual = new byte[size];
            currentProgram.getMemory().getBytes(toAddr(base), actual);
            for (int index = 0; index < size; index++) {
                byte expected = overrides.containsKey(base + index) ? overrides.get(base + index) : original[offset + index];
                compared++;
                if (expected == actual[index]) continue;
                differences++;
                if (examples.size() < 100) {
                    JsonObject example = new JsonObject();
                    example.addProperty("address", "0x" + Long.toHexString(base + index));
                    example.addProperty("original", original[offset + index] & 255);
                    example.addProperty("expected", expected & 255);
                    example.addProperty("actual", actual[index] & 255);
                    examples.add(example);
                }
            }
        }
        JsonObject report = new JsonObject();
        report.addProperty("program", currentProgram.getName());
        report.addProperty("executable_path", currentProgram.getExecutablePath());
        report.addProperty("recorded_sha256", currentProgram.getExecutableSHA256());
        report.addProperty("image_base", currentProgram.getImageBase().toString());
        report.addProperty("bytes_compared", compared);
        report.addProperty("bytes_differing", differences);
        report.add("examples", examples);
        JsonObject addresses = new JsonObject();
        for (String name : new String[] {"FUN_0002b3ac", "FUN_00028ec0", "thunk_FUN_000333a8", "FUN_000333a8", "DAT_011563a8", "DAT_01159228"}) {
            JsonArray values = new JsonArray();
            for (ghidra.program.model.symbol.Symbol symbol : currentProgram.getSymbolTable().getSymbols(name)) {
                values.add(symbol.getAddress().toString());
            }
            addresses.add(name, values);
        }
        report.add("named_symbol_addresses", addresses);
        JsonArray calls = new JsonArray();
        for (long pc : new long[] {0x289a4, 0x289e4, 0x28afc, 0x238f0, 0x23980}) {
            ghidra.program.model.listing.Instruction instruction = currentProgram.getListing().getInstructionAt(toAddr(pc));
            JsonObject call = new JsonObject();
            call.addProperty("address", "0x" + Long.toHexString(pc));
            call.addProperty("instruction", instruction == null ? "missing" : instruction.toString());
            JsonArray flows = new JsonArray();
            if (instruction != null) {
                for (Address destination : instruction.getFlows()) {
                    JsonObject flow = new JsonObject();
                    flow.addProperty("address", destination.toString());
                    ghidra.program.model.symbol.Symbol symbol = currentProgram.getSymbolTable().getPrimarySymbol(destination);
                    flow.addProperty("name", symbol == null ? "none" : symbol.getName());
                    flows.add(flow);
                }
            }
            call.add("flows", flows);
            calls.add(call);
        }
        report.add("decoded_calls", calls);
        Path output = manifestPath.resolveSibling("analysis-image-audit.json");
        Files.writeString(output, new GsonBuilder().setPrettyPrinting().create().toJson(report) + "\n");
        println(report.toString());
        if (differences != 0) throw new IllegalStateException("Analysis image differs from the expected original+patches; do not use its exports.");
    }
}
