/* Decompiled from supplied 5.2.2 arm package. VA 0x1c080. FUN_0001c080 */

undefined1  [16] FUN_0001c080(long param_1)

{
  undefined1 auVar1 [16];
  undefined *local_38;
  undefined8 local_30;
  code *local_28;
  undefined *puStack_20;
  undefined8 local_18;
  
  local_18 = *(undefined8 *)(param_1 + 0x20);
  local_38 = PTR___NSConcreteStackBlock_01060660;
  local_30 = DAT_00c4c230;
  local_28 = FUN_0001c0f8;
  puStack_20 = &DAT_01061470;
  _objc_msgSend(local_18,PTR_s_dismissViewControllerAnimated_co_0114aed0,1,&local_38);
  CallSupervisor(0x445d);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}


