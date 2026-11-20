/* Decompiled from supplied 5.2.2 arm package. VA 0x238398. initWithFrame: */

/* Function Stack Size: 0x30 bytes */

ID YTPSpeedControlView::initWithFrame_(ID param_1,SEL param_2,CGRect param_3)

{
  undefined *puVar1;
  ID IVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ID local_a0;
  undefined *puStack_98;
  uint local_8c;
  undefined **local_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  long local_58;
  
  local_58 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_011d21e8;
  puStack_98 = PTR_YTPSpeedControlView_0114f160;
  local_a0 = param_1;
  IVar2 = _objc_msgSendSuper2(param_3.field0_0x0.field0_0x0,param_3.field0_0x0.field1_0x8,
                              param_3.field1_0x10.field0_0x0,param_3.field1_0x10.field1_0x8,
                              &local_a0,PTR_s_initWithFrame__0114b770);
  local_8c = (uint)(IVar2 == 0);
  if (IVar2 != 0) {
    *(undefined4 *)(IVar2 + (long)_step) = 0x3d4ccccd;
    puVar1 = PTR_s_numberWithDouble__0114c310;
    _objc_msgSend(0x3ff0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,
                  PTR_s_numberWithDouble__0114c310);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uStack_80 = uVar3;
    _objc_msgSend(0x4000000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_78 = uVar4;
    _objc_msgSend(0x4008000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uStack_70 = uVar5;
    _objc_msgSend(0x4014000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uStack_68 = uVar6;
    _objc_msgSend(0x4024000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uStack_60 = uVar7;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  &uStack_80,5);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    uVar9 = *(undefined8 *)(IVar2 + (long)_presets);
    *(undefined8 *)(IVar2 + (long)_presets) = uVar8;
    _objc_release(uVar9);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_release(uVar3);
    _objc_msgSend(IVar2,PTR_s_setupUI_0114e838);
  }
  if (*(long *)PTR____stack_chk_guard_01060708 != local_58) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return IVar2;
}


