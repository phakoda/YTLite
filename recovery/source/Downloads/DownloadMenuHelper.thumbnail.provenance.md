# Thumbnail background write

This audit targets `getThumbnail:` in the first supplied `iphoneos-arm64e`
package. Run:

```sh
python3 recovery/tools/verify_first_menu_thumbnail.py
```

The original dylib is parsed as data and never executed. The fixture compiles the
actual recovered source, captures its queued block at the dispatch boundary, and
replaces the network read with supplied bytes. It performs a real Foundation
write under `.recovery-work/first-menu-thumbnail/` for the successful case.

## Recovered behavior

The method at `0x1069c0` selects the supported player-response getter and returns
for a nil response. Otherwise it queues its captured response on the default
global queue. Its block at `0x106b94` reads and retains `videoID` before fetching
player data, video details and the final thumbnail entry. It builds a URL from
that entry's URL string and synchronously reads data. A nil result stops before
any temporary-directory or file-manager work.

For nonnil data, it gets `NSTemporaryDirectory()` before calling
`NSFileManager.defaultManager` to check that path and its directory flag. If the
path is absent or is not a directory, it fetches the default manager again and
attempts to create the temporary root with intermediate directories, nil
attributes and an error pointer. A returned error is logged. The write proceeds
regardless of the creation result or error.

The destination is formed by appending the formatted component
`%@/thumbnail.webp`, using the earlier video ID, to the temporary root. The code
creates a file URL and calls `writeToURL:atomically:YES`. It does not create the
video subdirectory and does not inspect the write's return value.

The preceding reconstruction read the ID after fetching bytes, cached the file
manager before getting the temporary path, reused it for creation, created an
extra video subdirectory and called `writeToFile:atomically:`. Those differences
are corrected. The general downloads fixture now explicitly creates the video
parent as a prerequisite, rather than relying on the invented directory creation.

## Evidence and verification

The manifest pins the method, queued block and wrappers. It checks two decoded
CFStrings, 20 adjacent selector loads, three filesystem decision tables and 117
direct calls. The original system-trap instructions at `0x106b7c` and `0x107340`
remain omitted. Response-selection and constant-initialization branches are
pinned by the body hashes but are not individually decoded in this verifier.

The fixture runs 147 checks across all existence/directory/error combinations,
ID replacement during the URL getter, deferred execution, final-thumbnail
selection, fresh manager dispatch, nil bytes, missing video parents and a real
successful byte-preserving write. Four isolated reverted behaviors must fail.
The old implementation failed 64 checks in the initial fixture.

The fake directory manager controls its return flags and error object; it does
not model an actual root-directory creation failure. The dispatch boundary runs
the callback under test control rather than testing system scheduling. Full
response-capture lifetime, concurrent mutations, real HTTP fetching, downstream
thumbnail embedding and device behavior remain outside this audit. Omitted
system effects remain a fidelity difference, so this is not full package parity.
