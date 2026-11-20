/* Decompiled from supplied 5.2.2 arm package. VA 0x1a79a0. prepareURLsForImport: */

/* Function Stack Size: 0x18 bytes */

void DVNMediaPicker::prepareURLsForImport_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puStack_b0;
  undefined8 uStack_a8;
  code *pcStack_a0;
  undefined *puStack_98;
  undefined8 uStack_90;
  ID IStack_88;
  undefined **local_78;
  uint local_6c;
  undefined **local_68;
  
  local_68 = &PTR_LAB_011ae9f8;
  local_6c = (uint)(DAT_01227974 == 0);
  local_78 = &PTR_LAB_011ae4f0;
  DAT_01227974 = 1;
  _objc_retain(param_3);
  puVar1 = PTR__OBJC_CLASS___UIAlertController_0114ef40;
  puVar2 = PTR_s_ytl_localized_0114d190;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011ae2b0,PTR_s_ytl_localized_0114d190);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(&PTR____CFConstantStringClassReference_011ae270,puVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_alertControllerWithTitle_message_0114dc78,uVar5,uVar6,1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_msgSend(uVar7,PTR_s_addTextFieldWithConfigurationHan_0114dc80,
                &PTR___NSConcreteGlobalBlock_01062930);
  puVar1 = PTR__OBJC_CLASS___UIAlertAction_0114ef48;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011ae230,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_actionWithTitle_style_handler__0114dc90;
  puStack_b0 = PTR___NSConcreteStackBlock_01060660;
  uStack_a8 = DAT_00c4c228;
  pcStack_a0 = FUN_001a80f8;
  puStack_98 = &UNK_01062950;
  uStack_90 = uVar7;
  IStack_88 = param_3;
  _objc_retain(param_3);
  _objc_retain(uVar7);
  _objc_msgSend(puVar1,puVar3,uVar5,0,&puStack_b0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_addAction__0114b898;
  _objc_msgSend(uVar7,PTR_s_addAction__0114b898,uVar6);
  _objc_release(uVar6);
  _objc_release(uVar5);
  puVar4 = PTR__OBJC_CLASS___UIAlertAction_0114ef48;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011ae1f0,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar4,puVar3,uVar5,1,&PTR___NSConcreteGlobalBlock_010629a0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar1,uVar6);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_msgSend(*(undefined8 *)(param_1 + 8),PTR_s_presentViewController_animated_c_0114b298,uVar7,1
                ,0);
  _objc_release(IStack_88);
  _objc_release(uStack_90);
  _objc_release(param_3);
  _objc_release(uVar7);
  CallSupervisor(0x3eb0);
  return;
}


