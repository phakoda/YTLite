/* Decompiled from supplied 5.2.2 arm package. VA 0x251368. _av_audio_fifo_reset */

void _av_audio_fifo_reset(long *param_1)

{
  long lVar1;
  
  for (lVar1 = 0; lVar1 < (int)param_1[1]; lVar1 = lVar1 + 1) {
    _av_fifo_reset(*(undefined8 *)(*param_1 + lVar1 * 8));
  }
  *(undefined4 *)((long)param_1 + 0xc) = 0;
  return;
}


