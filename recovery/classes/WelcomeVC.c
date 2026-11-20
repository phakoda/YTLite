// Decompiled implementation evidence for WelcomeVC. Not compilable source.

// -[WelcomeVC viewDidLoad], 0x3c314
/* Decompiled from supplied 5.2.2 arm package. VA 0x3c314. viewDidLoad */

/* Function Stack Size: 0x10 bytes */

void WelcomeVC::viewDidLoad(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  ID IVar9;
  int iVar10;
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
  undefined *puVar21;
  ulong uVar22;
  long lVar23;
  ulong uVar24;
  undefined8 auStack_490 [4];
  undefined8 auStack_470 [4];
  undefined8 auStack_450 [4];
  undefined8 auStack_430 [4];
  undefined8 auStack_410 [4];
  undefined8 auStack_3f0 [4];
  undefined8 auStack_3d0 [4];
  undefined8 auStack_3b0 [4];
  undefined8 auStack_390 [4];
  undefined8 auStack_370 [2];
  undefined1 auStack_360 [16];
  undefined auStack_350 [16];
  undefined auStack_340 [32];
  undefined auStack_320 [32];
  undefined1 auStack_300 [32];
  undefined1 auStack_2e0 [16];
  undefined8 uStack_2d0;
  undefined8 uStack_2c8;
  undefined8 uStack_2c0;
  undefined8 uStack_2b8;
  ID IStack_2b0;
  undefined *puStack_2a8;
  undefined *puStack_298;
  undefined *puStack_290;
  undefined8 uStack_288;
  undefined *puStack_280;
  undefined *puStack_278;
  undefined8 uStack_270;
  undefined8 uStack_268;
  undefined8 uStack_260;
  undefined8 uStack_258;
  undefined8 uStack_250;
  undefined8 *puStack_248;
  undefined8 *puStack_240;
  undefined8 *puStack_238;
  undefined8 *puStack_230;
  undefined8 *puStack_228;
  undefined8 *puStack_220;
  undefined8 *puStack_218;
  undefined8 *puStack_210;
  undefined8 *puStack_208;
  undefined8 *puStack_200;
  undefined *puStack_1f8;
  undefined *puStack_1f0;
  undefined *puStack_1e8;
  undefined *puStack_1e0;
  undefined *puStack_1d8;
  undefined *puStack_1d0;
  undefined *puStack_1c8;
  undefined *puStack_1c0;
  undefined *puStack_1b8;
  undefined *puStack_1b0;
  undefined *puStack_1a8;
  undefined *puStack_1a0;
  undefined *puStack_198;
  undefined *puStack_190;
  undefined *puStack_188;
  undefined *puStack_180;
  undefined *puStack_178;
  undefined *puStack_170;
  undefined *puStack_168;
  undefined *puStack_160;
  undefined *puStack_158;
  undefined *puStack_150;
  undefined *puStack_148;
  undefined1 *puStack_140;
  undefined8 *puStack_138;
  undefined *puStack_130;
  undefined1 *puStack_128;
  undefined1 *puStack_120;
  undefined1 *puStack_118;
  undefined *puStack_110;
  undefined *puStack_108;
  undefined1 *puStack_100;
  undefined *puStack_f8;
  undefined *puStack_f0;
  undefined8 *puStack_e8;
  undefined *puStack_e0;
  undefined *puStack_d8;
  undefined *puStack_d0;
  ID local_c8;
  uint uStack_bc;
  undefined **local_b8;
  undefined **ppuStack_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_0115c9e8;
  local_8c = (uint)(DAT_01225eb0 == 0);
  local_a0 = &PTR_LAB_0115ca08;
  ppuStack_98 = &PTR_LAB_0115c850;
  local_b8 = &PTR_LAB_0115ca28;
  ppuStack_b0 = &PTR_LAB_0115c850;
  DAT_01225eb0 = 1;
  puStack_138 = &uStack_2d0;
  puStack_128 = auStack_2e0;
  puStack_120 = auStack_300;
  puStack_168 = auStack_320;
  puStack_160 = auStack_340;
  puStack_150 = auStack_350;
  puStack_140 = auStack_360;
  puStack_248 = auStack_370;
  puStack_200 = auStack_390;
  puStack_238 = auStack_3b0;
  puStack_240 = auStack_3d0;
  puStack_228 = auStack_3f0;
  puStack_230 = auStack_410;
  puStack_218 = auStack_430;
  puStack_220 = auStack_450;
  puStack_208 = auStack_470;
  puStack_210 = auStack_490;
  puStack_2a8 = PTR_WelcomeVC_0114f090;
  IStack_2b0 = param_1;
  puStack_158 = puStack_160;
  puStack_148 = puStack_150;
  puStack_118 = puStack_120;
  puStack_110 = puStack_168;
  puStack_100 = puStack_128;
  puStack_e8 = puStack_138;
  local_c8 = param_1;
  _objc_msgSendSuper2(&IStack_2b0,@selector(viewDidLoad));
  puVar1 = @selector(navigationController);
  _objc_msgSend(param_1,@selector(navigationController));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar21 = @selector(navigationBar);
  _objc_msgSend(uVar11,@selector(navigationBar));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,@selector(setTranslucent:),1);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_msgSend(param_1,puVar1);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar21);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(new);
  uVar13 = _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,@selector(new));
  _objc_msgSend(uVar12,@selector(setBackgroundImage:forBarMetrics:),uVar13,0);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  uVar11 = _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,puVar2);
  _objc_msgSend(param_1,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,puVar21);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,@selector(setShadowImage:),uVar11);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  uVar11 = _objc_alloc(PTR__OBJC_CLASS___UITableView_0114ec70);
  uVar11 = _objc_msgSend(*(undefined8 *)PTR__CGRectZero_01060260,
                         *(undefined8 *)(PTR__CGRectZero_01060260 + 8),
                         *(undefined8 *)(PTR__CGRectZero_01060260 + 0x10),
                         *(undefined8 *)(PTR__CGRectZero_01060260 + 0x18),uVar11,
                         @selector(initWithFrame:style:),2);
  lVar23 = (long)_tableView;
  uVar12 = *(undefined8 *)(param_1 + lVar23);
  *(undefined8 *)(param_1 + lVar23) = uVar11;
  _objc_release(uVar12);
  puStack_1a8 = @selector(setTranslatesAutoresizingMaskIntoConstraints:);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar23),@selector(setTranslatesAutoresizingMaskIntoConstraints:),0)
  ;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar23),@selector(setDataSource:),param_1);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar23),@selector(setDelegate:),param_1);
  puStack_e0 = @selector(clearColor);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar23),@selector(setSeparatorColor:),uVar11);
  _objc_release(uVar11);
  puVar1 = @selector(view);
  _objc_msgSend(param_1,@selector(view));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puStack_1b8 = @selector(addSubview:);
  _objc_msgSend(uVar11,@selector(addSubview:),*(undefined8 *)(param_1 + lVar23));
  _objc_release(uVar11);
  _objc_msgSend(param_1,puVar1);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,@selector(bringSubviewToFront:),*(undefined8 *)(param_1 + lVar23));
  _objc_release(uVar11);
  _objc_msgSend(0,DAT_00c4c270,PTR__OBJC_CLASS___UIColor_0114eb18,
                @selector(colorWithWhite:alpha:));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puStack_d0 = @selector(setBackgroundColor:);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar23),@selector(setBackgroundColor:),uVar11);
  _objc_release(uVar11);
  puVar2 = @selector(centerXAnchor);
  puStack_178 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  puStack_1d0 = @selector(centerXAnchor);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar23),@selector(centerXAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puStack_108 = (undefined *)uVar11;
  _objc_msgSend(param_1,puVar1);
  puStack_f0 = (undefined *)_objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_f0,puVar2);
  puStack_130 = (undefined *)_objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(constraintEqualToAnchor:);
  _objc_msgSend(uVar11,@selector(constraintEqualToAnchor:),puStack_130);
  uStack_2d0 = _objc_retainAutoreleasedReturnValue();
  puVar21 = @selector(centerYAnchor);
  puStack_170 = (undefined *)uStack_2d0;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar23),@selector(centerYAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puStack_188 = (undefined *)uVar11;
  _objc_msgSend(param_1,puVar1);
  puStack_180 = (undefined *)_objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_180,puVar21);
  puStack_190 = (undefined *)_objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar2,puStack_190);
  uStack_2c8 = _objc_retainAutoreleasedReturnValue();
  puVar21 = @selector(widthAnchor);
  puStack_f8 = @selector(widthAnchor);
  puStack_1d8 = (undefined *)lVar23;
  puStack_198 = (undefined *)uStack_2c8;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar23),@selector(widthAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puStack_1b0 = puVar1;
  _objc_msgSend(param_1,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,puVar21);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puStack_1c0 = puVar2;
  _objc_msgSend(uVar11,puVar2,uVar13);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  puVar21 = @selector(heightAnchor);
  puStack_d8 = @selector(heightAnchor);
  uStack_2c0 = uVar14;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar23),@selector(heightAnchor));
  uVar15 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar16,puVar21);
  uVar17 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar15,puVar2,uVar17);
  uVar18 = _objc_retainAutoreleasedReturnValue();
  puStack_1a0 = @selector(arrayWithObjects:count:);
  uStack_2b8 = uVar18;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),puStack_e8
                ,4);
  uVar19 = _objc_retainAutoreleasedReturnValue();
  puStack_1c8 = @selector(activateConstraints:);
  _objc_msgSend(puStack_178,@selector(activateConstraints:),uVar19);
  _objc_release(uVar19);
  _objc_release(uVar18);
  _objc_release(uVar17);
  _objc_release(uVar16);
  _objc_release(uVar15);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(puStack_198);
  _objc_release(puStack_190);
  _objc_release(puStack_180);
  _objc_release(puStack_188);
  _objc_release(puStack_170);
  _objc_release(puStack_130);
  _objc_release(puStack_f0);
  _objc_release(puStack_108);
  uVar11 = _objc_alloc(PTR__OBJC_CLASS___UIVisualEffectView_0114ebd8);
  puStack_188 = @selector(effectWithStyle:);
  _objc_msgSend(PTR__OBJC_CLASS___UIBlurEffect_0114ebe0,@selector(effectWithStyle:),1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_190 = @selector(initWithEffect:);
  uVar11 = _objc_msgSend(uVar11,@selector(initWithEffect:),uVar12);
  _objc_release(uVar12);
  puVar21 = puStack_1b0;
  _objc_msgSend(param_1,puStack_1b0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_198 = @selector(bounds);
  _objc_msgSend();
  puStack_1e0 = @selector(setFrame:);
  _objc_msgSend(uVar11);
  _objc_release(uVar12);
  puStack_1e8 = @selector(setAutoresizingMask:);
  _objc_msgSend(uVar11,@selector(setAutoresizingMask:),0x12);
  _objc_msgSend(param_1,puVar21);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar2 = puStack_1b8;
  _objc_msgSend(uVar12,puStack_1b8,uVar11);
  _objc_release(uVar12);
  _objc_msgSend(param_1,puVar21);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  uStack_250 = uVar11;
  _objc_msgSend(uVar12,@selector(sendSubviewToBack:),uVar11);
  _objc_release(uVar12);
  uVar11 = _objc_alloc(PTR__OBJC_CLASS___UIImageView_0114ebf0);
  puStack_108 = @selector(imageNamed:);
  _objc_msgSend(param_1,@selector(imageNamed:),@"ytl_logo");
  uVar12 = _objc_retainAutoreleasedReturnValue();
  uVar13 = _objc_msgSend(uVar11,@selector(initWithImage:),uVar12);
  _objc_release(uVar12);
  uVar11 = _objc_alloc_init(PTR__OBJC_CLASS___UILabel_0114ec00);
  _objc_msgSend(uVar11,@selector(setText:),@"YouTube Plus");
  puStack_e8 = (undefined8 *)@selector(whiteColor);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,@selector(setTextColor:),uVar12);
  _objc_release(uVar12);
  puStack_130 = @selector(boldSystemFontOfSize:);
  _objc_msgSend(0x4038000000000000,PTR__OBJC_CLASS___UIFont_0114ec08);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_f0 = @selector(setFont:);
  _objc_msgSend(uVar11,@selector(setFont:),uVar12);
  _objc_release(uVar12);
  uVar12 = _objc_alloc(PTR__OBJC_CLASS___UIStackView_0114ec10);
  puVar4 = puStack_138;
  puStack_138[-2] = uVar13;
  puVar4[-1] = uVar11;
  uStack_260 = uVar11;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puStack_1a0,puStack_100,2);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  uVar12 = _objc_msgSend(uVar12,@selector(initWithArrangedSubviews:),uVar11);
  _objc_release(uVar11);
  puStack_180 = @selector(setAxis:);
  _objc_msgSend(uVar12,@selector(setAxis:),1);
  puStack_170 = @selector(setAlignment:);
  _objc_msgSend(uVar12,@selector(setAlignment:),3);
  puStack_178 = @selector(setSpacing:);
  _objc_msgSend(0x4034000000000000,uVar12);
  _objc_msgSend(uVar12,puStack_1a8,0);
  uVar11 = _objc_alloc(PTR__OBJC_CLASS___UIView_0114ec30);
  uVar11 = _objc_msgSend(0,0,0,DAT_00c4c278,uVar11,@selector(initWithFrame:));
  puVar1 = puStack_1d8;
  _objc_msgSend(*(undefined8 *)(param_1 + (long)puStack_1d8),@selector(setTableHeaderView:),
                uVar11);
  _objc_release(uVar11);
  iVar10 = FUN_000458f8();
  uVar11 = DAT_00c4c280;
  if (iVar10 == 0) {
    uVar11 = 0x4059000000000000;
  }
  _objc_msgSend(0,0,uVar11,0,*(undefined8 *)(param_1 + (long)puVar1),@selector(setContentInset:)
               );
  puVar3 = @selector(tableHeaderView);
  _objc_msgSend(*(undefined8 *)(param_1 + (long)puVar1),@selector(tableHeaderView));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar2,uVar12);
  _objc_release(uVar11);
  puVar2 = puStack_1d0;
  puStack_278 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  _objc_msgSend(uVar12,puStack_1d0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puStack_1f0 = (undefined *)uVar11;
  _objc_msgSend(param_1,puVar21);
  puStack_138 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_138,puVar2);
  puStack_1f8 = (undefined *)_objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puStack_1c0,puStack_1f8);
  uStack_270 = _objc_retainAutoreleasedReturnValue();
  puVar7 = puStack_128;
  *(undefined8 *)(puStack_128 + -0x20) = uStack_270;
  puVar2 = @selector(topAnchor);
  uStack_268 = uVar12;
  _objc_msgSend(uVar12,@selector(topAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + (long)puVar1),puVar3);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_280 = puVar2;
  _objc_msgSend(uVar12,puVar2);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  puStack_1d8 = @selector(constraintEqualToAnchor:constant:);
  _objc_msgSend(0x4044000000000000,uVar11,@selector(constraintEqualToAnchor:constant:),uVar14);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar7 + -0x18) = uVar15;
  _objc_msgSend(uVar13,puStack_d8);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(constraintEqualToConstant:);
  puStack_100 = @selector(constraintEqualToConstant:);
  _objc_msgSend(0x4060000000000000,uVar16,@selector(constraintEqualToConstant:));
  uVar17 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar7 + -0x10) = uVar17;
  uStack_258 = uVar13;
  _objc_msgSend(uVar13,puStack_f8);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4060000000000000,uVar13,puVar1);
  uVar18 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar7 + -8) = uVar18;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puStack_1a0,puStack_120,4);
  uVar19 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_278,puStack_1c8,uVar19);
  _objc_release(uVar19);
  _objc_release(uVar18);
  _objc_release(uVar13);
  _objc_release(uVar17);
  _objc_release(uVar16);
  _objc_release(uVar15);
  _objc_release(uVar14);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uStack_270);
  _objc_release(puStack_1f8);
  _objc_release(puStack_138);
  _objc_release(puStack_1f0);
  uVar11 = _objc_alloc_init(PTR__OBJC_CLASS___UIView_0114ec30);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puStack_e0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puStack_d0,uVar12);
  _objc_release(uVar12);
  _objc_msgSend(uVar11,@selector(setUserInteractionEnabled:),0);
  puVar1 = @selector(layer);
  _objc_msgSend(uVar11,@selector(layer));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_138 = (undefined8 *)@selector(setCornerRadius:);
  _objc_msgSend(0x4018000000000000);
  _objc_release(uVar12);
  uVar13 = *(undefined8 *)PTR__kCACornerCurveContinuous_01060bb0;
  uStack_288 = uVar13;
  _objc_msgSend(uVar11,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_290 = @selector(setCornerCurve:);
  _objc_msgSend(uVar12,@selector(setCornerCurve:),uVar13);
  _objc_release(uVar12);
  puStack_298 = puVar1;
  _objc_msgSend(uVar11,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,@selector(setMaskedCorners:),3);
  _objc_release(uVar12);
  _objc_msgSend(uVar11,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,@selector(setMasksToBounds:),1);
  _objc_release(uVar12);
  _objc_msgSend(uVar11,puStack_1a8,0);
  IVar9 = local_c8;
  puVar21 = puStack_1b0;
  _objc_msgSend(local_c8,puStack_1b0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar1 = puStack_1b8;
  _objc_msgSend(uVar12,puStack_1b8,uVar11);
  _objc_release(uVar12);
  uVar12 = _objc_alloc(PTR__OBJC_CLASS___UIVisualEffectView_0114ebd8);
  _objc_msgSend(PTR__OBJC_CLASS___UIBlurEffect_0114ebe0,puStack_188,2);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  uVar12 = _objc_msgSend(uVar12,puStack_190,uVar13);
  _objc_release(uVar13);
  _objc_msgSend(uVar12,puStack_1e8,0x12);
  _objc_msgSend(uVar11,puStack_198);
  _objc_msgSend(uVar12,puStack_1e0);
  _objc_msgSend(DAT_00c4c250,uVar12,@selector(setAlpha:));
  puStack_278 = (undefined *)uVar12;
  _objc_msgSend(uVar11,puVar1,uVar12);
  puVar1 = @selector(leadingAnchor);
  puStack_198 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  _objc_msgSend(uVar11,@selector(leadingAnchor));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_128 = (undefined1 *)uVar12;
  _objc_msgSend(IVar9,puVar21);
  puStack_120 = (undefined1 *)_objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_120,puVar1);
  puStack_188 = (undefined *)_objc_retainAutoreleasedReturnValue();
  puVar2 = puStack_1c0;
  _objc_msgSend(uVar12,puStack_1c0,puStack_188);
  puStack_190 = (undefined *)_objc_retainAutoreleasedReturnValue();
  puVar7 = puStack_118;
  *(undefined **)(puStack_118 + -0x20) = puStack_190;
  puVar1 = @selector(trailingAnchor);
  _objc_msgSend(uVar11,@selector(trailingAnchor));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_1e0 = (undefined *)uVar12;
  _objc_msgSend(IVar9,puVar21);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,puVar1);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,puVar2,uVar14);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar7 + -0x18) = uVar12;
  puVar1 = @selector(bottomAnchor);
  puStack_1f8 = @selector(bottomAnchor);
  _objc_msgSend(uVar11,@selector(bottomAnchor));
  uVar15 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(IVar9,puVar21);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar16,puVar1);
  uVar17 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar15,puVar2,uVar17);
  uVar18 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar7 + -0x10) = uVar18;
  uStack_270 = uVar11;
  _objc_msgSend(uVar11,puStack_d8);
  uVar19 = _objc_retainAutoreleasedReturnValue();
  iVar10 = FUN_00045fbc();
  uVar11 = DAT_00c4c290;
  if (iVar10 == 0) {
    uVar11 = DAT_00c4c288;
  }
  _objc_msgSend(uVar11,uVar19,puStack_100);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar7 + -8) = uVar11;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puStack_1a0,puStack_110,4);
  uVar20 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_198,puStack_1c8,uVar20);
  _objc_release(uVar20);
  _objc_release(uVar11);
  _objc_release(uVar19);
  _objc_release(uVar18);
  _objc_release(uVar17);
  _objc_release(uVar16);
  _objc_release(uVar15);
  _objc_release(uVar12);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(puStack_1e0);
  _objc_release(puStack_190);
  _objc_release(puStack_188);
  _objc_release(puStack_120);
  _objc_release(puStack_128);
  puStack_110 = @selector(buttonWithType:);
  _objc_msgSend(PTR__OBJC_CLASS___UIButton_0114ec38,@selector(buttonWithType:),0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puStack_1e8 = @selector(ytl_defaultBundle);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_1f0 = @selector(localizedStringForKey:value:table:);
  _objc_msgSend(uVar12,@selector(localizedStringForKey:value:table:),
                @"Continue",0,0);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puStack_118 = @selector(setTitle:forState:);
  _objc_msgSend(uVar11,@selector(setTitle:forState:),uVar13,0);
  _objc_release(uVar13);
  _objc_release(uVar12);
  puVar4 = puStack_e8;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puStack_e8);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(setTitleColor:forState:);
  _objc_msgSend(uVar11,@selector(setTitleColor:forState:),uVar12,0);
  _objc_release(uVar12);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar4);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(colorWithAlphaComponent:);
  _objc_msgSend(0x3fe0000000000000,uVar12,@selector(colorWithAlphaComponent:));
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puStack_120 = puVar2;
  _objc_msgSend(uVar11,puVar2,uVar13,1);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_msgSend(0x402e000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,puStack_130);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_130 = @selector(titleLabel);
  _objc_msgSend(uVar11);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,puStack_f0,uVar12);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar4);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_128 = puVar1;
  _objc_msgSend(DAT_00c4c258,uVar12,puVar1);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puStack_d0,uVar13);
  _objc_release(uVar13);
  _objc_release(uVar12);
  puVar1 = puStack_298;
  _objc_msgSend(uVar11,puStack_298);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4039000000000000,uVar12,puStack_138);
  _objc_release(uVar12);
  _objc_msgSend(uVar11,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,puStack_290,uStack_288);
  _objc_release(uVar12);
  _objc_msgSend(uVar11,puStack_1a8,0);
  IVar9 = local_c8;
  puStack_138 = (undefined8 *)@selector(addTarget:action:forControlEvents:);
  _objc_msgSend(uVar11,@selector(addTarget:action:forControlEvents:),local_c8,
                @selector(thanksButtonTapped),0x40);
  puVar2 = puStack_1b0;
  _objc_msgSend(IVar9,puStack_1b0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,puStack_1b8,uVar11);
  _objc_release(uVar12);
  puVar1 = puStack_1d0;
  puStack_290 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  _objc_msgSend(uVar11,puStack_1d0);
  puVar21 = (undefined *)_objc_retainAutoreleasedReturnValue();
  puStack_190 = puVar21;
  _objc_msgSend(IVar9,puVar2);
  puStack_188 = (undefined *)_objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_188,puVar1);
  puStack_198 = (undefined *)_objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar21,puStack_1c0,puStack_198);
  uStack_288 = _objc_retainAutoreleasedReturnValue();
  puVar21 = puStack_168;
  *(undefined8 *)(puStack_168 + -0x20) = uStack_288;
  puVar1 = puStack_1f8;
  _objc_msgSend(uVar11,puStack_1f8);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(IVar9,puVar2);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,puVar1);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  iVar10 = FUN_00046400();
  uVar15 = 0xc04e000000000000;
  if (iVar10 == 0) {
    uVar15 = 0xc034000000000000;
  }
  _objc_msgSend(uVar15,uVar12,puStack_1d8,uVar14);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar21 + -0x18) = uVar15;
  _objc_msgSend(uVar11,puStack_d8);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  puVar7 = puStack_100;
  _objc_msgSend(0x4049000000000000,uVar16,puStack_100);
  uVar17 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar21 + -0x10) = uVar17;
  puStack_1e0 = (undefined *)uVar11;
  _objc_msgSend(uVar11,puStack_f8);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(DAT_00c4c238,uVar11,puVar7);
  uVar18 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar21 + -8) = uVar18;
  puVar1 = puStack_1a0;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puStack_1a0,puStack_160,4);
  uVar19 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_290,puStack_1c8,uVar19);
  _objc_release(uVar19);
  _objc_release(uVar18);
  _objc_release(uVar11);
  _objc_release(uVar17);
  _objc_release(uVar16);
  _objc_release(uVar15);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uStack_288);
  _objc_release(puStack_198);
  _objc_release(puStack_188);
  _objc_release(puStack_190);
  uVar11 = _objc_alloc_init(PTR__OBJC_CLASS___UIStackView_0114ec10);
  _objc_msgSend(uVar11,puStack_180,0);
  _objc_msgSend(uVar11,@selector(setDistribution:),1);
  _objc_msgSend(uVar11,puStack_170,3);
  _objc_msgSend(0x4024000000000000,uVar11,puStack_178);
  puStack_d8 = (undefined *)uVar11;
  _objc_msgSend(uVar11,puStack_1a8,0);
  puVar2 = puStack_158;
  *(undefined ***)(puStack_158 + -0x10) = @"@Dayanch96";
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_1e8);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puStack_1f0,@"SupportMe",0,0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar2 + -8) = uVar12;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar1,puStack_150,2);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar12);
  _objc_release(uVar11);
  puVar2 = puStack_148;
  *(undefined ***)(puStack_148 + -0x10) = @"x";
  *(undefined ***)(puVar2 + -8) = @"heart";
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar1,puStack_140,2);
  puStack_100 = (undefined1 *)_objc_retainAutoreleasedReturnValue();
  puStack_140 = @selector(count);
  puStack_f8 = (undefined *)uVar13;
  lVar23 = _objc_msgSend(uVar13);
  puVar4 = puStack_e8;
  puVar2 = puStack_f8;
  puVar8 = puStack_120;
  puVar7 = puStack_128;
  puVar1 = @selector(objectAtIndexedSubscript:);
  uStack_a4 = (uint)(lVar23 == 0);
  if (lVar23 != 0) {
    uVar24 = 0;
    uVar11 = *(undefined8 *)PTR__UIFontWeightLight_01060568;
    puStack_148 = @selector(monospacedDigitSystemFontOfSize:weight:);
    puStack_150 = @selector(setTintColor:);
    puStack_158 = @selector(contactsButtonTapped:);
    puStack_160 = @selector(imageWithRenderingMode:);
    puStack_168 = @selector(setImage:forState:);
    puStack_170 = @selector(imageView);
    puStack_178 = @selector(setContentMode:);
    puStack_180 = @selector(setSemanticContentAttribute:);
    puStack_188 = @selector(setImageEdgeInsets:);
    puStack_190 = @selector(setTag:);
    puStack_198 = @selector(addArrangedSubview:);
    do {
      _objc_msgSend(PTR__OBJC_CLASS___UIButton_0114ec38,puStack_110,1);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puVar2,puVar1,uVar24);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar12,puStack_118,uVar13,0);
      _objc_release(uVar13);
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar4);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0x3fe8000000000000,uVar13,puVar7);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar12,puVar8,uVar14,0);
      _objc_release(uVar14);
      _objc_release(uVar13);
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar4);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0x3fe0000000000000,uVar13,puVar7);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar12,puVar8,uVar14,1);
      _objc_release(uVar14);
      _objc_release(uVar13);
      _objc_msgSend(uVar12,puStack_130);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0x402c000000000000,uVar11,PTR__OBJC_CLASS___UIFont_0114ec08,puStack_148);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar13,puStack_f0,uVar14);
      _objc_release(uVar14);
      _objc_release(uVar13);
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puStack_e0);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar12,puStack_d0,uVar13);
      _objc_release(uVar13);
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar4);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar12,puStack_150,uVar13);
      _objc_release(uVar13);
      IVar9 = local_c8;
      _objc_msgSend(uVar12,puStack_138,local_c8,puStack_158,0x40);
      _objc_msgSend(puStack_100,puVar1,uVar24);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(IVar9,puStack_108,uVar13);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar14,puStack_160,2);
      uVar15 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar12,puStack_168,uVar15,0);
      _objc_release(uVar15);
      _objc_release(uVar14);
      _objc_release(uVar13);
      _objc_msgSend(uVar12,puStack_170);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar13,puStack_178,1);
      _objc_release(uVar13);
      _objc_msgSend(uVar12,puStack_180,3);
      _objc_msgSend(0,0xc014000000000000,0,0x4014000000000000,uVar12,puStack_188);
      _objc_msgSend(uVar12,puStack_190,uVar24);
      _objc_msgSend(puStack_d8,puStack_198,uVar12);
      _objc_release(uVar12);
      uVar24 = uVar24 + 1;
      uVar22 = _objc_msgSend(puVar2,puStack_140);
      CallSupervisor(0x18bd);
      uStack_bc = (uint)(uVar24 < uVar22);
    } while (uVar24 < uVar22);
  }
  puVar3 = puStack_d8;
  _objc_msgSend(puStack_d8,puStack_1a8,0);
  IVar9 = local_c8;
  puVar21 = puStack_1b0;
  _objc_msgSend(local_c8,puStack_1b0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puStack_1b8,puVar3);
  _objc_release(uVar11);
  puVar2 = puStack_1d0;
  puVar1 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  _objc_msgSend(puVar3,puStack_1d0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(IVar9,puVar21);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,puVar2);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puStack_1c0,uVar13);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  puVar4 = puStack_248;
  *puStack_248 = uVar14;
  _objc_msgSend(puVar3,puStack_1f8);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_1e0,puStack_280);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0xc02e000000000000,uVar15,puStack_1d8,uVar16);
  uVar17 = _objc_retainAutoreleasedReturnValue();
  puVar4[1] = uVar17;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puStack_1a0,puVar4,2);
  uVar18 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,puStack_1c8,uVar18);
  _objc_release(uVar18);
  _objc_release(uVar17);
  _objc_release(uVar16);
  _objc_release(uVar15);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  puVar4 = puStack_240;
  *puStack_240 = @"title";
  puVar21 = puStack_1e8;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_1e8);
  puStack_d0 = (undefined *)_objc_retainAutoreleasedReturnValue();
  puVar2 = puStack_1f0;
  _objc_msgSend(puStack_d0,puStack_1f0,@"Welcome.Download",0,0);
  puStack_e0 = (undefined *)_objc_retainAutoreleasedReturnValue();
  puVar5 = puStack_238;
  *puStack_238 = puStack_e0;
  puVar4[1] = @"desc";
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar21);
  puStack_e8 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_e8,puVar2,@"Welcome.DownloadDesc",0,0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(dictionaryWithObjects:forKeys:count:);
  puStack_f0 = (undefined *)uVar11;
  puVar4[2] = @"image";
  puVar5[1] = uVar11;
  puVar5[2] = @"arrow.down.app";
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                @selector(dictionaryWithObjects:forKeys:count:),puVar5,puVar4,3);
  puStack_108 = (undefined *)_objc_retainAutoreleasedReturnValue();
  puVar6 = puStack_200;
  *puStack_200 = puStack_108;
  puVar4 = puStack_230;
  *puStack_230 = @"title";
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar21);
  puStack_110 = (undefined *)_objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_110,puVar2,@"Welcome.Content",0,0);
  puStack_118 = (undefined1 *)_objc_retainAutoreleasedReturnValue();
  puVar5 = puStack_228;
  *puStack_228 = puStack_118;
  puVar4[1] = @"desc";
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar21);
  puStack_120 = (undefined1 *)_objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_120,puVar2,@"Welcome.ContentDesc",0,0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puStack_128 = (undefined1 *)uVar11;
  puVar4[2] = @"image";
  puVar5[1] = uVar11;
  puVar5[2] = @"paintbrush";
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar5,puVar4,3);
  puStack_130 = (undefined *)_objc_retainAutoreleasedReturnValue();
  puVar6[1] = puStack_130;
  puVar4 = puStack_220;
  *puStack_220 = @"title";
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar21);
  puStack_138 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_138,puVar2,@"Welcome.Player",0,0);
  puStack_140 = (undefined1 *)_objc_retainAutoreleasedReturnValue();
  puVar5 = puStack_218;
  *puStack_218 = puStack_140;
  puVar4[1] = @"desc";
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar21);
  puStack_148 = (undefined *)_objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_148,puVar2,@"Welcome.PlayerDesc",0,0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puStack_150 = (undefined *)uVar11;
  puVar4[2] = @"image";
  puVar5[1] = uVar11;
  puVar5[2] = @"hand.draw";
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar5,puVar4,3);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar6[2] = uVar11;
  puVar4 = puStack_210;
  *puStack_210 = @"title";
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar21);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,puVar2,@"Welcome.More",0,0);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puVar5 = puStack_208;
  *puStack_208 = uVar13;
  puVar4[1] = @"desc";
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar21);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar14,puVar2,@"Welcome.MoreDesc",0,0);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  puVar4[2] = @"image";
  puVar5[1] = uVar15;
  puVar5[2] = @"ellipsis";
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar5,puVar4,3);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  puVar6[3] = uVar16;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puStack_1a0,puVar6,4);
  uVar17 = _objc_retainAutoreleasedReturnValue();
  uVar18 = *(undefined8 *)(local_c8 + (long)_settingsData);
  *(undefined8 *)(local_c8 + (long)_settingsData) = uVar17;
  _objc_release(uVar18);
  _objc_release(uVar16);
  _objc_release(uVar15);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(puStack_150);
  _objc_release(puStack_148);
  _objc_release(puStack_140);
  _objc_release(puStack_138);
  _objc_release(puStack_130);
  _objc_release(puStack_128);
  _objc_release(puStack_120);
  _objc_release(puStack_118);
  _objc_release(puStack_110);
  _objc_release(puStack_108);
  _objc_release(puStack_f0);
  _objc_release(puStack_e8);
  _objc_release(puStack_e0);
  _objc_release(puStack_d0);
  _objc_release(puStack_100);
  _objc_release(puStack_f8);
  _objc_release(puStack_d8);
  _objc_release(puStack_1e0);
  _objc_release(puStack_278);
  _objc_release(uStack_270);
  _objc_release(uStack_268);
  _objc_release(uStack_260);
  _objc_release(uStack_258);
  _objc_release(uStack_250);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}



