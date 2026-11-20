/* Decompiled from supplied 5.2.2 arm package. VA 0x25fabc. _av_log2 */

int _av_log2(uint param_1)

{
  return 0x1f - (int)LZCOUNT(param_1 | 1);
}


