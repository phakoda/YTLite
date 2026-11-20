/* Decompiled from supplied 5.2.2 arm package. VA 0x18ff90. cellWithTitle:subtitle:imageIndexes:key: */

/* Function Stack Size: 0x30 bytes */

ID DVNCell::cellWithTitle_subtitle_imageIndexes_key_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,PTR_s_setTitle__0114afc0,param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,PTR_s_setSubtitle__0114b280,param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,PTR_s_setImageIndexes__0114d9e0,param_5);
  _objc_release(param_5);
  _objc_msgSend(uVar2,PTR_s_setType__0114bc00,2);
  _objc_msgSend(uVar2,PTR_s_setKey__0114d9d8,param_6);
  _objc_release(param_6);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}


