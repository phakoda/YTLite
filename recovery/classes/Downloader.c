// Decompiled implementation evidence for Downloader. Not compilable source.

// -[Downloader init], 0x1cce24
/* Decompiled from supplied 5.2.2 arm package. VA 0x1cce24. init */

/* Function Stack Size: 0x10 bytes */

ID Downloader::init(ID param_1,SEL param_2)

{
  undefined *puVar1;
  ID IVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID local_50;
  undefined *puStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_011b6008;
  puStack_48 = PTR_Downloader_0114f100;
  local_50 = param_1;
  IVar2 = _objc_msgSendSuper2(&local_50,@selector(init));
  local_3c = (uint)(IVar2 == 0);
  if (IVar2 != 0) {
    *(undefined8 *)(IVar2 + 0x20) = 0x500000;
    *(undefined8 *)(IVar2 + 0x30) = 0;
    puVar1 = PTR__OBJC_CLASS___NSURLSession_0114eeb0;
    _objc_msgSend(PTR__OBJC_CLASS___NSURLSessionConfiguration_0114ef88,
                  @selector(defaultSessionConfiguration));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSOperationQueue_0114ed28,@selector(mainQueue));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar1,@selector(sessionWithConfiguration:delegate:delegateQueue:),uVar3,IVar2,uVar4);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar6 = *(undefined8 *)(IVar2 + 8);
    *(undefined8 *)(IVar2 + 8) = uVar5;
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  return IVar2;
}



// -[Downloader downloadFileWithURL:fileName:fileSize:], 0x1ccf54
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ccf54. downloadFileWithURL:fileName:fileSize: */

/* Function Stack Size: 0x28 bytes */

void Downloader::downloadFileWithURL_fileName_fileSize_
               (ID param_1,SEL param_2,ID param_3,ID param_4,unsigned_long_long param_5)

{
  undefined *puVar1;
  ID IVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  double dVar8;
  undefined8 auStack_f0 [2];
  undefined8 auStack_e0 [2];
  undefined8 auStack_d0 [2];
  ID IStack_c0;
  ID IStack_b8;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **ppuStack_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011b6028;
  local_74 = (uint)(DAT_01227ce8 == 0);
  local_88 = &PTR_LAB_011b6048;
  ppuStack_80 = &PTR_LAB_011b5f00;
  local_a0 = &PTR_LAB_011b6068;
  ppuStack_98 = &PTR_LAB_011b5f00;
  local_b0 = &PTR_LAB_011b5f00;
  DAT_01227ce8 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  IStack_c0 = param_4;
  _objc_storeStrong(param_1 + 0x18,param_4);
  IStack_b8 = param_3;
  _objc_storeStrong(param_1 + 0x40,param_3);
  *(unsigned_long_long *)(param_1 + 0x50) = param_5;
  dVar8 = (double)NEON_ucvtf(*(undefined8 *)(param_1 + 0x20));
  *(long *)(param_1 + 0x28) = (long)((double)param_5 / dVar8);
  _objc_msgSend(param_1,@selector(getFilePath));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(defaultManager);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  FUN_001ce778(uVar5,@selector(removeItemAtPath:error:),uVar4,0);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar3 = FUN_001ce7c0(uVar5,@selector(fileExistsAtPath:),uVar4);
  _objc_release(uVar5);
  uStack_8c = uVar3;
  if (uVar3 == 0) {
    _objc_msgSend(local_88[uVar3] + (int)-(uRam00000000011b6058 ^ 0xba3cd678),
                  PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    auStack_e0[0] = *(undefined8 *)PTR__NSFileSize_01060360;
    _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithUnsignedInteger:),
                  param_5);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    auStack_d0[0] = uVar6;
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                  @selector(dictionaryWithObjects:forKeys:count:),auStack_d0,auStack_e0,1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    FUN_001ce6e4(uVar5,@selector(createFileAtPath:contents:attributes:),uVar4,0,uVar7);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
  }
  _objc_msgSend(PTR__OBJC_CLASS___NSFileHandle_0114ef90,@selector(fileHandleForWritingAtPath:),
                uVar4);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = *(undefined8 *)(param_1 + 0x38);
  *(undefined8 *)(param_1 + 0x38) = uVar5;
  _objc_release(uVar6);
  auStack_f0[0] = 0;
  uVar3 = FUN_001ce65c(*(undefined8 *)(param_1 + 0x38),@selector(truncateAtOffset:error:),
                       param_5,auStack_f0);
  uVar5 = auStack_f0[0];
  _objc_retain(auStack_f0[0]);
  IVar2 = IStack_b8;
  uStack_a4 = uVar3;
  if (uVar3 == 0) {
    thunk_FUN_001ce6f8(local_a0[uVar3] + (int)-(uRam00000000011b6078 ^ 0x52bfa2ec),
                       @"YTPlus --- Truncate failed with error: %@",uVar5);
  }
  _objc_msgSend(param_1,@selector(downloadNextChunk));
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(IStack_c0);
  _objc_release(IVar2);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}



