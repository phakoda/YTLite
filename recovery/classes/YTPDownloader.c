// Decompiled implementation evidence for YTPDownloader. Not compilable source.

// -[YTPDownloader init], 0x1cfddc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1cfddc. init */

/* Function Stack Size: 0x10 bytes */

ID YTPDownloader::init(ID param_1,SEL param_2)

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
  
  local_38 = &PTR__objc_msgSend_011b74e8;
  puStack_48 = PTR_YTPDownloader_0114f110;
  local_50 = param_1;
  IVar2 = _objc_msgSendSuper2(&local_50,@selector(init));
  puVar1 = PTR__OBJC_CLASS___NSURLSession_0114eeb0;
  local_3c = (uint)(IVar2 == 0);
  if (IVar2 != 0) {
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
    *(undefined8 *)(IVar2 + 0x48) = 0x500000;
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableDictionary_0114ed80,@selector(dictionary));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uVar4 = *(undefined8 *)(IVar2 + 0x40);
    *(undefined8 *)(IVar2 + 0x40) = uVar3;
    _objc_release(uVar4);
  }
  return IVar2;
}



// -[YTPDownloader cancelDownload], 0x1cff34
/* Decompiled from supplied 5.2.2 arm package. VA 0x1cff34. cancelDownload */

/* Function Stack Size: 0x10 bytes */

void YTPDownloader::cancelDownload(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(*(undefined8 *)(param_1 + 0x10),@selector(cancel));
  _objc_msgSend(param_1,@selector(cleanup));
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  FUN_001d5024(uVar1,@selector(removeItemAtPath:error:),*(undefined8 *)(param_1 + 0x50),0);
  _objc_release(uVar1);
  return;
}



// -[YTPDownloader cleanup], 0x1cffa8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1cffa8. cleanup */

/* Function Stack Size: 0x10 bytes */

void YTPDownloader::cleanup(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar4 = *(undefined8 *)(param_1 + 0x18);
  _objc_retain(uVar4);
  _objc_sync_enter();
  if (*(long *)(param_1 + 0x18) != 0) {
    _objc_msgSend(*(long *)(param_1 + 0x18),@selector(closeFile));
    uVar3 = *(undefined8 *)(param_1 + 0x18);
    *(undefined8 *)(param_1 + 0x18) = 0;
    _objc_release(uVar3);
  }
  _objc_sync_exit(uVar4);
  _objc_release(uVar4);
  puVar1 = @selector(defaultManager);
  if ((*(long *)(param_1 + 0x38) < *(long *)(param_1 + 0x30)) && (*(long *)(param_1 + 0x58) != 0)) {
    _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    uVar2 = FUN_001d5114(uVar4,@selector(fileExistsAtPath:),*(undefined8 *)(param_1 + 0x58));
    _objc_release(uVar4);
    if (uVar2 != 0) {
      _objc_msgSend((&PTR_LAB_011b7558)[uVar2] + (int)-(uRam00000000011b7568 ^ 0x19517958),
                    PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      FUN_001d508c(uVar4,@selector(removeItemAtPath:error:),*(undefined8 *)(param_1 + 0x58),0);
      _objc_release(uVar4);
    }
  }
  uVar4 = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x10) = 0;
  _objc_release(uVar4);
  uVar4 = *(undefined8 *)(param_1 + 0x40);
  *(undefined8 *)(param_1 + 0x40) = 0;
  (*(code *)PTR__objc_release_01061028)(uVar4);
  return;
}



// -[YTPDownloader downloadFileWithURL:fileName:videoID:fileSize:], 0x1d01c0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d01c0. downloadFileWithURL:fileName:videoID:fileSize: */

/* Function Stack Size: 0x30 bytes */

