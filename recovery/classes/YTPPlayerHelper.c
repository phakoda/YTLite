// Decompiled implementation evidence for YTPPlayerHelper. Not compilable source.

// +[YTPPlayerHelper getVideoID:], 0x1f2660
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f2660. getVideoID: */

/* Function Stack Size: 0x18 bytes */

ID YTPPlayerHelper::getVideoID_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulong uVar7;
  ID IVar8;
  undefined8 uVar9;
  undefined1 auVar10 [16];
  
  DAT_01227f98 = 1;
  _objc_retain(param_3);
  puVar2 = @selector(class);
  uVar9 = 0;
  if (param_3 != 0) {
    uVar9 = _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,@selector(class));
    puVar1 = @selector(isKindOfClass:);
    uVar3 = FUN_001f3c98(param_3,@selector(isKindOfClass:),uVar9);
    if (uVar3 == 0) {
      uVar9 = _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,puVar2);
      iVar4 = FUN_001f3b70(param_3,puVar1,uVar9);
      uVar9 = 0;
      if (iVar4 == 0) goto LAB_001f29f8;
      _objc_msgSend(param_3,@selector(absoluteString));
      IVar8 = _objc_retainAutoreleasedReturnValue();
    }
    else {
      _objc_retain((&PTR_LAB_011bdb88)[uVar3] + (int)-(uRam00000000011bdb98 ^ 0x60f62f76),param_3);
      IVar8 = param_3;
    }
    _objc_msgSend(PTR__OBJC_CLASS___NSRegularExpression_0114ecb8,
                  @selector(regularExpressionWithPattern:options:error:),
                  @"/vi/([^/]+)/",0,0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar9 = _objc_msgSend(IVar8,@selector(length));
    _objc_msgSend(uVar5,@selector(firstMatchInString:options:range:),IVar8,0,0,uVar9);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar7 = _objc_msgSend(uVar6,@selector(numberOfRanges));
    if (uVar7 < 2) {
      uVar9 = 0;
    }
    else {
      auVar10 = _objc_msgSend(uVar6,@selector(rangeAtIndex:),1);
      _objc_msgSend(IVar8,@selector(substringWithRange:),auVar10._0_8_,auVar10._8_8_);
      uVar9 = _objc_retainAutoreleasedReturnValue();
    }
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(IVar8);
  }
LAB_001f29f8:
  _objc_release(param_3);
  IVar8 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar9);
  return IVar8;
}



// +[YTPPlayerHelper openVideoWithID:], 0x1f2a1c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f2a1c. openVideoWithID: */

/* Function Stack Size: 0x18 bytes */

void YTPPlayerHelper::openVideoWithID_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  ID IVar8;
  
  DAT_01227f9c = 1;
  _objc_retain(param_3);
  puVar2 = @selector(class);
  if (param_3 == 0) goto LAB_001f2de4;
  uVar5 = _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,@selector(class));
  puVar1 = @selector(isKindOfClass:);
  uVar3 = FUN_001f3d6c(param_3,@selector(isKindOfClass:),uVar5);
  if (uVar3 == 0) {
    uVar5 = _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,puVar2);
    iVar4 = FUN_001f3db4(param_3,puVar1,uVar5);
    IVar8 = 0;
    if (iVar4 != 0) {
      _objc_msgSend(param_3,@selector(absoluteString));
      IVar8 = _objc_retainAutoreleasedReturnValue();
      goto LAB_001f2cf0;
    }
  }
  else {
    _objc_retain((&PTR_LAB_011bdc28)[uVar3] + (int)-(uRam00000000011bdc38 ^ 0xfc07c4b0),param_3);
    IVar8 = param_3;
LAB_001f2cf0:
    lVar6 = _objc_msgSend(IVar8,@selector(length));
    puVar2 = PTR__OBJC_CLASS___NSURL_0114eb78;
    if (lVar6 != 0) {
      thunk_FUN_001f3cac(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                         @"vnd.youtube://%@",IVar8);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puVar2,@selector(URLWithString:),uVar5);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar5);
      _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,@selector(openURL:options:completionHandler:),uVar7,
                    *(undefined8 *)PTR____NSDictionary0___01060678,0);
      _objc_release(uVar5);
      _objc_release(uVar7);
    }
  }
  _objc_release(IVar8);
