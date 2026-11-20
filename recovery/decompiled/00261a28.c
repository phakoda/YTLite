/* Decompiled from supplied 5.2.2 arm package. VA 0x261a28. _av_realloc_f */

long _av_realloc_f(void *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 local_28;
  
  iVar1 = FUN_00261a7c(param_3,param_2,&local_28);
  if ((iVar1 != 0) || (lVar2 = _av_realloc(param_1,local_28), lVar2 == 0)) {
    _free(param_1);
    lVar2 = 0;
  }
  return lVar2;
}


