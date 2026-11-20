/* Decompiled from supplied 5.2.2 arm package. VA 0x1202f4. formatSliderValue:format: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::formatSliderValue_format_
             (ID param_1,SEL param_2,double param_3,long_long param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ID IVar3;
  
  DAT_0122730c = 1;
  if ((long)param_4 < 2) {
    if (param_4 == 1) {
      thunk_FUN_0012b4ec(param_3,PTR__OBJC_CLASS___NSString_0114eb38,
                         PTR_s_stringWithFormat__0114b378,
                         &PTR____CFConstantStringClassReference_0118be40);
      uVar2 = _objc_retainAutoreleasedReturnValue();
      goto LAB_00120594;
    }
  }
  else if (param_4 == 2) {
    uVar1 = _objc_alloc_init(PTR__OBJC_CLASS___NSDateComponentsFormatter_0114ee40);
    _objc_msgSend(uVar1,PTR_s_setUnitsStyle__0114d500,2);
    _objc_msgSend(param_3,uVar1,PTR_s_stringFromTimeInterval__0114d508);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar1);
    goto LAB_00120594;
  }
  thunk_FUN_0012b518(param_3,PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_0118be00);
  uVar2 = _objc_retainAutoreleasedReturnValue();
LAB_00120594:
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}


