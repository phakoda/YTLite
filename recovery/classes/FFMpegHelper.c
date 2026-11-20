// Decompiled implementation evidence for FFMpegHelper. Not compilable source.

// -[FFMpegHelper init], 0x1f4248
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f4248. init */

/* Function Stack Size: 0x10 bytes */

ID FFMpegHelper::init(ID param_1,SEL param_2)

{
  ID IVar1;
  dispatch_queue_t pdVar2;
  undefined8 uVar3;
  ID IStack_60;
  undefined *puStack_58;
  undefined **local_50;
  uint uStack_44;
  undefined **local_40;
  undefined **ppuStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011c1878;
  local_2c = (uint)(DAT_01227fc0 == 0);
  local_40 = &PTR_LAB_011c1898;
  ppuStack_38 = &PTR_LAB_011c1600;
  local_50 = &PTR_LAB_011c1600;
  DAT_01227fc0 = 1;
  puStack_58 = PTR_FFMpegHelper_0114f130;
  IStack_60 = param_1;
  IVar1 = _objc_msgSendSuper2(&IStack_60,@selector(init));
  uStack_44 = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    pdVar2 = _dispatch_queue_create
                       (s_com_dvntm_ffmpeg_serialqueue_011bde50,(dispatch_queue_attr_t)0x0);
    uVar3 = *(undefined8 *)(IVar1 + 8);
    *(dispatch_queue_t *)(IVar1 + 8) = pdVar2;
    _objc_release(uVar3);
    *(undefined1 *)(IVar1 + 0x28) = 0;
  }
  return IVar1;
}



// -[FFMpegHelper statisticsCallback:], 0x1f4510
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f4510. statisticsCallback: */

/* Function Stack Size: 0x18 bytes */

void FFMpegHelper::statisticsCallback_(ID param_1,SEL param_2,ID param_3)

{
  undefined *local_50;
  undefined8 local_48;
  code *local_40;
  undefined *puStack_38;
  ID local_30;
  ID local_28;
  
  _objc_retain(param_3);
  local_50 = PTR___NSConcreteStackBlock_01060660;
  local_48 = DAT_00c4c228;
  local_40 = FUN_001f45b0;
  puStack_38 = &DAT_01061f70;
  local_30 = param_1;
  local_28 = param_3;
  _objc_retain(param_3);
  _dispatch_async(PTR___dispatch_main_q_01060760,&local_50);
  _objc_release(local_28);
  _objc_release(param_3);
  CallSupervisor(0x96);
  return;
}



// -[FFMpegHelper mergeVideo:withAudio:captions:duration:completion:], 0x1f4600
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f4600. mergeVideo:withAudio:captions:duration:completion: */

/* Function Stack Size: 0x38 bytes */

void FFMpegHelper::mergeVideo_withAudio_captions_duration_completion_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,long_long param_6,ID param_7
               ,undefined4 param_8)

