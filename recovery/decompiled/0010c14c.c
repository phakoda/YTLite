/* Decompiled from supplied 5.2.2 arm package. VA 0x10c14c. titleForCaption: */

/* Function Stack Size: 0x18 bytes */

ID DownloadMenuHelper::titleForCaption_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ID IVar10;
  
  DAT_01227218 = 1;
  uVar6 = _objc_retain(param_3);
  puVar2 = PTR_s_VSSID_0114d078;
  _objc_msgSend(uVar6,PTR_s_VSSID_0114d078);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_hasPrefix__0114aea0;
  uVar4 = FUN_00114bd0(uVar6,PTR_s_hasPrefix__0114aea0,
                       &PTR____CFConstantStringClassReference_01187fc0);
  _objc_release(uVar6);
  puVar3 = PTR__OBJC_CLASS___NSString_0114eb38;
  if (uVar4 == 0) {
    _objc_msgSend((&PTR_LAB_0118b258)[uVar4] + (int)-(uRam000000000118b268 ^ 0x8eee428f),param_3,
                  puVar2);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    iVar5 = FUN_00114ca4(uVar6,puVar1,&PTR____CFConstantStringClassReference_01187f00);
    _objc_release(uVar6);
    puVar1 = PTR__OBJC_CLASS___NSString_0114eb38;
    if (iVar5 == 0) {
      _objc_msgSend(param_3,PTR_s_displayName_0114d068);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      goto LAB_0010c6fc;
    }
    _objc_msgSend(param_3,PTR_s_displayName_0114d068);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_01187ec0,0,0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_00114d18(puVar1,PTR_s_stringWithFormat__0114b378,
                       &PTR____CFConstantStringClassReference_01187f40,uVar7,uVar9);
    uVar6 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(param_3,PTR_s_displayName_0114d068);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_01187f80,0,0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_00114c44(puVar3,PTR_s_stringWithFormat__0114b378,
                       &PTR____CFConstantStringClassReference_01187f40,uVar7,uVar9);
    uVar6 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
LAB_0010c6fc:
  _objc_release(param_3);
  IVar10 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar6);
  return IVar10;
}