// -[WelcomeVC thanksButtonTapped], 0x3f84c
/* Decompiled from supplied 5.2.2 arm package. VA 0x3f84c. thanksButtonTapped */

/* Function Stack Size: 0x10 bytes */

void WelcomeVC::thanksButtonTapped(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  DAT_01225eb4 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(setBool:forKey:),1,
                @"hasShownWelcome");
  _objc_release(uVar1);
  _objc_msgSend(param_1,@selector(dismissViewControllerAnimated:completion:),1,0);
  CallSupervisor(0xfec2);
  return;
}



// -[WelcomeVC contactsButtonTapped:], 0x3fa3c
/* Decompiled from supplied 5.2.2 arm package. VA 0x3fa3c. contactsButtonTapped: */

/* Function Stack Size: 0x18 bytes */

void WelcomeVC::contactsButtonTapped_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  DAT_01225eb8 = 1;
  uVar4 = _objc_retain(param_3);
  puVar2 = @selector(tag);
  lVar5 = _objc_msgSend(uVar4,@selector(tag));
  puVar1 = @selector(sharedApplication);
  if (lVar5 == 0) {
    _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar2 = @selector(URLWithString:);
    _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,@selector(URLWithString:),
                  @"twitter://user?screen_name=Dayanch96");
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar3 = FUN_00046868(uVar4,@selector(canOpenURL:),uVar6);
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    if (uVar3 == 0) {
      _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,puVar2,
                    @"https://twitter.com/Dayanch96");
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,@selector(openURL:options:completionHandler:),uVar6,
                    *(undefined8 *)PTR____NSDictionary0___01060678,0);
    }
    else {
      _objc_msgSend((&PTR_LAB_0115ca98)[uVar3] + (int)-(uRam000000000115caa8 ^ 0xd075c518),
                    PTR__OBJC_CLASS___NSURL_0114eb78,puVar2,
                    @"twitter://user?screen_name=Dayanch96");
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,@selector(openURL:options:completionHandler:),uVar6,
                    *(undefined8 *)PTR____NSDictionary0___01060678,0);
    }
    _objc_release(uVar6);
    _objc_release(uVar4);
  }
  else {
    lVar5 = _objc_msgSend((&PTR_LAB_0115ca80)[lVar5 == 0] +
                          (int)-(uRam000000000115ca90 ^ 0xc78d51ca),param_3,puVar2);
    if (lVar5 == 1) {
      if (lRam0000000001225ea0 == 0) {
        lRam0000000001225ea0 =
             _objc_getClass((&PTR_LAB_0115cad8)[lRam0000000001225ea0 == 0] +
                            (int)-(uRam000000000115cae8 ^ 0x1f9c2d39),
                            s_YTDefaultSheetController_0115bca0);
      }
      lVar5 = lRam0000000001225ea0;
      _objc_retainAutorelease(lRam0000000001225ea0);
      puVar1 = @selector(ytl_defaultBundle);
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
      uVar4 = _objc_retainAutoreleasedReturnValue();
      puVar2 = @selector(localizedStringForKey:value:table:);
      _objc_msgSend(uVar4,@selector(localizedStringForKey:value:table:),
                    @"SupportDevelopment",0,0);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,puVar2,@"SupportDevelopmentDesc",0,0);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar5,@selector(sheetControllerWithMessage:subMessage:delegate:parentResponder:),uVar6,uVar8,0,0);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar8);
      _objc_release(uVar7);
      _objc_release(uVar6);
      _objc_release(uVar4);
      puVar1 = @selector(valueForKey:);
      _objc_msgSend(uVar9,@selector(valueForKey:),
                    @"_headerView");
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,puVar1,@"_subtitleLabel");
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(setNumberOfLines:),0);
      _objc_msgSend(uVar4,@selector(showHeaderDivider));
                    /* WARNING: Could not recover jumptable at 0x000410e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((&PTR_LAB_0115caf8)[DAT_01225ea8 == 0] + (int)-(DAT_0115cb08 ^ 0x829cf339)))();
      return;
    }
  }
  _objc_release(param_3);
  CallSupervisor(0xb3ce);
  return;
}



// -[WelcomeVC imageNamed:], 0x42c68
/* Decompiled from supplied 5.2.2 arm package. VA 0x42c68. imageNamed: */

