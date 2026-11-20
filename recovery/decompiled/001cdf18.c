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
  puVar3 = PTR_s_downloadProgress__0114df68;
  uVar4 = FUN_001ceac0(uVar5,PTR_s_respondsToSelector__0114af58,PTR_s_downloadProgress__0114df68);
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


