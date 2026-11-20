/* Decompiled from supplied 5.2.2 arm package. VA 0x264394. _av_opt_get_int */

undefined8 _av_opt_get_int(undefined8 param_1,undefined8 param_2,undefined4 param_3,long *param_4)

{
  undefined8 uVar1;
  int local_34;
  double local_30;
  long lStack_28;
  
  local_30 = 1.0;
  lStack_28 = 1;
  local_34 = 1;
  uVar1 = FUN_00264408(param_1,param_2,&local_30,&local_34,&lStack_28,param_3);
  if (-1 < (int)uVar1) {
    uVar1 = 0;
    *param_4 = (long)((local_30 * (double)lStack_28) / (double)local_34);
  }
  return uVar1;
}


