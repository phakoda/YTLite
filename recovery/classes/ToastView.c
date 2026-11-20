// Decompiled implementation evidence for ToastView. Not compilable source.

// -[ToastView init], 0x1ba6d8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ba6d8. init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x10 bytes */

ID ToastView::init(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 *puVar4;
  byte bVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  ID IVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  protocol_list_t_1_ *ppVar12;
  long lVar13;
  long lVar14;
  ID IVar15;
  undefined *puVar16;
  undefined *puVar17;
  long lVar18;
  long lVar19;
  undefined8 auStack_1d0 [2];
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  ID IStack_160;
  undefined *puStack_158;
  undefined *puStack_150;
  undefined *puStack_148;
  long lStack_140;
  long lStack_138;
  long lStack_130;
  long lStack_128;
  undefined8 uStack_120;
  undefined *puStack_118;
  undefined *puStack_110;
  undefined8 *puStack_108;
  ID IStack_100;
  undefined **local_f8;
  uint uStack_ec;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **ppuStack_c8;
  uint uStack_bc;
  undefined **local_b8;
  undefined **ppuStack_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  puVar1 = @selector(currentDevice);
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_011b3f18;
  local_8c = (uint)(DAT_01227ae8 == 0);
  local_a0 = &PTR_LAB_011b3f38;
  local_98 = &PTR_LAB_011b39f0;
  local_b8 = &PTR_LAB_011b3f58;
  ppuStack_b0 = &PTR_LAB_011b39f0;
  local_d0 = &PTR_LAB_011b3f78;
  ppuStack_c8 = &PTR_LAB_011b39f0;
  local_e8 = &PTR_LAB_011b3f98;
  ppuStack_e0 = &PTR_LAB_011b39f0;
  local_f8 = &PTR_LAB_011b39f0;
  DAT_01227ae8 = 1;
  puStack_108 = auStack_1d0;
  IStack_100 = param_1;
  _objc_msgSend(PTR__OBJC_CLASS___UIDevice_0114eb58,@selector(currentDevice));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  lVar7 = _objc_msgSend(uVar6,@selector(userInterfaceIdiom));
  uStack_a4 = (uint)(lVar7 == 1);
  if (lVar7 == 1) {
    ppVar12 = &objc::protocol_list_t::CustomHUD;
    puVar16 = @selector(containsString:);
    puVar17 = @selector(model);
  }
  else {
    _objc_msgSend(local_a0[uStack_a4] + (int)-(DAT_011b3f48 ^ 0xa95e00fb),
                  PTR__OBJC_CLASS___UIDevice_0114eb58,puVar1);
    puStack_110 = (undefined *)_objc_retainAutoreleasedReturnValue();
    puVar17 = @selector(model);
    _objc_msgSend(puStack_110,@selector(model));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    puVar16 = @selector(containsString:);
    uStack_bc = FUN_001c488c(uVar8,@selector(containsString:),
                             @"iPad");
    IStack_160 = IStack_100;
    ppVar12 = (protocol_list_t_1_ *)
              (local_b8[uStack_bc] + (int)-(uRam00000000011b3f68 ^ 0x846ad4e9));
    if (uStack_bc == 0) {
      *(undefined1 *)(IStack_100 + (long)_isiPad) = 0;
      _objc_release(uVar8);
      _objc_release(puStack_110);
      _objc_release(uVar6);
      _objc_msgSend(PTR__OBJC_CLASS___UIBlurEffect_0114ebe0,@selector(effectWithStyle:),2);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      puStack_158 = PTR_ToastView_0114f0e8;
      IVar9 = _objc_msgSendSuper2(&IStack_160,@selector(initWithEffect:),uVar6);
      _objc_release(uVar6);
      puVar1 = @selector(setAlpha:);
      uStack_ec = (uint)(IVar9 == 0);
      if (IVar9 != 0) {
        _objc_msgSend(0,IVar9,@selector(setAlpha:));
        _CGAffineTransformMakeScale(&uStack_190,DAT_00c4c2a0,DAT_00c4c2a0);
        uStack_1b8 = uStack_188;
        uStack_1c0 = uStack_190;
        uStack_1a8 = uStack_178;
        uStack_1b0 = uStack_180;
        uStack_198 = uStack_168;
        uStack_1a0 = uStack_170;
        _objc_msgSend(IVar9,@selector(setTransform:),&uStack_1c0);
        puVar3 = @selector(setTranslatesAutoresizingMaskIntoConstraints:);
        _objc_msgSend(IVar9,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
        puVar16 = @selector(layer);
        _objc_msgSend(IVar9,@selector(layer));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(_UNK_00c4c3b0,uVar6,@selector(setCornerRadius:));
        _objc_release(uVar6);
        puVar17 = @selector(whiteColor);
        _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(whiteColor));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        puVar2 = @selector(colorWithAlphaComponent:);
        _objc_msgSend(DAT_00c4c2f0,uVar6,@selector(colorWithAlphaComponent:));
        uVar8 = _objc_retainAutoreleasedReturnValue();
        uVar10 = _objc_retainAutorelease();
        uVar10 = _objc_msgSend(uVar10,@selector(CGColor));
        _objc_msgSend(IVar9,puVar16);
        uVar11 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar11,@selector(setBorderColor:),uVar10);
        _objc_release(uVar11);
        _objc_release(uVar8);
        _objc_release(uVar6);
        _objc_msgSend(IVar9,puVar16);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(0x3ff0000000000000,uVar6,@selector(setBorderWidth:));
        _objc_release(uVar6);
        uVar8 = *(undefined8 *)PTR__kCACornerCurveContinuous_01060bb0;
        _objc_msgSend(IVar9,puVar16);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,@selector(setCornerCurve:),uVar8);
        _objc_release(uVar6);
        _objc_msgSend(IVar9,@selector(setClipsToBounds:),1);
        _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,@selector(delegate));
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,@selector(window));
        uVar10 = _objc_retainAutoreleasedReturnValue();
        uVar11 = *(undefined8 *)(IVar9 + (long)_ytSourceView);
        *(undefined8 *)(IVar9 + (long)_ytSourceView) = uVar10;
        _objc_release(uVar11);
        _objc_release(uVar8);
        _objc_release(uVar6);
        _objc_msgSend(DAT_01227ac8,@selector(rootViewController));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,@selector(view));
        uVar8 = _objc_retainAutoreleasedReturnValue();
        uVar10 = *(undefined8 *)(IVar9 + (long)_sourceView);
        *(undefined8 *)(IVar9 + (long)_sourceView) = uVar8;
        _objc_release(uVar10);
        _objc_release(uVar6);
        _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        uVar8 = *(undefined8 *)(IVar9 + (long)_commandQueue);
        *(undefined8 *)(IVar9 + (long)_commandQueue) = uVar6;
        _objc_release(uVar8);
        *(undefined1 *)(IVar9 + (long)_isAnimating) = 0;
        uVar6 = _objc_alloc_init(PTR__OBJC_CLASS___UILabel_0114ec00);
        lVar18 = (long)_toastLabel;
        uVar8 = *(undefined8 *)(IVar9 + lVar18);
        *(undefined8 *)(IVar9 + lVar18) = uVar6;
        _objc_release(uVar8);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar18),@selector(setNumberOfLines:),0);
        _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar17);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar18),@selector(setTextColor:),uVar6);
        _objc_release(uVar6);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar18),@selector(setTextAlignment:),1);
        _objc_msgSend(0x402e000000000000,*(undefined8 *)PTR__UIFontWeightBold_01060560,
                      PTR__OBJC_CLASS___UIFont_0114ec08,
                      @selector(monospacedDigitSystemFontOfSize:weight:));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar18),@selector(setFont:),uVar6);
        _objc_release(uVar6);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar18),puVar3,0);
        _objc_msgSend(0x447a0000,*(undefined8 *)(IVar9 + lVar18),
                      @selector(setContentHuggingPriority:forAxis:),1);
        lStack_140 = lVar18;
        _objc_msgSend(0x447a0000,*(undefined8 *)(IVar9 + lVar18),
                      @selector(setContentCompressionResistancePriority:forAxis:),1);
        uVar6 = _objc_alloc(PTR__OBJC_CLASS___UIProgressView_0114ef58);
        uVar6 = _objc_msgSend(uVar6,@selector(initWithProgressViewStyle:),1);
        lVar19 = (long)_toastProgress;
        uVar8 = *(undefined8 *)(IVar9 + lVar19);
        *(undefined8 *)(IVar9 + lVar19) = uVar6;
        _objc_release(uVar8);
        _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(blackColor));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(DAT_00c4c2e0,uVar6,puVar2);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar19),@selector(setProgressTintColor:),uVar8);
        _objc_release(uVar8);
        _objc_release(uVar6);
        _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(clearColor));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar19),@selector(setTrackTintColor:),uVar6);
        _objc_release(uVar6);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar19),puVar3,0);
        uVar6 = _objc_alloc_init(PTR__OBJC_CLASS___UIImageView_0114ebf0);
        lVar7 = (long)_toastIcon;
        uVar8 = *(undefined8 *)(IVar9 + lVar7);
        *(undefined8 *)(IVar9 + lVar7) = uVar6;
        _objc_release(uVar8);
        _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar17);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        puVar16 = @selector(setTintColor:);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar7),@selector(setTintColor:),uVar6);
        _objc_release(uVar6);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar7),puVar3,0);
        lStack_138 = lVar7;
        _objc_msgSend(0,*(undefined8 *)(IVar9 + lVar7),puVar1);
        _objc_msgSend(PTR__OBJC_CLASS___UIButton_0114ec38,@selector(buttonWithType:),0);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        lVar13 = (long)_toastButton;
        uVar8 = *(undefined8 *)(IVar9 + lVar13);
        *(undefined8 *)(IVar9 + lVar13) = uVar6;
        _objc_release(uVar8);
        _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar17);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar13),puVar16,uVar6);
        _objc_release(uVar6);
        uVar8 = *(undefined8 *)(IVar9 + lVar13);
        _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,@selector(systemImageNamed:),
                      @"stop.circle");
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,@selector(setImage:forState:),uVar6,0);
        _objc_release(uVar6);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar13),
                      @selector(addTarget:action:forControlEvents:),IVar9,
                      @selector(cancelButtonTapped),0x40);
        uVar6 = _objc_alloc(PTR__OBJC_CLASS___UILongPressGestureRecognizer_0114ed30);
        uVar6 = _objc_msgSend(uVar6,@selector(initWithTarget:action:),IVar9,
                              @selector(handleLongPress:));
        uStack_120 = uVar6;
        _objc_msgSend(0x4008000000000000,uVar6,@selector(setMinimumPressDuration:));
        lStack_130 = lVar13;
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar13),@selector(addGestureRecognizer:),uVar6);
        uVar6 = _objc_alloc(PTR__OBJC_CLASS___UIActivityIndicatorView_0114eb20);
        uVar6 = _objc_msgSend(uVar6,@selector(initWithActivityIndicatorStyle:),100);
        lVar14 = (long)_activityIndicator;
        uVar8 = *(undefined8 *)(IVar9 + lVar14);
        *(undefined8 *)(IVar9 + lVar14) = uVar6;
        _objc_release(uVar8);
        _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar17);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        lStack_128 = lVar14;
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar14),@selector(setColor:),uVar6);
        _objc_release(uVar6);
        uVar6 = _objc_alloc(PTR__OBJC_CLASS___UIStackView_0114ec10);
        puVar4 = puStack_108;
        *puStack_108 = *(undefined8 *)(IVar9 + lVar13);
        puVar4[1] = *(undefined8 *)(IVar9 + lVar14);
        _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                      puVar4,2);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        uVar6 = _objc_msgSend(uVar6,@selector(initWithArrangedSubviews:),uVar8);
        IVar15 = (ID)_actionsStack;
        uVar10 = *(undefined8 *)(IVar9 + IVar15);
        *(undefined8 *)(IVar9 + IVar15) = uVar6;
        _objc_release(uVar10);
        _objc_release(uVar8);
        _objc_msgSend(*(undefined8 *)(IVar9 + IVar15),@selector(setAxis:),0);
        _objc_msgSend(*(undefined8 *)(IVar9 + IVar15),@selector(setDistribution:),0);
        _objc_msgSend(*(undefined8 *)(IVar9 + IVar15),@selector(setAlignment:),3);
        _objc_msgSend(0x4024000000000000,*(undefined8 *)(IVar9 + IVar15),@selector(setSpacing:))
        ;
        IStack_100 = IVar15;
        _objc_msgSend(*(undefined8 *)(IVar9 + IVar15),puVar3,0);
        puVar3 = @selector(contentView);
        _objc_msgSend(IVar9,@selector(contentView));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        puVar1 = @selector(addSubview:);
        _objc_msgSend(uVar6,@selector(addSubview:),*(undefined8 *)(IVar9 + lVar19));
        _objc_release(uVar6);
        _objc_msgSend(IVar9,puVar3);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,puVar1,*(undefined8 *)(IVar9 + lVar18));
        _objc_release(uVar6);
        _objc_msgSend(IVar9,puVar3);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,puVar1,*(undefined8 *)(IVar9 + lVar7));
        _objc_release(uVar6);
        _objc_msgSend(IVar9,puVar3);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,puVar1,*(undefined8 *)(IVar9 + IVar15));
        _objc_release(uVar6);
        puVar1 = @selector(leadingAnchor);
        puStack_110 = @selector(leadingAnchor);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar19),@selector(leadingAnchor));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(IVar9,puVar3);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar1);
        uVar10 = _objc_retainAutoreleasedReturnValue();
        puVar16 = @selector(constraintEqualToAnchor:);
        _objc_msgSend(uVar6,@selector(constraintEqualToAnchor:),uVar10);
        uVar11 = _objc_retainAutoreleasedReturnValue();
        puVar17 = @selector(setActive:);
        _objc_msgSend(uVar11,@selector(setActive:),1);
        _objc_release(uVar11);
        _objc_release(uVar10);
        _objc_release(uVar8);
        _objc_release(uVar6);
        puVar1 = @selector(trailingAnchor);
        puStack_118 = @selector(trailingAnchor);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar19),@selector(trailingAnchor));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(IVar9,puVar3);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar1);
        uVar10 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,puVar16,uVar10);
        uVar11 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar11,puVar17,1);
        _objc_release(uVar11);
        _objc_release(uVar10);
        _objc_release(uVar8);
        _objc_release(uVar6);
        puVar2 = @selector(bottomAnchor);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar19),@selector(bottomAnchor));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(IVar9,puVar3);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar2);
        uVar10 = _objc_retainAutoreleasedReturnValue();
        puStack_108 = (undefined8 *)puVar16;
        _objc_msgSend(uVar6,puVar16,uVar10);
        uVar11 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar11,puVar17,1);
        _objc_release(uVar11);
        _objc_release(uVar10);
        _objc_release(uVar8);
        _objc_release(uVar6);
        puVar1 = @selector(topAnchor);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar19),@selector(topAnchor));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(IVar9,puVar3);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar1);
        uVar10 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,puVar16,uVar10);
        uVar11 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar11,puVar17,1);
        _objc_release(uVar11);
        _objc_release(uVar10);
        _objc_release(uVar8);
        _objc_release(uVar6);
        lVar7 = lStack_140;
        _objc_msgSend(*(undefined8 *)(IVar9 + lStack_140),puVar1);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        puStack_150 = puVar3;
        _objc_msgSend(IVar9,puVar3);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar1);
        uVar10 = _objc_retainAutoreleasedReturnValue();
        puVar1 = @selector(constraintEqualToAnchor:constant:);
        _objc_msgSend(0x4014000000000000,uVar6,@selector(constraintEqualToAnchor:constant:),
                      uVar10);
        uVar11 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar11,puVar17,1);
        _objc_release(uVar11);
        _objc_release(uVar10);
        _objc_release(uVar8);
        _objc_release(uVar6);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar7),puVar2);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(IVar9,puVar3);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar2);
        uVar10 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(0xc014000000000000,uVar6,puVar1,uVar10);
        uVar11 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar11,puVar17,1);
        _objc_release(uVar11);
        _objc_release(uVar10);
        _objc_release(uVar8);
        _objc_release(uVar6);
        puVar2 = puStack_110;
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar7),puStack_110);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        puVar16 = puStack_118;
        lVar13 = lStack_138;
        _objc_msgSend(*(undefined8 *)(IVar9 + lStack_138),puStack_118);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(0x4014000000000000,uVar6,puVar1,uVar8);
        uVar10 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar10,puVar17,1);
        _objc_release(uVar10);
        _objc_release(uVar8);
        _objc_release(uVar6);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar7),puVar16);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(*(undefined8 *)(IVar9 + IStack_100),puVar2);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        puStack_148 = puVar1;
        _objc_msgSend(0xc014000000000000,uVar6,puVar1,uVar8);
        uVar10 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar10,puVar17,1);
        _objc_release(uVar10);
        _objc_release(uVar8);
        _objc_release(uVar6);
        puVar2 = @selector(centerYAnchor);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar13),@selector(centerYAnchor));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        puVar3 = puStack_150;
        _objc_msgSend(IVar9,puStack_150);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar2);
        uVar10 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,puStack_108,uVar10);
        uVar11 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar11,puVar17,1);
        _objc_release(uVar11);
        _objc_release(uVar10);
        _objc_release(uVar8);
        _objc_release(uVar6);
        puVar16 = puStack_110;
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar13),puStack_110);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(IVar9,puVar3);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar16);
        uVar10 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(0x4024000000000000,uVar6,puVar1,uVar10);
        uVar11 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar11,puVar17,1);
        _objc_release(uVar11);
        _objc_release(uVar10);
        _objc_release(uVar8);
        _objc_release(uVar6);
        puStack_110 = @selector(heightAnchor);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar13));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        puVar1 = @selector(constraintEqualToConstant:);
        _objc_msgSend(0x4038000000000000,uVar6,@selector(constraintEqualToConstant:));
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar17,1);
        _objc_release(uVar8);
        _objc_release(uVar6);
        puVar16 = @selector(widthAnchor);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar13),@selector(widthAnchor));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(0x4038000000000000,uVar6,puVar1);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar17,1);
        _objc_release(uVar8);
        _objc_release(uVar6);
        IVar15 = IStack_100;
        _objc_msgSend(*(undefined8 *)(IVar9 + IStack_100),puVar2);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(IVar9,puVar3);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar2);
        uVar10 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,puStack_108,uVar10);
        uVar11 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar11,puVar17,1);
        _objc_release(uVar11);
        _objc_release(uVar10);
        _objc_release(uVar8);
        _objc_release(uVar6);
        puVar2 = puStack_118;
        _objc_msgSend(*(undefined8 *)(IVar9 + IVar15),puStack_118);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(IVar9,puVar3);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar2);
        uVar10 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(0xc024000000000000,uVar6,puStack_148,uVar10);
        uVar11 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar11,puVar17,1);
        _objc_release(uVar11);
        _objc_release(uVar10);
        _objc_release(uVar8);
        _objc_release(uVar6);
        puVar2 = puStack_110;
        lVar7 = lStack_130;
        _objc_msgSend(*(undefined8 *)(IVar9 + lStack_130),puStack_110);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(0x4038000000000000,uVar6,puVar1);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar17,1);
        _objc_release(uVar8);
        _objc_release(uVar6);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar7),puVar16);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(0x4038000000000000,uVar6,puVar1);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar17,1);
        _objc_release(uVar8);
        _objc_release(uVar6);
        lVar7 = lStack_128;
        _objc_msgSend(*(undefined8 *)(IVar9 + lStack_128),puVar2);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(0x403e000000000000,uVar6,puVar1);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar17,1);
        _objc_release(uVar8);
        _objc_release(uVar6);
        _objc_msgSend(*(undefined8 *)(IVar9 + lVar7),puVar16);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(0x403e000000000000,uVar6,puVar1);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar17,1);
        _objc_release(uVar8);
        _objc_release(uVar6);
        _objc_release(uStack_120);
      }
      if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
        ___stack_chk_fail();
      }
      return IVar9;
    }
  }
  _objc_msgSend(ppVar12,PTR__OBJC_CLASS___UIDevice_0114eb58,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,puVar17);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  bVar5 = FUN_001c48f4(uVar8,puVar16,@"iPhone");
  *(byte *)(IStack_100 + (long)_isiPad) = bVar5 ^ 1;
  _objc_release(uVar8);
  _objc_release(uVar6);
  uStack_d4 = (uint)(lVar7 == 1);
                    /* WARNING: Could not recover jumptable at 0x001baaf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar9 = (*(code *)(local_d0[uStack_d4] + (int)-(uRam00000000011b3f88 ^ 0xe86eb408)))();
  return IVar9;
}



// -[ToastView enqueueCommand:], 0x1bbd94
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bbd94. enqueueCommand: */

