/* Decompiled from supplied 5.2.2 arm package. VA 0xc20f4. FUN_000c20f4 */

undefined1  [16] FUN_000c20f4(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 auVar10 [16];
  
  puVar3 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar1 = PTR_s_ytl_defaultBundle_0114ae50;
  DAT_01226fb8 = 1;
  if (*(char *)(param_1 + 0x28) == '\0') {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_localizedStringForKey_value_tabl_0114b278;
    _objc_msgSend(uVar4,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_01172610,0,0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puVar2,&PTR____CFConstantStringClassReference_011725d0,0,0);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_localizedDescription_0114c618);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_000ed5fc(puVar3,PTR_s_stringWithFormat__0114b378,uVar6,uVar8,uVar9);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_01172590,0,0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_release(uVar4);
  _objc_msgSend(PTR_ToastManager_0114ecd0,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar5,
                *(undefined1 *)(param_1 + 0x28));
  _objc_release(uVar5);
  CallSupervisor(0x968f);
  auVar10._8_8_ = 0x1f;
  auVar10._0_8_ = 0x1a;
  return auVar10;
}


