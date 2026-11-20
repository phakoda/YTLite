// Decompiled implementation evidence for YTPSpeedPopupController. Not compilable source.

// -[YTPSpeedPopupController presentFromViewController:], 0x235bc4
/* Decompiled from supplied 5.2.2 arm package. VA 0x235bc4. presentFromViewController: */

/* Function Stack Size: 0x18 bytes */

void YTPSpeedPopupController::presentFromViewController_(ID param_1,SEL param_2,ID param_3)

{
  _objc_msgSend(param_3,@selector(presentViewController:animated:completion:),param_1,0,0);
  CallSupervisor(0x5b42);
  return;
}



// -[YTPSpeedPopupController viewDidAppear:], 0x235c0c
/* Decompiled from supplied 5.2.2 arm package. VA 0x235c0c. viewDidAppear: */

/* Function Stack Size: 0x14 bytes */

void YTPSpeedPopupController::viewDidAppear_(ID param_1,SEL param_2,bool param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined *local_68;
  undefined8 local_60;
  code *local_58;
  undefined *puStack_50;
  ID local_48;
  ID local_40;
  undefined *puStack_38;
  
  puStack_38 = PTR_YTPSpeedPopupController_0114f158;
  local_40 = param_1;
  _objc_msgSendSuper2(&local_40,@selector(viewDidAppear:),param_3);
  uVar2 = _objc_msgSend(param_1,@selector(bottomConstant));
  _objc_msgSend(param_1,@selector(bottomConstraint));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,uVar1,@selector(setConstant:));
  _objc_release(uVar1);
  local_68 = PTR___NSConcreteStackBlock_01060660;
  local_60 = DAT_00c4c228;
  local_58 = FUN_00235d04;
  puStack_50 = &DAT_01061420;
  local_48 = param_1;
  _objc_msgSend(DAT_00c4c300,0,DAT_00c4c250,0x3fe0000000000000,PTR__OBJC_CLASS___UIView_0114ec30,
                @selector(animateWithDuration:delay:usingSpringWithDamping:initialSpringVelocity:options:animations:completion:),0x20000,&local_68,0);
  return;
}



// -[YTPSpeedPopupController viewDidLoad], 0x235d64
/* Decompiled from supplied 5.2.2 arm package. VA 0x235d64. viewDidLoad */

/* Function Stack Size: 0x10 bytes */

