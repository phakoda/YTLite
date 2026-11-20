/* Decompiled from supplied 5.2.2 arm package. VA 0x190170. cellWithTitle:subtitle:titleIndexes:type:key: */

/* Function Stack Size: 0x38 bytes */

ID DVNCell::cellWithTitle_subtitle_titleIndexes_type_key_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,long_long param_6,ID param_7)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_7);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,PTR_s_setTitle__0114afc0,param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,PTR_s_setSubtitle__0114b280,param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,PTR_s_setTitleIndexes__0114d9d0,param_5);
  _objc_release(param_5);
  _objc_msgSend(uVar2,PTR_s_setType__0114bc00,param_6);
  _objc_msgSend(uVar2,PTR_s_setKey__0114d9d8,param_7);
  _objc_release(param_7);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}