/* Function Stack Size: 0x18 bytes */

void ToastView::enqueueCommand_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar3 = *(undefined8 *)(param_1 + (long)_commandQueue);
  uVar1 = _objc_msgSend(param_3,@selector(copy),param_3,param_4);
  uVar2 = _objc_retainBlock();
  _objc_msgSend(uVar3,@selector(addObject:),uVar2);
  _objc_release(uVar2);
  _objc_release(uVar1);
  _objc_msgSend(param_1,@selector(processQueue));
  CallSupervisor(0x567c);
  return;
}



// -[ToastView processQueue], 0x1bbe2c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bbe2c. processQueue */

/* Function Stack Size: 0x10 bytes */

void ToastView::processQueue(ID param_1,SEL param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = (long)_isAnimating;
  if (*(char *)(param_1 + lVar2) == '\0') {
    lVar3 = (long)_commandQueue;
    lVar1 = _objc_msgSend(*(undefined8 *)(param_1 + lVar3),@selector(count));
    if (lVar1 != 0) {
      *(undefined1 *)(param_1 + lVar2) = 1;
      _objc_msgSend(*(undefined8 *)(param_1 + lVar3),@selector(firstObject));
      lVar2 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(*(undefined8 *)(param_1 + lVar3),@selector(removeObjectAtIndex:),0);
      (**(code **)(lVar2 + 0x10))(lVar2);
      _objc_release(lVar2);
    }
  }
  CallSupervisor(0x97bc);
  return;
}



// -[ToastView setupInterfaceWithText:progress:withStop:isStatus:isSuccess:withWait:], 0x1bbf68
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bbf68. setupInterfaceWithText:progress:withStop:isStatus:isSuccess:withWait: */

/* Function Stack Size: 0x2c bytes */

void ToastView::setupInterfaceWithText_progress_withStop_isStatus_isSuccess_withWait_
               (ID param_1,SEL param_2,ID param_3,float param_4,bool param_5,bool param_6,
               bool param_7,bool param_8)

