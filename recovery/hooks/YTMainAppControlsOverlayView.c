// Decompiled hook evidence for YTMainAppControlsOverlayView. This is not compilable Logos source.

// -[YTMainAppControlsOverlayView handleYTLDiscordTap:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0xb598. FUN_0000b598 */

undefined1  [16] FUN_0000b598(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auVar7 [16];
  
  puVar2 = PTR_YTLUserDefaults_0114ead8;
  puVar1 = @selector(boolForKey:);
  DAT_012258d0 = 1;
  _objc_retain(param_3);
  uVar3 = FUN_0000c500(puVar2,puVar1,@"discordRPC");
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(setBool:forKey:),uVar3 ^ 1,
                @"discordRPC");
  _objc_msgSend(PTR_YTPDiscordRPC_0114eac8,@selector(sharedPresence));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  if (uVar3 == 0) {
    _objc_msgSend(param_1,@selector(_viewControllerForAncestor));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(parentViewController));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    _objc_msgSend(PTR_RPCMedia_0114ead0,@selector(mediaWithPlayer:),uVar6);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(setMedia:),uVar5);
    _objc_release(uVar5);
    _objc_msgSend(uVar4,@selector(startIfPossible));
    _objc_release(uVar6);
  }
  else {
    _objc_msgSend(uVar4,@selector(clearPlayback));
  }
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(adaptiveDiscord));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,@selector(setImage:forState:),uVar5,0);
  _objc_release(param_3);
  _objc_release(uVar5);
  _objc_release(uVar4);
  CallSupervisor(0x37eb);
  auVar7._8_8_ = 0x1f;
  auVar7._0_8_ = 0x1a;
  return auVar7;
}



// -[YTMainAppControlsOverlayView speedControls], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b06c. FUN_0004b06c */

void FUN_0004b06c(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b06c);
  return;
}



// -[YTMainAppControlsOverlayView setSpeedControls:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b078. FUN_0004b078 */

undefined1  [16] FUN_0004b078(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  _objc_setAssociatedObject(param_1,FUN_0004b06c,param_3,1);
  CallSupervisor(0xa980);
  return ZEXT816(0x1f);
}



// -[YTMainAppControlsOverlayView ytlButtons], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b0b0. FUN_0004b0b0 */

void FUN_0004b0b0(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b0b0);
  return;
}



// -[YTMainAppControlsOverlayView setYtlButtons:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b0bc. FUN_0004b0bc */

undefined1  [16] FUN_0004b0bc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  
  _objc_setAssociatedObject(param_1,FUN_0004b0b0,param_3,1);
  CallSupervisor(0x882e);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTMainAppControlsOverlayView speedMinus], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b0f4. FUN_0004b0f4 */

void FUN_0004b0f4(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b0f4);
  return;
}



// -[YTMainAppControlsOverlayView setSpeedMinus:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b100. FUN_0004b100 */

undefined1  [16] FUN_0004b100(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  _objc_setAssociatedObject(param_1,FUN_0004b0f4,param_3,1);
  CallSupervisor(0xe2ee);
  return ZEXT816(0x1f);
}



// -[YTMainAppControlsOverlayView speedPlus], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b138. FUN_0004b138 */

void FUN_0004b138(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b138);
  return;
}



// -[YTMainAppControlsOverlayView setSpeedPlus:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b144. FUN_0004b144 */

undefined1  [16] FUN_0004b144(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  
  _objc_setAssociatedObject(param_1,FUN_0004b138,param_3,1);
  CallSupervisor(0x107d);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTMainAppControlsOverlayView speedValue], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b17c. FUN_0004b17c */

void FUN_0004b17c(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b17c);
  return;
}



// -[YTMainAppControlsOverlayView setSpeedValue:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b188. FUN_0004b188 */

undefined1  [16] FUN_0004b188(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  
  _objc_setAssociatedObject(param_1,FUN_0004b17c,param_3,1);
  CallSupervisor(0x161c);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTMainAppControlsOverlayView ytlButton], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b1c0. FUN_0004b1c0 */

void FUN_0004b1c0(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b1c0);
  return;
}



// -[YTMainAppControlsOverlayView setYtlButton:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b1cc. FUN_0004b1cc */

undefined1  [16] FUN_0004b1cc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  
  _objc_setAssociatedObject(param_1,FUN_0004b1c0,param_3,1);
  CallSupervisor(0xa9cf);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTMainAppControlsOverlayView ytlMuteButton], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b204. FUN_0004b204 */

void FUN_0004b204(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b204);
  return;
}



