/* Decompiled from supplied 5.2.2 arm package. VA 0x177f70. patreonSection: */

/* Function Stack Size: 0x18 bytes */

ID YTPSettingsBuilder::patreonSection_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  undefined *puStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined *puStack_78;
  ID IStack_70;
  ID IStack_68;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_FUN_011a85d0;
  local_4c = (uint)(DAT_01227508 == 0);
  local_58 = &PTR_LAB_011a7950;
  DAT_01227508 = 1;
  _objc_retain(param_3);
  _objc_msgSend(PTR_DVNSection_0114ee90,PTR_s_sectionWithIdentifier__0114d7b0,
                &PTR____CFConstantStringClassReference_011a5120);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setHeader__0114d7b8,&PTR____CFConstantStringClassReference_011a50e0);
  puVar1 = PTR_s_setCellsProvider__0114d8d8;
  puStack_90 = PTR___NSConcreteStackBlock_01060660;
  uStack_88 = DAT_00c4c228;
  pcStack_80 = FUN_00178208;
  puStack_78 = &UNK_010626b0;
  IStack_70 = param_1;
  IStack_68 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,&puStack_90);
  _objc_release(IStack_68);
  _objc_release(param_3);
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return IVar3;
}


