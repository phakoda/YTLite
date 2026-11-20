/* Decompiled from supplied 5.2.2 arm package. VA 0xcc72c. FUN_000cc72c */

void FUN_000cc72c(undefined8 param_1)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)PTR____stack_chk_guard_01060708;
  DAT_01227034 = 1;
  uVar1 = _objc_retain(param_1);
  lVar2 = _objc_msgSend(uVar1,PTR_s_length_0114b438);
  if (lVar2 == 0) {
    _objc_retain((&PTR_LAB_01183968)[lVar2 == 0] + (int)-(uRam0000000001183978 ^ 0x50de4622),param_1
                );
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSURLComponents_0114edc8,PTR_s_componentsWithString__0114cb20,
                  param_1);
    lVar2 = _objc_retainAutoreleasedReturnValue();
    if (lVar2 != 0) {
      _objc_msgSend(lVar2,PTR_s_queryItems_0114cb28);
      lVar2 = _objc_retainAutoreleasedReturnValue();
      _objc_release();
                    /* WARNING: Could not recover jumptable at 0x000cca04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((&PTR_LAB_011839a0)[lVar2 == 0] + (int)-(uRam00000000011839b0 ^ 0xfa5a5440)))();
      return;
    }
    _objc_retain((&PTR_LAB_01183988)[lVar2 == 0] + (int)-(uRam0000000001183998 ^ 0xa19d3c16),param_1
                );
    _objc_release(0);
  }
  _objc_release(param_1);
  if (*(long *)PTR____stack_chk_guard_01060708 == lVar3) {
    (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(param_1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


