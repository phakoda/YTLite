/* Decompiled from supplied 5.2.2 arm package. VA 0x1cffa8. cleanup */

/* Function Stack Size: 0x10 bytes */

void YTPDownloader::cleanup(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar4 = *(undefined8 *)(param_1 + 0x18);
  _objc_retain(uVar4);
  _objc_sync_enter();
  if (*(long *)(param_1 + 0x18) != 0) {
    _objc_msgSend(*(long *)(param_1 + 0x18),PTR_s_closeFile_0114df50);
    uVar3 = *(undefined8 *)(param_1 + 0x18);
    *(undefined8 *)(param_1 + 0x18) = 0;
    _objc_release(uVar3);
  }
  _objc_sync_exit(uVar4);
  _objc_release(uVar4);
  puVar1 = PTR_s_defaultManager_0114b240;
  if ((*(long *)(param_1 + 0x38) < *(long *)(param_1 + 0x30)) && (*(long *)(param_1 + 0x58) != 0)) {
    _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    uVar2 = FUN_001d5114(uVar4,PTR_s_fileExistsAtPath__0114c408,*(undefined8 *)(param_1 + 0x58));
    _objc_release(uVar4);
    if (uVar2 != 0) {
      _objc_msgSend((&PTR_LAB_011b7558)[uVar2] + (int)-(uRam00000000011b7568 ^ 0x19517958),
                    PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      FUN_001d508c(uVar4,PTR_s_removeItemAtPath_error__0114c378,*(undefined8 *)(param_1 + 0x58),0);
      _objc_release(uVar4);
    }
  }
  uVar4 = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x10) = 0;
  _objc_release(uVar4);
  uVar4 = *(undefined8 *)(param_1 + 0x40);
  *(undefined8 *)(param_1 + 0x40) = 0;
  (*(code *)PTR__objc_release_01061028)(uVar4);
  return;
}


