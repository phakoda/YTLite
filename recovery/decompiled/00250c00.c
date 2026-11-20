/* Decompiled from supplied 5.2.2 arm package. VA 0x250c00. _av_aes_ctr_set_iv */

void _av_aes_ctr_set_iv(long param_1,undefined8 *param_2)

{
  *(undefined8 *)(param_1 + 8) = *param_2;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return;
}


