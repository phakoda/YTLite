/* Decompiled from supplied 5.2.2 arm package. VA 0x1ce0f4. FUN_001ce0f4 */

undefined1  [16] FUN_001ce0f4(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined1 auVar8 [16];
  
  uVar7 = *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x38);
  _objc_retain(uVar7);
  _objc_sync_enter();
  lVar6 = *(long *)(param_1 + 0x20);
  _objc_msgSend(*(undefined8 *)(lVar6 + 0x38),PTR_s_seekToFileOffset__0114df70,
                *(long *)(lVar6 + 0x20) * *(long *)(lVar6 + 0x30));
  _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x38),PTR_s_writeData__0114df78,
                *(undefined8 *)(param_1 + 0x28));
  _objc_sync_exit(uVar7);
  _objc_release(uVar7);
  *(long *)(*(long *)(param_1 + 0x20) + 0x30) = *(long *)(*(long *)(param_1 + 0x20) + 0x30) + 1;
  lVar6 = *(long *)(param_1 + 0x20);
  if (*(long *)(lVar6 + 0x30) == *(long *)(lVar6 + 0x28)) {
    _objc_msgSend(*(undefined8 *)(lVar6 + 0x38),PTR_s_closeFile_0114df50);
    uVar7 = _objc_loadWeakRetained(*(long *)(param_1 + 0x20) + 0x58);
    puVar1 = PTR_s_downloadDidFinish_fileName__0114df80;
    iVar3 = FUN_001cebc8(uVar7,PTR_s_respondsToSelector__0114af58,
                         PTR_s_downloadDidFinish_fileName__0114df80);
    _objc_release(uVar7);
    if (iVar3 != 0) {
      uVar7 = _objc_loadWeakRetained(*(long *)(param_1 + 0x20) + 0x58);
      puVar2 = PTR__OBJC_CLASS___NSURL_0114eb78;
      _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_getFilePath_0114df10);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puVar2,PTR_s_URLWithString__0114b3d0,uVar4);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,puVar1,uVar5,*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x18));
      _objc_release(uVar5);
      _objc_release(uVar4);
      _objc_release(uVar7);
    }
  }
  else {
    _objc_msgSend(lVar6,PTR_s_downloadNextChunk_0114df38);
  }
  CallSupervisor(0x8207);
  auVar8._8_8_ = 0x1f;
  auVar8._0_8_ = 0x1a;
  return auVar8;
}


