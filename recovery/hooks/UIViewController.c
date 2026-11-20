// Decompiled hook evidence for UIViewController. This is not compilable Logos source.

// -[UIViewController presentViewController:animated:completion:], original IMP slot 0x01225f68
/* Decompiled from supplied 5.2.2 arm package. VA 0x4eb2c. FUN_0004eb2c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0004eb2c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226a18 = 1;
  _objc_retain(param_3);
  _objc_retain(param_5);
  uVar2 = _NSClassFromString(@"YTInterstitialElementsViewController");
  iVar1 = FUN_000d0f54(param_3,@selector(isKindOfClass:),uVar2);
  if (iVar1 == 0) {
    (*_DAT_01225f68)(param_1,param_2,param_3,param_4,param_5);
  }
  _objc_release(param_5);
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}



// -[UIViewController viewDidLoad], original IMP slot 0x01225f70
/* Decompiled from supplied 5.2.2 arm package. VA 0x4ee9c. FUN_0004ee9c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0004ee9c(undefined8 param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  
  DAT_01226a1c = 1;
  (*_DAT_01225f70)(param_1);
  uVar1 = _NSClassFromString(@"YTEngagementPanelViewControllerImpl");
  uVar2 = FUN_000d1084(param_1,@selector(isKindOfClass:),uVar1);
                    /* WARNING: Could not recover jumptable at 0x0004f9e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117a338)[uVar2 & 0xffffffff] + (int)-(uRam000000000117a348 ^ 0x935011e2)))()
  ;
  return;
}



// -[UIViewController viewDidDisappear:], original IMP slot 0x01225f78
/* Decompiled from supplied 5.2.2 arm package. VA 0x4fc10. FUN_0004fc10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0004fc10(undefined8 param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  
  DAT_01226a20 = 1;
  (*_DAT_01225f78)(param_1);
  uVar1 = _NSClassFromString(@"YTEngagementPanelViewControllerImpl");
  uVar2 = FUN_000d12ac(param_1,@selector(isKindOfClass:),uVar1);
                    /* WARNING: Could not recover jumptable at 0x000504f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117a3d0)[uVar2 & 0xffffffff] + (int)-(DAT_0117a3e0 ^ 0x250708f9)))();
  return;
}


