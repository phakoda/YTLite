// Decompiled implementation evidence for DVNImageViewController. Not compilable source.

// -[DVNImageViewController viewDidLoad], 0x21fa6c
/* Decompiled from supplied 5.2.2 arm package. VA 0x21fa6c. viewDidLoad */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::viewDidLoad(ID param_1,SEL param_2)

{
  ID local_30;
  undefined *puStack_28;
  
  puStack_28 = PTR_DVNImageViewController_0114f140;
  local_30 = param_1;
  _objc_msgSendSuper2(&local_30,@selector(viewDidLoad));
  _objc_msgSend(param_1,@selector(setupNavbar));
  _objc_msgSend(param_1,@selector(setupViewer));
  CallSupervisor(0xc08d);
  return;
}



// -[DVNImageViewController setupNavbar], 0x21fae4
/* Decompiled from supplied 5.2.2 arm package. VA 0x21fae4. setupNavbar */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::setupNavbar(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined **ppuVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined1 auStack_190 [32];
  undefined1 auStack_170 [48];
  undefined1 auStack_140 [48];
  undefined *puStack_110;
  undefined *puStack_108;
  code *pcStack_100;
  undefined *puStack_f8;
  ID IStack_f0;
  undefined **ppuStack_e0;
  undefined **ppuStack_d8;
  undefined *puStack_d0;
  undefined *puStack_c8;
  undefined8 uStack_c0;
  undefined1 *puStack_b8;
  undefined1 *puStack_b0;
  undefined1 *puStack_a8;
  undefined1 *puStack_a0;
  undefined1 *puStack_98;
  undefined **local_90;
  uint local_84;
  undefined **local_80;
  long local_78;
  
  puVar1 = @selector(navigationController);
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  local_80 = &PTR_LAB_011ce2f8;
  local_84 = (uint)(DAT_012282b4 == 0);
  local_90 = &PTR_LAB_011ce2a0;
  DAT_012282b4 = 1;
  ppuStack_e0 = &puStack_110;
  puStack_b8 = auStack_140;
  puStack_a8 = auStack_170;
  puStack_98 = auStack_190;
  ppuStack_d8 = ppuStack_e0;
  puStack_b0 = puStack_b8;
  puStack_a0 = puStack_a8;
  _objc_msgSend(param_1,@selector(navigationController));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(navigationBar);
  _objc_msgSend(uVar11,@selector(navigationBar));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,@selector(setTranslucent:),1);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_msgSend(param_1,puVar1);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar3);
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
  _objc_msgSend(uVar12,puVar3);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,@selector(setShadowImage:),uVar11);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  uVar11 = _objc_alloc(PTR__OBJC_CLASS___UIBarButtonItem_0114ee18);
  puVar1 = PTR_BlurButton_0114f018;
  puVar4 = @selector(systemImageNamed:);
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,@selector(systemImageNamed:),
                @"xmark");
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_c8 = @selector(createButtonWithImage:target:action:menu:);
  _objc_msgSend(puVar1,@selector(createButtonWithImage:target:action:menu:),uVar12,param_1,
                @selector(closeButtonTapped:),0);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puStack_d0 = @selector(initWithCustomView:);
  uStack_c0 = _objc_msgSend(uVar11,@selector(initWithCustomView:),uVar13);
  _objc_release(uVar13);
  _objc_release(uVar12);
  puVar6 = PTR__OBJC_CLASS___UIAction_0114ec40;
  puVar2 = @selector(ytl_defaultBundle);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(localizedStringForKey:value:table:);
  _objc_msgSend(uVar11,@selector(localizedStringForKey:value:table:),
                @"Copy",0,0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,puVar4,
                @"doc.on.doc");
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puVar5 = @selector(actionWithTitle:image:identifier:handler:);
  puVar1 = DAT_00c4c228;
  puStack_110 = PTR___NSConcreteStackBlock_01060660;
  puStack_108 = DAT_00c4c228;
  pcStack_100 = FUN_002206f8;
  puStack_f8 = &DAT_01061780;
  IStack_f0 = param_1;
  _objc_msgSend(puVar6,@selector(actionWithTitle:image:identifier:handler:),uVar12,uVar13,0,ppuStack_d8);
  ppuStack_d8 = (undefined **)_objc_retainAutoreleasedReturnValue();
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  puVar6 = PTR__OBJC_CLASS___UIAction_0114ec40;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar2);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar3,@"Share",0,0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,puVar4,
                @"square.and.arrow.up");
  uVar13 = _objc_retainAutoreleasedReturnValue();
  ppuVar7 = ppuStack_e0;
  ppuStack_e0[-6] = PTR___NSConcreteStackBlock_01060660;
  ppuVar7[-5] = puVar1;
  ppuVar7[-4] = FUN_00220798;
  ppuVar7[-3] = &DAT_01061780;
  ppuVar7[-2] = (undefined *)param_1;
  _objc_msgSend(puVar6,puVar5,uVar12,uVar13,0,puStack_b8);
  puStack_b8 = (undefined1 *)_objc_retainAutoreleasedReturnValue();
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  puVar6 = PTR__OBJC_CLASS___UIAction_0114ec40;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar2);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar3,@"SaveToPhotos",0,0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,puVar4,
                @"photo");
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puVar9 = puStack_a8;
  puVar8 = puStack_b0;
  *(undefined **)(puStack_b0 + -0x30) = PTR___NSConcreteStackBlock_01060660;
  *(undefined **)(puVar8 + -0x28) = puVar1;
  *(code **)(puVar8 + -0x20) = FUN_002207ec;
  *(undefined **)(puVar8 + -0x18) = &DAT_01061780;
  *(ID *)(puVar8 + -0x10) = param_1;
  _objc_msgSend(puVar6,puVar5,uVar12,uVar13,0,puVar9);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  uVar11 = _objc_alloc(PTR__OBJC_CLASS___UIBarButtonItem_0114ee18);
  puVar2 = PTR_BlurButton_0114f018;
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,puVar4,
                @"ellipsis");
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar10 = puStack_98;
  puVar9 = puStack_a0;
  puVar8 = puStack_b8;
  puVar1 = PTR__OBJC_CLASS___UIMenu_0114ed00;
  *(undefined8 *)(puStack_a0 + -0x20) = uVar14;
  *(undefined1 **)(puVar9 + -0x18) = puVar8;
  ppuVar7 = ppuStack_d8;
  *(undefined ***)(puVar9 + -0x10) = ppuStack_d8;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),puVar10,3)
  ;
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,@selector(menuWithTitle:children:),&cf___,uVar13);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,puStack_c8,uVar12,0,0,uVar15);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  uVar17 = _objc_msgSend(uVar11,puStack_d0,uVar16);
  _objc_release(uVar16);
  _objc_release(uVar15);
  _objc_release(uVar13);
  _objc_release(uVar12);
  puVar1 = @selector(navigationItem);
  _objc_msgSend(param_1,@selector(navigationItem));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  uVar11 = uStack_c0;
  _objc_msgSend(uVar12,@selector(setLeftBarButtonItem:),uStack_c0);
  _objc_release(uVar12);
  _objc_msgSend(param_1,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,@selector(setRightBarButtonItem:),uVar17);
  _objc_release(uVar12);
  _objc_release(uVar17);
  _objc_release(uVar14);
  _objc_release(puVar8);
  _objc_release(ppuVar7);
  _objc_release(uVar11);
  CallSupervisor(0x7cf0);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_78) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}



