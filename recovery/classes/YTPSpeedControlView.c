// Decompiled implementation evidence for YTPSpeedControlView. Not compilable source.

// -[YTPSpeedControlView initWithFrame:], 0x238398
/* Decompiled from supplied 5.2.2 arm package. VA 0x238398. initWithFrame: */

/* Function Stack Size: 0x30 bytes */

ID YTPSpeedControlView::initWithFrame_(ID param_1,SEL param_2,CGRect param_3)

{
  undefined *puVar1;
  ID IVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ID local_a0;
  undefined *puStack_98;
  uint local_8c;
  undefined **local_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  long local_58;
  
  local_58 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_011d21e8;
  puStack_98 = PTR_YTPSpeedControlView_0114f160;
  local_a0 = param_1;
  IVar2 = _objc_msgSendSuper2(param_3.field0_0x0.field0_0x0,param_3.field0_0x0.field1_0x8,
                              param_3.field1_0x10.field0_0x0,param_3.field1_0x10.field1_0x8,
                              &local_a0,@selector(initWithFrame:));
  local_8c = (uint)(IVar2 == 0);
  if (IVar2 != 0) {
    *(undefined4 *)(IVar2 + (long)_step) = 0x3d4ccccd;
    puVar1 = @selector(numberWithDouble:);
    _objc_msgSend(0x3ff0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,
                  @selector(numberWithDouble:));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uStack_80 = uVar3;
    _objc_msgSend(0x4000000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_78 = uVar4;
    _objc_msgSend(0x4008000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uStack_70 = uVar5;
    _objc_msgSend(0x4014000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uStack_68 = uVar6;
    _objc_msgSend(0x4024000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uStack_60 = uVar7;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  &uStack_80,5);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    uVar9 = *(undefined8 *)(IVar2 + (long)_presets);
    *(undefined8 *)(IVar2 + (long)_presets) = uVar8;
    _objc_release(uVar9);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_release(uVar3);
    _objc_msgSend(IVar2,@selector(setupUI));
  }
  if (*(long *)PTR____stack_chk_guard_01060708 != local_58) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return IVar2;
}



// -[YTPSpeedControlView setupUI], 0x2385a0
/* Decompiled from supplied 5.2.2 arm package. VA 0x2385a0. setupUI */

/* Function Stack Size: 0x10 bytes */

void YTPSpeedControlView::setupUI(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  ID IVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  long lVar17;
  double dVar18;
  undefined8 auStack_2c0 [6];
  undefined8 auStack_290 [4];
  undefined1 auStack_270 [128];
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined *puStack_188;
  undefined *puStack_180;
  undefined *puStack_178;
  undefined *puStack_170;
  undefined8 uStack_168;
  undefined8 *puStack_160;
  undefined8 uStack_158;
  long lStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 *puStack_138;
  undefined *puStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 *puStack_118;
  undefined *puStack_110;
  undefined8 uStack_108;
  undefined *puStack_100;
  undefined1 *puStack_f8;
  undefined8 *puStack_f0;
  ID local_e8;
  undefined **local_d8;
  uint uStack_cc;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_011d2208;
  local_7c = (uint)(DAT_012284c4 == 0);
  local_90 = &PTR_LAB_011d2228;
  local_88 = &PTR_LAB_011d2170;
  local_a8 = &PTR_LAB_011d2170;
  ppuStack_a0 = &PTR_LAB_011d2170;
  local_b0 = &PTR_LAB_011d2250;
  local_c8 = &PTR_LAB_011d2270;
  ppuStack_c0 = &PTR_LAB_011d2170;
  local_d8 = &PTR_LAB_011d2288;
  DAT_012284c4 = 1;
  puStack_f0 = &uStack_1b0;
  puStack_160 = &uStack_1f0;
  puStack_f8 = auStack_270;
  puStack_138 = auStack_290;
  puStack_118 = auStack_2c0;
  puStack_130 = @selector(setTranslatesAutoresizingMaskIntoConstraints:);
  local_e8 = param_1;
  _objc_msgSend(param_1,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
  _objc_msgSend(param_1,@selector(layer));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4030000000000000,uVar7,@selector(setCornerRadius:));
  _objc_release(uVar7);
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(adaptiveBackgroundColor));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(setBackgroundColor:),uVar7);
  _objc_release(uVar7);
  uVar7 = _objc_alloc_init(PTR__OBJC_CLASS___UILabel_0114ec00);
  lVar17 = (long)_valueLabel;
  uVar15 = *(undefined8 *)(param_1 + lVar17);
  *(undefined8 *)(param_1 + lVar17) = uVar7;
  _objc_release(uVar15);
  puVar1 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar3 = @selector(currentPlaybackRate);
  _objc_msgSend(PTR_YTPSpeedMaster_0114eca0,@selector(currentPlaybackRate));
  thunk_FUN_0023a284(puVar1,@selector(stringWithFormat:),
                     @"%.2fx");
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar17),@selector(setText:),uVar7);
  _objc_release(uVar7);
  puVar1 = @selector(labelColor);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(labelColor));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar17),@selector(setTextColor:),uVar7);
  _objc_release(uVar7);
  _objc_msgSend(0x4032000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,
                @selector(boldSystemFontOfSize:));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar17),@selector(setFont:),uVar7);
  _objc_release(uVar7);
  lStack_150 = lVar17;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar17),@selector(setTextAlignment:),1);
  puVar4 = @selector(makeStepButton:);
  _objc_msgSend(param_1,@selector(makeStepButton:),
                @"minus");
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(addTarget:action:forControlEvents:);
  _objc_msgSend(uVar7,@selector(addTarget:action:forControlEvents:),param_1,
                @selector(minusTapped),0x40);
  _objc_msgSend(param_1,puVar4,@"plus");
  uVar15 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar15,puVar2,param_1,@selector(plusTapped),0x40);
  uVar8 = _objc_alloc_init(PTR__OBJC_CLASS___UISlider_0114ee50);
  lVar17 = (long)_slider;
  uVar16 = *(undefined8 *)(param_1 + lVar17);
  *(undefined8 *)(param_1 + lVar17) = uVar8;
  _objc_release(uVar16);
  _objc_msgSend(0x3e800000,*(undefined8 *)(param_1 + lVar17),@selector(setMinimumValue:));
  _objc_msgSend(0x41200000,*(undefined8 *)(param_1 + lVar17),@selector(setMaximumValue:));
  dVar18 = (double)_objc_msgSend(PTR_YTPSpeedMaster_0114eca0,puVar3);
  _objc_msgSend((float)dVar18,*(undefined8 *)(param_1 + lVar17),@selector(setValue:));
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar17),@selector(setMinimumTrackTintColor:),uVar8);
  _objc_release(uVar8);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(DAT_00c4c258,uVar8,@selector(colorWithAlphaComponent:));
  uVar16 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar17),@selector(setMaximumTrackTintColor:),uVar16);
  _objc_release(uVar16);
  _objc_release(uVar8);
  uVar8 = _objc_alloc(PTR__OBJC_CLASS___UIGraphicsImageRenderer_0114ec88);
  uStack_140 = _objc_msgSend(0x4028000000000000,0x402e000000000000,uVar8,
                             @selector(initWithSize:));
  _objc_msgSend(uStack_140,@selector(imageWithActions:),&PTR___NSConcreteGlobalBlock_01063290);
  uStack_148 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar17),@selector(setThumbImage:forState:),uStack_148,
                0);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar17),puVar2,param_1,@selector(sliderChanged:),
                0x1000);
  uVar8 = _objc_alloc(PTR__OBJC_CLASS___UITapGestureRecognizer_0114ed98);
  uStack_158 = _objc_msgSend(uVar8,@selector(initWithTarget:action:),param_1,
                             @selector(sliderTapped:));
  _objc_msgSend(*(undefined8 *)(param_1 + lVar17),@selector(addGestureRecognizer:));
  uVar8 = _objc_alloc(PTR__OBJC_CLASS___UIStackView_0114ec10);
  uStack_1a8 = *(undefined8 *)(param_1 + lVar17);
  puStack_110 = @selector(arrayWithObjects:count:);
  uStack_1b0 = uVar7;
  uStack_1a0 = uVar15;
  uStack_128 = uVar15;
  uStack_120 = uVar7;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),puStack_f0
                ,3);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puStack_170 = @selector(initWithArrangedSubviews:);
  uVar15 = _objc_msgSend(uVar8,@selector(initWithArrangedSubviews:),uVar7);
  puVar5 = puStack_160;
  _objc_release(uVar7);
  puStack_178 = @selector(setAxis:);
  _objc_msgSend(uVar15,@selector(setAxis:),0);
  puStack_180 = @selector(setSpacing:);
  _objc_msgSend(0x4028000000000000,uVar15);
  puStack_188 = @selector(setAlignment:);
  uStack_108 = uVar15;
  _objc_msgSend(uVar15,@selector(setAlignment:),3);
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  uStack_1e8 = 0;
  uStack_1f0 = 0;
  uStack_1d8 = 0;
  uStack_1e0 = 0;
  uStack_1c8 = 0;
  uStack_1d0 = 0;
  uStack_1b8 = 0;
  uStack_1c0 = 0;
  puStack_f0 = (undefined8 *)_objc_retain(*(undefined8 *)(param_1 + (long)_presets));
  puStack_100 = @selector(countByEnumeratingWithState:objects:count:);
  lVar17 = _objc_msgSend(puStack_f0,@selector(countByEnumeratingWithState:objects:count:),puVar5,
                         puStack_f8,0x10);
  puVar2 = @selector(makePresetButton:);
  puVar1 = @selector(addObject:);
  uStack_94 = (uint)(lVar17 == 0);
  if (lVar17 != 0) {
    uStack_b4 = (uint)(*(long *)puVar5[2] == *(long *)puVar5[2]);
    if (*(long *)puVar5[2] != *(long *)puVar5[2]) {
      _objc_enumerationMutation
                (local_b0[uStack_b4] + (int)-(uRam00000000011d2260 ^ 0xda75b85d),puStack_f0);
    }
    _objc_msgSend(local_e8,puVar2,*(undefined8 *)puVar5[1]);
    uVar15 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puVar1,uVar15);
    _objc_release(uVar15);
    uStack_cc = (uint)(lVar17 == 1);
                    /* WARNING: Could not recover jumptable at 0x00238e64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_c8[uStack_cc] + (int)-(uRam00000000011d2280 ^ 0x9cf0aba8)))();
    return;
  }
  _objc_release(local_90[uStack_94] + (int)-(DAT_011d2238 ^ 0x7a5e0c1b),puStack_f0);
  uVar15 = _objc_alloc(PTR__OBJC_CLASS___UIStackView_0114ec10);
  puVar3 = puStack_170;
  uStack_168 = uVar7;
  uVar15 = _objc_msgSend(uVar15,puStack_170,uVar7);
  puVar2 = puStack_178;
  _objc_msgSend(uVar15,puStack_178,0);
  puVar1 = puStack_180;
  _objc_msgSend(0x4020000000000000,uVar15,puStack_180);
  _objc_msgSend(uVar15,@selector(setDistribution:),1);
  uVar8 = _objc_alloc(PTR__OBJC_CLASS___UIStackView_0114ec10);
  IVar6 = local_e8;
  uVar7 = uStack_108;
  puVar4 = puStack_110;
  puVar5 = puStack_138;
  *puStack_138 = *(undefined8 *)(local_e8 + lStack_150);
  puVar5[1] = uVar7;
  puVar5[2] = uVar15;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar4,puVar5,3);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  uVar8 = _objc_msgSend(uVar8,puVar3,uVar7);
  _objc_release(uVar7);
  _objc_msgSend(uVar8,puVar2,1);
  _objc_msgSend(0x4028000000000000,uVar8,puVar1);
  _objc_msgSend(uVar8,puStack_188,0);
  _objc_msgSend(uVar8,puStack_130,0);
  _objc_msgSend(IVar6,@selector(addSubview:),uVar8);
  puVar1 = @selector(topAnchor);
  puStack_138 = (undefined8 *)PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  _objc_msgSend(uVar8,@selector(topAnchor));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puStack_f0 = (undefined8 *)uVar7;
  _objc_msgSend(IVar6,puVar1);
  puStack_f8 = (undefined1 *)_objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(constraintEqualToAnchor:constant:);
  _objc_msgSend(0x4038000000000000,uVar7,@selector(constraintEqualToAnchor:constant:),puStack_f8)
  ;
  puStack_100 = (undefined *)_objc_retainAutoreleasedReturnValue();
  puVar5 = puStack_118;
  *puStack_118 = puStack_100;
  puVar1 = @selector(leadingAnchor);
  _objc_msgSend(uVar8,@selector(leadingAnchor));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puStack_130 = (undefined *)uVar7;
  _objc_msgSend(IVar6,puVar1);
  lStack_150 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4030000000000000,uVar7,puVar2,lStack_150);
  puStack_160 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
  puVar5[1] = puStack_160;
  puVar1 = @selector(trailingAnchor);
  _objc_msgSend(uVar8,@selector(trailingAnchor));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puStack_170 = (undefined *)uVar7;
  _objc_msgSend(IVar6,puVar1);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0xc030000000000000,uVar7,puVar2,uVar16);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar5[2] = uVar7;
  puVar1 = @selector(bottomAnchor);
  _objc_msgSend(uVar8,@selector(bottomAnchor));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(IVar6,puVar1);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0xc030000000000000,uVar9,puVar2,uVar10);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar5[3] = uVar11;
  _objc_msgSend(uVar15,@selector(heightAnchor));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4040000000000000,uVar12,@selector(constraintEqualToConstant:));
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puVar5[4] = uVar13;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puStack_110,puVar5,5);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_138,@selector(activateConstraints:),uVar14);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar7);
  _objc_release(uVar16);
  _objc_release(puStack_170);
  _objc_release(puStack_160);
  _objc_release(lStack_150);
  _objc_release(puStack_130);
  _objc_release(puStack_100);
  _objc_release(puStack_f8);
  _objc_release(puStack_f0);
  _objc_release(uVar8);
  _objc_release(uVar15);
  _objc_release(uStack_168);
  _objc_release(uStack_108);
  _objc_release(uStack_158);
  _objc_release(uStack_148);
  _objc_release(uStack_140);
  _objc_release(uStack_128);
  _objc_release(uStack_120);
  CallSupervisor(0x32f2);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}



// -[YTPSpeedControlView makeStepButton:], 0x239460
/* Decompiled from supplied 5.2.2 arm package. VA 0x239460. makeStepButton: */

