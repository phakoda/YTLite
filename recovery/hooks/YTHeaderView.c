// Decompiled hook evidence for YTHeaderView. This is not compilable Logos source.

// -[YTHeaderView stickyNavHeaderEnabled], original IMP slot 0x01225f80
/* Decompiled from supplied 5.2.2 arm package. VA 0x506c4. FUN_000506c4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000506c4(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_01226a24 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  iVar1 = FUN_000d12f4(uVar2,@selector(boolForKey:),
                       @"stickyNavbar");
  if (iVar1 == 0) {
    uVar3 = (*_DAT_01225f80)(param_1,param_2);
  }
  else {
    uVar3 = 1;
  }
  _objc_release(uVar2);
  return uVar3;
}



// -[YTHeaderView clipsToStatusArea], original IMP slot 0x01225f88
/* Decompiled from supplied 5.2.2 arm package. VA 0x508c8. FUN_000508c8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000508c8(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_01226a28 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  iVar1 = FUN_000d133c(uVar2,@selector(boolForKey:),
                       @"stickyNavbar");
  if (iVar1 == 0) {
    uVar3 = (*_DAT_01225f88)(param_1,param_2);
  }
  else {
    uVar3 = 0;
  }
  _objc_release(uVar2);
  return uVar3;
}


