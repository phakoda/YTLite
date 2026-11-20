# Speed control view

All 12 packaged methods and four relative ivar layouts are implemented. The actual source fixture covers construction, the step and preset buttons, hierarchy and constraints, slider/tap/step/preset actions, label/playback forwarding, the thumb drawing block and ARC cleanup. UIKit objects and playback are test doubles; CoreGraphics executes the actual drawing block in a bitmap context.

The behavioral audit corrected five reconstruction errors against original instructions:

- `speedControls` allocates the concrete `YTPSpeedControlView` class even when invoked on a subclass. Original `0x23836c` loads the class reference before allocation.
- Slider step counts use single-precision `FRINTA`, rounding to nearest with ties away from zero. The older decompiler prints integer casts, which incorrectly led to truncation. Original instructions at `0x239b28`, `0x239c34`, `0x239cf0` and `0x239da4` all encode `FRINTA s0,s0`. `ControlsNumbers.h` now uses `roundf`.
- Slider taps use fused single-precision multiply-add at `0x239c20`, after double division and narrowing the position ratio to float. The two `minimumValue` reads are retained separately.
- Minus and plus use different `FCSEL` operand orders after comparing the limit with the candidate. Minus selects the minimum when the comparison is unordered; plus retains the candidate. The source preserves these NaN and signed-zero details through the corresponding strict comparisons.
- Preset tags multiply the second `floatValue` result by 100 in single precision, then perform signed 64-bit truncating conversion. Original `0x239a34` is `FMUL s0,s8,s0`; `0x239a38` is `FCVTZS x2,s0`. This differs from multiplying in double precision before conversion.

The five default presets are double-valued NSNumber objects containing 1, 2, 3, 5 and 10. The private step starts with raw float bits `0x3d4ccccd`, approximately 0.05. UI dimensions, colors, event constants, two independent playback-rate reads and constraint order follow the original methods. The renderer's global block at `0x239344` creates the white circular thumb with its original shadow parameters.

Run `python3 recovery/tools/verify_speed_control.py`. It pins critical original words and records all 12 method intervals plus the drawing block. It checks the iOS ABI and runs 1,864 actual-source assertions under UndefinedBehaviorSanitizer. Newly compiled, isolated ARM64 arithmetic sequences provide independent expected values for rounding, fused arithmetic, selection and tag conversion. They do not load or execute the supplied binary. The original truncation and subclass-factory versions both produced recorded failures before correction.

The fixture records forwarded slider values without claiming to reproduce UIKit's internal clamping. Full UIKit layout, touch delivery, visual rendering in YouTube and on-device playback remain outside this test. Obfuscator initialization and anti-debug supervisor calls are omitted consistently with the rest of this reconstruction.