/* Function Stack Size: 0x18 bytes */

ID YTPSpeedControlView::makeStepButton_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ID IVar9;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  puVar2 = PTR__OBJC_CLASS___UIButton_0114ec38;
  puVar1 = @selector(buttonWithType:);
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1,0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,@selector(systemImageNamed:),param_3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(uVar3,@selector(setImage:forState:),uVar4,0);
  _objc_release(uVar4);
  puVar1 = @selector(labelColor);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(labelColor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setTintColor:),uVar4);
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(DAT_00c4c258,uVar4,@selector(colorWithAlphaComponent:));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setBackgroundColor:),uVar5);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,@selector(layer));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4034000000000000,uVar4,@selector(setCornerRadius:));
  _objc_release(uVar4);
  _objc_msgSend(uVar3,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
  puVar2 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  _objc_msgSend(uVar3,@selector(widthAnchor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(constraintEqualToConstant:);
  _objc_msgSend(0x4044000000000000,uVar4,@selector(constraintEqualToConstant:));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  local_78 = uVar5;
  _objc_msgSend(uVar3,@selector(heightAnchor));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4044000000000000,uVar6,puVar1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  local_70 = uVar7;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),&local_78,
                2);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,@selector(activateConstraints:),uVar8);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(param_1,@selector(addSubview:),uVar3);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    IVar9 = _objc_autoreleaseReturnValue(uVar3);
    return IVar9;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}