// -[YTMainAppControlsOverlayView setYtlMuteButton:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b210. FUN_0004b210 */

undefined1  [16] FUN_0004b210(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  _objc_setAssociatedObject(param_1,FUN_0004b204,param_3,1);
  CallSupervisor(0xf92d);
  return ZEXT816(0x1f);
}



// -[YTMainAppControlsOverlayView ytlLockButton], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b248. FUN_0004b248 */

void FUN_0004b248(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b248);
  return;
}



// -[YTMainAppControlsOverlayView setYtlLockButton:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b254. FUN_0004b254 */

undefined1  [16] FUN_0004b254(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  
  _objc_setAssociatedObject(param_1,FUN_0004b248,param_3,1);
  CallSupervisor(0x17c6);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTMainAppControlsOverlayView ytlSleepButton], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b28c. FUN_0004b28c */

void FUN_0004b28c(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b28c);
  return;
}



// -[YTMainAppControlsOverlayView setYtlSleepButton:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b298. FUN_0004b298 */

undefined1  [16] FUN_0004b298(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  _objc_setAssociatedObject(param_1,FUN_0004b28c,param_3,1);
  CallSupervisor(0xd25b);
  return ZEXT816(0x1f);
}



// -[YTMainAppControlsOverlayView ytlDiscordButton], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b2d0. FUN_0004b2d0 */

void FUN_0004b2d0(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b2d0);
  return;
}



// -[YTMainAppControlsOverlayView setYtlDiscordButton:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b2dc. FUN_0004b2dc */

undefined1  [16] FUN_0004b2dc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  
  _objc_setAssociatedObject(param_1,FUN_0004b2d0,param_3,1);
  CallSupervisor(0x6313);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTMainAppControlsOverlayView ytlSbButton], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b314. FUN_0004b314 */

void FUN_0004b314(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b314);
  return;
}



// -[YTMainAppControlsOverlayView setYtlSbButton:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b320. FUN_0004b320 */

undefined1  [16] FUN_0004b320(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  
  _objc_setAssociatedObject(param_1,FUN_0004b314,param_3,1);
  CallSupervisor(0x8b20);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTMainAppControlsOverlayView ytlButtonsTopAnchor], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b358. FUN_0004b358 */

void FUN_0004b358(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b358);
  return;
}



// -[YTMainAppControlsOverlayView setYtlButtonsTopAnchor:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b364. FUN_0004b364 */

undefined1  [16] FUN_0004b364(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  
  _objc_setAssociatedObject(param_1,FUN_0004b358,param_3,1);
  CallSupervisor(0xaaa1);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTMainAppControlsOverlayView ytlButtonsTrailingAnchor], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b39c. FUN_0004b39c */

void FUN_0004b39c(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b39c);
  return;
}



// -[YTMainAppControlsOverlayView setYtlButtonsTrailingAnchor:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b3a8. FUN_0004b3a8 */

void FUN_0004b3a8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  _objc_setAssociatedObject(param_1,FUN_0004b39c,param_3,1);
  return;
}



// -[YTMainAppControlsOverlayView ytlButtonsFSTopAnchor], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b3b8. FUN_0004b3b8 */

void FUN_0004b3b8(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b3b8);
  return;
}



// -[YTMainAppControlsOverlayView setYtlButtonsFSTopAnchor:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b3c4. FUN_0004b3c4 */

undefined1  [16] FUN_0004b3c4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  _objc_setAssociatedObject(param_1,FUN_0004b3b8,param_3,1);
  CallSupervisor(0x851c);
  return ZEXT816(0x1f);
}



// -[YTMainAppControlsOverlayView ytlButtonsFSTrailingAnchor], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b3fc. FUN_0004b3fc */

void FUN_0004b3fc(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004b3fc);
  return;
}



// -[YTMainAppControlsOverlayView setYtlButtonsFSTrailingAnchor:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4b408. FUN_0004b408 */

undefined1  [16] FUN_0004b408(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  _objc_setAssociatedObject(param_1,FUN_0004b3fc,param_3,1);
  CallSupervisor(0x99b9);
  return ZEXT816(0x1f);
}