// -[Downloader downloadNextChunk], 0x1cd570
/* Decompiled from supplied 5.2.2 arm package. VA 0x1cd570. downloadNextChunk */

/* Function Stack Size: 0x10 bytes */

void Downloader::downloadNextChunk(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  DAT_01227cec = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableURLRequest_0114ef80,@selector(requestWithURL:),
                *(undefined8 *)(param_1 + 0x40));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar4 = *(long *)(param_1 + 0x20) * *(long *)(param_1 + 0x30);
  thunk_FUN_001ce7f4(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                     @"bytes=%lu-%lu",lVar4,
                     *(long *)(param_1 + 0x20) + lVar4 + -1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(setValue:forHTTPHeaderField:),uVar2,
                @"Range");
  _objc_release(uVar2);
  _objc_msgSend(*(undefined8 *)(param_1 + 8),@selector(downloadTaskWithRequest:),uVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(resume));
  uVar3 = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x10) = uVar2;
  _objc_release(uVar3);
  _objc_release(uVar1);
  CallSupervisor(0xbf73);
  return;
}



// -[Downloader cancelDownload], 0x1cd81c
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
    _objc_msgSend(*(long *)(param_1 + 0x10),@selector(cancel));
    _objc_msgSend(*(undefined8 *)(param_1 + 0x38),@selector(closeFile));
    _objc_msgSend(PTR__OBJC_CLASS___NSError_0114ef98,@selector(errorWithDomain:code:userInfo:),
                  *(undefined8 *)PTR__NSURLErrorDomain_010603c0,0xfffffffffffffc19,0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uVar4 = _objc_loadWeakRetained(param_1 + 0x58);
    puVar1 = @selector(downloadDidFailureWithError:);
    uVar2 = FUN_001ce8f4(uVar4,@selector(respondsToSelector:),
                         @selector(downloadDidFailureWithError:));
    _objc_release(uVar4);
    if (uVar2 != 0) {
      uVar4 = _objc_loadWeakRetained
                        ((&PTR_LAB_011b60c0)[uVar2] + (int)-(uRam00000000011b60d0 ^ 0x80b8e188),
                         param_1 + 0x58);
      _objc_msgSend(uVar4,puVar1,uVar3);
      _objc_release(uVar4);
    }
    _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,@selector(getFilePath));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    FUN_001ce95c(uVar4,@selector(removeItemAtPath:error:),uVar5,0);
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  CallSupervisor(0xd5f2);
  return;
}



// -[Downloader getFilePath], 0x1cd9f8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1cd9f8. getFilePath */

/* Function Stack Size: 0x10 bytes */

