/* Decompiled from supplied 5.2.2 arm package. VA 0x1d42d4. URLSession:task:didCompleteWithError: */

/* Function Stack Size: 0x28 bytes */

void YTPDownloader::URLSession_task_didCompleteWithError_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  DAT_01227d84 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  if (param_5 == 0) {
    if (*(long *)(param_1 + 0x38) < *(long *)(param_1 + 0x30)) {
      _NSLog((&PTR_LAB_011b7a10)[*(long *)(param_1 + 0x38) < *(long *)(param_1 + 0x30)] +
             (int)-(uRam00000000011b7a20 ^ 0x52c6730a),
             &PTR____CFConstantStringClassReference_011b7170);
      _objc_msgSend(param_4,PTR_s_originalRequest_0114e048);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_URL_0114c578);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_1,PTR_s_continueDownloadingForURL__0114dfd8,uVar5);
    }
    else {
      _NSLog(&PTR____CFConstantStringClassReference_011b71b0);
      _objc_msgSend(param_1,PTR_s_cleanup_0114de90);
      puVar1 = PTR_s_delegate_0114b530;
      _objc_msgSend(param_1,PTR_s_delegate_0114b530);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      puVar2 = PTR_s_downloadDidFinish_fileName__0114df80;
      uVar3 = FUN_001d6464(uVar4,PTR_s_respondsToSelector__0114af58,
                           PTR_s_downloadDidFinish_fileName__0114df80);
      _objc_release(uVar4);
      if (uVar3 == 0) goto LAB_001d4ddc;
      _objc_msgSend((&PTR_LAB_011b7a28)[uVar3] + (int)-(uRam00000000011b7a38 ^ 0xf322c2ee),param_1,
                    puVar1);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_fileURLWithPath__0114c430,
                    *(undefined8 *)(param_1 + 0x50));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,puVar2,uVar5,*(undefined8 *)(param_1 + 0x20));
    }
    _objc_release(uVar5);
  }
  else {
    _objc_msgSend(param_5,PTR_s_localizedDescription_0114c618);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_001d6538(&PTR____CFConstantStringClassReference_011b71f0,uVar4);
    _objc_release(uVar4);
    puVar1 = PTR_s_delegate_0114b530;
    _objc_msgSend(param_1,PTR_s_delegate_0114b530);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_downloadDidFailureWithError__0114df60;
    uVar3 = FUN_001d6598(uVar4,PTR_s_respondsToSelector__0114af58,
                         PTR_s_downloadDidFailureWithError__0114df60);
    _objc_release(uVar4);
    if (uVar3 == 0) goto LAB_001d4ddc;
    _objc_msgSend((&PTR_LAB_011b79f0)[uVar3] + (int)-(uRam00000000011b7a00 ^ 0x6f97d6dd),param_1,
                  puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puVar2,param_5);
  }
  _objc_release(uVar4);
LAB_001d4ddc:
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x501d);
  return;
}


