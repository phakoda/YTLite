// Decompiled implementation evidence for YTLHelper. Not compilable source.

// -[YTLHelper init], 0x22b24c
/* Decompiled from supplied 5.2.2 arm package. VA 0x22b24c. init */

/* Function Stack Size: 0x10 bytes */

ID YTLHelper::init(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IStack_60;
  undefined *puStack_58;
  undefined **local_50;
  uint uStack_44;
  undefined **local_40;
  undefined **ppuStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011d1338;
  local_2c = (uint)(DAT_01228388 == 0);
  local_40 = &PTR__objc_msgSend_011d1358;
  ppuStack_38 = &PTR__objc_msgSend_011d0fe0;
  local_50 = &PTR__objc_msgSend_011d0fe0;
  DAT_01228388 = 1;
  puStack_58 = PTR_YTLHelper_0114f150;
  IStack_60 = param_1;
  IVar1 = _objc_msgSendSuper2(&IStack_60,@selector(init));
  uStack_44 = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    uVar2 = _objc_alloc_init(PTR_ToastView_0114ec98);
    uVar3 = *(undefined8 *)(IVar1 + 0x18);
    *(undefined8 *)(IVar1 + 0x18) = uVar2;
    _objc_release(uVar3);
    _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,
                  @selector(characterSetWithCharactersInString:),
                  @"/\\?*|\"<>");
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uVar3 = *(undefined8 *)(IVar1 + 8);
    *(undefined8 *)(IVar1 + 8) = uVar2;
    _objc_release(uVar3);
  }
  return IVar1;
}



// -[YTLHelper downloadVideoWithUrl:audioUrl:fileName:format:videoID:videoSize:audioSize:duration:captions:], 0x22b424
/* Decompiled from supplied 5.2.2 arm package. VA 0x22b424. downloadVideoWithUrl:audioUrl:fileName:format:videoID:videoSize:audioSize:duration:captions: */

/* Function Stack Size: 0x58 bytes */

void YTLHelper::
     downloadVideoWithUrl_audioUrl_fileName_format_videoID_videoSize_audioSize_duration_captions_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,ID param_7,
               unsigned_long_long param_8,unsigned_long_long param_9,unsigned_long_long param_10,
               ID param_11)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  double dVar4;
  undefined *puStack_c0;
  undefined8 uStack_b8;
  code *pcStack_b0;
  undefined *puStack_a8;
  ID IStack_a0;
  unsigned_long_long local_90;
  undefined **ppuStack_88;
  unsigned_long_long local_80;
  undefined **local_78;
  uint local_6c;
  undefined **local_68;
  
  local_90 = param_10;
  local_68 = &PTR_LAB_011d1378;
  local_6c = (uint)(DAT_0122838c == 0);
  local_78 = &PTR__objc_msgSend_011d0fe0;
  DAT_0122838c = 1;
  ppuStack_88 = &puStack_c0;
  local_80 = param_8;
  _objc_retain(param_4);
  _objc_retain(param_6);
  _objc_retain(param_7);
  _objc_retain(param_11);
  *(undefined2 *)(param_1 + 0x40) = 0;
  uVar3 = *(undefined8 *)(param_1 + 0x50);
  *(ID *)(param_1 + 0x50) = param_4;
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_retain(param_3);
  _objc_release(uVar3);
  _objc_msgSend(param_5,@selector(componentsSeparatedByCharactersInSet:),*(undefined8 *)(param_1 + 8)
               );
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_5);
  _objc_msgSend(uVar3,@selector(componentsJoinedByString:),&cf___);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(param_1 + 0x20) = uVar1;
  _objc_release(uVar2);
  _objc_release(uVar3);
  uVar3 = *(undefined8 *)(param_1 + 0x28);
  *(ID *)(param_1 + 0x28) = param_7;
  _objc_retain(param_7);
  _objc_release(uVar3);
  *(unsigned_long_long *)(param_1 + 0x60) = param_9;
  dVar4 = (double)local_90 / DAT_00c4c4a0;
  uVar3 = *(undefined8 *)(param_1 + 0x30);
  *(ID *)(param_1 + 0x30) = param_6;
  *(long *)(param_1 + 0x38) = (long)dVar4;
  _objc_retain(param_6);
  _objc_release(uVar3);
  uVar3 = *(undefined8 *)(param_1 + 0x58);
  *(ID *)(param_1 + 0x58) = param_11;
  _objc_retain(param_11);
  _objc_release(uVar3);
  uVar3 = _objc_alloc_init(PTR_YTPDownloader_0114f020);
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x10) = uVar3;
  _objc_release(uVar1);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x10),@selector(setDelegate:),param_1);
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  thunk_FUN_00231ef8(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                     @"%@_v.mp4",*(undefined8 *)(param_1 + 0x28)
                    );
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(downloadFileWithURL:fileName:videoID:fileSize:),param_3,uVar3,
                *(undefined8 *)(param_1 + 0x28),local_80);
  _objc_release(param_3);
  _objc_release(uVar3);
  uVar2 = *(undefined8 *)(param_1 + 0x18);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(localizedStringForKey:value:table:),
                @"DownloadingVideo",0,0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  puStack_c0 = PTR___NSConcreteStackBlock_01060660;
  uStack_b8 = DAT_00c4c228;
  pcStack_b0 = FUN_0022b918;
  puStack_a8 = &DAT_01061420;
  IStack_a0 = param_1;
  _objc_msgSend(0,uVar2,@selector(showProgressWithText:progress:withStop:stopCompletion:),uVar1,1,ppuStack_88);
  _objc_release(uVar1);
  _objc_release(uVar3);
  _objc_release(param_11);
  _objc_release(param_6);
  _objc_release(param_7);
  _objc_release(param_4);
  CallSupervisor(0x697e);
  return;
}



