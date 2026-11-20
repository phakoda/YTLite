/* Decompiled from supplied 5.2.2 arm package. VA 0xa9c2c. FUN_000a9c2c */

undefined1  [16]
FUN_000a9c2c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  
  pcVar1 = DAT_01226640;
  _objc_retain(param_4);
  _objc_retain(param_3);
  (*pcVar1)(param_1,param_2,param_3,param_4);
  _addEndTime(param_1,param_3,param_4);
  _autoSkipShortsLegacy(param_1,param_3,param_4);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0xe00b);
  return ZEXT816(0x1f);
}


