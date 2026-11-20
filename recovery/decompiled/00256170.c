/* Decompiled from supplied 5.2.2 arm package. VA 0x256170. FUN_00256170 */

undefined1  [16] FUN_00256170(double param_1)

{
  double dVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  
  if (param_1 < 0.0) {
    return ZEXT816(0);
  }
  if (param_1 < DAT_00c505c8) {
    auVar2._0_8_ = param_1 * DAT_00c505e8;
    auVar2._8_8_ = 0;
    return auVar2;
  }
  dVar1 = (double)_pow(param_1,DAT_00c505d0);
  auVar3._0_8_ = dVar1 * DAT_00c505d8 + DAT_00c505e0;
  auVar3._8_8_ = 0;
  return auVar3;
}


