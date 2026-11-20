// Decompiled hook evidence for YTIPivotBarRenderer. This is not compilable Logos source.

// -[YTIPivotBarRenderer backgroundStyle], original IMP slot 0x01225fb0
/* Decompiled from supplied 5.2.2 arm package. VA 0x51344. FUN_00051344 */

undefined4 FUN_00051344(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  DAT_01226a3c = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  iVar1 = FUN_000d14c8(uVar2,@selector(boolForKey:),
                       @"frostedPivot");
  if (iVar1 != 0) {
    uVar3 = 2;
  }
  _objc_release(uVar2);
  return uVar3;
}


