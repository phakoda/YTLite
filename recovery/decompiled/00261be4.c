/* Decompiled from supplied 5.2.2 arm package. VA 0x261be4. _av_realloc_array */

undefined8 _av_realloc_array(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_28;
  
  iVar1 = FUN_00261a7c(param_2,param_3,&local_28);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = _av_realloc(param_1,local_28);
  }
  return uVar2;
}


