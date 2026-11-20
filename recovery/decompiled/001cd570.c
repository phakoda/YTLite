/* Decompiled from supplied 5.2.2 arm package. VA 0x1cd570. downloadNextChunk */

/* Function Stack Size: 0x10 bytes */

void Downloader::downloadNextChunk(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  DAT_01227cec = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableURLRequest_0114ef80,PTR_s_requestWithURL__0114da38,
                *(undefined8 *)(param_1 + 0x40));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar4 = *(long *)(param_1 + 0x20) * *(long *)(param_1 + 0x30);
  thunk_FUN_001ce7f4(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011b5e20,lVar4,
                     *(long *)(param_1 + 0x20) + lVar4 + -1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_setValue_forHTTPHeaderField__0114def0,uVar2,
                &PTR____CFConstantStringClassReference_011b5de0);
  _objc_release(uVar2);
  _objc_msgSend(*(undefined8 *)(param_1 + 8),PTR_s_downloadTaskWithRequest__0114df40,uVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_resume_0114d928);
  uVar3 = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x10) = uVar2;
  _objc_release(uVar3);
  _objc_release(uVar1);
  CallSupervisor(0xbf73);
  return;
}


