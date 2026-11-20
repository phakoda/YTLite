/* Decompiled from supplied 5.2.2 arm package. VA 0x256258. FUN_00256258 */

undefined1  [16] FUN_00256258(double param_1)

{
  undefined1 auVar1 [16];
  
  if (param_1 < 0.0) {
    return ZEXT816(0);
  }
  auVar1 = _pow((param_1 * DAT_00c50620) / DAT_00c50628,DAT_00c50630);
  return auVar1;
}


