/* Decompiled from supplied 5.2.2 arm package. VA 0x261b78. _av_mallocz_array */

undefined8 _av_mallocz_array(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_18;
  
  iVar1 = FUN_00261a7c(param_1,param_2,&local_18);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = _av_mallocz(local_18);
  }
  return uVar2;
}


