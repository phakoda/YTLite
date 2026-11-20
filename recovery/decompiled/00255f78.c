/* Decompiled from supplied 5.2.2 arm package. VA 0x255f78. FUN_00255f78 */

undefined1  [16] FUN_00255f78(double param_1)

{
  double dVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  
  if (param_1 < 0.0) {
    return ZEXT816(0);
  }
  if (param_1 < DAT_00c50588) {
    auVar2._0_8_ = param_1 * 4.0;
    auVar2._8_8_ = 0;
    return auVar2;
  }
  dVar1 = (double)_pow(param_1,DAT_00c4c4b8);
  auVar3._0_8_ = dVar1 * DAT_00c50590 + DAT_00c50598;
  auVar3._8_8_ = 0;
  return auVar3;
}


