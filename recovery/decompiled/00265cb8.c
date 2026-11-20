/* Decompiled from supplied 5.2.2 arm package. VA 0x265cb8. _av_opt_ptr */

long _av_opt_ptr(undefined8 param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  undefined8 local_28;
  
  local_28 = param_1;
  lVar1 = _av_opt_find2(&local_28,param_3,0,0,2,0);
  lVar2 = 0;
  if (lVar1 != 0) {
    lVar2 = param_2 + *(int *)(lVar1 + 0x10);
  }
  return lVar2;
}


