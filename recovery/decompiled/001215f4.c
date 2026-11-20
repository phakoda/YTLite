/* Decompiled from supplied 5.2.2 arm package. VA 0x1215f4. toggleSwitch: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::toggleSwitch_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  _objc_retain(param_3);
  uVar1 = _objc_msgSend(param_3,PTR_s_tag_0114b868);
  _objc_msgSend(param_1,PTR_s__cellForTag__0114d510,uVar1);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 != 0) {
    _objc_msgSend(param_1,PTR_s_defaults_0114d278);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    uVar3 = FUN_0012c1e0(param_3,PTR_s_isOn_0114d490);
    _objc_msgSend(lVar2,PTR_s_key_0114c8f8);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,PTR_s_setBool_forKey__0114add8,uVar3,uVar4);
    _objc_release(uVar4);
    _objc_release(uVar1);
  }
  _objc_release(lVar2);
  _objc_release(param_3);
  CallSupervisor(0x7bf4);
  return;
}