void YTPSpeedPopupController::viewDidLoad(ID param_1,SEL param_2)

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
  double in_d3;
  ID local_b8;
  undefined *puStack_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  puStack_b0 = PTR_YTPSpeedPopupController_0114f158;
  local_b8 = param_1;
  _objc_msgSendSuper2(&local_b8,@selector(viewDidLoad));
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(blackColor));
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(colorWithAlphaComponent:);
  _objc_msgSend(DAT_00c4c2f0,uVar10,@selector(colorWithAlphaComponent:));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(view);
  _objc_msgSend(param_1,@selector(view));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar4 = @selector(setBackgroundColor:);
  _objc_msgSend(uVar12,@selector(setBackgroundColor:),uVar11);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  uVar10 = _objc_alloc(PTR__OBJC_CLASS___UITapGestureRecognizer_0114ed98);
  puVar6 = @selector(initWithTarget:action:);
  uVar10 = _objc_msgSend(uVar10,@selector(initWithTarget:action:),param_1,@selector(dismiss)
                        );
  _objc_msgSend(uVar10,@selector(setDelegate:),param_1);
  _objc_msgSend(param_1,puVar1);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar7 = @selector(addGestureRecognizer:);
  _objc_msgSend(uVar11,@selector(addGestureRecognizer:),uVar10);
  _objc_release(uVar11);
  _objc_msgSend(PTR_YTPSpeedControlView_0114f030,@selector(speedControls));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(setSpeedView:),uVar11);
  _objc_release(uVar11);
  _objc_msgSend(param_1,puVar1);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar8 = @selector(speedView);
  _objc_msgSend(param_1,@selector(speedView));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(addSubview:);
  _objc_msgSend(uVar11,@selector(addSubview:),uVar12);
  _objc_release(uVar12);
  _objc_release(uVar11);
  uVar11 = _objc_alloc_init(PTR__OBJC_CLASS___UIView_0114ec30);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(labelColor));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(DAT_00c4c2e0,uVar12,puVar3);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar4,uVar13);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_msgSend(uVar11,@selector(layer));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4004000000000000,uVar12,@selector(setCornerRadius:));
  _objc_release(uVar12);
  _objc_msgSend(uVar11,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
  _objc_msgSend(param_1,puVar8);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,puVar2,uVar11);
  _objc_release(uVar12);
  _objc_msgSend(param_1,puVar8);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(bottomAnchor);
  _objc_msgSend(uVar12,@selector(bottomAnchor));
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar14,@selector(safeAreaLayoutGuide));
  uVar15 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar15,puVar2);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar8);
  uVar17 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar17,@selector(bounds));
  puVar3 = @selector(constraintEqualToAnchor:constant:);
  _objc_msgSend(in_d3 + 20.0,uVar13,@selector(constraintEqualToAnchor:constant:),uVar16);
  uVar18 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(setBottomConstraint:),uVar18);
  _objc_release(uVar18);
  _objc_release(uVar17);
  _objc_release(uVar16);
  _objc_release(uVar15);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  puVar9 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  puVar2 = @selector(topAnchor);
  _objc_msgSend(uVar11,@selector(topAnchor));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar8);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,puVar2);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4020000000000000,uVar12,puVar3,uVar14);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(centerXAnchor);
  local_a8 = uVar15;
  _objc_msgSend(uVar11,@selector(centerXAnchor));
  uVar16 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar8);
  uVar17 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar17,puVar3);
  uVar18 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(constraintEqualToAnchor:);
  _objc_msgSend(uVar16,@selector(constraintEqualToAnchor:),uVar18);
  uVar19 = _objc_retainAutoreleasedReturnValue();
  puVar5 = @selector(widthAnchor);
  local_a0 = uVar19;
  _objc_msgSend(uVar11,@selector(widthAnchor));
  uVar20 = _objc_retainAutoreleasedReturnValue();
  puVar4 = @selector(constraintEqualToConstant:);
  _objc_msgSend(0x4042000000000000,uVar20,@selector(constraintEqualToConstant:));
  uVar21 = _objc_retainAutoreleasedReturnValue();
  local_98 = uVar21;
  _objc_msgSend(uVar11,@selector(heightAnchor));
  uVar22 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4014000000000000,uVar22,puVar4);
  uVar23 = _objc_retainAutoreleasedReturnValue();
  local_90 = uVar23;
  _objc_msgSend(param_1,puVar8);
  uVar24 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar24,puVar3);
  uVar25 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar26 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar26,puVar3);
  uVar27 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar25,puVar2,uVar27);
  uVar28 = _objc_retainAutoreleasedReturnValue();
  local_88 = uVar28;
  _objc_msgSend(param_1,puVar8);
  uVar29 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar29,puVar5);
  uVar30 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(calculateWidth));
  _objc_msgSend(uVar30,puVar4);
  uVar31 = _objc_retainAutoreleasedReturnValue();
  local_80 = uVar31;
  _objc_msgSend(param_1,@selector(bottomConstraint));
  uVar32 = _objc_retainAutoreleasedReturnValue();
  local_78 = uVar32;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),&local_a8,
                7);
  uVar33 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar9,@selector(activateConstraints:),uVar33);
  _objc_release(uVar33);
  _objc_release(uVar32);
  _objc_release(uVar31);
  _objc_release(uVar30);
  _objc_release(uVar29);
  _objc_release(uVar28);
  _objc_release(uVar27);
  _objc_release(uVar26);
  _objc_release(uVar25);
  _objc_release(uVar24);
  _objc_release(uVar23);
  _objc_release(uVar22);
  _objc_release(uVar21);
  _objc_release(uVar20);
  _objc_release(uVar19);
  _objc_release(uVar18);
  _objc_release(uVar17);
  _objc_release(uVar16);
  _objc_release(uVar15);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  uVar12 = _objc_alloc(PTR__OBJC_CLASS___UIPanGestureRecognizer_0114ed90);
  uVar12 = _objc_msgSend(uVar12,puVar6,param_1,@selector(handlePan:));
  _objc_msgSend(param_1,puVar8);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,puVar7,uVar12);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  CallSupervisor(0x75a);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_70) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}



