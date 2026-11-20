/* Decompiled from supplied 5.2.2 arm package. VA 0x1c1150. FUN_001c1150 */

void FUN_001c1150(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined *local_b0;
  undefined8 local_a8;
  code *local_a0;
  undefined *puStack_98;
  undefined8 local_90;
  undefined8 local_88;
  
  *(undefined1 *)(*(long *)(param_1 + 0x20) + (long)ToastView::_ignoresFullscreenOpacity) = 1;
  _objc_msgSend(0x3f800000,*(undefined8 *)(param_1 + 0x20),
                PTR_s_setupInterfaceWithText_progress__0114de28,*(undefined8 *)(param_1 + 0x28),0,0,
                0,0);
  lVar8 = (long)ToastView::_toastLabel;
  _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + lVar8),PTR_s_setTextAlignment__0114b5f8,
                4);
  uVar9 = *(undefined8 *)PTR__UIFontWeightBold_01060560;
  _objc_msgSend(0x402c000000000000,uVar9,PTR__OBJC_CLASS___UIFont_0114ec08,
                PTR_s_monospacedDigitSystemFontOfSize__0114b6e0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_setFont__0114b5e8;
  _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + lVar8),PTR_s_setFont__0114b5e8,uVar4);
  _objc_release(uVar4);
  _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + (long)ToastView::_toastButton),
                PTR_s_setHidden__0114bfc0,1);
  puVar1 = PTR__OBJC_CLASS___UIAction_0114ec40;
  local_b0 = PTR___NSConcreteStackBlock_01060660;
  local_a8 = DAT_00c4c228;
  local_a0 = FUN_001c1544;
  puStack_98 = &DAT_01062b90;
  local_88 = _objc_retain(*(undefined8 *)(param_1 + 0x38));
  local_90 = *(undefined8 *)(param_1 + 0x20);
  _objc_msgSend(puVar1,PTR_s_actionWithHandler__0114b6c8,&local_b0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIButton_0114ec38,PTR_s_buttonWithType__0114b6a0,0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setTitle_forState__0114b6a8,*(undefined8 *)(param_1 + 0x30),0);
  puVar1 = PTR_s_whiteColor_0114b080;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_whiteColor_0114b080);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_setTitleColor_forState__0114b6b0;
  _objc_msgSend(uVar5,PTR_s_setTitleColor_forState__0114b6b0,uVar6,0);
  _objc_release(uVar6);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(DAT_00c4c368,uVar6,PTR_s_colorWithAlphaComponent__0114b548);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,puVar3,uVar7,1);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_msgSend(uVar5,PTR_s_addAction_forControlEvents__0114b6d0,uVar4,0x40);
  _objc_msgSend(0x4018000000000000,0x4028000000000000,0x4018000000000000,0x4028000000000000,uVar5,
                PTR_s_setContentEdgeInsets__0114de68);
  _objc_msgSend(0x402a000000000000,uVar9,PTR__OBJC_CLASS___UIFont_0114ec08,
                PTR_s_systemFontOfSize_weight__0114d330);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_titleLabel_0114b6d8);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar2,uVar6);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_msgSend(0x447a0000,uVar5,PTR_s_setContentHuggingPriority_forAxi_0114dce0,0);
  _objc_msgSend(0x447a0000,uVar5,PTR_s_setContentCompressionResistanceP_0114dce8,0);
  _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + (long)ToastView::_actionsStack),
                PTR_s_addArrangedSubview__0114b860,uVar5);
  _objc_msgSend(0,*(undefined8 *)(param_1 + 0x20),PTR_s_calculateToastParametersWithKeyb_0114dd38,
                &uStack_b8,&local_c0,&local_c8);
  lVar8 = *(long *)(param_1 + 0x20);
  uVar6 = _objc_msgSend(*(undefined8 *)(lVar8 + ToastView::_widthConstraint),PTR_s_constant_0114de30
                       );
  _objc_msgSend(uStack_b8,local_c0,local_c8,uVar6,0x3ff0000000000000,DAT_00c4c2e0,lVar8,
                PTR_s_configureToastAppearanceWithBott_0114de38,0);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(param_1 + 0x20),
                PTR_s_startTimerCountdown__0114de60);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(local_88);
  return;
}


