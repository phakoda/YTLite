/* Decompiled from supplied 5.2.2 arm package. VA 0x41984. FUN_00041984 */

void FUN_00041984(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  DAT_01225ec0 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0,
                &PTR____CFConstantStringClassReference_0115c2e0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_openURL_options_completionHandle_0114b878,uVar2,
                *(undefined8 *)PTR____NSDictionary0___01060678,0);
  _objc_release(uVar2);
  (*(code *)PTR__objc_release_01061028)(uVar1);
  return;
}


