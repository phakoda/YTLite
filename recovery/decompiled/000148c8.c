/* Decompiled from supplied 5.2.2 arm package. VA 0x148c8. _replaceInfoDict */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _replaceInfoDict(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  pcVar1 = __orig_infoDictionary;
  DAT_01225b30 = 1;
  uVar2 = _objc_retain(param_1);
  (*pcVar1)(uVar2,param_2);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_mutableCopy_0114b010);
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_mainBundle_0114adf8);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = FUN_0001c5cc(param_1,PTR_s_isEqual__0114b060,uVar2);
  _objc_release(param_1);
  _objc_release(uVar2);
                    /* WARNING: Could not recover jumptable at 0x00014c84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01155000)[uVar3 & 0xffffffff] + (int)-(DAT_01155010 ^ 0x59d2ea6d)))();
  return;
}


