/* Decompiled from supplied 5.2.2 arm package. VA 0x1da52c. updateSortMenu */

/* Function Stack Size: 0x10 bytes */

void SbWhitelistVC::updateSortMenu(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  puVar1 = PTR__OBJC_CLASS___UIMenu_0114ed00;
  DAT_01227dc0 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_011b87f0,0,0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,PTR_s_getSortActions_0114e088);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_menuWithTitle_image_identifier_o_0114c3e0,uVar3,0,
                &PTR____CFConstantStringClassReference_011b87b0,1,uVar4);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_sortButton),PTR_s_setMenu__0114d658,uVar5);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0xc97);
  return;
}


