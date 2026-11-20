/* Decompiled from supplied 5.2.2 arm package. VA 0x255e98. _avpriv_get_gamma_from_trc */

undefined1  [16] _avpriv_get_gamma_from_trc(int param_1)

{
  undefined1 auVar1 [16];
  
  if (param_1 - 1U < 0xf) {
    auVar1._0_8_ = *(ulong *)(&DAT_00c50660 + (long)(int)(param_1 - 1U) * 8);
    auVar1._8_8_ = 0;
    return auVar1;
  }
  return ZEXT816(0);
}