// -[YTMainAppControlsOverlayView initWithDelegate:], original IMP slot 0x01226220
/* Decompiled from supplied 5.2.2 arm package. VA 0x71838. FUN_00071838 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00071838(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  long lVar13;
  double dVar14;
  undefined1 auStack_120 [32];
  undefined *puStack_100;
  undefined *puStack_f8;
  undefined *puStack_f0;
  undefined *puStack_e8;
  undefined *puStack_e0;
  undefined1 *puStack_d8;
  undefined1 *puStack_d0;
  undefined *puStack_c8;
  undefined *puStack_c0;
  undefined8 uStack_b8;
  undefined **local_b0;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  undefined8 local_70;
  
  puStack_d8 = (undefined1 *)&puStack_100;
  local_70 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0117baf8;
  local_7c = (uint)(DAT_01226b8c == 0);
  local_90 = &PTR_LAB_0117bb18;
  ppuStack_88 = &PTR_LAB_01175340;
  local_a0 = &PTR_LAB_0117bb30;
  local_b0 = &PTR_LAB_01175340;
  DAT_01226b8c = 1;
  puStack_d0 = auStack_120;
  uVar7 = (*_DAT_01226220)();
  puVar5 = PTR_YTLHelper_0114ed50;
  puVar1 = @selector(ytl_defaultBundle);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(localizedStringForKey:value:table:);
  _objc_msgSend(uVar8,@selector(localizedStringForKey:value:table:),
                @"SpeedButton",0,0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(systemImageNamed:);
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,@selector(systemImageNamed:),
                @"plus");
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puVar4 = @selector(createYTQTMButton:accessibilityLabel:buttonLabel:icon:selector:);
  _objc_msgSend(puVar5,@selector(createYTQTMButton:accessibilityLabel:buttonLabel:icon:selector:),uVar7,uVar9,0,uVar10,
                @selector(speedValuePlus:));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(setSpeedPlus:),uVar11);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar5 = PTR_YTLHelper_0114ed50;
  puStack_c8 = puVar1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puStack_c0 = puVar2;
  _objc_msgSend(uVar8,puVar2,@"SpeedButton",0,0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,puVar3,
                @"minus");
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar5,puVar4,uVar7,uVar9,0,uVar10,@selector(speedValueMinus:));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(setSpeedMinus:),uVar11);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar3 = PTR_YTLHelper_0114ed50;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar2,@"SpeedButton",0,0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar1 = PTR__OBJC_CLASS___NSNumber_0114eb00;
  dVar14 = (double)_objc_msgSend(PTR_YTPSpeedMaster_0114eca0,@selector(currentPlaybackRate));
  _objc_msgSend((float)dVar14,puVar1,@selector(numberWithFloat:));
  uVar10 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_000d99ec(puVar2,@selector(stringWithFormat:),
                     &PTR____CFConstantStringClassReference_01164020,uVar10);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar3,puVar4,uVar7,uVar9,uVar11,0,@selector(resetSpeedValue:));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(setSpeedValue:),uVar12);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  uVar8 = _objc_alloc(PTR__OBJC_CLASS___UILongPressGestureRecognizer_0114ed30);
  uVar8 = _objc_msgSend(uVar8,@selector(initWithTarget:action:),uVar7,
                        @selector(showSpeedControl:));
  _objc_msgSend(DAT_00c4c300,uVar8,@selector(setMinimumPressDuration:));
  puVar1 = @selector(speedValue);
  _objc_msgSend(uVar7,@selector(speedValue));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  uStack_b8 = uVar8;
  _objc_msgSend(uVar9,@selector(addGestureRecognizer:),uVar8);
  _objc_release(uVar9);
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,@selector(defaultCenter));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,@selector(addObserver:selector:name:object:),uVar7,
                @selector(speedDidChange:),@"YTPSpeedDidChange",0);
  _objc_release(uVar8);
  uVar8 = _objc_alloc(PTR__OBJC_CLASS___UIStackView_0114ec10);
  _objc_msgSend(uVar7,@selector(speedPlus));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar6 = puStack_d8;
  *(undefined8 *)(puStack_d8 + -0x20) = uVar9;
  _objc_msgSend(uVar7,puVar1);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar6 + -0x18) = uVar10;
  _objc_msgSend(uVar7,@selector(speedMinus));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar6 + -0x10) = uVar11;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),puStack_d0
                ,3);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  uVar8 = _objc_msgSend(uVar8,@selector(initWithArrangedSubviews:),uVar12);
  _objc_msgSend(uVar7,@selector(setSpeedControls:),uVar8);
  _objc_release(uVar8);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(blackColor));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(DAT_00c4c308,uVar8,@selector(colorWithAlphaComponent:));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(speedControls);
  _objc_msgSend(uVar7,@selector(speedControls));
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,@selector(setBackgroundColor:),uVar9);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_msgSend(uVar7,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puStack_d0 = @selector(setAxis:);
  _objc_msgSend(uVar8,@selector(setAxis:),1);
  _objc_release(uVar8);
  _objc_msgSend(uVar7,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puStack_d8 = @selector(setDistribution:);
  _objc_msgSend(uVar8,@selector(setDistribution:),1);
  _objc_release(uVar8);
  _objc_msgSend(uVar7,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar4 = @selector(setAlignment:);
  _objc_msgSend(uVar8,@selector(setAlignment:),3);
  _objc_release(uVar8);
  _objc_msgSend(uVar7,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,@selector(setClipsToBounds:),1);
  _objc_release(uVar8);
  _objc_msgSend(uVar7,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,@selector(layer));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4034000000000000,uVar9,@selector(setCornerRadius:));
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_msgSend(uVar7,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar5 = @selector(setTag:);
  _objc_msgSend(uVar8,@selector(setTag:),999);
  _objc_release(uVar8);
  _objc_msgSend(uVar7,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(setTranslatesAutoresizingMaskIntoConstraints:);
  _objc_msgSend(uVar8,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
  _objc_release(uVar8);
  _objc_msgSend(uVar7,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puStack_100 = @selector(addSubview:);
  _objc_msgSend(uVar7,@selector(addSubview:),uVar8);
  _objc_release(uVar8);
  _objc_msgSend(uVar7,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(centerYAnchor);
  _objc_msgSend(uVar8,@selector(centerYAnchor));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar2);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puStack_f8 = @selector(constraintEqualToAnchor:);
  _objc_msgSend(uVar9,@selector(constraintEqualToAnchor:),uVar10);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(setActive:);
  _objc_msgSend(uVar11,@selector(setActive:),1);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_msgSend(uVar7,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(leadingAnchor);
  _objc_msgSend(uVar8,@selector(leadingAnchor));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(safeAreaLayoutGuide));
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puStack_e8 = puVar3;
  _objc_msgSend(uVar10,puVar3);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puStack_f0 = @selector(constraintEqualToAnchor:constant:);
  _objc_msgSend(0x4024000000000000,uVar9,@selector(constraintEqualToAnchor:constant:),uVar11);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_e0 = puVar2;
  _objc_msgSend(uVar12,puVar2,1);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  uVar8 = _objc_alloc_init(PTR__OBJC_CLASS___UIStackView_0114ec10);
  _objc_msgSend(uVar7,@selector(setYtlButtons:),uVar8);
  _objc_release(uVar8);
  puVar2 = @selector(ytlButtons);
  _objc_msgSend(uVar7,@selector(ytlButtons));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puStack_d0,0);
  _objc_release(uVar8);
  _objc_msgSend(uVar7,puVar2);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puStack_d8,1);
  _objc_release(uVar8);
  _objc_msgSend(uVar7,puVar2);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar4,3);
  _objc_release(uVar8);
  _objc_msgSend(uVar7,puVar2);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4024000000000000,uVar8,@selector(setSpacing:));
  _objc_release(uVar8);
  _objc_msgSend(uVar7,puVar2);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar1,0);
  _objc_release(uVar8);
  puStack_d0 = puVar2;
  _objc_msgSend(uVar7,puVar2);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar5,0x3e6);
  _objc_release(uVar8);
  puVar3 = puStack_c8;
  puVar2 = PTR_YTLHelper_0114ed50;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_c8);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar4 = puStack_c0;
  _objc_msgSend(uVar8,puStack_c0,@"YTLButton",0,0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(ytPlus));
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(createOverlayButton:accessibilityLabel:buttonLabel:icon:selector:);
  _objc_msgSend(puVar2,@selector(createOverlayButton:accessibilityLabel:buttonLabel:icon:selector:),uVar7,uVar9,0,uVar10,
                @selector(handleYTLIconTap:));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(setYtlButton:),uVar11);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar2 = PTR_YTLHelper_0114ed50;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar4,@"YTLMuteButton",0,0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(volumeOn));
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,puVar1,uVar7,uVar9,0,uVar10,@selector(handleYTLMuteTap:));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(setYtlMuteButton:),uVar11);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar2 = PTR_YTLHelper_0114ed50;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar4,@"YTLLockButton",0,0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(lock));
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,puVar1,uVar7,uVar9,0,uVar10,@selector(handleYTLLockTap:));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(setYtlLockButton:),uVar11);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar2 = PTR_YTLHelper_0114ed50;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar4,@"YTLSbButton",0,0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sponsorblock));
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,puVar1,uVar7,uVar9,0,uVar10,@selector(handleYTLSbTap:));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(setYtlSbButton:),uVar11);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar2 = PTR_YTLHelper_0114ed50;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar4,@"YTLSleepButton",0,0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(moon));
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,puVar1,uVar7,uVar9,0,uVar10,@selector(handleYTLSleepTap:));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(setYtlSleepButton:),uVar11);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar2 = PTR_YTLHelper_0114ed50;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar4,@"YTLDiscordButton",0,0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(adaptiveDiscord));
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,puVar1,uVar7,uVar9,0,uVar10,@selector(handleYTLDiscordTap:));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(setYtlDiscordButton:),uVar11);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_msgSend(uVar7,@selector(topControlsAccessibilityContainerView));
  lVar13 = _objc_retainAutoreleasedReturnValue();
  uStack_94 = (uint)(lVar13 == 0);
                    /* WARNING: Could not recover jumptable at 0x00072f74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_90[uStack_94] + (int)-(DAT_0117bb28 ^ 0xcdb5b435)))();
  return;
}



// -[YTMainAppControlsOverlayView layoutSubviews], original IMP slot 0x01226228
/* Decompiled from supplied 5.2.2 arm package. VA 0x735a0. FUN_000735a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000735a0(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226b90 = 1;
  (*_DAT_01226228)(param_1);
  uVar1 = FUN_000dab14(@"hideOverlayTitle");
                    /* WARNING: Could not recover jumptable at 0x000740c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117bb70)[uVar1 & 0xffffffff] + (int)-(uRam000000000117bb80 ^ 0xb5a961d1)))()
  ;
  return;
}



// -[YTMainAppControlsOverlayView speedValueMinus:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x74860. FUN_00074860 */

