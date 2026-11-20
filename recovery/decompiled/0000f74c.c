/* Decompiled from supplied 5.2.2 arm package. VA 0xf74c. FUN_0000f74c */

void FUN_0000f74c(undefined8 param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  (*DAT_012258f0)();
  puVar1 = PTR_s_layer_0114ae60;
  _objc_msgSend(param_1,PTR_s_layer_0114ae60);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4028000000000000,uVar2,PTR_s_setCornerRadius__0114ae68);
  _objc_release(uVar2);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setMasksToBounds__0114ae70,1);
  _objc_release(uVar2);
  return;
}


