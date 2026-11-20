/* Decompiled from supplied 5.2.2 arm package. VA 0x3fa3c. contactsButtonTapped: */

/* Function Stack Size: 0x18 bytes */

void WelcomeVC::contactsButtonTapped_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  DAT_01225eb8 = 1;
  uVar4 = _objc_retain(param_3);
  puVar2 = PTR_s_tag_0114b868;
  lVar5 = _objc_msgSend(uVar4,PTR_s_tag_0114b868);
  puVar1 = PTR_s_sharedApplication_0114b528;
  if (lVar5 == 0) {
    _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_URLWithString__0114b3d0;
    _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0,
                  &PTR____CFConstantStringClassReference_0115c1a0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar3 = FUN_00046868(uVar4,PTR_s_canOpenURL__0114b870,uVar6);
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    if (uVar3 == 0) {
      _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,puVar2,
                    &PTR____CFConstantStringClassReference_0115c120);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_openURL_options_completionHandle_0114b878,uVar6,
                    *(undefined8 *)PTR____NSDictionary0___01060678,0);
    }
    else {
      _objc_msgSend((&PTR_LAB_0115ca98)[uVar3] + (int)-(uRam000000000115caa8 ^ 0xd075c518),
                    PTR__OBJC_CLASS___NSURL_0114eb78,puVar2,
                    &PTR____CFConstantStringClassReference_0115c1a0);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_openURL_options_completionHandle_0114b878,uVar6,
                    *(undefined8 *)PTR____NSDictionary0___01060678,0);
    }
    _objc_release(uVar6);
    _objc_release(uVar4);
  }
  else {
    lVar5 = _objc_msgSend((&PTR_LAB_0115ca80)[lVar5 == 0] +
                          (int)-(uRam000000000115ca90 ^ 0xc78d51ca),param_3,puVar2);
    if (lVar5 == 1) {
      if (lRam0000000001225ea0 == 0) {
        lRam0000000001225ea0 =
             _objc_getClass((&PTR_LAB_0115cad8)[lRam0000000001225ea0 == 0] +
                            (int)-(uRam000000000115cae8 ^ 0x1f9c2d39),
                            s_YTDefaultSheetController_0115bca0);
      }
      lVar5 = lRam0000000001225ea0;
      _objc_retainAutorelease(lRam0000000001225ea0);
      puVar1 = PTR_s_ytl_defaultBundle_0114ae50;
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      puVar2 = PTR_s_localizedStringForKey_value_tabl_0114b278;
      _objc_msgSend(uVar4,PTR_s_localizedStringForKey_value_tabl_0114b278,
                    &PTR____CFConstantStringClassReference_0115c0a0,0,0);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,puVar2,&PTR____CFConstantStringClassReference_0115c020,0,0);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar5,PTR_s_sheetControllerWithMessage_subMe_0114b880,uVar6,uVar8,0,0);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar8);
      _objc_release(uVar7);
      _objc_release(uVar6);
      _objc_release(uVar4);
      puVar1 = PTR_s_valueForKey__0114ae90;
      _objc_msgSend(uVar9,PTR_s_valueForKey__0114ae90,
                    &PTR____CFConstantStringClassReference_0115bea0);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,puVar1,&PTR____CFConstantStringClassReference_0115bfe0);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,PTR_s_setNumberOfLines__0114b5f0,0);
      _objc_msgSend(uVar4,PTR_s_showHeaderDivider_0114b888);
                    /* WARNING: Could not recover jumptable at 0x000410e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((&PTR_LAB_0115caf8)[DAT_01225ea8 == 0] + (int)-(DAT_0115cb08 ^ 0x829cf339)))();
      return;
    }
  }
  _objc_release(param_3);
  CallSupervisor(0xb3ce);
  return;
}


