/* Decompiled from supplied 5.2.2 arm package. VA 0x1205ac. pickerView:viewForRow:forComponent:reusingView: */

/* Function Stack Size: 0x30 bytes */

ID DVNTableViewController::pickerView_viewForRow_forComponent_reusingView_
             (ID param_1,SEL param_2,ID param_3,long_long param_4,long_long param_5,ID param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  
  _objc_retain(param_6);
  uVar1 = _objc_msgSend(param_3,PTR_s_tag_0114b868);
  _objc_msgSend(param_1,PTR_s__cellForTag__0114d510,uVar1);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_retain(param_6);
  IVar4 = param_6;
  if (param_6 == 0) {
    IVar4 = _objc_alloc_init(PTR__OBJC_CLASS___UILabel_0114ec00);
    _objc_msgSend(IVar4,PTR_s_setTextAlignment__0114b5f8,1);
    _objc_msgSend(0x402a000000000000,*(undefined8 *)PTR__UIFontWeightRegular_01060578,
                  PTR__OBJC_CLASS___UIFont_0114ec08,PTR_s_systemFontOfSize_weight__0114d330);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar4,PTR_s_setFont__0114b5e8,uVar3);
    _objc_release(uVar3);
    _objc_msgSend(param_1,PTR_s_view_0114b090);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_tintColor_0114d1b8);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar4,PTR_s_setTextColor__0114b5d8,uVar2);
    _objc_release(uVar2);
    _objc_release(uVar3);
  }
  uVar3 = _objc_msgSend(uVar1,PTR_s_sliderFormat_0114d418);
  _objc_msgSend((double)(long)param_4,param_1,PTR_s_formatSliderValue_format__0114d420,uVar3);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(IVar4,PTR_s_setText__0114b388,uVar3);
  _objc_release(uVar3);
  _objc_release(uVar1);
  _objc_release(param_6);
  IVar4 = _objc_autoreleaseReturnValue(IVar4);
  return IVar4;
}


