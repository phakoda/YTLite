/* Decompiled from supplied 5.2.2 arm package. VA 0x26b0c0. _av_get_bytes_per_sample */

int _av_get_bytes_per_sample(uint param_1)

{
  if (0xb < param_1) {
    return 0;
  }
  return *(int *)(&DAT_00c5192c + (long)(int)param_1 * 0x14) >> 3;
}


