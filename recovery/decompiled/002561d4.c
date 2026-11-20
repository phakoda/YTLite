/* Decompiled from supplied 5.2.2 arm package. VA 0x2561d4. FUN_002561d4 */

undefined1  [16] FUN_002561d4(double param_1)

{
  double dVar1;
  undefined1 auVar2 [16];
  
  dVar1 = (double)_pow(param_1 / DAT_00c505f0,DAT_00c505f8);
  if (param_1 < 0.0) {
    return ZEXT816(0);
  }
  auVar2 = _pow((dVar1 * DAT_00c50600 + DAT_00c50608) / (dVar1 * DAT_00c50610 + 1.0),DAT_00c50618);
  return auVar2;
}