// -[YTLHelper downloadAudioWithUrl:fileName:videoID:audioSize:duration:], 0x22b9a4
/* Decompiled from supplied 5.2.2 arm package. VA 0x22b9a4. downloadAudioWithUrl:fileName:videoID:audioSize:duration: */

/* Function Stack Size: 0x38 bytes */

void YTLHelper::downloadAudioWithUrl_fileName_videoID_audioSize_duration_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,unsigned_long_long param_6,
               unsigned_long_long param_7)

{
  uint uVar1;
  char cVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  DAT_0122839c = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  puVar4 = (&PTR_LAB_011d13d8)
           [(((param_3 != 0 && param_4 != 0) && param_5 != 0) && param_6 != 0) && param_7 != 0];
  uVar1 = DAT_011d13e8 ^ 0x7dd00b03;
  if ((((param_3 != 0 && param_4 != 0) && param_5 != 0) && param_6 != 0) && param_7 != 0) {
    *(undefined1 *)(param_1 + 0x41) = 1;
    _objc_storeStrong(puVar4 + (int)-uVar1,param_1 + 0x50,param_3);
    _objc_msgSend(param_4,@selector(componentsSeparatedByCharactersInSet:),
                  *(undefined8 *)(param_1 + 8));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(componentsJoinedByString:),&cf___);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar6 = *(undefined8 *)(param_1 + 0x20);
    *(undefined8 *)(param_1 + 0x20) = uVar5;
    _objc_release(uVar6);
    _objc_release(uVar3);
    _objc_storeStrong(param_1 + 0x28,param_5);
    *(unsigned_long_long *)(param_1 + 0x60) = param_6;
    *(long *)(param_1 + 0x38) = (long)((double)param_7 / DAT_00c4c4a0);
  }
  *(undefined1 *)(param_1 + 0x40) = 1;
  uVar3 = _objc_alloc_init(PTR_YTPDownloader_0114f020);
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x10) = uVar3;
  _objc_release(uVar5);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x10),@selector(setDelegate:),param_1);
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  uVar6 = *(undefined8 *)(param_1 + 0x50);
  thunk_FUN_00232044(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                     @"%@_a.m4a",*(undefined8 *)(param_1 + 0x28)
                    );
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(downloadFileWithURL:fileName:videoID:fileSize:),uVar6,uVar3,
                *(undefined8 *)(param_1 + 0x28),*(undefined8 *)(param_1 + 0x60));
  _objc_release(uVar3);
  cVar2 = *(char *)(param_1 + 0x41);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(localizedStringForKey:value:table:),
                @"DownloadingAudio",0,0);
  _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x0022be00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011d13f8)[cVar2 == '\0'] + (int)-(DAT_011d1408 ^ 0xda0deb62)))();
  return;
}



// -[YTLHelper downloadProgress:], 0x22bf60
/* Decompiled from supplied 5.2.2 arm package. VA 0x22bf60. downloadProgress: */

/* Function Stack Size: 0x14 bytes */

void YTLHelper::downloadProgress_(ID param_1,SEL param_2,float param_3)

{
  undefined **ppuVar1;
  char cVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  puVar3 = PTR__OBJC_CLASS___NSString_0114eb38;
  DAT_012283a4 = 1;
  uVar7 = *(undefined8 *)(param_1 + 0x18);
  cVar2 = *(char *)(param_1 + 0x40);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  ppuVar1 = @"DownloadingVideo";
  if (cVar2 != '\0') {
    ppuVar1 = @"DownloadingAudio";
  }
  _objc_msgSend(uVar4,@selector(localizedStringForKey:value:table:),ppuVar1,0,0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00232170((double)(param_3 * 100.0),puVar3,@selector(stringWithFormat:),
                     @"%@: %.0f%%",uVar5);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,uVar7,@selector(updateText:progress:),uVar6);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  CallSupervisor(0x4748);
  return;
}



