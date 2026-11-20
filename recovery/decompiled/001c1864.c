/* Decompiled from supplied 5.2.2 arm package. VA 0x1c1864. FUN_001c1864 */

undefined1  [16] FUN_001c1864(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  undefined1 auVar3 [16];
  undefined *local_98;
  undefined8 local_90;
  code *local_88;
  undefined *puStack_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  *(undefined1 *)(*(long *)(param_1 + 0x20) + (long)ToastView::_ignoresFullscreenOpacity) = 1;
  *(undefined1 *)(*(long *)(param_1 + 0x20) + (long)ToastView::_ignoresPanGesture) =
       *(undefined1 *)(param_1 + 0x48);
  _objc_msgSend(0x3f800000,*(undefined8 *)(param_1 + 0x20),
                PTR_s_setupInterfaceWithText_progress__0114de28,*(undefined8 *)(param_1 + 0x28),1,0,
                0,0);
  lVar2 = (long)ToastView::_toastLabel;
  _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + lVar2),PTR_s_setTextAlignment__0114b5f8,
                4);
  _objc_msgSend(0x402c000000000000,*(undefined8 *)PTR__UIFontWeightBold_01060560,
                PTR__OBJC_CLASS___UIFont_0114ec08,PTR_s_monospacedDigitSystemFontOfSize__0114b6e0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + lVar2),PTR_s_setFont__0114b5e8,uVar1);
  _objc_release(uVar1);
  _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + (long)ToastView::_toastButton),
                PTR_s_setImage_forState__0114adf0,*(undefined8 *)(param_1 + 0x30),0);
  _objc_msgSend(0,*(undefined8 *)(param_1 + 0x20),PTR_s_calculateToastParametersWithKeyb_0114dd38,
                &uStack_58,&local_60,&local_68);
  lVar2 = *(long *)(param_1 + 0x20);
  uVar1 = _objc_msgSend(*(undefined8 *)(lVar2 + ToastView::_widthConstraint),PTR_s_constant_0114de30
                       );
  local_98 = PTR___NSConcreteStackBlock_01060660;
  local_90 = DAT_00c4c228;
  local_88 = FUN_001c1a6c;
  puStack_80 = &DAT_01062ad0;
  local_70 = _objc_retain(*(undefined8 *)(param_1 + 0x38));
  local_78 = *(undefined8 *)(param_1 + 0x20);
  _objc_msgSend(uStack_58,local_60,local_68,uVar1,0x3ff0000000000000,DAT_00c4c2e0,lVar2,
                PTR_s_configureToastAppearanceWithBott_0114de38,&local_98);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(param_1 + 0x20),
                PTR_s_startTimerCountdown__0114de60);
  _objc_release(local_70);
  CallSupervisor(0x237d);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


