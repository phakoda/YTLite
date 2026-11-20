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
  _objc_msgSend(param_1,PTR_s_getFilePath_0114df10);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_defaultManager_0114b240;
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  FUN_001ce778(uVar5,PTR_s_removeItemAtPath_error__0114c378,uVar4,0);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar3 = FUN_001ce7c0(uVar5,PTR_s_fileExistsAtPath__0114c408,uVar4);
  _objc_release(uVar5);
  uStack_8c = uVar3;
  if (uVar3 == 0) {
    _objc_msgSend(local_88[uVar3] + (int)-(uRam00000000011b6058 ^ 0xba3cd678),
                  PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    auStack_e0[0] = *(undefined8 *)PTR__NSFileSize_01060360;
    _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,PTR_s_numberWithUnsignedInteger__0114df18,
                  param_5);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    auStack_d0[0] = uVar6;
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                  PTR_s_dictionaryWithObjects_forKeys_co_0114b420,auStack_d0,auStack_e0,1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    FUN_001ce6e4(uVar5,PTR_s_createFileAtPath_contents_attrib_0114df20,uVar4,0,uVar7);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
  }
  _objc_msgSend(PTR__OBJC_CLASS___NSFileHandle_0114ef90,PTR_s_fileHandleForWritingAtPath__0114df28,
                uVar4);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = *(undefined8 *)(param_1 + 0x38);
  *(undefined8 *)(param_1 + 0x38) = uVar5;
  _objc_release(uVar6);
  auStack_f0[0] = 0;
  uVar3 = FUN_001ce65c(*(undefined8 *)(param_1 + 0x38),PTR_s_truncateAtOffset_error__0114df30,
                       param_5,auStack_f0);
  uVar5 = auStack_f0[0];
  _objc_retain(auStack_f0[0]);
  IVar2 = IStack_b8;
  uStack_a4 = uVar3;
  if (uVar3 == 0) {
    thunk_FUN_001ce6f8(local_a0[uVar3] + (int)-(uRam00000000011b6078 ^ 0x52bfa2ec),
                       &PTR____CFConstantStringClassReference_011b5d70,uVar5);
  }
  _objc_msgSend(param_1,PTR_s_downloadNextChunk_0114df38);
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


