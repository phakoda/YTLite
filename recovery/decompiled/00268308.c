/* Decompiled from supplied 5.2.2 arm package. VA 0x268308. _av_pix_fmt_desc_next */

undefined ** _av_pix_fmt_desc_next(undefined **param_1)

{
  undefined **ppuVar1;
  
  ppuVar1 = &PTR_s_yuv420p_01065540;
  if (param_1 != (undefined **)0x0) {
    do {
      if (0xc4 < (ulong)(((long)(param_1 + -0x20caa8) >> 5) * -0x3333333333333333)) {
        return (undefined **)0x0;
      }
      ppuVar1 = param_1 + 0x14;
      param_1 = ppuVar1;
    } while (*ppuVar1 == (undefined *)0x0);
  }
  return ppuVar1;
}


