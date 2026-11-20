/* Decompiled from supplied 5.2.2 arm package. VA 0x190388. cellWithTitle:subtitle:icon:accessoryIcon:type:handler: */

/* Function Stack Size: 0x40 bytes */

ID DVNCell::cellWithTitle_subtitle_icon_accessoryIcon_type_handler_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,long_long param_7,
             ID param_8,undefined4 param_9)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_8);
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,PTR_s_setTitle__0114afc0,param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,PTR_s_setSubtitle__0114b280,param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,PTR_s_setIcon__0114d9c8,param_5);
  _objc_release(param_5);
  _objc_msgSend(uVar2,PTR_s_setAccessoryIcon__0114d9f0,param_6);
  _objc_release(param_6);
  _objc_msgSend(uVar2,PTR_s_setType__0114bc00,param_7);
  _objc_msgSend(uVar2,PTR_s_setHandler__0114d9e8,param_8);
  _objc_release(param_8);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}