undefined1  [16] FUN_00074860(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  double dVar4;
  undefined1 auVar5 [16];
  
  _objc_msgSend(param_1,@selector(eventsDelegate));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(resetAutoHideTimer));
  _objc_msgSend(param_1,@selector(_viewControllerForAncestor));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(parentViewController));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  dVar4 = (double)_objc_msgSend(PTR_YTPSpeedMaster_0114eca0,@selector(playbackRateForPlayer:),
                                uVar3);
  if (0.25 < dVar4) {
    _objc_msgSend((double)(float)(dVar4 + -0.25),PTR_YTPSpeedMaster_0114eca0,
                  @selector(setPlaybackRate:forPlayer:),uVar3);
  }
  _objc_release(uVar3);
  _objc_release(uVar1);
  CallSupervisor(0x56b3);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}



// -[YTMainAppControlsOverlayView speedValuePlus:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x749a0. FUN_000749a0 */

undefined1  [16] FUN_000749a0(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  double dVar4;
  undefined1 auVar5 [16];
  
  _objc_msgSend(param_1,@selector(eventsDelegate));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(resetAutoHideTimer));
  _objc_msgSend(param_1,@selector(_viewControllerForAncestor));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(parentViewController));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  dVar4 = (double)_objc_msgSend(PTR_YTPSpeedMaster_0114eca0,@selector(playbackRateForPlayer:),
                                uVar3);
  if (dVar4 < 5.0) {
    _objc_msgSend((double)(float)(dVar4 + 0.25),PTR_YTPSpeedMaster_0114eca0,
                  @selector(setPlaybackRate:forPlayer:),uVar3);
  }
  _objc_release(uVar3);
  _objc_release(uVar1);
  CallSupervisor(0xe330);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}



