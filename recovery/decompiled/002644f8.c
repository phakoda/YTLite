/* Decompiled from supplied 5.2.2 arm package. VA 0x2644f8. _av_opt_get_q */

undefined8 _av_opt_get_q(undefined8 param_1,undefined8 param_2,undefined4 param_3,int *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int local_34;
  double local_30;
  long local_28;
  
  local_30 = 1.0;
  local_28 = 1;
  local_34 = 1;
  uVar1 = FUN_00264408(param_1,param_2,&local_30,&local_34,&local_28,param_3);
  if (-1 < (int)uVar1) {
    if (local_30 == 1.0 && (int)local_28 == local_28) {
      uVar1 = 0;
      *param_4 = (int)local_28;
      param_4[1] = local_34;
    }
    else {
      uVar2 = _av_d2q((local_30 * (double)local_28) / (double)local_34,0x1000000);
      uVar1 = 0;
      *(undefined8 *)param_4 = uVar2;
    }
  }
  return uVar1;
}


