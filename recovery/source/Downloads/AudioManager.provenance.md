# Audio manager recovery against the first package

`AudioManager` now constructs its resource URL before allocating `AVAudioPlayer`.
The first binary calls `fileURLWithPath:` at `0x1cef48`, allocates the player at
`0x1cef60`, initializes it at `0x1cef78` and sends the result to `setAudioPlayer:`
at `0x1cefa4`. The previous nested expression allocated the player before calling
the URL factory. Splitting out the URL restores this observable order.

The remaining source behavior agrees with the inspected first-package paths:

- `+sharedInstance` at `0x1ce700` captures the receiving class. Its once block at
  `0x1ce7b4` allocates and initializes that class, storing the result at
  `0x1227cb0`. Token `0x1227cb8` prevents retries even when initialization returns
  nil. Subclasses share the same stored instance.
- `-init` at `0x1ce7f8` calls the superclass initializer and configures the audio
  session for playback with option 1. The category's BOOL result is ignored.
  Its NSError is logged when present and then passed into player initialization.
  The later NSError content decides success, after the player setter is called.
  A player initializer can leave, replace or clear the category error.
- Resource lookup uses `SponsorAudio.m4a`. Nil bundle, resource path, URL and
  player results are forwarded without adding guards. On success, separate
  `audioPlayer` reads precede delegate assignment and `prepareToPlay`.
- `-playAudio` at `0x1cf0dc` reads the current player's playing state, then reads
  the property again before playing if it was stopped. `-stopAudio` at
  `0x1cf1bc` reads the property separately for the predicate, stop and rewind.
  A stopped player is not rewound. Rewind sets zero seconds.
- The finish callback at `0x1cf2cc` has no application operation after excluding
  its system trap. The getter at `0x1cf2e8`, setter at `0x1cf2f0` and destructor
  at `0x1cf2fc` use a strong player ivar at offset 8.

## Verification

Run `python3 recovery/tools/verify_first_audio_manager.py`.

The verifier reads the supplied first DEB as data, checks its archive and binary
hashes, and pins the complete class bodies and intervening wrappers at
`0x1ce700..0x1cf6e8`. It verifies four decoded strings, 18 adjacent selector loads,
121 direct calls, seven branch tables, 18 instruction words, the audio-session
category import and the runtime entry points used by the wrappers.

The actual reconstructed class passes 643 assertions across a main fixture and
three separate singleton processes. Tests cover initialization order, all
category/player NSError replacement combinations independently of the category
BOOL, nil host results, fresh player reads, playback gates, strong ownership,
receiving-class selection, shared subclass instances and permanent nil singleton
results. The initial fixture, after correcting its missing resource-root setup,
reported one production mismatch among 551 checks: URL/allocation ordering.

Ten compiled regressions must fail: early player allocation, cleared category
error, early return on a category error, direct ivar assignment, cached player
reads during initialization, play or stop, unconditional rewind, a finish
callback that stops playback, and singleton retries. iOS compilation separately
checks all eight method encodings, the strong property attributes and ivar layout
on arm64 and arm64e.

The fixture replaces AVFoundation, resource and URL factories. It does not play
audio or execute the original dylib. Superclass-initializer failure and exact
temporary object lifetimes are not tested. Two original system traps remain
omitted. Audio-session behavior on a device and concurrent playback remain
unverified, so this audit does not establish complete package parity.
