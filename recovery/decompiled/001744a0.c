/* Decompiled from supplied 5.2.2 arm package. VA 0x1744a0. thanksTable */

/* Function Stack Size: 0x10 bytes */

ID YTPSettingsBuilder::thanksTable(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  puVar1 = PTR_DVNTableModel_0114ee88;
  DAT_012274d4 = 1;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a4010,PTR_s_ytl_localized_0114d190);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_alloc_init(PTR_DVNSupportersVC_0114eea8);
  _objc_msgSend(puVar1,PTR_s_modelWithTitle_header_footer_vie_0114d7f0,uVar2,0,0,uVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(uVar4,PTR_s_setSupportsSearching__0114d6e8,0);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar5;
}