{
  undefined **ppuVar1;
  char cVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  bool bVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  double dVar18;
  double dVar19;
  double in_d2;
  undefined8 auStack_170 [2];
  undefined8 auStack_160 [2];
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined1 auStack_130 [16];
  undefined8 auStack_120 [2];
  undefined1 auStack_110 [16];
  undefined8 *puStack_100;
  undefined8 *puStack_f8;
  bool local_f0;
  bool bStack_ec;
  undefined1 *puStack_e8;
  bool local_dc;
  undefined8 *puStack_d8;
  undefined **local_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **local_b8;
  undefined **ppuStack_b0;
  int iStack_a4;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  puVar4 = PTR_ToastManager_0114ecd0;
  puVar3 = @selector(sharedManager);
  puStack_e8 = (undefined1 *)&puStack_100;
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_011b3ff0;
  local_8c = (uint)(DAT_01227af4 == 0);
  local_a0 = &PTR_LAB_011b4010;
  ppuStack_98 = &PTR_LAB_011b39f0;
  local_b8 = &PTR_LAB_011b39f0;
  ppuStack_b0 = &PTR_LAB_011b39f0;
  local_c0 = &PTR_LAB_011b4038;
  local_d0 = &PTR_LAB_011b39f0;
  DAT_01227af4 = 1;
  puStack_d8 = &uStack_150;
  puStack_f8 = auStack_160;
  puStack_100 = auStack_170;
  local_f0 = param_6;
  bStack_ec = param_5;
  local_dc = param_7;
  _objc_retain(param_3);
  _objc_msgSend(puVar4,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,@selector(registerToast:),param_1);
  _objc_release(uVar8);
  _objc_msgSend(param_4,*(undefined8 *)(param_1 + (long)_toastProgress),
                @selector(setProgress:animated:),0);
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastLabel),@selector(setText:),param_3);
  _objc_release(param_3);
  puVar3 = @selector(setAlpha:);
  uVar8 = 0x3ff0000000000000;
  if (local_f0 == 0) {
    uVar8 = 0;
  }
  lVar14 = (long)_toastIcon;
  _objc_msgSend(uVar8,*(undefined8 *)(param_1 + lVar14),@selector(setAlpha:));
  uVar8 = 0x3ff0000000000000;
  if (bStack_ec == 0) {
    uVar8 = 0;
  }
  lVar16 = (long)_toastButton;
  _objc_msgSend(uVar8,*(undefined8 *)(param_1 + lVar16),puVar3);
  puVar3 = @selector(setHidden:);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar16),@selector(setHidden:),param_8);
  lVar16 = (long)_activityIndicator;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar16),puVar3,param_8 ^ 1);
  ppuVar1 = @"checkmark.circle";
  if (local_dc == 0) {
    ppuVar1 = @"xmark.circle";
  }
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,@selector(systemImageNamed:),ppuVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(setImage:),uVar8);
  _objc_release(uVar8);
  ppuVar1 = &@selector(startAnimating);
  if (param_8 == 0) {
    ppuVar1 = &@selector(stopAnimating);
  }
  _objc_msgSend(*(undefined8 *)(param_1 + lVar16),*ppuVar1);
  lVar14 = (long)_sourceView;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(addSubview:),param_1);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(bringSubviewToFront:),param_1);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(frame));
  cVar2 = *(char *)(param_1 + (long)_isiPad);
  iVar7 = FUN_001c4c7c(param_1,@selector(isLandscape));
  dVar18 = DAT_00c4c2e0;
  if (iVar7 == 0) {
    dVar18 = 0.5;
  }
  dVar19 = 0.5;
  if (iVar7 == 0) {
    dVar19 = DAT_00c4c3b8;
  }
  if (cVar2 != '\0') {
    dVar19 = dVar18;
  }
  _objc_msgSend(0,param_1,@selector(calculateToastParametersWithKeyboardHeight:bottomOffset:topOffset:scale:),auStack_110,auStack_120,
                auStack_130);
  puVar3 = @selector(topAnchor);
  _objc_msgSend(param_1,@selector(topAnchor));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),puVar3);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar4 = @selector(constraintEqualToAnchor:constant:);
  _objc_msgSend(auStack_120[0],uVar8,@selector(constraintEqualToAnchor:constant:),uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  lVar16 = (long)_topConstraint;
  uVar12 = *(undefined8 *)(param_1 + lVar16);
  *(undefined8 *)(param_1 + lVar16) = uVar10;
  _objc_release(uVar12);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar3 = @selector(bottomAnchor);
  _objc_msgSend(param_1,@selector(bottomAnchor));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),puVar3);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(-*(double *)(puStack_e8 + -0x10),uVar8,puVar4,uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  lVar17 = (long)_bottomConstraint;
  uVar12 = *(undefined8 *)(param_1 + lVar17);
  *(undefined8 *)(param_1 + lVar17) = uVar10;
  _objc_release(uVar12);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar3 = @selector(centerXAnchor);
  _objc_msgSend(param_1,@selector(centerXAnchor));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),puVar3);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,@selector(constraintEqualToAnchor:),uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  lVar13 = (long)_centerXConstraint;
  uVar12 = *(undefined8 *)(param_1 + lVar13);
  *(undefined8 *)(param_1 + lVar13) = uVar10;
  _objc_release(uVar12);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_msgSend(param_1,@selector(widthAnchor));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(in_d2 * dVar19,uVar8,@selector(constraintEqualToConstant:));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  lVar14 = (long)_widthConstraint;
  uVar10 = *(undefined8 *)(param_1 + lVar14);
  *(undefined8 *)(param_1 + lVar14) = uVar9;
  _objc_release(uVar10);
  _objc_release(uVar8);
  _objc_msgSend(param_1,@selector(heightAnchor));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(DAT_00c4c358,uVar8,@selector(constraintGreaterThanOrEqualToConstant:));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  lVar15 = (long)_heightConstraint;
  uVar10 = *(undefined8 *)(param_1 + lVar15);
  *(undefined8 *)(param_1 + lVar15) = uVar9;
  _objc_release(uVar10);
  _objc_release(uVar8);
  puVar5 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  puVar3 = @selector(arrayWithObjects:count:);
  uStack_150 = *(undefined8 *)(param_1 + lVar13);
  uStack_148 = *(undefined8 *)(param_1 + lVar14);
  uStack_140 = *(undefined8 *)(param_1 + lVar15);
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),puStack_d8
                ,3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar4 = @selector(activateConstraints:);
  _objc_msgSend(puVar5,@selector(activateConstraints:),uVar8);
  _objc_release(uVar8);
  iStack_a4 = FUN_001c4ea4(param_1,@selector(isPinnedTop));
  puVar5 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  if (iStack_a4 == 0) {
    uVar8 = *(undefined8 *)(param_1 + lVar17);
    puVar11 = puStack_100;
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + lVar16);
    puVar11 = puStack_f8;
  }
  *puVar11 = uVar8;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar3,puVar11,1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar5,puVar4,uVar8);
  _objc_release(uVar8);
  uVar8 = _objc_alloc(PTR__OBJC_CLASS___UITapGestureRecognizer_0114ed98);
  puVar3 = @selector(initWithTarget:action:);
  uVar8 = _objc_msgSend(uVar8,@selector(initWithTarget:action:),param_1,@selector(handleTap)
                       );
  puVar4 = @selector(addGestureRecognizer:);
  _objc_msgSend(param_1,@selector(addGestureRecognizer:),uVar8);
  bVar6 = *(char *)(param_1 + (long)_ignoresPanGesture) == '\0';
  uStack_c4 = (uint)bVar6;
  if (bVar6) {
    uVar9 = _objc_alloc(PTR__OBJC_CLASS___UIPanGestureRecognizer_0114ed90);
    uVar9 = _objc_msgSend(uVar9,puVar3,param_1,@selector(handlePanGesture:));
    _objc_msgSend(param_1,puVar4,uVar9);
    _objc_release(uVar9);
  }
  _objc_msgSend(param_1,@selector(setupObservers));
  _objc_release(uVar8);
  CallSupervisor(0xdc6c);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}



// -[ToastView handlePanGesture:], 0x1bc8e4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bc8e4. handlePanGesture: */

/* Function Stack Size: 0x18 bytes */