// -[YTLHelper downloadDidFinish:fileName:], 0x22c3a4
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
  puVar2 = @selector(stringWithFormat:);
  IStack_b8 = param_3;
  thunk_FUN_00232200(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                     @"%@/%@.%@",*(undefined8 *)(param_1 + 0x28)
                     ,*(undefined8 *)(param_1 + 0x20),*(undefined8 *)(param_1 + 0x30));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(stringByAppendingPathComponent:);
  _objc_msgSend(uVar8,@selector(stringByAppendingPathComponent:),uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puVar4 = @selector(fileURLWithPath:);
  _objc_msgSend(puVar5,@selector(fileURLWithPath:),uVar10);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar5 = PTR__OBJC_CLASS___NSURL_0114eb78;
  _NSTemporaryDirectory();
  uVar8 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00232290(PTR__OBJC_CLASS___NSString_0114eb38,puVar2,
                     @"%@/%@.m4a",*(undefined8 *)(param_1 + 0x28)
                     ,*(undefined8 *)(param_1 + 0x20));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar3,uVar9);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar5,puVar4,uVar10);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar2 = @selector(defaultManager);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(removeItemAtURL:error:);
  FUN_00232330(uVar8,@selector(removeItemAtURL:error:),uVar11,0);
  _objc_release(uVar8);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar2);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  FUN_00232378(uVar8,puVar3,uVar12,0);
  _objc_release(uVar8);
  IVar6 = IStack_b8;
  bVar7 = *(char *)(param_1 + 0x40) == '\0';
  uStack_84 = (uint)bVar7;
  if (!bVar7) {
    _objc_msgSend(*(undefined8 *)(param_1 + 0x18),@selector(hide));
    cVar1 = *(char *)(param_1 + 0x41);
    _objc_msgSend(PTR_FFMpegHelper_0114f028,@selector(sharedInstance));
    _objc_retainAutoreleasedReturnValue();
    uStack_9c = (uint)(cVar1 == '\0');
                    /* WARNING: Could not recover jumptable at 0x0022c7f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_98[uStack_9c] + (int)-(uRam00000000011d14b0 ^ 0x8b6b24af)))();
    return;
  }
  _objc_storeStrong(local_80[uStack_84] + (int)-(DAT_011d1490 ^ 0x29f19d74),param_1 + 0x48,IStack_b8
                   );
  _objc_msgSend(param_1,@selector(downloadAudioWithUrl:fileName:videoID:audioSize:duration:),0,0,0,0,0);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(IVar6);
  CallSupervisor(0x645);
  return;
}



// -[YTLHelper downloadDidFailureWithError:], 0x22dcbc
/* Decompiled from supplied 5.2.2 arm package. VA 0x22dcbc. downloadDidFailureWithError: */

/* Function Stack Size: 0x18 bytes */

void YTLHelper::downloadDidFailureWithError_(ID param_1,SEL param_2,ID param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_012283bc = 1;
  _objc_retain(param_3);
  if (param_3 != 0) {
    lVar1 = _objc_msgSend(param_3,@selector(code));
    if (lVar1 != -999) {
      thunk_FUN_00232c44((&PTR_LAB_011d1620)[lVar1 == -999] +
                         (int)-(uRam00000000011d1630 ^ 0x400b7b2e),
                         @"YTPlus --- %@",param_3);
      uVar3 = *(undefined8 *)(param_1 + 0x18);
      _objc_msgSend(param_3,@selector(localizedDescription));
      uVar2 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar3,@selector(showMessageWithText:isSuccess:),uVar2,0);
      _objc_release(uVar2);
    }
  }
  _objc_release(param_3);
  CallSupervisor(0xfe78);
  return;
}



// -[YTLHelper saveMedia:], 0x22df30
/* Decompiled from supplied 5.2.2 arm package. VA 0x22df30. saveMedia: */

/* Function Stack Size: 0x18 bytes */

void YTLHelper::saveMedia_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *puStack_f0;
  undefined8 uStack_e8;
  code *pcStack_e0;
  undefined *puStack_d8;
  ID IStack_d0;
  ID IStack_c8;
  undefined *puStack_c0;
  undefined8 uStack_b8;
  code *pcStack_b0;
  undefined *puStack_a8;
  ID IStack_a0;
  undefined **local_88;
  undefined **ppuStack_80;
  int iStack_74;
  undefined **local_70;
  undefined **local_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR__av_write_image_line2_011d1640;
  local_5c = (uint)(DAT_012283c0 == 0);
  local_70 = &PTR_LAB_011d1660;
  local_68 = &PTR__objc_msgSend_011d0fe0;
  local_88 = &PTR__objc_msgSend_011d0fe0;
  ppuStack_80 = &PTR__objc_msgSend_011d0fe0;
  DAT_012283c0 = 1;
  uVar3 = _objc_retain(param_3);
  _objc_msgSend(uVar3,@selector(pathExtension));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_00232d44(uVar3,@selector(isEqualToString:),
                       @"m4a");
  _objc_release(uVar3);
  iStack_74 = iVar2;
  if (iVar2 == 0) {
    _objc_msgSend(PTR__OBJC_CLASS___PHPhotoLibrary_0114ed58,@selector(sharedPhotoLibrary));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR___NSConcreteStackBlock_01060660;
    uVar3 = DAT_00c4c228;
    puStack_c0 = PTR___NSConcreteStackBlock_01060660;
    uStack_b8 = DAT_00c4c228;
    pcStack_b0 = FUN_0022e17c;
    puStack_a8 = &DAT_01061420;
    _objc_retain(param_3);
    puStack_f0 = puVar1;
    uStack_e8 = uVar3;
    pcStack_e0 = FUN_0022e1f0;
    puStack_d8 = &UNK_010631d0;
    IStack_d0 = param_1;
    IStack_a0 = param_3;
    _objc_retain();
    IStack_c8 = param_3;
    _objc_msgSend(uVar4,@selector(performChanges:completionHandler:),&puStack_c0,&puStack_f0);
    _objc_release(uVar4);
    _objc_release(IStack_c8);
    _objc_release(IStack_a0);
  }
  else {
    _objc_msgSend(param_1,@selector(shareMedia:),param_3);
  }
  _objc_release(param_3);
  return;
}