{
  bool bVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined *puStack_f8;
  undefined8 uStack_f0;
  code *pcStack_e8;
  undefined *puStack_e0;
  ID IStack_d8;
  undefined8 uStack_d0;
  ID IStack_c8;
  ID IStack_c0;
  ID IStack_b8;
  ID IStack_b0;
  long_long lStack_a8;
  undefined *puStack_a0;
  undefined8 uStack_98;
  code *pcStack_90;
  undefined *puStack_88;
  undefined8 uStack_80;
  uint local_74;
  undefined **local_70;
  
  local_70 = &PTR_LAB_011c18b8;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_retain(param_7);
  uVar2 = _objc_alloc_init(PTR_ToastView_0114ec98);
  puStack_f8 = PTR___NSConcreteStackBlock_01060660;
  bVar1 = *(char *)(param_1 + 0x28) == '\0';
  local_74 = (uint)bVar1;
  if (!bVar1) {
    puStack_a0 = PTR___NSConcreteStackBlock_01060660;
    uStack_98 = DAT_00c4c228;
    pcStack_90 = FUN_001f47f8;
    puStack_88 = &DAT_01061420;
    _objc_retain(uVar2);
    uStack_80 = uVar2;
    _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_a0);
    _objc_release(uStack_80);
  }
  uVar3 = *(undefined8 *)(param_1 + 8);
  uStack_f0 = DAT_00c4c228;
  pcStack_e8 = FUN_001f4a28;
  puStack_e0 = &UNK_01062fb0;
  IStack_d8 = param_1;
  uStack_d0 = uVar2;
  IStack_c8 = param_3;
  IStack_c0 = param_4;
  IStack_b8 = param_5;
  IStack_b0 = param_7;
  lStack_a8 = param_6;
  _objc_retain(param_7);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  _objc_retain(uVar2);
  _dispatch_async(uVar3,&puStack_f8);
  _objc_release(IStack_b0);
  _objc_release(IStack_b8);
  _objc_release(IStack_c0);
  _objc_release(IStack_c8);
  _objc_release(uStack_d0);
  _objc_release(param_7);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_release(uVar2);
  CallSupervisor(0x4417);
  return;
}



// -[FFMpegHelper getCommandWithVideoURL:audioURL:captionsURL:thumbnailURL:duration:outputURL:], 0x1f5d58
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
  puVar1 = @selector(defaultManager);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar3 = @selector(path);
  _objc_msgSend(param_5,@selector(path));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(fileExistsAtPath:);
  uVar4 = FUN_001fd56c(uVar6,@selector(fileExistsAtPath:),uVar7);
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



// -[FFMpegHelper cutAudio:duration:completion:], 0x1f7cd8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f7cd8. cutAudio:duration:completion: */

/* Function Stack Size: 0x28 bytes */

void FFMpegHelper::cutAudio_duration_completion_
               (ID param_1,SEL param_2,ID param_3,long_long param_4,ID param_5,undefined4 param_6)

{
  bool bVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined *puStack_d0;
  undefined8 uStack_c8;
  code *pcStack_c0;
  undefined *puStack_b8;
  ID IStack_b0;
  undefined8 uStack_a8;
  ID IStack_a0;
  ID IStack_98;
  long_long lStack_90;
  undefined *puStack_88;
  undefined8 uStack_80;
  code *pcStack_78;
  undefined *puStack_70;
  undefined8 uStack_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011c1a48;
  _objc_retain(param_3);
  _objc_retain(param_5);
  uVar2 = _objc_alloc_init(PTR_ToastView_0114ec98);
  puStack_d0 = PTR___NSConcreteStackBlock_01060660;
  bVar1 = *(char *)(param_1 + 0x28) == '\0';
  local_5c = (uint)bVar1;
  if (!bVar1) {
    puStack_88 = PTR___NSConcreteStackBlock_01060660;
    uStack_80 = DAT_00c4c228;
    pcStack_78 = FUN_001f7e7c;
    puStack_70 = &DAT_01061420;
    _objc_retain(uVar2);
    uStack_68 = uVar2;
    _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_88);
    _objc_release(uStack_68);
  }
  uVar3 = *(undefined8 *)(param_1 + 8);
  uStack_c8 = DAT_00c4c228;
  pcStack_c0 = FUN_001f80b4;
  puStack_b8 = &DAT_01062bc0;
  IStack_b0 = param_1;
  uStack_a8 = uVar2;
  IStack_a0 = param_3;
  IStack_98 = param_5;
  lStack_90 = param_4;
  _objc_retain(param_5);
  _objc_retain(param_3);
  _objc_retain(uVar2);
  _dispatch_async(uVar3,&puStack_d0);
  _objc_release(IStack_98);
  _objc_release(IStack_a0);
  _objc_release(uStack_a8);
  _objc_release(param_5);
  _objc_release(param_3);
  _objc_release(uVar2);
  CallSupervisor(0xd8bf);
  return;
}