// -[YTMainAppControlsOverlayView resetSpeedValue:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x74ae0. FUN_00074ae0 */

undefined1  [16] FUN_00074ae0(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  DAT_01226b9c = 1;
  _objc_msgSend(param_1,@selector(eventsDelegate));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(resetAutoHideTimer));
  _objc_msgSend(0x3ff0000000000000,uVar1,@selector(setPlaybackRate:));
  _objc_msgSend(param_1,@selector(speedValue));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setTitle:forState:),
                &PTR____CFConstantStringClassReference_011645a0,0);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0x1f64);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}



// -[YTMainAppControlsOverlayView speedDidChange:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x74c3c. FUN_00074c3c */

undefined1  [16] FUN_00074c3c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  
  DAT_01226ba0 = 1;
  _objc_msgSend(param_3,@selector(object));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar5 = _objc_msgSend(uVar2,@selector(floatValue));
  _objc_release(uVar2);
  _objc_msgSend(param_1,@selector(speedValue));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR__OBJC_CLASS___NSString_0114eb38;
  _objc_msgSend(uVar5,PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithFloat:));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_000daff0(puVar1,@selector(stringWithFormat:),
                     &PTR____CFConstantStringClassReference_011645f0,uVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setTitle:forState:),uVar4,0);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0xce24);
  return ZEXT816(0x1f);
}



