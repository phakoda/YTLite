/* Decompiled from supplied 5.2.2 arm package. VA 0x178208. FUN_00178208 */

void FUN_00178208(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined **local_80;
  undefined **ppuStack_78;
  int iStack_6c;
  undefined **local_68;
  undefined **local_60;
  uint local_54;
  undefined **local_50;
  long local_48;
  
  local_48 = *(long *)PTR____stack_chk_guard_01060708;
  local_50 = &PTR_LAB_011a85f0;
  local_54 = (uint)(DAT_0122750c == 0);
  local_68 = &PTR_heightCalculator_011a8610;
  local_60 = &PTR_LAB_011a7950;
  local_80 = &PTR_LAB_011a7950;
  ppuStack_78 = &PTR_LAB_011a7950;
  DAT_0122750c = 1;
  iStack_6c = FUN_00189d2c();
  puVar2 = PTR_DVNCell_0114ee98;
  puVar1 = PTR_s_patreonButtonCellWithType_model__0114d8d0;
  if (iStack_6c == 0) {
    _objc_msgSend(&PTR____CFConstantStringClassReference_011a52b0,PTR_s_ytl_localized_0114d190);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_imageWithName__0114c5b0,
                  &PTR____CFConstantStringClassReference_011a53b0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar2,PTR_s_cellWithTitle_subtitle_icon_type_0114d840,uVar3,0,uVar4,0,
                  &PTR____CFConstantStringClassReference_011a5370);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uStack_a0 = uVar5;
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_patreonButtonCellWithType_model__0114d8d0,
                  &PTR____CFConstantStringClassReference_011a52f0,*(undefined8 *)(param_1 + 0x28));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uStack_98 = uVar6;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  &uStack_a0,2);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
  }
  else {
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_patreonButtonCellWithType_model__0114d8d0,
                  &PTR____CFConstantStringClassReference_011a5330,*(undefined8 *)(param_1 + 0x28));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uStack_90 = uVar3;
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),puVar1,
                  &PTR____CFConstantStringClassReference_011a5270,*(undefined8 *)(param_1 + 0x28));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_88 = uVar4;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  &uStack_90,2);
    uVar7 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_release(uVar4);
  _objc_release(uVar3);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_48) {
    (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar7);
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