// -[YTPSpeedPopupController calculateWidth], 0x236564
/* Decompiled from supplied 5.2.2 arm package. VA 0x236564. calculateWidth */

/* Function Stack Size: 0x10 bytes */

double YTPSpeedPopupController::calculateWidth(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  double dVar5;
  double in_d2;
  double in_d3;
  
  puVar2 = @selector(mainScreen);
  _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,@selector(mainScreen));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(bounds);
  _objc_msgSend(uVar4,@selector(bounds));
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar1);
  _objc_release(uVar4);
  if (in_d3 <= in_d2) {
    in_d2 = in_d3;
  }
  iVar3 = FUN_00237c94(param_1,@selector(isiPad));
  dVar5 = 0.5;
  if (iVar3 == 0) {
    dVar5 = DAT_00c4c3b8;
  }
  return in_d2 * dVar5;
}



// -[YTPSpeedPopupController bottomConstant], 0x236634
/* Decompiled from supplied 5.2.2 arm package. VA 0x236634. bottomConstant */

/* Function Stack Size: 0x10 bytes */

double YTPSpeedPopupController::bottomConstant(ID param_1,SEL param_2)

{
  int iVar1;
  double dVar2;
  
  iVar1 = FUN_00237cbc((int)param_1,@selector(hasNotch));
  dVar2 = 0.0;
  if (iVar1 == 0) {
    dVar2 = -10.0;
  }
  return dVar2;
}



// -[YTPSpeedPopupController isiPad], 0x236660
/* Decompiled from supplied 5.2.2 arm package. VA 0x236660. isiPad */

/* Function Stack Size: 0x10 bytes */

bool YTPSpeedPopupController::isiPad(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  bool bVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  protocol_list_t_1_ *ppVar8;
  undefined *puVar9;
  undefined *puVar10;
  
  puVar1 = @selector(currentDevice);
  DAT_01228488 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIDevice_0114eb58,@selector(currentDevice));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  lVar5 = _objc_msgSend(uVar4,@selector(userInterfaceIdiom));
  if (lVar5 == 1) {
    ppVar8 = &objc::protocol_list_t::CustomHUD;
    puVar9 = @selector(model);
    puVar10 = @selector(containsString:);
  }
  else {
    _objc_msgSend((&PTR_LAB_011d1f10)[lVar5 == 1] + (int)-(DAT_011d1f20 ^ 0x66d9b11d),
                  PTR__OBJC_CLASS___UIDevice_0114eb58,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar9 = @selector(model);
    _objc_msgSend(uVar6,@selector(model));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar10 = @selector(containsString:);
    uVar2 = FUN_00237d24(uVar7,@selector(containsString:),
                         @"iPad");
    ppVar8 = (protocol_list_t_1_ *)
             ((&PTR_LAB_011d1f30)[uVar2] + (int)-(uRam00000000011d1f40 ^ 0x56402869));
    if (uVar2 == 0) {
      _objc_release(uVar7);
      _objc_release(uVar6);
      _objc_release(uVar4);
      return 0;
    }
  }
  _objc_msgSend(ppVar8,PTR__OBJC_CLASS___UIDevice_0114eb58,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar9);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  FUN_00237dcc(uVar6,puVar10,@"iPhone");
  _objc_release(uVar6);
  _objc_release(uVar4);
                    /* WARNING: Could not recover jumptable at 0x00236950. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  bVar3 = (*(code *)((&PTR_LAB_011d1f48)[lVar5 == 1] + (int)-(DAT_011d1f58 ^ 0xce0586f8)))();
  return bVar3;
}



// -[YTPSpeedPopupController hasNotch], 0x236994
/* Decompiled from supplied 5.2.2 arm package. VA 0x236994. hasNotch */

/* Function Stack Size: 0x10 bytes */

bool YTPSpeedPopupController::hasNotch(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  double dVar4;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(delegate));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(window));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  dVar4 = (double)_objc_msgSend(uVar3,@selector(safeAreaInsets));
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(uVar1);
  return (bool)(20.0 < dVar4);
}



