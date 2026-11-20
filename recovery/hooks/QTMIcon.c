// Decompiled hook evidence for QTMIcon. This is not compilable Logos source.

// +[QTMIcon imageWithName:color:], original IMP slot 0x12258e0
/* Decompiled from supplied 5.2.2 arm package. VA 0xd508. FUN_0000d508 */

void FUN_0000d508(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_01225930 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  iVar1 = FUN_000114b0(param_3,@selector(isEqualToString:),
                       @"youtube_outline/moon_z_24pt");
  if (iVar1 == 0) {
    (*pcRam00000000012258e0)(param_1,param_2,param_3,param_4);
    uVar2 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(imageWithName:tintColor:),
                  @"moon",param_4);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar3);
  }
  _objc_release(param_4);
  _objc_release(param_3);
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return;
}



// +[QTMIcon imageWithName:color:], original IMP slot 0x01225ff8
/* Decompiled from supplied 5.2.2 arm package. VA 0x65fbc. FUN_00065fbc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00065fbc(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined *puVar1;
  ulong uVar2;
  
  DAT_01226a6c = 1;
  _objc_retain(param_3);
  puVar1 = @selector(isEqualToString:);
  _objc_retain(param_4);
  uVar2 = FUN_000d6d58(param_3,puVar1,@"youtube_outline/moon_z_24pt");
  (*_DAT_01225ff8)(param_1,param_2,param_3,param_4);
  _objc_retainAutoreleasedReturnValue();
  _objc_release(param_4);
                    /* WARNING: Could not recover jumptable at 0x0006628c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR__objc_msgSend_0117aa60)[uVar2 & 0xffffffff] +
            (int)-(uRam000000000117aa70 ^ 0xeb5ff2af)))();
  return;
}


