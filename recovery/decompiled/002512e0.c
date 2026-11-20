/* Decompiled from supplied 5.2.2 arm package. VA 0x2512e0. _av_audio_fifo_drain */

undefined8 _av_audio_fifo_drain(long *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (param_2 < 0) {
    uVar3 = 0xffffffea;
  }
  else {
    iVar1 = *(int *)((long)param_1 + 0xc);
    if (param_2 <= *(int *)((long)param_1 + 0xc)) {
      iVar1 = param_2;
    }
    if (iVar1 == 0) {
      uVar3 = 0;
    }
    else {
      iVar2 = *(int *)((long)param_1 + 0x1c);
      for (lVar4 = 0; lVar4 < (int)param_1[1]; lVar4 = lVar4 + 1) {
        _av_fifo_drain(*(undefined8 *)(*param_1 + lVar4 * 8),iVar2 * iVar1);
      }
      uVar3 = 0;
      *(int *)((long)param_1 + 0xc) = (int)((ulong)param_1[1] >> 0x20) - iVar1;
    }
  }
  return uVar3;
}


