// Decompiled hook evidence for YTHUDMessageView. This is not compilable Logos source.

// -[YTHUDMessageView initWithMessage:dismissHandler:], original IMP slot 0x012267f0
/* Decompiled from supplied 5.2.2 arm package. VA 0xba7d4. FUN_000ba7d4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000ba7d4(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  
  DAT_01226f00 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  iVar2 = FUN_000eafd8(@"noHudMsgs");
  pcVar1 = _DAT_012267f0;
  if (iVar2 == 0) {
    uVar3 = _objc_retain(param_1);
    uVar3 = (*pcVar1)(uVar3,param_2,param_3,param_4);
  }
  else {
    uVar3 = 0;
  }
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_release(param_1);
  return uVar3;
}


