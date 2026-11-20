/* Decompiled from supplied 5.2.2 arm package. VA 0x26d6d8. _av_timecode_init */

void _av_timecode_init(undefined8 *param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                      undefined8 param_5)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 2) = 0;
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)param_1 = param_4;
  *(undefined4 *)((long)param_1 + 4) = param_3;
  param_1[1] = param_2;
  uVar1 = FUN_0026d6b0(param_2);
  *(undefined4 *)(param_1 + 2) = uVar1;
  FUN_0026d71c(param_5,param_1);
  return;
}