// -[DVNImageViewController setupViewer], 0x220864
/* Decompiled from supplied 5.2.2 arm package. VA 0x220864. setupViewer */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::setupViewer(ID param_1,SEL param_2)

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
  long lVar12;
  long lVar13;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(clearColor));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(view);
  _objc_msgSend(param_1,@selector(view));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(setBackgroundColor:),uVar5);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___UIBlurEffect_0114ebe0,@selector(effectWithStyle:),1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = _objc_alloc(PTR__OBJC_CLASS___UIVisualEffectView_0114ebd8);
  uVar6 = _objc_msgSend(uVar6,@selector(initWithEffect:),uVar5);
  _objc_msgSend(param_1,puVar1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(bounds));
  _objc_msgSend(uVar6,@selector(setFrame:));
  _objc_release(uVar7);
  _objc_msgSend(uVar6,@selector(setAutoresizingMask:),0x12);
  _objc_msgSend(param_1,puVar1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(addSubview:);
  _objc_msgSend(uVar7,@selector(addSubview:),uVar6);
  _objc_release(uVar7);
  _objc_msgSend(param_1,puVar1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(sendSubviewToBack:),uVar6);
  _objc_release(uVar7);
  uVar7 = _objc_alloc_init(PTR__OBJC_CLASS___UIScrollView_0114ebe8);
  lVar12 = (long)_scrollView;
  uVar11 = *(undefined8 *)(param_1 + lVar12);
  *(undefined8 *)(param_1 + lVar12) = uVar7;
  _objc_release(uVar11);
  _objc_msgSend(0x4008000000000000,*(undefined8 *)(param_1 + lVar12),
                @selector(setMaximumZoomScale:));
  _objc_msgSend(0x3ff0000000000000,*(undefined8 *)(param_1 + lVar12),
                @selector(setMinimumZoomScale:));
  _objc_msgSend(*(undefined8 *)(param_1 + lVar12),@selector(setDelegate:),param_1);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar12),@selector(setShowsHorizontalScrollIndicator:),0)
  ;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar12),@selector(setShowsVerticalScrollIndicator:),0)
  ;
  _objc_msgSend(*(double *)PTR__UIScrollViewDecelerationRateNormal_010605d0 * 0.5,
                *(undefined8 *)(param_1 + lVar12),@selector(setDecelerationRate:));
  puVar3 = @selector(setTranslatesAutoresizingMaskIntoConstraints:);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar12),@selector(setTranslatesAutoresizingMaskIntoConstraints:),0)
  ;
  _objc_msgSend(param_1,puVar1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar2,*(undefined8 *)(param_1 + lVar12));
  _objc_release(uVar7);
  uVar7 = _objc_alloc_init(PTR__OBJC_CLASS___UIImageView_0114ebf0);
  lVar13 = (long)_imageView;
  uVar11 = *(undefined8 *)(param_1 + lVar13);
  *(undefined8 *)(param_1 + lVar13) = uVar7;
  _objc_release(uVar11);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar13),puVar3,0);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar13),@selector(setContentMode:),1);
  _objc_msgSend(param_1,@selector(fullImage));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar13),@selector(setImage:),uVar7);
  _objc_release(uVar7);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar12),puVar2,*(undefined8 *)(param_1 + lVar13));
  uVar7 = _objc_alloc(PTR__OBJC_CLASS___UITapGestureRecognizer_0114ed98);
  uVar7 = _objc_msgSend(uVar7,@selector(initWithTarget:action:),param_1,
                        @selector(handleDoubleTap:));
  _objc_msgSend(uVar7,@selector(setNumberOfTapsRequired:),2);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar12),@selector(addGestureRecognizer:),uVar7);
  puVar2 = @selector(leadingAnchor);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar12),@selector(leadingAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar2);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(constraintEqualToAnchor:);
  _objc_msgSend(uVar11,@selector(constraintEqualToAnchor:),uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puVar4 = @selector(setActive:);
  _objc_msgSend(uVar10,@selector(setActive:),1);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar11);
  puVar2 = @selector(trailingAnchor);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar12),@selector(trailingAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar2);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar3,uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puVar4,1);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar11);
  puVar2 = @selector(topAnchor);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar12),@selector(topAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar2);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar3,uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puVar4,1);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar11);
  puVar2 = @selector(bottomAnchor);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar12),@selector(bottomAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar2);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar3,uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puVar4,1);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar11);
  puVar1 = @selector(widthAnchor);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar13),@selector(widthAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar12),puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar3,uVar8);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,puVar4,1);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar11);
  puVar1 = @selector(heightAnchor);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar13),@selector(heightAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar12),puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar3,uVar8);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,puVar4,1);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar11);
  puVar1 = @selector(centerXAnchor);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar13),@selector(centerXAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar12),puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar3,uVar8);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,puVar4,1);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar11);
  puVar1 = @selector(centerYAnchor);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar13),@selector(centerYAnchor));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar12),puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar3,uVar8);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,puVar4,1);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar11);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  CallSupervisor(0x3a13);
  return;
}