void ToastView::handlePanGesture_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined8 uVar13;
  double dVar14;
  double in_d1;
  double dVar15;
  undefined1 auStack_3c0 [128];
  undefined1 auStack_340 [128];
  undefined1 auStack_2c0 [128];
  undefined8 uStack_240;
  undefined8 uStack_238;
  undefined8 uStack_230;
  undefined8 uStack_228;
  undefined8 uStack_220;
  undefined8 uStack_218;
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined *puStack_1b8;
  undefined *puStack_1b0;
  undefined8 uStack_1a8;
  undefined *puStack_1a0;
  undefined *puStack_198;
  undefined *puStack_190;
  undefined *puStack_188;
  undefined *puStack_180;
  undefined1 *puStack_178;
  ID IStack_170;
  undefined1 *puStack_168;
  ID IStack_160;
  undefined **local_158;
  undefined **local_150;
  undefined **local_148;
  undefined **local_138;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  uint uStack_114;
  undefined **local_110;
  uint uStack_104;
  undefined **local_100;
  undefined **ppuStack_f8;
  undefined **local_f0;
  undefined **ppuStack_e8;
  uint uStack_dc;
  undefined **local_d8;
  uint uStack_cc;
  undefined **local_c8;
  undefined **local_c0;
  undefined **ppuStack_b8;
  int iStack_ac;
  undefined **local_a8;
  undefined **local_a0;
  uint local_94;
  undefined **local_90;
  
  local_90 = &PTR_LAB_011b4058;
  local_94 = (uint)(DAT_01227af8 == 0);
  local_a8 = &PTR_LAB_011b4078;
  local_a0 = &PTR_LAB_011b39f0;
  local_c0 = &PTR_LAB_011b39f0;
  ppuStack_b8 = &PTR_LAB_011b39f0;
  local_c8 = &PTR_LAB_011b40a0;
  local_d8 = &PTR_LAB_011b40b8;
  local_f0 = &PTR_LAB_011b39f0;
  ppuStack_e8 = &PTR_LAB_011b39f0;
  local_100 = &PTR_LAB_011b40e8;
  ppuStack_f8 = &PTR_LAB_011b39f0;
  local_110 = &PTR_LAB_011b4100;
  local_120 = &PTR_LAB_011b4118;
  local_130 = &PTR_LAB_011b39f0;
  local_138 = &PTR_LAB_011b4138;
  local_148 = &PTR_LAB_011b39f0;
  local_150 = &PTR_LAB_011b39f0;
  local_158 = &PTR_LAB_011b39f0;
  DAT_01227af8 = 1;
  puStack_168 = auStack_340;
  _objc_retain(param_3);
  _objc_msgSend(param_1,@selector(superview));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,@selector(translationInView:),uVar3);
  _objc_release(uVar3);
  iStack_ac = FUN_001c534c(param_1,@selector(isPinnedTop));
  puVar12 = @selector(state);
  if (iStack_ac == 0) {
    dVar14 = 0.0;
    if (in_d1 <= 0.0) {
      dVar14 = in_d1;
    }
    dVar15 = -80.0;
    if (-80.0 <= dVar14) {
      dVar15 = dVar14;
    }
  }
  else {
    dVar15 = (double)NEON_fminnm(in_d1,0x4054000000000000);
  }
  lVar4 = _objc_msgSend(param_3,@selector(state));
  puVar11 = @selector(layer);
  uStack_cc = (uint)(lVar4 == 2);
  puVar10 = local_c8[uStack_cc] + (int)-(uRam00000000011b40b0 ^ 0xa9fca659);
  if (lVar4 == 2) {
    puStack_180 = puVar12;
    puStack_178 = auStack_3c0;
    IStack_160 = param_3;
    _objc_msgSend(param_1,@selector(layer));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(removeAllAnimations));
    _objc_release(uVar3);
    uVar3 = 0x3fd0000000000000;
    if (ABS(dVar15) <= 60.0) {
      uVar3 = 0x3ff0000000000000;
    }
    puStack_188 = @selector(animationWithKeyPath:);
    _objc_msgSend(PTR__OBJC_CLASS___CABasicAnimation_0114ee20,@selector(animationWithKeyPath:),
                  @"transform");
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar12 = PTR__OBJC_CLASS___NSValue_0114ef60;
    IStack_170 = param_1;
    _objc_msgSend(param_1,puVar11);
    lVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_dc = (uint)(lVar4 == 0);
    if (lVar4 == 0) {
      uStack_1d8 = 0;
      uStack_1e0 = 0;
      uStack_1c8 = 0;
      uStack_1d0 = 0;
      uStack_1f8 = 0;
      uStack_200 = 0;
      uStack_1e8 = 0;
      uStack_1f0 = 0;
      uStack_218 = 0;
      uStack_220 = 0;
      uStack_208 = 0;
      uStack_210 = 0;
      uStack_238 = 0;
      uStack_240 = 0;
      uStack_228 = 0;
      uStack_230 = 0;
    }
    else {
      _objc_msgSend(&uStack_240,lVar4,@selector(transform));
    }
    puVar1 = @selector(valueWithCATransform3D:);
    _objc_msgSend(puVar12,@selector(valueWithCATransform3D:),&uStack_240);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puStack_190 = @selector(setFromValue:);
    _objc_msgSend(uVar5,@selector(setFromValue:),uVar6);
    _objc_release(uVar6);
    _objc_release(lVar4);
    puVar12 = PTR__OBJC_CLASS___NSValue_0114ef60;
    _CATransform3DMakeTranslation(auStack_2c0,0,dVar15,0);
    _objc_msgSend(puVar12,puVar1,auStack_2c0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puStack_198 = @selector(setToValue:);
    _objc_msgSend(uVar5,@selector(setToValue:),uVar6);
    _objc_release(uVar6);
    uVar6 = DAT_00c4c3c0;
    puStack_1a0 = @selector(setDuration:);
    _objc_msgSend(DAT_00c4c3c0,uVar5);
    uStack_1a8 = *(undefined8 *)PTR__kCAMediaTimingFunctionLinear_01060bd8;
    puStack_1b0 = @selector(functionWithName:);
    _objc_msgSend(PTR__OBJC_CLASS___CAMediaTimingFunction_0114ef68);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puStack_1b8 = @selector(setTimingFunction:);
    _objc_msgSend(uVar5,@selector(setTimingFunction:),uVar7);
    _objc_release(uVar7);
    puVar12 = @selector(setRemovedOnCompletion:);
    _objc_msgSend(uVar5,@selector(setRemovedOnCompletion:),0);
    puVar1 = @selector(setFillMode:);
    uVar13 = *(undefined8 *)PTR__kCAFillModeForwards_01060bb8;
    _objc_msgSend(uVar5,@selector(setFillMode:),uVar13);
    _objc_msgSend(PTR__OBJC_CLASS___CABasicAnimation_0114ee20,puStack_188,
                  @"opacity");
    uVar7 = _objc_retainAutoreleasedReturnValue();
    param_1 = IStack_170;
    puVar2 = PTR__OBJC_CLASS___NSNumber_0114eb00;
    _objc_msgSend(IStack_170,puVar11);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,@selector(opacity));
    _objc_msgSend(puVar2,@selector(numberWithFloat:));
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puStack_190,uVar9);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_msgSend(uVar3,PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithDouble:));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puStack_198,uVar3);
    _objc_release(uVar3);
    _objc_msgSend(uVar6,uVar7,puStack_1a0);
    _objc_msgSend(PTR__OBJC_CLASS___CAMediaTimingFunction_0114ef68,puStack_1b0,uStack_1a8);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puStack_1b8,uVar3);
    _objc_release(uVar3);
    _objc_msgSend(uVar7,puVar12,0);
    _objc_msgSend(uVar7,puVar1,uVar13);
    _objc_msgSend(param_1,puVar11);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    puVar12 = @selector(addAnimation:forKey:);
    _objc_msgSend(uVar3,@selector(addAnimation:forKey:),uVar5,
                  @"panTranslation");
    _objc_release(uVar3);
    _objc_msgSend(param_1,puVar11);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,puVar12,uVar7,@"panOpacity");
    _objc_release(uVar3);
    _objc_release(uVar7);
    _objc_release(uVar5);
    puVar10 = &stack0xffffffffffffff80;
    puVar12 = puStack_180;
    param_3 = IStack_160;
  }
  lVar4 = _objc_msgSend(puVar10,param_3,puVar12);
  uStack_104 = (uint)(lVar4 == 3);
  puVar11 = local_100[uStack_104] + (int)-(uRam00000000011b40f8 ^ 0x4d75847f);
  if (lVar4 != 3) {
    lVar4 = _objc_msgSend(puVar11,param_3,puVar12);
    uStack_114 = (uint)(lVar4 == 4);
    puVar11 = local_110[uStack_114] + (int)-(uRam00000000011b4110 ^ 0x4b09c9e8);
    if (lVar4 != 4) {
      _objc_release(param_3);
      return;
    }
  }
  _objc_msgSend(puVar11,param_1,@selector(layer));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(removeAllAnimations));
  _objc_release(uVar3);
  uStack_124 = (uint)(60.0 < ABS(dVar15));
                    /* WARNING: Could not recover jumptable at 0x001bd53c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_120[uStack_124] + (int)-(uRam00000000011b4128 ^ 0xebe10052)))();
  return;
}



// -[ToastView handleTap], 0x1bd9b4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bd9b4. handleTap */

/* Function Stack Size: 0x10 bytes */

void ToastView::handleTap(ID param_1,SEL param_2)

{
  undefined8 *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  bool bVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  ID IVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined **ppuVar16;
  undefined1 *puVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  double in_d1;
  undefined8 uVar20;
  double in_d3;
  undefined8 uVar21;
  undefined8 auStack_2c0 [16];
  undefined8 auStack_240 [16];
  undefined *puStack_1c0;
  undefined8 uStack_1b8;
  code *pcStack_1b0;
  undefined *puStack_1a8;
  undefined8 uStack_1a0;
  ID IStack_198;
  ID IStack_190;
  undefined8 uStack_188;
  undefined *puStack_170;
  undefined *puStack_168;
  undefined *puStack_160;
  undefined *puStack_158;
  undefined8 uStack_150;
  undefined *puStack_148;
  undefined8 uStack_140;
  ID IStack_138;
  undefined8 *puStack_130;
  undefined8 *puStack_128;
  undefined8 uStack_120;
  undefined **local_118;
  undefined **local_110;
  uint uStack_104;
  undefined **local_100;
  uint uStack_f4;
  undefined **local_f0;
  undefined **local_e8;
  uint uStack_dc;
  undefined **local_d8;
  int iStack_cc;
  undefined **local_c8;
  uint uStack_bc;
  undefined **local_b8;
  undefined **local_b0;
  uint local_a4;
  undefined **local_a0;
  
  local_a0 = &PTR_LAB_011b4168;
  local_a4 = (uint)(DAT_01227afc == 0);
  local_b8 = &PTR_LAB_011b4188;
  local_c8 = &PTR_LAB_011b41a0;
  local_d8 = &PTR__objc_msgSend_011b41b8;
  local_f0 = &PTR_LAB_011b41d8;
  local_100 = &PTR_LAB_011b41f0;
  local_b0 = &PTR_LAB_011b39f0;
  local_e8 = &PTR_LAB_011b39f0;
  local_110 = &PTR_LAB_011b39f0;
  local_118 = &PTR_LAB_011b39f0;
  DAT_01227afc = 1;
  _objc_msgSend(PTR_ToastManager_0114ecd0,@selector(sharedManager));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,@selector(toasts));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(count);
  uVar10 = _objc_msgSend(uVar9,@selector(count));
  uStack_bc = (uint)(uVar10 < 2);
  puVar17 = local_b8[uStack_bc] + (int)-(uRam00000000011b4198 ^ 0x6fd4affb);
  if (uVar10 >= 2) {
    puStack_130 = auStack_240;
    puStack_128 = auStack_2c0;
    _objc_retain(uVar9);
    _objc_sync_enter();
    iStack_cc = FUN_001c5cf4(uVar9,@selector(containsObject:),param_1);
    if (iStack_cc != 0) {
      _objc_msgSend(uVar9,@selector(removeObject:),param_1);
      _objc_msgSend(uVar9,@selector(insertObject:atIndex:),param_1,0);
    }
    uStack_120 = uVar8;
    _objc_sync_exit(uVar9);
    _objc_release(uVar9);
    lVar11 = _objc_msgSend(uVar9,puVar3);
    puVar4 = @selector(updateLayout);
    puVar2 = @selector(objectAtIndexedSubscript:);
    uStack_dc = (uint)(lVar11 == 0);
    if (lVar11 != 0) {
      uVar10 = 0;
      ppuVar16 = &@selector(addObjectsFromArray:);
      do {
        _objc_msgSend(ppuVar16,uVar9,puVar2,uVar10);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar4);
        _objc_release(uVar8);
        uVar10 = uVar10 + 1;
        uVar12 = _objc_msgSend(uVar9,puVar3);
        uStack_104 = (uint)(uVar10 < uVar12);
        ppuVar16 = (undefined **)(local_100[uStack_104] + (int)-(uRam00000000011b4200 ^ 0x2d891bf3))
        ;
      } while (uVar10 < uVar12);
    }
    _objc_msgSend(uVar9,@selector(lastObject));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,@selector(firstObject));
    IVar13 = _objc_retainAutoreleasedReturnValue();
    lVar11 = _objc_msgSend(uVar9,puVar3);
    bVar7 = IVar13 != 0 && IVar13 == param_1;
    uStack_f4 = (uint)bVar7;
    if (bVar7) {
      uVar21 = *(undefined8 *)(&UNK_00c4c3e0 + (ulong)(lVar11 == 2) * 8);
      puStack_148 = @selector(layer);
      _objc_msgSend(param_1);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      IStack_138 = IVar13;
      uVar19 = _objc_msgSend(uVar14,@selector(position));
      _objc_release(uVar14);
      _objc_msgSend(param_1,@selector(bounds));
      puStack_158 = @selector(animationWithKeyPath:);
      uStack_140 = uVar8;
      _objc_msgSend(PTR__OBJC_CLASS___CABasicAnimation_0114ee20,@selector(animationWithKeyPath:)
                    ,@"position.y");
      uVar8 = _objc_retainAutoreleasedReturnValue();
      puVar3 = @selector(numberWithDouble:);
      _objc_msgSend(in_d1,PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithDouble:));
      uVar14 = _objc_retainAutoreleasedReturnValue();
      puStack_160 = @selector(setFromValue:);
      _objc_msgSend(uVar8,@selector(setFromValue:),uVar14);
      _objc_release(uVar14);
      _objc_msgSend(in_d1 - in_d3,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      puStack_168 = @selector(setToValue:);
      _objc_msgSend(uVar8,@selector(setToValue:),uVar14);
      _objc_release(uVar14);
      puStack_170 = @selector(setDuration:);
      uStack_150 = uVar8;
      _objc_msgSend(0x3fd0000000000000,uVar8);
      puVar2 = @selector(functionWithName:);
      uVar18 = *(undefined8 *)PTR__kCAMediaTimingFunctionEaseInEaseOut_01060bc8;
      _objc_msgSend(PTR__OBJC_CLASS___CAMediaTimingFunction_0114ef68,
                    @selector(functionWithName:),uVar18);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      puVar4 = @selector(setTimingFunction:);
      _objc_msgSend(uVar8,@selector(setTimingFunction:),uVar14);
      _objc_release(uVar14);
      _objc_msgSend(PTR__OBJC_CLASS___CABasicAnimation_0114ee20,puStack_158,
                    @"transform.scale");
      uVar15 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0x3ff0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar15,puStack_160,uVar8);
      _objc_release(uVar8);
      _objc_msgSend(uVar21,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar15,puStack_168,uVar14);
      uVar8 = uStack_140;
      _objc_release(uVar14);
      _objc_msgSend(0x3fd0000000000000,uVar15,puStack_170);
      _objc_msgSend(PTR__OBJC_CLASS___CAMediaTimingFunction_0114ef68,puVar2,uVar18);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar15,puVar4,uVar14);
      _objc_release(uVar14);
      _objc_msgSend(PTR__OBJC_CLASS___CATransaction_0114ed20,@selector(begin));
      puVar3 = PTR__OBJC_CLASS___CATransaction_0114ed20;
      puStack_1c0 = PTR___NSConcreteStackBlock_01060660;
      uStack_1b8 = DAT_00c4c228;
      pcStack_1b0 = FUN_001be4a4;
      puStack_1a8 = &DAT_01062a40;
      _objc_retain(uVar8);
      uStack_1a0 = uVar8;
      IStack_198 = param_1;
      uStack_188 = uVar19;
      _objc_retain(param_1);
      IStack_190 = param_1;
      _objc_msgSend(puVar3,@selector(setCompletionBlock:),&puStack_1c0);
      puVar2 = puStack_148;
      _objc_msgSend(param_1,puStack_148);
      uVar18 = _objc_retainAutoreleasedReturnValue();
      uVar14 = uStack_150;
      puVar3 = @selector(addAnimation:forKey:);
      _objc_msgSend(uVar18,@selector(addAnimation:forKey:),uStack_150,
                    @"lift");
      _objc_release(uVar18);
      _objc_msgSend(param_1,puVar2);
      uVar18 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar18,puVar3,uVar15,@"scaleDown");
      _objc_release(uVar18);
      _objc_msgSend(param_1,puVar2);
      uVar18 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar19,in_d1 - in_d3,uVar18,@selector(setPosition:));
      _objc_release(uVar18);
      puVar5 = puStack_130;
      _CATransform3DMakeScale(puStack_130,uVar21,uVar21,0x3ff0000000000000);
      _objc_msgSend(param_1,puVar2);
      uVar18 = _objc_retainAutoreleasedReturnValue();
      puVar6 = puStack_128;
      uVar19 = puVar5[8];
      uVar20 = puVar5[0xb];
      uVar21 = puVar5[10];
      puVar1 = puStack_128 + 8;
      puStack_128[9] = puVar5[9];
      *puVar1 = uVar19;
      puVar6[0xb] = uVar20;
      puVar6[10] = uVar21;
      uVar19 = puVar5[0xc];
      uVar20 = puVar5[0xf];
      uVar21 = puVar5[0xe];
      puVar6[0xd] = puVar5[0xd];
      puVar6[0xc] = uVar19;
      puVar6[0xf] = uVar20;
      puVar6[0xe] = uVar21;
      uVar19 = *puVar5;
      uVar20 = puVar5[3];
      uVar21 = puVar5[2];
      puVar6[1] = puVar5[1];
      *puVar6 = uVar19;
      puVar6[3] = uVar20;
      puVar6[2] = uVar21;
      uVar19 = puVar5[4];
      uVar20 = puVar5[7];
      uVar21 = puVar5[6];
      puVar6[5] = puVar5[5];
      puVar6[4] = uVar19;
      puVar6[7] = uVar20;
      puVar6[6] = uVar21;
      _objc_msgSend(uVar18,@selector(setTransform:));
      IVar13 = IStack_138;
      _objc_release(uVar18);
      _objc_msgSend(PTR__OBJC_CLASS___CATransaction_0114ed20,@selector(commit));
      _objc_release(IStack_190);
      _objc_release(uStack_1a0);
      _objc_release(uVar15);
      _objc_release(uVar14);
    }
    _objc_release(IVar13);
    _objc_release(uVar8);
    puVar17 = &stack0xffffffffffffffe0;
    uVar8 = uStack_120;
  }
  _objc_release(puVar17,uVar9);
  _objc_release(uVar8);
  CallSupervisor(0xb64f);
  return;
}



