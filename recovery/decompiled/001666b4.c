/* Decompiled from supplied 5.2.2 arm package. VA 0x1666b4. tabBarTable */

/* Function Stack Size: 0x10 bytes */

ID YTPSettingsBuilder::tabBarTable(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  puVar1 = PTR_DVNTableModel_0114ee88;
  DAT_01227454 = 1;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a04d0,PTR_s_ytl_localized_0114d190);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_alloc(PTR_TabbarVC_0114ecf0);
  uVar3 = _objc_msgSend(uVar3,PTR_s_initForSettings__0114c398,1);
  _objc_msgSend(puVar1,PTR_s_modelWithTitle_header_footer_vie_0114d7f0,uVar2,0,0,uVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(uVar4,PTR_s_setSupportsSearching__0114d6e8,0);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}


