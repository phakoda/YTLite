/* Decompiled from supplied 5.2.2 arm package. VA 0x26b0f0. _av_sample_fmt_is_planar */

undefined4 _av_sample_fmt_is_planar(uint param_1)

{
  if (0xb < param_1) {
    return 0;
  }
  return *(undefined4 *)(&DAT_00c51930 + (long)(int)param_1 * 0x14);
}


