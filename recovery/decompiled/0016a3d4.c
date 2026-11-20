/* Decompiled from supplied 5.2.2 arm package. VA 0x16a3d4. rpcTable */

/* Function Stack Size: 0x10 bytes */

ID YTPSettingsBuilder::rpcTable(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  ID IVar14;
  undefined1 auStack_170 [48];
  undefined1 auStack_140 [16];
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined *puStack_d8;
  undefined *puStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined1 *puStack_b0;
  undefined1 *puStack_a8;
  undefined8 *puStack_a0;
  undefined1 *puStack_98;
  ID local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  puVar2 = PTR_DVNTableModel_0114ee88;
  puVar1 = PTR_s_ytl_localized_0114d190;
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_011a8170;
  local_7c = (uint)(DAT_01227464 == 0);
  local_88 = &PTR_LAB_011a7950;
  DAT_01227464 = 1;
  puStack_b0 = auStack_140;
  puStack_a8 = auStack_170;
  puStack_a0 = &uStack_130;
  puStack_98 = puStack_b0;
  local_90 = param_1;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a1e90,PTR_s_ytl_localized_0114d190);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,PTR_s_modelWithTitle_sections__0114d6e0,uVar5,0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  _objc_msgSend(uVar6,PTR_s_setSupportsSearching__0114d6e8,1);
  puStack_d8 = PTR_DVNSection_0114ee90;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a1e50,puVar1);
  uStack_e0 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a1d50,puVar1);
  uStack_f0 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_DVNCell_0114ee98;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a1bd0,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uStack_b8 = uVar5;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a1d10,puVar1);
  uStack_c0 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_cellWithTitle_subtitle_type_key__0114d788;
  _objc_msgSend(puVar3,PTR_s_cellWithTitle_subtitle_type_key__0114d788,uVar5,uStack_c0,0,
                &PTR____CFConstantStringClassReference_011a1cd0);
  uStack_130 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_DVNCell_0114ee98;
  uStack_c8 = uStack_130;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a1c10,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uStack_e8 = uVar5;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a1b50,puVar1);
  uStack_f8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar3,puVar2,uVar5,uStack_f8,0,&PTR____CFConstantStringClassReference_011a1dd0);
  uStack_128 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_DVNCell_0114ee98;
  uStack_100 = uStack_128;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a1b10,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uStack_108 = uVar5;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a1b90,puVar1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar3,puVar2,uVar5,uVar7,0,&PTR____CFConstantStringClassReference_011a1e10);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_DVNCell_0114ee98;
  uStack_120 = uVar8;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a1ad0,puVar1);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,PTR_s_textFieldCellWithTitle_subtitle__0114d820,uVar9,0,
                &PTR____CFConstantStringClassReference_011a1a90,
                &PTR____CFConstantStringClassReference_011a1c90);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puStack_d0 = PTR_s_arrayWithObjects_count__0114b600;
  uStack_118 = uVar10;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                &uStack_130,4);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  uVar13 = uStack_e0;
  uVar5 = uStack_f0;
  _objc_msgSend(puStack_d8,PTR_s_sectionWithHeader_footer_cells_i_0114d758,uStack_e0,uStack_f0,
                uVar11,&PTR____CFConstantStringClassReference_011a1c50);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_d8 = PTR_s_addSection__0114d710;
  _objc_msgSend(uVar6,PTR_s_addSection__0114d710,uVar12);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uStack_108);
  _objc_release(uStack_100);
  _objc_release(uStack_f8);
  _objc_release(uStack_e8);
  _objc_release(uStack_c8);
  _objc_release(uStack_c0);
  _objc_release(uStack_b8);
  _objc_release(uVar5);
  _objc_release(uVar13);
  puVar2 = PTR_DVNSection_0114ee90;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a1a50,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_DVNCell_0114ee98;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a1d90,puVar1);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_imageWithName__0114c5b0,
                &PTR____CFConstantStringClassReference_011a1a10);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar4 = puStack_b0;
  *(undefined **)(puStack_b0 + -0x30) = PTR___NSConcreteStackBlock_01060660;
  *(undefined8 *)(puVar4 + -0x28) = DAT_00c4c228;
  *(code **)(puVar4 + -0x20) = FUN_0016bb48;
  *(undefined **)(puVar4 + -0x18) = &DAT_01061420;
  *(ID *)(puVar4 + -0x10) = local_90;
  _objc_msgSend(puVar3,PTR_s_cellWithTitle_subtitle_icon_acce_0114d830,uVar13,0,0,uVar7,5,puStack_a8
               );
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar4 = puStack_98;
  puStack_a0[-2] = uVar8;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puStack_d0,puVar4,1);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,PTR_s_sectionWithHeader_cells_identifi_0114d790,uVar5,uVar9,
                &PTR____CFConstantStringClassReference_011a19d0);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,puStack_d8,uVar10);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar13);
  _objc_release(uVar5);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_70) {
    IVar14 = _objc_autoreleaseReturnValue(uVar6);
    return IVar14;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


