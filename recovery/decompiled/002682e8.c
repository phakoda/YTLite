/* Decompiled from supplied 5.2.2 arm package. VA 0x2682e8. _av_pix_fmt_desc_get */

undefined ** _av_pix_fmt_desc_get(uint param_1)

{
  undefined **ppuVar1;
  
  ppuVar1 = (undefined **)0x0;
  if (param_1 < 0xc6) {
    ppuVar1 = &PTR_s_yuv420p_01065540 + (long)(int)param_1 * 0x14;
  }
  return ppuVar1;
}


