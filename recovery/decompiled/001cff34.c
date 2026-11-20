/* Decompiled from supplied 5.2.2 arm package. VA 0x1cff34. cancelDownload */

/* Function Stack Size: 0x10 bytes */

void YTPDownloader::cancelDownload(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(*(undefined8 *)(param_1 + 0x10),PTR_s_cancel_0114df48);
  _objc_msgSend(param_1,PTR_s_cleanup_0114de90);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  FUN_001d5024(uVar1,PTR_s_removeItemAtPath_error__0114c378,*(undefined8 *)(param_1 + 0x50),0);
  _objc_release(uVar1);
  return;
}


