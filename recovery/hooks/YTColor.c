// Decompiled hook evidence for YTColor. This is not compilable Logos source.

// +[YTColor black0], original IMP slot 0x01226268
/* Decompiled from supplied 5.2.2 arm package. VA 0x7cca4. FUN_0007cca4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0007cca4(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226bd8 = 1;
  iVar1 = FUN_000dc9b4(@"oledTheme");
  if (iVar1 == 0) {
    (*_DAT_01226268)(param_1,param_2);
    _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(param_1,@selector(blackPure));
    _objc_retainAutoreleasedReturnValue();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}



// +[YTColor black1], original IMP slot 0x01226270
/* Decompiled from supplied 5.2.2 arm package. VA 0x7ce48. FUN_0007ce48 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0007ce48(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226bdc = 1;
  iVar1 = FUN_000dc9f8(@"oledTheme");
  if (iVar1 == 0) {
    (*_DAT_01226270)(param_1,param_2);
    _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(param_1,@selector(blackPure));
    _objc_retainAutoreleasedReturnValue();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}



// +[YTColor black2], original IMP slot 0x01226278
/* Decompiled from supplied 5.2.2 arm package. VA 0x7cff8. FUN_0007cff8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0007cff8(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226be0 = 1;
  iVar1 = FUN_000dca3c(@"oledTheme");
  if (iVar1 == 0) {
    (*_DAT_01226278)(param_1,param_2);
    _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(param_1,@selector(blackPure));
    _objc_retainAutoreleasedReturnValue();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}



// +[YTColor black3], original IMP slot 0x01226280
/* Decompiled from supplied 5.2.2 arm package. VA 0x7d1a4. FUN_0007d1a4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0007d1a4(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226be4 = 1;
  iVar1 = FUN_000dca60(@"oledTheme");
  if (iVar1 == 0) {
    (*_DAT_01226280)(param_1,param_2);
    _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(param_1,@selector(blackPure));
    _objc_retainAutoreleasedReturnValue();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}



// +[YTColor black4], original IMP slot 0x01226288
/* Decompiled from supplied 5.2.2 arm package. VA 0x7d350. FUN_0007d350 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0007d350(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226be8 = 1;
  iVar1 = FUN_000dcac4(@"oledTheme");
  if (iVar1 == 0) {
    (*_DAT_01226288)(param_1,param_2);
    _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(param_1,@selector(blackPure));
    _objc_retainAutoreleasedReturnValue();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}



// +[YTColor bgColorForPageStyle:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x7d4f8. FUN_0007d4f8 */

void FUN_0007d4f8(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(labelColor));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(&DAT_00c4c330 + (ulong)(param_3 == 0) * 8),uVar1,
                @selector(colorWithAlphaComponent:));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  _objc_autoreleaseReturnValue(uVar2);
  return;
}


