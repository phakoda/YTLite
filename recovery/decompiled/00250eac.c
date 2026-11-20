/* Decompiled from supplied 5.2.2 arm package. VA 0x250eac. _av_audio_fifo_alloc */

long * _av_audio_fifo_alloc(undefined4 param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  int iVar6;
  int local_34;
  
  iVar6 = (int)param_2;
  iVar2 = _av_samples_get_buffer_size(&local_34,param_2,param_3,param_1,1);
  if ((-1 < iVar2) && (plVar3 = (long *)_av_mallocz(0x20), plVar3 != (long *)0x0)) {
    *(int *)((long)plVar3 + 0x14) = iVar6;
    *(undefined4 *)(plVar3 + 3) = param_1;
    iVar2 = 0;
    if (param_3 != 0) {
      iVar2 = local_34 / param_3;
    }
    *(int *)((long)plVar3 + 0x1c) = iVar2;
    iVar2 = _av_sample_fmt_is_planar(param_1);
    if (iVar2 == 0) {
      iVar6 = 1;
    }
    *(int *)(plVar3 + 1) = iVar6;
    lVar4 = _av_mallocz_array((long)iVar6,8);
    *plVar3 = lVar4;
    if (lVar4 != 0) {
      lVar4 = 0;
      do {
        if ((int)plVar3[1] <= lVar4) {
          *(int *)(plVar3 + 2) = param_3;
          return plVar3;
        }
        uVar5 = _av_fifo_alloc(local_34);
        *(undefined8 *)(*plVar3 + lVar4 * 8) = uVar5;
        lVar1 = lVar4 * 8;
        lVar4 = lVar4 + 1;
      } while (*(long *)(*plVar3 + lVar1) != 0);
    }
    _av_audio_fifo_free(plVar3);
  }
  return (long *)0x0;
}


