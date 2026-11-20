/* Decompiled from supplied 5.2.2 arm package. VA 0x250f88. _av_audio_fifo_realloc */

undefined8 _av_audio_fifo_realloc(long *param_1,undefined4 param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined4 local_34;
  
  uVar1 = _av_samples_get_buffer_size
                    (&local_34,*(undefined4 *)((long)param_1 + 0x14),param_2,(int)param_1[3],1);
  if (-1 < (int)uVar1) {
    lVar2 = 0;
    do {
      if ((int)param_1[1] <= lVar2) {
        *(undefined4 *)(param_1 + 2) = param_2;
        return 0;
      }
      uVar1 = _av_fifo_realloc2(*(undefined8 *)(*param_1 + lVar2 * 8),local_34);
      lVar2 = lVar2 + 1;
    } while (-1 < (int)uVar1);
  }
  return uVar1;
}


