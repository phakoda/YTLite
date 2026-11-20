/* Decompiled from supplied 5.2.2 arm package. VA 0x256018. FUN_00256018 */

undefined1  [16] FUN_00256018(double param_1)

{
  double dVar1;
  undefined1 auVar2 [16];
  
  if (param_1 < DAT_00c505a0) {
    return ZEXT816(0);
  }
  dVar1 = (double)_log10();
  auVar2._0_8_ = dVar1 / 2.5 + 1.0;
  auVar2._8_8_ = 0;
  return auVar2;
}


