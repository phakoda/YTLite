// Decompiled implementation evidence for PlayerToast. Not compilable source.

// -[PlayerToast init], 0x23b560
/* Decompiled from supplied 5.2.2 arm package. VA 0x23b560. init */

/* Function Stack Size: 0x10 bytes */

ID PlayerToast::init(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined8 uVar10;
  ID IVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  ID local_80;
  undefined *puStack_78;
  uint local_6c;
  undefined **local_68;
  
  local_68 = &PTR_LAB_011d2830;
  _objc_msgSend(PTR__OBJC_CLASS___UIBlurEffect_0114ebe0,@selector(effectWithStyle:),5);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puStack_78 = PTR_PlayerToast_0114f168;
  local_80 = param_1;
  IVar11 = _objc_msgSendSuper2(&local_80,@selector(init));
  local_6c = (uint)(IVar11 == 0);
  if (IVar11 != 0) {
    uVar12 = _objc_msgSend(PTR_CustomHUD_0114f038,@selector(new));
    uVar14 = *(undefined8 *)(IVar11 + (long)_volumeHUD);
    *(undefined8 *)(IVar11 + (long)_volumeHUD) = uVar12;
    _objc_release(uVar14);
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
    uVar12 = _objc_retainAutoreleasedReturnValue();
    uVar14 = *(undefined8 *)(IVar11 + (long)_activeConstraints);
    *(undefined8 *)(IVar11 + (long)_activeConstraints) = uVar12;
    _objc_release(uVar14);
    _objc_msgSend(0,IVar11,@selector(setAlpha:));
    _objc_msgSend(IVar11,@selector(setUserInteractionEnabled:),0);
    puVar2 = @selector(setTranslatesAutoresizingMaskIntoConstraints:);
    _objc_msgSend(IVar11,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(blackColor));
    uVar12 = _objc_retainAutoreleasedReturnValue();
    uVar14 = _objc_retainAutorelease();
    uVar14 = _objc_msgSend(uVar14,@selector(CGColor));
    puVar1 = @selector(layer);
    _objc_msgSend(IVar11,@selector(layer));
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar13,@selector(setShadowColor:),uVar14);
    _objc_release(uVar13);
    _objc_release(uVar12);
    _objc_msgSend(IVar11,puVar1);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(0,0x4000000000000000,uVar12,@selector(setShadowOffset:));
    _objc_release(uVar12);
    _objc_msgSend(IVar11,puVar1);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(0x4028000000000000,uVar12,@selector(setShadowRadius:));
    _objc_release(uVar12);
    _objc_msgSend(IVar11,puVar1);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(DAT_00c4c548,uVar12,@selector(setShadowOpacity:));
    _objc_release(uVar12);
    uVar12 = _objc_alloc(PTR__OBJC_CLASS___UIVisualEffectView_0114ebd8);
    uVar12 = _objc_msgSend(uVar12,@selector(initWithEffect:),uVar10);
    lVar17 = (long)_toastView;
    uVar14 = *(undefined8 *)(IVar11 + lVar17);
    *(undefined8 *)(IVar11 + lVar17) = uVar12;
    _objc_release(uVar14);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar17),@selector(setAutoresizingMask:),0x12);
    uVar13 = *(undefined8 *)PTR__kCACornerCurveContinuous_01060bb0;
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar17),puVar1);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    puVar6 = @selector(setCornerCurve:);
    _objc_msgSend(uVar12,@selector(setCornerCurve:),uVar13);
    _objc_release(uVar12);
    puVar8 = @selector(setClipsToBounds:);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar17),@selector(setClipsToBounds:),1);
    uVar12 = _objc_alloc_init(PTR__OBJC_CLASS___UIImageView_0114ebf0);
    lVar15 = (long)_toastImage;
    uVar14 = *(undefined8 *)(IVar11 + lVar15);
    *(undefined8 *)(IVar11 + lVar15) = uVar12;
    _objc_release(uVar14);
    puVar9 = @selector(secondaryLabelColor);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(secondaryLabelColor));
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar15),@selector(setTintColor:),uVar12);
    _objc_release(uVar12);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar15),@selector(setContentMode:),1);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar15),puVar2,0);
    uVar12 = _objc_alloc_init(PTR__OBJC_CLASS___UILabel_0114ec00);
    lVar16 = (long)_toastLabel;
    uVar14 = *(undefined8 *)(IVar11 + lVar16);
    *(undefined8 *)(IVar11 + lVar16) = uVar12;
    _objc_release(uVar14);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar9);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    puVar3 = @selector(setTextColor:);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar16),@selector(setTextColor:),uVar12);
    _objc_release(uVar12);
    puVar7 = @selector(monospacedDigitSystemFontOfSize:weight:);
    _objc_msgSend(0x402a000000000000,*(undefined8 *)PTR__UIFontWeightBold_01060560,
                  PTR__OBJC_CLASS___UIFont_0114ec08,@selector(monospacedDigitSystemFontOfSize:weight:))
    ;
    uVar12 = _objc_retainAutoreleasedReturnValue();
    puVar4 = @selector(setFont:);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar16),@selector(setFont:),uVar12);
    _objc_release(uVar12);
    puVar5 = @selector(setTextAlignment:);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar16),@selector(setTextAlignment:),1);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar16),puVar2,0);
    uVar12 = _objc_alloc_init(PTR__OBJC_CLASS___UILabel_0114ec00);
    lVar20 = (long)_toastSubLabel;
    uVar14 = *(undefined8 *)(IVar11 + lVar20);
    *(undefined8 *)(IVar11 + lVar20) = uVar12;
    _objc_release(uVar14);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar9);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar20),puVar3,uVar12);
    _objc_release(uVar12);
    _objc_msgSend(0x402a000000000000,*(undefined8 *)PTR__UIFontWeightRegular_01060578,
                  PTR__OBJC_CLASS___UIFont_0114ec08,puVar7);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar20),puVar4,uVar12);
    _objc_release(uVar12);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar20),puVar5,1);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar20),puVar2,0);
    uVar12 = _objc_alloc_init(PTR__OBJC_CLASS___UIView_0114ec30);
    lVar19 = (long)_toastProgress;
    uVar14 = *(undefined8 *)(IVar11 + lVar19);
    *(undefined8 *)(IVar11 + lVar19) = uVar12;
    _objc_release(uVar14);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar9);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(0x3fd0000000000000,uVar12,@selector(colorWithAlphaComponent:));
    uVar14 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar19),@selector(setBackgroundColor:),uVar14);
    _objc_release(uVar14);
    _objc_release(uVar12);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar19),puVar2,0);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar19),puVar8,1);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar19),puVar1);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(0x4000000000000000,uVar12,@selector(setCornerRadius:));
    _objc_release(uVar12);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar19),puVar1);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar12,puVar6,uVar13);
    _objc_release(uVar12);
    _objc_msgSend(PTR__OBJC_CLASS___CAShapeLayer_0114ef10,puVar1);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    lVar18 = (long)_progressLayer;
    uVar14 = *(undefined8 *)(IVar11 + lVar18);
    *(undefined8 *)(IVar11 + lVar18) = uVar12;
    _objc_release(uVar14);
    _objc_msgSend(0,0,0,0x4010000000000000,*(undefined8 *)(IVar11 + lVar18),@selector(setFrame:)
                 );
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar19),puVar1);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar12,@selector(addSublayer:),*(undefined8 *)(IVar11 + lVar18));
    _objc_release(uVar12);
    puVar1 = @selector(addSubview:);
    _objc_msgSend(IVar11,@selector(addSubview:),*(undefined8 *)(IVar11 + lVar17));
    puVar2 = @selector(contentView);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar17),@selector(contentView));
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar12,puVar1,*(undefined8 *)(IVar11 + lVar15));
    _objc_release(uVar12);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar17),puVar2);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar12,puVar1,*(undefined8 *)(IVar11 + lVar16));
    _objc_release(uVar12);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar17),puVar2);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar12,puVar1,*(undefined8 *)(IVar11 + lVar20));
    _objc_release(uVar12);
    _objc_msgSend(*(undefined8 *)(IVar11 + lVar17),puVar2);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar12,puVar1,*(undefined8 *)(IVar11 + lVar19));
    _objc_release(uVar12);
  }
  _objc_release(uVar10);
  return IVar11;
}