// -[YTPSpeedControlView makePresetButton:], 0x23973c
/* Decompiled from supplied 5.2.2 arm package. VA 0x23973c. makePresetButton: */

/* Function Stack Size: 0x18 bytes */

ID YTPSpeedControlView::makePresetButton_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  float fVar7;
  
  puVar2 = PTR__OBJC_CLASS___UIButton_0114ec38;
  puVar1 = @selector(buttonWithType:);
  DAT_012284d0 = 1;
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1,0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar2 = @selector(floatValue);
  fVar7 = (float)_objc_msgSend(param_3,@selector(floatValue));
  thunk_FUN_0023aef0((double)fVar7,puVar1,@selector(stringWithFormat:),
                     @"%.1f");
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setTitle:forState:),uVar4,0);
  _objc_release(uVar4);
  puVar1 = @selector(labelColor);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(labelColor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setTitleColor:forState:),uVar4,0);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,@selector(addTarget:action:forControlEvents:),param_1,
                @selector(presetTapped:),0x40);
  _objc_msgSend(0x4028000000000000,*(undefined8 *)PTR__UIFontWeightMedium_01060570,
                PTR__OBJC_CLASS___UIFont_0114ec08,@selector(systemFontOfSize:weight:));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(titleLabel));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setFont:),uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(DAT_00c4c258,uVar4,@selector(colorWithAlphaComponent:));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setBackgroundColor:),uVar5);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,@selector(layer));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4030000000000000,uVar4,@selector(setCornerRadius:));
  _objc_release(uVar4);
  fVar7 = (float)_objc_msgSend(param_3,puVar2);
  _objc_release(param_3);
  _objc_msgSend(uVar3,@selector(setTag:),(long)(fVar7 * 100.0));
  _objc_msgSend(uVar3,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
  _objc_msgSend(uVar3,@selector(heightAnchor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4040000000000000,uVar4,@selector(constraintEqualToConstant:));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setActive:),1);
  _objc_release(uVar5);
  _objc_release(uVar4);
  IVar6 = _objc_autoreleaseReturnValue(uVar3);
  return IVar6;
}



