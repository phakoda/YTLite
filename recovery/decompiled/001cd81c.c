/* Decompiled from supplied 5.2.2 arm package. VA 0x1cd81c. cancelDownload */

/* Function Stack Size: 0x10 bytes */

void Downloader::cancelDownload(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  if (*(long *)(param_1 + 0x10) != 0) {
    _objc_msgSend(*(long *)(param_1 + 0x10),PTR_s_cancel_0114df48);
    _objc_msgSend(*(undefined8 *)(param_1 + 0x38),PTR_s_closeFile_0114df50);
    _objc_msgSend(PTR__OBJC_CLASS___NSError_0114ef98,PTR_s_errorWithDomain_code_userInfo__0114df58,
                  *(undefined8 *)PTR__NSURLErrorDomain_010603c0,0xfffffffffffffc19,0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uVar4 = _objc_loadWeakRetained(param_1 + 0x58);
    puVar1 = PTR_s_downloadDidFailureWithError__0114df60;
    uVar2 = FUN_001ce8f4(uVar4,PTR_s_respondsToSelector__0114af58,
                         PTR_s_downloadDidFailureWithError__0114df60);
    _objc_release(uVar4);
    if (uVar2 != 0) {
      uVar4 = _objc_loadWeakRetained
                        ((&PTR_LAB_011b60c0)[uVar2] + (int)-(uRam00000000011b60d0 ^ 0x80b8e188),
                         param_1 + 0x58);
      _objc_msgSend(uVar4,puVar1,uVar3);
      _objc_release(uVar4);
    }
    _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,PTR_s_getFilePath_0114df10);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    FUN_001ce95c(uVar4,PTR_s_removeItemAtPath_error__0114c378,uVar5,0);
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  CallSupervisor(0xd5f2);
  return;
}