/* Function Stack Size: 0x18 bytes */

ID WelcomeVC::imageNamed_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  
  puVar3 = PTR__OBJC_CLASS___UIImage_0114ebf8;
  puVar2 = PTR__OBJC_CLASS___NSBundle_0114eae8;
  puVar1 = @selector(ytl_defaultBundle);
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar3,@selector(imageNamed:inBundle:compatibleWithTraitCollection:),param_3,uVar4,0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_release(uVar4);
  IVar6 = _objc_autoreleaseReturnValue(uVar5);
  return IVar6;
}



// -[WelcomeVC tableView:heightForRowAtIndexPath:], 0x42d00
/* Decompiled from supplied 5.2.2 arm package. VA 0x42d00. tableView:heightForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

double WelcomeVC::tableView_heightForRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  return *(double *)PTR__UITableViewAutomaticDimension_010605d8;
}



// -[WelcomeVC numberOfSectionsInTableView:], 0x42d10
/* Decompiled from supplied 5.2.2 arm package. VA 0x42d10. numberOfSectionsInTableView: */

/* Function Stack Size: 0x18 bytes */

long_long WelcomeVC::numberOfSectionsInTableView_(ID param_1,SEL param_2,ID param_3)

{
  return 1;
}



// -[WelcomeVC tableView:numberOfRowsInSection:], 0x42d18
/* Decompiled from supplied 5.2.2 arm package. VA 0x42d18. tableView:numberOfRowsInSection: */