void YTPDownloader::downloadFileWithURL_fileName_videoID_fileSize_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,unsigned_long_long param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  DAT_01227d60 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_storeStrong(param_1 + 0x20,param_4);
  _objc_storeStrong(param_1 + 0x28,param_5);
  *(unsigned_long_long *)(param_1 + 0x30) = param_6;
  _objc_msgSend(param_1,@selector(getFilePath));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = *(undefined8 *)(param_1 + 0x50);
  *(undefined8 *)(param_1 + 0x50) = uVar5;
  _objc_release(uVar6);
  _objc_msgSend(param_1,@selector(getChunkMapPath));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = *(undefined8 *)(param_1 + 0x58);
  *(undefined8 *)(param_1 + 0x58) = uVar5;
  _objc_release(uVar6);
  puVar1 = @selector(defaultManager);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(fileExistsAtPath:);
  uVar3 = FUN_001d5338(uVar5,@selector(fileExistsAtPath:),*(undefined8 *)(param_1 + 0x50));
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar4 = FUN_001d5380(uVar5,puVar2,*(undefined8 *)(param_1 + 0x58));
  _objc_release(uVar5);
                    /* WARNING: Could not recover jumptable at 0x001d08b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011b7598)[uVar3 & uVar4] + (int)-(DAT_011b75a8 ^ 0x67298729)))();
  return;
}



// -[YTPDownloader hashForFile:fileSize:], 0x1d0b6c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d0b6c. hashForFile:fileSize: */

/* Function Stack Size: 0x20 bytes */

ID YTPDownloader::hashForFile_fileSize_
             (ID param_1,SEL param_2,ID param_3,unsigned_long_long param_4)

{
  CC_LONG len;
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  void *data;
  ID IVar4;
  uchar auStack_70 [32];
  undefined **local_50;
  uint local_44;
  undefined **local_40;
  long local_38;
  
  local_38 = *(long *)PTR____stack_chk_guard_01060708;
  local_40 = &PTR_LAB_011b7638;
  local_44 = (uint)(DAT_01227d64 == 0);
  local_50 = &PTR__objc_msgSend_011b7210;
  DAT_01227d64 = 1;
  thunk_FUN_001d541c(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                     @"%@%lu",param_3,param_4);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(dataUsingEncoding:),4);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_retainAutorelease();
  data = (void *)_objc_msgSend(uVar3,@selector(bytes));
  len = _objc_msgSend(uVar2,@selector(length));
  _CC_SHA256(data,len,auStack_70);
  _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,@selector(dataWithBytes:length:),auStack_70,
                0x20);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  _objc_release(uVar1);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_38) {
    IVar4 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar3);
    return IVar4;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}



// -[YTPDownloader createTempDirectoryIfNeeded], 0x1d0d50
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d0d50. createTempDirectoryIfNeeded */

/* Function Stack Size: 0x10 bytes */

ID YTPDownloader::createTempDirectoryIfNeeded(ID param_1,SEL param_2)

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
  
  local_58 = &PTR_LAB_011b7658;
  local_5c = (uint)(DAT_01227d68 == 0);
  local_70 = &PTR_LAB_011b7678;
  local_80 = &PTR_LAB_011b7690;
  local_68 = &PTR__objc_msgSend_011b7210;
  local_98 = &PTR__objc_msgSend_011b7210;
  ppuStack_90 = &PTR__objc_msgSend_011b7210;
  DAT_01227d68 = 1;
  _NSTemporaryDirectory();
  uVar2 = _objc_retainAutoreleasedReturnValue();
  acStack_b0[0] = '\0';
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar1 = FUN_001d55d0(uVar3,@selector(fileExistsAtPath:isDirectory:),uVar2,acStack_b0);
  _objc_release(uVar3);
  uStack_74 = 0;
  if (acStack_b0[0] != '\0') {
    uStack_74 = uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x001d116c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar4 = (*(code *)(local_70[uStack_74] + (int)-(DAT_011b7688 ^ 0xcbb4b3e4)))();
  return IVar4;
}



// -[YTPDownloader getFilePath], 0x1d124c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d124c. getFilePath */

/* Function Stack Size: 0x10 bytes */

ID YTPDownloader::getFilePath(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  _objc_msgSend(param_1,@selector(createTempDirectoryIfNeeded));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(stringByAppendingPathComponent:);
  _objc_msgSend(uVar2,@selector(stringByAppendingPathComponent:),*(undefined8 *)(param_1 + 0x28)
               );
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  FUN_001d5658(uVar4,@selector(createDirectoryAtPath:withIntermediateDirectories:attributes:error:),uVar3,1,0,0);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,puVar1,*(undefined8 *)(param_1 + 0x20));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// -[YTPDownloader getChunkMapPath], 0x1d1324
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d1324. getChunkMapPath */

/* Function Stack Size: 0x10 bytes */

