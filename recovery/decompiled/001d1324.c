/* Decompiled from supplied 5.2.2 arm package. VA 0x1d1324. getChunkMapPath */

/* Function Stack Size: 0x10 bytes */

ID YTPDownloader::getChunkMapPath(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  
  DAT_01227d70 = 1;
  _objc_msgSend(param_1,PTR_s_createTempDirectoryIfNeeded_0114dfe0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_stringByAppendingPathComponent__0114b6e8;
  _objc_msgSend(uVar2,PTR_s_stringByAppendingPathComponent__0114b6e8,*(undefined8 *)(param_1 + 0x28)
               );
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  FUN_001d5700(uVar4,PTR_s_createDirectoryAtPath_withInterm_0114d050,uVar3,1,0,0);
  _objc_release(uVar4);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_stringByDeletingPathExtension_0114dfe8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_stringByAppendingPathExtension__0114dff0,
                &PTR____CFConstantStringClassReference_011b6840);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_msgSend(uVar3,puVar1,uVar5);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  _objc_release(uVar3);
  _objc_release(uVar2);
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar6;
}


