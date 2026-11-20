# YTPDiscordRPC recovery

`YTPDiscordRPC.h/.m` reconstruct all 16 runtime methods (including synthesized accessors and ARC destruction), two properties, and four ivars of the supplied 5.2.2 class. The implementation uses the existing canonical `RPCMedia`, `YTLUserDefaults` and `NSString (YTLite)` implementations. The only YouTube contract is a protocol for the dynamically looked-up `YTAlertView`; no YouTube host class is implemented here.

`manifest.json` records the original binary SHA-256, every method address/encoding, seven anonymous callback addresses, the original instruction interval hash, six verified branch tables, and six decoded strings. The later analysis-v3 exports are used as reading aids. Branch tails still unresolved by that export were recovered directly from the original ARM64 bytes:

- `0x21c4a0`: the permission result block captures self, defaults, and the requested address at offsets 0x20/0x28/0x30. Table `0x11cdd30` selects startup only when both callback booleans are true. The remaining tables select the permission dialog first, then the missing-server dialog unless `rpcNoServerAlerts` is true.
- `0x21e488`: table `0x11cdfc8` selects whether to add the settings action. Both paths add a literal, unlocalized `OK` button with a nil action, then show the dialog. Settings action `0x21ea18` opens `UIApplicationOpenSettingsURLString` with empty options and a nil completion.
- `0x21dc68`: original `fcmp` / `cset mi` at `0x21dd6c..0x21dd70` suppresses a send when the elapsed time is less than one second. A nil last-send date sends immediately; the date is stored before `_send:`. Exact one-second boundary sends.
- `0x21d340`: the nil-field fallback loaded at `0x21d9a8..0x21d9ac` is the verified empty CFString at `0x113acf0`. Current/total times are boxed doubles. The body contains exactly seven keys.

Other callback provenance: `0x21b54c` creates the singleton; `0x21b744` classifies network errors; `0x21b8f4` invokes the two-BOOL permission callback on the main queue; `0x21cce0` sends after startup delay; `0x21e234` logs POST errors.

Preserved package behavior includes several unusual details:

- HTTPS addresses are rewritten to HTTP. Missing port becomes 5001. Missing, empty, or `/` path becomes `/update`; custom paths, ports, queries and fragments survive Foundation normalization.
- `startIfPossible` probes the shared presence object's existing URL before assigning the captured `rpcAddress`. There is no default URL initialization in this class. An unset existing URL can cause Foundation request construction to raise; this reconstruction does not invent a fallback.
- Only error -1009 is classified as denied local permission. Error -1004 is classified as an unavailable server. Other errors, including timeouts, produce `(YES, YES)` and allow startup; response body/status are ignored.
- New video startup stores the current ID, clears the throttle date, and schedules a main-queue callback after one second. That callback reads the latest ID rather than a captured ID, clears `isPaused`, and sends. Multiple startup callbacks can survive video changes; the send throttle suppresses duplicates.
- `clearPlayback` acts only when media exists and sends the one-key stopped body immediately. `_send:` is a five-second JSON POST. Errors are logged; there is no retry or response parsing.

The obfuscator's supervisor calls and constant initialization machinery are excluded. They are not media/RPC logic. No endpoint, account token, authorization bypass or alternate transport is introduced.

Run `python3 recovery/tools/verify_discord.py`. It verifies original-byte provenance, compiles the production source against Apple's iOS SDK, checks all packaged method/property/ivar metadata, and executes 166 runtime assertions with undefined-behavior sanitization. Tests compile the actual source and canonical RPCMedia implementation. All NSURLSession calls are intercepted before any transport task can be created; request construction and JSON encoding/decoding use real Foundation. Dispatch scheduling and wall-clock dates are deterministic test boundaries. Preference gates, permission outcomes, captured-address timing, body fields, throttle boundaries, startup replacement/clear ordering, error handling and dialog actions are exercised. No supplied binary is executed and no live network request is sent.

Integration requires adding `Discord/YTPDiscordRPC.m` to the shared source list and connecting the recovered YouTube hooks that supply media and call start/update/clear methods. This class alone does not install those hooks. Device UI and a real desktop companion exchange remain untested; source reconstruction and offline behavior tests do not establish end-to-end device compatibility.
