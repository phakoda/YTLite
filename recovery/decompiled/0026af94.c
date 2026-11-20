/* Decompiled from supplied 5.2.2 arm package. VA 0x26af94. _av_get_packed_sample_fmt */

ulong _av_get_packed_sample_fmt(ulong param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (0xb < uVar1) {
    return 0xffffffff;
  }
  if ((0xbe0UL >> ((long)(int)uVar1 & 0x3fU) & 1) != 0) {
    param_1 = (ulong)*(uint *)(&DAT_00c51934 + (long)(int)uVar1 * 0x14);
  }
  return param_1;
}


