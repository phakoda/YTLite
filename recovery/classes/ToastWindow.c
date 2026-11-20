// Decompiled implementation evidence for ToastWindow. Not compilable source.

// -[ToastWindow hitTest:withEvent:], 0x1c7e28
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c7e28. hitTest:withEvent: */

/* Function Stack Size: 0x28 bytes */

ID ToastWindow::hitTest_withEvent_(ID param_1,SEL param_2,CGPoint param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  ID IVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IStack_1a0;
  undefined *puStack_198;
  ID IStack_190;
  undefined *puStack_188;
  ID IStack_180;
  undefined *puStack_178;
  undefined **local_168;
  undefined **local_158;
  uint uStack_14c;
  undefined **local_148;
  undefined **ppuStack_140;
  undefined **local_138;
  undefined **ppuStack_130;
  undefined **local_128;
  undefined **ppuStack_120;
  undefined **local_110;
  undefined **local_100;
  undefined **local_f0;
  undefined **local_e0;
  uint uStack_d4;
  undefined **local_d0;
  uint uStack_c4;
  undefined **local_c0;
  uint uStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  
  local_70 = &PTR_LAB_011b4b08;
  local_74 = (uint)(DAT_01227c54 == 0);
  local_88 = &PTR_LAB_011b4b28;
  local_a0 = &PTR__objc_msgSend_011b4b48;
  local_b0 = &PTR_LAB_011b4b60;
  local_c0 = &PTR_LAB_011b4b78;
  local_d0 = &PTR_LAB_011b4b90;
  local_e0 = &PTR_LAB_011b4ba8;
  local_f0 = &PTR_LAB_011b4bc0;
  local_100 = &PTR__objc_alloc_init_011b4bd8;
  local_110 = &PTR_LAB_011b4bf0;
  local_80 = &PTR_LAB_011b49f0;
  local_98 = &PTR_LAB_011b49f0;
  local_128 = &PTR_LAB_011b49f0;
  ppuStack_120 = &PTR_LAB_011b49f0;
  local_138 = &PTR_LAB_011b49f0;
  ppuStack_130 = &PTR_LAB_011b49f0;
  local_148 = &PTR__objc_msgSend_011b4c30;
  ppuStack_140 = &PTR_LAB_011b49f0;
  local_158 = &PTR__objc_alloc_init_011b4c48;
  local_168 = &PTR_LAB_011b49f0;
  DAT_01227c54 = 1;
  puStack_198 = PTR_ToastWindow_0114f0f0;
  IStack_1a0 = param_1;
  IStack_190 = param_1;
  _objc_msgSendSuper2(param_3.field0_0x0,param_3.field1_0x8,&IStack_1a0,
                      @selector(hitTest:withEvent:));
  _objc_retainAutoreleasedReturnValue();
  IVar3 = _objc_retain();
  puVar2 = @selector(_viewControllerForAncestor);
  puVar1 = @selector(isKindOfClass:);
  uStack_8c = (uint)(IVar3 == 0);
  IStack_180 = IVar3;
  if (IVar3 != 0) {
    puStack_178 = @selector(class);
    puStack_188 = @selector(superview);
    uVar4 = _objc_msgSend(PTR_ToastView_0114ec98,@selector(class));
    uStack_a4 = FUN_001c971c(IVar3,puVar1,uVar4);
    if (uStack_a4 == 0) {
      _objc_msgSend(local_a0[uStack_a4] + (int)-(uRam00000000011b4b58 ^ 0x4906b865),IVar3,puVar2);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      uVar5 = _NSClassFromString(@"YTActionSheetDialogViewController");
      uStack_b4 = FUN_001c95e4(uVar4,puVar1,uVar5);
      if (uStack_b4 == 0) {
        _objc_msgSend(local_b0[uStack_b4] + (int)-(uRam00000000011b4b70 ^ 0x60a44e0),IVar3,puVar2);
        uVar5 = _objc_retainAutoreleasedReturnValue();
        uVar6 = _NSClassFromString(@"YTDefaultSheetController");
        uStack_c4 = FUN_001c964c(uVar5,puVar1,uVar6);
        if (uStack_c4 == 0) {
          _objc_msgSend(IVar3,puVar2);
          uVar4 = _objc_retainAutoreleasedReturnValue();
          uVar5 = _NSClassFromString(@"YTActionSheetDialogViewController");
          uStack_d4 = FUN_001c953c(uVar4,puVar1,uVar5);
                    /* WARNING: Could not recover jumptable at 0x001c87f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          IVar3 = (*(code *)(local_d0[uStack_d4] + (int)-(uRam00000000011b4ba0 ^ 0x87dab333)))();
          return IVar3;
        }
        _objc_release(local_c0[uStack_c4] + (int)-(uRam00000000011b4b88 ^ 0x46256e23),uVar5);
      }
      _objc_release(uVar4);
      uStack_14c = (uint)(IStack_180 == IStack_190);
                    /* WARNING: Could not recover jumptable at 0x001c8a5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar3 = (*(code *)(local_148[uStack_14c] + (int)-(uRam00000000011b4c40 ^ 0x2c33df6)))();
      return IVar3;
    }
  }
  uStack_14c = (uint)(IStack_180 == IStack_190);
                    /* WARNING: Could not recover jumptable at 0x001c89f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar3 = (*(code *)(local_148[uStack_14c] + (int)-(uRam00000000011b4c40 ^ 0x2c33df6)))();
  return IVar3;
}



// -[ToastWindow initWithWindowScene:], 0x1c8b10
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c8b10. initWithWindowScene: */

/* Function Stack Size: 0x18 bytes */

ID ToastWindow::initWithWindowScene_(ID param_1,SEL param_2,ID param_3)

{
  ID IVar1;
  undefined8 uVar2;
  ID local_40;
  undefined *puStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011b4c68;
  puStack_38 = PTR_ToastWindow_0114f0f0;
  local_40 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_40,@selector(initWithWindowScene:));
  local_2c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    _objc_msgSend(*(double *)PTR__UIWindowLevelAlert_010605e0 + -1.0,IVar1,
                  @selector(setWindowLevel:));
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(clearColor));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar1,@selector(setBackgroundColor:),uVar2);
    _objc_release(uVar2);
  }
  return IVar1;
}



// -[ToastWindow canBecomeKeyWindow], 0x1c8c00
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c8c00. canBecomeKeyWindow */

/* Function Stack Size: 0x10 bytes */

bool ToastWindow::canBecomeKeyWindow(ID param_1,SEL param_2)

{
  return 0;
}



// -[ToastWindow makeKeyAndVisible], 0x1c8c08
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c8c08. makeKeyAndVisible */

/* Function Stack Size: 0x10 bytes */

void ToastWindow::makeKeyAndVisible(ID param_1,SEL param_2)

{
  ID local_40;
  undefined *puStack_38;
  int local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011b4c88;
  puStack_38 = PTR_ToastWindow_0114f0f0;
  local_40 = param_1;
  _objc_msgSendSuper2(&local_40,@selector(makeKeyAndVisible));
  local_2c = FUN_001c984c(param_1,@selector(isKeyWindow));
  if (local_2c != 0) {
    _objc_msgSend(param_1,@selector(resignKeyWindow));
  }
  CallSupervisor(0x5907);
  return;
}



// -[ToastWindow shouldAffectStatusBarAppearance], 0x1c8cc4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c8cc4. shouldAffectStatusBarAppearance */

/* Function Stack Size: 0x10 bytes */

bool ToastWindow::shouldAffectStatusBarAppearance(ID param_1,SEL param_2)

{
  return 0;
}



// -[ToastWindow _windowControlsStatusBarOrientation], 0x1c8ccc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c8ccc. _windowControlsStatusBarOrientation */

/* Function Stack Size: 0x10 bytes */

bool ToastWindow::_windowControlsStatusBarOrientation(ID param_1,SEL param_2)

{
  return 0;
}



// -[ToastWindow _canBecomeKeyWindow], 0x1c8cd4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c8cd4. _canBecomeKeyWindow */

/* Function Stack Size: 0x10 bytes */

bool ToastWindow::_canBecomeKeyWindow(ID param_1,SEL param_2)

{
  return 0;
}



// -[ToastWindow appKeyWindow], 0x1c8cdc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c8cdc. appKeyWindow */

/* Function Stack Size: 0x10 bytes */

ID ToastWindow::appKeyWindow(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  ID IVar6;
  undefined8 local_140;
  undefined8 *puStack_138;
  long *plStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  uint local_fc;
  undefined **local_f8;
  undefined1 auStack_f0 [128];
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_f8 = &PTR_LAB_011b4ca8;
  puStack_138 = (undefined8 *)0x0;
  local_140 = 0;
  uStack_128 = 0;
  plStack_130 = (long *)0x0;
  uStack_118 = 0;
  local_120 = 0;
  uStack_108 = 0;
  uStack_110 = 0;
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(windows));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  lVar4 = _objc_msgSend(uVar3,@selector(countByEnumeratingWithState:objects:count:),&local_140,auStack_f0,
                        0x10);
  puVar1 = @selector(isKeyWindow);
  local_fc = (uint)(lVar4 == 0);
  if (lVar4 != 0) {
    if (*plStack_130 != *plStack_130) {
      _objc_enumerationMutation
                ((&PTR_LAB_011b4cd0)[*plStack_130 == *plStack_130] +
                 (int)-(uRam00000000011b4ce0 ^ 0xc2542f69),uVar3);
    }
    uVar5 = FUN_001c9934(*puStack_138,puVar1);
                    /* WARNING: Could not recover jumptable at 0x001c8f00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar6 = (*(code *)((&PTR_LAB_011b4cf0)[uVar5 & 0xffffffff] +
                      (int)-(uRam00000000011b4d00 ^ 0x7fb08900)))();
    return IVar6;
  }
  _objc_release(local_f8[local_fc] + (int)-(DAT_011b4cb8 ^ 0x291ef60f),uVar3);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(0);
  return IVar6;
}



// +[ToastWindow initialize], 0x1c8fb4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1c8fb4. initialize */

/* Function Stack Size: 0x10 bytes */

void ToastWindow::initialize(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined **ppuStack_90;
  undefined **ppuStack_88;
  undefined **ppuStack_80;
  undefined **ppuStack_78;
  undefined **ppuStack_70;
  undefined **local_60;
  uint local_54;
  undefined **local_50;
  long local_48;
  
  local_48 = *(long *)PTR____stack_chk_guard_01060708;
  local_50 = &PTR_LAB_011b4d40;
  local_54 = (uint)(DAT_01227c74 == 0);
  local_60 = &PTR_LAB_011b49f0;
  DAT_01227c74 = 1;
  ppuStack_90 = @"_can";
  ppuStack_88 = @"Affect";
  ppuStack_80 = @"Status";
  ppuStack_78 = @"Bar";
  ppuStack_70 = @"Appearance";
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                &ppuStack_90,5);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(componentsJoinedByString:),&cf___);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  uVar3 = _NSSelectorFromString(uVar4);
  uVar5 = _class_getInstanceMethod(param_1,@selector(shouldAffectStatusBarAppearance));
  uVar6 = _method_getImplementation();
  uVar5 = _method_getTypeEncoding(uVar5);
  FUN_001c9a18(param_1,uVar3,uVar6,uVar5);
  puVar2 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar1 = @selector(canBecomeKeyWindow);
  _NSStringFromSelector(@selector(canBecomeKeyWindow));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_001c9a4c(puVar2,@selector(stringWithFormat:),
                     @"_%@",uVar3);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  uVar3 = _NSSelectorFromString(uVar5);
  uVar6 = _class_getInstanceMethod(param_1,puVar1);
  uVar7 = _method_getImplementation();
  uVar6 = _method_getTypeEncoding(uVar6);
  FUN_001c9b08(param_1,uVar3,uVar7,uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  CallSupervisor(0xdb6a);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