// -[YTMainAppControlsOverlayView showSpeedControl:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x74e0c. FUN_00074e0c */

undefined1  [16] FUN_00074e0c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  
  DAT_01226ba4 = 1;
  lVar2 = _objc_msgSend(param_3,@selector(state));
  if ((lVar2 == 1) &&
     (iVar1 = FUN_000db0cc((&PTR_LAB_0117bd58)[lVar2 == 1] +
                           (int)-(uRam000000000117bd68 ^ 0xec8590cc),
                           @"speedControls"), iVar1 != 0)) {
    _objc_msgSend(PTR_YTPSpeedPopupController_0114ed70,@selector(speedController));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,@selector(_viewControllerForAncestor));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(presentFromViewController:),uVar4);
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  CallSupervisor(0x58c7);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}



// -[YTMainAppControlsOverlayView handleYTLIconTap:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x75074. FUN_00075074 */

undefined1  [16] FUN_00075074(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auVar6 [16];
  
  puVar1 = @selector(_viewControllerForAncestor);
  DAT_01226ba8 = 1;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226890 == 0) {
    DAT_01226890 = _objc_getClass((&PTR_LAB_0117bdb0)[DAT_01226890 == 0] +
                                  (int)-(DAT_0117bdc0 ^ 0x1f546635),
                                  s_YTMainAppVideoPlayerOverlayViewC_011646a0);
  }
  lVar2 = DAT_01226890;
  _objc_retainAutorelease(DAT_01226890);
  iVar3 = FUN_000db114(uVar4,@selector(isKindOfClass:),lVar2);
  if (iVar3 == 0) {
    _objc_msgSend(param_1,@selector(eventsDelegate));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    uVar4 = uVar5;
  }
  _objc_msgSend(uVar4,@selector(parentViewController));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_DownloadMenuHelper_0114ed78,@selector(showDownloadSheet:withSender:),uVar5,
                param_3);
  _objc_release(param_3);
  _objc_release(uVar5);
  _objc_release(uVar4);
  CallSupervisor(0x14ae);
  auVar6._8_8_ = 0x1f;
  auVar6._0_8_ = 0x1a;
  return auVar6;
}



// -[YTMainAppControlsOverlayView handleYTLMuteTap:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x754cc. FUN_000754cc */

undefined1  [16] FUN_000754cc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined **ppuVar1;
  undefined *puVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 auVar10 [16];
  
  puVar2 = @selector(_viewControllerForAncestor);
  DAT_01226bac = 1;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226890 == 0) {
    DAT_01226890 = _objc_getClass((&PTR_LAB_0117be10)[DAT_01226890 == 0] +
                                  (int)-(DAT_0117be20 ^ 0x76153877),
                                  s_YTMainAppVideoPlayerOverlayViewC_01164700);
  }
  lVar3 = DAT_01226890;
  _objc_retainAutorelease(DAT_01226890);
  iVar4 = FUN_000db2c4(uVar6,@selector(isKindOfClass:),lVar3);
  if (iVar4 == 0) {
    _objc_msgSend(param_1,@selector(eventsDelegate));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    uVar6 = uVar7;
  }
  _objc_msgSend(uVar6,@selector(parentViewController));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(activeVideo));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  uVar5 = FUN_000db1fc(uVar8,@selector(isMuted));
  _objc_msgSend(uVar8,@selector(setMuted:),uVar5 ^ 1);
  ppuVar1 = &@selector(volumeOn);
  if (uVar5 == 0) {
    ppuVar1 = &@selector(volumeOff);
  }
  _objc_msgSend(PTR_YTPMedia_0114eae0,*ppuVar1);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,@selector(setImage:forState:),uVar9,0);
  _objc_release(param_3);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar6);
  CallSupervisor(0x5ad5);
  auVar10._8_8_ = 0x1f;
  auVar10._0_8_ = 0x1a;
  return auVar10;
}



// -[YTMainAppControlsOverlayView handleYTLLockTap:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x759c4. FUN_000759c4 */

