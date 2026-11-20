/* Decompiled from supplied 5.2.2 arm package. VA 0x1f55b4. FUN_001f55b4 */

undefined1  [16] FUN_001f55b4(long param_1)

{
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  
  local_28 = _objc_msgSend(PTR_MobileFFmpeg_0114eff0,PTR_s_execute__0114e290,
                           *(undefined8 *)(param_1 + 0x20));
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_001f5678;
  puStack_48 = &DAT_01062f50;
  local_40 = *(undefined8 *)(param_1 + 0x28);
  local_30 = _objc_retain(*(undefined8 *)(param_1 + 0x38));
  local_38 = _objc_retain(*(undefined8 *)(param_1 + 0x30));
  _dispatch_async(PTR___dispatch_main_q_01060760,&local_60);
  _objc_release(local_38);
  _objc_release(local_30);
  CallSupervisor(0x7954);
  return ZEXT816(0x1f);
}


