/* Decompiled from supplied 5.2.2 arm package. VA 0x1d124c. getFilePath */

/* Function Stack Size: 0x10 bytes */

ID YTPDownloader::getFilePath(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  _objc_msgSend(param_1,PTR_s_createTempDirectoryIfNeeded_0114dfe0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_stringByAppendingPathComponent__0114b6e8;
  _objc_msgSend(uVar2,PTR_s_stringByAppendingPathComponent__0114b6e8,*(undefined8 *)(param_1 + 0x28)
               );
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  FUN_001d5658(uVar4,PTR_s_createDirectoryAtPath_withInterm_0114d050,uVar3,1,0,0);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,puVar1,*(undefined8 *)(param_1 + 0x20));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}


