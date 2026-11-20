/* Decompiled from supplied 5.2.2 arm package. VA 0x235644. FUN_00235644 */

void FUN_00235644(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  puVar1 = PTR_s_imageWithName__0114c5b0;
  DAT_01228460 = 1;
  _objc_retain(param_4);
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,param_3);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_imageWithTintColor__0114e7d0,param_4);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_4);
  _objc_msgSend(uVar3,PTR_s_imageWithRenderingMode__0114b850,1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  thunk_FUN_00235b28(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011d1cb0,param_3);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(uVar4,PTR_s_setAccessibilityIdentifier__0114c4c8,uVar2);
  _objc_release(uVar2);
  _objc_autoreleaseReturnValue(uVar4);
  return;
}


