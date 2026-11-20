/* Decompiled from supplied 5.2.2 arm package. VA 0x13248c. tableView:titleForFooterInSection: */

/* Function Stack Size: 0x20 bytes */

ID TabbarVC::tableView_titleForFooterInSection_(ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  long lVar1;
  undefined8 uVar2;
  ID IVar3;
  undefined8 uVar4;
  
  DAT_012273e4 = 1;
  lVar1 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),PTR_s_count_0114b840);
  if (lVar1 - 1U == param_4) {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_0118f0b0,0,0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar2);
  }
  else {
    uVar4 = 0;
  }
  IVar3 = _objc_autoreleaseReturnValue(uVar4);
  return IVar3;
}


