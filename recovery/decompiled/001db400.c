/* Decompiled from supplied 5.2.2 arm package. VA 0x1db400. tableView:trailingSwipeActionsConfigurationForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

ID SbWhitelistVC::tableView_trailingSwipeActionsConfigurationForRowAtIndexPath_
             (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 auStack_d0 [2];
  undefined *puStack_c0;
  undefined8 uStack_b8;
  code *pcStack_b0;
  undefined *puStack_a8;
  ID IStack_a0;
  undefined8 uStack_98;
  undefined **local_88;
  int iStack_7c;
  undefined **local_78;
  undefined **ppuStack_70;
  uint local_64;
  undefined **local_60;
  long local_58;
  
  puVar1 = PTR_s_section_0114af60;
  local_58 = *(long *)PTR____stack_chk_guard_01060708;
  local_60 = &PTR_LAB_011b9358;
  local_64 = (uint)(DAT_01227dd8 == 0);
  local_78 = &PTR_LAB_011b9378;
  ppuStack_70 = &PTR_LAB_011b8c20;
  local_88 = &PTR_LAB_011b8c20;
  DAT_01227dd8 = 1;
  uVar7 = *(undefined8 *)(param_1 + (long)_sections);
  uVar3 = _objc_retain(param_4);
  uVar3 = _objc_msgSend(uVar3,puVar1);
  puVar1 = PTR_s_objectAtIndexedSubscript__0114aeb0;
  _objc_msgSend(uVar7,PTR_s_objectAtIndexedSubscript__0114aeb0,uVar3);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar7 = _objc_msgSend(param_4,PTR_s_row_0114af70);
  _objc_release(param_4);
  _objc_msgSend(uVar3,puVar1,uVar7);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_msgSend(uVar7,PTR_s_objectForKeyedSubscript__0114ae80,
                &PTR____CFConstantStringClassReference_011b8b00);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_001ddeec(uVar3,PTR_s_isEqualToString__0114ae48,
                       &PTR____CFConstantStringClassReference_011b8ac0);
  _objc_release(uVar3);
  puVar1 = PTR__OBJC_CLASS___UIContextualAction_0114efb0;
  iStack_7c = iVar2;
  if (iVar2 == 0) {
    uVar6 = 0;
  }
  else {
    puStack_c0 = PTR___NSConcreteStackBlock_01060660;
    uStack_b8 = DAT_00c4c228;
    pcStack_b0 = FUN_001db870;
    puStack_a8 = &UNK_01062d70;
    IStack_a0 = param_1;
    _objc_retain(uVar7);
    uStack_98 = uVar7;
    _objc_msgSend(puVar1,PTR_s_contextualActionWithStyle_title__0114e0a8,1,&cf___,&puStack_c0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,PTR_s_systemImageNamed__0114b718,
                  &PTR____CFConstantStringClassReference_011b8a80);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_setImage__0114b8f8,uVar4);
    _objc_release(uVar4);
    puVar1 = PTR__OBJC_CLASS___UISwipeActionsConfiguration_0114efb8;
    auStack_d0[0] = uVar3;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  auStack_d0,1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar1,PTR_s_configurationWithActions__0114e0b0,uVar4);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_msgSend(uVar6,PTR_s_setPerformsFirstActionWithFullSw_0114e0b8,1);
    _objc_release(uVar3);
    _objc_release(uStack_98);
  }
  _objc_release(uVar7);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_58) {
    IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar6);
    return IVar5;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


