/* Decompiled from supplied 5.2.2 arm package. VA 0x250f0. FUN_000250f0 */

undefined1  [16] FUN_000250f0(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  undefined8 local_28;
  
  uVar1 = DAT_01225d18;
  DAT_01225d18 = 0;
  _objc_release(uVar1);
  _isYTPFirstTime = 1;
  thunk_FUN_0002495c();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _dispatch_get_global_queue(0,0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  local_48 = PTR___NSConcreteStackBlock_01060660;
  local_40 = DAT_00c4c228;
  local_38 = FUN_000251cc;
  puStack_30 = &DAT_01061420;
  local_28 = uVar1;
  _objc_retain(uVar1);
  _dispatch_async(uVar2,&local_48);
  _objc_release(uVar2);
  _objc_release(local_28);
  _objc_release(uVar1);
  CallSupervisor(0x9509);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


