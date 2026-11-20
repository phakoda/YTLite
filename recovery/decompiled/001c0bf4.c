/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0bf4. FUN_001c0bf4 */

undefined1  [16] FUN_001c0bf4(long param_1)

{
  dispatch_time_t dVar1;
  undefined1 auVar2 [16];
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  undefined8 local_28;
  
  dVar1 = _dispatch_time(0,500000000);
  local_48 = PTR___NSConcreteStackBlock_01060660;
  local_40 = DAT_00c4c228;
  local_38 = FUN_001c0c84;
  puStack_30 = &DAT_01061420;
  local_28 = *(undefined8 *)(param_1 + 0x20);
  _dispatch_after(dVar1,PTR___dispatch_main_q_01060760,&local_48);
  CallSupervisor(0x34fc);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