// -[ToastView updateLayout], 0x1be8a0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1be8a0. updateLayout */

/* Function Stack Size: 0x10 bytes */

void ToastView::updateLayout(ID param_1,SEL param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  double dVar4;
  double dVar5;
  double in_d2;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_011b4258;
  lVar3 = *(long *)(param_1 + (long)_sourceView);
  local_3c = (uint)(lVar3 == 0);
  if (lVar3 != 0) {
    _objc_msgSend(lVar3,@selector(frame));
    cVar1 = *(char *)(param_1 + (long)_isiPad);
    iVar2 = FUN_001c5fbc(param_1,@selector(isLandscape));
    dVar4 = DAT_00c4c2e0;
    if (iVar2 == 0) {
      dVar4 = 0.5;
    }
    dVar5 = 0.5;
    if (iVar2 == 0) {
      dVar5 = DAT_00c4c3b8;
    }
    if (cVar1 != '\0') {
      dVar5 = dVar4;
    }
    _objc_msgSend(*(undefined8 *)(param_1 + (long)_keyboardHeight),param_1,
                  @selector(calculateToastParametersWithKeyboardHeight:bottomOffset:topOffset:scale:),&uStack_48,&uStack_50,&uStack_58);
    _objc_msgSend(uStack_48,uStack_50,uStack_58,in_d2 * dVar5,0x3fe0000000000000,param_1,
                  @selector(configureToastAppearanceWithBottomOffset:topOffset:scale:width:animationDuration:));
  }
  CallSupervisor(0x3db5);
  return;
}



// -[ToastView calculateToastParametersWithKeyboardHeight:bottomOffset:topOffset:scale:], 0x1be9d8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1be9d8. calculateToastParametersWithKeyboardHeight:bottomOffset:topOffset:scale: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x30 bytes */

void ToastView::calculateToastParametersWithKeyboardHeight_bottomOffset_topOffset_scale_
               (ID param_1,SEL param_2,double param_3,double *param_4,double *param_5,
               double *param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  undefined *puVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  dVar6 = (double)_objc_msgSend(*(undefined8 *)(param_1 + (long)_sourceView),
                                @selector(safeAreaInsets));
  _objc_msgSend(PTR_ToastManager_0114ecd0,@selector(sharedManager));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(toasts));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  lVar3 = _objc_msgSend(uVar2,@selector(indexOfObject:),param_1);
  uVar4 = _objc_msgSend(uVar2,@selector(count));
  _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,@selector(mainScreen));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(bounds));
  dVar7 = (double)_CGRectGetWidth();
  _objc_release(uVar1);
  puVar5 = @selector(bottomOffset);
  dVar8 = (double)_objc_msgSend(param_1,@selector(bottomOffset));
  *param_6 = 1.0;
  *param_5 = dVar6 + 15.0;
  if (0.0 < param_3) {
    dVar6 = *(double *)(param_1 + (long)__goodHeight) + param_3 + 15.0;
    *param_4 = dVar6;
    puVar5 = (&PTR_LAB_011b42a0)[uVar4 == 1] + (int)-(uRam00000000011b42b0 ^ 0xd3c8ba4c);
  }
  else {
    dVar6 = 0.0;
    if (dVar7 != _UNK_00c4c3c8) {
      dVar6 = 30.0;
    }
    if (dVar8 != 0.0) {
      dVar6 = 0.0;
    }
    dVar7 = *(double *)(param_1 + (long)__goodHeight) + -30.0;
    if (*(double *)(param_1 + (long)__goodHeight) <= 0.0) {
      dVar7 = 0.0;
    }
    dVar8 = (double)_objc_msgSend(param_1,puVar5);
    dVar6 = dVar6 + dVar8 + dVar7 + 15.0;
    *param_4 = dVar6;
    puVar5 = (&PTR_LAB_011b42a0)[uVar4 == 1] + (int)-(uRam00000000011b42b0 ^ 0xd3c8ba4c);
  }
  if (uVar4 == 1) goto LAB_001bedcc;
  if (lVar3 == uVar4 - 1) {
    puVar5 = (&PTR_LAB_011b42d0)[uVar4 == 2] + (int)-(uRam00000000011b42e0 ^ 0x9d2ba2d6);
    if (uVar4 == 2) {
LAB_001bedac:
      dVar7 = 5.0;
    }
    else {
      puVar5 = (&PTR_LAB_011b42f0)[2 < uVar4] + (int)-(uRam00000000011b4300 ^ 0xa383896e);
      if (uVar4 < 3) goto LAB_001bedcc;
      dVar7 = 10.0;
    }
  }
  else {
    if (lVar3 != uVar4 - 2) {
      puVar5 = (undefined *)0x3feccccccccccccd;
      *param_6 = 0.9;
      goto LAB_001bedcc;
    }
    *param_6 = 0.95;
    dVar6 = *param_4;
    puVar5 = (&PTR_LAB_011b4328)[uVar4 == 2] + (int)-(uRam00000000011b4338 ^ 0x37569626);
    if (uVar4 != 2) goto LAB_001bedac;
    dVar7 = 0.0;
  }
  *param_4 = dVar6 + dVar7;
  *param_5 = *param_5 + dVar7;
LAB_001bedcc:
  _objc_release(puVar5,uVar2);
  CallSupervisor(0xa0e3);
  return;
}



// -[ToastView configureToastAppearanceWithBottomOffset:topOffset:scale:width:animationDuration:], 0x1bee14
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bee14. configureToastAppearanceWithBottomOffset:topOffset:scale:width:animationDuration: */

/* Function Stack Size: 0x38 bytes */

void ToastView::configureToastAppearanceWithBottomOffset_topOffset_scale_width_animationDuration_
               (ID param_1,SEL param_2,double param_3,double param_4,double param_5,double param_6,
               double param_7)

{
  undefined *puVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined *puStack_80;
  undefined8 uStack_78;
  code *pcStack_70;
  undefined *puStack_68;
  ID IStack_60;
  double dStack_58;
  uint local_4c;
  undefined **local_48;
  
  puVar1 = @selector(setConstant:);
  local_48 = &PTR_LAB_011b4358;
  _objc_msgSend(-param_3,*(undefined8 *)(param_1 + (long)_bottomConstraint),
                @selector(setConstant:));
  _objc_msgSend(param_6,*(undefined8 *)(param_1 + (long)_widthConstraint),puVar1);
  _objc_msgSend(param_4,*(undefined8 *)(param_1 + (long)_topConstraint),puVar1);
  bVar2 = *(char *)(param_1 + (long)_ignoresFullscreenOpacity) == '\0';
  local_4c = (uint)bVar2;
  if (bVar2) {
    uVar3 = FUN_001c61e4(param_1,@selector(isFullscreen));
    _objc_msgSend(param_1,@selector(setHidden:),uVar3);
  }
  puStack_80 = PTR___NSConcreteStackBlock_01060660;
  uStack_78 = DAT_00c4c228;
  pcStack_70 = FUN_001befa0;
  puStack_68 = &DAT_01061810;
  IStack_60 = param_1;
  dStack_58 = param_5;
  _objc_msgSend(param_7,0,0x3ff0000000000000,0x402e000000000000,PTR__OBJC_CLASS___UIView_0114ec30,
                @selector(animateWithDuration:delay:usingSpringWithDamping:initialSpringVelocity:options:animations:completion:),0,&puStack_80,0);
  CallSupervisor(0xa031);
  return;
}



// -[ToastView configureToastAppearanceWithBottomOffset:topOffset:scale:width:alpha:animationDuration:completion:], 0x1bf098
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bf098. configureToastAppearanceWithBottomOffset:topOffset:scale:width:alpha:animationDuration:completion: */

/* Function Stack Size: 0x48 bytes */

