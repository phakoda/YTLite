/* Decompiled from supplied 5.2.2 arm package. VA 0x263954. _av_opt_set_bin */

undefined8
_av_opt_set_bin(undefined8 param_1,undefined8 param_2,void *param_3,int param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 uVar3;
  void *pvVar4;
  long local_38;
  
  lVar2 = _av_opt_find2(param_1,param_2,0,0,param_5,&local_38);
  uVar3 = 0xabafb008;
  if ((lVar2 != 0) && (local_38 != 0)) {
    if ((*(int *)(lVar2 + 0x14) == 7) && (-1 < *(char *)(lVar2 + 0x30))) {
      if (param_4 == 0) {
        pvVar4 = (void *)0x0;
      }
      else {
        pvVar4 = (void *)_av_malloc((long)param_4);
        if (pvVar4 == (void *)0x0) {
          return 0xfffffff4;
        }
      }
      puVar1 = (undefined8 *)(local_38 + *(int *)(lVar2 + 0x10));
      _av_free((void *)*puVar1);
      *puVar1 = pvVar4;
      *(int *)(puVar1 + 1) = param_4;
      if (param_4 != 0) {
        _memcpy(pvVar4,param_3,(long)param_4);
      }
      uVar3 = 0;
    }
    else {
      uVar3 = 0xffffffea;
    }
  }
  return uVar3;
}


