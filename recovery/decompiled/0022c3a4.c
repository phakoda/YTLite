/* Decompiled from supplied 5.2.2 arm package. VA 0x22c3a4. downloadDidFinish:fileName: */

/* Function Stack Size: 0x20 bytes */

void YTLHelper::downloadDidFinish_fileName_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  ID IVar6;
  bool bVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined1 auStack_130 [48];
  undefined1 auStack_100 [56];
  undefined1 *puStack_c8;
  undefined1 *puStack_c0;
  ID IStack_b8;
  undefined **local_b0;
  undefined **ppuStack_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **local_90;
  uint uStack_84;
  undefined **local_80;
  undefined **local_78;
  uint local_6c;
  undefined **local_68;
  
  local_68 = &PTR_LAB_011d1460;
  local_6c = (uint)(DAT_012283a8 == 0);
  local_80 = &PTR_caseD_10_011d1480;
  local_98 = &PTR_LAB_011d14a0;
  local_78 = &PTR__objc_msgSend_011d0fe0;
  local_90 = &PTR__objc_msgSend_011d0fe0;
  local_b0 = &PTR__objc_msgSend_011d0fe0;
  ppuStack_a8 = &PTR__objc_msgSend_011d0fe0;
  DAT_012283a8 = 1;
  puStack_c0 = auStack_100;
  puStack_c8 = auStack_130;
  _objc_retain(param_3);
  puVar5 = PTR__OBJC_CLASS___NSURL_0114eb78;
  _NSTemporaryDirectory();
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_stringWithFormat__0114b378;
  IStack_b8 = param_3;
  thunk_FUN_00232200(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011d0430,*(undefined8 *)(param_1 + 0x28)
                     ,*(undefined8 *)(param_1 + 0x20),*(undefined8 *)(param_1 + 0x30));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_stringByAppendingPathComponent__0114b6e8;
  _objc_msgSend(uVar8,PTR_s_stringByAppendingPathComponent__0114b6e8,uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puVar4 = PTR_s_fileURLWithPath__0114c430;
  _objc_msgSend(puVar5,PTR_s_fileURLWithPath__0114c430,uVar10);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar5 = PTR__OBJC_CLASS___NSURL_0114eb78;
  _NSTemporaryDirectory();
  uVar8 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00232290(PTR__OBJC_CLASS___NSString_0114eb38,puVar2,
                     &PTR____CFConstantStringClassReference_011d03f0,*(undefined8 *)(param_1 + 0x28)
                     ,*(undefined8 *)(param_1 + 0x20));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar3,uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar5,puVar4,uVar10);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar2 = PTR_s_defaultManager_0114b240;
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_removeItemAtURL_error__0114dc60;
  FUN_00232330(uVar8,PTR_s_removeItemAtURL_error__0114dc60,uVar11,0);
  _objc_release(uVar8);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar2);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  FUN_00232378(uVar8,puVar3,uVar12,0);
  _objc_release(uVar8);
  IVar6 = IStack_b8;
  bVar7 = *(char *)(param_1 + 0x40) == '\0';
  uStack_84 = (uint)bVar7;
  if (!bVar7) {
    _objc_msgSend(*(undefined8 *)(param_1 + 0x18),PTR_s_hide_0114d0a0);
    cVar1 = *(char *)(param_1 + 0x41);
    _objc_msgSend(PTR_FFMpegHelper_0114f028,PTR_s_sharedInstance_0114c418);
    _objc_retainAutoreleasedReturnValue();
    uStack_9c = (uint)(cVar1 == '\0');
                    /* WARNING: Could not recover jumptable at 0x0022c7f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_98[uStack_9c] + (int)-(uRam00000000011d14b0 ^ 0x8b6b24af)))();
    return;
  }
  _objc_storeStrong(local_80[uStack_84] + (int)-(DAT_011d1490 ^ 0x29f19d74),param_1 + 0x48,IStack_b8
                   );
  _objc_msgSend(param_1,PTR_s_downloadAudioWithUrl_fileName_vi_0114cf28,0,0,0,0,0);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(IVar6);
  CallSupervisor(0x645);
  return;
}