// -[DVNImageViewController viewForZoomingInScrollView:], 0x221048
/* Decompiled from supplied 5.2.2 arm package. VA 0x221048. viewForZoomingInScrollView: */

/* Function Stack Size: 0x18 bytes */

ID DVNImageViewController::viewForZoomingInScrollView_(ID param_1,SEL param_2,ID param_3)

{
  ID IVar1;
  
  IVar1 = _objc_retainAutoreleaseReturnValue(*(undefined8 *)(param_1 + (long)_imageView));
  return IVar1;
}



// -[DVNImageViewController viewDidLayoutSubviews], 0x221058
/* Decompiled from supplied 5.2.2 arm package. VA 0x221058. viewDidLayoutSubviews */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::viewDidLayoutSubviews(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  long lVar3;
  double dVar4;
  double in_d1;
  double dVar5;
  double in_d2;
  double in_d3;
  double dVar6;
  ID local_60;
  undefined *puStack_58;
  
  puStack_58 = PTR_DVNImageViewController_0114f140;
  local_60 = param_1;
  _objc_msgSendSuper2(&local_60,@selector(viewDidLayoutSubviews));
  _objc_msgSend(param_1,@selector(adjustScrollViewInsets));
  puVar2 = @selector(contentSize);
  lVar3 = (long)_scrollView;
  dVar4 = (double)_objc_msgSend(*(undefined8 *)(param_1 + lVar3),@selector(contentSize));
  puVar1 = @selector(bounds);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar3),@selector(bounds));
  dVar6 = (dVar4 - in_d2) * 0.5;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar3),puVar2);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar3),puVar1);
  dVar5 = (in_d1 - in_d3) * 0.5;
  dVar4 = 0.0;
  if (0.0 <= dVar6) {
    dVar4 = dVar6;
  }
  dVar6 = 0.0;
  if (0.0 <= dVar5) {
    dVar6 = dVar5;
  }
  _objc_msgSend(dVar4,dVar6,*(undefined8 *)(param_1 + lVar3),@selector(setContentOffset:));
  CallSupervisor(0x9d1f);
  return;
}



