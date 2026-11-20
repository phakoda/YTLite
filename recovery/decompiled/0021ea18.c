/* Decompiled from supplied 5.2.2 arm package. VA 0x21ea18. FUN_0021ea18 */

undefined1  [16] FUN_0021ea18(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0,
                *(undefined8 *)PTR__UIApplicationOpenSettingsURLString_01060550);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_openURL_options_completionHandle_0114b878,uVar2,
                *(undefined8 *)PTR____NSDictionary0___01060678,0);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0x3a13);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