// -[PlayerToast showPlayerToastWithText:value:style:isCompact:], 0x23bd28
/* Decompiled from supplied 5.2.2 arm package. VA 0x23bd28. showPlayerToastWithText:value:style:isCompact: */

/* Function Stack Size: 0x2c bytes */

void PlayerToast::showPlayerToastWithText_value_style_isCompact_
               (ID param_1,SEL param_2,ID param_3,double param_4,long_long param_5,bool param_6)

{
  ID IVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  long lVar15;
  undefined8 uVar16;
  undefined *local_b0;
  undefined8 local_a8;
  code *local_a0;
  undefined *puStack_98;
  ID local_90;
  undefined8 local_88;
  undefined8 local_80;
  long local_78;
  
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  *(long_long *)(param_1 + (long)_style) = param_5;
  lVar15 = (long)_isCompact;
  *(char *)(param_1 + lVar15) = (char)param_6;
  puVar2 = @selector(imgForVal:);
  _objc_retain(param_3);
  _objc_msgSend(param_4,param_1,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastImage),@selector(setImage:),uVar5);
  _objc_release(uVar5);
  puVar2 = @selector(setText:);
  IVar1 = param_3;
  if (*(char *)(param_1 + lVar15) != '\0') {
    IVar1 = 0;
  }
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastLabel),@selector(setText:),IVar1);
  _objc_release(param_3);
  _objc_msgSend(param_4,param_1,@selector(subLabelForVal:style:),param_5);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastSubLabel),puVar2,uVar5);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(secondaryLabelColor));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = _objc_retainAutorelease();
  uVar6 = _objc_msgSend(uVar6,@selector(CGColor));
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_progressLayer),@selector(setBackgroundColor:),
                uVar6);
  _objc_release(uVar5);
  _objc_msgSend(param_1,@selector(prepareForPresentation));
  _objc_msgSend(param_1,@selector(clearConstraints));
  _objc_msgSend(param_1,@selector(setupConstraints));
  _objc_msgSend(param_1,@selector(setupSubForStyle:),param_5);
  puVar3 = @selector(sourceView);
  _objc_msgSend(param_1,@selector(sourceView));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(addSubview:),param_1);
  _objc_release(uVar5);
  puVar2 = @selector(topAnchor);
  lVar15 = (long)_activeConstraints;
  uVar14 = *(undefined8 *)(param_1 + lVar15);
  _objc_msgSend(param_1,@selector(topAnchor));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar3);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(safeAreaLayoutGuide));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar2);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  iVar4 = FUN_0023ee84(param_1,@selector(isLandscape));
  uVar16 = 0x4014000000000000;
  if (iVar4 == 0) {
    uVar16 = 0x4034000000000000;
  }
  _objc_msgSend(uVar16,uVar5,@selector(constraintEqualToAnchor:constant:),uVar8);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(centerXAnchor);
  local_88 = uVar16;
  _objc_msgSend(param_1,@selector(centerXAnchor));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar3);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puVar2);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,@selector(constraintEqualToAnchor:),uVar11);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  local_80 = uVar12;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),&local_88,
                2);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar14,@selector(addObjectsFromArray:),uVar13);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar16);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20,@selector(activateConstraints:),
                *(undefined8 *)(param_1 + lVar15));
  local_b0 = PTR___NSConcreteStackBlock_01060660;
  local_a8 = DAT_00c4c228;
  local_a0 = FUN_0023c1a4;
  puStack_98 = &DAT_01061420;
  local_90 = param_1;
  _objc_msgSend(DAT_00c4c2e0,0,PTR__OBJC_CLASS___UIView_0114ec30,
                @selector(animateWithDuration:delay:options:animations:completion:),0x20000,&local_b0,0);
  CallSupervisor(0x5a5c);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_78) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}



