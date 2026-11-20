/* Decompiled from supplied 5.2.2 arm package. VA 0x1ce31c. URLSession:task:didCompleteWithError: */

/* Function Stack Size: 0x28 bytes */

void Downloader::URLSession_task_didCompleteWithError_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  _objc_retain(param_5);
  if (param_5 != 0) {
    _objc_msgSend(*(undefined8 *)(param_1 + 0x38),PTR_s_closeFile_0114df50);
    uVar3 = _objc_loadWeakRetained(param_1 + 0x58);
    puVar1 = PTR_s_downloadDidFailureWithError__0114df60;
    uVar2 = FUN_001ced58(uVar3,PTR_s_respondsToSelector__0114af58,
                         PTR_s_downloadDidFailureWithError__0114df60);
    _objc_release(uVar3);
    if (uVar2 != 0) {
      uVar3 = _objc_loadWeakRetained
                        ((&PTR_LAB_011b61c0)[uVar2] + (int)-(uRam00000000011b61d0 ^ 0x5468276d),
                         param_1 + 0x58);
      _objc_msgSend(uVar3,puVar1,param_5);
      _objc_release(uVar3);
    }
    _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,PTR_s_getFilePath_0114df10);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    FUN_001ced10(uVar3,PTR_s_removeItemAtPath_error__0114c378,uVar4,0);
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  _objc_release(param_5);
  CallSupervisor(0xb428);
  return;
}


