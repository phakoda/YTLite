// Decompiled hook evidence for LSBundleProxy. This is not compilable Logos source.

// -[LSBundleProxy bundleIdentifier], original IMP slot 0x01225a90
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ba30. FUN_0001ba30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001ba30(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  DAT_01225bcc = 1;
  (*_DAT_01225a90)();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(mainBundle));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(bundleIdentifier));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(stringByReplacingOccurrencesOfString:withString:),uVar3,
                @"com.google.ios.youtube");
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(uVar1);
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return;
}