// -[PlayerToast prepareForPresentation], 0x23c1e0
/* Decompiled from supplied 5.2.2 arm package. VA 0x23c1e0. prepareForPresentation */

/* Function Stack Size: 0x10 bytes */

void PlayerToast::prepareForPresentation(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(param_1,@selector(layer));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(removeAllAnimations));
  _objc_release(uVar1);
  _objc_msgSend(param_1,@selector(removeFromSuperview));
  _objc_msgSend(0,param_1,@selector(setAlpha:));
  CallSupervisor(0x36d);
  return;
}



// -[PlayerToast updateToastText:value:], 0x23c264
/* Decompiled from supplied 5.2.2 arm package. VA 0x23c264. updateToastText:value: */

/* Function Stack Size: 0x20 bytes */

void PlayerToast::updateToastText_value_(ID param_1,SEL param_2,ID param_3,double param_4)

{
  ID IVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  undefined *puStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined *puStack_78;
  ID IStack_70;
  undefined8 uStack_68;
  int local_5c;
  undefined **local_58;
  
  puVar2 = @selector(image);
  local_58 = &PTR_LAB_011d2850;
  lVar7 = (long)_toastImage;
  uVar6 = *(undefined8 *)(param_1 + lVar7);
  _objc_retain(param_3);
  _objc_msgSend(uVar6,puVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar7),@selector(setImage:),uVar6);
  _objc_release(uVar6);
  _objc_msgSend(param_4,param_1,@selector(setProgress:));
  puVar3 = @selector(setText:);
  IVar1 = param_3;
  if (*(char *)(param_1 + (long)_isCompact) != '\0') {
    IVar1 = 0;
  }
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastLabel),@selector(setText:),IVar1);
  _objc_release(param_3);
  lVar8 = (long)_style;
  _objc_msgSend((double)(long)(param_4 * 100.0),param_1,@selector(subLabelForVal:style:),
                *(undefined8 *)(param_1 + lVar8));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastSubLabel),puVar3,uVar6);
  _objc_release(uVar6);
  _objc_msgSend(param_4,param_1,@selector(setValue:forEventWithStyle:),
                *(undefined8 *)(param_1 + lVar8));
  _objc_msgSend((double)(long)(param_4 * 100.0),param_1,@selector(imgForVal:));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar7),puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  iVar4 = FUN_0023f18c(uVar5,@selector(isEqual:),uVar6);
  _objc_release(uVar5);
  puVar2 = PTR__OBJC_CLASS___UIView_0114ec30;
  local_5c = iVar4;
  if (iVar4 == 0) {
    uVar5 = *(undefined8 *)(param_1 + lVar7);
    puStack_90 = PTR___NSConcreteStackBlock_01060660;
    uStack_88 = DAT_00c4c228;
    pcStack_80 = FUN_0023c4e8;
    puStack_78 = &DAT_01061f70;
    IStack_70 = param_1;
    _objc_retain(uVar6);
    uStack_68 = uVar6;
    _objc_msgSend(0x3fe0000000000000,puVar2,@selector(transitionWithView:duration:options:animations:completion:),uVar5,
                  0x500000,&puStack_90,0);
    _objc_release(uStack_68);
  }
  _objc_release(uVar6);
  CallSupervisor(0x6e0b);
  return;
}



// -[PlayerToast setProgress:], 0x23c52c
/* Decompiled from supplied 5.2.2 arm package. VA 0x23c52c. setProgress: */

/* Function Stack Size: 0x18 bytes */

void __thiscall PlayerToast::setProgress_(PlayerToast *this,ID param_1,SEL param_2,double param_3)

{
  undefined *puVar1;
  long lVar2;
  double dVar3;
  double in_d2;
  
  puVar1 = @selector(bounds);
  lVar2 = (long)_toastProgress;
  _objc_msgSend(*(undefined8 *)(this + lVar2),@selector(bounds));
  if (0.0 < in_d2) {
    dVar3 = 1.0;
    if (param_3 <= 1.0) {
      dVar3 = param_3;
    }
    if (dVar3 <= 0.0) {
      dVar3 = 0.0;
    }
    _objc_msgSend(PTR__OBJC_CLASS___CATransaction_0114ed20,@selector(begin));
    _objc_msgSend(PTR__OBJC_CLASS___CATransaction_0114ed20,@selector(setDisableActions:),0);
    _objc_msgSend(DAT_00c4c2f0,PTR__OBJC_CLASS___CATransaction_0114ed20,
                  @selector(setAnimationDuration:));
    _objc_msgSend(*(undefined8 *)(this + lVar2),puVar1);
    _objc_msgSend(0,0,dVar3 * in_d2,*(undefined8 *)(this + _progressLayer),@selector(setFrame:))
    ;
    _objc_msgSend(PTR__OBJC_CLASS___CATransaction_0114ed20,@selector(commit));
  }
  CallSupervisor(0xa550);
  return;
}



