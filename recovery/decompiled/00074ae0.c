/* Decompiled from supplied 5.2.2 arm package. VA 0x74ae0. FUN_00074ae0 */

undefined1  [16] FUN_00074ae0(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  DAT_01226b9c = 1;
  _objc_msgSend(param_1,PTR_s_eventsDelegate_0114c740);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_resetAutoHideTimer_0114c748);
  _objc_msgSend(0x3ff0000000000000,uVar1,PTR_s_setPlaybackRate__0114c758);
  _objc_msgSend(param_1,PTR_s_speedValue_0114bcc8);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setTitle_forState__0114b6a8,
                &PTR____CFConstantStringClassReference_011645a0,0);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0x1f64);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