/* Function Stack Size: 0x20 bytes */

long_long WelcomeVC::tableView_numberOfRowsInSection_
                    (ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  long_long lVar1;
  
  lVar1 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_settingsData),@selector(count));
  return lVar1;
}



// -[WelcomeVC tableView:willDisplayCell:forRowAtIndexPath:], 0x42d30
/* Decompiled from supplied 5.2.2 arm package. VA 0x42d30. tableView:willDisplayCell:forRowAtIndexPath: */

/* Function Stack Size: 0x28 bytes */

void WelcomeVC::tableView_willDisplayCell_forRowAtIndexPath_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  _objc_msgSend(param_3,@selector(setSeparatorStyle:),0);
  return;
}



// -[WelcomeVC tableView:cellForRowAtIndexPath:], 0x42d44
/* Decompiled from supplied 5.2.2 arm package. VA 0x42d44. tableView:cellForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

ID WelcomeVC::tableView_cellForRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  ID IVar12;
  undefined8 uVar13;
  
  DAT_01225ef0 = 1;
  _objc_retain(param_4);
  _objc_msgSend(param_3,@selector(dequeueReusableCellWithIdentifier:),
                @"cell");
  lVar7 = _objc_retainAutoreleasedReturnValue();
  if (lVar7 == 0) {
    uVar9 = _objc_alloc(PTR__OBJC_CLASS___UITableViewCell_0114ec80);
    lVar7 = _objc_msgSend(uVar9,@selector(initWithStyle:reuseIdentifier:),3,
                          @"cell");
  }
  lVar8 = _objc_msgSend(param_4,@selector(section));
  if (lVar8 == 0) {
    uVar13 = *(undefined8 *)(param_1 + (long)_settingsData);
    uVar9 = _objc_msgSend(param_4,@selector(row));
    _objc_msgSend(uVar13,@selector(objectAtIndexedSubscript:),uVar9);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(objectForKeyedSubscript:);
    _objc_msgSend(uVar9,@selector(objectForKeyedSubscript:),
                  @"title");
    uVar13 = _objc_retainAutoreleasedReturnValue();
    puVar4 = @selector(textLabel);
    _objc_msgSend(lVar7,@selector(textLabel));
    uVar10 = _objc_retainAutoreleasedReturnValue();
    puVar3 = @selector(setText:);
    _objc_msgSend(uVar10,@selector(setText:),uVar13);
    _objc_release(uVar10);
    _objc_release(uVar13);
    _objc_msgSend(0x4030000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,
                  @selector(boldSystemFontOfSize:));
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar7,puVar4);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    puVar5 = @selector(setFont:);
    _objc_msgSend(uVar10,@selector(setFont:),uVar13);
    _objc_release(uVar10);
    _objc_release(uVar13);
    _objc_msgSend(lVar7,puVar4);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar13,@selector(setAdjustsFontSizeToFitWidth:),1);
    _objc_release(uVar13);
    puVar2 = @selector(whiteColor);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(whiteColor));
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar7,puVar4);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    puVar4 = @selector(setTextColor:);
    _objc_msgSend(uVar10,@selector(setTextColor:),uVar13);
    _objc_release(uVar10);
    _objc_release(uVar13);
    _objc_msgSend(uVar9,puVar1,@"desc");
    uVar13 = _objc_retainAutoreleasedReturnValue();
    puVar6 = @selector(detailTextLabel);
    _objc_msgSend(lVar7,@selector(detailTextLabel));
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar10,puVar3,uVar13);
    _objc_release(uVar10);
    _objc_release(uVar13);
    _objc_msgSend(lVar7,puVar6);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar13,@selector(setNumberOfLines:),0);
    _objc_release(uVar13);
    _objc_msgSend(0x402c000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,
                  @selector(systemFontOfSize:));
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar7,puVar6);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar10,puVar5,uVar13);
    _objc_release(uVar10);
    _objc_release(uVar13);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar2);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(DAT_00c4c250,uVar13,@selector(colorWithAlphaComponent:));
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar7,puVar6);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar11,puVar4,uVar10);
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar13);
    _objc_msgSend(uVar9,puVar1,@"image");
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,@selector(cellImageWithName:),uVar13);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar7,@selector(imageView));
    uVar11 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar11,@selector(setImage:),uVar10);
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar13);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(clearColor));
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar7,@selector(setBackgroundColor:),uVar13);
    _objc_release(uVar13);
    _objc_msgSend(lVar7,@selector(setUserInteractionEnabled:),0);
    _objc_release(uVar9);
  }
  _objc_release(param_4);
  IVar12 = _objc_autoreleaseReturnValue(lVar7);
  return IVar12;
}



// -[WelcomeVC tableView:shouldHighlightRowAtIndexPath:], 0x4343c
/* Decompiled from supplied 5.2.2 arm package. VA 0x4343c. tableView:shouldHighlightRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

bool WelcomeVC::tableView_shouldHighlightRowAtIndexPath_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  return 0;
}



// -[WelcomeVC showAlertWithTitle:imageName:], 0x43444
/* Decompiled from supplied 5.2.2 arm package. VA 0x43444. showAlertWithTitle:imageName: */

