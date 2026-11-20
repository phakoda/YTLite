/* Decompiled from supplied 5.2.2 arm package. VA 0x2560d8. FUN_002560d8 */

undefined1  [16] FUN_002560d8(double param_1)

{
  double dVar1;
  undefined1 auVar2 [16];
  
  if (param_1 <= DAT_00c505c0) {
    dVar1 = (double)_pow(param_1 * -4.0,DAT_00c4c4b8);
    param_1 = (dVar1 * DAT_00c50568 + DAT_00c505b8) * -0.25;
  }
  else if (DAT_00c50560 <= param_1) {
    dVar1 = (double)_pow(param_1,DAT_00c4c4b8);
    param_1 = dVar1 * DAT_00c50568 + DAT_00c50570;
  }
  else {
    param_1 = param_1 * 4.5;
  }
  auVar2._8_8_ = 0;
  auVar2._0_8_ = param_1;
  return auVar2;
}


