/* Decompiled from supplied 5.2.2 arm package. VA 0xd508. FUN_0000d508 */

void FUN_0000d508(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_01225930 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  iVar1 = FUN_000114b0(param_3,PTR_s_isEqualToString__0114ae48,
                       &PTR____CFConstantStringClassReference_01151920);
  if (iVar1 == 0) {
    (*pcRam00000000012258e0)(param_1,param_2,param_3,param_4);
    uVar2 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_imageWithName_tintColor__0114ae58,
                  &PTR____CFConstantStringClassReference_011518e0,param_4);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar3);
  }
  _objc_release(param_4);
  _objc_release(param_3);
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return;
}


