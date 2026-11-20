// Decompiled hook evidence for YTSettingsCell. This is not compilable Logos source.

// -[YTSettingsCell setDetailText:], original IMP slot 0x1225900
/* Decompiled from supplied 5.2.2 arm package. VA 0xf8d8. FUN_0000f8d8 */

undefined1  [16] FUN_0000f8d8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  DAT_01225940 = 1;
  uVar2 = _objc_retain(param_3);
  iVar1 = FUN_00011738(uVar2,@selector(isEqualToString:),
                       @"20.21.6");
  if (iVar1 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(mainBundle));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(infoDictionary));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(objectForKeyedSubscript:),
                  @"CFBundleShortVersionString");
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(param_3);
    _objc_release(uVar3);
    _objc_release(uVar2);
    param_3 = uVar4;
  }
  (*pcRam0000000001225900)(param_1,param_2,param_3);
  _objc_release(param_3);
  CallSupervisor(0x5d62);
  return ZEXT816(0x1f);
}