// -[YTLHelper shareMedia:], 0x22e4ac
/* Decompiled from supplied 5.2.2 arm package. VA 0x22e4ac. shareMedia: */

/* Function Stack Size: 0x18 bytes */

void YTLHelper::shareMedia_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  double in_d2;
  undefined8 in_d3;
  undefined *puStack_100;
  undefined8 uStack_f8;
  code *pcStack_f0;
  undefined *puStack_e8;
  ID IStack_e0;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  ID aIStack_c0 [2];
  ID local_b0;
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **ppuStack_90;
  uint local_84;
  undefined **local_80;
  long local_78;
  
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  local_80 = &PTR_LAB_011d16d0;
  local_84 = (uint)(DAT_012283d0 == 0);
  local_98 = &PTR__objc_msgSend_011d16f0;
  ppuStack_90 = &PTR__objc_msgSend_011d0fe0;
  local_a8 = &PTR__objc_msgSend_011d0fe0;
  DAT_012283d0 = 1;
  local_b0 = param_1;
  _objc_retain(param_3);
  uVar4 = _objc_alloc(PTR__OBJC_CLASS___UIActivityViewController_0114ede8);
  puVar2 = @selector(arrayWithObjects:count:);
  aIStack_c0[0] = param_3;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),aIStack_c0
                ,1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar4 = _objc_msgSend(uVar4,@selector(initWithActivityItems:applicationActivities:),uVar5,0);
  _objc_release(uVar5);
  uStack_d0 = *(undefined8 *)PTR__UIActivityTypeAssignToContact_01060538;
  uStack_c8 = *(undefined8 *)PTR__UIActivityTypePrint_01060540;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar2,&uStack_d0,2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(setExcludedActivityTypes:),uVar5);
  _objc_release(uVar5);
  puStack_100 = PTR___NSConcreteStackBlock_01060660;
  uStack_f8 = DAT_00c4c228;
  pcStack_f0 = FUN_0022e960;
  puStack_e8 = &UNK_01063200;
  IStack_e0 = local_b0;
  _objc_msgSend(uVar4,@selector(setCompletionWithItemsHandler:),&puStack_100);
  uVar5 = _NSClassFromString(@"YTUIUtils");
  _objc_msgSend(uVar5,@selector(topViewControllerForPresenting));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(popoverPresentationController);
  _objc_msgSend(uVar4,@selector(popoverPresentationController));
  lVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  uStack_9c = (uint)(lVar6 == 0);
  if (lVar6 != 0) {
    _objc_msgSend(uVar5,@selector(view));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puVar2);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,@selector(setSourceView:),uVar7);
    _objc_release(uVar8);
    _objc_release(uVar7);
    puVar3 = @selector(mainScreen);
    _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,@selector(mainScreen));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(bounds);
    _objc_msgSend(uVar7,@selector(bounds));
    _objc_release(uVar7);
    _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,puVar3);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puVar1);
    _objc_release(uVar7);
    _objc_msgSend(uVar4,puVar2);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(in_d2 * 0.5,in_d3,0,0,uVar7,@selector(setSourceRect:));
    _objc_release(uVar7);
    _objc_msgSend(uVar4,puVar2);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(setPermittedArrowDirections:),0xf);
    _objc_release(uVar7);
  }
  _objc_msgSend(uVar5,@selector(presentViewController:animated:completion:),uVar4,1,0);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(param_3);
  CallSupervisor(0xc038);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_78) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}



// -[YTLHelper cleanup], 0x22e998
/* Decompiled from supplied 5.2.2 arm package. VA 0x22e998. cleanup */

/* Function Stack Size: 0x10 bytes */

void YTLHelper::cleanup(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  puVar1 = PTR__OBJC_CLASS___NSURL_0114eb78;
  DAT_012283d8 = 1;
  _NSTemporaryDirectory();
  uVar2 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00233138(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                     @"%@",*(undefined8 *)(param_1 + 0x28)
                    );
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(stringByAppendingPathComponent:),uVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,@selector(fileURLWithPath:),uVar4);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  FUN_002331d8(uVar2,@selector(removeItemAtURL:error:),uVar5,0);
  _objc_release(uVar2);
  _objc_release(uVar5);
  CallSupervisor(0x1622);
  return;
}