// -[PlayerToast hideToast], 0x23c67c
/* Decompiled from supplied 5.2.2 arm package. VA 0x23c67c. hideToast */

/* Function Stack Size: 0x10 bytes */

void PlayerToast::hideToast(ID param_1,SEL param_2)

{
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  ID local_40;
  undefined *puStack_38;
  undefined8 local_30;
  code *local_28;
  undefined *puStack_20;
  ID local_18;
  
  puStack_38 = PTR___NSConcreteStackBlock_01060660;
  local_30 = DAT_00c4c228;
  local_28 = FUN_0023c710;
  puStack_20 = &DAT_01061420;
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_0023c724;
  puStack_48 = &DAT_01061940;
  local_40 = param_1;
  local_18 = param_1;
  _objc_msgSend(DAT_00c4c2e0,0x3ff0000000000000,PTR__OBJC_CLASS___UIView_0114ec30,
                @selector(animateWithDuration:delay:options:animations:completion:),0x10000,&puStack_38,&local_60);
  return;
}



// -[PlayerToast setupConstraints], 0x23c7cc
/* Decompiled from supplied 5.2.2 arm package. VA 0x23c7cc. setupConstraints */

/* Function Stack Size: 0x10 bytes */

void PlayerToast::setupConstraints(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  undefined8 uVar31;
  undefined8 uVar32;
  undefined8 uVar33;
  undefined8 uVar34;
  undefined8 uVar35;
  undefined8 uVar36;
  undefined8 uVar37;
  undefined8 uVar38;
  undefined8 uVar39;
  undefined8 uVar40;
  undefined8 uVar41;
  undefined8 uVar42;
  undefined8 uVar43;
  undefined8 uVar44;
  undefined8 uVar45;
  undefined8 uVar46;
  undefined8 uVar47;
  undefined8 uVar48;
  long lVar49;
  undefined8 uVar50;
  long lVar51;
  long lVar52;
  long lVar53;
  undefined8 uVar54;
  undefined8 uVar55;
  undefined8 uVar56;
  undefined8 uVar57;
  undefined8 uVar58;
  undefined8 uVar59;
  undefined8 uVar60;
  undefined8 uVar61;
  undefined8 uVar62;
  undefined8 uVar63;
  undefined8 uVar64;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  long local_a0;
  
  local_a0 = *(long *)PTR____stack_chk_guard_01060708;
  lVar53 = (long)_isCompact;
  uVar64 = 0x4039000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar64 = 0x402e000000000000;
  }
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastView),@selector(layer));
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar64,uVar10,@selector(setCornerRadius:));
  _objc_release(uVar10);
  lVar49 = (long)_toastLabel;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar49),@selector(setHidden:),
                *(undefined1 *)(param_1 + lVar53));
  puVar9 = PTR__OBJC_CLASS___NSMutableArray_0114eb90;
  puVar4 = @selector(heightAnchor);
  _objc_msgSend(param_1,@selector(heightAnchor));
  uVar64 = _objc_retainAutoreleasedReturnValue();
  puVar5 = @selector(constraintEqualToConstant:);
  uVar10 = 0x4049000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar10 = 0x403e000000000000;
  }
  _objc_msgSend(uVar10);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puVar6 = @selector(widthAnchor);
  local_130 = uVar10;
  _objc_msgSend(param_1,@selector(widthAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar8 = @selector(constraintGreaterThanOrEqualToConstant:);
  uVar54 = 0x4069000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar54 = 0x4059000000000000;
  }
  _objc_msgSend(uVar54);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar7 = @selector(centerYAnchor);
  lVar51 = (long)_toastImage;
  local_128 = uVar12;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar51),@selector(centerYAnchor));
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar7);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,@selector(constraintEqualToAnchor:),uVar14);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  local_120 = uVar15;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar51),@selector(centerXAnchor));
  uVar16 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(leadingAnchor);
  _objc_msgSend(param_1,@selector(leadingAnchor));
  uVar17 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(constraintEqualToAnchor:constant:);
  uVar54 = DAT_00c4c360;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar54 = 0x4034000000000000;
  }
  _objc_msgSend(uVar54,uVar16,@selector(constraintEqualToAnchor:constant:),uVar17);
  uVar54 = _objc_retainAutoreleasedReturnValue();
  local_118 = uVar54;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar51),puVar4);
  uVar18 = _objc_retainAutoreleasedReturnValue();
  uVar55 = 0x4039000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar55 = 0x402e000000000000;
  }
  _objc_msgSend(uVar55,uVar18,puVar5);
  uVar55 = _objc_retainAutoreleasedReturnValue();
  local_110 = uVar55;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar51),puVar6);
  uVar19 = _objc_retainAutoreleasedReturnValue();
  uVar56 = 0x4039000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar56 = 0x402e000000000000;
  }
  _objc_msgSend(uVar56,uVar19,puVar5);
  uVar56 = _objc_retainAutoreleasedReturnValue();
  local_108 = uVar56;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar49),puVar1);
  uVar20 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(trailingAnchor);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar51),@selector(trailingAnchor));
  uVar21 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4024000000000000,uVar20,puVar3,uVar21);
  uVar22 = _objc_retainAutoreleasedReturnValue();
  local_100 = uVar22;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar49),puVar2);
  uVar23 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar2);
  uVar24 = _objc_retainAutoreleasedReturnValue();
  uVar57 = 0xc044000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar57 = 0xc039000000000000;
  }
  _objc_msgSend(uVar57,uVar23,puVar3,uVar24);
  uVar57 = _objc_retainAutoreleasedReturnValue();
  local_f8 = uVar57;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar49),puVar7);
  uVar25 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar7);
  uVar26 = _objc_retainAutoreleasedReturnValue();
  uVar58 = 0xc024000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar58 = 0;
  }
  _objc_msgSend(uVar58,uVar25,puVar3,uVar26);
  uVar58 = _objc_retainAutoreleasedReturnValue();
  lVar52 = (long)_toastSubLabel;
  local_f0 = uVar58;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar1);
  uVar27 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar51),puVar2);
  uVar28 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4024000000000000,uVar27,puVar3,uVar28);
  uVar29 = _objc_retainAutoreleasedReturnValue();
  local_e8 = uVar29;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar2);
  uVar30 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar2);
  uVar31 = _objc_retainAutoreleasedReturnValue();
  uVar59 = 0xc044000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar59 = 0xc039000000000000;
  }
  _objc_msgSend(uVar59,uVar30,puVar3,uVar31);
  uVar59 = _objc_retainAutoreleasedReturnValue();
  local_e0 = uVar59;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar7);
  uVar32 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar7);
  uVar33 = _objc_retainAutoreleasedReturnValue();
  uVar60 = 0x4024000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar60 = 0;
  }
  _objc_msgSend(uVar60,uVar32,puVar3,uVar33);
  uVar60 = _objc_retainAutoreleasedReturnValue();
  lVar52 = (long)_toastProgress;
  local_d8 = uVar60;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar6);
  uVar34 = _objc_retainAutoreleasedReturnValue();
  uVar61 = 0x4059000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar61 = 0x404e000000000000;
  }
  _objc_msgSend(uVar61,uVar34,puVar8);
  uVar61 = _objc_retainAutoreleasedReturnValue();
  local_d0 = uVar61;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar6);
  uVar35 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar49),puVar6);
  uVar36 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar35,@selector(constraintGreaterThanOrEqualToAnchor:),uVar36);
  uVar37 = _objc_retainAutoreleasedReturnValue();
  local_c8 = uVar37;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar4);
  uVar38 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4010000000000000,uVar38,puVar5);
  uVar39 = _objc_retainAutoreleasedReturnValue();
  local_c0 = uVar39;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar1);
  uVar40 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar51),puVar2);
  uVar41 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4024000000000000,uVar40,puVar3,uVar41);
  uVar42 = _objc_retainAutoreleasedReturnValue();
  local_b8 = uVar42;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar2);
  uVar43 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar2);
  uVar44 = _objc_retainAutoreleasedReturnValue();
  uVar62 = 0xc044000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar62 = 0xc039000000000000;
  }
  _objc_msgSend(uVar62,uVar43,puVar3,uVar44);
  uVar62 = _objc_retainAutoreleasedReturnValue();
  local_b0 = uVar62;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar7);
  uVar45 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar7);
  uVar46 = _objc_retainAutoreleasedReturnValue();
  uVar63 = 0x4024000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar63 = 0;
  }
  _objc_msgSend(uVar63,uVar45,puVar3,uVar46);
  uVar63 = _objc_retainAutoreleasedReturnValue();
  local_a8 = uVar63;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),&local_130
                ,0x12);
  uVar47 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar9,@selector(arrayWithArray:),uVar47);
  uVar48 = _objc_retainAutoreleasedReturnValue();
  uVar50 = *(undefined8 *)(param_1 + (long)_activeConstraints);
  *(undefined8 *)(param_1 + (long)_activeConstraints) = uVar48;
  _objc_release(uVar50);
  _objc_release(uVar47);
  _objc_release(uVar63);
  _objc_release(uVar46);
  _objc_release(uVar45);
  _objc_release(uVar62);
  _objc_release(uVar44);
  _objc_release(uVar43);
  _objc_release(uVar42);
  _objc_release(uVar41);
  _objc_release(uVar40);
  _objc_release(uVar39);
  _objc_release(uVar38);
  _objc_release(uVar37);
  _objc_release(uVar36);
  _objc_release(uVar35);
  _objc_release(uVar61);
  _objc_release(uVar34);
  _objc_release(uVar60);
  _objc_release(uVar33);
  _objc_release(uVar32);
  _objc_release(uVar59);
  _objc_release(uVar31);
  _objc_release(uVar30);
  _objc_release(uVar29);
  _objc_release(uVar28);
  _objc_release(uVar27);
  _objc_release(uVar58);
  _objc_release(uVar26);
  _objc_release(uVar25);
  _objc_release(uVar57);
  _objc_release(uVar24);
  _objc_release(uVar23);
  _objc_release(uVar22);
  _objc_release(uVar21);
  _objc_release(uVar20);
  _objc_release(uVar56);
  _objc_release(uVar19);
  _objc_release(uVar55);
  _objc_release(uVar18);
  _objc_release(uVar54);
  _objc_release(uVar17);
  _objc_release(uVar16);
  _objc_release(uVar15);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar64);
  CallSupervisor(0x954c);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_a0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}



