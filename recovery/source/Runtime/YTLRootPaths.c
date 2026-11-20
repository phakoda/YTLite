#include "YTLRootPaths.h"
#include <dispatch/dispatch.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef const char *(*PrefixFunction)(void);
typedef char *(*PathFunction)(const char *, char *);
static PrefixFunction rootPrefix, jailbreakPrefix, bootUUID;
static PathFunction rootFSPath, jailbreakPath;
static dispatch_once_t onceToken;

// 0x82ac, 0x82b8, 0x82f0. Preserve the package's marker spelling.
static const char *fallbackRootPrefix(void) { return ""; }
static const char *fallbackJailbreakPrefix(void) { return access("/var/LIY", F_OK) == 0 ? "/var/jb" : ""; }
static const char *fallbackBootUUID(void) { return "00000000-0000-0000-0000-000000000000"; }

// 0x82fc. This is the original 11-byte prefix comparison, not a path-component
// check. It therefore also applies to strings such as /var/mobileSuffix.
static char *fallbackJailbreakPath(const char *path, char *output) {
    if (!path) return NULL;
    if (!output) output = malloc(1024);
    const char *prefix = YTLJailbreakPrefix();
    if (path[0] == '/' && (access("/var/LIY", F_OK) != 0 || strncmp(path, "/var/mobile", 11) != 0)) {
        strlcpy(output, prefix, 1024);
        strlcat(output, path, 1024);
    } else {
        strlcpy(output, path, 1024);
    }
    return output;
}

// 0x83e8. Null input neither changes nor frees caller-provided storage.
static char *fallbackRootFSPath(const char *path, char *output) {
    if (!path) return NULL;
    if (!output) output = malloc(1024);
    const char *root = YTLRootPrefix();
    const char *jailbreak = YTLJailbreakPrefix();
    size_t prefixLength = strlen(jailbreak);
    if (path[0] == '/') {
        if (strncmp(path, jailbreak, prefixLength) != 0) {
            strlcpy(output, root, 1024);
            strlcat(output, path, 1024);
            return output;
        }
        path += prefixLength;
    }
    strlcpy(output, path, 1024);
    return output;
}

// 0x8170. Resolve exports independently, retaining the loaded library. A
// partially implemented libroot can mix its own functions with local fallbacks.
static void initializePaths(void) {
    dispatch_once(&onceToken, ^{
        void *library = dlopen("@rpath/libroot.dylib", RTLD_NOW);
        if (library) {
            rootPrefix = (PrefixFunction)dlsym(library, "libroot_get_root_prefix");
            jailbreakPrefix = (PrefixFunction)dlsym(library, "libroot_get_jbroot_prefix");
            bootUUID = (PrefixFunction)dlsym(library, "libroot_get_boot_uuid");
            jailbreakPath = (PathFunction)dlsym(library, "libroot_jbrootpath");
            rootFSPath = (PathFunction)dlsym(library, "libroot_rootfspath");
        }
        if (!rootPrefix) rootPrefix = fallbackRootPrefix;
        if (!jailbreakPrefix) jailbreakPrefix = fallbackJailbreakPrefix;
        if (!bootUUID) bootUUID = fallbackBootUUID;
        if (!jailbreakPath) jailbreakPath = fallbackJailbreakPath;
        if (!rootFSPath) rootFSPath = fallbackRootFSPath;
    });
}

const char *YTLRootPrefix(void) { initializePaths(); return rootPrefix(); }
const char *YTLJailbreakPrefix(void) { initializePaths(); return jailbreakPrefix(); }
const char *YTLBootUUID(void) { initializePaths(); return bootUUID(); }
char *YTLRootFSPath(const char *path, char *output) { initializePaths(); return rootFSPath(path, output); }
char *YTLJailbreakPath(const char *path, char *output) { initializePaths(); return jailbreakPath(path, output); }