void ToastView::
     configureToastAppearanceWithBottomOffset_topOffset_scale_width_alpha_animationDuration_completion_
               (ID param_1,SEL param_2,double param_3,double param_4,double param_5,double param_6,
               double param_7,double param_8,ID param_9,undefined4 param_10)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *local_c0;
  undefined8 local_b8;
  code *local_b0;
  undefined *puStack_a8;
  ID local_a0;
  undefined *local_98;
  undefined8 local_90;
  code *local_88;
  undefined *puStack_80;
  ID local_78;
  double local_70;
  double dStack_68;
  
  _objc_retain(param_9,param_2,param_9,param_10);
  puVar1 = @selector(setConstant:);
  _objc_msgSend(-param_3,*(undefined8 *)(param_1 + (long)_bottomConstraint),
                @selector(setConstant:));
  _objc_msgSend(param_6,*(undefined8 *)(param_1 + (long)_widthConstraint),puVar1);
  _objc_msgSend(param_4,*(undefined8 *)(param_1 + (long)_topConstraint),puVar1);
  puVar2 = PTR__OBJC_CLASS___UIView_0114ec30;
  puVar1 = @selector(animateWithDuration:delay:usingSpringWithDamping:initialSpringVelocity:options:animations:completion:);
  local_98 = PTR___NSConcreteStackBlock_01060660;
  local_90 = DAT_00c4c228;
  local_88 = FUN_001bf1f4;
  puStack_80 = &DAT_01062a70;
  local_c0 = PTR___NSConcreteStackBlock_01060660;
  local_b8 = DAT_00c4c228;
  local_b0 = FUN_001bf2e4;
  puStack_a8 = &DAT_01062aa0;
  local_a0 = param_9;
  local_78 = param_1;
  local_70 = param_7;
  dStack_68 = param_5;
  _objc_retain(param_9);
  _objc_msgSend(param_8,0,0x3ff0000000000000,0x402e000000000000,puVar2,puVar1,0,&local_98,&local_c0)
  ;
  _objc_release(local_a0);
  _objc_release(param_9);
  return;
}



// -[ToastView setupObservers], 0x1bf368
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bf368. setupObservers */

/* Function Stack Size: 0x10 bytes */

void ToastView::setupObservers(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  
  puVar1 = @selector(defaultCenter);
  DAT_01227b40 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,@selector(defaultCenter));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(addObserver:selector:name:object:);
  _objc_msgSend(uVar3,@selector(addObserver:selector:name:object:),param_1,
                @selector(keyboardWillShow:),
                *(undefined8 *)PTR__UIKeyboardWillShowNotification_010605c0,0);
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,puVar2,param_1,@selector(keyboardWillHide:),
                *(undefined8 *)PTR__UIKeyboardWillHideNotification_010605b8,0);
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,puVar2,param_1,@selector(goodHeightDidChange:),
                @"GOODHeightDidChangeNotification",0);
  _objc_release(uVar3);
  CallSupervisor(0xcf9b);
  return;
}



// -[ToastView removeObservers], 0x1bf6d4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bf6d4. removeObservers */

/* Function Stack Size: 0x10 bytes */

void ToastView::removeObservers(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  
  puVar1 = @selector(defaultCenter);
  DAT_01227b44 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,@selector(defaultCenter));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(removeObserver:name:object:);
  _objc_msgSend(uVar3,@selector(removeObserver:name:object:),param_1,
                *(undefined8 *)PTR__UIKeyboardWillShowNotification_010605c0,0);
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,puVar2,param_1,*(undefined8 *)PTR__UIKeyboardWillHideNotification_010605b8,0);
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,puVar2,param_1,@"GOODHeightDidChangeNotification",0);
  _objc_release(uVar3);
  return;
}



// -[ToastView goodHeightDidChange:], 0x1bfa0c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bfa0c. goodHeightDidChange: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x18 bytes */

void ToastView::goodHeightDidChange_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  float fVar3;
  
  DAT_01227b48 = 1;
  _objc_msgSend(param_3,@selector(userInfo));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(objectForKeyedSubscript:),
                @"height");
  uVar2 = _objc_retainAutoreleasedReturnValue();
  fVar3 = (float)_objc_msgSend(uVar2,@selector(floatValue));
  *(double *)(param_1 + (long)__goodHeight) = (double)fVar3;
  _objc_release(uVar2);
  _objc_msgSend(param_1,@selector(updateLayout));
  _objc_release(uVar1);
  CallSupervisor(0x810f);
  return;
}



// -[ToastView keyboardWillShow:], 0x1bfba0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bfba0. keyboardWillShow: */

/* Function Stack Size: 0x18 bytes */

void ToastView::keyboardWillShow_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  
  _objc_msgSend(param_3,@selector(userInfo));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(objectForKeyedSubscript:),
                *(undefined8 *)PTR__UIKeyboardFrameEndUserInfoKey_010605b0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_msgSend(uVar2,@selector(CGRectValue));
  _objc_release(uVar2);
  _objc_msgSend(uVar3,in_d1,in_d2,in_d3,param_1,@selector(convertRect:fromView:),0);
  uVar2 = _CGRectGetHeight();
  *(undefined8 *)(param_1 + (long)_keyboardHeight) = uVar2;
  _objc_msgSend(param_1,@selector(updateLayout));
  _objc_release(uVar1);
  CallSupervisor(0xabc8);
  return;
}



// -[ToastView keyboardWillHide:], 0x1bfc9c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bfc9c. keyboardWillHide: */

/* Function Stack Size: 0x18 bytes */

void ToastView::keyboardWillHide_(ID param_1,SEL param_2,ID param_3)

{
  *(undefined8 *)(param_1 + (long)_keyboardHeight) = 0;
  _objc_msgSend(param_1,@selector(updateLayout));
  CallSupervisor(0xcd51);
  return;
}



// -[ToastView cleanup], 0x1bfcdc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bfcdc. cleanup */

/* Function Stack Size: 0x10 bytes */

void ToastView::cleanup(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  _objc_msgSend(param_1,@selector(layer));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(removeAllAnimations));
  _objc_release(uVar1);
  lVar2 = (long)_progressTimer;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar2),@selector(invalidate));
  uVar1 = *(undefined8 *)(param_1 + lVar2);
  *(undefined8 *)(param_1 + lVar2) = 0;
  _objc_release(uVar1);
  *(undefined1 *)(param_1 + (long)_ignoresPanGesture) = 0;
  *(undefined1 *)(param_1 + (long)_ignoresFullscreenOpacity) = 0;
  _objc_msgSend(param_1,@selector(removeFromSuperview));
  _objc_msgSend(param_1,@selector(removeObservers));
  _objc_msgSend(PTR_ToastManager_0114ecd0,@selector(sharedManager));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(unregisterToast:),param_1);
  _objc_release(uVar1);
  CallSupervisor(0x1a38);
  return;
}



// -[ToastView cancelButtonTapped], 0x1bfdd0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bfdd0. cancelButtonTapped */

/* Function Stack Size: 0x10 bytes */

void ToastView::cancelButtonTapped(ID param_1,SEL param_2)

{
  undefined *puVar1;
  long lVar2;
  
  puVar1 = @selector(completion);
  _objc_msgSend(param_1,@selector(completion));
  lVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar2 != 0) {
    _objc_msgSend((&PTR_LAB_011b43f8)[lVar2 == 0] + (int)-(DAT_011b4408 ^ 0xf31a9c34),param_1,puVar1
                 );
    lVar2 = _objc_retainAutoreleasedReturnValue();
    (**(code **)(lVar2 + 0x10))();
    _objc_release(lVar2);
                    /* WARNING: Could not recover jumptable at 0x001bfec4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011b4418)[*(char *)(param_1 + (long)_ignoresPanGesture) == '\0'] +
              (int)-(uRam00000000011b4428 ^ 0x4e358d11)))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x001bff1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011b4418)[*(char *)(param_1 + (long)_ignoresPanGesture) == '\0'] +
            (int)-(uRam00000000011b4428 ^ 0x4e358d11)))();
  return;
}



// -[ToastView handleLongPress:], 0x1bff34
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bff34. handleLongPress: */

/* Function Stack Size: 0x18 bytes */

void ToastView::handleLongPress_(ID param_1,SEL param_2,ID param_3)

{
  long lVar1;
  
  lVar1 = _objc_msgSend(param_3,@selector(state));
  if (lVar1 == 1) {
    _objc_msgSend(param_1,@selector(hide));
  }
  CallSupervisor(0xf280);
  return;
}



// -[ToastView showProgressWithText:progress:withStop:stopCompletion:], 0x1bffdc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bffdc. showProgressWithText:progress:withStop:stopCompletion: */

/* Function Stack Size: 0x28 bytes */

void ToastView::showProgressWithText_progress_withStop_stopCompletion_
               (ID param_1,SEL param_2,ID param_3,float param_4,bool param_5,ID param_6,
               undefined4 param_7)

{
  undefined *puVar1;
  undefined *local_80;
  undefined8 local_78;
  code *local_70;
  undefined *puStack_68;
  ID local_60;
  ID local_58;
  ID local_50;
  float local_48;
  undefined1 local_44;
  
  _objc_retain(param_3);
  _objc_retain(param_6);
  puVar1 = @selector(enqueueCommand:);
  local_80 = PTR___NSConcreteStackBlock_01060660;
  local_78 = DAT_00c4c228;
  local_70 = FUN_001c00c8;
  puStack_68 = &DAT_01062b00;
  local_44 = (undefined1)param_5;
  local_60 = param_1;
  local_58 = param_3;
  local_50 = param_6;
  local_48 = param_4;
  _objc_retain();
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,&local_80);
  _objc_release(local_50);
  _objc_release(local_58);
  _objc_release(param_6);
  _objc_release(param_3);
  CallSupervisor(0xa6e9);
  return;
}



// -[ToastView updateText:progress:], 0x1c033c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c033c. updateText:progress: */

/* Function Stack Size: 0x1c bytes */

void ToastView::updateText_progress_(ID param_1,SEL param_2,ID param_3,float param_4)

{
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastLabel),@selector(setText:));
  _objc_msgSend(param_4,*(undefined8 *)(param_1 + (long)_toastProgress),
                @selector(setProgress:animated:),1);
  CallSupervisor(0x1a9b);
  return;
}



// -[ToastView updateText:progress:animated:], 0x1c03b4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c03b4. updateText:progress:animated: */

/* Function Stack Size: 0x20 bytes */

void ToastView::updateText_progress_animated_
               (ID param_1,SEL param_2,ID param_3,float param_4,bool param_5)

{
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastLabel),@selector(setText:));
  _objc_msgSend(param_4,*(undefined8 *)(param_1 + (long)_toastProgress),
                @selector(setProgress:animated:),param_5);
  CallSupervisor(0x51b3);
  return;
}



// -[ToastView showMessageWithText:isSuccess:], 0x1c0430
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0430. showMessageWithText:isSuccess: */

/* Function Stack Size: 0x1c bytes */

void ToastView::showMessageWithText_isSuccess_(ID param_1,SEL param_2,ID param_3,bool param_4)

{
  _objc_msgSend(0x4004000000000000,param_1,@selector(showMessageWithText:isSuccess:duration:),param_3,
                param_4);
  CallSupervisor(0xa510);
  return;
}



// -[ToastView showMessageWithText:isSuccess:duration:], 0x1c0468
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0468. showMessageWithText:isSuccess:duration: */

/* Function Stack Size: 0x24 bytes */

void ToastView::showMessageWithText_isSuccess_duration_
               (ID param_1,SEL param_2,ID param_3,bool param_4,double param_5)

