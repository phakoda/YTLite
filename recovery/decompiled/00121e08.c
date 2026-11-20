/* Decompiled from supplied 5.2.2 arm package. VA 0x121e08. colorWellTap: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::colorWellTap_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  _objc_retain(param_3);
  uVar2 = _objc_msgSend(param_3,PTR_s_tag_0114b868);
  _objc_msgSend(param_1,PTR_s__cellForTag__0114d510,uVar2);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR__OBJC_CLASS___NSKeyedArchiver_0114ec48;
  if (lVar3 != 0) {
    _objc_msgSend(param_3,PTR_s_selectedColor_0114d568);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar1,PTR_s_archivedDataWithRootObject_requi_0114b6f8,uVar2,0,0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar2);
    _objc_msgSend(param_1,PTR_s_defaults_0114d278);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar3,PTR_s_key_0114c8f8);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_setObject_forKey__0114c2b8,uVar4,uVar5);
    _objc_release(uVar5);
    _objc_release(uVar2);
    _objc_release(uVar4);
  }
  _objc_release(lVar3);
  _objc_release(param_3);
  CallSupervisor(0x3c2a);
  return;
}


