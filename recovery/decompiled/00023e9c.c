/* Decompiled from supplied 5.2.2 arm package. VA 0x23e9c. FUN_00023e9c */

void FUN_00023e9c(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  _objc_msgSend(param_1,PTR_s_view_0114b090);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_window_0114b3b0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  _objc_autoreleaseReturnValue(uVar2);
  return;
}


