/* Decompiled from supplied 5.2.2 arm package. VA 0x25a514. _av_fifo_generic_write */

int _av_fifo_generic_write(ulong *param_1,void *param_2,int param_3,code *param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  void *pvVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = *(int *)((long)param_1 + 0x24);
  pvVar5 = (void *)param_1[2];
  pvVar4 = (void *)param_1[3];
  iVar7 = param_3;
  do {
    lVar3 = (long)pvVar4 - (long)pvVar5;
    iVar2 = iVar7;
    lVar1 = (long)iVar7;
    if (lVar3 <= iVar7) {
      iVar2 = (int)lVar3;
      lVar1 = lVar3;
    }
    if (param_4 == (code *)0x0) {
      _memcpy(pvVar5,param_2,(long)(int)lVar1);
      param_2 = (void *)((long)param_2 + (long)(int)lVar1);
    }
    else {
      iVar2 = (*param_4)(param_2,pvVar5,iVar2);
      if (iVar2 < 1) break;
    }
    pvVar4 = (void *)param_1[3];
    pvVar5 = (void *)((long)pvVar5 + (long)iVar2);
    if (pvVar4 <= pvVar5) {
      pvVar5 = (void *)*param_1;
    }
    iVar6 = iVar2 + iVar6;
    iVar7 = iVar7 - iVar2;
  } while (0 < iVar7);
  *(int *)((long)param_1 + 0x24) = iVar6;
  param_1[2] = (ulong)pvVar5;
  return param_3 - iVar7;
}


