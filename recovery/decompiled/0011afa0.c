/* Decompiled from supplied 5.2.2 arm package. VA 0x11afa0. addDismissButton: */

/* Function Stack Size: 0x14 bytes */

void DVNTableViewController::addDismissButton_(ID param_1,SEL param_2,bool param_3)

{
  undefined **ppuVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIBarButtonItem_0114ee18);
  uVar2 = _objc_msgSend(uVar2,PTR_s_initWithBarButtonSystemItem_targ_0114d2c0,0x18,param_1,
                        PTR_s_closeButtonTapped_0114d2b8);
  _objc_msgSend(param_1,PTR_s_navigationItem_0114d2c8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = &PTR_s_setLeftBarButtonItem__0114d2d0;
  if (param_3 == 0) {
    ppuVar1 = &PTR_s_setRightBarButtonItem__0114d2d8;
  }
  _objc_msgSend(uVar3,*ppuVar1,uVar2);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0xcffc);
  return;
}