/* Function Stack Size: 0x20 bytes */

void WelcomeVC::showAlertWithTitle_imageName_(ID param_1,SEL param_2,ID param_3,ID param_4)

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
  undefined *puVar10;
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
  undefined *local_1b0;
  undefined8 local_1a8;
  code *local_1a0;
  undefined *puStack_198;
  undefined8 local_190;
  undefined8 local_188;
  ID local_180;
  undefined *local_178;
  undefined8 local_170;
  code *local_168;
  undefined *puStack_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  long local_88;
  
  puVar1 = PTR__OBJC_CLASS___UIImpactFeedbackGenerator_0114ec68;
  local_88 = *(long *)PTR____stack_chk_guard_01060708;
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar11 = _objc_alloc(puVar1);
  uVar12 = _objc_msgSend(uVar11,@selector(initWithStyle:),1);
  _objc_msgSend(uVar12,@selector(prepare));
  uVar11 = _objc_alloc(PTR__OBJC_CLASS___UIImageView_0114ebf0);
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,@selector(systemImageNamed:),param_4);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_4);
  uVar14 = _objc_msgSend(uVar11,@selector(initWithImage:),uVar13);
  _objc_release(uVar13);
  puVar1 = @selector(whiteColor);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(whiteColor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar14,@selector(setTintColor:),uVar11);
  _objc_release(uVar11);
  _objc_msgSend(uVar14,@selector(setContentMode:),1);
  uVar13 = _objc_alloc_init(PTR__OBJC_CLASS___UILabel_0114ec00);
  _objc_msgSend(uVar13,@selector(setText:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar13,@selector(setTextAlignment:),1);
  _objc_msgSend(0x4030000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,
                @selector(boldSystemFontOfSize:));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,@selector(setFont:),uVar11);
  _objc_release(uVar11);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,@selector(setTextColor:),uVar11);
  _objc_release(uVar11);
  _objc_msgSend(uVar13,@selector(setNumberOfLines:),2);
  uVar11 = _objc_alloc(PTR__OBJC_CLASS___UIStackView_0114ec10);
  puVar4 = @selector(arrayWithObjects:count:);
  local_98 = uVar14;
  uStack_90 = uVar13;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),&local_98,
                2);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  uVar16 = _objc_msgSend(uVar11,@selector(initWithArrangedSubviews:),uVar15);
  _objc_release(uVar15);
  _objc_msgSend(uVar16,@selector(setAxis:),1);
  _objc_msgSend(uVar16,@selector(setAlignment:),3);
  _objc_msgSend(uVar16,@selector(setDistribution:),2);
  _objc_msgSend(0x4014000000000000,uVar16,@selector(setSpacing:));
  puVar2 = @selector(setTranslatesAutoresizingMaskIntoConstraints:);
  _objc_msgSend(uVar16,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
  uVar11 = _objc_alloc(PTR__OBJC_CLASS___UIVisualEffectView_0114ebd8);
  _objc_msgSend(PTR__OBJC_CLASS___UIBlurEffect_0114ebe0,@selector(effectWithStyle:),4);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  uVar17 = _objc_msgSend(uVar11,@selector(initWithEffect:),uVar15);
  _objc_release(uVar15);
  puVar1 = @selector(layer);
  _objc_msgSend(uVar17,@selector(layer));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x402e000000000000,uVar11,@selector(setCornerRadius:));
  _objc_release(uVar11);
  uVar15 = *(undefined8 *)PTR__kCACornerCurveContinuous_01060bb0;
  _objc_msgSend(uVar17,puVar1);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,@selector(setCornerCurve:),uVar15);
  _objc_release(uVar11);
  _objc_msgSend(uVar17,@selector(setClipsToBounds:),1);
  _objc_msgSend(uVar17,puVar2,0);
  _objc_msgSend(uVar17,@selector(setUserInteractionEnabled:),0);
  _objc_msgSend(uVar17,@selector(contentView));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(addSubview:);
  _objc_msgSend(uVar11,@selector(addSubview:),uVar16);
  _objc_release(uVar11);
  puVar1 = @selector(view);
  _objc_msgSend(param_1,@selector(view));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar2,uVar17);
  _objc_release(uVar11);
  puVar3 = @selector(centerYAnchor);
  _objc_msgSend(uVar17,@selector(centerYAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar15,puVar3);
  uVar18 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(constraintEqualToAnchor:);
  _objc_msgSend(uVar11,@selector(constraintEqualToAnchor:),uVar18);
  uVar19 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar18);
  _objc_release(uVar15);
  _objc_release(uVar11);
  puVar10 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  puVar5 = @selector(centerXAnchor);
  _objc_msgSend(uVar16,@selector(centerXAnchor));
  uVar15 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar17,puVar5);
  uVar18 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar15,puVar2,uVar18);
  uVar20 = _objc_retainAutoreleasedReturnValue();
  local_e8 = uVar20;
  _objc_msgSend(uVar16,puVar3);
  uVar21 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar17,puVar3);
  uVar22 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar21,puVar2,uVar22);
  uVar23 = _objc_retainAutoreleasedReturnValue();
  puVar9 = @selector(widthAnchor);
  local_e0 = uVar23;
  _objc_msgSend(uVar14,@selector(widthAnchor));
  uVar24 = _objc_retainAutoreleasedReturnValue();
  puVar8 = @selector(constraintEqualToConstant:);
  _objc_msgSend(0x4049000000000000,uVar24,@selector(constraintEqualToConstant:));
  uVar25 = _objc_retainAutoreleasedReturnValue();
  puVar7 = @selector(heightAnchor);
  local_d8 = uVar25;
  _objc_msgSend(uVar14,@selector(heightAnchor));
  uVar26 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4049000000000000,uVar26,puVar8);
  uVar27 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(leadingAnchor);
  local_d0 = uVar27;
  _objc_msgSend(uVar13,@selector(leadingAnchor));
  uVar28 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar17,puVar3);
  uVar29 = _objc_retainAutoreleasedReturnValue();
  puVar6 = @selector(constraintEqualToAnchor:constant:);
  _objc_msgSend(0x4014000000000000,uVar28,@selector(constraintEqualToAnchor:constant:),uVar29);
  uVar30 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(trailingAnchor);
  local_c8 = uVar30;
  _objc_msgSend(uVar13,@selector(trailingAnchor));
  uVar31 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar17,puVar3);
  uVar32 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0xc014000000000000,uVar31,puVar6,uVar32);
  uVar33 = _objc_retainAutoreleasedReturnValue();
  local_c0 = uVar33;
  _objc_msgSend(uVar17,puVar5);
  uVar34 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar35 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar35,puVar5);
  uVar36 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar34,puVar2,uVar36);
  uVar37 = _objc_retainAutoreleasedReturnValue();
  local_b8 = uVar37;
  uStack_b0 = uVar19;
  _objc_msgSend(uVar17,puVar9);
  uVar38 = _objc_retainAutoreleasedReturnValue();
  uVar11 = DAT_00c4c298;
  _objc_msgSend(DAT_00c4c298,uVar38,puVar8);
  uVar39 = _objc_retainAutoreleasedReturnValue();
  local_a8 = uVar39;
  _objc_msgSend(uVar17,puVar7);
  uVar40 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,uVar40,puVar8);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  local_a0 = uVar11;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar4,&local_e8,10);
  uVar41 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar10,@selector(activateConstraints:),uVar41);
  _objc_release(uVar41);
  _objc_release(uVar11);
  _objc_release(uVar40);
  _objc_release(uVar39);
  _objc_release(uVar38);
  _objc_release(uVar37);
  _objc_release(uVar36);
  _objc_release(uVar35);
  _objc_release(uVar34);
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
  _objc_release(uVar18);
  _objc_release(uVar15);
  _objc_msgSend(0,uVar17,@selector(setAlpha:));
  _CGAffineTransformMakeScale(&local_118,DAT_00c4c2a0,DAT_00c4c2a0);
  uStack_148 = uStack_110;
  local_150 = local_118;
  uStack_138 = uStack_100;
  uStack_140 = uStack_108;
  uStack_128 = uStack_f0;
  local_130 = local_f8;
  _objc_msgSend(uVar17,@selector(setTransform:),&local_150);
  _objc_msgSend(uVar12,@selector(impactOccurred));
  puVar3 = PTR__OBJC_CLASS___UIView_0114ec30;
  puVar1 = PTR___NSConcreteStackBlock_01060660;
  uVar11 = DAT_00c4c228;
  local_178 = PTR___NSConcreteStackBlock_01060660;
  local_170 = DAT_00c4c228;
  local_168 = FUN_00043ea0;
  puStack_160 = &DAT_01061420;
  _objc_retain(uVar17);
  puVar2 = @selector(animateWithDuration:delay:usingSpringWithDamping:initialSpringVelocity:options:animations:completion:);
  local_1b0 = puVar1;
  local_1a8 = uVar11;
  local_1a0 = FUN_00043f1c;
  puStack_198 = &DAT_01061970;
  local_190 = uVar17;
  local_188 = uVar19;
  local_180 = param_1;
  local_158 = uVar17;
  _objc_retain(uVar19);
  _objc_retain(uVar17);
  _objc_msgSend(0x3fe0000000000000,0,0x3ff0000000000000,0x402e000000000000,puVar3,puVar2,0,
                &local_178,&local_1b0);
  _objc_release(local_188);
  _objc_release(local_190);
  _objc_release(local_158);
  _objc_release(uVar19);
  _objc_release(uVar17);
  _objc_release(uVar16);
  _objc_release(uVar13);
  _objc_release(uVar14);
  _objc_release(uVar12);
  CallSupervisor(0xc0e1);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_88) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}



