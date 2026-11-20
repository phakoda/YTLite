/* Decompiled from supplied 5.2.2 arm package. VA 0x2666b4. _av_opt_is_set_to_default_by_name */

undefined8 _av_opt_is_set_to_default_by_name(long param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_18;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    lVar1 = _av_opt_find2(param_1,param_2,0,0,param_3,&local_18);
    if (lVar1 == 0) {
      uVar2 = 0xabafb008;
    }
    else {
      uVar2 = _av_opt_is_set_to_default(local_18,lVar1);
    }
  }
  return uVar2;
}


