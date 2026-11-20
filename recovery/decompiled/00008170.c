/* Decompiled from supplied 5.2.2 arm package. VA 0x8170. FUN_00008170 */

void FUN_00008170(void)

{
  long lVar1;
  
  lVar1 = _dlopen("@rpath/libroot.dylib",2);
  if (lVar1 != 0) {
    DAT_01225820 = (code *)_dlsym(lVar1,"libroot_get_root_prefix");
    DAT_01225828 = (code *)_dlsym(lVar1,"libroot_get_jbroot_prefix");
    DAT_01225830 = (code *)_dlsym(lVar1,"libroot_get_boot_uuid");
    DAT_01225840 = (code *)_dlsym(lVar1,"libroot_jbrootpath");
    DAT_01225838 = (code *)_dlsym(lVar1,"libroot_rootfspath");
  }
  if (DAT_01225820 == (code *)0x0) {
    DAT_01225820 = FUN_000082ac;
  }
  if (DAT_01225828 == (code *)0x0) {
    DAT_01225828 = FUN_000082b8;
  }
  if (DAT_01225830 == (code *)0x0) {
    DAT_01225830 = FUN_000082f0;
  }
  if (DAT_01225840 == (code *)0x0) {
    DAT_01225840 = FUN_000082fc;
  }
  if (DAT_01225838 == (code *)0x0) {
    DAT_01225838 = FUN_000083e8;
  }
  DAT_01225820 = DAT_01225820;
  DAT_01225828 = DAT_01225828;
  DAT_01225830 = DAT_01225830;
  return;
}


