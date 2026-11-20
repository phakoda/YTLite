#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../source/Runtime/YTLRootPaths.h"

static unsigned checks, loads, lookups, accesses;
static int mode, marker;
static char libraryHandle;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #__VA_ARGS__); abort(); \
} } while (0)
static const char *fixtureRoot(void) { return "/root-fixture"; }
static const char *fixtureJailbreak(void) { return "/jb-fixture"; }
static const char *fixtureUUID(void) { return "fixture-boot-uuid"; }
static char *fixturePath(const char *path, char *output) {
    CHECK(path != NULL && output != NULL);
    strlcpy(output, "provider:", 1024); strlcat(output, path, 1024);
    return output;
}
void *YTLTestDlopen(const char *path, int flags) {
    CHECK(strcmp(path, "@rpath/libroot.dylib") == 0 && flags == RTLD_NOW);
    loads++;
    return mode ? &libraryHandle : NULL;
}
void *YTLTestDlsym(void *library, const char *name) {
    CHECK(library == &libraryHandle); lookups++;
    if (!strcmp(name, "libroot_get_root_prefix")) return (void *)fixtureRoot;
    if (!strcmp(name, "libroot_get_jbroot_prefix")) return (void *)fixtureJailbreak;
    if (!strcmp(name, "libroot_get_boot_uuid")) return mode == 2 ? (void *)fixtureUUID : NULL;
    CHECK(!strcmp(name, "libroot_jbrootpath") || !strcmp(name, "libroot_rootfspath"));
    return mode == 2 ? (void *)fixturePath : NULL;
}
int YTLTestAccess(const char *path, int flags) {
    CHECK(strcmp(path, "/var/LIY") == 0 && flags == F_OK);
    accesses++;
    return marker ? 0 : -1;
}

int main(int argc, const char *argv[]) {
    CHECK(argc == 3); mode = atoi(argv[1]); marker = atoi(argv[2]);
    CHECK(!strcmp(YTLRootPrefix(), mode ? "/root-fixture" : ""));
    CHECK(!strcmp(YTLJailbreakPrefix(), mode ? "/jb-fixture" : marker ? "/var/jb" : ""));
    CHECK(!strcmp(YTLBootUUID(), mode == 2 ? "fixture-boot-uuid" : "00000000-0000-0000-0000-000000000000"));
    CHECK(loads == 1 && lookups == (mode ? 5u : 0u));
    char output[1024];
    if (mode == 2) {
        CHECK(YTLJailbreakPath("/absolute", output) == output && !strcmp(output, "provider:/absolute"));
        CHECK(YTLRootFSPath("relative", output) == output && !strcmp(output, "provider:relative"));
        CHECK(accesses == 0);
    } else {
        const char *jailbreak = mode ? "/jb-fixture" : marker ? "/var/jb" : "";
        char expected[1024]; strlcpy(expected, jailbreak, sizeof(expected)); strlcat(expected, "/absolute", sizeof(expected));
        CHECK(YTLJailbreakPath("/absolute", output) == output && !strcmp(output, expected));
        CHECK(YTLJailbreakPath("relative", output) == output && !strcmp(output, "relative"));
        strlcpy(expected, marker ? "" : jailbreak, sizeof(expected)); strlcat(expected, "/var/mobile/test", sizeof(expected));
        CHECK(!strcmp(YTLJailbreakPath("/var/mobile/test", output), expected));
        strlcpy(expected, marker ? "" : jailbreak, sizeof(expected)); strlcat(expected, "/var/mobileSuffix", sizeof(expected));
        CHECK(!strcmp(YTLJailbreakPath("/var/mobileSuffix", output), expected));
        char *allocated = YTLJailbreakPath("allocated", NULL);
        CHECK(allocated != NULL && !strcmp(allocated, "allocated")); free(allocated);
        allocated = YTLRootFSPath("allocated-root", NULL);
        CHECK(allocated != NULL && !strcmp(allocated, "allocated-root")); free(allocated);
        strlcpy(output, "untouched", sizeof(output));
        CHECK(YTLJailbreakPath(NULL, output) == NULL && !strcmp(output, "untouched"));
        CHECK(YTLRootFSPath(NULL, output) == NULL && !strcmp(output, "untouched"));
        strlcpy(expected, jailbreak, sizeof(expected)); strlcat(expected, "/library", sizeof(expected));
        CHECK(!strcmp(YTLRootFSPath(expected, output), "/library"));
        CHECK(!strcmp(YTLRootFSPath("relative", output), "relative"));
        CHECK(!strcmp(YTLRootFSPath("/other", output), mode ? "/root-fixture/other" : "/other"));
        char longPath[2200]; memset(longPath, 'a', sizeof(longPath)); longPath[0] = '/'; longPath[sizeof(longPath) - 1] = 0;
        CHECK(strlen(YTLJailbreakPath(longPath, output)) == 1023);
        CHECK(strlen(YTLRootFSPath(longPath, output)) == 1023);
        if (!mode) { marker = !marker; CHECK(!strcmp(YTLJailbreakPrefix(), marker ? "/var/jb" : "")); }
    }
    CHECK(loads == 1 && lookups == (mode ? 5u : 0u));
    printf("Root-path assertions passed: %u (provider mode %d).\n", checks, mode);
    return 0;
}
