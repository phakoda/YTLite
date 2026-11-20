/* Decompiled from supplied 5.2.2 arm package. VA 0x25628c. FUN_0025628c */

undefined1  [16] FUN_0025628c(double param_1)

{
  double dVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  
  if (param_1 < 0.0) {
    return ZEXT816(0);
  }
  if (DAT_00c50638 < param_1) {
    dVar1 = (double)_log(param_1 * 12.0 + DAT_00c50640);
    auVar2._0_8_ = dVar1 * DAT_00c50648 + DAT_00c50650;
    auVar2._8_8_ = 0;
    return auVar2;
  }
  auVar3._0_8_ = SQRT(param_1 * 3.0);
  auVar3._8_8_ = 0;
  return auVar3;
}


