/* Decompiled from supplied 5.2.2 arm package. VA 0x263d68. _av_opt_set_dict_val */

undefined8
_av_opt_set_dict_val(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  undefined8 uVar2;
  long local_28;
  
  lVar1 = _av_opt_find2(param_1,param_2,0,0,param_4,&local_28);
  uVar2 = 0xabafb008;
  if ((lVar1 != 0) && (local_28 != 0)) {
    if (*(char *)(lVar1 + 0x30) < '\0') {
      uVar2 = 0xffffffea;
    }
    else {
      lVar1 = local_28 + *(int *)(lVar1 + 0x10);
      _av_dict_free(lVar1);
      _av_dict_copy(lVar1,param_3,0);
      uVar2 = 0;
    }
  }
  return uVar2;
}


