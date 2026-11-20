/* Decompiled from supplied 5.2.2 arm package. VA 0x1ff474. FUN_001ff474 */

undefined1  [16] FUN_001ff474(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x28);
  if (lVar1 != 0) {
    (**(code **)(lVar1 + 0x10))(lVar1,*(undefined8 *)(param_1 + 0x20),0);
  }
  CallSupervisor(0x7390);
  return ZEXT816(0x1f);
}


