# Helper media presentation fidelity

This audit covers `saveMedia:`, `shareMedia:` and `askForAction:` with their
Photos, activity and action callbacks. The original image is pinned by
`recovery/evidence/helper-media-fidelity.json`. Nine complete original intervals
and two functional branch tables are checked by `verify_helper_media.py`.

`shareMedia:` at `0x22e4ac` allocates an activity controller before constructing
the one-element URL array. There is no nil guard or dispatch wrapper. The array
therefore retains its original exception for nil. The popover branch at
`0x22e79c` skips all geometry work when the first popover getter returns nil.
Otherwise, four independent getter calls serve the test, source view, source
rectangle and arrows. The screen width comes from the bounds call at `0x22e824`;
height comes from the second call at `0x22e850`. Completion at `0x22e960` invokes
`cleanup` directly regardless of success, cancellation, items or error.

`askForAction:` at `0x22eb5c` builds both actions and presents synchronously.
Its source view comes from the delegate window's root and pivot controller,
through the calls at `0x22f578` through `0x22f5fc`. There is no scene-window
fallback. A nil URL is still captured and forwarded by the action callbacks at
`0x22f6ac` and `0x22f6e8`.

`saveMedia:` at `0x22df30` branches on the `m4a` extension and forwards that case
to sharing. Other values, including nil, enter the Photos transaction. Its
completion at `0x22e1f0` always queues the main callback at `0x22e278`. Success
cleans up and shows saved feedback; failure forwards to sharing. This genuine
main dispatch remains intact.

`helper_media_runtime.m` executes the complete reconstructed helper. It replaces
getters only on the synthetic UIKit classes to return distinct popovers and
screen sizes. It also calls the methods from a real worker thread, tests both
activity completion results, and verifies nil behavior at the framework boundary.
No Photos transaction with a nil URL is executed. Other shared tests exercise
Photos success/failure and ordinary save/share/action routing.

The preceding source fails the original getter-order assertion. Its source,
failed report and output are retained under `.recovery-work/helper-media/before-*`.
Run these commands in order:

```sh
python3 tools/verify_presentation_runtime.py
python3 tools/verify_presentation_sources.py
python3 recovery/tools/verify_helper_media.py
```

These checks establish the documented source paths against static packaged
evidence. They do not establish UIKit rendering, real Photos behavior or live
YouTube integration. Download-path validation remains a reconstruction difference;
the later rendering audit is documented in `YTLHelper.rendering.provenance.md`.
