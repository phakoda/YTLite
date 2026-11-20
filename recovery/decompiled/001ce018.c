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
  
  _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,PTR_s_dataWithContentsOfURL__0114c598,param_5);
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


