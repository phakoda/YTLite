/* Decompiled from supplied 5.2.2 arm package. VA 0xc2050. FUN_000c2050 */

undefined1  [16] FUN_000c2050(undefined8 param_1,undefined1 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  undefined *local_50;
  undefined8 local_48;
  code *local_40;
  undefined *puStack_38;
  undefined8 local_30;
  undefined1 local_28;
  
  _objc_retain(param_3);
  local_50 = PTR___NSConcreteStackBlock_01060660;
  local_48 = DAT_00c4c228;
  local_40 = FUN_000c20f4;
  puStack_38 = &DAT_01061d80;
  local_30 = param_3;
  local_28 = param_2;
  _objc_retain(param_3);
  _dispatch_async(PTR___dispatch_main_q_01060760,&local_50);
  _objc_release(local_30);
  _objc_release(param_3);
  CallSupervisor(0x130a);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}


