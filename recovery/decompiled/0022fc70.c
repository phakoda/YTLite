/* Decompiled from supplied 5.2.2 arm package. VA 0x22fc70. YTImageNamed: */

/* Function Stack Size: 0x18 bytes */

ID YTLHelper::YTImageNamed_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ID IVar3;
  
  DAT_012283f8 = 1;
  _objc_retain(param_3);
  _NSClassFromString(&PTR____CFConstantStringClassReference_011d0c20);
  uVar1 = _objc_alloc();
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_mainBundle_0114adf8);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar1 = _objc_msgSend(uVar1,PTR_s_initWithBundle__0114c8a0,uVar2);
  _objc_release(uVar2);
  _objc_msgSend(uVar1,PTR_s_imageNamed__0114b800,param_3);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_release(uVar1);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}


