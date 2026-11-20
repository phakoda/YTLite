/* Decompiled from supplied 5.2.2 arm package. VA 0xcf320. FUN_000cf320 */

undefined8 FUN_000cf320(long param_1,undefined8 param_2)

{
  undefined **ppuVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  puVar2 = PTR_s_isEqualToString__0114ae48;
  DAT_0122704c = 1;
  uVar6 = *(undefined8 *)(param_1 + 0x20);
  _objc_retain(param_2);
  iVar3 = FUN_000f0ac4(uVar6,puVar2,&PTR____CFConstantStringClassReference_01175250);
  ppuVar1 = &PTR_s_pivotBarIconOnlyItemRenderer_0114cda8;
  if (iVar3 == 0) {
    ppuVar1 = &PTR_s_pivotBarItemRenderer_0114cd98;
  }
  _objc_msgSend(param_2,*ppuVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_2);
  _objc_msgSend(uVar6,PTR_s_pivotIdentifier_0114cda0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar5 = FUN_000f0b2c(uVar4,puVar2,*(undefined8 *)(param_1 + 0x20));
  _objc_release(uVar4);
  _objc_release(uVar6);
  return uVar5;
}


