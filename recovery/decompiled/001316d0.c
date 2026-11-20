/* Decompiled from supplied 5.2.2 arm package. VA 0x1316d0. saveTabsOrder */

/* Function Stack Size: 0x10 bytes */

void TabbarVC::saveTabsOrder(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  DAT_012273dc = 1;
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_activeTabs),PTR_s_valueForKey__0114ae90,
                &PTR____CFConstantStringClassReference_0118eee0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setObject_forKey__0114c2b8,uVar4,
                &PTR____CFConstantStringClassReference_0118eea0);
  _objc_release(uVar5);
  _objc_msgSend(param_1,PTR_s_tableView_0114d120);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR__OBJC_CLASS___NSIndexSet_0114ee80;
  uVar6 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),PTR_s_indexOfObject__0114b020,
                        *(undefined8 *)(param_1 + (long)_startup));
  _objc_msgSend(puVar1,PTR_s_indexSetWithIndex__0114d698,uVar6);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_reloadSections_withRowAnimation__0114d6a0,uVar6,100);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _NSClassFromString(&PTR____CFConstantStringClassReference_0118ee60);
  uVar5 = _objc_alloc_init();
  _objc_msgSend(uVar5,PTR_s_refreshPivotBar_0114b470);
  _objc_release(uVar5);
  puVar1 = PTR_s_parentViewController_0114ad68;
  _objc_msgSend(param_1,PTR_s_parentViewController_0114ad68);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = _objc_getClass(s_YTHeaderContentComboViewControll_0118ed90);
  uVar2 = FUN_00136e94(uVar5,PTR_s_isKindOfClass__0114ad70,uVar6);
  _objc_release(uVar5);
  if (uVar2 != 0) {
    _objc_msgSend((&PTR_LAB_0118ffb8)[uVar2] + (int)-(DAT_0118ffc8 ^ 0x9041c40f),param_1,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_headerViewController_0114afd8);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_hideRightNavigationButtons_0114d138;
    iVar3 = FUN_00136f1c(uVar6,PTR_s_respondsToSelector__0114af58,
                         PTR_s_hideRightNavigationButtons_0114d138);
    if (iVar3 != 0) {
      _objc_msgSend(uVar6,PTR_s_performSelector__0114b268,puVar1);
    }
    _objc_release(uVar6);
    _objc_release(uVar5);
  }
  _objc_release(uVar4);
  CallSupervisor(0x5a46);
  return;
}