{
  undefined *puVar1;
  undefined *local_80;
  undefined8 local_78;
  code *local_70;
  undefined *puStack_68;
  ID local_60;
  ID local_58;
  double local_50;
  undefined1 local_48;
  
  _objc_retain(param_3);
  puVar1 = @selector(enqueueCommand:);
  local_80 = PTR___NSConcreteStackBlock_01060660;
  local_78 = DAT_00c4c228;
  local_70 = FUN_001c0530;
  puStack_68 = &DAT_01062b60;
  local_48 = (undefined1)param_4;
  local_60 = param_1;
  local_58 = param_3;
  local_50 = param_5;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,&local_80);
  _objc_release(local_58);
  _objc_release(param_3);
  CallSupervisor(0xf7d7);
  return;
}



// -[ToastView showText:], 0x1c0740
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0740. showText: */

/* Function Stack Size: 0x18 bytes */

void ToastView::showText_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  ID local_40;
  ID local_38;
  
  _objc_retain(param_3);
  puVar1 = @selector(enqueueCommand:);
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_001c07f0;
  puStack_48 = &DAT_01061f70;
  local_40 = param_1;
  local_38 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,&local_60);
  _objc_release(local_38);
  _objc_release(param_3);
  CallSupervisor(0x6ee6);
  return;
}



// -[ToastView showToast:], 0x1c09b0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c09b0. showToast: */

/* Function Stack Size: 0x18 bytes */

void ToastView::showToast_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  ID local_40;
  ID local_38;
  
  _objc_retain(param_3);
  puVar1 = @selector(enqueueCommand:);
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_001c0a60;
  puStack_48 = &DAT_01061f70;
  local_40 = param_1;
  local_38 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,&local_60);
  _objc_release(local_38);
  _objc_release(param_3);
  CallSupervisor(0xd082);
  return;
}



// -[ToastView showProgressiveToastWithText:duration:isSuccess:], 0x1c0ccc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0ccc. showProgressiveToastWithText:duration:isSuccess: */

/* Function Stack Size: 0x24 bytes */

void ToastView::showProgressiveToastWithText_duration_isSuccess_
               (ID param_1,SEL param_2,ID param_3,double param_4,bool param_5)

{
  undefined *puVar1;
  undefined *local_80;
  undefined8 local_78;
  code *local_70;
  undefined *puStack_68;
  ID local_60;
  ID local_58;
  double local_50;
  undefined1 local_48;
  
  _objc_retain(param_3);
  puVar1 = @selector(enqueueCommand:);
  local_80 = PTR___NSConcreteStackBlock_01060660;
  local_78 = DAT_00c4c228;
  local_70 = FUN_001c0d7c;
  puStack_68 = &DAT_01062b60;
  local_48 = (undefined1)param_5;
  local_60 = param_1;
  local_58 = param_3;
  local_50 = param_4;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,&local_80);
  _objc_release(local_58);
  _objc_release(param_3);
  return;
}



// -[ToastView showProgressiveToastWithText:duration:actionTitle:actionCompletion:], 0x1c0f78
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0f78. showProgressiveToastWithText:duration:actionTitle:actionCompletion: */

/* Function Stack Size: 0x30 bytes */

void ToastView::showProgressiveToastWithText_duration_actionTitle_actionCompletion_
               (ID param_1,SEL param_2,ID param_3,double param_4,ID param_5,ID param_6,
               undefined4 param_7)

{
  undefined *puVar1;
  undefined *local_98;
  undefined8 local_90;
  code *local_88;
  undefined *puStack_80;
  ID local_78;
  ID local_70;
  ID local_68;
  ID local_60;
  double local_58;
  
  _objc_retain(param_3);
  _objc_retain(param_5);
  _objc_retain(param_6);
  puVar1 = @selector(enqueueCommand:);
  local_98 = PTR___NSConcreteStackBlock_01060660;
  local_90 = DAT_00c4c228;
  local_88 = FUN_001c108c;
  puStack_80 = &DAT_01062bc0;
  local_78 = param_1;
  local_70 = param_3;
  local_68 = param_5;
  local_60 = param_6;
  local_58 = param_4;
  _objc_retain(param_5);
  _objc_retain(param_6);
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,&local_98);
  _objc_release(local_68);
  _objc_release(local_60);
  _objc_release(local_70);
  _objc_release(param_5);
  _objc_release(param_6);
  _objc_release(param_3);
  CallSupervisor(0x5499);
  return;
}



// -[ToastView showProgressiveToastWithText:duration:actionIcon:actionCompletion:], 0x1c1644
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c1644. showProgressiveToastWithText:duration:actionIcon:actionCompletion: */

/* Function Stack Size: 0x30 bytes */

void ToastView::showProgressiveToastWithText_duration_actionIcon_actionCompletion_
               (ID param_1,SEL param_2,ID param_3,double param_4,ID param_5,ID param_6,
               undefined4 param_7)

{
  _objc_msgSend(param_1,@selector(showProgressiveToastWithText:duration:actionIcon:ignoresPan:actionCompletion:),param_3,param_5,0,param_6);
  CallSupervisor(0xd776);
  return;
}



// -[ToastView showProgressiveToastWithText:duration:actionIcon:ignoresPan:actionCompletion:], 0x1c1680
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c1680. showProgressiveToastWithText:duration:actionIcon:ignoresPan:actionCompletion: */

/* Function Stack Size: 0x34 bytes */

void ToastView::showProgressiveToastWithText_duration_actionIcon_ignoresPan_actionCompletion_
               (ID param_1,SEL param_2,ID param_3,double param_4,ID param_5,bool param_6,ID param_7,
               undefined4 param_8)

{
  undefined *puVar1;
  undefined *local_a0;
  undefined8 local_98;
  code *local_90;
  undefined *puStack_88;
  ID local_80;
  ID local_78;
  ID local_70;
  ID local_68;
  double local_60;
  undefined1 local_58;
  
  _objc_retain(param_3);
  _objc_retain(param_5);
  _objc_retain(param_7);
  puVar1 = @selector(enqueueCommand:);
  local_a0 = PTR___NSConcreteStackBlock_01060660;
  local_98 = DAT_00c4c228;
  local_90 = FUN_001c1798;
  puStack_88 = &DAT_01062bf0;
  local_58 = (undefined1)param_6;
  local_80 = param_1;
  local_78 = param_3;
  local_70 = param_5;
  local_68 = param_7;
  local_60 = param_4;
  _objc_retain();
  _objc_retain(param_5);
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,&local_a0);
  _objc_release(local_68);
  _objc_release(local_70);
  _objc_release(local_78);
  _objc_release(param_7);
  _objc_release(param_5);
  _objc_release(param_3);
  CallSupervisor(0xa46c);
  return;
}



// -[ToastView showDonationReminder:], 0x1c1af8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c1af8. showDonationReminder: */

/* Function Stack Size: 0x18 bytes */

void ToastView::showDonationReminder_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  ID local_40;
  ID local_38;
  
  _objc_retain(param_3);
  puVar1 = @selector(enqueueCommand:);
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_001c1b90;
  puStack_48 = &DAT_01061f70;
  local_40 = param_1;
  local_38 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,&local_60);
  _objc_release(local_38);
  _objc_release(param_3);
  return;
}



// -[ToastView startTimerCountdown:], 0x1c1d18
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c1d18. startTimerCountdown: */

/* Function Stack Size: 0x18 bytes */

void ToastView::startTimerCountdown_(ID param_1,SEL param_2,double param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined *local_78;
  undefined8 local_70;
  code *local_68;
  undefined *puStack_60;
  ID local_58;
  undefined8 *puStack_50;
  double local_48;
  undefined8 local_40;
  undefined8 *puStack_38;
  undefined8 local_30;
  undefined8 local_28;
  
  puStack_50 = &local_40;
  local_40 = 0;
  local_30 = DAT_00c4c3d0;
  local_28 = 0x3ff0000000000000;
  local_48 = DAT_00c4c3d8 / param_3;
  local_78 = PTR___NSConcreteStackBlock_01060660;
  local_70 = DAT_00c4c228;
  local_68 = FUN_001c1e4c;
  puStack_60 = &DAT_01062c20;
  local_58 = param_1;
  puStack_38 = puStack_50;
  _objc_msgSend(DAT_00c4c3d8,PTR__OBJC_CLASS___NSTimer_0114ef70,
                @selector(timerWithTimeInterval:repeats:block:),1,&local_78);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSRunLoop_0114ef78,@selector(mainRunLoop));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(addTimer:forMode:),uVar1,
                *(undefined8 *)PTR__NSRunLoopCommonModes_01060390);
  _objc_release(uVar2);
  _objc_release(uVar1);
  __Block_object_dispose(&local_40,8);
  return;
}



// -[ToastView hideAnimatedWithCompletion:], 0x1c1fb4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c1fb4. hideAnimatedWithCompletion: */

/* Function Stack Size: 0x18 bytes */

void ToastView::hideAnimatedWithCompletion_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  ID IVar6;
  ID IVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
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
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined1 auStack_110 [48];
  undefined1 auStack_e0 [8];
  undefined *puStack_d8;
  undefined *puStack_d0;
  undefined8 uStack_c8;
  ID IStack_c0;
  ID IStack_b8;
  undefined1 *puStack_b0;
  undefined *puStack_a8;
  undefined1 *puStack_a0;
  undefined8 *puStack_98;
  undefined8 *puStack_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  
  puStack_b0 = auStack_e0;
  local_78 = &PTR_LAB_011b44e0;
  local_7c = (uint)(DAT_01227c0c == 0);
  local_88 = &PTR_LAB_011b39f0;
  DAT_01227c0c = 1;
  puStack_a0 = auStack_110;
  puStack_98 = &uStack_190;
  puStack_90 = &uStack_210;
  IStack_b8 = param_3;
  _objc_retain(param_3,param_2,param_3,param_4);
  puStack_a8 = @selector(layer);
  _objc_msgSend(param_1);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  IStack_c0 = param_1;
  _objc_msgSend(uVar9,@selector(removeAllAnimations));
  _objc_release(uVar9);
  puVar2 = @selector(animationWithKeyPath:);
  _objc_msgSend(PTR__OBJC_CLASS___CABasicAnimation_0114ee20,@selector(animationWithKeyPath:),
                @"transform.scale");
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(numberWithDouble:);
  _objc_msgSend(0x3ff0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,
                @selector(numberWithDouble:));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puStack_d0 = @selector(setFromValue:);
  _objc_msgSend(uVar10,@selector(setFromValue:),uVar9);
  _objc_release(uVar9);
  uVar9 = DAT_00c4c250;
  _objc_msgSend(DAT_00c4c250,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puStack_d8 = @selector(setToValue:);
  _objc_msgSend(uVar10,@selector(setToValue:),uVar11);
  _objc_release(uVar11);
  puVar3 = @selector(setDuration:);
  uVar11 = DAT_00c4c2e0;
  uStack_c8 = uVar10;
  _objc_msgSend(DAT_00c4c2e0,uVar10,@selector(setDuration:));
  puVar4 = @selector(functionWithName:);
  uVar13 = *(undefined8 *)PTR__kCAMediaTimingFunctionEaseIn_01060bc0;
  _objc_msgSend(PTR__OBJC_CLASS___CAMediaTimingFunction_0114ef68,@selector(functionWithName:),
                uVar13);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar5 = @selector(setTimingFunction:);
  _objc_msgSend(uVar10,@selector(setTimingFunction:),uVar12);
  _objc_release(uVar12);
  _objc_msgSend(PTR__OBJC_CLASS___CABasicAnimation_0114ee20,puVar2,
                @"opacity");
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x3ff0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puStack_d0,uVar12);
  _objc_release(uVar12);
  _objc_msgSend(0,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puStack_d8,uVar12);
  _objc_release(uVar12);
  _objc_msgSend(uVar11,uVar10,puVar3);
  _objc_msgSend(PTR__OBJC_CLASS___CAMediaTimingFunction_0114ef68,puVar4,uVar13);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puVar5,uVar11);
  _objc_release(uVar11);
  _objc_msgSend(PTR__OBJC_CLASS___CATransaction_0114ed20,@selector(begin));
  puVar8 = puStack_b0;
  IVar7 = IStack_b8;
  puVar2 = PTR__OBJC_CLASS___CATransaction_0114ed20;
  *(undefined **)(puStack_b0 + -0x30) = PTR___NSConcreteStackBlock_01060660;
  *(undefined8 *)(puVar8 + -0x28) = DAT_00c4c228;
  *(code **)(puVar8 + -0x20) = FUN_001c269c;
  *(undefined **)(puVar8 + -0x18) = &UNK_01062c50;
  IVar6 = IStack_c0;
  *(ID *)(puVar8 + -0x10) = IStack_c0;
  *(ID *)(puVar8 + -8) = IVar7;
  puVar1 = @selector(setCompletionBlock:);
  _objc_retain(IVar7);
  _objc_msgSend(puVar2,puVar1,puStack_a0);
  puVar2 = puStack_a8;
  _objc_msgSend(IVar6,puStack_a8);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  uVar11 = uStack_c8;
  puVar1 = @selector(addAnimation:forKey:);
  _objc_msgSend(uVar12,@selector(addAnimation:forKey:),uStack_c8,
                @"scale");
  _objc_release(uVar12);
  _objc_msgSend(IVar6,puVar2);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,puVar1,uVar10,@"opacity");
  _objc_release(uVar12);
  _CATransform3DMakeScale(puStack_98,uVar9,uVar9,0x3ff0000000000000);
  _objc_msgSend(IVar6,puVar2);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  uStack_1c8 = uStack_148;
  uStack_1d0 = uStack_150;
  uStack_1b8 = uStack_138;
  uStack_1c0 = uStack_140;
  uStack_1a8 = uStack_128;
  uStack_1b0 = uStack_130;
  uStack_198 = uStack_118;
  uStack_1a0 = uStack_120;
  uStack_208 = uStack_188;
  uStack_210 = uStack_190;
  uStack_1f8 = uStack_178;
  uStack_200 = uStack_180;
  uStack_1e8 = uStack_168;
  uStack_1f0 = uStack_170;
  uStack_1d8 = uStack_158;
  uStack_1e0 = uStack_160;
  _objc_msgSend(uVar9,@selector(setTransform:),puStack_90);
  _objc_release(uVar9);
  _objc_msgSend(IVar6,puVar2);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0,uVar9,@selector(setOpacity:));
  _objc_release(uVar9);
  _objc_msgSend(PTR__OBJC_CLASS___CATransaction_0114ed20,@selector(commit));
  _objc_release(*(undefined8 *)(puVar8 + -8));
  _objc_release(IVar7);
  _objc_release(uVar10);
  _objc_release(uVar11);
  CallSupervisor(0x1c4e);
  return;
}



