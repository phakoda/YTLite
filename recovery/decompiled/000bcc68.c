/* Decompiled from supplied 5.2.2 arm package. VA 0xbcc68. FUN_000bcc68 */

undefined1  [16] FUN_000bcc68(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auVar6 [16];
  
  thunk_FUN_000eb7d4(0xd,1,1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_firstObject_0114b748);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  puVar1 = PTR_s_defaultManager_0114b240;
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_removeItemAtPath_error__0114c378;
  FUN_000eb84c(uVar3,PTR_s_removeItemAtPath_error__0114c378,uVar4,0);
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _NSTemporaryDirectory();
  uVar5 = _objc_retainAutoreleasedReturnValue();
  FUN_000eb8b4(uVar3,puVar2,uVar5,0);
  _objc_release(uVar5);
  _objc_release(uVar3);
  _objc_release(uVar4);
  CallSupervisor(0xda3a);
  auVar6._8_8_ = 0x1f;
  auVar6._0_8_ = 0x1a;
  return auVar6;
}


