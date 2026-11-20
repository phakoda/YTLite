// Decompiled hook evidence for YTHeaderContentComboView. This is not compilable Logos source.

// -[YTHeaderContentComboView enableSubheaderBarWithView:], original IMP slot 0x01225fa0
/* Decompiled from supplied 5.2.2 arm package. VA 0x50fe8. FUN_00050fe8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00050fe8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226a34 = 1;
  _objc_retain(param_3);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  iVar1 = FUN_000d1438(uVar2,@selector(boolForKey:),
                       @"noSubbar");
  _objc_release(uVar2);
  if (iVar1 == 0) {
    (*_DAT_01225fa0)(param_1,param_2,param_3);
  }
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}



// -[YTHeaderContentComboView setFeedHeaderScrollMode:], original IMP slot 0x01225fa8
/* Decompiled from supplied 5.2.2 arm package. VA 0x511ac. FUN_000511ac */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000511ac(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  DAT_01226a38 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_000d1480(uVar3,@selector(boolForKey:),
                       @"noSubbar");
  uVar1 = 0;
  if (iVar2 == 0) {
    uVar1 = param_3;
  }
  (*_DAT_01225fa8)(param_1,param_2,uVar1);
  _objc_release(uVar3);
  CallSupervisor(0xa02d);
  return ZEXT816(0x1f);
}


