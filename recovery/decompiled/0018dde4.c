/* Decompiled from supplied 5.2.2 arm package. VA 0x18dde4. sectionWithIdentifier: */

/* Function Stack Size: 0x18 bytes */

ID DVNSection::sectionWithIdentifier_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNSection_0114ee90;
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,PTR_s_setIdentifier__0114d998,param_3);
  _objc_release(param_3);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}


