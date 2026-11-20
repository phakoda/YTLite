/* Decompiled from supplied 5.2.2 arm package. VA 0x166620. FUN_00166620 */

undefined1  [16] FUN_00166620(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  _objc_msgSend(PTR_DVNMediaPicker_0114eea0,PTR_s_sharedPicker_0114d7d0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_selfViewController_0114d7d8);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_presentImagePickerForVC__0114d7e0,uVar2);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0xb2c6);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


