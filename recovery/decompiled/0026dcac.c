/* Decompiled from supplied 5.2.2 arm package. VA 0x26dcac. _ff_tx_type_is_mdct */

undefined4 _ff_tx_type_is_mdct(int param_1)

{
  if (param_1 - 1U < 5) {
    return *(undefined4 *)(&DAT_00c51e20 + (long)(int)(param_1 - 1U) * 4);
  }
  return 0;
}