ID YTPDownloader::getChunkMapPath(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  
  DAT_01227d70 = 1;
  _objc_msgSend(param_1,@selector(createTempDirectoryIfNeeded));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(stringByAppendingPathComponent:);
  _objc_msgSend(uVar2,@selector(stringByAppendingPathComponent:),*(undefined8 *)(param_1 + 0x28)
               );
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  FUN_001d5700(uVar4,@selector(createDirectoryAtPath:withIntermediateDirectories:attributes:error:),uVar3,1,0,0);
  _objc_release(uVar4);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),@selector(stringByDeletingPathExtension));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(stringByAppendingPathExtension:),
                @"ytpmap");
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_msgSend(uVar3,puVar1,uVar5);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  _objc_release(uVar3);
  _objc_release(uVar2);
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar6;
}



// -[YTPDownloader saveChunkMap], 0x1d1528
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d1528. saveChunkMap */

/* Function Stack Size: 0x10 bytes */

void YTPDownloader::saveChunkMap(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  ID IVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  undefined4 auStack_250 [4];
  undefined4 auStack_240 [4];
  undefined8 auStack_230 [2];
  undefined1 auStack_220 [128];
  undefined8 uStack_1a0;
  long lStack_198;
  long *plStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined4 auStack_160 [6];
  undefined8 uStack_148;
  undefined *puStack_140;
  undefined1 *puStack_138;
  undefined8 uStack_130;
  long lStack_128;
  undefined *puStack_120;
  undefined4 *puStack_118;
  undefined4 *puStack_110;
  undefined8 *puStack_108;
  undefined8 uStack_100;
  ID local_f8;
  long lStack_f0;
  undefined *puStack_e8;
  uint uStack_dc;
  undefined **local_d8;
  uint uStack_cc;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_011b76d8;
  local_7c = (uint)(DAT_01227d74 == 0);
  local_90 = &PTR_LAB_011b76f8;
  local_88 = &PTR__objc_msgSend_011b7210;
  local_a8 = &PTR__objc_msgSend_011b7210;
  ppuStack_a0 = &PTR__objc_msgSend_011b7210;
  local_b0 = &PTR_LAB_011b7720;
  local_c8 = &PTR_LAB_011b7740;
  ppuStack_c0 = &PTR__objc_msgSend_011b7210;
  local_d8 = &PTR_LAB_011b7758;
  DAT_01227d74 = 1;
  puStack_108 = auStack_230;
  puStack_110 = auStack_240;
  puStack_118 = auStack_250;
  local_f8 = param_1;
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableData_0114eba0,@selector(data));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  IVar7 = local_f8;
  _objc_msgSend(local_f8,@selector(hashForFile:fileSize:),*(undefined8 *)(local_f8 + 0x20),
                *(undefined8 *)(local_f8 + 0x30));
  uStack_148 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,@selector(appendData:));
  auStack_160[0] = _objc_msgSend(*(undefined8 *)(IVar7 + 0x40),@selector(count));
  puStack_120 = @selector(appendBytes:length:);
  uStack_100 = uVar9;
  _objc_msgSend(uVar9,@selector(appendBytes:length:),auStack_160,4);
  uStack_178 = 0;
  uStack_180 = 0;
  uStack_168 = 0;
  uStack_170 = 0;
  lStack_198 = 0;
  uStack_1a0 = 0;
  uStack_188 = 0;
  plStack_190 = (long *)0x0;
  uStack_130 = _objc_retain(*(undefined8 *)(IVar7 + 0x40));
  puStack_140 = @selector(countByEnumeratingWithState:objects:count:);
  puStack_138 = auStack_220;
  lVar10 = _objc_msgSend(uStack_130,@selector(countByEnumeratingWithState:objects:count:),&uStack_1a0,
                         auStack_220,0x10);
  puVar6 = puStack_108;
  puVar5 = puStack_110;
  puVar4 = puStack_118;
  uStack_94 = (uint)(lVar10 == 0);
  if (lVar10 == 0) {
LAB_001d1abc:
    _objc_release(uStack_130);
    uVar9 = uStack_100;
    FUN_001d5788(uStack_100,@selector(writeToFile:atomically:),*(undefined8 *)(local_f8 + 0x58),
                 1);
    _objc_release(uStack_148);
    _objc_release(uVar9);
    CallSupervisor(0xaf21);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail(0x1a,0x1f,0,0);
    }
    return;
  }
  lStack_128 = *plStack_190;
