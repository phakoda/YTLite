// Decompiled hook evidence for MDXPlaybackRouteButtonController. This is not compilable Logos source.

// -[MDXPlaybackRouteButtonController isPersistentCastIconEnabled], original IMP slot 0x012261b8
/* Decompiled from supplied 5.2.2 arm package. VA 0x6e65c. FUN_0006e65c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0006e65c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226b58 = 1;
  iVar1 = FUN_000d8a04(@"noCast");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0006e7ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_012261b8)(param_1,param_2);
    return uVar2;
  }
  return 0;
}



// -[MDXPlaybackRouteButtonController updateRouteButton:], original IMP slot 0x012261c0
/* Decompiled from supplied 5.2.2 arm package. VA 0x6e7c4. FUN_0006e7c4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0006e7c4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  DAT_01226b5c = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000d8a28(@"noCast");
  if (iVar1 == 0) {
    (*_DAT_012261c0)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0x646c);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}



// -[MDXPlaybackRouteButtonController updateAllRouteButtons], original IMP slot 0x012261c8
/* Decompiled from supplied 5.2.2 arm package. VA 0x6e950. FUN_0006e950 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0006e950(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226b60 = 1;
  iVar1 = FUN_000d8a4c(@"noCast");
  if (iVar1 == 0) {
    (*_DAT_012261c8)(param_1,param_2);
  }
  CallSupervisor(0xd22b);
  return ZEXT816(0x1f);
}


