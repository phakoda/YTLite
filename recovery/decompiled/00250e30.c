/* Decompiled from supplied 5.2.2 arm package. VA 0x250e30. _av_audio_fifo_free */

void _av_audio_fifo_free(long *param_1)

{
  long lVar1;
  long lVar2;
  
  if (param_1 != (long *)0x0) {
    if (*param_1 != 0) {
      lVar2 = -1;
      lVar1 = 0;
      while (lVar2 = lVar2 + 1, lVar2 < (int)param_1[1]) {
        _av_fifo_freep(*param_1 + lVar1);
        lVar1 = lVar1 + 8;
      }
      _av_freep(param_1);
    }
    _av_free(param_1);
    return;
  }
  return;
}