LAB_001d1874:
  puVar2 = @selector(unsignedIntValue);
  puVar1 = @selector(objectForKeyedSubscript:);
  lVar11 = 0;
  lStack_f0 = lVar10 + -1;
  puStack_e8 = @selector(unsignedLongLongValue);
  uStack_b4 = (uint)(*plStack_190 == lStack_128);
  if (*plStack_190 == lStack_128) goto LAB_001d18dc;
  do {
    _objc_enumerationMutation(uStack_130);
LAB_001d18dc:
    do {
      uVar12 = *(undefined8 *)(lStack_198 + lVar11 * 8);
      uVar9 = _objc_msgSend(uVar12,puStack_e8);
      *puVar6 = uVar9;
      _objc_msgSend(*(undefined8 *)(local_f8 + 0x40),puVar1,uVar12);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar12,puVar1,@"downloaded");
      uVar9 = _objc_retainAutoreleasedReturnValue();
      uVar8 = _objc_msgSend(uVar9,puVar2);
      _objc_release(uVar9);
      *puVar5 = uVar8;
      _objc_msgSend(uVar12,puVar1,@"full");
      uVar9 = _objc_retainAutoreleasedReturnValue();
      uVar8 = _objc_msgSend(uVar9,puVar2);
      _objc_release(uVar9);
      *puVar4 = uVar8;
      uVar9 = uStack_100;
      puVar3 = puStack_120;
      _objc_msgSend(uStack_100,puStack_120,puVar6,8);
      _objc_msgSend(uVar9,puVar3,puVar5,4);
      _objc_msgSend(uVar9,puVar3,puVar4,4);
      _objc_release(uVar12);
      uStack_cc = (uint)(lStack_f0 == lVar11);
      if (lStack_f0 == lVar11) {
        lVar10 = _objc_msgSend(uStack_130,puStack_140,&uStack_1a0,puStack_138,0x10);
        uStack_dc = (uint)(lVar10 == 0);
        if (lVar10 != 0) goto LAB_001d1874;
        uStack_dc = 1;
        goto LAB_001d1abc;
      }
      lVar11 = lVar11 + 1;
      uStack_b4 = (uint)(*plStack_190 == lStack_128);
    } while (*plStack_190 == lStack_128);
  } while( true );
}



// -[YTPDownloader loadChunkMap], 0x1d1b4c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d1b4c. loadChunkMap */

/* Function Stack Size: 0x10 bytes */

