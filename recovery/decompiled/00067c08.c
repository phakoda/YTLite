/* Decompiled from supplied 5.2.2 arm package. VA 0x67c08. FUN_00067c08 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00067c08(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  
  DAT_01226ac0 = 1;
  _objc_msgSend(param_1,PTR_s_description_0114af00);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_000d71bc(uVar4,PTR_s_containsString__0114af08,
                       &PTR____CFConstantStringClassReference_01161ff0);
  puVar1 = PTR_s_hasCompatibilityOptions_0114c508;
  if (iVar2 == 0) {
    if (lRam0000000001226828 != 0) {
      uVar3 = FUN_000d71e4(param_1,PTR_s_respondsToSelector__0114af58,
                           PTR_s_hasCompatibilityOptions_0114c508);
      if ((uVar3 != 0) &&
         (iVar2 = FUN_000d712c((&PTR_LAB_0117aed0)[uVar3] +
                               (int)-(uRam000000000117aee0 ^ 0x8b96ba54),param_1,puVar1), iVar2 != 0
         )) {
        _objc_msgSend(param_1,PTR_s_compatibilityOptions_0114c510);
        uVar5 = _objc_retainAutoreleasedReturnValue();
        iVar2 = FUN_000d7174(uVar5,PTR_s_hasAdLoggingData_0114c518);
        _objc_release(uVar5);
        if (iVar2 != 0) goto LAB_00067fa8;
      }
    }
    (*_DAT_012260a0)(param_1,param_2);
    lVar6 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    if (lRam0000000001226828 == 0) {
      (*_DAT_012260a0)(param_1,param_2);
      lVar7 = _objc_retainAutoreleasedReturnValue();
      lVar6 = lRam0000000001226828;
      lRam0000000001226828 = lVar7;
      _objc_release(lVar6);
    }
LAB_00067fa8:
    lVar6 = lRam0000000001226828;
    _objc_retain(lRam0000000001226828);
  }
  _objc_release(uVar4);
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(lVar6);
  return;
}


