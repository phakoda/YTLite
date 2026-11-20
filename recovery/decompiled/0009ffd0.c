/* Decompiled from supplied 5.2.2 arm package. VA 0x9ffd0. FUN_0009ffd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0009ffd0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  
  DAT_01226de0 = 1;
  lVar2 = _ytpInt(&PTR____CFConstantStringClassReference_0116c580);
  if ((lVar2 == 1) &&
     (iVar1 = FUN_000e50ac(param_1,PTR_s_respondsToSelector__0114af58,
                           PTR_s_reelContentViewRequestsAdvanceTo_0114b9c8), iVar1 != 0)) {
    uVar3 = _objc_msgSend(param_1,PTR_s_class_0114ae88);
    lVar2 = _class_getInstanceVariable(uVar3,s__isEngagementPanelVisible_0116c4c0);
                    /* WARNING: Could not recover jumptable at 0x000a05e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    auVar4 = (*(code *)((&PTR_LAB_0117fe60)[lVar2 == 0] + (int)-(DAT_0117fe70 ^ 0xe2cb3780)))();
    return auVar4;
  }
  (*_DAT_01226600)(param_1,param_2);
  CallSupervisor(0x25c6);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}