bool YTPDownloader::loadChunkMap(ID param_1,SEL param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  ulong uVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  ID IVar6;
  bool bVar7;
  bool bVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  int iVar16;
  undefined1 auStack_2b0 [128];
  undefined8 uStack_230;
  undefined8 uStack_228;
  long *plStack_220;
  undefined8 uStack_218;
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 auStack_1f0 [2];
  undefined8 auStack_1e0 [3];
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  long lStack_1b8;
  undefined *puStack_1b0;
  long lStack_1a8;
  undefined *puStack_1a0;
  undefined *puStack_198;
  undefined *puStack_190;
  int iStack_184;
  undefined8 *puStack_180;
  undefined8 *puStack_178;
  undefined1 *puStack_170;
  undefined8 uStack_168;
  ID IStack_160;
  undefined **local_158;
  undefined **local_150;
  undefined **local_140;
  undefined **local_130;
  undefined **local_128;
  uint uStack_11c;
  undefined **local_118;
  undefined **local_110;
  undefined **ppuStack_108;
  uint uStack_fc;
  undefined **local_f8;
  uint uStack_ec;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **ppuStack_c8;
  uint uStack_bc;
  undefined **local_b8;
  undefined **ppuStack_b0;
  uint uStack_a4;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_011b7770;
  local_7c = (uint)(DAT_01227d78 == 0);
  local_90 = &PTR_LAB_011b7790;
  local_a0 = &PTR_LAB_011b77a8;
  local_88 = &PTR__objc_msgSend_011b7210;
  local_b8 = &PTR_LAB_011b77c8;
  ppuStack_b0 = &PTR__objc_msgSend_011b7210;
  local_d0 = &PTR_LAB_011b77e8;
  ppuStack_c8 = &PTR__objc_msgSend_011b7210;
  local_e8 = &PTR_LAB_011b7808;
  ppuStack_e0 = &PTR__objc_msgSend_011b7210;
  local_f8 = &PTR_LAB_011b7820;
  local_110 = &PTR__objc_msgSend_011b7210;
  ppuStack_108 = &PTR__objc_msgSend_011b7210;
  local_118 = &PTR_LAB_011b7848;
  local_128 = &PTR__objc_msgSend_011b7210;
  local_130 = &PTR_LAB_011b7868;
  local_140 = &PTR_LAB_011b7880;
  local_150 = &PTR__objc_msgSend_011b7210;
  local_158 = &PTR__objc_msgSend_011b7210;
  DAT_01227d78 = 1;
  puStack_178 = auStack_1e0;
  puStack_180 = auStack_1f0;
  puStack_170 = auStack_2b0;
  _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,@selector(dataWithContentsOfFile:),
                *(undefined8 *)(param_1 + 0x58));
  lVar9 = _objc_retainAutoreleasedReturnValue();
  uStack_94 = (uint)(lVar9 == 0);
  if (lVar9 == 0) {
    bVar8 = 0;
  }
  else {
    uVar10 = _objc_retainAutorelease(local_90[uStack_94] + (int)-(DAT_011b77a0 ^ 0xa03db4e7),lVar9);
    lVar11 = _objc_msgSend(uVar10,@selector(bytes));
    _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,@selector(dataWithBytes:length:),lVar11,0x20
                 );
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,@selector(hashForFile:fileSize:),*(undefined8 *)(param_1 + 0x20),
                  *(undefined8 *)(param_1 + 0x30));
    uVar12 = _objc_retainAutoreleasedReturnValue();
    uStack_a4 = FUN_001d5a50(uVar10,@selector(isEqualToData:),uVar12);
    if (uStack_a4 == 0) {
      _NSLog(local_a0[uStack_a4] + (int)-(uRam00000000011b77b8 ^ 0x1147c12b),
             @"YTPlus --- Hash not matching, removing old files");
      _objc_msgSend(param_1,@selector(cleanup));
      bVar8 = 0;
    }
    else {
      iVar16 = *(int *)(lVar11 + 0x20);
      uStack_1c8 = uVar12;
      uStack_1c0 = uVar10;
      lStack_1b8 = lVar9;
      _objc_msgSend(PTR__OBJC_CLASS___NSMutableDictionary_0114ed80,@selector(dictionary));
      uVar10 = _objc_retainAutoreleasedReturnValue();
      uVar12 = *(undefined8 *)(param_1 + 0x40);
      *(undefined8 *)(param_1 + 0x40) = uVar10;
      IStack_160 = param_1;
      _objc_release(uVar12);
      puVar5 = puStack_180;
      puVar4 = @selector(numberWithUnsignedInt:);
      uStack_bc = (uint)(iVar16 == 0);
      iStack_184 = iVar16;
      if (iVar16 == 0) {
LAB_001d2770:
        *(undefined8 *)(IStack_160 + 0x38) = 0;
        uStack_228 = 0;
        uStack_230 = 0;
        uStack_218 = 0;
        plStack_220 = (long *)0x0;
        uStack_208 = 0;
        uStack_210 = 0;
        uStack_1f8 = 0;
        uStack_200 = 0;
        _objc_msgSend(*(undefined8 *)(IStack_160 + 0x40),@selector(allValues));
        uStack_168 = _objc_retainAutoreleasedReturnValue();
        puStack_178 = (undefined8 *)@selector(countByEnumeratingWithState:objects:count:);
        lVar9 = _objc_msgSend(uStack_168,@selector(countByEnumeratingWithState:objects:count:),&uStack_230
                              ,puStack_170,0x10);
        uStack_fc = (uint)(lVar9 == 0);
        if (lVar9 != 0) {
          uStack_11c = (uint)(*plStack_220 == *plStack_220);
                    /* WARNING: Could not recover jumptable at 0x001d2874. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          bVar8 = (*(code *)(local_118[uStack_11c] + (int)-(uRam00000000011b7858 ^ 0x57dd7b65)))();
          return bVar8;
        }
        _objc_release(uStack_168);
        bVar8 = 1;
        lVar9 = lStack_1b8;
        uVar10 = uStack_1c0;
        uVar12 = uStack_1c8;
      }
      else {
        iVar16 = 0;
        puStack_190 = @selector(numberWithUnsignedInt:);
        puStack_198 = @selector(dictionaryWithObjects:forKeys:count:);
        puStack_1a0 = @selector(numberWithUnsignedLongLong:);
        lVar9 = 0x24;
        puStack_1b0 = @selector(setObject:forKeyedSubscript:);
        lStack_1a8 = lVar11;
        while( true ) {
          IVar6 = IStack_160;
          puVar1 = (undefined8 *)(lVar11 + lVar9);
          uVar2 = *(uint *)((long)puVar1 + 0xc);
          uVar3 = (ulong)uVar2;
          bVar7 = *(ulong *)(IStack_160 + 0x48) < uVar3;
          uStack_d4 = (uint)(bVar7 || uVar2 < *(uint *)(puVar1 + 1));
          if (bVar7 || uVar2 < *(uint *)(puVar1 + 1)) break;
          uStack_168 = *puVar1;
          *puVar5 = @"downloaded";
          _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar4);
          uVar10 = _objc_retainAutoreleasedReturnValue();
          puVar1 = puStack_178;
          *puStack_178 = uVar10;
          puVar5[1] = @"full";
          _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar4,uVar3);
          uVar12 = _objc_retainAutoreleasedReturnValue();
          puVar1[1] = uVar12;
          _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puStack_198,puVar1,puVar5,2);
          uVar13 = _objc_retainAutoreleasedReturnValue();
          uVar15 = *(undefined8 *)(IVar6 + 0x40);
          _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puStack_1a0,uStack_168);
          uVar14 = _objc_retainAutoreleasedReturnValue();
          _objc_msgSend(uVar15,puStack_1b0,uVar13,uVar14);
          _objc_release(uVar14);
          _objc_release(uVar13);
          _objc_release(uVar12);
          lVar11 = lStack_1a8;
          _objc_release(uVar10);
          iVar16 = iVar16 + 1;
          uStack_ec = (uint)(iVar16 == iStack_184);
          if (iVar16 == iStack_184) goto LAB_001d2770;
          lVar9 = lVar9 + 0x10;
        }
        _NSLog(@"YTPlus --- Invalid chunk data detected, removing old files");
        _objc_msgSend(IVar6,@selector(cleanup));
        bVar8 = 0;
        lVar9 = lStack_1b8;
        uVar10 = uStack_1c0;
        uVar12 = uStack_1c8;
      }
    }
    _objc_release(uVar12);
    _objc_release(uVar10);
  }
  _objc_release(lVar9);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_70) {
    return bVar8;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}



// -[YTPDownloader continueDownloadingForURL:], 0x1d2a48
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d2a48. continueDownloadingForURL: */

/* Function Stack Size: 0x18 bytes */

void YTPDownloader::continueDownloadingForURL_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long lVar11;
  ulong uVar12;
  undefined8 uVar13;
  
  DAT_01227d7c = 1;
  _objc_retain(param_3);
  lVar7 = *(long *)(param_1 + 0x38);
  if (lVar7 < *(long *)(param_1 + 0x30)) {
    uVar13 = *(undefined8 *)(param_1 + 0x40);
    _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithLongLong:),lVar7);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(objectForKeyedSubscript:);
    _objc_msgSend(uVar13,@selector(objectForKeyedSubscript:),uVar4);
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    if (lVar5 == 0) {
      uVar8 = (lVar7 + *(long *)(param_1 + 0x48)) - 1;
      uVar12 = *(long *)(param_1 + 0x30) - 1;
      if (uVar12 <= uVar8) {
        uVar8 = uVar12;
      }
      thunk_FUN_001d5d04(@"YTPlus --- Downloading new chunk %lld-%lld",lVar7,uVar8);
      _objc_msgSend(PTR__OBJC_CLASS___NSMutableURLRequest_0114ef80,@selector(requestWithURL:),
                    param_3);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      thunk_FUN_001d5d50(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                         @"bytes=%lld-%lld",lVar7,uVar8);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,@selector(setValue:forHTTPHeaderField:),uVar13,
                    @"Range");
      _objc_release(uVar13);
      _objc_msgSend(*(undefined8 *)(param_1 + 8),@selector(dataTaskWithRequest:),uVar4);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      uVar9 = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(param_1 + 0x10) = uVar13;
      _objc_release(uVar9);
      _objc_msgSend(*(undefined8 *)(param_1 + 0x10),@selector(resume));
    }
    else {
      _objc_msgSend((&PTR_LAB_011b7900)[lVar5 == 0] + (int)-(uRam00000000011b7910 ^ 0x3ffacb7a),
                    lVar5,puVar1,@"downloaded");
      uVar4 = _objc_retainAutoreleasedReturnValue();
      puVar2 = @selector(unsignedLongLongValue);
      lVar6 = _objc_msgSend(uVar4,@selector(unsignedLongLongValue));
      lVar6 = lVar6 + lVar7;
      _objc_msgSend(lVar5,puVar1,@"full");
      uVar13 = _objc_retainAutoreleasedReturnValue();
      lVar7 = _objc_msgSend(uVar13,puVar2);
      uVar8 = _objc_msgSend(uVar4,puVar2);
      _objc_release(uVar13);
      lVar7 = ~uVar8 + lVar6 + lVar7;
      lVar11 = *(long *)(param_1 + 0x30) + -1;
      if (lVar11 <= lVar7) {
        lVar7 = lVar11;
      }
      thunk_FUN_001d5e7c(@"YTPlus --- Continuing download of chunk from %lld to %lld",lVar6,lVar7);
      _objc_msgSend(PTR__OBJC_CLASS___NSMutableURLRequest_0114ef80,@selector(requestWithURL:),
                    param_3);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      thunk_FUN_001d5ec8(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                         @"bytes=%lld-%lld",lVar6,lVar7);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar13,@selector(setValue:forHTTPHeaderField:),uVar9,
                    @"Range");
      _objc_release(uVar9);
      _objc_msgSend(*(undefined8 *)(param_1 + 8),@selector(dataTaskWithRequest:),uVar13);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      uVar10 = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(param_1 + 0x10) = uVar9;
      _objc_release(uVar10);
      _objc_msgSend(*(undefined8 *)(param_1 + 0x10),@selector(resume));
      _objc_release(uVar13);
    }
  }
  else {
    _NSLog((&PTR_LAB_011b78c8)[lVar7 < *(long *)(param_1 + 0x30)] +
           (int)-(DAT_011b78d8 ^ 0xadb623b4),@"YTPlus --- File has been downloaded");
    _objc_msgSend(param_1,@selector(cleanup));
    puVar1 = @selector(delegate);
    _objc_msgSend(param_1,@selector(delegate));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar2 = @selector(downloadDidFinish:fileName:);
    uVar3 = FUN_001d5fc8(uVar4,@selector(respondsToSelector:),
                         @selector(downloadDidFinish:fileName:));
    _objc_release(uVar4);
    if (uVar3 == 0) goto LAB_001d3904;
    _objc_msgSend((&PTR_LAB_011b78e0)[uVar3] + (int)-(uRam00000000011b78f0 ^ 0xede920aa),param_1,
                  puVar1);
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,@selector(fileURLWithPath:),
                  *(undefined8 *)(param_1 + 0x50));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar5,puVar2,uVar4,*(undefined8 *)(param_1 + 0x20));
  }
  _objc_release(uVar4);
  _objc_release(lVar5);