// -[YTPSpeedPopupController dismiss], 0x236a38
/* Decompiled from supplied 5.2.2 arm package. VA 0x236a38. dismiss */

/* Function Stack Size: 0x10 bytes */

void YTPSpeedPopupController::dismiss(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  double in_d3;
  undefined *local_90;
  undefined8 local_88;
  code *local_80;
  undefined *puStack_78;
  ID local_70;
  undefined *puStack_68;
  undefined8 local_60;
  code *local_58;
  undefined *puStack_50;
  ID local_48;
  
  _objc_msgSend(param_1,@selector(speedView));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(bounds));
  _objc_msgSend(param_1,@selector(bottomConstraint));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(in_d3 + 50.0,uVar2,@selector(setConstant:));
  _objc_release(uVar2);
  _objc_release(uVar1);
  puStack_68 = PTR___NSConcreteStackBlock_01060660;
  local_60 = DAT_00c4c228;
  local_58 = FUN_00236b84;
  puStack_50 = &DAT_01061420;
  local_90 = PTR___NSConcreteStackBlock_01060660;
  local_88 = DAT_00c4c228;
  local_80 = FUN_00236c30;
  puStack_78 = &DAT_01061940;
  local_70 = param_1;
  local_48 = param_1;
  _objc_msgSend(DAT_00c4c2e0,0,0x3ff0000000000000,
                *(double *)(param_1 + (long)_dismissVelocity) / DAT_00c4c4a0,
                PTR__OBJC_CLASS___UIView_0114ec30,@selector(animateWithDuration:delay:usingSpringWithDamping:initialSpringVelocity:options:animations:completion:),
                0x10000,&puStack_68,&local_90);
  CallSupervisor(0x2f6a);
  return;
}



// -[YTPSpeedPopupController handlePan:], 0x236c70
/* Decompiled from supplied 5.2.2 arm package. VA 0x236c70. handlePan: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x18 bytes */

void YTPSpeedPopupController::handlePan_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined *puVar8;
  double dVar9;
  double in_d1;
  double dVar10;
  
  _objc_retain(param_3);
  puVar1 = @selector(view);
  _objc_msgSend(param_1,@selector(view));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,@selector(translationInView:),uVar3);
  dVar10 = in_d1;
  _objc_release(uVar3);
  puVar2 = @selector(state);
  lVar4 = _objc_msgSend(param_3,@selector(state));
  if (lVar4 == 2) {
    dVar9 = (double)_objc_msgSend(param_1,@selector(bottomConstant));
    dVar10 = in_d1;
    if (in_d1 <= 0.0) {
      dVar10 = DAT_00c4c258 * in_d1;
    }
    _objc_msgSend(param_1,@selector(bottomConstraint));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(dVar10 + dVar9,uVar3,@selector(setConstant:));
    _objc_release(uVar3);
    dVar10 = 1.0;
    if (in_d1 / 200.0 <= 1.0) {
      dVar10 = in_d1 / 200.0;
    }
    if (dVar10 <= 0.0) {
      dVar10 = 0.0;
    }
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(blackColor));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend((1.0 - dVar10) * DAT_00c4c2f0,uVar3,@selector(colorWithAlphaComponent:));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(setBackgroundColor:),uVar5);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar3);
    _objc_msgSend(param_1,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(layoutIfNeeded));
    _objc_release(uVar3);
