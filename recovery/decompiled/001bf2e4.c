/* Decompiled from supplied 5.2.2 arm package. VA 0x1bf2e4. FUN_001bf2e4 */

undefined1  [16] FUN_001bf2e4(long param_1)

{
  if (*(long *)(param_1 + 0x20) != 0) {
    (**(code **)(*(long *)(param_1 + 0x20) + 0x10))();
  }
  CallSupervisor(0x7ac4);
  return ZEXT816(0x1f);
}


