/* Decompiled from supplied 5.2.2 arm package. VA 0x1066e4. FUN_001066e4 */

undefined1  [16] FUN_001066e4(long param_1,long param_2)

{
  _objc_retain(param_2);
  if (param_2 != 0) {
    _objc_storeStrong(*(long *)(*(long *)(param_1 + 0x28) + 8) + 0x28,param_2);
  }
  (**(code **)(*(long *)(param_1 + 0x20) + 0x10))();
  _objc_release(param_2);
  CallSupervisor(0x355f);
  return ZEXT816(0x1f);
}


