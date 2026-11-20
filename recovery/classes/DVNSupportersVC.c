// Decompiled implementation evidence for DVNSupportersVC. Not compilable source.

// -[DVNSupportersVC viewDidLoad], 0x191f84
/* Decompiled from supplied 5.2.2 arm package. VA 0x191f84. viewDidLoad */

/* Function Stack Size: 0x10 bytes */

void DVNSupportersVC::viewDidLoad(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  long lVar14;
  undefined1 auStack_180 [16];
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  ID IStack_150;
  undefined *puStack_148;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined *puStack_100;
  undefined8 uStack_f8;
  undefined *puStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined *puStack_c8;
  undefined8 uStack_c0;
  undefined *puStack_b8;
  undefined8 *puStack_b0;
  long lStack_a8;
  undefined *puStack_a0;
  undefined8 *puStack_98;
  undefined1 *puStack_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_011a98d0;
  local_7c = (uint)(DAT_012277bc == 0);
  local_88 = &PTR_LAB_011a98c0;
  DAT_012277bc = 1;
  puStack_b0 = &uStack_170;
  puStack_90 = auStack_180;
  puStack_148 = PTR_DVNSupportersVC_0114f0d0;
  IStack_150 = param_1;
  puStack_98 = puStack_b0;
  _objc_msgSendSuper2(&IStack_150,@selector(viewDidLoad));
  _objc_msgSend(@"SpecialThanks",@selector(ytl_localized));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(setTitle:),uVar6);
  _objc_release(uVar6);
  uVar6 = _objc_alloc_init(PTR__OBJC_CLASS___WKWebView_0114eec8);
  lVar14 = (long)_webView;
  uVar13 = *(undefined8 *)(param_1 + lVar14);
  *(undefined8 *)(param_1 + lVar14) = uVar6;
  _objc_release(uVar13);
  puStack_a0 = @selector(setTranslatesAutoresizingMaskIntoConstraints:);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(setTranslatesAutoresizingMaskIntoConstraints:),0)
  ;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(setNavigationDelegate:),param_1);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(setOpaque:),0);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(systemBackgroundColor));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(setBackgroundColor:),uVar6);
  _objc_release(uVar6);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(scrollView));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(setContentInsetAdjustmentBehavior:),0);
  _objc_release(uVar6);
  puVar1 = @selector(view);
  _objc_msgSend(param_1,@selector(view));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puStack_b8 = @selector(addSubview:);
  _objc_msgSend(uVar6,@selector(addSubview:),*(undefined8 *)(param_1 + lVar14));
  _objc_release(uVar6);
  puVar2 = @selector(topAnchor);
  puStack_100 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(topAnchor));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uStack_d0 = uVar6;
  _objc_msgSend(param_1,puVar1);
  uStack_c0 = _objc_retainAutoreleasedReturnValue();
  puVar4 = @selector(safeAreaLayoutGuide);
  _objc_msgSend(uStack_c0,@selector(safeAreaLayoutGuide));
  uStack_d8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uStack_d8,puVar2);
  uStack_e0 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(constraintEqualToAnchor:);
  _objc_msgSend(uVar6,@selector(constraintEqualToAnchor:),uStack_e0);
  uStack_170 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(bottomAnchor);
  uStack_e8 = uStack_170;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(bottomAnchor));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uStack_108 = uVar6;
  _objc_msgSend(param_1,puVar1);
  uStack_f8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uStack_f8,puVar3);
  uStack_110 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,puVar2,uStack_110);
  uStack_168 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(leadingAnchor);
  uStack_118 = uStack_168;
  lStack_a8 = lVar14;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(leadingAnchor));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puStack_f0 = puVar1;
  uStack_128 = uVar6;
  _objc_msgSend(param_1,puVar1);
  uStack_120 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uStack_120,puVar4);
  uStack_130 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uStack_130,puVar3);
  uStack_138 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,puVar2,uStack_138);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(trailingAnchor);
  uStack_160 = uVar6;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(trailingAnchor));
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar4);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar3);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,puVar2,uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puStack_c8 = @selector(arrayWithObjects:count:);
  uStack_158 = uVar10;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),puStack_b0
                ,4);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puStack_b0 = (undefined8 *)@selector(activateConstraints:);
  _objc_msgSend(puStack_100,@selector(activateConstraints:),uVar11);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar13);
  _objc_release(uVar6);
  _objc_release(uStack_138);
  _objc_release(uStack_130);
  _objc_release(uStack_120);
  _objc_release(uStack_128);
  _objc_release(uStack_118);
  _objc_release(uStack_110);
  _objc_release(uStack_f8);
  _objc_release(uStack_108);
  _objc_release(uStack_e8);
  _objc_release(uStack_e0);
  _objc_release(uStack_d8);
  _objc_release(uStack_c0);
  _objc_release(uStack_d0);
  uVar6 = _objc_alloc(PTR__OBJC_CLASS___UIActivityIndicatorView_0114eb20);
  uVar6 = _objc_msgSend(uVar6,@selector(initWithActivityIndicatorStyle:),100);
  lVar14 = (long)_activityIndicator;
  uVar13 = *(undefined8 *)(param_1 + lVar14);
  *(undefined8 *)(param_1 + lVar14) = uVar6;
  _objc_release(uVar13);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),puStack_a0,0);
  puVar3 = puStack_f0;
  _objc_msgSend(param_1,puStack_f0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,puStack_b8,*(undefined8 *)(param_1 + lVar14));
  _objc_release(uVar6);
  puVar1 = @selector(centerXAnchor);
  puStack_b8 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(centerXAnchor));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puStack_a0 = (undefined *)uVar6;
  _objc_msgSend(param_1,puVar3);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,puVar1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,puVar2,uVar7);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar5 = puStack_98;
  puStack_98[-2] = uVar6;
  puVar1 = @selector(centerYAnchor);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar14),@selector(centerYAnchor));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar3);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,puVar1);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar2,uVar10);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar5[-1] = uVar11;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puStack_c8,puStack_90,2);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_b8,puStack_b0,uVar12);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar6);
  _objc_release(uVar7);
  _objc_release(uVar13);
  _objc_release(puStack_a0);
  puVar1 = PTR__OBJC_CLASS___NSURLRequest_0114eed0;
  uVar7 = *(undefined8 *)(param_1 + lStack_a8);
  _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,@selector(URLWithString:),
                @"https://dvntm.com/patreon/specialthanks");
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,@selector(requestWithURL:),uVar6);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(loadRequest:),uVar13);
  _objc_unsafeClaimAutoreleasedReturnValue();
  _objc_release(uVar13);
  _objc_release(uVar6);
  CallSupervisor(0xbeea);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_70) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}