// -[YTPSpeedControlView sliderChanged:], 0x239ae0
/* Decompiled from supplied 5.2.2 arm package. VA 0x239ae0. sliderChanged: */

/* Function Stack Size: 0x18 bytes */

void YTPSpeedControlView::sliderChanged_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  float fVar2;
  
  puVar1 = @selector(value);
  _objc_retain(param_3);
  fVar2 = (float)_objc_msgSend(param_3,puVar1);
  fVar2 = *(float *)(param_1 + (long)_step) *
          (float)(int)(fVar2 / *(float *)(param_1 + (long)_step));
  _objc_msgSend(fVar2,param_3,@selector(setValue:));
  _objc_release(param_3);
  _objc_msgSend(fVar2,param_1,@selector(updateLabel:));
  CallSupervisor(0x4818);
  return;
}



// -[YTPSpeedControlView sliderTapped:], 0x239b8c
/* Decompiled from supplied 5.2.2 arm package. VA 0x239b8c. sliderTapped: */

/* Function Stack Size: 0x18 bytes */

void YTPSpeedControlView::sliderTapped_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  long lVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  double in_d2;
  
  lVar2 = (long)_slider;
  dVar6 = (double)_objc_msgSend(param_3,@selector(locationInView:),
                                *(undefined8 *)(param_1 + lVar2));
  _objc_msgSend(*(undefined8 *)(param_1 + lVar2),@selector(bounds));
  puVar1 = @selector(minimumValue);
  fVar3 = (float)_objc_msgSend(*(undefined8 *)(param_1 + lVar2),@selector(minimumValue));
  fVar4 = (float)_objc_msgSend(*(undefined8 *)(param_1 + lVar2),@selector(maximumValue));
  fVar5 = (float)_objc_msgSend(*(undefined8 *)(param_1 + lVar2),puVar1);
  fVar3 = *(float *)(param_1 + (long)_step) *
          (float)(int)((fVar3 + (fVar4 - fVar5) * (float)(dVar6 / in_d2)) /
                      *(float *)(param_1 + (long)_step));
  _objc_msgSend(fVar3,*(undefined8 *)(param_1 + lVar2),@selector(setValue:));
  _objc_msgSend(fVar3,param_1,@selector(updateLabel:));
  CallSupervisor(0xeca0);
  return;
}



