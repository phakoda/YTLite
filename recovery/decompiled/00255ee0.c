/* Decompiled from supplied 5.2.2 arm package. VA 0x255ee0. FUN_00255ee0 */

undefined1  [16] FUN_00255ee0(double param_1)

{
  double dVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  
  if (param_1 < 0.0) {
    return ZEXT816(0);
  }
  if (param_1 < DAT_00c50560) {
    auVar2._0_8_ = param_1 * 4.5;
    auVar2._8_8_ = 0;
    return auVar2;
  }
  dVar1 = (double)_pow(param_1,DAT_00c4c4b8);
  auVar3._0_8_ = dVar1 * DAT_00c50568 + DAT_00c50570;
  auVar3._8_8_ = 0;
  return auVar3;
}


