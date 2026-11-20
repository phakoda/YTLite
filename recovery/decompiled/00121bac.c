/* Decompiled from supplied 5.2.2 arm package. VA 0x121bac. stepperValueChanged: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::stepperValueChanged_(ID param_1,SEL param_2,ID param_3)

{
  double dVar1;
  undefined *puVar2;
  undefined2 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  
  _objc_retain(param_3);
  puVar2 = PTR_s_tag_0114b868;
  uVar4 = _objc_msgSend(param_3,PTR_s_tag_0114b868);
  _objc_msgSend(param_1,PTR_s__cellForTag__0114d510,uVar4);
  lVar5 = _objc_retainAutoreleasedReturnValue();
  if (lVar5 != 0) {
    _objc_msgSend(param_1,PTR_s_defaults_0114d278);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    dVar1 = (double)_objc_msgSend(param_3,PTR_s_value_0114cdf0);
    _objc_msgSend(lVar5,PTR_s_key_0114c8f8);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend((float)dVar1,uVar4,PTR_s_setFloat_forKey__0114d518,uVar6);
    _objc_release(uVar6);
    _objc_release(uVar4);
    lVar7 = _objc_msgSend(param_3,puVar2);
    uVar3 = _objc_msgSend(param_3,puVar2);
    _objc_msgSend(param_1,PTR_s_tableView_0114d120);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSIndexPath_0114ee10,PTR_s_indexPathForRow_inSection__0114d250,
                  uVar3,lVar7 >> 0x10);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_cellForRowAtIndexPath__0114d298,uVar6);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_msgSend(param_1,PTR_s_stepperLabelForCell__0114d438,lVar5);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,PTR_s_textLabel_0114b8e0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_setAttributedText__0114b678,uVar4);
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_release(uVar8);
  }
  _objc_release(lVar5);
  _objc_release(param_3);
  CallSupervisor(0xade3);
  return;
}


