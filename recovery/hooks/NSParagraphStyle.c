// Decompiled hook evidence for NSParagraphStyle. This is not compilable Logos source.

// +[NSParagraphStyle defaultWritingDirectionForLanguage:], original IMP slot 0x012267f8
/* Decompiled from supplied 5.2.2 arm package. VA 0xba9bc. FUN_000ba9bc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000ba9bc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226f04 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000eaffc(@"disableRTL");
  if (iVar1 == 0) {
    uVar2 = (*_DAT_012267f8)(param_1,param_2,param_3);
  }
  else {
    uVar2 = 0;
  }
  _objc_release(param_3);
  return uVar2;
}



// +[NSParagraphStyle _defaultWritingDirection], original IMP slot 0x01226800
/* Decompiled from supplied 5.2.2 arm package. VA 0xbab78. FUN_000bab78 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000bab78(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226f08 = 1;
  iVar1 = FUN_000eb020(@"disableRTL");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000bad08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226800)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


