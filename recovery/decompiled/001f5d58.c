/* Decompiled from supplied 5.2.2 arm package. VA 0x1f5d58. getCommandWithVideoURL:audioURL:captionsURL:thumbnailURL:duration:outputURL: */

/* Function Stack Size: 0x40 bytes */

ID FFMpegHelper::getCommandWithVideoURL_audioURL_captionsURL_thumbnailURL_duration_outputURL_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,long_long param_7,
             ID param_8)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ID IVar8;
  
  DAT_01228010 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_retain(param_6);
  _objc_retain(param_8);
  puVar1 = PTR_s_defaultManager_0114b240;
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_path_0114cde8;
  _objc_msgSend(param_5,PTR_s_path_0114cde8);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_fileExistsAtPath__0114c408;
  uVar4 = FUN_001fd56c(uVar6,PTR_s_fileExistsAtPath__0114c408,uVar7);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_6,puVar3);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  uVar5 = FUN_001fd5d4(uVar6,puVar2,uVar7);
  _objc_release(uVar7);
  _objc_release(uVar6);
                    /* WARNING: Could not recover jumptable at 0x001f7b00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar8 = (*(code *)((&PTR_LAB_011c19e0)[uVar4 ^ 1 | uVar5 ^ 1] + (int)-(DAT_011c19f0 ^ 0xacfd1426))
          )();
  return IVar8;
}