// -[DVNImageViewController handleDoubleTap:], 0x221160
/* Decompiled from supplied 5.2.2 arm package. VA 0x221160. handleDoubleTap: */

/* Function Stack Size: 0x18 bytes */

void DVNImageViewController::handleDoubleTap_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  double dVar4;
  double dVar5;
  double in_d1;
  double in_d2;
  double in_d3;
  
  _objc_retain(param_3);
  lVar3 = (long)_scrollView;
  dVar4 = (double)_objc_msgSend(*(undefined8 *)(param_1 + lVar3),@selector(zoomScale));
  puVar1 = @selector(maximumZoomScale);
  dVar5 = (double)_objc_msgSend(*(undefined8 *)(param_1 + lVar3),@selector(maximumZoomScale));
  if (dVar4 == dVar5) {
    uVar2 = *(undefined8 *)(param_1 + lVar3);
    _objc_msgSend(uVar2,@selector(minimumZoomScale));
    _objc_msgSend(uVar2,@selector(setZoomScale:animated:),1);
  }
  else {
    dVar4 = (double)_objc_msgSend(param_3,@selector(locationInView:),
                                  *(undefined8 *)(param_1 + (long)_imageView));
    dVar5 = (double)_objc_msgSend(*(undefined8 *)(param_1 + lVar3),puVar1);
    _objc_msgSend(*(undefined8 *)(param_1 + lVar3),@selector(bounds));
    _objc_msgSend(dVar4 - (in_d2 / dVar5) * 0.5,in_d1 - (in_d3 / dVar5) * 0.5,
                  *(undefined8 *)(param_1 + lVar3),@selector(zoomToRect:animated:),1);
  }
  _objc_release(param_3);
  CallSupervisor(0x22dd);
  return;
}



// -[DVNImageViewController scrollViewDidZoom:], 0x2212e4
/* Decompiled from supplied 5.2.2 arm package. VA 0x2212e4. scrollViewDidZoom: */

/* Function Stack Size: 0x18 bytes */

void DVNImageViewController::scrollViewDidZoom_(ID param_1,SEL param_2,ID param_3)

{
  _objc_msgSend(param_1,@selector(adjustScrollViewInsets));
  return;
}



// -[DVNImageViewController scrollViewDidEndZooming:withView:atScale:], 0x2212f0
/* Decompiled from supplied 5.2.2 arm package. VA 0x2212f0. scrollViewDidEndZooming:withView:atScale: */

/* Function Stack Size: 0x28 bytes */

