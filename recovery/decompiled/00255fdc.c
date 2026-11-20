/* Decompiled from supplied 5.2.2 arm package. VA 0x255fdc. FUN_00255fdc */

undefined1  [16] FUN_00255fdc(double param_1)

{
  double dVar1;
  undefined1 auVar2 [16];
  
  if (param_1 < DAT_00c4c3c0) {
    return ZEXT816(0);
  }
  dVar1 = (double)_log10();
  auVar2._0_8_ = dVar1 * 0.5 + 1.0;
  auVar2._8_8_ = 0;
  return auVar2;
}