// -[YTPSpeedControlView minusTapped], 0x239c94
/* Decompiled from supplied 5.2.2 arm package. VA 0x239c94. minusTapped */

/* Function Stack Size: 0x10 bytes */

void YTPSpeedControlView::minusTapped(ID param_1,SEL param_2)

{
  long lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  lVar1 = (long)_slider;
  fVar2 = (float)_objc_msgSend(*(undefined8 *)(param_1 + lVar1),@selector(minimumValue));
  fVar3 = (float)_objc_msgSend(*(undefined8 *)(param_1 + lVar1),@selector(value));
  fVar5 = *(float *)(param_1 + (long)_step);
  fVar4 = fVar3 - fVar5;
  if (fVar3 - fVar5 <= fVar2) {
    fVar4 = fVar2;
  }
  fVar5 = fVar5 * (float)(int)(fVar4 / fVar5);
  _objc_msgSend(fVar5,*(undefined8 *)(param_1 + lVar1),@selector(setValue:));
  _objc_msgSend(fVar5,param_1,@selector(updateLabel:));
  CallSupervisor(0xbe77);
  return;
}



// -[YTPSpeedControlView plusTapped], 0x239d48
/* Decompiled from supplied 5.2.2 arm package. VA 0x239d48. plusTapped */

/* Function Stack Size: 0x10 bytes */

