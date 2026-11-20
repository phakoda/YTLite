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
  _objc_msgSend(param_5,PTR_s_componentsSeparatedByCharactersI_0114e2c8,*(undefined8 *)(param_1 + 8)
               );
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_5);
  _objc_msgSend(uVar3,PTR_s_componentsJoinedByString__0114ded0,&cf___);
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
  _objc_msgSend(*(undefined8 *)(param_1 + 0x10),PTR_s_setDelegate__0114b7d8,param_1);
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  thunk_FUN_00231ef8(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011d0140,*(undefined8 *)(param_1 + 0x28)
                    );
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_downloadFileWithURL_fileName_vid_0114e738,param_3,uVar3,
                *(undefined8 *)(param_1 + 0x28),local_80);
  _objc_release(param_3);
  _objc_release(uVar3);
  uVar2 = *(undefined8 *)(param_1 + 0x18);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_011d0100,0,0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  puStack_c0 = PTR___NSConcreteStackBlock_01060660;
  uStack_b8 = DAT_00c4c228;
  pcStack_b0 = FUN_0022b918;
  puStack_a8 = &DAT_01061420;
  IStack_a0 = param_1;
  _objc_msgSend(0,uVar2,PTR_s_showProgressWithText_progress_wi_0114e280,uVar1,1,ppuStack_88);
  _objc_release(uVar1);
  _objc_release(uVar3);
  _objc_release(param_11);
  _objc_release(param_6);
  _objc_release(param_7);
  _objc_release(param_4);
  CallSupervisor(0x697e);
  return;
}