void DVNImageViewController::scrollViewDidEndZooming_withView_atScale_
               (ID param_1,SEL param_2,ID param_3,ID param_4,double param_5)

{
  _objc_msgSend(param_1,@selector(adjustScrollViewInsets));
  CallSupervisor(0xa03c);
  return;
}



// -[DVNImageViewController scrollViewWillBeginZooming:withView:], 0x221324
/* Decompiled from supplied 5.2.2 arm package. VA 0x221324. scrollViewWillBeginZooming:withView: */

/* Function Stack Size: 0x20 bytes */

void DVNImageViewController::scrollViewWillBeginZooming_withView_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  _objc_msgSend(param_1,@selector(adjustScrollViewInsets));
  CallSupervisor(0xdfe6);
  return;
}



// -[DVNImageViewController adjustScrollViewInsets], 0x221358
/* Decompiled from supplied 5.2.2 arm package. VA 0x221358. adjustScrollViewInsets */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::adjustScrollViewInsets(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  long lVar5;
  double dVar6;
  double in_d1;
  double in_d2;
  double in_d3;
  
  puVar2 = @selector(image);
  lVar5 = (long)_imageView;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar5),@selector(image));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(size);
  dVar6 = (double)_objc_msgSend(uVar4,@selector(size));
  _objc_release(uVar4);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar5),puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar3);
  _objc_release(uVar4);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar5),@selector(frame));
  in_d2 = in_d2 / (dVar6 / in_d1);
  dVar6 = (dVar6 / in_d1) * in_d3;
  if (in_d2 <= in_d3) {
    dVar6 = in_d2;
  }
  ppuVar1 = &@selector(adjustHorizontalInsetsWithImageWidth:);
  if (in_d2 <= in_d3) {
    ppuVar1 = &@selector(adjustVerticalInsetsWithImageHeight:);
  }
  _objc_msgSend(dVar6,param_1,*ppuVar1);
  CallSupervisor(0x5eda);
  return;
}



// -[DVNImageViewController adjustHorizontalInsetsWithImageWidth:], 0x221458
/* Decompiled from supplied 5.2.2 arm package. VA 0x221458. adjustHorizontalInsetsWithImageWidth: */

/* Function Stack Size: 0x18 bytes */

void __thiscall
DVNImageViewController::adjustHorizontalInsetsWithImageWidth_
          (DVNImageViewController *this,ID param_1,SEL param_2,double param_3)

{
  undefined *puVar1;
  long lVar2;
  double dVar3;
  double in_d2;
  
  lVar2 = (long)_scrollView;
  dVar3 = (double)_objc_msgSend(*(undefined8 *)(this + lVar2),@selector(contentSize));
  puVar1 = @selector(frame);
  dVar3 = (dVar3 - param_3) * 0.5;
  _objc_msgSend(*(undefined8 *)(this + lVar2),@selector(frame));
  if (param_3 < in_d2) {
    _objc_msgSend((&PTR_LAB_011ce340)[param_3 < in_d2] + (int)-(DAT_011ce350 ^ 0xb33326ec),
                  *(undefined8 *)(this + lVar2),puVar1);
    dVar3 = dVar3 + (in_d2 - param_3) * -0.5;
  }
  _objc_msgSend(0,-dVar3,0,-dVar3,*(undefined8 *)(this + lVar2),@selector(setContentInset:));
  CallSupervisor(0x8ba8);
  return;
}



// -[DVNImageViewController adjustVerticalInsetsWithImageHeight:], 0x22156c
/* Decompiled from supplied 5.2.2 arm package. VA 0x22156c. adjustVerticalInsetsWithImageHeight: */

/* Function Stack Size: 0x18 bytes */

void DVNImageViewController::adjustVerticalInsetsWithImageHeight_
               (ID param_1,SEL param_2,double param_3)

{
  undefined *puVar1;
  long lVar2;
  double in_d1;
  double in_d3;
  double dVar3;
  
  lVar2 = (long)_scrollView;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar2),@selector(contentSize));
  puVar1 = @selector(frame);
  dVar3 = (in_d1 - param_3) * 0.5;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar2),@selector(frame));
  if (param_3 < in_d3) {
    _objc_msgSend((&PTR_LAB_011ce360)[param_3 < in_d3] + (int)-(DAT_011ce370 ^ 0xa0aa92b),
                  *(undefined8 *)(param_1 + lVar2),puVar1);
    dVar3 = dVar3 + (in_d3 - param_3) * -0.5;
  }
  _objc_msgSend(-dVar3,0,-dVar3,0,*(undefined8 *)(param_1 + lVar2),@selector(setContentInset:));
  CallSupervisor(0xdec9);
  return;
}



