/* Decompiled from supplied 5.2.2 arm package. VA 0x264870. _av_opt_get_dict_val */

undefined8
_av_opt_get_dict_val(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 uVar2;
  long local_28;
  
  lVar1 = _av_opt_find2(param_1,param_2,0,0,param_3,&local_28);
  uVar2 = 0xabafb008;
  if ((lVar1 != 0) && (local_28 != 0)) {
    if (*(int *)(lVar1 + 0x14) == 8) {
      _av_dict_copy(param_4,*(undefined8 *)(local_28 + *(int *)(lVar1 + 0x10)),0);
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffea;
    }
  }
  return uVar2;
}


