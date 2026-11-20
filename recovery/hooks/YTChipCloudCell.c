// Decompiled hook evidence for YTChipCloudCell. This is not compilable Logos source.

// -[YTChipCloudCell framesForChipViewsWithWidth:], original IMP slot 0x01225f90
/* Decompiled from supplied 5.2.2 arm package. VA 0x50ac4. FUN_00050ac4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00050ac4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  DAT_01226a2c = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar1 = FUN_000d13a8(uVar3,@selector(boolForKey:),
                       @"noSubbar");
  if (uVar1 == 0) {
    iVar2 = FUN_000d1360(@"hideInlineComment");
    _objc_release(uVar3);
    if (iVar2 == 0) {
      (*_DAT_01225f90)(param_1,param_2,param_3);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      goto LAB_00050de4;
    }
  }
  else {
    _objc_release((&PTR_LAB_0117a4c8)[uVar1] + (int)-(DAT_0117a4d8 ^ 0xde19938c),uVar3);
  }
  uVar3 = 0;
LAB_00050de4:
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar3);
  return;
}


