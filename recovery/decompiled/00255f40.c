/* Decompiled from supplied 5.2.2 arm package. VA 0x255f40. FUN_00255f40 */

undefined1  [16] FUN_00255f40(double param_1)

{
  undefined1 auVar1 [16];
  
  if (param_1 < 0.0) {
    return ZEXT816(0);
  }
  auVar1 = _pow(param_1,DAT_00c50578);
  return auVar1;
}