// -[DVNSupportersVC webView:didStartProvisionalNavigation:], 0x192ac0
/* Decompiled from supplied 5.2.2 arm package. VA 0x192ac0. webView:didStartProvisionalNavigation: */

/* Function Stack Size: 0x20 bytes */

void DVNSupportersVC::webView_didStartProvisionalNavigation_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_activityIndicator),@selector(startAnimating));
  CallSupervisor(0xdcdb);
  return;
}



// -[DVNSupportersVC webView:didFinishNavigation:], 0x192b00
/* Decompiled from supplied 5.2.2 arm package. VA 0x192b00. webView:didFinishNavigation: */

/* Function Stack Size: 0x20 bytes */

void DVNSupportersVC::webView_didFinishNavigation_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_activityIndicator),@selector(stopAnimating));
  CallSupervisor(0x255e);
  return;
}



// -[DVNSupportersVC webView:didFailProvisionalNavigation:withError:], 0x192b40
/* Decompiled from supplied 5.2.2 arm package. VA 0x192b40. webView:didFailProvisionalNavigation:withError: */

/* Function Stack Size: 0x28 bytes */

void DVNSupportersVC::webView_didFailProvisionalNavigation_withError_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
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
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  puVar1 = @selector(stopAnimating);
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar22 = *(undefined8 *)(param_1 + (long)_activityIndicator);
  _objc_retain(param_5);
  _objc_msgSend(uVar22,puVar1);
  uVar22 = _objc_alloc_init(PTR__OBJC_CLASS___UILabel_0114ec00);
  _objc_msgSend(param_5,@selector(localizedDescription));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_5);
  _objc_msgSend(uVar22,@selector(setText:),uVar5);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(secondaryLabelColor));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar22,@selector(setTextColor:),uVar5);
  _objc_release(uVar5);
  _objc_msgSend(uVar22,@selector(setTextAlignment:),1);
  _objc_msgSend(uVar22,@selector(setNumberOfLines:),0);
  _objc_msgSend(uVar22,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
  puVar1 = @selector(view);
  _objc_msgSend(param_1,@selector(view));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(addSubview:),uVar22);
  _objc_release(uVar5);
  puVar4 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  puVar2 = @selector(centerXAnchor);
  _objc_msgSend(uVar22,@selector(centerXAnchor));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,puVar2);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(constraintEqualToAnchor:);
  _objc_msgSend(uVar5,@selector(constraintEqualToAnchor:),uVar7);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(centerYAnchor);
  local_88 = uVar8;
  _objc_msgSend(uVar22,@selector(centerYAnchor));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puVar3);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,puVar2,uVar11);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(leadingAnchor);
  local_80 = uVar12;
  _objc_msgSend(uVar22,@selector(leadingAnchor));
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar14,puVar2);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(constraintEqualToAnchor:constant:);
  _objc_msgSend(0x4040000000000000,uVar13,@selector(constraintEqualToAnchor:constant:),uVar15);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(trailingAnchor);
  local_78 = uVar16;
  _objc_msgSend(uVar22,@selector(trailingAnchor));
  uVar17 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar18 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar18,puVar2);
  uVar19 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0xc040000000000000,uVar17,puVar3,uVar19);
  uVar20 = _objc_retainAutoreleasedReturnValue();
  local_70 = uVar20;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),&local_88,
                4);
  uVar21 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar4,@selector(activateConstraints:),uVar21);
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
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar22);
  CallSupervisor(0xc93a);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}



// -[DVNSupportersVC .cxx_destruct], 0x192fa4
/* Decompiled from supplied 5.2.2 arm package. VA 0x192fa4. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void DVNSupportersVC::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_activityIndicator,0);
  _objc_storeStrong(param_1 + (long)_webView,0);
  CallSupervisor(0x7828);
  return;
}


