/* Decompiled from supplied 5.2.2 arm package. VA 0x123508. textFieldForCell: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableViewController::textFieldForCell_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  ID IVar5;
  
  _objc_retain(param_3);
  uVar1 = _objc_alloc_init(PTR__OBJC_CLASS___UITextField_0114ee70);
  _objc_msgSend(0x402c000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,
                PTR_s_systemFontOfSize__0114b660);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_setFont__0114b5e8,uVar2);
  _objc_release(uVar2);
  _objc_msgSend(uVar1,PTR_s_setKeyboardType__0114d5f0,0);
  _objc_msgSend(uVar1,PTR_s_setReturnKeyType__0114d188,9);
  _objc_msgSend(uVar1,PTR_s_setDelegate__0114b7d8,param_1);
  _objc_msgSend(uVar1,PTR_s_setBorderStyle__0114d5f8,0);
  _objc_msgSend(uVar1,PTR_s_setTextAlignment__0114b5f8,2);
  _objc_msgSend(uVar1,PTR_s_setClearButtonMode__0114d600,1);
  _objc_msgSend(uVar1,PTR_s_setTranslatesAutoresizingMaskInt_0114b590,0);
  _objc_msgSend(param_1,PTR_s_defaults_0114d278);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,PTR_s_key_0114c8f8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_stringForKey__0114d478,uVar3);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  if (lVar4 == 0) {
    _objc_msgSend(param_3,PTR_s_placeholder_0114d588);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,PTR_s_setPlaceholder__0114d198,uVar2);
  }
  else {
    _objc_msgSend(uVar1,PTR_s_setText__0114b388,lVar4);
    _objc_msgSend(param_1,PTR_s_view_0114b090);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_tintColor_0114d1b8);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,PTR_s_setTextColor__0114b5d8,uVar3);
    _objc_release(uVar3);
  }
  _objc_release(uVar2);
  _objc_msgSend(uVar1,PTR_s_addTarget_action_forControlEvent_0114b830,param_1,
                PTR_s_titleValue__0114d608,0x20000);
  _objc_release(lVar4);
  _objc_release(param_3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar1);
  return IVar5;
}