LAB_001f2de4:
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}



// +[YTPPlayerHelper openVideoWithID:handler:], 0x1f2dfc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f2dfc. openVideoWithID:handler: */

/* Function Stack Size: 0x20 bytes */

void YTPPlayerHelper::openVideoWithID_handler_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  DAT_01227fa0 = 1;
  _objc_retain(param_3);
  uVar3 = _objc_retain(param_4);
  puVar1 = @selector(valueForKey:);
  _objc_msgSend(uVar3,@selector(valueForKey:),@"_controller");
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(node));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  uVar3 = _objc_msgSend(param_4,@selector(class));
  lVar5 = _class_getInstanceVariable(uVar3,s__context_011bd8d2);
  if (lVar5 == 0) {
    _objc_msgSend(param_1,@selector(openVideoWithID:),param_3);
  }
  else {
    _objc_msgSend((&PTR_LAB_011bdcb0)[lVar5 == 0] + (int)-(uRam00000000011bdcc0 ^ 0xebb355cb),
                  param_4,puVar1,@"_context");
    uVar3 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(parentResponder);
    _objc_msgSend(uVar3,@selector(parentResponder));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar7 = _objc_getClass(s_YTElementsCellController_011bd8b0);
    uVar2 = FUN_001f3fbc(uVar6,@selector(isKindOfClass:),uVar7);
    _objc_release(uVar6);
    if (uVar2 == 0) {
      _objc_msgSend(param_1,@selector(openVideoWithID:),param_3);
    }
    else {
      _objc_msgSend((&PTR_LAB_011bdcd0)[uVar2] + (int)-(uRam00000000011bdce0 ^ 0x7a351179),uVar3,
                    puVar1);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      uVar7 = _objc_getClass(s_YTICommand_011bd8e6);
      _objc_msgSend(uVar7,@selector(watchNavigationEndpointWithVideoID:),param_3);
      lVar5 = _objc_retainAutoreleasedReturnValue();
      if (lVar5 == 0) {
        _objc_msgSend(param_1,@selector(openVideoWithID:),param_3);
      }
      else {
        uVar7 = _objc_getClass((&PTR_LAB_011bdcf0)[lVar5 == 0] +
                               (int)-(uRam00000000011bdd00 ^ 0x65faefad),
                               s_YTCommandResponderEvent_011bd930);
        _objc_msgSend(uVar4,@selector(view));
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,@selector(elementEntry));
        uVar9 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar7,@selector(eventWithCommand:fromView:entry:sendClick:firstResponder:),lVar5,uVar8,uVar9,0,
                      uVar6);
        uVar7 = _objc_retainAutoreleasedReturnValue();
        _objc_release(uVar9);
        _objc_release(uVar8);
        _objc_msgSend(uVar7,@selector(send));
        _objc_release(uVar7);
      }
      _objc_release(lVar5);
      _objc_release(uVar6);
    }
    _objc_release(uVar3);
  }
  _objc_release(uVar4);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x3cb8);
  return;
}



// +[YTPPlayerHelper openVideoWithID:viewController:], 0x1f3740
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f3740. openVideoWithID:viewController: */

/* Function Stack Size: 0x20 bytes */

void YTPPlayerHelper::openVideoWithID_viewController_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  
  DAT_01227fa4 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  uVar1 = _objc_getClass(s_YTICommand_011bda23);
  _objc_msgSend(uVar1,@selector(watchNavigationEndpointWithVideoID:),param_3);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 == 0) {
    _objc_msgSend(param_1,@selector(openVideoWithID:),param_3);
  }
  else {
    uVar1 = _objc_getClass((&PTR_LAB_011bdd48)[lVar2 == 0] +
                           (int)-(uRam00000000011bdd58 ^ 0x3073c2d7),
                           s_YTCommandResponderEvent_011bda00);
    _objc_msgSend(param_4,@selector(view));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,@selector(eventWithCommand:fromView:entry:sendClick:firstResponder:),lVar2,uVar3,param_4,0,
                  param_4);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar3);
    _objc_msgSend(uVar1,@selector(send));
    _objc_release(uVar1);
  }
  _objc_release(lVar2);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0xb65b);
  return;
}


