/* Decompiled from supplied 5.2.2 arm package. VA 0x1907c8. timePickerWithTitle:subtitle:minimum:maximum:format:key: */

/* Function Stack Size: 0x40 bytes */

ID DVNCell::timePickerWithTitle_subtitle_minimum_maximum_format_key_
             (ID param_1,SEL param_2,ID param_3,ID param_4,double param_5,double param_6,
             long_long param_7,ID param_8)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_8);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,PTR_s_setTitle__0114afc0,param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,PTR_s_setSubtitle__0114b280,param_4);
  _objc_release(param_4);
  _objc_msgSend(param_5,uVar2,PTR_s_setMinimumValue__0114d598);
  _objc_msgSend(param_6,uVar2,PTR_s_setMaximumValue__0114d5a0);
  _objc_msgSend(uVar2,PTR_s_setSliderFormat__0114da08,param_7);
  _objc_msgSend(uVar2,PTR_s_setType__0114bc00,7);
  _objc_msgSend(uVar2,PTR_s_setKey__0114d9d8,param_8);
  _objc_release(param_8);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}