// -[YTLHelper askForAction:], 0x22eb5c
/* Decompiled from supplied 5.2.2 arm package. VA 0x22eb5c. askForAction: */

/* Function Stack Size: 0x18 bytes */

void YTLHelper::askForAction_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined **ppuVar6;
  undefined *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined1 auStack_120 [48];
  undefined *puStack_f0;
  undefined *puStack_e8;
  code *pcStack_e0;
  undefined *puStack_d8;
  undefined *puStack_d0;
  undefined8 uStack_c8;
  undefined1 auStack_c0 [8];
  undefined **ppuStack_b8;
  undefined **ppuStack_b0;
  undefined1 *puStack_a8;
  undefined1 *puStack_a0;
  undefined *local_98;
  undefined *puStack_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  
  local_78 = &PTR_LAB_011d1730;
  local_7c = (uint)(DAT_012283dc == 0);
  local_88 = &PTR__objc_msgSend_011d0fe0;
  DAT_012283dc = 1;
  ppuStack_b8 = &puStack_f0;
  puStack_a8 = auStack_120;
  ppuStack_b0 = ppuStack_b8;
  local_98 = (undefined *)param_1;
  puStack_90 = (undefined *)param_3;
  _objc_retain(param_3);
  uVar8 = _NSClassFromString(@"YTDefaultSheetController");
  puVar2 = @selector(ytl_defaultBundle);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(localizedStringForKey:value:table:);
  _objc_msgSend(uVar9,@selector(localizedStringForKey:value:table:),
                @"DownloadCompleted",0,0);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,@selector(sheetControllerWithMessage:delegate:parentResponder:),uVar10,0,0);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar10);
  _objc_release(uVar9);
  uVar9 = _NSClassFromString(@"YTActionSheetAction");
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar2);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puVar3,@"SaveToPhotos",0,0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar7 = local_98;
  _objc_msgSend(local_98,@selector(imageNamed:),@"save_photos")
  ;
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar1 = DAT_00c4c228;
  puStack_f0 = PTR___NSConcreteStackBlock_01060660;
  puStack_e8 = DAT_00c4c228;
  pcStack_e0 = FUN_0022f6ac;
  puStack_d8 = &DAT_01061c60;
  puStack_d0 = puVar7;
  puStack_a0 = auStack_c0;
  uStack_c8 = _objc_retain(puStack_90);
  puVar4 = @selector(actionWithTitle:iconImage:secondaryIconImage:accessibilityIdentifier:handler:);
  _objc_msgSend(uVar9,@selector(actionWithTitle:iconImage:secondaryIconImage:accessibilityIdentifier:handler:),uVar11,uVar12,0,0,ppuStack_b8)
  ;
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar5 = @selector(addAction:);
  _objc_msgSend(uVar8,@selector(addAction:),uVar9);
  _objc_release(uVar9);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  uVar9 = _NSClassFromString(@"YTActionSheetAction");
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar2);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puVar3,@"Share",0,0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  uVar12 = _NSClassFromString(@"YTUIResources");
  _objc_msgSend(uVar12,@selector(actionsheetShareImage));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  ppuVar6 = ppuStack_b0;
  ppuStack_b0[-6] = PTR___NSConcreteStackBlock_01060660;
  ppuVar6[-5] = puVar1;
  ppuVar6[-4] = FUN_0022f6e8;
  ppuVar6[-3] = &DAT_01061c60;
  puVar1 = puStack_90;
  ppuVar6[-2] = puVar7;
  ppuVar6[-1] = puVar1;
  _objc_retain(puVar1);
  _objc_msgSend(uVar9,puVar4,uVar11,uVar12,0,0,puStack_a8);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar5,uVar9);
  _objc_release(uVar9);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,@selector(delegate));
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,@selector(window));
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,@selector(rootViewController));
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_msgSend(uVar12,@selector(pivotBarViewController));
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,@selector(view));
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,@selector(setSourceView:),uVar10);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_msgSend(uVar8,@selector(presentFromViewController:animated:completion:),uVar12,1,0);
  _objc_release(uVar12);
  _objc_release(ppuVar6[-1]);
  _objc_release(*(undefined8 *)(puStack_a0 + -8));
  _objc_release(puVar1);
  _objc_release(uVar8);
  CallSupervisor(0x9c4b);
  return;
}



// -[YTLHelper resizeImage:toSize:], 0x22f724
/* Decompiled from supplied 5.2.2 arm package. VA 0x22f724. resizeImage:toSize: */

/* Function Stack Size: 0x20 bytes */

ID YTLHelper::resizeImage_toSize_(ID param_1,SEL param_2,ID param_3,double param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  undefined *local_70;
  undefined8 local_68;
  code *local_60;
  undefined *puStack_58;
  ID local_50;
  double local_48;
  
  _objc_retain(param_3);
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIGraphicsImageRenderer_0114ec88);
  uVar2 = _objc_msgSend(param_4,param_4,uVar2,@selector(initWithSize:));
  puVar1 = @selector(imageWithActions:);
  local_70 = PTR___NSConcreteGlobalBlock_01060658;
  local_68 = DAT_00c4c2a8;
  local_60 = FUN_0022f804;
  puStack_58 = &DAT_010624f0;
  local_50 = param_3;
  local_48 = param_4;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,&local_70);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(local_50);
  _objc_release(param_3);
  _objc_release(uVar2);
  IVar4 = _objc_autoreleaseReturnValue(uVar3);
  return IVar4;
}



