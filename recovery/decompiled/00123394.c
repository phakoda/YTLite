/* Decompiled from supplied 5.2.2 arm package. VA 0x123394. colorWellForKey:title: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::colorWellForKey_title_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  puVar1 = PTR_s_defaults_0114d278;
  _objc_retain(param_4);
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_objectForKey__0114b238,param_3);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_release(uVar2);
  puVar1 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  uVar2 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_class_0114ae88);
  _objc_msgSend(puVar1,PTR_s_unarchivedObjectOfClass_fromData_0114b758,uVar2,uVar3,0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar4 = _objc_alloc(PTR__OBJC_CLASS___UIColorWell_0114ee68);
  uVar4 = _objc_msgSend(0,0,0x403e000000000000,0x403e000000000000,uVar4,
                        PTR_s_initWithFrame__0114b770);
  _objc_msgSend(uVar4,PTR_s_setTitle__0114afc0,param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar4,PTR_s_setSupportsAlpha__0114d5d8,1);
  _objc_msgSend(uVar4,PTR_s_setSelectedColor__0114d5e0,uVar2);
  _objc_msgSend(uVar4,PTR_s_addTarget_action_forControlEvent_0114b830,param_1,
                PTR_s_colorWellTap__0114d5e8,0x1000);
  _objc_release(uVar2);
  _objc_release(uVar3);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}


