/* Decompiled from supplied 5.2.2 arm package. VA 0x194bdc. FUN_00194bdc */

void FUN_00194bdc(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = _objc_loadWeakRetained(param_1 + 0x20);
  _objc_msgSend(uVar1,PTR_s_requestSbSegments_0114daa0);
  _objc_release(uVar1);
  return;
}


