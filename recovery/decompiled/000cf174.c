/* Decompiled from supplied 5.2.2 arm package. VA 0xcf174. FUN_000cf174 */

undefined8 FUN_000cf174(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  DAT_01227048 = 1;
  _objc_msgSend(param_2,PTR_s_pivotBarItemRenderer_0114cd98);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_pivotIdentifier_0114cda0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_objectForKeyedSubscript__0114ae80,
                &PTR____CFConstantStringClassReference_011751f0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar4 = FUN_000f0a9c(uVar2,PTR_s_isEqualToString__0114ae48,uVar3);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(uVar1);
  return uVar4;
}


