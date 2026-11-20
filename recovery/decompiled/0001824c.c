/* Decompiled from supplied 5.2.2 arm package. VA 0x1824c. FUN_0001824c */

void FUN_0001824c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined **ppuVar5;
  
  DAT_01225b80 = 1;
  uVar4 = _objc_retain(param_3);
  puVar1 = PTR_s_isEqualToString__0114ae48;
  uVar2 = FUN_0001d19c(uVar4,PTR_s_isEqualToString__0114ae48,
                       &PTR____CFConstantStringClassReference_01154260);
  ppuVar5 = &PTR____CFConstantStringClassReference_01154160;
  if (uVar2 == 0) {
    uVar2 = FUN_0001d14c((&PTR_LAB_01155208)[uVar2] + (int)-(uRam0000000001155218 ^ 0x55d06a16),
                         param_3,puVar1,&PTR____CFConstantStringClassReference_01154220);
    ppuVar5 = &PTR____CFConstantStringClassReference_011541a0;
    if ((uVar2 == 0) &&
       (iVar3 = FUN_0001d174((&PTR_LAB_01155220)[uVar2] + (int)-(DAT_01155230 ^ 0x9125e73f),param_3,
                             puVar1,&PTR____CFConstantStringClassReference_011541e0),
       ppuVar5 = &PTR____CFConstantStringClassReference_011541a0, iVar3 == 0)) {
      (*pcRam0000000001225a00)(param_1,param_2,param_3);
      ppuVar5 = (undefined **)_objc_retainAutoreleasedReturnValue();
    }
  }
  _objc_release(param_3);
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(ppuVar5);
  return;
}


