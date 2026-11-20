/* Decompiled from supplied 5.2.2 arm package. VA 0x6e590. FUN_0006e590 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0006e590(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_000d89a0(param_1,PTR_s_hasModalClientThrottlingRules_0114c660);
  if (iVar1 != 0) {
    _objc_msgSend(param_1,PTR_s_modalClientThrottlingRules_0114c668);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_setThrottledAfterRecentSignIn__0114c670,1);
    _objc_release(uVar2);
  }
                    /* WARNING: Could not recover jumptable at 0x0006e650. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_012261a0)(param_1,param_2);
  return;
}


