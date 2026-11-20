// Decompiled hook evidence for YTInlinePlayerBarContainerView. This is not compilable Logos source.

// -[YTInlinePlayerBarContainerView sbTimeString], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x1dfc0. FUN_0001dfc0 */

void FUN_0001dfc0(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0001dfc0);
  return;
}



// -[YTInlinePlayerBarContainerView setSbTimeString:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x1dfcc. FUN_0001dfcc */

undefined1  [16] FUN_0001dfcc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  _objc_setAssociatedObject(param_1,FUN_0001dfc0,param_3,1);
  CallSupervisor(0x87b7);
  return ZEXT816(0x1f);
}



// -[YTInlinePlayerBarContainerView setPeekableViewVisible:], original IMP slot 0x01225c40
/* Decompiled from supplied 5.2.2 arm package. VA 0x20fd4. FUN_00020fd4 */

void FUN_00020fd4(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01225ce4 = 1;
  (*DAT_01225c40)(param_1);
  uVar1 = FUN_00022ec4(@"sponsorBlock");
                    /* WARNING: Could not recover jumptable at 0x00021300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01156590)[uVar1 & 0xffffffff] + (int)-(DAT_011565a0 ^ 0x7d8bdef8)))();
  return;
}



// -[YTInlinePlayerBarContainerView endTimeString], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4c9b4. FUN_0004c9b4 */

void FUN_0004c9b4(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_0004c9b4);
  return;
}



// -[YTInlinePlayerBarContainerView setEndTimeString:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x4c9c0. FUN_0004c9c0 */

undefined1  [16] FUN_0004c9c0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  
  _objc_setAssociatedObject(param_1,FUN_0004c9b4,param_3,1);
  CallSupervisor(0xaaca);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTInlinePlayerBarContainerView setPlayerBarAlpha:], original IMP slot 0x012264c0
/* Decompiled from supplied 5.2.2 arm package. VA 0x8e4e8. FUN_0008e4e8 */

undefined1  [16] FUN_0008e4e8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226d38 = 1;
  iVar1 = FUN_000e089c(@"persistentProgressBar");
  uVar2 = 0x3ff0000000000000;
  if (iVar1 == 0) {
    uVar2 = param_1;
  }
  (*DAT_012264c0)(uVar2,param_2,param_3);
  CallSupervisor(0x89db);
  return ZEXT816(0x1f);
}



// -[YTInlinePlayerBarContainerView setFrame:], original IMP slot 0x012264c8
/* Decompiled from supplied 5.2.2 arm package. VA 0x8e70c. FUN_0008e70c */

undefined1  [16]
FUN_0008e70c(undefined8 param_1,double param_2,double param_3,double param_4,undefined8 param_5,
            undefined8 param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined1 auVar9 [16];
  
  puVar2 = @selector(mainScreen);
  DAT_01226d3c = 1;
  dVar5 = param_3;
  dVar7 = param_4;
  _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,@selector(mainScreen));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(bounds);
  _objc_msgSend(uVar4,@selector(bounds));
  dVar6 = dVar5;
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar1);
  dVar8 = dVar7;
  _objc_release(uVar4);
  if (dVar7 <= dVar5) {
    dVar5 = dVar7;
  }
  if ((dVar5 < param_3) &&
     (iVar3 = FUN_000e09c0((&PTR_LAB_0117e2e8)[dVar5 < param_3] + (int)-(DAT_0117e2f8 ^ 0x594cb6eb),
                           @"noFullscreenActions"),
     puVar2 = @selector(superview), iVar3 != 0)) {
    _objc_msgSend(param_5,@selector(superview));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(safeAreaInsets));
    _objc_release(uVar4);
    _objc_msgSend(param_5,puVar2);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puVar1);
    _objc_release(uVar4);
    param_2 = ((dVar8 - dVar6) - param_4) + -10.0;
  }
  (*DAT_012264c8)(param_1,param_2,param_3,param_4,param_5,param_6);
  CallSupervisor(0x3054);
  auVar9._8_8_ = 0x1f;
  auVar9._0_8_ = 0x1a;
  return auVar9;
}



// -[YTInlinePlayerBarContainerView quietProgressBarColor], original IMP slot 0x012264d0
/* Decompiled from supplied 5.2.2 arm package. VA 0x8eaac. FUN_0008eaac */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0008eaac(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  DAT_01226d40 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(objectForKey:),@"progressMainColor");
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  puVar1 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  uVar2 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(class));
  _objc_msgSend(puVar1,@selector(unarchivedObjectOfClass:fromData:error:),uVar2,uVar3,0);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  lVar5 = _ytpInt(@"progressBarIndex");
  if (lVar5 != 0 && lVar4 != 0) {
    _objc_retain((&PTR_LAB_0117e340)[lVar5 != 0 && lVar4 != 0] +
                 (int)-(uRam000000000117e350 ^ 0xe9457ba3),lVar4);
    lVar5 = lVar4;
  }
  else {
    (*_DAT_012264d0)(param_1,param_2);
    lVar5 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_release(lVar4);
  _objc_release(uVar3);
  _objc_autoreleaseReturnValue(lVar5);
  return;
}



// -[YTInlinePlayerBarContainerView setPeekableViewVisible:], original IMP slot 0x012264d8
/* Decompiled from supplied 5.2.2 arm package. VA 0x8ee8c. FUN_0008ee8c */

void FUN_0008ee8c(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226d44 = 1;
  (*DAT_012264d8)(param_1);
  uVar1 = FUN_000e0b0c(@"videoEndTime");
                    /* WARNING: Could not recover jumptable at 0x0008f0b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117e388)[uVar1 & 0xffffffff] + (int)-(DAT_0117e398 ^ 0xb2fdade1)))();
  return;
}



// -[YTInlinePlayerBarContainerView didPressScrubber:], original IMP slot 0x012264e0
/* Decompiled from supplied 5.2.2 arm package. VA 0x8f31c. FUN_0008f31c */

void FUN_0008f31c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  DAT_01226d48 = 1;
  _objc_retain(param_3);
  (*DAT_012264e0)(param_1,param_2,param_3);
  _objc_msgSend(param_1,@selector(_viewControllerForAncestor));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(parentViewController));
  _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x0008f644. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117e3f8)[DAT_01226898 == 0] + (int)-(DAT_0117e408 ^ 0x1e9fc856)))();
  return;
}