// -[FFMpegHelper logCallback:::], 0x1f912c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f912c. logCallback::: */

/* Function Stack Size: 0x24 bytes */

void FFMpegHelper::logCallback___(ID param_1,SEL param_2,long_long param_3,int param_4,ID param_5)

{
  CallSupervisor(0x11a3);
  return;
}



// -[FFMpegHelper getCleanLog:], 0x1f9148
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f9148. getCleanLog: */

/* Function Stack Size: 0x18 bytes */

void FFMpegHelper::getCleanLog_(ID param_1,SEL param_2,ID param_3)

{
                    /* WARNING: Could not recover jumptable at 0x001f9240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011c1b50)[DAT_01228034 == 0] + (int)-(DAT_011c1b60 ^ 0x96158471)))();
  return;
}



// -[FFMpegHelper setActive], 0x1f9854
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f9854. setActive */

/* Function Stack Size: 0x10 bytes */

void FFMpegHelper::setActive(ID param_1,SEL param_2)

{
  _objc_msgSend(PTR_MobileFFmpegConfig_0114efe8,@selector(setLogDelegate:),param_1);
  _objc_msgSend(PTR_MobileFFmpegConfig_0114efe8,@selector(setStatisticsDelegate:),param_1);
  CallSupervisor(0x1f03);
  return;
}



// -[FFMpegHelper updateProgressDialog], 0x1f98b4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f98b4. updateProgressDialog */

/* Function Stack Size: 0x10 bytes */

void FFMpegHelper::updateProgressDialog(ID param_1,SEL param_2)

{
  if (DAT_0122803c != 0) {
    DAT_0122803c = 1;
                    /* WARNING: Could not recover jumptable at 0x001f997c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011c1c78)[*(long *)(param_1 + 0x10) == 0] +
              (int)-(uRam00000000011c1c88 ^ 0x4106f22)))();
    return;
  }
  s_Converting_011beaed[0] = DAT_011beae2 ^ 0x80;
  s_Converting_011beaed[1] = bRam00000000011beae3 ^ 0xeb;
  s_Converting_011beaed[2] = bRam00000000011beae4 ^ 0xf;
  s_Converting_011beaed[3] = bRam00000000011beae5 ^ 0x45;
  s_Converting_011beaed[4] = bRam00000000011beae6 ^ 0xee;
  s_Converting_011beaed[5] = bRam00000000011beae7 ^ 0x11;
  s_Converting_011beaed[6] = bRam00000000011beae8 ^ 0x4f;
  s_Converting_011beaed[7] = bRam00000000011beae9 ^ 0x1e;
  s_Converting_011beaed[8] = bRam00000000011beaea ^ 0xc2;
  s_Converting_011beaed[9] = bRam00000000011beaeb ^ 0x6a;
  s_Converting_011beaed[10] = bRam00000000011beaec ^ 0x15;
  s______d___011bead9[0] = DAT_011bead0 ^ 0xc6;
  s______d___011bead9[1] = bRam00000000011bead1 ^ 0xd;
  s______d___011bead9[2] = bRam00000000011bead2 ^ 0xd8;
  s______d___011bead9[3] = bRam00000000011bead3 ^ 0xa8;
  s______d___011bead9[4] = bRam00000000011bead4 ^ 0xda;
  s______d___011bead9[5] = bRam00000000011bead5 ^ 0x80;
  s______d___011bead9[6] = bRam00000000011bead6 ^ 0x15;
  s______d___011bead9[7] = bRam00000000011bead7 ^ 0x7c;
  s______d___011bead9[8] = bRam00000000011bead8 ^ 0x54;
  DAT_0122803c = 1;
                    /* WARNING: Could not recover jumptable at 0x001f9af8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011c1c78)[*(long *)(param_1 + 0x10) == 0] +
            (int)-(uRam00000000011c1c88 ^ 0x4106f22)))();
  return;
}



// -[FFMpegHelper codeForCaps:], 0x1f9c44
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f9c44. codeForCaps: */

/* Function Stack Size: 0x18 bytes */

ID FFMpegHelper::codeForCaps_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  ID IVar4;
  long lVar5;
  undefined1 auVar6 [16];
  undefined **ppuStack_5a0;
  undefined **ppuStack_598;
  undefined **ppuStack_590;
  undefined **ppuStack_588;
  undefined **ppuStack_580;
  undefined **ppuStack_578;
  undefined **ppuStack_570;
  undefined **ppuStack_568;
  undefined **ppuStack_560;
  undefined **ppuStack_558;
  undefined **ppuStack_550;
  undefined **ppuStack_548;
  undefined **ppuStack_540;
  undefined **ppuStack_538;
  undefined **ppuStack_530;
  undefined **ppuStack_528;
  undefined **ppuStack_520;
  undefined **ppuStack_518;
  undefined **ppuStack_510;
  undefined **ppuStack_508;
  undefined **ppuStack_500;
  undefined **ppuStack_4f8;
  undefined **ppuStack_4f0;
  undefined **ppuStack_4e8;
  undefined **ppuStack_4e0;
  undefined **ppuStack_4d8;
  undefined **ppuStack_4d0;
  undefined **ppuStack_4c8;
  undefined **ppuStack_4c0;
  undefined **ppuStack_4b8;
  undefined **ppuStack_4b0;
  undefined **ppuStack_4a8;
  undefined **ppuStack_4a0;
  undefined **ppuStack_498;
  undefined **ppuStack_490;
  undefined **ppuStack_488;
  undefined **ppuStack_480;
  undefined **ppuStack_478;
  undefined **ppuStack_470;
  undefined **ppuStack_468;
  undefined **ppuStack_460;
  undefined **ppuStack_458;
  undefined **ppuStack_450;
  undefined **ppuStack_448;
  undefined **ppuStack_440;
  undefined **ppuStack_438;
  undefined **ppuStack_430;
  undefined **ppuStack_428;
  undefined **ppuStack_420;
  undefined **ppuStack_418;
  undefined **ppuStack_410;
  undefined **ppuStack_408;
  undefined **ppuStack_400;
  undefined **ppuStack_3f8;
  undefined **ppuStack_3f0;
  undefined **ppuStack_3e8;
  undefined **ppuStack_3e0;
  undefined **ppuStack_3d8;
  undefined **ppuStack_3d0;
  undefined **ppuStack_3c8;
  undefined **ppuStack_3c0;
  undefined **ppuStack_3b8;
  undefined **ppuStack_3b0;
  undefined **ppuStack_3a8;
  undefined **ppuStack_3a0;
  undefined **ppuStack_398;
  undefined **ppuStack_390;
  undefined **ppuStack_388;
  undefined **ppuStack_380;
  undefined **ppuStack_378;
  undefined **ppuStack_370;
  undefined **ppuStack_368;
  undefined **ppuStack_360;
  undefined **ppuStack_358;
  undefined **ppuStack_350;
  undefined **ppuStack_348;
  undefined **ppuStack_340;
  undefined **ppuStack_338;
  undefined **ppuStack_330;
  undefined **ppuStack_328;
  undefined **ppuStack_320;
  undefined **ppuStack_318;
  undefined **ppuStack_310;
  undefined **ppuStack_308;
  undefined **ppuStack_300;
  undefined **ppuStack_2f8;
  undefined **ppuStack_2f0;
  undefined **ppuStack_2e8;
  undefined **ppuStack_2e0;
  undefined **ppuStack_2d8;
  undefined **ppuStack_2d0;
  undefined **ppuStack_2c8;
  undefined **ppuStack_2c0;
  undefined **ppuStack_2b8;
  undefined **ppuStack_2b0;
  undefined **ppuStack_2a8;
  undefined **ppuStack_2a0;
  undefined **ppuStack_298;
  undefined **ppuStack_290;
  undefined **ppuStack_288;
  undefined **ppuStack_280;
  undefined **ppuStack_278;
  undefined **ppuStack_270;
  undefined **ppuStack_268;
  undefined **ppuStack_260;
  undefined **ppuStack_258;
  undefined **ppuStack_250;
  undefined **ppuStack_248;
  undefined **ppuStack_240;
  undefined **ppuStack_238;
  undefined **ppuStack_230;
  undefined **ppuStack_228;
  undefined **ppuStack_220;
  undefined **ppuStack_218;
  undefined **ppuStack_210;
  undefined **ppuStack_208;
  undefined **ppuStack_200;
  undefined **ppuStack_1f8;
  undefined **ppuStack_1f0;
  undefined **ppuStack_1e8;
  undefined **ppuStack_1e0;
  undefined **ppuStack_1d8;
  undefined **ppuStack_1d0;
  undefined **ppuStack_1c8;
  undefined **ppuStack_1c0;
  undefined **ppuStack_1b8;
  undefined **ppuStack_1b0;
  undefined **ppuStack_1a8;
  undefined **ppuStack_1a0;
  undefined **ppuStack_198;
  undefined **ppuStack_190;
  undefined **ppuStack_188;
  undefined **ppuStack_180;
  undefined **ppuStack_178;
  undefined **ppuStack_170;
  undefined **ppuStack_168;
  undefined **ppuStack_160;
  undefined **ppuStack_158;
  undefined **ppuStack_150;
  undefined **ppuStack_148;
  undefined **ppuStack_140;
  undefined **ppuStack_138;
  undefined **ppuStack_130;
  undefined **ppuStack_128;
  undefined **ppuStack_120;
  undefined **ppuStack_118;
  undefined **ppuStack_110;
  undefined **ppuStack_108;
  undefined **ppuStack_100;
  undefined **ppuStack_f8;
  undefined **ppuStack_f0;
  undefined **ppuStack_e8;
  undefined **ppuStack_e0;
  undefined **ppuStack_d8;
  undefined **ppuStack_d0;
  undefined **ppuStack_c8;
  undefined **ppuStack_c0;
  undefined **ppuStack_b8;
  undefined **ppuStack_b0;
  undefined **ppuStack_a8;
  undefined **local_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **ppuStack_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  auVar6._8_8_ = param_2;
  auVar6._0_8_ = param_1;
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011c1cb0;
  local_74 = (uint)(DAT_01228040 == 0);
  local_88 = &PTR_LAB_011c1cd0;
  ppuStack_80 = &PTR_LAB_011c1600;
  local_98 = &PTR_LAB_011c1600;
  DAT_01228040 = 1;
  uStack_8c = (uint)(param_3 == 0);
  if (param_3 == 0) {
    lVar5 = 0;
  }
  else {
    _objc_msgSend(param_3,@selector(lastPathComponent));
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,@selector(stringByDeletingPathExtension));
    lVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar1);
    ppuStack_5a0 = @"af";
    ppuStack_598 = @"am";
    ppuStack_320 = @"afr";
    ppuStack_318 = @"amh";
    ppuStack_590 = @"ar";
    ppuStack_588 = @"az";
    ppuStack_310 = @"ara";
    ppuStack_308 = @"aze";
    ppuStack_580 = @"be";
    ppuStack_578 = @"bg";
    ppuStack_300 = @"bel";
    ppuStack_2f8 = @"bul";
    ppuStack_570 = @"bn";
    ppuStack_568 = @"bs";
    ppuStack_2f0 = @"ben";
    ppuStack_2e8 = @"bos";
    ppuStack_560 = @"ca";
    ppuStack_558 = @"cs";
    ppuStack_2e0 = @"cat";
    ppuStack_2d8 = @"ces";
    ppuStack_550 = @"da";
    ppuStack_548 = @"de";
    ppuStack_2d0 = @"dan";
    ppuStack_2c8 = @"deu";
    ppuStack_540 = @"el";
    ppuStack_538 = @"en";
    ppuStack_2c0 = @"ell";
    ppuStack_2b8 = @"eng";
    ppuStack_530 = @"en-GB";
    ppuStack_528 = @"es";
    ppuStack_2b0 = @"eng";
    ppuStack_2a8 = @"spa";
    ppuStack_520 = @"es-419";
    ppuStack_518 = @"et";
    ppuStack_2a0 = @"spa";
    ppuStack_298 = @"est";
    ppuStack_510 = @"eu";
    ppuStack_508 = @"fa";
    ppuStack_290 = @"eus";
    ppuStack_288 = @"fas";
    ppuStack_500 = @"fi";
    ppuStack_4f8 = @"fil";
    ppuStack_280 = @"fin";
    ppuStack_278 = @"fil";
    ppuStack_4f0 = @"fr";
    ppuStack_4e8 = @"fr-CA";
    ppuStack_270 = @"fra";
    ppuStack_268 = @"fra";
    ppuStack_4e0 = @"gl";
    ppuStack_4d8 = @"gu";
    ppuStack_260 = @"glg";
    ppuStack_258 = @"guj";
    ppuStack_4d0 = @"he";
    ppuStack_4c8 = @"hi";
    ppuStack_250 = @"heb";
    ppuStack_248 = @"hin";
    ppuStack_4c0 = @"hr";
    ppuStack_4b8 = @"hu";
    ppuStack_240 = @"hrv";
    ppuStack_238 = @"hun";
    ppuStack_4b0 = @"hy";
    ppuStack_4a8 = @"id";
    ppuStack_230 = @"hye";
    ppuStack_228 = @"ind";
    ppuStack_4a0 = @"is";
    ppuStack_498 = @"it";
    ppuStack_220 = @"isl";
    ppuStack_218 = @"ita";
    ppuStack_490 = @"ja";
    ppuStack_488 = @"ka";
    ppuStack_210 = @"jpn";
    ppuStack_208 = @"kat";
    ppuStack_480 = @"kk";
    ppuStack_478 = @"km";
    ppuStack_200 = @"kaz";
    ppuStack_1f8 = @"khm";
    ppuStack_470 = @"kn";
    ppuStack_468 = @"ko";
    ppuStack_1f0 = @"kan";
    ppuStack_1e8 = @"kor";
    ppuStack_460 = @"ky";
    ppuStack_458 = @"lo";
    ppuStack_1e0 = @"kir";
    ppuStack_1d8 = @"lao";
    ppuStack_450 = @"lt";
    ppuStack_448 = @"lv";
    ppuStack_1d0 = @"lit";
    ppuStack_1c8 = @"lav";
    ppuStack_440 = @"mk";
    ppuStack_438 = @"ml";
    ppuStack_1c0 = @"mkd";
    ppuStack_1b8 = @"mal";
    ppuStack_430 = @"mn";
    ppuStack_428 = @"mr";
    ppuStack_1b0 = @"mon";
    ppuStack_1a8 = @"mar";
    ppuStack_420 = @"ms";
    ppuStack_418 = @"my";
    ppuStack_1a0 = @"msa";
    ppuStack_198 = @"mya";
    ppuStack_410 = @"ne";
    ppuStack_408 = @"nl";
    ppuStack_190 = @"nep";
    ppuStack_188 = @"nld";
    ppuStack_400 = @"no";
    ppuStack_3f8 = @"pa";
    ppuStack_180 = @"nor";
    ppuStack_178 = @"pan";
    ppuStack_3f0 = @"pl";
    ppuStack_3e8 = @"pt";
    ppuStack_170 = @"pol";
    ppuStack_168 = @"por";
    ppuStack_3e0 = @"ro";
    ppuStack_3d8 = @"ru";
    ppuStack_160 = @"ron";
    ppuStack_158 = @"rus";
    ppuStack_3d0 = @"si";
    ppuStack_3c8 = @"sk";
    ppuStack_150 = @"sin";
    ppuStack_148 = @"slk";
    ppuStack_3c0 = @"sl";
    ppuStack_3b8 = @"sq";
    ppuStack_140 = @"slv";
    ppuStack_138 = @"sqi";
    ppuStack_3b0 = @"sr";
    ppuStack_3a8 = @"sr-Latn";
    ppuStack_130 = @"srp";
    ppuStack_128 = @"srp";
    ppuStack_3a0 = @"sv";
    ppuStack_120 = @"swe";
    ppuStack_398 = @"sw";
    ppuStack_118 = @"swa";
    ppuStack_390 = @"ta";
    ppuStack_110 = @"tam";
    ppuStack_388 = @"te";
    ppuStack_108 = @"tel";
    ppuStack_380 = @"th";
    ppuStack_100 = @"tha";
    ppuStack_378 = @"tr";
    ppuStack_f8 = @"tur";
    ppuStack_370 = @"uk";
    ppuStack_f0 = @"ukr";
    ppuStack_368 = @"uz";
    ppuStack_e8 = @"uzb";
    ppuStack_360 = @"vi";
    ppuStack_e0 = @"vie";
    ppuStack_358 = @"xh";
    ppuStack_d8 = @"xho";
    ppuStack_350 = @"yi";
    ppuStack_d0 = @"yid";
    ppuStack_348 = @"zu";
    ppuStack_c8 = @"zul";
    ppuStack_340 = @"zh-Hans";
    ppuStack_c0 = @"zho";
    ppuStack_338 = @"zh-Hant";
    ppuStack_b8 = @"zho";
    ppuStack_330 = @"zh-Hant-HK";
    ppuStack_b0 = @"zho";
    ppuStack_328 = @"zh-Hant-TW";
    ppuStack_a8 = @"zho";
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                  @selector(dictionaryWithObjects:forKeys:count:),&ppuStack_320,&ppuStack_5a0,0x50);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,@selector(objectForKeyedSubscript:),lVar2);
    lVar3 = _objc_retainAutoreleasedReturnValue();
    lVar5 = lVar2;
    if (lVar3 != 0) {
      lVar5 = lVar3;
    }
    _objc_retain(lVar5);
    _objc_release(lVar3);
    _objc_release(uVar1);
    auVar6 = _objc_release(lVar2);
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    IVar4 = _objc_autoreleaseReturnValue(lVar5);
    return IVar4;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(auVar6._0_8_,auVar6._8_8_);
}



