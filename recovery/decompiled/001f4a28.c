/* Decompiled from supplied 5.2.2 arm package. VA 0x1f4a28. FUN_001f4a28 */

undefined1  [16] FUN_001f4a28(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined *puStack_120;
  undefined8 uStack_118;
  code *pcStack_110;
  undefined *puStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined *puStack_e0;
  undefined8 uStack_d8;
  code *pcStack_d0;
  undefined *puStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined **ppuStack_a8;
  undefined **local_a0;
  int iStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  
  local_78 = &PTR_LAB_011c18f8;
  local_7c = (uint)(DAT_01227fe4 == 0);
  local_90 = &PTR_LAB_011c1918;
  ppuStack_88 = &PTR_LAB_011c1600;
  local_a0 = &PTR_LAB_011c1600;
  DAT_01227fe4 = 1;
  *(undefined1 *)(*(long *)(param_1 + 0x20) + 0x28) = 1;
  *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x20) = *(undefined8 *)(param_1 + 0x50);
  uVar4 = *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x10);
  *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x10) = 0;
  _objc_release(uVar4);
  _objc_msgSend(PTR_MobileFFmpegConfig_0114efe8,PTR_s_resetStatistics_0114e270);
  uVar4 = DAT_00c4c228;
  puStack_e0 = PTR___NSConcreteStackBlock_01060660;
  uStack_d8 = DAT_00c4c228;
  pcStack_d0 = FUN_001f5368;
  puStack_c8 = &DAT_01061f70;
  uStack_c0 = *(undefined8 *)(param_1 + 0x20);
  uStack_b8 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
  ppuStack_a8 = &puStack_e0;
  _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_e0);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x30),PTR_s_URLByDeletingLastPathComponent_0114e288);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_URLByAppendingPathComponent__0114b258;
  _objc_msgSend(uVar5,PTR_s_URLByAppendingPathComponent__0114b258,
                &PTR____CFConstantStringClassReference_011be080);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,puVar1,&PTR____CFConstantStringClassReference_011be000);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,puVar1,&PTR____CFConstantStringClassReference_011be040);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_defaultManager_0114b240;
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_removeItemAtURL_error__0114dc60;
  FUN_001fd05c(uVar9,PTR_s_removeItemAtURL_error__0114dc60,uVar8,0);
  _objc_release(uVar9);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  FUN_001fd0a4(uVar9,puVar2,uVar6,0);
  _objc_release(uVar9);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_path_0114cde8);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  iVar3 = FUN_001fd10c(uVar9,PTR_s_fileExistsAtPath__0114c408,uVar10);
  _objc_release(uVar10);
  _objc_release(uVar9);
  puVar1 = PTR_MobileFFmpeg_0114eff0;
  iStack_94 = iVar3;
  if (iVar3 != 0) {
    thunk_FUN_001fcf1c(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                       &PTR____CFConstantStringClassReference_011bdfc0,uVar7,uVar8);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar1,PTR_s_execute__0114e290,uVar9);
    _objc_release(uVar9);
  }
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_getCommandWithVideoURL_audioURL__0114e298,
                *(undefined8 *)(param_1 + 0x30),*(undefined8 *)(param_1 + 0x38),
                *(undefined8 *)(param_1 + 0x40),uVar8,*(undefined8 *)(param_1 + 0x50),uVar6);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_MobileFFmpegConfig_0114efe8,PTR_s_setLogDelegate__0114e2a0,
                *(undefined8 *)(param_1 + 0x20));
  _dispatch_get_global_queue(0,0);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puStack_120 = PTR___NSConcreteStackBlock_01060660;
  uStack_118 = uVar4;
  pcStack_110 = FUN_001f55b4;
  puStack_108 = &DAT_01062f80;
  uStack_f8 = *(undefined8 *)(param_1 + 0x20);
  uStack_100 = uVar9;
  uStack_e8 = _objc_retain(*(undefined8 *)(param_1 + 0x48));
  uStack_f0 = uVar6;
  _objc_retain(uVar6);
  _objc_retain(uVar9);
  _dispatch_async(uVar10,&puStack_120);
  _objc_release(uVar10);
  _objc_release(uStack_f0);
  _objc_release(uStack_e8);
  _objc_release(uStack_100);
  _objc_release(uVar6);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar5);
  _objc_release(ppuStack_a8[5]);
  CallSupervisor(0xa817);
  return ZEXT816(0x1f);
}


