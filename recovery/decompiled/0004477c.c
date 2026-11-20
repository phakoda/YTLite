/* Decompiled from supplied 5.2.2 arm package. VA 0x4477c. FUN_0004477c */

bool FUN_0004477c(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  double dVar4;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_delegate_0114b530);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_window_0114b3b0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  dVar4 = (double)_objc_msgSend(uVar3,PTR_s_safeAreaInsets_0114b538);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(uVar1);
  return 20.0 < dVar4;
}


