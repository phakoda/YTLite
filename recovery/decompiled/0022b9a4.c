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
    _objc_msgSend(param_4,PTR_s_componentsSeparatedByCharactersI_0114e2c8,
                  *(undefined8 *)(param_1 + 8));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_componentsJoinedByString__0114ded0,&cf___);
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
  _objc_msgSend(*(undefined8 *)(param_1 + 0x10),PTR_s_setDelegate__0114b7d8,param_1);
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  uVar6 = *(undefined8 *)(param_1 + 0x50);
  thunk_FUN_00232044(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011d0220,*(undefined8 *)(param_1 + 0x28)
                    );
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_downloadFileWithURL_fileName_vid_0114e738,uVar6,uVar3,
                *(undefined8 *)(param_1 + 0x28),*(undefined8 *)(param_1 + 0x60));
  _objc_release(uVar3);
  cVar2 = *(char *)(param_1 + 0x41);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_011d01e0,0,0);
  _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x0022be00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011d13f8)[cVar2 == '\0'] + (int)-(DAT_011d1408 ^ 0xda0deb62)))();
  return;
}


