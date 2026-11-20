/* Decompiled from supplied 5.2.2 arm package. VA 0x11b098. addLeftBarItem:image:handler: */

/* Function Stack Size: 0x28 bytes */

void DVNTableViewController::addLeftBarItem_image_handler_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,undefined4 param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 in_x6;
  undefined8 in_x7;
  undefined **ppuVar4;
  
  ppuVar4 = &PTR__objc_msgSend_0118c130;
  DAT_012272bc = 1;
  _objc_retain(param_4);
  _objc_retain(param_5);
  puVar1 = PTR__OBJC_CLASS___UIBarButtonItem_0114ee18;
  _objc_retain(param_3);
  uVar2 = _objc_alloc(puVar1);
  uVar2 = _objc_msgSend(uVar2,PTR_s_initWithTitle_style_target_actio_0114d2e8,param_3,0,param_1,
                        PTR_s__barButtonTriggered__0114d2e0,in_x6,in_x7,ppuVar4);
  _objc_release(param_3);
  if (param_4 != 0) {
    _objc_msgSend(uVar2,PTR_s_setImage__0114b8f8,param_4);
  }
  uVar3 = _objc_retainBlock(param_5);
  _objc_setAssociatedObject(uVar2,&PTR____CFConstantStringClassReference_0118bac0,uVar3,3);
  _objc_release(uVar3);
  _objc_msgSend(param_1,PTR_s_navigationItem_0114d2c8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setLeftBarButtonItem__0114d2d0,uVar2);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(param_5);
  _objc_release(param_4);
  CallSupervisor(0x1a54);
  return;
}


