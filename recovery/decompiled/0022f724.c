/* Decompiled from supplied 5.2.2 arm package. VA 0x22f724. resizeImage:toSize: */

/* Function Stack Size: 0x20 bytes */

ID YTLHelper::resizeImage_toSize_(ID param_1,SEL param_2,ID param_3,double param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  undefined *local_70;
  undefined8 local_68;
  code *local_60;
  undefined *puStack_58;
  ID local_50;
  double local_48;
  
  _objc_retain(param_3);
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIGraphicsImageRenderer_0114ec88);
  uVar2 = _objc_msgSend(param_4,param_4,uVar2,PTR_s_initWithSize__0114b938);
  puVar1 = PTR_s_imageWithActions__0114b950;
  local_70 = PTR___NSConcreteGlobalBlock_01060658;
  local_68 = DAT_00c4c2a8;
  local_60 = FUN_0022f804;
  puStack_58 = &DAT_010624f0;
  local_50 = param_3;
  local_48 = param_4;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,&local_70);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(local_50);
  _objc_release(param_3);
  _objc_release(uVar2);
  IVar4 = _objc_autoreleaseReturnValue(uVar3);
  return IVar4;
}


