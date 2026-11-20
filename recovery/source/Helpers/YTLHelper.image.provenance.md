# Helper image download fidelity

`downloadImageFromURL:download:` starts at `0x230a44`. Its URL transformation
reads `absoluteString` once, calls `containsString:` at `0x230c0c`, and only then
calls `rangeOfString:` at `0x230c60` when the contains result is true. A missing
range after that positive result selects nil at `0x230d1c`. Otherwise, it replaces
the substring from the crop marker with `nd-v1`. The negative contains branch
preserves the original URL object. Every branch reaches the URL session and
task resume, including nil input; there is no early toast error.

The network completion at `0x230ddc` tests data presence before inspecting the
captured download flag. Nonnil data takes precedence over an accompanying error,
and zero-length data follows the same branch as other nonnil data. Copying queues
the callback at `0x231550`, which decodes the data, sets the pasteboard image and
shows copied feedback. The download branch immediately creates a Photos change
transaction. The changes callback at `0x23102c` forwards the original raw data.

The Photos completion at `0x2310a0` queues main-thread feedback at `0x231144`.
Failure uses a localized format string and error prefix. Network failure queues
`0x231730`, which uses the literal format with a localized error prefix. Nil error
descriptions retain normal Objective-C `%@` formatting in both paths. The existing
callback code already matched these branches and remains unchanged.

`helper_image_runtime.m` executes the complete reconstructed helper with synthetic
URL/string objects whose contains and range results vary independently. It checks
selector order, original URL identity, replacement arguments, nil session inputs,
task resume, data/error precedence, empty data, dispatch and raw Photos data.
The synthetic session accepts nil to record the attempted call; the test does not
assert that a real URL session accepts nil or performs a request with it.

Seven original function intervals, four functional branch tables and selector
references are pinned in `recovery/evidence/helper-image-fidelity.json`. The prior
reconstruction fails the URL-identity regression; its source, transform header,
failed report and output are preserved under `.recovery-work/helper-image/before-*`.
Run:

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_helper_media.py --image
```

The runtime verifier snapshots production and fixture headers before compilation
and checks them again after compilation and execution, including the transform
header containing this URL logic. No packaged binary, real network request,
Photos import or system pasteboard operation is executed. Device behavior and
download file-path validation remain outside this audit.
