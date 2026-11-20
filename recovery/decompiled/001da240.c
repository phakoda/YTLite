/* Decompiled from supplied 5.2.2 arm package. VA 0x1da240. FUN_001da240 */

void FUN_001da240(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_01227db4 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_objectForKeyedSubscript__0114ae80,
                &PTR____CFConstantStringClassReference_011b8740);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_msgSend(uVar2,PTR_s_integerValue_0114b4c8);
  _objc_msgSend(uVar1,PTR_s_setInteger_forKey__0114c2d8,uVar3,
                &PTR____CFConstantStringClassReference_011b8700);
  _objc_release(uVar2);
  _objc_release(uVar1);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_setupWhitelist_0114e050);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_updateSortMenu_0114e090);
  return;
}


