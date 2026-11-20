/* Decompiled from supplied 5.2.2 arm package. VA 0x268350. _av_pix_fmt_desc_get_id */

int _av_pix_fmt_desc_get_id(undefined **param_1)

{
  if (&PTR_s_yuv420p_01065540 <= param_1 && param_1 < &PTR_s_unknown_0106d100) {
    return (int)((ulong)(param_1 + -0x20caa8) >> 5) * -0x33333333;
  }
  return -1;
}


