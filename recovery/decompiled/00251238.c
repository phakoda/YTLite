/* Decompiled from supplied 5.2.2 arm package. VA 0x251238. _av_audio_fifo_read */

int _av_audio_fifo_read(long *param_1,long param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  
  if (param_3 < 0) {
    iVar3 = -0x16;
  }
  else {
    iVar3 = *(int *)((long)param_1 + 0xc);
    if (param_3 <= *(int *)((long)param_1 + 0xc)) {
      iVar3 = param_3;
    }
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar1 = *(int *)((long)param_1 + 0x1c);
      lVar4 = 0;
      do {
        if ((int)param_1[1] <= lVar4) {
          *(int *)((long)param_1 + 0xc) = (int)((ulong)param_1[1] >> 0x20) - iVar3;
          return iVar3;
        }
        iVar2 = _av_fifo_generic_read
                          (*(undefined8 *)(*param_1 + lVar4 * 8),
                           *(undefined8 *)(param_2 + lVar4 * 8),iVar1 * iVar3,0);
        lVar4 = lVar4 + 1;
      } while (-1 < iVar2);
      iVar3 = -0x21475542;
    }
  }
  return iVar3;
}


