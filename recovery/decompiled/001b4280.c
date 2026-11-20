/* Decompiled from supplied 5.2.2 arm package. VA 0x1b4280. x_prefs */

/* Function Stack Size: 0x10 bytes */

ID YTPMedia::x_prefs(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ID IVar3;
  
  DAT_01227a74 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_imageWithName__0114c5b0,&PTR____CFConstantStringClassReference_011b1380)
  ;
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return IVar3;
}


