/* Decompiled from supplied 5.2.2 arm package. VA 0x1a6a20. tempCopyOfURL: */

/* Function Stack Size: 0x18 bytes */

ID DVNMediaPicker::tempCopyOfURL_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ID IVar8;
  long lStack_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011ae8c8;
  _objc_retain(param_3);
  puVar1 = PTR__OBJC_CLASS___NSURL_0114eb78;
  _NSTemporaryDirectory();
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_fileURLWithPath_isDirectory__0114dc58,uVar4,1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_msgSend(param_3,PTR_s_lastPathComponent_0114b500);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_URLByAppendingPathComponent__0114b258,uVar4);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  puVar1 = PTR_s_defaultManager_0114b240;
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_path_0114cde8);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  uVar3 = FUN_001a9a90(uVar4,PTR_s_fileExistsAtPath__0114c408,uVar7);
  _objc_release(uVar7);
  _objc_release(uVar4);
  local_5c = uVar3;
  if (uVar3 != 0) {
    _objc_msgSend(local_58[uVar3] + (int)-(DAT_011ae8d8 ^ 0x9660a38d),
                  PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    FUN_001a9b20(uVar4,PTR_s_removeItemAtURL_error__0114dc60,uVar6,0);
    _objc_release(uVar4);
  }
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  lStack_68 = 0;
  FUN_001a9ad8(uVar4,PTR_s_copyItemAtURL_toURL_error__0114dc68,param_3,uVar6,&lStack_68);
  lVar2 = lStack_68;
  _objc_release(uVar4);
  if (lVar2 == 0) {
    _objc_retain((&PTR_LAB_011ae8e8)[lVar2 == 0] + (int)-(uRam00000000011ae8f8 ^ 0xc022f4a8),uVar6);
    uVar4 = uVar6;
  }
  else {
    uVar4 = 0;
  }
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(param_3);
  IVar8 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar8;
}


