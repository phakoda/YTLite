#pragma once
#ifdef __cplusplus
extern "C" {
#endif
// Packaged libroot compatibility entry points 0x8000..0x8118. A null output
// requests a malloc-owned 1024-byte buffer, which the caller must free.
const char *YTLRootPrefix(void);
const char *YTLJailbreakPrefix(void);
const char *YTLBootUUID(void);
char *YTLRootFSPath(const char *path, char *output);
char *YTLJailbreakPath(const char *path, char *output);
#ifdef __cplusplus
}
#endif