LAB_001d3904:
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}



// -[YTPDownloader URLSession:dataTask:didReceiveData:], 0x1d3924
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d3924. URLSession:dataTask:didReceiveData: */

/* Function Stack Size: 0x28 bytes */

void YTPDownloader::URLSession_dataTask_didReceiveData_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auStack_140 [48];
  undefined1 *puStack_110;
  ID IStack_108;
  ID IStack_100;
  ID IStack_f8;
  undefined *puStack_f0;
  undefined **local_e8;
  undefined **local_d8;
  undefined **local_d0;
  undefined **ppuStack_c8;
  undefined **local_b8;
  undefined **ppuStack_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  undefined8 local_80;
  
  local_80 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_011b7930;
  local_8c = (uint)(DAT_01227d80 == 0);
  local_a0 = &PTR_LAB_011b7950;
  local_98 = &PTR__objc_msgSend_011b7210;
  local_b8 = &PTR_LAB_011b7970;
  ppuStack_b0 = &PTR__objc_msgSend_011b7210;
  local_d0 = &PTR__objc_msgSend_011b7210;
  ppuStack_c8 = &PTR__objc_msgSend_011b7210;
  local_d8 = &PTR_LAB_011b7998;
  local_e8 = &PTR__objc_msgSend_011b7210;
  DAT_01227d80 = 1;
  puStack_110 = auStack_140;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  uVar3 = *(undefined8 *)(param_1 + 0x38);
  uVar2 = *(undefined8 *)(param_1 + 0x18);
  _objc_retain(uVar2);
  _objc_sync_enter();
  _objc_msgSend(*(undefined8 *)(param_1 + 0x18),@selector(seekToFileOffset:),uVar3);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x18),@selector(writeData:),param_5);
  IStack_100 = param_4;
  IStack_f8 = param_3;
  _objc_sync_exit(uVar2);
  _objc_release(uVar2);
  lVar1 = _objc_msgSend(param_5,@selector(length));
  uVar2 = *(undefined8 *)(param_1 + 0x40);
  *(long *)(param_1 + 0x38) = *(long *)(param_1 + 0x38) + lVar1;
  puStack_f0 = @selector(numberWithLongLong:);
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithLongLong:),uVar3);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(objectForKeyedSubscript:),uVar3);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  _objc_release(uVar3);
  uStack_a4 = (uint)(lVar1 == 0);
  IStack_108 = param_5;
                    /* WARNING: Could not recover jumptable at 0x001d3e90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_a0[uStack_a4] + (int)-(uRam00000000011b7960 ^ 0x79965837)))();
  return;
}



// -[YTPDownloader URLSession:task:didCompleteWithError:], 0x1d42d4
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
      _objc_msgSend(param_4,@selector(originalRequest));
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,@selector(URL));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_1,@selector(continueDownloadingForURL:),uVar5);
    }
    else {
      _NSLog(@"YTPlus --- File has been downloaded");
      _objc_msgSend(param_1,@selector(cleanup));
      puVar1 = @selector(delegate);
      _objc_msgSend(param_1,@selector(delegate));
      uVar4 = _objc_retainAutoreleasedReturnValue();
      puVar2 = @selector(downloadDidFinish:fileName:);
      uVar3 = FUN_001d6464(uVar4,@selector(respondsToSelector:),
                           @selector(downloadDidFinish:fileName:));
      _objc_release(uVar4);
      if (uVar3 == 0) goto LAB_001d4ddc;
      _objc_msgSend((&PTR_LAB_011b7a28)[uVar3] + (int)-(uRam00000000011b7a38 ^ 0xf322c2ee),param_1,
                    puVar1);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,@selector(fileURLWithPath:),
                    *(undefined8 *)(param_1 + 0x50));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,puVar2,uVar5,*(undefined8 *)(param_1 + 0x20));
    }
    _objc_release(uVar5);
  }
  else {
    _objc_msgSend(param_5,@selector(localizedDescription));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_001d6538(@"YTPlus --- Error while downloading: %@",uVar4);
    _objc_release(uVar4);
    puVar1 = @selector(delegate);
    _objc_msgSend(param_1,@selector(delegate));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar2 = @selector(downloadDidFailureWithError:);
    uVar3 = FUN_001d6598(uVar4,@selector(respondsToSelector:),
                         @selector(downloadDidFailureWithError:));
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



// -[YTPDownloader delegate], 0x1d4e28
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d4e28. delegate */

/* Function Stack Size: 0x10 bytes */

ID YTPDownloader::delegate(ID param_1,SEL param_2)

{
  ID IVar1;
  
  _objc_loadWeakRetained(param_1 + 0x60);
  IVar1 = _objc_autoreleaseReturnValue();
  return IVar1;
}



// -[YTPDownloader setDelegate:], 0x1d4e40
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d4e40. setDelegate: */

/* Function Stack Size: 0x18 bytes */

void YTPDownloader::setDelegate_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeWeak(param_1 + 0x60,param_3);
  CallSupervisor(0x33a8);
  return;
}



// -[YTPDownloader .cxx_destruct], 0x1d4e74
/* Decompiled from supplied 5.2.2 arm package. VA 0x1d4e74. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void YTPDownloader::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_destroyWeak(param_1 + 0x60);
  _objc_storeStrong(param_1 + 0x58,0);
  _objc_storeStrong(param_1 + 0x50,0);
  _objc_storeStrong(param_1 + 0x40,0);
  _objc_storeStrong(param_1 + 0x28,0);
  _objc_storeStrong(param_1 + 0x20,0);
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  _objc_storeStrong(param_1 + 8,0);
  CallSupervisor(0x12f);
  return;
}


