/* Decompiled from supplied 5.2.2 arm package. VA 0x25fad0. _av_log2_16bit */

int _av_log2_16bit(uint param_1)

{
  return 0x1f - (int)LZCOUNT(param_1 | 1);
}