ID Downloader::getFilePath(ID param_1,SEL param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  char acStack_b0 [24];
  undefined **local_98;
  undefined **ppuStack_90;
  undefined **local_80;
  uint uStack_74;
  undefined **local_70;
  undefined **local_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011b60e8;
  local_5c = (uint)(DAT_01227cf4 == 0);
  local_70 = &PTR_LAB_011b6108;
  local_80 = &PTR_LAB_011b6120;
  local_68 = &PTR_LAB_011b5f00;
  local_98 = &PTR_LAB_011b5f00;
  ppuStack_90 = &PTR_LAB_011b5f00;
  DAT_01227cf4 = 1;
  _NSTemporaryDirectory();
  uVar2 = _objc_retainAutoreleasedReturnValue();
  acStack_b0[0] = '\0';
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar1 = FUN_001cea98(uVar3,@selector(fileExistsAtPath:isDirectory:),uVar2,acStack_b0);
  _objc_release(uVar3);
  uStack_74 = 0;
  if (acStack_b0[0] != '\0') {
    uStack_74 = uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x001cde10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar4 = (*(code *)(local_70[uStack_74] + (int)-(DAT_011b6118 ^ 0xf683adcc)))();
  return IVar4;
}



// -[Downloader URLSession:downloadTask:didWriteData:totalBytesWritten:totalBytesExpectedToWrite:], 0x1cdf18
/* Decompiled from supplied 5.2.2 arm package. VA 0x1cdf18. URLSession:downloadTask:didWriteData:totalBytesWritten:totalBytesExpectedToWrite: */

/* Function Stack Size: 0x38 bytes */

void Downloader::URLSession_downloadTask_didWriteData_totalBytesWritten_totalBytesExpectedToWrite_
               (ID param_1,SEL param_2,ID param_3,ID param_4,long_long param_5,long_long param_6,
               long_long param_7)

{
  long lVar1;
  long lVar2;
  undefined *puVar3;
  uint uVar4;
  undefined8 uVar5;
  
  lVar2 = *(long *)(param_1 + 0x50);
  lVar1 = *(long *)(param_1 + 0x48) + param_5;
  *(long *)(param_1 + 0x48) = lVar1;
  uVar5 = _objc_loadWeakRetained(param_1 + 0x58);
  puVar3 = @selector(downloadProgress:);
  uVar4 = FUN_001ceac0(uVar5,@selector(respondsToSelector:),@selector(downloadProgress:));
  _objc_release(uVar5);
  if (uVar4 != 0) {
    uVar5 = _objc_loadWeakRetained
                      ((&PTR_LAB_011b6148)[uVar4] + (int)-(DAT_011b6158 ^ 0xfdf31dda),param_1 + 0x58
                      );
    _objc_msgSend((float)lVar1 / (float)lVar2,uVar5,puVar3);
    _objc_release(uVar5);
  }
  CallSupervisor(0xc271);
  return;
}



// -[Downloader URLSession:downloadTask:didFinishDownloadingToURL:], 0x1ce018
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ce018. URLSession:downloadTask:didFinishDownloadingToURL: */

/* Function Stack Size: 0x28 bytes */

void Downloader::URLSession_downloadTask_didFinishDownloadingToURL_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  ID local_40;
  undefined8 local_38;
  
  _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,@selector(dataWithContentsOfURL:),param_5);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _dispatch_get_global_queue(0,0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_001ce0f4;
  puStack_48 = &DAT_01061f70;
  local_40 = param_1;
  local_38 = uVar1;
  _objc_retain(uVar1);
  _dispatch_async(uVar2,&local_60);
  _objc_release(uVar2);
  _objc_release(local_38);
  _objc_release(uVar1);
  CallSupervisor(0x2129);
  return;
}



// -[Downloader URLSession:task:didCompleteWithError:], 0x1ce31c
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
    _objc_msgSend(*(undefined8 *)(param_1 + 0x38),@selector(closeFile));
    uVar3 = _objc_loadWeakRetained(param_1 + 0x58);
    puVar1 = @selector(downloadDidFailureWithError:);
    uVar2 = FUN_001ced58(uVar3,@selector(respondsToSelector:),
                         @selector(downloadDidFailureWithError:));
    _objc_release(uVar3);
    if (uVar2 != 0) {
      uVar3 = _objc_loadWeakRetained
                        ((&PTR_LAB_011b61c0)[uVar2] + (int)-(uRam00000000011b61d0 ^ 0x5468276d),
                         param_1 + 0x58);
      _objc_msgSend(uVar3,puVar1,param_5);
      _objc_release(uVar3);
    }
    _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,@selector(getFilePath));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    FUN_001ced10(uVar3,@selector(removeItemAtPath:error:),uVar4,0);
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  _objc_release(param_5);
  CallSupervisor(0xb428);
  return;
}



// -[Downloader delegate], 0x1ce4c4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ce4c4. delegate */

/* Function Stack Size: 0x10 bytes */

ID Downloader::delegate(ID param_1,SEL param_2)

{
  ID IVar1;
  
  _objc_loadWeakRetained(param_1 + 0x58);
  IVar1 = _objc_autoreleaseReturnValue();
  return IVar1;
}



// -[Downloader setDelegate:], 0x1ce4dc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ce4dc. setDelegate: */

/* Function Stack Size: 0x18 bytes */

void Downloader::setDelegate_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeWeak(param_1 + 0x58,param_3);
  CallSupervisor(0x3738);
  return;
}



// -[Downloader .cxx_destruct], 0x1ce510
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ce510. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void Downloader::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_destroyWeak(param_1 + 0x58);
  _objc_storeStrong(param_1 + 0x40,0);
  _objc_storeStrong(param_1 + 0x38,0);
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  _objc_storeStrong(param_1 + 8,0);
  CallSupervisor(0xb5b);
  return;
}


