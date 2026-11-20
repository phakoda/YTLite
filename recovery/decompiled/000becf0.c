/* Decompiled from supplied 5.2.2 arm package. VA 0xbecf0. FUN_000becf0 */

undefined1  [16] FUN_000becf0(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  _objc_msgSend(PTR__OBJC_CLASS___AVAudioSession_0114ed08,PTR_s_sharedInstance_0114c418);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  FUN_000ec3c0(uVar2,PTR_s_setActive_withOptions_error__0114c480,0,1,0);
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___CATransaction_0114ed20,PTR_s_begin_0114c468);
  _objc_msgSend(DAT_00c4c2b8,PTR__OBJC_CLASS___CATransaction_0114ed20,
                PTR_s_setAnimationDuration__0114c470);
  puVar1 = PTR__OBJC_CLASS___CATransaction_0114ed20;
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_000bee20;
  puStack_48 = &DAT_01061b00;
  local_40 = _objc_retain(*(undefined8 *)(param_1 + 0x20));
  uStack_38 = *(undefined8 *)(param_1 + 0x28);
  _objc_msgSend(puVar1,PTR_s_setCompletionBlock__0114c498,&local_60);
  _objc_msgSend(0,*(undefined8 *)(param_1 + 0x20),PTR_s_setOpacity__0114c450);
  _objc_msgSend(PTR__OBJC_CLASS___CATransaction_0114ed20,PTR_s_commit_0114c478);
  _objc_release(local_40);
  CallSupervisor(0xd7f3);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


