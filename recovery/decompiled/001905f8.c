/* Decompiled from supplied 5.2.2 arm package. VA 0x1905f8. sliderCellWithMinimum:maximum:divider:format:key: */

/* Function Stack Size: 0x38 bytes */

ID DVNCell::sliderCellWithMinimum_maximum_divider_format_key_
             (ID param_1,SEL param_2,double param_3,double param_4,double param_5,long_long param_6,
             ID param_7)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_7);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(param_3,uVar2,PTR_s_setMinimumValue__0114d598);
  _objc_msgSend(param_4,uVar2,PTR_s_setMaximumValue__0114d5a0);
  _objc_msgSend(param_5,uVar2,PTR_s_setDividerValue__0114da00);
  _objc_msgSend(uVar2,PTR_s_setSliderFormat__0114da08,param_6);
  _objc_msgSend(uVar2,PTR_s_setType__0114bc00,6);
  _objc_msgSend(uVar2,PTR_s_setKey__0114d9d8,param_7);
  _objc_release(param_7);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}


