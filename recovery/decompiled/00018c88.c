/* Decompiled from supplied 5.2.2 arm package. VA 0x18c88. FUN_00018c88 */

void FUN_00018c88(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  DAT_01225ba4 = 1;
  if (_isYTPFirstTime != '\0') {
    _isYTPFirstTime = '\0';
    uVar1 = _objc_getClass(s_NSBundle_011542e9);
    _MSHookMessageEx(uVar1,PTR_s_infoDictionary_0114ae78,_replaceInfoDict,&_orig_infoDictionary);
  }
                    /* WARNING: Could not recover jumptable at 0x00018e28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000001225a48)(param_1,param_2);
  return;
}


