/* Decompiled from supplied 5.2.2 arm package. VA 0x25117c. _av_audio_fifo_peek_at */

int _av_audio_fifo_peek_at(long *param_1,long param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  
  if (-1 < param_4) {
    if (param_3 < 0) {
      return -0x16;
    }
    iVar2 = *(int *)((long)param_1 + 0xc);
    if (iVar2 <= param_4) {
      return -0x16;
    }
    iVar1 = iVar2;
    if (param_3 <= iVar2) {
      iVar1 = param_3;
    }
    if (iVar1 == 0) {
      return 0;
    }
    if (param_4 <= iVar2 - iVar1) {
      iVar2 = *(int *)((long)param_1 + 0x1c);
      lVar4 = 0;
      do {
        if ((int)param_1[1] <= lVar4) {
          return iVar1;
        }
        iVar3 = _av_fifo_generic_peek_at
                          (*(undefined8 *)(*param_1 + lVar4 * 8),
                           *(undefined8 *)(param_2 + lVar4 * 8),iVar2 * param_4,iVar2 * iVar1,0);
        lVar4 = lVar4 + 1;
      } while (-1 < iVar3);
      return -0x21475542;
    }
  }
  return -0x16;
}


