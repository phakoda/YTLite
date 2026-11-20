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
  _objc_msgSend(param_1,PTR_s_getFilePath_0114df10);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = *(undefined8 *)(param_1 + 0x50);
  *(undefined8 *)(param_1 + 0x50) = uVar5;
  _objc_release(uVar6);
  _objc_msgSend(param_1,PTR_s_getChunkMapPath_0114dfc0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = *(undefined8 *)(param_1 + 0x58);
  *(undefined8 *)(param_1 + 0x58) = uVar5;
  _objc_release(uVar6);
  puVar1 = PTR_s_defaultManager_0114b240;
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_fileExistsAtPath__0114c408;
  uVar3 = FUN_001d5338(uVar5,PTR_s_fileExistsAtPath__0114c408,*(undefined8 *)(param_1 + 0x50));
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