LAB_00237068:
    _objc_release(param_3);
    CallSupervisor(0x144e);
    return;
  }
  lVar4 = _objc_msgSend((&PTR_LAB_011d1f68)[lVar4 == 2] + (int)-(DAT_011d1f78 ^ 0xbee489fe),param_3,
                        puVar2);
  puVar8 = (&PTR_LAB_011d1f88)[lVar4 == 3] + (int)-(uRam00000000011d1f98 ^ 0xcc428557);
  if (lVar4 != 3) {
    lVar4 = _objc_msgSend(puVar8,param_3,puVar2);
    puVar8 = (&PTR_LAB_011d1fa0)[lVar4 == 4] + (int)-(uRam00000000011d1fb0 ^ 0x6189ebe7);
    if (lVar4 != 4) goto LAB_00237068;
  }
  _objc_msgSend(puVar8,param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,@selector(velocityInView:),uVar3);
  _objc_release(uVar3);
  uVar7 = (uint)(120.0 < in_d1);
  if (_UNK_00c4c518 < dVar10) {
    uVar7 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00236e60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011d1fb8)[uVar7] + (int)-(uRam00000000011d1fc8 ^ 0x4303fdff)))();
  return;
}



// -[YTPSpeedPopupController gestureRecognizer:shouldReceiveTouch:], 0x23719c
/* Decompiled from supplied 5.2.2 arm package. VA 0x23719c. gestureRecognizer:shouldReceiveTouch: */

/* Function Stack Size: 0x20 bytes */

bool YTPSpeedPopupController::gestureRecognizer_shouldReceiveTouch_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  long lVar2;
  long lVar3;
  
  puVar1 = @selector(view);
  _objc_msgSend(param_4,@selector(view));
  lVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  _objc_release(lVar2);
  return (bool)(lVar2 == lVar3);
}



// -[YTPSpeedPopupController speedView], 0x23720c
/* Decompiled from supplied 5.2.2 arm package. VA 0x23720c. speedView */

/* Function Stack Size: 0x10 bytes */

ID YTPSpeedPopupController::speedView(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + (long)_speedView);
}



// -[YTPSpeedPopupController setSpeedView:], 0x23721c
/* Decompiled from supplied 5.2.2 arm package. VA 0x23721c. setSpeedView: */

/* Function Stack Size: 0x18 bytes */

void YTPSpeedPopupController::setSpeedView_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + (long)_speedView,param_3);
  CallSupervisor(0xe4a5);
  return;
}



// -[YTPSpeedPopupController bottomConstraint], 0x237258
/* Decompiled from supplied 5.2.2 arm package. VA 0x237258. bottomConstraint */

/* Function Stack Size: 0x10 bytes */

ID YTPSpeedPopupController::bottomConstraint(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + (long)_bottomConstraint);
}



// -[YTPSpeedPopupController setBottomConstraint:], 0x237268
/* Decompiled from supplied 5.2.2 arm package. VA 0x237268. setBottomConstraint: */

/* Function Stack Size: 0x18 bytes */

void YTPSpeedPopupController::setBottomConstraint_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + (long)_bottomConstraint,param_3);
  CallSupervisor(0x5996);
  return;
}



// -[YTPSpeedPopupController .cxx_destruct], 0x2372a4
/* Decompiled from supplied 5.2.2 arm package. VA 0x2372a4. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void YTPSpeedPopupController::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_bottomConstraint,0);
  _objc_storeStrong(param_1 + (long)_speedView,0);
  CallSupervisor(0xc722);
  return;
}



// +[YTPSpeedPopupController speedController], 0x235b74
/* Decompiled from supplied 5.2.2 arm package. VA 0x235b74. speedController */

/* Function Stack Size: 0x10 bytes */

ID YTPSpeedPopupController::speedController(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  ID IVar2;
  
  uVar1 = _objc_alloc_init(PTR_YTPSpeedPopupController_0114ed70);
  _objc_msgSend(uVar1,@selector(setModalPresentationStyle:),6);
  _objc_msgSend(uVar1,@selector(setModalTransitionStyle:),2);
  IVar2 = _objc_autoreleaseReturnValue(uVar1);
  return IVar2;
}