// -[WelcomeVC cellImageWithName:], 0x441a8
/* Decompiled from supplied 5.2.2 arm package. VA 0x441a8. cellImageWithName: */

/* Function Stack Size: 0x18 bytes */

ID WelcomeVC::cellImageWithName_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  undefined *local_58;
  undefined8 local_50;
  code *local_48;
  undefined *puStack_40;
  ID local_38;
  
  _objc_retain(param_3);
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIGraphicsImageRenderer_0114ec88);
  uVar2 = _objc_msgSend(0x4044000000000000,0x4044000000000000,uVar2,@selector(initWithSize:));
  puVar1 = @selector(imageWithActions:);
  local_58 = PTR___NSConcreteGlobalBlock_01060658;
  local_50 = DAT_00c4c2a8;
  local_48 = FUN_0004427c;
  puStack_40 = &DAT_010619a0;
  local_38 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,&local_58);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(local_38);
  _objc_release(param_3);
  _objc_release(uVar2);
  IVar4 = _objc_autoreleaseReturnValue(uVar3);
  return IVar4;
}



// -[WelcomeVC .cxx_destruct], 0x44448
/* Decompiled from supplied 5.2.2 arm package. VA 0x44448. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void WelcomeVC::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_settingsData,0);
  _objc_storeStrong(param_1 + (long)_tableView,0);
  return;
}


