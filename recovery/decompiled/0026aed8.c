/* Decompiled from supplied 5.2.2 arm package. VA 0x26aed8. _av_get_sample_fmt_name */

undefined * _av_get_sample_fmt_name(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_1 < 0xc) {
    puVar1 = &DAT_00c51924 + (long)(int)param_1 * 0x14;
  }
  return puVar1;
}


