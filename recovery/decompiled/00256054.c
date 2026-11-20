/* Decompiled from supplied 5.2.2 arm package. VA 0x256054. FUN_00256054 */

undefined1  [16] FUN_00256054(double param_1)

{
  double dVar1;
  undefined1 auVar2 [16];
  double dVar3;
  
  if (param_1 <= DAT_00c505a8) {
    dVar1 = (double)_pow(-param_1,DAT_00c4c4b8);
    dVar3 = DAT_00c505b0;
    param_1 = DAT_00c505b8;
  }
  else {
    if (param_1 < DAT_00c50560) {
      param_1 = param_1 * 4.5;
      goto LAB_002560d0;
    }
    dVar1 = (double)_pow(param_1,DAT_00c4c4b8);
    dVar3 = DAT_00c50568;
    param_1 = DAT_00c50570;
  }
  param_1 = dVar1 * dVar3 + param_1;
LAB_002560d0:
  auVar2._8_8_ = 0;
  auVar2._0_8_ = param_1;
  return auVar2;
}