undefined1  [16] FUN_000759c4(undefined8 param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  
  DAT_01226bb0 = 1;
  _objc_msgSend(param_1,@selector(_viewControllerForAncestor));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226890 == 0) {
    DAT_01226890 = _objc_getClass((&PTR_LAB_0117be70)[DAT_01226890 == 0] +
                                  (int)-(uRam000000000117be80 ^ 0xc2037588),
                                  s_YTMainAppVideoPlayerOverlayViewC_01164760);
  }
  lVar5 = DAT_01226890;
  _objc_retainAutorelease(DAT_01226890);
  iVar2 = FUN_000db30c(uVar3,@selector(isKindOfClass:),lVar5);
  if (iVar2 == 0) {
    _objc_msgSend(param_1,@selector(eventsDelegate));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar3);
    uVar3 = uVar4;
  }
  puVar1 = @selector(lockModeStateEntityController);
  _objc_msgSend(uVar3,@selector(lockModeStateEntityController));
  lVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar5 != 0) {
    _objc_msgSend(uVar3,@selector(lockModeDidRequestShowFullscreen));
    _objc_msgSend(uVar3,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(setLockModeActive:),1);
    _objc_release(uVar4);
  }
  _objc_release(uVar3);
  CallSupervisor(0x2738);
  return ZEXT816(0x1f);
}



// -[YTMainAppControlsOverlayView handleYTLSleepTap:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x75e88. FUN_00075e88 */

undefined1  [16] FUN_00075e88(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  
  puVar2 = PTR_YTPSleepTimer_0114eaf0;
  puVar1 = @selector(sharedTimer);
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(showOptions:),param_3);
  _objc_release(param_3);
  _objc_release(uVar3);
  CallSupervisor(0x4d72);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}



// -[YTMainAppControlsOverlayView handleYTLSbTap:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x75f14. FUN_00075f14 */