// -[YTLHelper imageNamed:], 0x22f9bc
/* Decompiled from supplied 5.2.2 arm package. VA 0x22f9bc. imageNamed: */

/* Function Stack Size: 0x18 bytes */

ID YTLHelper::imageNamed_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  undefined *local_58;
  undefined8 local_50;
  code *local_48;
  undefined *puStack_40;
  ID local_38;
  
  _objc_retain(param_3);
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIGraphicsImageRenderer_0114ec88);
  uVar2 = _objc_msgSend(0x4038000000000000,0x4038000000000000,uVar2,@selector(initWithSize:));
  puVar1 = @selector(imageWithActions:);
  local_58 = PTR___NSConcreteGlobalBlock_01060658;
  local_50 = DAT_00c4c2a8;
  local_48 = FUN_0022fab0;
  puStack_40 = &DAT_010619a0;
  local_38 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,&local_58);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(imageWithRenderingMode:),2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(local_38);
  _objc_release(param_3);
  _objc_release(uVar2);
  IVar5 = _objc_autoreleaseReturnValue(uVar4);
  return IVar5;
}



// -[YTLHelper .cxx_destruct], 0x231d78
/* Decompiled from supplied 5.2.2 arm package. VA 0x231d78. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void YTLHelper::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 0x58,0);
  _objc_storeStrong(param_1 + 0x50,0);
  _objc_storeStrong(param_1 + 0x48,0);
  _objc_storeStrong(param_1 + 0x30,0);
  _objc_storeStrong(param_1 + 0x28,0);
  _objc_storeStrong(param_1 + 0x20,0);
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  _objc_storeStrong(param_1 + 8,0);
  CallSupervisor(0x8ddf);
  return;
}



// +[YTLHelper YTImageNamed:], 0x22fc70
/* Decompiled from supplied 5.2.2 arm package. VA 0x22fc70. YTImageNamed: */

/* Function Stack Size: 0x18 bytes */

ID YTLHelper::YTImageNamed_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ID IVar3;
  
  DAT_012283f8 = 1;
  _objc_retain(param_3);
  _NSClassFromString(@"YTAssetLoader");
  uVar1 = _objc_alloc();
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(mainBundle));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar1 = _objc_msgSend(uVar1,@selector(initWithBundle:),uVar2);
  _objc_release(uVar2);
  _objc_msgSend(uVar1,@selector(imageNamed:),param_3);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_release(uVar1);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[YTLHelper YTLImageNamed:], 0x22fe70
/* Decompiled from supplied 5.2.2 arm package. VA 0x22fe70. YTLImageNamed: */

/* Function Stack Size: 0x18 bytes */

ID YTLHelper::YTLImageNamed_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ID IVar3;
  
  DAT_012283fc = 1;
  _objc_retain(param_3);
  _NSClassFromString(@"YTAssetLoader");
  uVar1 = _objc_alloc();
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar1 = _objc_msgSend(uVar1,@selector(initWithBundle:),uVar2);
  _objc_release(uVar2);
  _objc_msgSend(uVar1,@selector(imageNamed:),param_3);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_release(uVar1);
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return IVar3;
}



// +[YTLHelper isConnectedToWiFi], 0x230064
/* Decompiled from supplied 5.2.2 arm package. VA 0x230064. isConnectedToWiFi */

/* Function Stack Size: 0x10 bytes */

bool YTLHelper::isConnectedToWiFi(ID param_1,SEL param_2)

{
  int iVar1;
  undefined8 uVar2;
  uint local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  local_28 = *(long *)PTR____stack_chk_guard_01060708;
  uStack_30 = 0;
  local_38 = 0x210;
  uVar2 = _SCNetworkReachabilityCreateWithAddress(0,&local_38);
  iVar1 = _SCNetworkReachabilityGetFlags(uVar2,&local_3c);
  _CFRelease(uVar2);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_28) {
    return (bool)(iVar1 != 0 && (local_3c & 0x40002) == 2);
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}



// +[YTLHelper createYTQTMButton:accessibilityLabel:buttonLabel:icon:selector:], 0x2300f8
/* Decompiled from supplied 5.2.2 arm package. VA 0x2300f8. createYTQTMButton:accessibilityLabel:buttonLabel:icon:selector: */

/* Function Stack Size: 0x38 bytes */

ID YTLHelper::createYTQTMButton_accessibilityLabel_buttonLabel_icon_selector_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,SEL param_7)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = @selector(class);
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_msgSend(param_1,puVar1);
  _objc_msgSend(0x4044000000000000,0x4044000000000000,uVar2,
                @selector(createYTQTMButton:accessibilityLabel:buttonLabel:icon:size:selector:),param_3,param_4,param_5,param_6,
                param_7);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_6);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[YTLHelper createYTQTMButton:accessibilityLabel:buttonLabel:icon:size:selector:], 0x2301d0
