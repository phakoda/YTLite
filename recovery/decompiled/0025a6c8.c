/* Decompiled from supplied 5.2.2 arm package. VA 0x25a6c8. _av_fifo_generic_peek */

undefined8 _av_fifo_generic_peek(long *param_1,void *param_2,int param_3,code *param_4)

{
  long lVar1;
  int iVar2;
  void *pvVar3;
  long lVar4;
  void *pvVar5;
  int iVar6;
  
  pvVar5 = (void *)param_1[1];
  pvVar3 = (void *)param_1[3];
  do {
    lVar4 = (long)pvVar3 - (long)pvVar5;
    iVar2 = param_3;
    lVar1 = (long)param_3;
    if (lVar4 <= param_3) {
      iVar2 = (int)lVar4;
      lVar1 = lVar4;
    }
    iVar6 = (int)lVar1;
    if (param_4 == (code *)0x0) {
      _memcpy(param_2,pvVar5,(long)iVar6);
      param_2 = (void *)((long)param_2 + (long)iVar6);
    }
    else {
      (*param_4)(param_2,pvVar5,iVar2);
    }
    pvVar3 = (void *)param_1[3];
    pvVar5 = (void *)((long)pvVar5 + (long)iVar6);
    if (pvVar3 <= pvVar5) {
      pvVar5 = (void *)((long)pvVar5 + (*param_1 - (long)pvVar3));
    }
    param_3 = param_3 - iVar2;
  } while (0 < param_3);
  return 0;
}


