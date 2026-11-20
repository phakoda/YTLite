// Decompiled hook evidence for YTAppDelegate. This is not compilable Logos source.

// -[YTAppDelegate application:didFinishLaunchingWithOptions:], original IMP slot 0x01225fc8
/* Decompiled from supplied 5.2.2 arm package. VA 0x51d7c. FUN_00051d7c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00051d7c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226a48 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  iVar1 = FUN_000d1748(uVar2,@selector(boolForKey:),
                       @"autoClearCache");
  _objc_release(uVar2);
  if (iVar1 != 0) {
    _dispatch_get_global_queue(0,0);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _dispatch_async(uVar2,&PTR___NSConcreteGlobalBlock_01061a40);
    _objc_release(uVar2);
  }
  uVar2 = (*_DAT_01225fc8)(param_1,param_2,param_3,param_4);
  _objc_release(param_4);
  _objc_release(param_3);
  return uVar2;
}



// -[YTAppDelegate appDidBecomeActive], original IMP slot 0x01226820
/* Decompiled from supplied 5.2.2 arm package. VA 0xbb9ec. FUN_000bb9ec */

void FUN_000bb9ec(void)

{
  undefined8 uVar1;
  ulong uVar2;
  
  DAT_01226f18 = 1;
  (*DAT_01226820)();
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_000eb490(uVar1,@selector(boolForKey:),
                       @"autoCheckCb");
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x000bbfe8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01182440)[uVar2 & 0xffffffff] + (int)-(DAT_01182450 ^ 0xc23e043d)))();
  return;
}


