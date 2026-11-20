/* Decompiled from supplied 5.2.2 arm package. VA 0x2355c0. FUN_002355c0 */

void FUN_002355c0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,PTR_s_imageNamed_inBundle_compatibleWi_0114b5c8,
                param_3,param_1,0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_imageWithRenderingMode__0114b850,2);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  _objc_autoreleaseReturnValue(uVar2);
  return;
}


