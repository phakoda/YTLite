/* Decompiled from supplied 5.2.2 arm package. VA 0x251008. _av_audio_fifo_write */

ulong _av_audio_fifo_write(long *param_1,long param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  
  iVar1 = *(int *)((long)param_1 + 0xc);
  if ((int)param_1[2] - iVar1 < (int)param_3) {
    if (0x3fffffff - iVar1 < (int)param_3) {
      return 0xffffffea;
    }
    uVar3 = _av_audio_fifo_realloc(param_1,(iVar1 + param_3) * 2);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
  }
  lVar4 = 0;
  iVar1 = *(int *)((long)param_1 + 0x1c) * param_3;
  do {
    if ((int)param_1[1] <= lVar4) {
      *(uint *)((long)param_1 + 0xc) = (int)((ulong)param_1[1] >> 0x20) + param_3;
      return (ulong)param_3;
    }
    iVar2 = _av_fifo_generic_write
                      (*(undefined8 *)(*param_1 + lVar4 * 8),*(undefined8 *)(param_2 + lVar4 * 8),
                       iVar1,0);
    lVar4 = lVar4 + 1;
  } while (iVar2 == iVar1);
  return 0xdeb8aabe;
}


