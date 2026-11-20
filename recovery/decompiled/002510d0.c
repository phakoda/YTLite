/* Decompiled from supplied 5.2.2 arm package. VA 0x2510d0. _av_audio_fifo_space */

int _av_audio_fifo_space(long param_1)

{
  return *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc);
}


