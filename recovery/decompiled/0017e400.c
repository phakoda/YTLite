/* Decompiled from supplied 5.2.2 arm package. VA 0x17e400. openURL: */

/* Function Stack Size: 0x18 bytes */

void YTPSettingsBuilder::openURL_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_sharedApplication_0114b528;
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_0018ade0(uVar4,PTR_s_canOpenURL__0114b870,uVar3);
  _objc_release(uVar4);
  if (uVar2 != 0) {
    _objc_msgSend((&PTR_LAB_011a89b0)[uVar2] + (int)-(DAT_011a89c0 ^ 0xe09bd3b9),
                  PTR__OBJC_CLASS___UIApplication_0114ebc8,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_openURL_options_completionHandle_0114b878,uVar3,
                  *(undefined8 *)PTR____NSDictionary0___01060678,0);
    _objc_release(uVar4);
  }
  _objc_release(uVar3);
  CallSupervisor(0x8840);
  return;
}


