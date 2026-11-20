# SponsorBlock player lifecycle

The module reconstructs all five `YTPlayerViewController` registrations in the immediate initializer at `0x1efd4`. The manifest records both associated-property accessors and three replacement callbacks. It also pins six preference wrapper chains to `_ytpBool`.

Activation calls the saved original first. It creates a new `SBPlaybackController` only when the resulting player state is not an advertisement, SponsorBlock is enabled, and either feed playback is enabled or the parent is a `YTWatchViewController`. If any condition fails, the existing associated controller is retained. The code does not clear it or issue another segment request directly.

Both time callbacks call the original first, then ask the associated controller to skip segments when SponsorBlock is enabled. The ordinary callback uses `sbDuration`; the potentially mutated callback uses `sbDurationLabel`. Those are distinct strings in the supplied binary. Duration decoration may still run when the associated controller is nil. Both callbacks forward their incoming object arguments unchanged.

The property is retained and nonatomic. Its getter is the associated-object key in the packaged implementation; pinned Logos generates the same association scheme. The `YTWatchViewController` check accepts subclasses. Host superclass declarations here describe only messages used by this module and do not implement or replace host classes.

Run `python3 recovery/tools/verify_sponsor_playback.py`. All five original instruction ranges, wrapper terminals and emitted iOS callback signatures are checked. The actual generated Logos module passes 313 runtime assertions under UBSan, covering original forwarding, operation order, all eligibility gates, parent subclasses, both distinct duration keys, nil controllers, associated-object retention and per-player isolation. Fixtures replace the SponsorBlock class boundaries, so tests make no network requests and execute none of the supplied binary.

`YTLInstallSponsorPlaybackHooks` exposes the immediate registration sequence without adding a constructor. The parent recovery owns installation timing and its relationship to the Discord and primary player layers. The selected local preference policy remains a documented difference from the historical account gate.
