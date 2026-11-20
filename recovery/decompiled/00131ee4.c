/* Decompiled from supplied 5.2.2 arm package. VA 0x131ee4. tableView:titleForHeaderInSection: */

/* Function Stack Size: 0x20 bytes */

ID TabbarVC::tableView_titleForHeaderInSection_(ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  undefined *puVar1;
  long_long lVar2;
  undefined8 uVar3;
  ID IVar4;
  undefined8 uVar5;
  long lVar6;
  
  puVar1 = PTR_s_indexOfObject__0114b020;
  DAT_012273e0 = 1;
  lVar6 = (long)_sections;
  lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + lVar6),PTR_s_indexOfObject__0114b020,
                        *(undefined8 *)(param_1 + (long)_startup));
  if (lVar2 == param_4) {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_0118f030,0,0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + lVar6),puVar1,
                          *(undefined8 *)(param_1 + (long)_tabbar));
    if (lVar2 == param_4) {
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar3,PTR_s_localizedStringForKey_value_tabl_0114b278,
                    &PTR____CFConstantStringClassReference_0118eff0,0,0);
      uVar5 = _objc_retainAutoreleasedReturnValue();
    }
    else {
      lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + lVar6),puVar1,
                            *(undefined8 *)(param_1 + (long)_activeTabs));
      if (lVar2 == param_4) {
        _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
        uVar3 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar3,PTR_s_localizedStringForKey_value_tabl_0114b278,
                      &PTR____CFConstantStringClassReference_0118efb0,0,0);
        uVar5 = _objc_retainAutoreleasedReturnValue();
      }
      else {
        lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + lVar6),puVar1,
                              *(undefined8 *)(param_1 + (long)_inactiveTabs));
        if (lVar2 != param_4) {
          uVar5 = 0;
          goto LAB_00132474;
        }
        _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
        uVar3 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar3,PTR_s_localizedStringForKey_value_tabl_0114b278,
                      &PTR____CFConstantStringClassReference_0118ef70,0,0);
        uVar5 = _objc_retainAutoreleasedReturnValue();
      }
    }
  }
  _objc_release(uVar3);
LAB_00132474:
  IVar4 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
  return IVar4;
}


