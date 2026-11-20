/* Decompiled from supplied 5.2.2 arm package. VA 0x1357c4. tableView:commitEditingStyle:forRowAtIndexPath: */

/* Function Stack Size: 0x28 bytes */

void TabbarVC::tableView_commitEditingStyle_forRowAtIndexPath_
               (ID param_1,SEL param_2,ID param_3,long_long param_4,ID param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  long lVar13;
  
  DAT_01227424 = 1;
  _objc_retain(param_3);
  _objc_retain(param_5);
  puVar1 = PTR_s_standardUserDefaults_0114afa0;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar4 = PTR_s_objectForKey__0114b238;
  _objc_msgSend(uVar6,PTR_s_objectForKey__0114b238,&PTR____CFConstantStringClassReference_0118f9d0);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar6);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,puVar4,&PTR____CFConstantStringClassReference_0118fa90);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar6);
  puVar4 = PTR_s_count_0114b840;
  if ((long)param_4 < 2) {
    if (param_4 != 1) goto LAB_001364d0;
    lVar9 = _objc_msgSend(uVar7,PTR_s_count_0114b840);
    puVar2 = PTR_s_row_0114af70;
    if (lVar9 == 1) {
      uVar6 = _NSClassFromString((&PTR_LAB_01190458)[lVar9 == 1] +
                                 (int)-(uRam0000000001190468 ^ 0xe6bfd783),
                                 &PTR____CFConstantStringClassReference_0118fad0);
      _objc_msgSend(uVar6,PTR_s_infoDialog_0114b270);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      puVar1 = PTR_s_ytl_defaultBundle_0114ae50;
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      puVar4 = PTR_s_localizedStringForKey_value_tabl_0114b278;
      _objc_msgSend(uVar11,PTR_s_localizedStringForKey_value_tabl_0114b278,
                    &PTR____CFConstantStringClassReference_0118fa10,0,0);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,PTR_s_setTitle__0114afc0,uVar12);
      _objc_release(uVar12);
      _objc_release(uVar11);
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar11,puVar4,&PTR____CFConstantStringClassReference_0118f990,0,0);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,PTR_s_setSubtitle__0114b280,uVar12);
      _objc_release(uVar12);
      _objc_release(uVar11);
      _objc_msgSend(uVar6,PTR_s_show_0114b288);
    }
    else {
      lVar9 = (long)_activeTabs;
      uVar11 = *(undefined8 *)(param_1 + lVar9);
      uVar6 = _objc_msgSend(param_5,PTR_s_row_0114af70);
      puVar3 = PTR_s_objectAtIndexedSubscript__0114aeb0;
      _objc_msgSend(uVar11,PTR_s_objectAtIndexedSubscript__0114aeb0,uVar6);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      uVar12 = *(undefined8 *)(param_1 + lVar9);
      uVar11 = _objc_msgSend(param_5,puVar2);
      _objc_msgSend(uVar12,PTR_s_removeObjectAtIndex__0114cdd0,uVar11);
      lVar13 = (long)_inactiveTabs;
      _objc_msgSend(*(undefined8 *)(param_1 + lVar13),PTR_s_addObject__0114b3a0,uVar6);
      puVar2 = PTR_s_objectForKeyedSubscript__0114ae80;
      _objc_msgSend(uVar6,PTR_s_objectForKeyedSubscript__0114ae80,
                    &PTR____CFConstantStringClassReference_0118fa50);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      uVar5 = FUN_00138b80(uVar11,PTR_s_isEqualToString__0114ae48,uVar8);
      _objc_release(uVar11);
      if (uVar5 != 0) {
        _objc_msgSend((&PTR_LAB_01190478)[uVar5] + (int)-(DAT_01190488 ^ 0x9d0c36fd),
                      PTR_YTLUserDefaults_0114ead8,puVar1);
        uVar11 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(*(undefined8 *)(param_1 + lVar9),puVar3,0);
        uVar12 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar12,puVar2,&PTR____CFConstantStringClassReference_0118fa50);
        uVar10 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar11,PTR_s_setObject_forKey__0114c2b8,uVar10,
                      &PTR____CFConstantStringClassReference_0118fa90);
        _objc_release(uVar10);
        _objc_release(uVar12);
        _objc_release(uVar11);
      }
      puVar1 = PTR__OBJC_CLASS___NSIndexPath_0114ee10;
      lVar9 = _objc_msgSend(*(undefined8 *)(param_1 + lVar13),puVar4);
      uVar11 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),
                             PTR_s_indexOfObject__0114b020,*(undefined8 *)(param_1 + lVar13));
      _objc_msgSend(puVar1,PTR_s_indexPathForRow_inSection__0114d250,lVar9 + -1,uVar11);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_3,PTR_s_moveRowAtIndexPath_toIndexPath__0114d6d8,param_5,uVar11);
      _objc_release(uVar11);
      _objc_msgSend(param_1,PTR_s_saveTabsOrder_0114d6d0);
    }
  }
  else {
    if (param_4 != 2) goto LAB_001364d0;
    lVar13 = (long)_activeTabs;
    lVar9 = _objc_msgSend(*(undefined8 *)(param_1 + lVar13),PTR_s_count_0114b840);
    puVar1 = PTR_s_row_0114af70;
    if (lVar9 == 6) {
      uVar6 = _NSClassFromString((&PTR_LAB_011904a0)[lVar9 == 6] +
                                 (int)-(uRam00000000011904b0 ^ 0xceed9c55),
                                 &PTR____CFConstantStringClassReference_0118fad0);
      _objc_msgSend(uVar6,PTR_s_infoDialog_0114b270);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      puVar1 = PTR_s_ytl_defaultBundle_0114ae50;
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      puVar4 = PTR_s_localizedStringForKey_value_tabl_0114b278;
      _objc_msgSend(uVar11,PTR_s_localizedStringForKey_value_tabl_0114b278,
                    &PTR____CFConstantStringClassReference_0118fa10,0,0);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,PTR_s_setTitle__0114afc0,uVar12);
      _objc_release(uVar12);
      _objc_release(uVar11);
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar11,puVar4,&PTR____CFConstantStringClassReference_0118f950,0,0);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,PTR_s_setSubtitle__0114b280,uVar12);
      _objc_release(uVar12);
      _objc_release(uVar11);
      _objc_msgSend(uVar6,PTR_s_show_0114b288);
    }
    else {
      lVar9 = (long)_inactiveTabs;
      uVar11 = *(undefined8 *)(param_1 + lVar9);
      uVar6 = _objc_msgSend(param_5,PTR_s_row_0114af70);
      _objc_msgSend(uVar11,PTR_s_objectAtIndexedSubscript__0114aeb0,uVar6);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      uVar12 = *(undefined8 *)(param_1 + lVar9);
      uVar11 = _objc_msgSend(param_5,puVar1);
      _objc_msgSend(uVar12,PTR_s_removeObjectAtIndex__0114cdd0,uVar11);
      _objc_msgSend(*(undefined8 *)(param_1 + lVar13),PTR_s_addObject__0114b3a0,uVar6);
      puVar1 = PTR__OBJC_CLASS___NSIndexPath_0114ee10;
      lVar9 = _objc_msgSend(*(undefined8 *)(param_1 + lVar13),puVar4);
      uVar11 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),
                             PTR_s_indexOfObject__0114b020,*(undefined8 *)(param_1 + lVar13));
      _objc_msgSend(puVar1,PTR_s_indexPathForRow_inSection__0114d250,lVar9 + -1,uVar11);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_3,PTR_s_moveRowAtIndexPath_toIndexPath__0114d6d8,param_5,uVar11);
      _objc_release(uVar11);
      _objc_msgSend(param_1,PTR_s_saveTabsOrder_0114d6d0);
    }
  }
  _objc_release(uVar6);
LAB_001364d0:
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(param_5);
  _objc_release(param_3);
  CallSupervisor(0x6e21);
  return;
}


