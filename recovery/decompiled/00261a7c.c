/* Decompiled from supplied 5.2.2 arm package. VA 0x261a7c. FUN_00261a7c */

undefined8 FUN_00261a7c(ulong param_1,ulong param_2,ulong *param_3)

{
  ulong uVar1;
  
  if ((param_1 != 0) && ((param_2 | param_1) >> 0x20 != 0)) {
    uVar1 = 0;
    if (param_1 != 0) {
      uVar1 = (param_2 * param_1) / param_1;
    }
    if (uVar1 != param_2) {
      return 0xffffffea;
    }
  }
  *param_3 = param_2 * param_1;
  return 0;
}


