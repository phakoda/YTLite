/* Decompiled from supplied 5.2.2 arm package. VA 0x89834. FUN_00089834 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16]
FUN_00089834(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  
  DAT_01226cfc = 1;
  _objc_retain(param_3);
  uVar5 = _objc_retain(param_4);
  puVar2 = PTR_s_overlayIdentifier_0114c950;
  _objc_msgSend(uVar5,PTR_s_overlayIdentifier_0114c950);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_isEqualToString__0114ae48;
  uVar3 = FUN_000df5fc(uVar5,PTR_s_isEqualToString__0114ae48,
                       &PTR____CFConstantStringClassReference_01168300);
  if (uVar3 == 0) {
    _objc_release(uVar5);
  }
  else {
    iVar4 = FUN_000df5b4((&PTR_LAB_0117dc30)[uVar3] + (int)-(DAT_0117dc40 ^ 0x79abde1),
                         &PTR____CFConstantStringClassReference_011682c0);
    _objc_release(uVar5);
    if (iVar4 != 0) goto LAB_00089f64;
  }
  _objc_msgSend(param_4,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar3 = FUN_000df644(uVar5,puVar1,&PTR____CFConstantStringClassReference_01168280);
  if (uVar3 == 0) {
    _objc_release(uVar5);
  }
  else {
    iVar4 = FUN_000df590((&PTR_LAB_0117dc68)[uVar3] + (int)-(uRam000000000117dc78 ^ 0xac4e0234),
                         &PTR____CFConstantStringClassReference_01168240);
    _objc_release(uVar5);
    if (iVar4 != 0) goto LAB_00089f64;
  }
  (*_DAT_01226468)(param_1,param_2,param_3,param_4);
LAB_00089f64:
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x7888);
  return ZEXT816(0x1f);
}


