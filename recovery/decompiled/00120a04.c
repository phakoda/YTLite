/* Decompiled from supplied 5.2.2 arm package. VA 0x120a04. headerImage: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableViewController::headerImage_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  undefined *local_58;
  undefined8 local_50;
  code *local_48;
  undefined *puStack_40;
  ID local_38;
  
  _objc_retain(param_3);
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIGraphicsImageRenderer_0114ec88);
  uVar2 = _objc_msgSend(0x4030000000000000,0x4030000000000000,uVar2,PTR_s_initWithSize__0114b938);
  puVar1 = PTR_s_imageWithActions__0114b950;
  local_58 = PTR___NSConcreteGlobalBlock_01060658;
  local_50 = DAT_00c4c2a8;
  local_48 = FUN_00120afc;
  puStack_40 = &DAT_010619a0;
  local_38 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,&local_58);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  _objc_msgSend(uVar3,PTR_s_imageWithRenderingMode__0114b850,2);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(local_38);
  _objc_release(param_3);
  IVar4 = _objc_autoreleaseReturnValue(uVar2);
  return IVar4;
}