// -[PlayerToast clearConstraints], 0x23d138
/* Decompiled from supplied 5.2.2 arm package. VA 0x23d138. clearConstraints */

/* Function Stack Size: 0x10 bytes */

void PlayerToast::clearConstraints(ID param_1,SEL param_2)

{
  long lVar1;
  
  lVar1 = (long)_activeConstraints;
  _objc_msgSend(PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20,@selector(deactivateConstraints:),
                *(undefined8 *)(param_1 + lVar1));
  _objc_msgSend(*(undefined8 *)(param_1 + lVar1),@selector(removeAllObjects));
  return;
}



// -[PlayerToast imgForVal:], 0x23d180
/* Decompiled from supplied 5.2.2 arm package. VA 0x23d180. imgForVal: */

/* Function Stack Size: 0x18 bytes */

ID PlayerToast::imgForVal_(ID param_1,SEL param_2,double param_3)

{
  ID IVar1;
  
  if (DAT_0122854c != 0) {
    DAT_0122854c = 1;
                    /* WARNING: Could not recover jumptable at 0x0023d2c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar1 = (*(code *)((&PTR_LAB_011d28d8)[*(long *)(param_1 + (long)_style) < 1] +
                      (int)-(uRam00000000011d28e8 ^ 0xb515959c)))();
    return IVar1;
  }
  s_vol_low_011d2352[0] = DAT_011d234a ^ 0x8e;
  s_vol_low_011d2352[1] = bRam00000000011d234b ^ 0xf9;
  s_vol_low_011d2352[2] = bRam00000000011d234c ^ 0x70;
  s_vol_low_011d2352[3] = bRam00000000011d234d ^ 0x21;
  s_vol_low_011d2352[4] = bRam00000000011d234e ^ 0x2f;
  s_vol_low_011d2352[5] = bRam00000000011d234f ^ 0x5c;
  s_vol_low_011d2352[6] = bRam00000000011d2350 ^ 200;
  s_vol_low_011d2352[7] = bRam00000000011d2351 ^ 0x9d;
  s_speed_fast_011d233f[0] = DAT_011d2334 ^ 0x76;
  s_speed_fast_011d233f[1] = DAT_011d2335 ^ 0xe1;
  s_speed_fast_011d233f[2] = DAT_011d2336 ^ 0xa2;
  s_speed_fast_011d233f[3] = DAT_011d2337 ^ 0x2a;
  s_speed_fast_011d233f[4] = DAT_011d2338 ^ 0xf5;
  s_speed_fast_011d233f[5] = DAT_011d2339 ^ 0xed;
  s_speed_fast_011d233f[6] = DAT_011d233a ^ 0xe3;
  s_speed_fast_011d233f[7] = DAT_011d233b ^ 0xe9;
  s_speed_fast_011d233f[8] = DAT_011d233c ^ 0x6e;
  s_speed_fast_011d233f[9] = DAT_011d233d ^ 0x36;
  s_speed_fast_011d233f[10] = DAT_011d233e ^ 0x30;
  s_speed_slow_011d2375[0] = DAT_011d236a ^ 0x1b;
  s_speed_slow_011d2375[1] = DAT_011d236b ^ 0x7a;
  s_speed_slow_011d2375[2] = DAT_011d236c ^ 0x48;
  s_speed_slow_011d2375[3] = DAT_011d236d ^ 0x87;
  s_speed_slow_011d2375[4] = DAT_011d236e ^ 0xf2;
  s_speed_slow_011d2375[5] = DAT_011d236f ^ 0xeb;
  s_speed_slow_011d2375[6] = DAT_011d2370 ^ 0x9b;
  s_speed_slow_011d2375[7] = DAT_011d2371 ^ 0x59;
  s_speed_slow_011d2375[8] = DAT_011d2372 ^ 0xe8;
  s_speed_slow_011d2375[9] = DAT_011d2373 ^ 0x41;
  s_speed_slow_011d2375[10] = DAT_011d2374 ^ 0x20;
  s_sun_min_011d232c[0] = DAT_011d2324 ^ 0xb;
  s_sun_min_011d232c[1] = DAT_011d2325 ^ 0xe3;
  s_sun_min_011d232c[2] = DAT_011d2326 ^ 0x27;
  s_sun_min_011d232c[3] = DAT_011d2327 ^ 0x87;
  s_sun_min_011d232c[4] = DAT_011d2328 ^ 0xa2;
  s_sun_min_011d232c[5] = DAT_011d2329 ^ 0x59;
  s_sun_min_011d232c[6] = DAT_011d232a ^ 0x45;
  s_sun_min_011d232c[7] = DAT_011d232b ^ 0xd3;
  s_speed_reg_011d230a[0] = DAT_011d2300 ^ 0x87;
  s_speed_reg_011d230a[1] = DAT_011d2301 ^ 0xc9;
  s_speed_reg_011d230a[2] = DAT_011d2302 ^ 0x90;
  s_speed_reg_011d230a[3] = DAT_011d2303 ^ 0x7e;
  s_speed_reg_011d230a[4] = DAT_011d2304 ^ 0xb7;
  s_speed_reg_011d230a[5] = DAT_011d2305 ^ 0xb5;
  s_speed_reg_011d230a[6] = DAT_011d2306 ^ 0x42;
  s_speed_reg_011d230a[7] = DAT_011d2307 ^ 0xcb;
  s_speed_reg_011d230a[8] = DAT_011d2308 ^ 0xe5;
  s_speed_reg_011d230a[9] = DAT_011d2309 ^ 0x43;
  s_vol_off_011d22f8[0] = DAT_011d22f0 ^ 0x7c;
  s_vol_off_011d22f8[1] = DAT_011d22f1 ^ 0x58;
  s_vol_off_011d22f8[2] = DAT_011d22f2 ^ 0x92;
  s_vol_off_011d22f8[3] = DAT_011d22f3 ^ 0x5a;
  s_vol_off_011d22f8[4] = DAT_011d22f4 ^ 0xfb;
  s_vol_off_011d22f8[5] = DAT_011d22f5 ^ 0xd7;
  s_vol_off_011d22f8[6] = DAT_011d22f6 ^ 0x48;
  s_vol_off_011d22f8[7] = DAT_011d22f7 ^ 0x93;
  s_sun_max_011d2388[0] = DAT_011d2380 ^ 0xc1;
  s_sun_max_011d2388[1] = DAT_011d2381 ^ 0x29;
  s_sun_max_011d2388[2] = DAT_011d2382 ^ 0xd1;
  s_sun_max_011d2388[3] = DAT_011d2383 ^ 0xbf;
  s_sun_max_011d2388[4] = DAT_011d2384 ^ 0xe8;
  s_sun_max_011d2388[5] = DAT_011d2385 ^ 0xed;
  s_sun_max_011d2388[6] = DAT_011d2386 ^ 0x61;
  s_sun_max_011d2388[7] = DAT_011d2387 ^ 0x3d;
  s_sun_mid_011d231c[0] = DAT_011d2314 ^ 0x7a;
  s_sun_mid_011d231c[1] = DAT_011d2315 ^ 0xc3;
  s_sun_mid_011d231c[2] = DAT_011d2316 ^ 0x9a;
  s_sun_mid_011d231c[3] = DAT_011d2317 ^ 0x4c;
  s_sun_mid_011d231c[4] = DAT_011d2318 ^ 0x9f;
  s_sun_mid_011d231c[5] = DAT_011d2319 ^ 0x99;
  s_sun_mid_011d231c[6] = DAT_011d231a ^ 0x4c;
  s_sun_mid_011d231c[7] = DAT_011d231b ^ 0x7d;
  s_vol_max_011d2362[0] = DAT_011d235a ^ 0x2e;
  s_vol_max_011d2362[1] = DAT_011d235b ^ 0x4b;
  s_vol_max_011d2362[2] = DAT_011d235c ^ 0x4e;
  s_vol_max_011d2362[3] = DAT_011d235d ^ 0x2b;
  s_vol_max_011d2362[4] = DAT_011d235e ^ 0x2b;
  s_vol_max_011d2362[5] = DAT_011d235f ^ 0xc2;
  s_vol_max_011d2362[6] = DAT_011d2360 ^ 0x2a;
  s_vol_max_011d2362[7] = DAT_011d2361 ^ 0x56;
  s_vol_mid_011d22e8[0] = DAT_011d22e0 ^ 0x1a;
  s_vol_mid_011d22e8[1] = DAT_011d22e1 ^ 0xc9;
  s_vol_mid_011d22e8[2] = ~DAT_011d22e2;
  s_vol_mid_011d22e8[3] = DAT_011d22e3 ^ 0xfd;
  s_vol_mid_011d22e8[4] = DAT_011d22e4 ^ 0x81;
  s_vol_mid_011d22e8[5] = DAT_011d22e5 ^ 0x1f;
  s_vol_mid_011d22e8[6] = DAT_011d22e6 ^ 0x96;
  s_vol_mid_011d22e8[7] = DAT_011d22e7 ^ 0x68;
  DAT_0122854c = 1;
                    /* WARNING: Could not recover jumptable at 0x0023da18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar1 = (*(code *)((&PTR_LAB_011d28d8)[*(long *)(param_1 + (long)_style) < 1] +
                    (int)-(uRam00000000011d28e8 ^ 0xb515959c)))();
  return IVar1;
}



// -[PlayerToast subLabelForVal:style:], 0x23dc90
/* Decompiled from supplied 5.2.2 arm package. VA 0x23dc90. subLabelForVal:style: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x20 bytes */

ID PlayerToast::subLabelForVal_style_(ID param_1,SEL param_2,double param_3,long_long param_4)

{
  ID IVar1;
  
  if (DAT_01228550 != 0) {
    DAT_01228550 = 1;
                    /* WARNING: Could not recover jumptable at 0x0023dd48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar1 = (*(code *)((&PTR_LAB_011d2a30)[param_4 == 1] + (int)-(uRam00000000011d2a40 ^ 0xc9c6a16))
            )();
    return IVar1;
  }
  s___011d2624 = (char  [2])(_DAT_011d261c ^ 0xd129);
  s___011d2626 = (char  [2])(uRam00000000011d261e ^ 0x6920);
  uRam00000000011d2628 = uRam00000000011d2620 ^ 0xd73b;
  uRam00000000011d262a = uRam00000000011d2622 ^ 0xc34d;
  s__ld___011d2616[0] = DAT_011d2610 ^ 0x70;
  s__ld___011d2616[1] = bRam00000000011d2611 ^ 0x9b;
  s__ld___011d2616[2] = bRam00000000011d2612 ^ 0xe7;
  s__ld___011d2616[3] = bRam00000000011d2613 ^ 0x40;
  s__ld___011d2616[4] = bRam00000000011d2614 ^ 0x1c;
  s__ld___011d2616[5] = bRam00000000011d2615 ^ 0xc4;
  DAT_01228550 = 1;
                    /* WARNING: Could not recover jumptable at 0x0023de60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar1 = (*(code *)((&PTR_LAB_011d2a30)[param_4 == 1] + (int)-(uRam00000000011d2a40 ^ 0xc9c6a16)))
                    ();
  return IVar1;
}



// -[PlayerToast setupSubForStyle:], 0x23decc
/* Decompiled from supplied 5.2.2 arm package. VA 0x23decc. setupSubForStyle: */

/* Function Stack Size: 0x18 bytes */

void PlayerToast::setupSubForStyle_(ID param_1,SEL param_2,long_long param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  puVar1 = @selector(setAlpha:);
  uVar2 = 0;
  if (param_3 != 1) {
    uVar2 = 0x3ff0000000000000;
  }
  uVar3 = 0x3ff0000000000000;
  if (param_3 != 1) {
    uVar3 = 0;
  }
  _objc_msgSend(uVar2,*(undefined8 *)(param_1 + (long)_toastProgress),@selector(setAlpha:));
  _objc_msgSend(uVar3,*(undefined8 *)(param_1 + (long)_toastSubLabel),puVar1);
  CallSupervisor(0x1ad4);
  return;
}



// -[PlayerToast setValue:forEventWithStyle:], 0x23df50
/* Decompiled from supplied 5.2.2 arm package. VA 0x23df50. setValue:forEventWithStyle: */

/* Function Stack Size: 0x20 bytes */

void PlayerToast::setValue_forEventWithStyle_
               (ID param_1,SEL param_2,double param_3,long_long param_4)

{
  undefined8 uVar1;
  long lVar2;
  
  if ((long)param_4 < 2) {
    if (param_4 == 0) {
      if (param_3 <= 0.0) {
                    /* WARNING: Could not recover jumptable at 0x0023e0e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)((&PTR_LAB_011d2ac0)[bRam0000000001228500] +
                  (int)-(uRam00000000011d2ad0 ^ 0x6e068310)))();
        return;
      }
      bRam0000000001228500 = 0;
      _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,@selector(mainScreen));
      uVar1 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_3,uVar1,@selector(setBrightness:));
      _objc_release(uVar1);
    }
  }
  else if (param_4 == 2) {
    lVar2 = (long)_volumeHUD;
    _objc_msgSend(*(undefined8 *)(param_1 + lVar2),@selector(addToController));
    _objc_msgSend((float)param_3,*(undefined8 *)(param_1 + lVar2),@selector(setVolumeLevel:));
  }
  CallSupervisor(0xc13b);
  return;
}



// -[PlayerToast sourceView], 0x23e19c
/* Decompiled from supplied 5.2.2 arm package. VA 0x23e19c. sourceView */

/* Function Stack Size: 0x10 bytes */

ID PlayerToast::sourceView(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(delegate));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(window));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  _objc_release(uVar1);
  IVar4 = _objc_autoreleaseReturnValue(uVar3);
  return IVar4;
}



// -[PlayerToast isLandscape], 0x23e220
/* Decompiled from supplied 5.2.2 arm package. VA 0x23e220. isLandscape */

/* Function Stack Size: 0x10 bytes */

bool PlayerToast::isLandscape(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(connectedScenes));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(allObjects));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(firstObject));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(uVar1);
  lVar5 = _objc_msgSend(uVar4,@selector(interfaceOrientation));
  _objc_release(uVar4);
  return (bool)(lVar5 - 3U < 2);
}



// -[PlayerToast .cxx_destruct], 0x23e2e8
/* Decompiled from supplied 5.2.2 arm package. VA 0x23e2e8. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void PlayerToast::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_volumeHUD,0);
  _objc_storeStrong(param_1 + (long)_progressLayer,0);
  _objc_storeStrong(param_1 + (long)_toastProgress,0);
  _objc_storeStrong(param_1 + (long)_toastSubLabel,0);
  _objc_storeStrong(param_1 + (long)_toastLabel,0);
  _objc_storeStrong(param_1 + (long)_toastImage,0);
  _objc_storeStrong(param_1 + (long)_toastView,0);
  _objc_storeStrong(param_1 + (long)_containerView,0);
  _objc_storeStrong(param_1 + (long)_activeConstraints,0);
  CallSupervisor(0x6362);
  return;
}



// +[PlayerToast sharedToast], 0x23b468
/* Decompiled from supplied 5.2.2 arm package. VA 0x23b468. sharedToast */

/* Function Stack Size: 0x10 bytes */

ID PlayerToast::sharedToast(ID param_1,SEL param_2)

{
  ID IVar1;
  SEL extraout_x1;
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  ID local_28;
  uint local_1c;
  undefined **local_18;
  
  local_18 = &PTR_LAB_011d2808;
  local_48 = PTR___NSConcreteGlobalBlock_01060658;
  local_40 = DAT_00c4c2a8;
  local_38 = FUN_0023b51c;
  puStack_30 = &DAT_01062880;
  local_1c = (uint)(DAT_012284f8 == -1);
  local_28 = param_1;
  if (DAT_012284f8 != -1) {
    _dispatch_once((&PTR_LAB_011d2808)[local_1c] + (int)-(DAT_011d2818 ^ 0xe33e269e),&DAT_012284f8,
                   &local_48);
    param_2 = extraout_x1;
  }
  IVar1 = (*(code *)PTR__objc_retainAutoreleaseReturnValue_01061040)(DAT_012284f0,param_2);
  return IVar1;
}


