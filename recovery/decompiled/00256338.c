/* Decompiled from supplied 5.2.2 arm package. VA 0x256338. _av_set_cpu_flags_mask */

void _av_set_cpu_flags_mask(uint param_1)

{
  uint uVar1;
  
  uVar1 = _ff_get_cpu_flags_aarch64();
  DAT_011d3160 = uVar1 & param_1;
  return;
}


