/* Decompiled from supplied 5.2.2 arm package. VA 0x22e1f0. FUN_0022e1f0 */

undefined1  [16] FUN_0022e1f0(long param_1,undefined1 param_2)

{
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18;
  
  local_48 = PTR___NSConcreteStackBlock_01060660;
  local_40 = DAT_00c4c228;
  local_38 = FUN_0022e278;
  puStack_30 = &DAT_01062cc0;
  local_28 = *(undefined8 *)(param_1 + 0x20);
  local_18 = param_2;
  local_20 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
  _dispatch_async(PTR___dispatch_main_q_01060760,&local_48);
  _objc_release(local_20);
  CallSupervisor(0x5cb3);
  return ZEXT816(0x1f);
}