void YTPSpeedControlView::plusTapped(ID param_1,SEL param_2)

{
  long lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  lVar1 = (long)_slider;
  fVar2 = (float)_objc_msgSend(*(undefined8 *)(param_1 + lVar1),@selector(maximumValue));
  fVar3 = (float)_objc_msgSend(*(undefined8 *)(param_1 + lVar1),@selector(value));
  fVar4 = *(float *)(param_1 + (long)_step);
  if (fVar3 + fVar4 <= fVar2) {
    fVar2 = fVar3 + fVar4;
  }
  fVar4 = fVar4 * (float)(int)(fVar2 / fVar4);
  _objc_msgSend(fVar4,*(undefined8 *)(param_1 + lVar1),@selector(setValue:));
  _objc_msgSend(fVar4,param_1,@selector(updateLabel:));
  return;
}



// -[YTPSpeedControlView presetTapped:], 0x239de0
/* Decompiled from supplied 5.2.2 arm package. VA 0x239de0. presetTapped: */

/* Function Stack Size: 0x18 bytes */

void YTPSpeedControlView::presetTapped_(ID param_1,SEL param_2,ID param_3)

{
  long lVar1;
  
  lVar1 = _objc_msgSend(param_3,@selector(tag));
  _objc_msgSend((float)((double)lVar1 / 100.0),*(undefined8 *)(param_1 + (long)_slider),
                @selector(setValue:));
  _objc_msgSend((float)((double)lVar1 / 100.0),param_1,@selector(updateLabel:));
  CallSupervisor(0x8e87);
  return;
}



// -[YTPSpeedControlView updateLabel:], 0x239e70
/* Decompiled from supplied 5.2.2 arm package. VA 0x239e70. updateLabel: */

/* Function Stack Size: 0x14 bytes */

void YTPSpeedControlView::updateLabel_(ID param_1,SEL param_2,float param_3)

{
  undefined8 uVar1;
  
  DAT_012284e8 = 1;
  thunk_FUN_0023b3fc((double)param_3,PTR__OBJC_CLASS___NSString_0114eb38,
                     @selector(stringWithFormat:),
                     @"%.2fx");
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_valueLabel),@selector(setText:),uVar1);
  _objc_release(uVar1);
  _objc_msgSend((double)param_3,PTR_YTPSpeedMaster_0114eca0,
                @selector(setPlaybackRate:forPlayer:),0);
  CallSupervisor(0x4b38);
  return;
}



// -[YTPSpeedControlView .cxx_destruct], 0x239ff4
/* Decompiled from supplied 5.2.2 arm package. VA 0x239ff4. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void YTPSpeedControlView::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_presets,0);
  _objc_storeStrong(param_1 + (long)_valueLabel,0);
  _objc_storeStrong(param_1 + (long)_slider,0);
  CallSupervisor(0xb6f);
  return;
}



// +[YTPSpeedControlView speedControls], 0x238360
/* Decompiled from supplied 5.2.2 arm package. VA 0x238360. speedControls */

/* Function Stack Size: 0x10 bytes */

ID YTPSpeedControlView::speedControls(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  ID IVar2;
  
  uVar1 = _objc_alloc(PTR_YTPSpeedControlView_0114f030);
  _objc_msgSend(*(undefined8 *)PTR__CGRectZero_01060260,
                *(undefined8 *)(PTR__CGRectZero_01060260 + 8),
                *(undefined8 *)(PTR__CGRectZero_01060260 + 0x10),
                *(undefined8 *)(PTR__CGRectZero_01060260 + 0x18),uVar1,@selector(initWithFrame:)
               );
  IVar2 = _objc_autoreleaseReturnValue();
  return IVar2;
}


