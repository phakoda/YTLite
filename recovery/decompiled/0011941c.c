/* Decompiled from supplied 5.2.2 arm package. VA 0x11941c. searchBarTextDidEndEditing: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::searchBarTextDidEndEditing_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  puVar1 = PTR_s_searchTextField_0114d1a8;
  _objc_retain(param_3);
  _objc_msgSend(param_3,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setRightView__0114d238,0);
  _objc_release(uVar2);
  _objc_msgSend(param_3,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setRightViewMode__0114d218,0);
  _objc_release(uVar2);
  _objc_msgSend(param_1,PTR_s__removeSearchFieldCornerRadius__0114d1c0,param_3);
  _objc_release(param_3);
  CallSupervisor(0xa87a);
  return;
}