// -[DVNImageViewController hapticFeedback], 0x221680
/* Decompiled from supplied 5.2.2 arm package. VA 0x221680. hapticFeedback */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::hapticFeedback(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  uVar1 = _objc_alloc(PTR__OBJC_CLASS___UIImpactFeedbackGenerator_0114ec68);
  uVar1 = _objc_msgSend(uVar1,@selector(initWithStyle:),1);
  _objc_msgSend(uVar1,@selector(prepare));
  _objc_msgSend(uVar1,@selector(impactOccurred));
  _objc_release(uVar1);
  return;
}



// -[DVNImageViewController closeButtonTapped], 0x2216d8
/* Decompiled from supplied 5.2.2 arm package. VA 0x2216d8. closeButtonTapped */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::closeButtonTapped(ID param_1,SEL param_2)

{
  _objc_msgSend(param_1,@selector(hapticFeedback));
  _objc_msgSend(param_1,@selector(dismissViewControllerAnimated:completion:),1,0);
  CallSupervisor(0x31f6);
  return;
}



// -[DVNImageViewController share], 0x221730
/* Decompiled from supplied 5.2.2 arm package. VA 0x221730. share */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::share(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  double in_d2;
  undefined8 in_d3;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar4 = _objc_alloc(PTR__OBJC_CLASS___UIActivityViewController_0114ede8);
  _objc_msgSend(param_1,@selector(fullImage));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(arrayWithObjects:count:);
  local_70 = uVar5;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),&local_70,
                1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uVar4 = _objc_msgSend(uVar4,@selector(initWithActivityItems:applicationActivities:),uVar6,0);
  _objc_release(uVar6);
  _objc_release(uVar5);
  local_80 = *(undefined8 *)PTR__UIActivityTypeAssignToContact_01060538;
  uStack_78 = *(undefined8 *)PTR__UIActivityTypePrint_01060540;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar2,&local_80,2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(setExcludedActivityTypes:),uVar5);
  _objc_release(uVar5);
  puVar2 = @selector(popoverPresentationController);
  _objc_msgSend(uVar4,@selector(popoverPresentationController));
  lVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar7 != 0) {
    _objc_msgSend(param_1,@selector(view));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puVar2);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(setSourceView:),uVar5);
    _objc_release(uVar6);
    _objc_release(uVar5);
    puVar3 = @selector(mainScreen);
    _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,@selector(mainScreen));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(bounds);
    _objc_msgSend(uVar5,@selector(bounds));
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,puVar3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar1);
    _objc_release(uVar5);
    _objc_msgSend(uVar4,puVar2);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(in_d2 * 0.5,in_d3,0,0,uVar5,@selector(setSourceRect:));
    _objc_release(uVar5);
    _objc_msgSend(uVar4,puVar2);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(setPermittedArrowDirections:),0xf);
    _objc_release(uVar5);
  }
  _objc_msgSend(param_1,@selector(presentViewController:animated:completion:),uVar4,1,0);
  _objc_release(uVar4);
  CallSupervisor(0x7a9a);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}



// -[DVNImageViewController fullImage], 0x221a60
/* Decompiled from supplied 5.2.2 arm package. VA 0x221a60. fullImage */

/* Function Stack Size: 0x10 bytes */

ID DVNImageViewController::fullImage(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + (long)_fullImage);
}



// -[DVNImageViewController setFullImage:], 0x221a70
/* Decompiled from supplied 5.2.2 arm package. VA 0x221a70. setFullImage: */

/* Function Stack Size: 0x18 bytes */

void DVNImageViewController::setFullImage_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + (long)_fullImage,param_3);
  CallSupervisor(0x83b1);
  return;
}



// -[DVNImageViewController .cxx_destruct], 0x221aac
/* Decompiled from supplied 5.2.2 arm package. VA 0x221aac. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_fullImage,0);
  _objc_storeStrong(param_1 + (long)_imageView,0);
  _objc_storeStrong(param_1 + (long)_scrollView,0);
  CallSupervisor(0xe776);
  return;
}