/* Decompiled from supplied 5.2.2 arm package. VA 0x2301d0. createYTQTMButton:accessibilityLabel:buttonLabel:icon:size:selector: */

/* Function Stack Size: 0x48 bytes */

ID YTLHelper::createYTQTMButton_accessibilityLabel_buttonLabel_icon_size_selector_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,CGSize param_7,
             SEL param_8)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  
  DAT_01228408 = 1;
  _objc_retain(param_5);
  _objc_retain(param_6);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar3 = _NSClassFromString(@"YTQTMButton");
  _objc_msgSend(uVar3,@selector(iconButton));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setAccessibilityLabel:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar3,@selector(enableNewTouchFeedback));
  if (param_6 == 0) {
    _objc_msgSend(uVar3,@selector(setTitle:forState:),param_5,0);
    _objc_msgSend(uVar3,@selector(titleLabel));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(setAdjustsFontSizeToFitWidth:),1);
    _objc_release(uVar4);
  }
  else {
    _objc_msgSend(uVar3,@selector(setImage:forState:),param_6,0);
  }
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(whiteColor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setTintColor:),uVar4);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
  _objc_msgSend(uVar3,@selector(addTarget:action:forControlEvents:),param_3,param_8,0x40);
  _objc_release(param_3);
  _objc_msgSend(uVar3,@selector(widthAnchor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(constraintEqualToConstant:);
  _objc_msgSend(param_7.field0_0x0,uVar4,@selector(constraintEqualToConstant:));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(setActive:);
  _objc_msgSend(uVar5,@selector(setActive:),1);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,@selector(heightAnchor));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_7.field1_0x8,uVar4,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,puVar1,1);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(param_6);
  _objc_release(param_5);
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar3);
  return IVar6;
}



// +[YTLHelper createOverlayButton:accessibilityLabel:buttonLabel:icon:selector:], 0x230598
/* Decompiled from supplied 5.2.2 arm package. VA 0x230598. createOverlayButton:accessibilityLabel:buttonLabel:icon:selector: */

/* Function Stack Size: 0x38 bytes */

ID YTLHelper::createOverlayButton_accessibilityLabel_buttonLabel_icon_selector_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,SEL param_7)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  
  DAT_0122840c = 1;
  _objc_retain(param_5);
  _objc_retain(param_6);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar4 = _NSClassFromString(@"YTQTMButton");
  _objc_msgSend(uVar4,@selector(iconButton));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(setAccessibilityLabel:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar4,@selector(enableNewTouchFeedback));
  if (param_6 == 0) {
    _objc_msgSend(uVar4,@selector(setTitle:forState:),param_5,0);
    _objc_msgSend(uVar4,@selector(titleLabel));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(setAdjustsFontSizeToFitWidth:),1);
  }
  else {
    _objc_msgSend(param_6,@selector(imageWithRenderingMode:),2);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(setImage:forState:),uVar5,0);
  }
  _objc_release(uVar5);
  puVar1 = @selector(whiteColor);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(whiteColor));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(setTintColor:),uVar5);
  _objc_release(uVar5);
  _objc_msgSend(uVar4,@selector(setTranslatesAutoresizingMaskIntoConstraints:),0);
  _objc_msgSend(uVar4,@selector(addTarget:action:forControlEvents:),param_3,param_7,0x40);
  _objc_release(param_3);
  _objc_msgSend(uVar4,@selector(widthAnchor));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(constraintEqualToConstant:);
  _objc_msgSend(0x4038000000000000,uVar5,@selector(constraintEqualToConstant:));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(setActive:);
  _objc_msgSend(uVar6,@selector(setActive:),1);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_msgSend(uVar4,@selector(heightAnchor));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4042000000000000,uVar5,puVar3);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,puVar2,1);
  _objc_release(uVar6);
  _objc_release(uVar5);
  puVar2 = @selector(touchFeedbackView);
  _objc_msgSend(uVar4,@selector(touchFeedbackView));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(setForceCircularTouchFeedback:),1);
  _objc_release(uVar5);
  _objc_msgSend(uVar4,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0,0xc018000000000000,0,0xc018000000000000,uVar5,
                @selector(setTouchFeedbackInsets:));
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(setCustomTouchFeedbackColor:),uVar5);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(param_6);
  _objc_release(param_5);
  IVar7 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar7;
}



// +[YTLHelper downloadImageFromURL:download:], 0x230a44
/* Decompiled from supplied 5.2.2 arm package. VA 0x230a44. downloadImageFromURL:download: */

/* Function Stack Size: 0x1c bytes */

void YTLHelper::downloadImageFromURL_download_(ID param_1,SEL param_2,ID param_3,bool param_4)

