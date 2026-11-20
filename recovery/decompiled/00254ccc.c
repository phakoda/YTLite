/* Decompiled from supplied 5.2.2 arm package. VA 0x254ccc. _av_bprint_finalize */

undefined8 _av_bprint_finalize(long *param_1,long *param_2)

{
  uint uVar1;
  long lVar2;
  void *pvVar3;
  undefined8 uVar4;
  ulong uVar5;
  
  uVar1 = *(uint *)((long)param_1 + 0xc);
  lVar2 = *param_1;
  if ((int)param_1[1] + 1U <= uVar1) {
    uVar1 = (int)param_1[1] + 1;
  }
  if (param_2 == (long *)0x0) {
    if (lVar2 != (long)param_1 + 0x14) {
      _av_freep(param_1);
    }
    uVar4 = 0;
  }
  else {
    uVar5 = (ulong)uVar1;
    if (lVar2 == (long)param_1 + 0x14) {
      pvVar3 = (void *)_av_malloc(uVar5);
      if (pvVar3 == (void *)0x0) {
        pvVar3 = (void *)0x0;
        uVar4 = 0xfffffff4;
      }
      else {
        _memcpy(pvVar3,(void *)*param_1,uVar5);
        uVar4 = 0;
      }
    }
    else {
      pvVar3 = (void *)_av_realloc(lVar2,uVar5);
      if (pvVar3 == (void *)0x0) {
        pvVar3 = (void *)*param_1;
      }
      uVar4 = 0;
      *param_1 = 0;
    }
    *param_2 = (long)pvVar3;
  }
  *(uint *)((long)param_1 + 0xc) = uVar1;
  return uVar4;
}


