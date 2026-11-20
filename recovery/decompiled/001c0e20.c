/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0e20. FUN_001c0e20 */

undefined1  [16] FUN_001c0e20(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  *(undefined1 *)(*(long *)(param_1 + 0x20) + (long)ToastView::_ignoresFullscreenOpacity) = 1;
  uVar1 = _objc_alloc(PTR__OBJC_CLASS___UIImpactFeedbackGenerator_0114ec68);
  uVar1 = _objc_msgSend(uVar1,PTR_s_initWithStyle__0114b790,1);
  _objc_msgSend(uVar1,PTR_s_prepare_0114b798);
  _objc_msgSend(uVar1,PTR_s_impactOccurred_0114b918);
  _objc_msgSend(0x3f800000,*(undefined8 *)(param_1 + 0x20),
                PTR_s_setupInterfaceWithText_progress__0114de28,*(undefined8 *)(param_1 + 0x28),0,1,
                *(undefined1 *)(param_1 + 0x38),0);
  _objc_msgSend(0,*(undefined8 *)(param_1 + 0x20),PTR_s_calculateToastParametersWithKeyb_0114dd38,
                &uStack_58,&local_60,&local_68);
  lVar2 = *(long *)(param_1 + 0x20);
  uVar3 = _objc_msgSend(*(undefined8 *)(lVar2 + ToastView::_widthConstraint),PTR_s_constant_0114de30
                       );
  _objc_msgSend(uStack_58,local_60,local_68,uVar3,0x3ff0000000000000,DAT_00c4c2e0,lVar2,
                PTR_s_configureToastAppearanceWithBott_0114de38,0);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x30),*(undefined8 *)(param_1 + 0x20),
                PTR_s_startTimerCountdown__0114de60);
  _objc_release(uVar1);
  CallSupervisor(0x11e6);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}