undefined1  [16] FUN_00075f14(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  undefined1 auVar9 [16];
  
  DAT_01226bb8 = 1;
  _objc_retain(param_3);
  _objc_msgSend(param_1,@selector(_viewControllerForAncestor));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226890 == 0) {
    DAT_01226890 = _objc_getClass((&PTR_LAB_0117bef0)[DAT_01226890 == 0] +
                                  (int)-(DAT_0117bf00 ^ 0x7dce4994),
                                  s_YTMainAppVideoPlayerOverlayViewC_01164920);
  }
  lVar8 = DAT_01226890;
  _objc_retainAutorelease(DAT_01226890);
  puVar1 = @selector(isKindOfClass:);
  iVar3 = FUN_000db74c(uVar5,@selector(isKindOfClass:),lVar8);
  if (iVar3 == 0) {
    _objc_msgSend(param_1,@selector(eventsDelegate));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    uVar5 = uVar6;
  }
  _objc_msgSend(uVar5,@selector(parentViewController));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226898 == 0) {
    DAT_01226898 = _objc_getClass((&PTR_LAB_0117bf30)[DAT_01226898 == 0] +
                                  (int)-(uRam000000000117bf40 ^ 0x50fa04af),
                                  s_YTPlayerViewController_011649a0);
  }
  lVar8 = DAT_01226898;
  _objc_retainAutorelease(DAT_01226898);
  uVar4 = FUN_000db67c(uVar6,puVar1,lVar8);
  puVar2 = @selector(playerResponse);
  puVar1 = @selector(respondsToSelector:);
  if (uVar4 != 0) {
    uVar4 = FUN_000db6e4(uVar6,@selector(respondsToSelector:),@selector(playerResponse));
    if (uVar4 != 0) {
      _objc_msgSend((&PTR_LAB_0117bf68)[uVar4] + (int)-(uRam000000000117bf78 ^ 0x6204af88),uVar6,
                    puVar2);
      lVar8 = _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x00076f88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      auVar9 = (*(code *)((&PTR_LAB_0117bf98)[lVar8 == 0] +
                         (int)-(uRam000000000117bfa8 ^ 0x34850606)))();
      return auVar9;
    }
    uVar7 = FUN_000db5f4(uVar6,puVar1,@selector(contentPlayerResponse));
                    /* WARNING: Could not recover jumptable at 0x00076f40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    auVar9 = (*(code *)((&PTR_LAB_0117bf80)[uVar7 & 0xffffffff] +
                       (int)-(uRam000000000117bf90 ^ 0x29716a49)))();
    return auVar9;
  }
  _objc_release((&PTR_LAB_0117bf50)[uVar4] + (int)-(uRam000000000117bf60 ^ 0xb799602),uVar6);
  _objc_release(uVar5);
  _objc_release(param_3);
  CallSupervisor(0xf993);
  auVar9._8_8_ = 0x1f;
  auVar9._0_8_ = 0x1a;
  return auVar9;
}



// -[YTMainAppControlsOverlayView setAutoplaySwitchButtonRenderer:], original IMP slot 0x01226230
/* Decompiled from supplied 5.2.2 arm package. VA 0x775a8. FUN_000775a8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000775a8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  DAT_01226bbc = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000db9b0(@"hideAutoplay");
  if (iVar1 == 0) {
    (*_DAT_01226230)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0xe862);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}



// -[YTMainAppControlsOverlayView setClosedCaptionsOrSubtitlesButtonAvailable:], original IMP slot 0x01226238
/* Decompiled from supplied 5.2.2 arm package. VA 0x77788. FUN_00077788 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_00077788(undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  undefined1 auVar2 [16];
  
  DAT_01226bc0 = 1;
  uVar1 = FUN_000db9d4(@"hideSubs");
  (*_DAT_01226238)(param_1,param_2,param_3 & (uVar1 ^ 0xffffffff));
  CallSupervisor(0x800);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}



// -[YTMainAppControlsOverlayView setOverlayVisible:], original IMP slot 0x01226240
/* Decompiled from supplied 5.2.2 arm package. VA 0x778f0. FUN_000778f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000778f0(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined *puVar9;
  double dVar10;
  
  DAT_01226bc4 = 1;
  uVar2 = FUN_000dba7c(@"downloadManager");
  puVar9 = (&PTR_LAB_0117c0b8)[uVar2] + (int)-(uRam000000000117c0c8 ^ 0xc5838616);
  if (uVar2 == 0) {
LAB_0007816c:
    uVar2 = FUN_000dbc9c(puVar9,@"ytlMuteButton");
    if ((uVar2 == 0) &&
       (iVar3 = FUN_000db9f8((&PTR_LAB_0117c0e8)[uVar2] + (int)-(uRam000000000117c0f8 ^ 0x837d19c),
                             @"ytlLockButton"), iVar3 == 0))
    goto LAB_00078210;
  }
  else {
    lVar4 = _ytpInt(puVar9,@"ytlButtonIndex");
    puVar9 = (&PTR_LAB_0117c0d0)[lVar4 == 0] + (int)-(uRam000000000117c0e0 ^ 0xa50aea73);
    if (lVar4 == 0) goto LAB_0007816c;
  }
  _objc_msgSend(param_1,@selector(ytlButtons));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend((double)(param_3 & 0xffffffff),uVar5,@selector(setAlpha:));
  _objc_release(uVar5);
LAB_00078210:
  iVar3 = FUN_000dbc54(@"speedControls");
  if (iVar3 != 0) {
    _objc_msgSend(param_1,@selector(speedControls));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend((double)(param_3 & 0xffffffff),uVar5,@selector(setAlpha:));
    _objc_release(uVar5);
    _objc_msgSend(param_1,@selector(speedValue));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR__OBJC_CLASS___NSString_0114eb38;
    puVar9 = PTR__OBJC_CLASS___NSNumber_0114eb00;
    dVar10 = (double)_objc_msgSend(PTR_YTPSpeedMaster_0114eca0,@selector(currentPlaybackRate));
    _objc_msgSend((float)dVar10,puVar9,@selector(numberWithFloat:));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_000dbbf8(puVar1,@selector(stringWithFormat:),
                       &PTR____CFConstantStringClassReference_01164e60,uVar6);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(setTitle:forState:),uVar7,0);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
  }
  (*_DAT_01226240)(param_1,param_2,param_3);
  uVar8 = FUN_000dbc78(@"pauseOnOverlay");
                    /* WARNING: Could not recover jumptable at 0x00078380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117c140)[uVar8 & 0xffffffff] + (int)-(uRam000000000117c150 ^ 0xf9f3b793)))()
  ;
  return;
}



// -[YTMainAppControlsOverlayView playbackRouteButton], original IMP slot 0x01226248
/* Decompiled from supplied 5.2.2 arm package. VA 0x7850c. FUN_0007850c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0007850c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226bc8 = 1;
  iVar1 = FUN_000dbce0(@"noCast");
  if (iVar1 == 0) {
    (*_DAT_01226248)(param_1,param_2);
    uVar2 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(param_1,@selector(setValue:forKey:),0,
                  @"_playbackRouteButton");
    uVar2 = 0;
  }
  _objc_autoreleaseReturnValue(uVar2);
  return;
}



// -[YTMainAppControlsOverlayView dealloc], original IMP slot 0x01226250
/* Decompiled from supplied 5.2.2 arm package. VA 0x787dc. FUN_000787dc */

void FUN_000787dc(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,@selector(defaultCenter));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(removeObserver:),param_1);
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00078848. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_01226250)(param_1,param_2);
  return;
}


