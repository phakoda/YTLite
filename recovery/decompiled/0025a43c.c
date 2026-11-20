/* Decompiled from supplied 5.2.2 arm package. VA 0x25a43c. _av_fifo_generic_read */

undefined8 _av_fifo_generic_read(long param_1,void *param_2,int param_3,code *param_4)

{
  long lVar1;
  void *pvVar2;
  int iVar3;
  long lVar4;
  
  do {
    pvVar2 = *(void **)(param_1 + 8);
    lVar4 = *(long *)(param_1 + 0x18) - (long)pvVar2;
    iVar3 = param_3;
    lVar1 = (long)param_3;
    if (lVar4 <= param_3) {
      iVar3 = (int)lVar4;
      lVar1 = lVar4;
    }
    if (param_4 == (code *)0x0) {
      _memcpy(param_2,pvVar2,(long)(int)lVar1);
      param_2 = (void *)((long)param_2 + (long)(int)lVar1);
    }
    else {
      (*param_4)(param_2,pvVar2,iVar3);
    }
    _av_fifo_drain(param_1,iVar3);
    param_3 = param_3 - iVar3;
  } while (0 < param_3);
  return 0;
}


