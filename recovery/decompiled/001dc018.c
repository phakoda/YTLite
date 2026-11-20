/* Decompiled from supplied 5.2.2 arm package. VA 0x1dc018. ytlImageWithName: */

/* Function Stack Size: 0x18 bytes */

ID SbWhitelistVC::ytlImageWithName_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  
  puVar3 = PTR__OBJC_CLASS___UIImage_0114ebf8;
  puVar2 = PTR__OBJC_CLASS___NSBundle_0114eae8;
  puVar1 = PTR_s_ytl_defaultBundle_0114ae50;
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar3,PTR_s_imageNamed_inBundle_compatibleWi_0114b5c8,param_3,uVar4,0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(uVar5,PTR_s_imageWithRenderingMode__0114b850,2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  _objc_release(uVar4);
  IVar7 = _objc_autoreleaseReturnValue(uVar6);
  return IVar7;
}


