// Decompiled hook evidence for YTPivotBarItemView. This is not compilable Logos source.

// -[YTPivotBarItemView navigationButton], original IMP slot 0x01226798
/* Decompiled from supplied 5.2.2 arm package. VA 0xb8a9c. FUN_000b8a9c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000b8a9c(undefined8 param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  DAT_01226ed4 = 1;
  (*_DAT_01226798)(param_1);
  _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(_viewControllerForAncestor));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(renderer);
  _objc_msgSend(uVar3,@selector(renderer));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(description));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = FUN_000ea5f8(uVar5,@selector(containsString:),
                       @"_CAIRO");
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(sharedMedia));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,@selector(setCairo:),uVar6);
  _objc_release(uVar7);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_msgSend(param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(icon));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar2 = _objc_msgSend(uVar4,@selector(iconType));
  _objc_release(uVar4);
  _objc_release(uVar3);
                    /* WARNING: Could not recover jumptable at 0x000b8d6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01181eb0)[iVar2 == 0x36c] + (int)-(DAT_01181ec0 ^ 0x1dcdb1c1)))();
  return;
}



// -[YTPivotBarItemView setRenderer:], original IMP slot 0x012267a0
/* Decompiled from supplied 5.2.2 arm package. VA 0xb9568. FUN_000b9568 */

void FUN_000b9568(undefined8 param_1)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  DAT_01226ed8 = 1;
  (*DAT_012267a0)(param_1);
  _objc_msgSend(param_1,@selector(navigationButton));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar1 = FUN_000eacbc(@"removeLabels");
  _objc_msgSend(uVar2,@selector(setSizeWithPaddingAndInsets:),uVar1 ^ 1);
  _objc_release(uVar2);
  uVar3 = FUN_000ead00(@"removeLabels");
                    /* WARNING: Could not recover jumptable at 0x000b9754. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01181ff0)[uVar3 & 0xffffffff] + (int)-(DAT_01182000 ^ 0x83ede03)))();
  return;
}



// -[YTPivotBarItemView layoutSubviews], original IMP slot 0x012267a8
/* Decompiled from supplied 5.2.2 arm package. VA 0xb97bc. FUN_000b97bc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000b97bc(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226edc = 1;
  (*_DAT_012267a8)(param_1);
  uVar1 = FUN_000ead64(@"removeIndicators");
                    /* WARNING: Could not recover jumptable at 0x000b99a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01182030)[uVar1 & 0xffffffff] + (int)-(uRam0000000001182040 ^ 0xe2fbf059)))()
  ;
  return;
}


