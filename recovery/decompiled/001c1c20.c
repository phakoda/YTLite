/* Decompiled from supplied 5.2.2 arm package. VA 0x1c1c20. FUN_001c1c20 */

void FUN_001c1c20(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  *(undefined1 *)(*(long *)(param_1 + 0x20) + (long)ToastView::_ignoresPanGesture) = 1;
  _objc_msgSend(0x3f800000,*(undefined8 *)(param_1 + 0x20),
                PTR_s_setupInterfaceWithText_progress__0114de28,*(undefined8 *)(param_1 + 0x28),0,0,
                0,0);
  _objc_msgSend(0,*(undefined8 *)(param_1 + 0x20),PTR_s_calculateToastParametersWithKeyb_0114dd38,
                &uStack_48,&local_50,&local_58);
  lVar1 = *(long *)(param_1 + 0x20);
  uVar2 = _objc_msgSend(*(undefined8 *)(lVar1 + ToastView::_widthConstraint),PTR_s_constant_0114de30
                       );
  _objc_msgSend(uStack_48,local_50,local_58,uVar2,0x3ff0000000000000,DAT_00c4c2e0,lVar1,
                PTR_s_configureToastAppearanceWithBott_0114de38,0);
  _objc_msgSend(0x4024000000000000,*(undefined8 *)(param_1 + 0x20),
                PTR_s_startTimerCountdown__0114de60);
  return;
}