// -[ToastView hideImmediately], 0x1c2760
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2760. hideImmediately */

/* Function Stack Size: 0x10 bytes */

void ToastView::hideImmediately(ID param_1,SEL param_2)

{
  _objc_msgSend(param_1,@selector(cleanup));
  _objc_msgSend(param_1,@selector(processQueue));
  CallSupervisor(0xe053);
  return;
}



// -[ToastView hideWithDelay:], 0x1c27b0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c27b0. hideWithDelay: */

/* Function Stack Size: 0x18 bytes */

void ToastView::hideWithDelay_(ID param_1,SEL param_2,double param_3)

{
  dispatch_time_t dVar1;
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  ID local_28;
  
  dVar1 = _dispatch_time(0,(long)(param_3 * DAT_00c4c268));
  local_48 = PTR___NSConcreteStackBlock_01060660;
  local_40 = DAT_00c4c228;
  local_38 = FUN_001c282c;
  puStack_30 = &DAT_01061420;
  local_28 = param_1;
  _dispatch_after(dVar1,PTR___dispatch_main_q_01060760,&local_48);
  return;
}



// -[ToastView hide], 0x1c2840
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2840. hide */

/* Function Stack Size: 0x10 bytes */

void ToastView::hide(ID param_1,SEL param_2)

{
  _objc_msgSend(0,param_1,@selector(hideWithDelay:));
  CallSupervisor(0x463f);
  return;
}



// -[ToastView isHidden], 0x1c2878
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2878. isHidden */

/* Function Stack Size: 0x10 bytes */

bool ToastView::isHidden(ID param_1,SEL param_2)

{
  bool bVar1;
  dispatch_time_t dVar2;
  ID local_30;
  undefined *puStack_28;
  
  puStack_28 = PTR_ToastView_0114f0e8;
  local_30 = param_1;
  bVar1 = FUN_001c7b1c(&local_30,@selector(isHidden));
  dVar2 = _dispatch_time(0,300000000);
  _dispatch_after(dVar2,PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_01062c80);
  return bVar1;
}



// -[ToastView hideWithCompletion:], 0x1c2944
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2944. hideWithCompletion: */

/* Function Stack Size: 0x18 bytes */

void ToastView::hideWithCompletion_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  bool bVar1;
  double dVar2;
  undefined *puStack_60;
  undefined8 uStack_58;
  code *pcStack_50;
  undefined *puStack_48;
  ID IStack_40;
  ID IStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011b4528;
  _objc_retain(param_3,param_2,param_3,param_4);
  bVar1 = *(char *)(param_1 + (long)_isAnimating) == '\0';
  local_2c = (uint)bVar1;
  if ((bVar1) && (dVar2 = (double)_objc_msgSend(param_1,@selector(alpha)), dVar2 == 0.0)) {
                    /* WARNING: Could not recover jumptable at 0x001c2acc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011b4558)[param_3 == 0] + (int)-(uRam00000000011b4568 ^ 0x8411f74c)))();
    return;
  }
  puStack_60 = PTR___NSConcreteStackBlock_01060660;
  uStack_58 = DAT_00c4c228;
  pcStack_50 = FUN_001c2ae0;
  puStack_48 = &UNK_01062c50;
  IStack_40 = param_1;
  _objc_retain(param_3);
  IStack_38 = param_3;
  _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_60);
  _objc_release(IStack_38);
  _objc_release(param_3);
  CallSupervisor(0xdc27);
  return;
}



// -[ToastView isLandscape], 0x1c2b1c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2b1c. isLandscape */

/* Function Stack Size: 0x10 bytes */

bool ToastView::isLandscape(ID param_1,SEL param_2)

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



// -[ToastView isFullscreen], 0x1c2be4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2be4. isFullscreen */

/* Function Stack Size: 0x10 bytes */

bool ToastView::isFullscreen(ID param_1,SEL param_2)

{
  bool bVar1;
  undefined8 uVar2;
  
  _objc_msgSend(PTR_ToastManager_0114ecd0,@selector(sharedManager));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  bVar1 = FUN_001c7ce4(uVar2,@selector(isFullscreen));
  _objc_release(uVar2);
  return bVar1;
}



// -[ToastView isPinnedTop], 0x1c2c38
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2c38. isPinnedTop */

/* Function Stack Size: 0x10 bytes */

bool ToastView::isPinnedTop(ID param_1,SEL param_2)

{
  bool bVar1;
  undefined8 uVar2;
  
  _objc_msgSend(PTR_ToastManager_0114ecd0,@selector(sharedManager));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  bVar1 = FUN_001c7d2c(uVar2,@selector(isPinnedTop));
  _objc_release(uVar2);
  return bVar1;
}



// -[ToastView bottomOffset], 0x1c2c8c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2c8c. bottomOffset */

/* Function Stack Size: 0x10 bytes */

double ToastView::bottomOffset(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  double dVar5;
  
  _objc_msgSend(PTR_ToastManager_0114ecd0,@selector(sharedManager));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(offsetController));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  puVar1 = @selector(bottomOffset);
  uVar2 = FUN_001c7d94(uVar4,@selector(respondsToSelector:),@selector(bottomOffset));
  if (uVar2 == 0) {
    dVar5 = 0.0;
  }
  else {
    dVar5 = (double)_objc_msgSend((&PTR_LAB_011b4580)[uVar2] + (int)-(DAT_011b4590 ^ 0xbd4e97d6),
                                  uVar4,puVar1);
  }
  _objc_release(uVar4);
  return dVar5;
}



// -[ToastView dealloc], 0x1c2d78
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2d78. dealloc */

/* Function Stack Size: 0x10 bytes */

void ToastView::dealloc(ID param_1,SEL param_2)

{
  ID local_30;
  undefined *puStack_28;
  
  _objc_msgSend(param_1,@selector(removeObservers));
  puStack_28 = PTR_ToastView_0114f0e8;
  local_30 = param_1;
  _objc_msgSendSuper2(&local_30,@selector(dealloc));
  CallSupervisor(0xb073);
  return;
}



// -[ToastView completion], 0x1c2ddc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2ddc. completion */

/* Function Stack Size: 0x10 bytes */

ID ToastView::completion(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + (long)_completion);
}



// -[ToastView setCompletion:], 0x1c2dec
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2dec. setCompletion: */

/* Function Stack Size: 0x18 bytes */

void ToastView::setCompletion_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  _objc_setProperty_nonatomic_copy();
  CallSupervisor(0x6339);
  return;
}



// -[ToastView .cxx_destruct], 0x1c2e20
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2e20. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void ToastView::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_completion,0);
  _objc_storeStrong(param_1 + (long)_heightConstraint,0);
  _objc_storeStrong(param_1 + (long)_widthConstraint,0);
  _objc_storeStrong(param_1 + (long)_centerXConstraint,0);
  _objc_storeStrong(param_1 + (long)_bottomConstraint,0);
  _objc_storeStrong(param_1 + (long)_topConstraint,0);
  _objc_storeStrong(param_1 + (long)_progressTimer,0);
  _objc_storeStrong(param_1 + (long)_activityIndicator,0);
  _objc_storeStrong(param_1 + (long)_toastButton,0);
  _objc_storeStrong(param_1 + (long)_actionsStack,0);
  _objc_storeStrong(param_1 + (long)_toastIcon,0);
  _objc_storeStrong(param_1 + (long)_toastProgress,0);
  _objc_storeStrong(param_1 + (long)_toastLabel,0);
  _objc_storeStrong(param_1 + (long)_sourceView,0);
  _objc_storeStrong(param_1 + (long)_ytSourceView,0);
  _objc_storeStrong(param_1 + (long)_commandQueue,0);
  return;
}



// +[ToastView initialize], 0x1b9d50
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b9d50. initialize */

/* Function Stack Size: 0x10 bytes */

void ToastView::initialize(ID param_1,SEL param_2)

{
  ID IVar1;
  
  IVar1 = _objc_msgSend(PTR_ToastView_0114ec98,@selector(class));
  if (IVar1 == param_1) {
    _objc_msgSend(param_1,@selector(toastWindow));
    _objc_unsafeClaimAutoreleasedReturnValue();
  }
  CallSupervisor(0xed57);
  return;
}



// +[ToastView toastWindow], 0x1b9e04
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b9e04. toastWindow */

/* Function Stack Size: 0x10 bytes */

ID ToastView::toastWindow(ID param_1,SEL param_2)

{
  ID IVar1;
  SEL extraout_x1;
  
  if (DAT_01227ad0 != -1) {
    _dispatch_once((&PTR_LAB_011b3e20)[DAT_01227ad0 == -1] + (int)-(DAT_011b3e30 ^ 0xdbe57c1c),
                   &DAT_01227ad0,&PTR___NSConcreteGlobalBlock_01062a00);
    param_2 = extraout_x1;
  }
  IVar1 = (*(code *)PTR__objc_retainAutoreleaseReturnValue_01061040)(DAT_01227ac8,param_2);
  return IVar1;
}


