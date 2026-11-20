// Decompiled hook evidence for MDXSession. This is not compilable Logos source.

// -[MDXSession adPlaying:], original IMP slot 0x01226090
/* Decompiled from supplied 5.2.2 arm package. VA 0x678b4. FUN_000678b4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000678b4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  DAT_01226ab8 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000d6ff8(@"noAds");
  if (iVar1 == 0) {
    (*_DAT_01226090)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0x5045);
  return ZEXT816(0x1f);
}


