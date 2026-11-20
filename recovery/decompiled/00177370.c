/* Decompiled from supplied 5.2.2 arm package. VA 0x177370. creditsSection */

/* Function Stack Size: 0x10 bytes */

ID YTPSettingsBuilder::creditsSection(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  ID IVar15;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 *puStack_b0;
  undefined *puStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  puVar2 = PTR_s_ytl_localized_0114d190;
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011a85b0;
  local_74 = (uint)(DAT_01227504 == 0);
  local_80 = &PTR_LAB_011a7950;
  DAT_01227504 = 1;
  puStack_b0 = &uStack_110;
  puStack_a8 = PTR_DVNSection_0114ee90;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a4f70,PTR_s_ytl_localized_0114d190);
  uStack_b8 = _objc_retainAutoreleasedReturnValue();
  puVar4 = PTR_DVNCell_0114ee98;
  _objc_msgSend(param_1,PTR_s_contribsTable_0114d8b0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uStack_88 = uVar6;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a5070,puVar2);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_imageWithName__0114c5b0;
  uStack_90 = uVar7;
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_imageWithName__0114c5b0,
                &PTR____CFConstantStringClassReference_011a4ff0);
  uStack_98 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_controllerCellWithModel_title_su_0114d720;
  _objc_msgSend(puVar4,PTR_s_controllerCellWithModel_title_su_0114d720,uVar6,uVar7,0,uStack_98);
  uStack_110 = _objc_retainAutoreleasedReturnValue();
  puVar4 = PTR_DVNCell_0114ee98;
  uStack_a0 = uStack_110;
  _objc_msgSend(param_1,PTR_s_libsTable_0114d8b8);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uStack_c0 = uVar6;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a4fb0,puVar2);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  uStack_c8 = uVar7;
  _objc_msgSend(PTR_YTPMedia_0114eae0,puVar1,&PTR____CFConstantStringClassReference_011a5030);
  uStack_d0 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar4,puVar3,uVar6,uVar7,0,uStack_d0);
  uStack_108 = _objc_retainAutoreleasedReturnValue();
  puVar4 = PTR_DVNCell_0114ee98;
  uStack_d8 = uStack_108;
  _objc_msgSend(param_1,PTR_s_thanksTable_0114d8c0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uStack_e0 = uVar6;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a4f30,puVar2);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  uStack_e8 = uVar7;
  _objc_msgSend(PTR_YTPMedia_0114eae0,puVar1,&PTR____CFConstantStringClassReference_011a4ef0);
  uStack_f0 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar4,puVar3,uVar6,uVar7,0,uStack_f0);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar5 = PTR_DVNCell_0114ee98;
  uStack_100 = uVar7;
  _objc_msgSend(param_1,PTR_s_prefsTable_0114d8c8);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar4 = PTR__OBJC_CLASS___NSString_0114eb38;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a4eb0,puVar2);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00189c10(puVar4,PTR_s_stringWithFormat__0114b378,uVar9,
                     &PTR____CFConstantStringClassReference_011a4e30);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,puVar1,&PTR____CFConstantStringClassReference_011a4df0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar5,puVar3,uVar8,uVar10,0,uVar11);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  uStack_f8 = uVar12;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,puStack_b0
                ,4);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  uVar6 = uStack_b8;
  _objc_msgSend(puStack_a8,PTR_s_sectionWithHeader_footer_cells_i_0114d758,uStack_b8,0,uVar13,
                &PTR____CFConstantStringClassReference_011a4e70);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uStack_f0);
  _objc_release(uStack_e8);
  _objc_release(uStack_e0);
  _objc_release(uStack_d8);
  _objc_release(uStack_d0);
  _objc_release(uStack_c8);
  _objc_release(uStack_c0);
  _objc_release(uStack_a0);
  _objc_release(uStack_98);
  _objc_release(uStack_90);
  _objc_release(uStack_88);
  _objc_release(uVar6);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    IVar15 = _objc_autoreleaseReturnValue(uVar14);
    return IVar15;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


