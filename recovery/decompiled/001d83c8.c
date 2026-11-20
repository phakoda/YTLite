/* Decompiled from supplied 5.2.2 arm package. VA 0x1d83c8. tableView:titleForHeaderInSection: */

/* Function Stack Size: 0x20 bytes */

ID SbWhitelistVC::tableView_titleForHeaderInSection_
             (ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  long_long lVar1;
  undefined8 uVar2;
  ID IVar3;
  undefined8 uVar4;
  
  DAT_01227da8 = 1;
  lVar1 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),PTR_s_indexOfObject__0114b020,
                        *(undefined8 *)(param_1 + (long)_channels));
  if (lVar1 == param_4) {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_011b8110,0,0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar2);
  }
  else {
    uVar4 = 0;
  }
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar3;
}


