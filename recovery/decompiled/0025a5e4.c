/* Decompiled from supplied 5.2.2 arm package. VA 0x25a5e4. _av_fifo_generic_peek_at */

undefined8
_av_fifo_generic_peek_at(long *param_1,void *param_2,int param_3,int param_4,code *param_5)

{
  int iVar1;
  void *pvVar2;
  long lVar3;
  long lVar4;
  void *pvVar5;
  int iVar6;
  
  lVar4 = (long)param_3;
  if (param_1[3] - param_1[1] <= lVar4) {
    lVar4 = (lVar4 - param_1[3]) + *param_1;
  }
  pvVar5 = (void *)(param_1[1] + lVar4);
  for (; 0 < param_4; param_4 = param_4 - iVar1) {
    pvVar2 = (void *)param_1[3];
    if (pvVar2 <= pvVar5) {
      pvVar5 = (void *)((long)pvVar5 + (*param_1 - (long)pvVar2));
    }
    lVar3 = (long)pvVar2 - (long)pvVar5;
    iVar1 = param_4;
    lVar4 = (long)param_4;
    if (lVar3 <= param_4) {
      iVar1 = (int)lVar3;
      lVar4 = lVar3;
    }
    iVar6 = (int)lVar4;
    if (param_5 == (code *)0x0) {
      _memcpy(param_2,pvVar5,(long)iVar6);
      param_2 = (void *)((long)param_2 + (long)iVar6);
    }
    else {
      (*param_5)(param_2,pvVar5,iVar1);
    }
    pvVar5 = (void *)((long)pvVar5 + (long)iVar6);
  }
  return 0;
}