{
  undefined8 uVar1;
  long lVar2;
  ID IVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined *puStack_c0;
  undefined8 uStack_b8;
  code *pcStack_b0;
  undefined *puStack_a8;
  undefined1 uStack_a0;
  undefined **local_88;
  undefined **ppuStack_80;
  uint uStack_74;
  undefined **local_70;
  uint uStack_64;
  undefined **local_60;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011d1820;
  local_4c = (uint)(DAT_01228410 == 0);
  local_60 = &PTR_LAB_011d1840;
  local_70 = &PTR_LAB_011d1858;
  local_58 = &PTR__objc_msgSend_011d0fe0;
  local_88 = &PTR__objc_msgSend_011d0fe0;
  ppuStack_80 = &PTR__objc_msgSend_011d0fe0;
  DAT_01228410 = 1;
  uVar1 = _objc_retain(param_3);
  _objc_msgSend(uVar1,@selector(absoluteString));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uStack_64 = FUN_00234240(uVar1,@selector(containsString:),
                           @"c-fcrop");
  if (uStack_64 == 0) {
    _objc_retain(local_60[uStack_64] + (int)-(DAT_011d1850 ^ 0xe6f46a1b),param_3);
    IVar3 = param_3;
  }
  else {
    lVar2 = _objc_msgSend(uVar1,@selector(rangeOfString:),
                          @"c-fcrop");
    uStack_74 = (uint)(lVar2 == 0x7fffffffffffffff);
    if (lVar2 == 0x7fffffffffffffff) {
      IVar3 = 0;
    }
    else {
      _objc_msgSend(uVar1,@selector(substringFromIndex:),lVar2);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar1,@selector(stringByReplacingOccurrencesOfString:withString:),uVar4,
                    @"nd-v1");
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar4);
      _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,@selector(URLWithString:),uVar5);
      IVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar5);
    }
  }
  _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,@selector(sharedSession));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puStack_c0 = PTR___NSConcreteStackBlock_01060660;
  uStack_b8 = DAT_00c4c230;
  pcStack_b0 = FUN_00230ddc;
  puStack_a8 = &UNK_01063250;
  uStack_a0 = (undefined1)param_4;
  _objc_msgSend(uVar4,@selector(dataTaskWithURL:completionHandler:),IVar3,&puStack_c0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(resume));
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(IVar3);
  _objc_release(uVar1);
  _objc_release(param_3);
  return;
}



// +[YTLHelper genImageFromLayer:backgroundColor:completionHandler:], 0x231990
/* Decompiled from supplied 5.2.2 arm package. VA 0x231990. genImageFromLayer:backgroundColor:completionHandler: */

/* Function Stack Size: 0x28 bytes */

void YTLHelper::genImageFromLayer_backgroundColor_completionHandler_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,undefined4 param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 in_d2;
  undefined8 uVar4;
  undefined8 in_d3;
  
  _objc_retain(param_5);
  puVar1 = @selector(frame);
  _objc_retain(param_4);
  uVar2 = _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1);
  uVar4 = 0;
  thunk_FUN_002345ec(in_d2,in_d3,0,0);
  uVar2 = _UIGraphicsGetCurrentContext();
  uVar3 = _objc_retainAutorelease(param_4);
  uVar3 = _objc_msgSend(uVar3,@selector(CGColor));
  _objc_release(param_4);
  _CGContextSetFillColorWithColor(uVar2,uVar3);
  _objc_msgSend(param_3,puVar1);
  _objc_msgSend(param_3,puVar1);
  _CGContextFillRect(0,0,uVar4,uVar2);
  _objc_msgSend(param_3,@selector(renderInContext:),uVar2);
  _objc_release(param_3);
  _UIGraphicsGetImageFromCurrentImageContext();
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _UIGraphicsEndImageContext();
  if (param_5 != 0) {
    (**(code **)(param_5 + 0x10))(param_5,uVar2);
  }
  _objc_release(uVar2);
  _objc_release(param_5);
  CallSupervisor(0x1dc7);
  return;
}



// +[YTLHelper resizeImage:toSize:], 0x231b28
/* Decompiled from supplied 5.2.2 arm package. VA 0x231b28. resizeImage:toSize: */

/* Function Stack Size: 0x20 bytes */

ID YTLHelper::resizeImage_toSize_(ID param_1,SEL param_2,ID param_3,double param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  undefined *local_70;
  undefined8 local_68;
  code *local_60;
  undefined *puStack_58;
  ID local_50;
  double local_48;
  
  _objc_retain(param_3);
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIGraphicsImageRenderer_0114ec88);
  uVar2 = _objc_msgSend(param_4,param_4,uVar2,@selector(initWithSize:));
  puVar1 = @selector(imageWithActions:);
  local_70 = PTR___NSConcreteGlobalBlock_01060658;
  local_68 = DAT_00c4c2a8;
  local_60 = FUN_00231c08;
  puStack_58 = &DAT_010624f0;
  local_50 = param_3;
  local_48 = param_4;
  _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1,&local_70);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(local_50);
  _objc_release(param_3);
  _objc_release(uVar2);
  IVar4 = _objc_autoreleaseReturnValue(uVar3);
  return IVar4;
}


