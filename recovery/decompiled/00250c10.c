/* Decompiled from supplied 5.2.2 arm package. VA 0x250c10. _av_aes_ctr_set_full_iv */

void _av_aes_ctr_set_full_iv(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = *param_2;
  *(undefined8 *)(param_1 + 0x10) = param_2[1];
  *(undefined8 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return;
}


