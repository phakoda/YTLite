/* Decompiled from supplied 5.2.2 arm package. VA 0x122e44. stepperForCell:indexPath: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::stepperForCell_indexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  ID IVar7;
  float fVar8;
  
  puVar1 = PTR__OBJC_CLASS___UIStepper_0114ee60;
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(param_3,PTR_s_minimumValue_0114d400);
  _objc_msgSend(uVar2,PTR_s_setMinimumValue__0114d598);
  _objc_msgSend(param_3,PTR_s_maximumValue_0114d408);
  _objc_msgSend(uVar2,PTR_s_setMaximumValue__0114d5a0);
  _objc_msgSend(param_3,PTR_s_dividerValue_0114d558);
  _objc_msgSend(uVar2,PTR_s_setStepValue__0114d5c0);
  _objc_msgSend(param_1,PTR_s_defaults_0114d278);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,PTR_s_key_0114c8f8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  fVar8 = (float)_objc_msgSend(uVar3,PTR_s_floatForKey__0114c308,uVar4);
  _objc_msgSend((double)fVar8,uVar2,PTR_s_setValue__0114d560);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_msgSend(param_1,PTR_s_tableView_0114d120);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_tintColor_0114d1b8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setTintColor__0114b000,uVar4);
  _objc_release(uVar4);
  _objc_release(uVar3);
  lVar5 = _objc_msgSend(param_4,PTR_s_section_0114af60);
  uVar6 = _objc_msgSend(param_4,PTR_s_row_0114af70);
  _objc_release(param_4);
  _objc_msgSend(uVar2,PTR_s_setTag__0114b858,uVar6 & 0xffff | lVar5 << 0x10);
  _objc_msgSend(uVar2,PTR_s_addTarget_action_forControlEvent_0114b830,param_1,
                PTR_s_stepperValueChanged__0114d5c8,0x1000);
  IVar7 = _objc_autoreleaseReturnValue(uVar2);
  return IVar7;
}


