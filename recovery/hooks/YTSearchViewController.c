// Decompiled hook evidence for YTSearchViewController. This is not compilable Logos source.

// -[YTSearchViewController viewDidLoad], original IMP slot 0x012261f0
/* Decompiled from supplied 5.2.2 arm package. VA 0x6fbb0. FUN_0006fbb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0006fbb0(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226b74 = 1;
  (*_DAT_012261f0)(param_1);
  uVar1 = FUN_000d8d7c(@"noVoiceSearchButton");
                    /* WARNING: Could not recover jumptable at 0x0006fef8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117b880)[uVar1 & 0xffffffff] + (int)-(uRam000000000117b890 ^ 0xe12b782d)))()
  ;
  return;
}



// -[YTSearchViewController setSuggestions:], original IMP slot 0x012261f8
/* Decompiled from supplied 5.2.2 arm package. VA 0x6ff6c. FUN_0006ff6c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0006ff6c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  DAT_01226b78 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000d8de0(@"noSearchHistory");
  if (iVar1 == 0) {
    (*_DAT_012261f8)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0xf88e);
  return ZEXT816(0x1f);
}


