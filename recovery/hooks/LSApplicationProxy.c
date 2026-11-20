// Decompiled hook evidence for LSApplicationProxy. This is not compilable Logos source.

// -[LSApplicationProxy teamID], original IMP slot 0x01225a78
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b564. FUN_0001b564 */

undefined ** FUN_0001b564(void)

{
  DAT_01225bc0 = 1;
  return @"EQHXZ8M8AV";
}



// -[LSApplicationProxy appIDPrefix], original IMP slot 0x01225a80
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b688. FUN_0001b688 */

undefined ** FUN_0001b688(void)

{
  DAT_01225bc4 = 1;
  return @"EQHXZ8M8AV";
}



// -[LSApplicationProxy applicationIdentifier], original IMP slot 0x01225a88
/* Decompiled from supplied 5.2.2 arm package. VA 0x1b7b0. FUN_0001b7b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001b7b0(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  DAT_01225bc8 = 1;
  (*_DAT_01225a88)();
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