// -[FFMpegHelper .cxx_destruct], 0x1fcd44
/* Decompiled from supplied 5.2.2 arm package. VA 0x1fcd44. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void FFMpegHelper::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  _objc_storeStrong(param_1 + 8,0);
  CallSupervisor(0x5bc9);
  return;
}



// +[FFMpegHelper sharedInstance], 0x1f4150
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f4150. sharedInstance */

/* Function Stack Size: 0x10 bytes */

ID FFMpegHelper::sharedInstance(ID param_1,SEL param_2)

{
  ID IVar1;
  SEL extraout_x1;
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  ID local_28;
  uint local_1c;
  undefined **local_18;
  
  local_18 = &PTR_LAB_011c1850;
  local_48 = PTR___NSConcreteGlobalBlock_01060658;
  local_40 = DAT_00c4c2a8;
  local_38 = FUN_001f4204;
  puStack_30 = &DAT_01062880;
  local_1c = (uint)(DAT_01227fb0 == -1);
  local_28 = param_1;
  if (DAT_01227fb0 != -1) {
    _dispatch_once((&PTR_LAB_011c1850)[local_1c] + (int)-(DAT_011c1860 ^ 0x2fae34d8),&DAT_01227fb0,
                   &local_48);
    param_2 = extraout_x1;
  }
  IVar1 = (*(code *)PTR__objc_retainAutoreleaseReturnValue_01061040)(DAT_01227fa8,param_2);
  return IVar1;
}


