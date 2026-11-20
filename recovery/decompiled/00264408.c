/* Decompiled from supplied 5.2.2 arm package. VA 0x264408. FUN_00264408 */

undefined8
FUN_00264408(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4,
            undefined8 *param_5,undefined4 param_6)

{
  long lVar1;
  undefined8 uVar2;
  long local_38;
  
  lVar1 = _av_opt_find2(param_1,param_2,0,0,param_6,&local_38);
  if ((lVar1 == 0) || (local_38 == 0)) {
    *param_5 = 0;
    *param_4 = 0;
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = FUN_00266578(lVar1,local_38 + *(int *)(lVar1 + 0x10),param_3,param_4,param_5);
  }
  return uVar2;
}


