/* Decompiled from supplied 5.2.2 arm package. VA 0x231144. FUN_00231144 */

void FUN_00231144(long param_1)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  puVar5 = PTR_ToastManager_0114ecd0;
  puVar4 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar2 = PTR_s_ytl_defaultBundle_0114ae50;
  DAT_01228420 = 1;
  cVar1 = *(char *)(param_1 + 0x28);
  if (cVar1 == '\0') {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar3 = PTR_s_localizedStringForKey_value_tabl_0114b278;
    _objc_msgSend(uVar6,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_011d0e50,0,0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar2);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puVar3,&PTR____CFConstantStringClassReference_011d0e90,0,0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_localizedDescription_0114c618);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_00234434(puVar4,PTR_s_stringWithFormat__0114b378,uVar6,uVar7,uVar8);
    uVar6 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_011d0ed0,0,0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_msgSend(puVar5,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar6,
                *(undefined1 *)(param_1 + 0x28));
                    /* WARNING: Could not recover jumptable at 0x002314e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011d1910)[cVar1 == '\0'] + (int)-(uRam00000000011d1920 ^ 0x29a99256)))();
  return;
}


