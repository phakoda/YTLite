/* Decompiled from supplied 5.2.2 arm package. VA 0x2649b8. _av_opt_show2 */

undefined8
_av_opt_show2(undefined8 *param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
             undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 uVar1;
  
  if (param_1 == (undefined8 *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined8 *)*param_1;
    _av_log(param_2,0x20,"%s AVOptions:\n");
    FUN_00264a3c(param_1,param_2,0,param_3,param_4,0xffffffff,param_7,param_8,uVar1);
    uVar1 = 0;
  }
  return uVar1;
}


