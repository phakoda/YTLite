// Decompiled implementation evidence for YTPSleepTimer. Not compilable source.

// -[YTPSleepTimer timerQueue], 0x2114fc
/* Decompiled from supplied 5.2.2 arm package. VA 0x2114fc. timerQueue */

/* Function Stack Size: 0x10 bytes */

ID YTPSleepTimer::timerQueue(ID param_1,SEL param_2)

{
  ID IVar1;
  
  if (DAT_01228108 != 0) {
    DAT_01228108 = 1;
                    /* WARNING: Could not recover jumptable at 0x002115b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar1 = (*(code *)((&PTR_LAB_011cc3c0)[*(long *)(param_1 + 0x10) == 0] +
                      (int)-(uRam00000000011cc3d0 ^ 0xe9d8cb86)))();
    return IVar1;
  }
  s_com_dvn_ytpsleeptimer_queue_011cb280[0] = bRam00000000011cb260 ^ 0xb8;
  s_com_dvn_ytpsleeptimer_queue_011cb280[1] = bRam00000000011cb261 ^ 0xc6;
  s_com_dvn_ytpsleeptimer_queue_011cb280[2] = bRam00000000011cb262 ^ 8;
  s_com_dvn_ytpsleeptimer_queue_011cb280[3] = bRam00000000011cb263 ^ 0xbd;
  s_com_dvn_ytpsleeptimer_queue_011cb280[4] = bRam00000000011cb264 ^ 0x7a;
  s_com_dvn_ytpsleeptimer_queue_011cb280[5] = bRam00000000011cb265 ^ 0x8f;
  s_com_dvn_ytpsleeptimer_queue_011cb280[6] = bRam00000000011cb266 ^ 0x36;
  s_com_dvn_ytpsleeptimer_queue_011cb280[7] = bRam00000000011cb267 ^ 0x60;
  s_com_dvn_ytpsleeptimer_queue_011cb280[8] = bRam00000000011cb268 ^ 0xf4;
  s_com_dvn_ytpsleeptimer_queue_011cb280[9] = bRam00000000011cb269 ^ 0x69;
  s_com_dvn_ytpsleeptimer_queue_011cb280[10] = bRam00000000011cb26a ^ 0xc1;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0xb] = bRam00000000011cb26b ^ 0x6c;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0xc] = bRam00000000011cb26c ^ 0xfe;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0xd] = bRam00000000011cb26d ^ 0xf6;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0xe] = bRam00000000011cb26e ^ 0xa1;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0xf] = bRam00000000011cb26f ^ 0x7d;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x10] = bRam00000000011cb270 ^ 0x58;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x11] = bRam00000000011cb271 ^ 0x7b;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x12] = bRam00000000011cb272 ^ 8;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x13] = bRam00000000011cb273 ^ 0x60;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x14] = bRam00000000011cb274 ^ 0x3c;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x15] = bRam00000000011cb275 ^ 0x30;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x16] = bRam00000000011cb276 ^ 0x25;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x17] = bRam00000000011cb277 ^ 0x6b;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x18] = bRam00000000011cb278 ^ 0xe1;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x19] = bRam00000000011cb279 ^ 0xba;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x1a] = bRam00000000011cb27a ^ 0xf7;
  s_com_dvn_ytpsleeptimer_queue_011cb280[0x1b] = bRam00000000011cb27b ^ 0x54;
  DAT_01228108 = 1;
                    /* WARNING: Could not recover jumptable at 0x00211794. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar1 = (*(code *)((&PTR_LAB_011cc3c0)[*(long *)(param_1 + 0x10) == 0] +
                    (int)-(uRam00000000011cc3d0 ^ 0xe9d8cb86)))();
  return IVar1;
}



// -[YTPSleepTimer isRunning], 0x2117cc
/* Decompiled from supplied 5.2.2 arm package. VA 0x2117cc. isRunning */

/* Function Stack Size: 0x10 bytes */

bool YTPSleepTimer::isRunning(ID param_1,SEL param_2)

{
  uint uVar1;
  long lVar2;
  
  if (*(dispatch_source_t *)(param_1 + 8) == (dispatch_source_t)0x0) {
    uVar1 = 0;
  }
  else {
    lVar2 = _dispatch_source_testcancel(*(dispatch_source_t *)(param_1 + 8));
    uVar1 = (uint)(lVar2 == 0);
  }
  return uVar1;
}



// -[YTPSleepTimer showOptions:], 0x211844
/* Decompiled from supplied 5.2.2 arm package. VA 0x211844. showOptions: */

/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::showOptions_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  ID IVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  long lVar15;
  long lVar16;
  undefined1 auStack_360 [48];
  undefined1 auStack_330 [48];
  undefined *puStack_300;
  undefined8 uStack_2f8;
  code *pcStack_2f0;
  undefined *puStack_2e8;
  ID IStack_2e0;
  double dStack_2d8;
  undefined1 auStack_2d0 [128];
  undefined8 auStack_250 [8];
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined *puStack_1e0;
  undefined8 uStack_1d8;
  code *pcStack_1d0;
  undefined *puStack_1c8;
  ID IStack_1c0;
  undefined1 *puStack_1b0;
  undefined8 uStack_1a8;
  undefined1 *puStack_1a0;
  ID IStack_198;
  undefined *puStack_190;
  undefined1 *puStack_188;
  undefined8 uStack_180;
  long lStack_178;
  ID IStack_170;
  undefined8 uStack_168;
  undefined8 *puStack_160;
  undefined **local_158;
  undefined **local_150;
  uint uStack_144;
  undefined **local_140;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  undefined **local_118;
  uint uStack_10c;
  undefined **local_108;
  undefined **local_100;
  undefined **ppuStack_f8;
  uint uStack_ec;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint local_8c;
  undefined **local_88;
  undefined8 local_80;
  
  local_80 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_011cc400;
  local_8c = (uint)(DAT_01228110 == 0);
  local_b0 = &PTR_LAB_011cc438;
  local_a0 = &PTR_LAB_011cc420;
  ppuStack_98 = &PTR_LAB_011cbe30;
  local_c8 = &PTR_LAB_011cbe30;
  ppuStack_c0 = &PTR_LAB_011cbe30;
  local_d0 = &PTR_LAB_011cc460;
  local_e8 = &PTR_LAB_011cc480;
  ppuStack_e0 = &PTR_LAB_011cbe30;
  local_100 = &PTR_LAB_011cbe30;
  ppuStack_f8 = &PTR_LAB_011cbe30;
  local_108 = &PTR_LAB_011cc4a8;
  local_118 = &PTR_LAB_011cbe30;
  local_120 = &PTR_LAB_011cc4c8;
  local_130 = &PTR_LAB_011cc4e0;
  local_140 = &PTR_LAB_011cc4f8;
  local_150 = &PTR_LAB_011cbe30;
  local_158 = &PTR_LAB_011cbe30;
  if (DAT_01228110 == 0) {
    s_YTActionSheetAction_011cb400[0] = bRam00000000011cb3e0 ^ 0x28;
    s_YTActionSheetAction_011cb400[1] = bRam00000000011cb3e1 ^ 0x5d;
    s_YTActionSheetAction_011cb400[2] = bRam00000000011cb3e2 ^ 0xbb;
    s_YTActionSheetAction_011cb400[3] = bRam00000000011cb3e3 ^ 0xd;
    s_YTActionSheetAction_011cb400[4] = bRam00000000011cb3e4 ^ 100;
    s_YTActionSheetAction_011cb400[5] = bRam00000000011cb3e5 ^ 0x58;
    s_YTActionSheetAction_011cb400[6] = bRam00000000011cb3e6 ^ 0xa1;
    s_YTActionSheetAction_011cb400[7] = bRam00000000011cb3e7 ^ 0x25;
    s_YTActionSheetAction_011cb400[8] = bRam00000000011cb3e8 ^ 0x49;
    s_YTActionSheetAction_011cb400[9] = bRam00000000011cb3e9 ^ 0xd4;
    s_YTActionSheetAction_011cb400[10] = bRam00000000011cb3ea ^ 0xb;
    s_YTActionSheetAction_011cb400[0xb] = bRam00000000011cb3eb ^ 0x28;
    s_YTActionSheetAction_011cb400[0xc] = bRam00000000011cb3ec ^ 0xa8;
    s_YTActionSheetAction_011cb400[0xd] = bRam00000000011cb3ed ^ 1;
    s_YTActionSheetAction_011cb400[0xe] = bRam00000000011cb3ee ^ 0x37;
    s_YTActionSheetAction_011cb400[0xf] = bRam00000000011cb3ef ^ 0x4a;
    s_YTActionSheetAction_011cb400[0x10] = bRam00000000011cb3f0 ^ 0xab;
    s_YTActionSheetAction_011cb400[0x11] = bRam00000000011cb3f1 ^ 0x86;
    s_YTActionSheetAction_011cb400[0x12] = bRam00000000011cb3f2 ^ 0x4d;
    s_YTActionSheetAction_011cb400[0x13] = bRam00000000011cb3f3 ^ 0x76;
    s_SleepTimer_EndAt_011cb340[0] = DAT_011cb320 ^ 0x67;
    s_SleepTimer_EndAt_011cb340[1] = bRam00000000011cb321 ^ 0x55;
    s_SleepTimer_EndAt_011cb340[2] = bRam00000000011cb322 ^ 0x4b;
    s_SleepTimer_EndAt_011cb340[3] = bRam00000000011cb323 ^ 0x8a;
    s_SleepTimer_EndAt_011cb340[4] = bRam00000000011cb324 ^ 0xdd;
    s_SleepTimer_EndAt_011cb340[5] = bRam00000000011cb325 ^ 0xf9;
    s_SleepTimer_EndAt_011cb340[6] = bRam00000000011cb326 ^ 0x58;
    s_SleepTimer_EndAt_011cb340[7] = cRam00000000011cb327;
    s_SleepTimer_EndAt_011cb340[8] = bRam00000000011cb328 ^ 0x5c;
    s_SleepTimer_EndAt_011cb340[9] = bRam00000000011cb329 ^ 0x24;
    s_SleepTimer_EndAt_011cb340[10] = bRam00000000011cb32a ^ 0xe3;
    s_SleepTimer_EndAt_011cb340[0xb] = bRam00000000011cb32b ^ 0x82;
    s_SleepTimer_EndAt_011cb340[0xc] = bRam00000000011cb32c ^ 0x45;
    s_SleepTimer_EndAt_011cb340[0xd] = bRam00000000011cb32d ^ 100;
    s_SleepTimer_EndAt_011cb340[0xe] = bRam00000000011cb32e ^ 0xec;
    s_SleepTimer_EndAt_011cb340[0xf] = bRam00000000011cb32f ^ 0xaf;
    s_SleepTimer_EndAt_011cb340[0x10] = bRam00000000011cb330 ^ 0x60;
    s_SleepTimer_TurnOff_011cb3c0[0] = DAT_011cb3a0 ^ 0x8d;
    s_SleepTimer_TurnOff_011cb3c0[1] = bRam00000000011cb3a1 ^ 0x5a;
    s_SleepTimer_TurnOff_011cb3c0[2] = bRam00000000011cb3a2 ^ 0x15;
    s_SleepTimer_TurnOff_011cb3c0[3] = bRam00000000011cb3a3 ^ 0xac;
    s_SleepTimer_TurnOff_011cb3c0[4] = bRam00000000011cb3a4 ^ 0x6f;
    s_SleepTimer_TurnOff_011cb3c0[5] = bRam00000000011cb3a5 ^ 0x2f;
    s_SleepTimer_TurnOff_011cb3c0[6] = bRam00000000011cb3a6 ^ 0x69;
    s_SleepTimer_TurnOff_011cb3c0[7] = bRam00000000011cb3a7 ^ 0x86;
    s_SleepTimer_TurnOff_011cb3c0[8] = bRam00000000011cb3a8 ^ 0x10;
    s_SleepTimer_TurnOff_011cb3c0[9] = bRam00000000011cb3a9 ^ 0xe3;
    s_SleepTimer_TurnOff_011cb3c0[10] = bRam00000000011cb3aa ^ 0xe8;
    s_SleepTimer_TurnOff_011cb3c0[0xb] = bRam00000000011cb3ab ^ 0x52;
    s_SleepTimer_TurnOff_011cb3c0[0xc] = bRam00000000011cb3ac ^ 0xf5;
    s_SleepTimer_TurnOff_011cb3c0[0xd] = bRam00000000011cb3ad ^ 0x51;
    s_SleepTimer_TurnOff_011cb3c0[0xe] = bRam00000000011cb3ae ^ 0xad;
    s_SleepTimer_TurnOff_011cb3c0[0xf] = bRam00000000011cb3af ^ 0xb;
    s_SleepTimer_TurnOff_011cb3c0[0x10] = bRam00000000011cb3b0 ^ 0x1f;
    s_SleepTimer_TurnOff_011cb3c0[0x11] = bRam00000000011cb3b1 ^ 0x97;
    s_SleepTimer_TurnOff_011cb3c0[0x12] = bRam00000000011cb3b2 ^ 0xc9;
    s_YTDefaultSheetController_011cb380[0] = bRam00000000011cb360 ^ 0x48;
    s_YTDefaultSheetController_011cb380[1] = bRam00000000011cb361 ^ 0x91;
    s_YTDefaultSheetController_011cb380[2] = bRam00000000011cb362 ^ 0xea;
    s_YTDefaultSheetController_011cb380[3] = cRam00000000011cb363;
    s_YTDefaultSheetController_011cb380[4] = bRam00000000011cb364 ^ 0xec;
    s_YTDefaultSheetController_011cb380[5] = bRam00000000011cb365 ^ 0x22;
    s_YTDefaultSheetController_011cb380[6] = bRam00000000011cb366 ^ 0xb3;
    s_YTDefaultSheetController_011cb380[7] = bRam00000000011cb367 ^ 0xe0;
    s_YTDefaultSheetController_011cb380[8] = bRam00000000011cb368 ^ 0xdd;
    s_YTDefaultSheetController_011cb380[9] = bRam00000000011cb369 ^ 0xed;
    s_YTDefaultSheetController_011cb380[10] = bRam00000000011cb36a ^ 0x4e;
    s_YTDefaultSheetController_011cb380[0xb] = bRam00000000011cb36b ^ 0xf8;
    s_YTDefaultSheetController_011cb380[0xc] = bRam00000000011cb36c ^ 0x95;
    s_YTDefaultSheetController_011cb380[0xd] = bRam00000000011cb36d ^ 0xcd;
    s_YTDefaultSheetController_011cb380[0xe] = bRam00000000011cb36e ^ 0xe2;
    s_YTDefaultSheetController_011cb380[0xf] = bRam00000000011cb36f ^ 0x2c;
    s_YTDefaultSheetController_011cb380[0x10] = bRam00000000011cb370 ^ 0x2c;
    s_YTDefaultSheetController_011cb380[0x11] = bRam00000000011cb371 ^ 0x7b;
    s_YTDefaultSheetController_011cb380[0x12] = bRam00000000011cb372 ^ 0x86;
    param_2 = (SEL)bRam00000000011cb373;
    s_YTDefaultSheetController_011cb380[0x13] = bRam00000000011cb373 ^ 0xa1;
    s_YTDefaultSheetController_011cb380[0x14] = bRam00000000011cb374 ^ 0x69;
    s_YTDefaultSheetController_011cb380[0x15] = bRam00000000011cb375 ^ 0x34;
    s_YTDefaultSheetController_011cb380[0x16] = bRam00000000011cb376 ^ 0xc0;
    s_YTDefaultSheetController_011cb380[0x17] = bRam00000000011cb377 ^ 0xad;
    s_YTDefaultSheetController_011cb380[0x18] = bRam00000000011cb378 ^ 0xf7;
    s_SleepTimer_EndOfVideo_011cb300[0] = DAT_011cb2e0 ^ 0x76;
    s_SleepTimer_EndOfVideo_011cb300[1] = bRam00000000011cb2e1 ^ 0xf5;
    s_SleepTimer_EndOfVideo_011cb300[2] = bRam00000000011cb2e2 ^ 0xb2;
    s_SleepTimer_EndOfVideo_011cb300[3] = bRam00000000011cb2e3 ^ 0xd;
    s_SleepTimer_EndOfVideo_011cb300[4] = bRam00000000011cb2e4 ^ 0x44;
    s_SleepTimer_EndOfVideo_011cb300[5] = bRam00000000011cb2e5 ^ 0x7d;
    s_SleepTimer_EndOfVideo_011cb300[6] = bRam00000000011cb2e6 ^ 0x13;
    s_SleepTimer_EndOfVideo_011cb300[7] = bRam00000000011cb2e7 ^ 0x12;
    s_SleepTimer_EndOfVideo_011cb300[8] = bRam00000000011cb2e8 ^ 0x10;
    s_SleepTimer_EndOfVideo_011cb300[9] = bRam00000000011cb2e9 ^ 0x6c;
    s_SleepTimer_EndOfVideo_011cb300[10] = bRam00000000011cb2ea ^ 0xd4;
    s_SleepTimer_EndOfVideo_011cb300[0xb] = bRam00000000011cb2eb ^ 0xfb;
    s_SleepTimer_EndOfVideo_011cb300[0xc] = bRam00000000011cb2ec ^ 0xd6;
    s_SleepTimer_EndOfVideo_011cb300[0xd] = bRam00000000011cb2ed ^ 1;
    s_SleepTimer_EndOfVideo_011cb300[0xe] = bRam00000000011cb2ee ^ 0xe5;
    s_SleepTimer_EndOfVideo_011cb300[0xf] = bRam00000000011cb2ef ^ 0xa6;
    s_SleepTimer_EndOfVideo_011cb300[0x10] = bRam00000000011cb2f0 ^ 0x94;
    s_SleepTimer_EndOfVideo_011cb300[0x11] = bRam00000000011cb2f1 ^ 0x62;
    s_SleepTimer_EndOfVideo_011cb300[0x12] = bRam00000000011cb2f2 ^ 0x74;
    s_SleepTimer_EndOfVideo_011cb300[0x13] = bRam00000000011cb2f3 ^ 0x2f;
    s_SleepTimer_EndOfVideo_011cb300[0x14] = bRam00000000011cb2f4 ^ 0xca;
    s_SleepTimer_EndOfVideo_011cb300[0x15] = bRam00000000011cb2f5 ^ 9;
    s_SleepTimer_SelectTime_011cb2c0[0] = DAT_011cb2a0 ^ 0x2e;
    s_SleepTimer_SelectTime_011cb2c0[1] = bRam00000000011cb2a1 ^ 0xae;
    s_SleepTimer_SelectTime_011cb2c0[2] = bRam00000000011cb2a2 ^ 0xb9;
    s_SleepTimer_SelectTime_011cb2c0[3] = bRam00000000011cb2a3 ^ 99;
    s_SleepTimer_SelectTime_011cb2c0[4] = bRam00000000011cb2a4 ^ 0x25;
    s_SleepTimer_SelectTime_011cb2c0[5] = bRam00000000011cb2a5 ^ 0xba;
    s_SleepTimer_SelectTime_011cb2c0[6] = bRam00000000011cb2a6 ^ 0xe1;
    s_SleepTimer_SelectTime_011cb2c0[7] = bRam00000000011cb2a7 ^ 0x68;
    s_SleepTimer_SelectTime_011cb2c0[8] = bRam00000000011cb2a8 ^ 0x80;
    s_SleepTimer_SelectTime_011cb2c0[9] = bRam00000000011cb2a9 ^ 0x86;
    s_SleepTimer_SelectTime_011cb2c0[10] = bRam00000000011cb2aa ^ 0x3b;
    s_SleepTimer_SelectTime_011cb2c0[0xb] = bRam00000000011cb2ab ^ 0x2d;
    s_SleepTimer_SelectTime_011cb2c0[0xc] = bRam00000000011cb2ac ^ 0x9a;
    s_SleepTimer_SelectTime_011cb2c0[0xd] = bRam00000000011cb2ad ^ 0xda;
    s_SleepTimer_SelectTime_011cb2c0[0xe] = bRam00000000011cb2ae ^ 0xa6;
    s_SleepTimer_SelectTime_011cb2c0[0xf] = bRam00000000011cb2af ^ 0xb3;
    s_SleepTimer_SelectTime_011cb2c0[0x10] = bRam00000000011cb2b0 ^ 0x20;
    s_SleepTimer_SelectTime_011cb2c0[0x11] = bRam00000000011cb2b1 ^ 0x30;
    s_SleepTimer_SelectTime_011cb2c0[0x12] = bRam00000000011cb2b2 ^ 0xcf;
    s_SleepTimer_SelectTime_011cb2c0[0x13] = bRam00000000011cb2b3 ^ 0x7f;
    s_SleepTimer_SelectTime_011cb2c0[0x14] = bRam00000000011cb2b4 ^ 0xa5;
    s_SleepTimer_SelectTime_011cb2c0[0x15] = bRam00000000011cb2b5 ^ 0x94;
  }
  DAT_01228110 = 1;
  puStack_160 = auStack_250;
  puStack_188 = auStack_2d0;
  puStack_1b0 = auStack_330;
  puStack_1a0 = auStack_360;
  _objc_retain(param_3,param_2);
  uStack_a4 = (uint)(param_3 == 0);
  IStack_198 = param_3;
  if (param_3 == 0) {
    _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(delegate));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    _objc_msgSend(uVar8,@selector(responderRoot));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar2 = @selector(pivotBarViewController);
    uStack_b4 = FUN_00218a54(uVar7,@selector(respondsToSelector:),
                             @selector(pivotBarViewController));
    if (uStack_b4 == 0) {
      IStack_198 = 0;
    }
    else {
      _objc_msgSend(local_b0[uStack_b4] + (int)-(uRam00000000011cc448 ^ 0x8c8538ea),uVar7,puVar2);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar9,@selector(view));
      IStack_198 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar9);
    }
    _objc_release(uVar7);
    _objc_release(uVar8);
  }
  uVar7 = _objc_getClass(s_YTDefaultSheetController_011cb380);
  _objc_msgSend(uVar7,@selector(sheetControllerWithMessage:subMessage:delegate:parentResponder:),0,0,0,0);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  uStack_d4 = FUN_0021884c(param_1,@selector(isRunning));
  puVar2 = PTR___NSConcreteStackBlock_01060660;
  if (uStack_d4 != 0) {
    uVar8 = _objc_getClass(local_d0[uStack_d4] + (int)-(uRam00000000011cc470 ^ 0x848af14a),
                           s_YTActionSheetAction_011cb400);
    _objc_msgSend(@"SleepTimer.TurnOff",@selector(ytl_localized));
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puStack_1e0 = puVar2;
    uStack_1d8 = DAT_00c4c228;
    pcStack_1d0 = FUN_00212b78;
    puStack_1c8 = &DAT_010618c0;
    IStack_1c0 = param_1;
    _objc_msgSend(uVar8,@selector(actionWithTitle:subtitle:iconImage:handler:),uVar9,0,0,&puStack_1e0);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(addAction:),uVar8);
    _objc_release(uVar8);
    _objc_release(uVar9);
  }
  IStack_170 = param_1;
  uStack_168 = uVar7;
  uVar8 = _objc_msgSend(PTR__OBJC_CLASS___NSDateComponentsFormatter_0114ee40,@selector(new));
  _objc_msgSend(uVar8,@selector(setUnitsStyle:),3);
  _objc_msgSend(uVar8,@selector(setAllowedUnits:),0xe0);
  _objc_msgSend(uVar8,@selector(setMaximumUnitCount:),2);
  _objc_msgSend(uVar8,@selector(setZeroFormattingBehavior:),0xe);
  puVar2 = @selector(numberWithInt:);
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithInt:),10);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  uStack_210 = uVar7;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar2,0xf);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  uStack_208 = uVar9;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar2,0x14);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  uStack_200 = uVar10;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar2,0x1e);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  uStack_1f8 = uVar11;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar2,0x2d);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  uStack_1f0 = uVar12;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar2,0x3c);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  uStack_1e8 = uVar13;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                &uStack_210,6);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar7);
  puVar6 = puStack_160;
  puVar1 = puStack_160 + 4;
  puStack_160[5] = 0;
  *puVar1 = 0;
  puVar6[7] = 0;
  puVar6[6] = 0;
  puVar6[1] = 0;
  *puVar6 = 0;
  puVar6[3] = 0;
  puVar6[2] = 0;
  uVar7 = _objc_retain(uVar14);
  puStack_190 = @selector(countByEnumeratingWithState:objects:count:);
  uStack_180 = uVar14;
  lVar15 = _objc_msgSend(uVar7,@selector(countByEnumeratingWithState:objects:count:),puVar6,puStack_188,
                         0x10);
  IVar5 = IStack_170;
  puVar4 = @selector(actionWithTitle:subtitle:iconImage:handler:);
  puVar3 = @selector(stringFromTimeInterval:);
  puVar2 = @selector(addAction:);
  uVar7 = DAT_00c4c228;
  uStack_ec = (uint)(lVar15 == 0);
  if (lVar15 == 0) {
    _objc_release(uStack_180);
    _objc_msgSend(IStack_170,@selector(getPlayerIfAvailable));
    puStack_160 = (undefined8 *)_objc_retainAutoreleasedReturnValue();
    uStack_144 = (uint)(puStack_160 == (undefined8 *)0x0);
    uStack_1a8 = uVar8;
                    /* WARNING: Could not recover jumptable at 0x00212870. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_140[uStack_144] + (int)-(uRam00000000011cc508 ^ 0xc451550d)))();
    return;
  }
  lStack_178 = *(long *)puVar6[2];
  puStack_160 = (undefined8 *)@selector(integerValue);
  uStack_10c = (uint)(*(long *)puVar6[2] == lStack_178);
  if (*(long *)puVar6[2] != lStack_178) {
    _objc_enumerationMutation(uStack_180);
  }
  lVar16 = _objc_msgSend(*(undefined8 *)puVar6[1],puStack_160);
  _objc_msgSend((double)(lVar16 * 0x3c),uVar8,puVar3);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  uVar9 = _objc_getClass(s_YTActionSheetAction_011cb400);
  puStack_300 = PTR___NSConcreteStackBlock_01060660;
  uStack_2f8 = uVar7;
  pcStack_2f0 = FUN_00212bb0;
  puStack_2e8 = &UNK_01063090;
  IStack_2e0 = IVar5;
  dStack_2d8 = (double)(lVar16 * 0x3c);
  _objc_msgSend(uVar9,puVar4,uVar8,0,0,&puStack_300);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uStack_168,puVar2,uVar7);
  _objc_release(uVar7);
  _objc_release(uVar8);
  uStack_124 = (uint)(lVar15 == 1);
                    /* WARNING: Could not recover jumptable at 0x00212790. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_120[uStack_124] + (int)-(uRam00000000011cc4d8 ^ 0x86f38692)))();
  return;
}



// -[YTPSleepTimer showTimeSelector], 0x212c38
/* Decompiled from supplied 5.2.2 arm package. VA 0x212c38. showTimeSelector */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::showTimeSelector(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *puStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined *puStack_78;
  ID IStack_70;
  undefined8 uStack_68;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011cc520;
  local_4c = (uint)(DAT_0122812c == 0);
  local_58 = &PTR_LAB_011cbe30;
  DAT_0122812c = 1;
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIDatePicker_0114f008);
  uVar2 = _objc_msgSend(0,0,DAT_00c4c4a8,0x4064000000000000,uVar2,@selector(initWithFrame:));
  _objc_msgSend(uVar2,@selector(setDatePickerMode:),0);
  _objc_msgSend(uVar2,@selector(setPreferredDatePickerStyle:),1);
  _objc_msgSend(PTR__OBJC_CLASS___NSLocale_0114ecb0,@selector(currentLocale));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setLocale:),uVar3);
  _objc_release(uVar3);
  uVar3 = _objc_getClass(s_YTAlertView_011cb59d);
  puVar1 = @selector(ytl_localized);
  puStack_90 = PTR___NSConcreteStackBlock_01060660;
  uStack_88 = DAT_00c4c228;
  pcStack_80 = FUN_00213194;
  puStack_78 = &DAT_01061f70;
  IStack_70 = param_1;
  uStack_68 = uVar2;
  _objc_retain(uVar2);
  _objc_msgSend(@"SleepTimer.Start",puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(confirmationDialogWithAction:actionTitle:),&puStack_90,uVar4);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_msgSend(@"SleepTimer.SelectTime",puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setTitle:),uVar4);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,@selector(setCustomContentView:),uVar2);
  _objc_msgSend(uVar3,@selector(show));
  _objc_release(uVar3);
  _objc_release(uStack_68);
  _objc_release(uVar2);
  return;
}



// -[YTPSleepTimer startForSeconds:], 0x21320c
/* Decompiled from supplied 5.2.2 arm package. VA 0x21320c. startForSeconds: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::startForSeconds_(ID param_1,SEL param_2,double param_3)

{
  undefined8 uVar1;
  double dVar2;
  
  if (0.0 < param_3) {
    _objc_msgSend(param_1,@selector(cancel));
    uVar1 = _DAT_00c4c4c0;
    *(undefined8 *)(param_1 + 0x28) = _UNK_00c4c4c8;
    *(undefined8 *)(param_1 + 0x20) = uVar1;
    _objc_msgSend(PTR__OBJC_CLASS___NSDate_0114ebb8,@selector(date));
    uVar1 = _objc_retainAutoreleasedReturnValue();
    dVar2 = (double)_objc_msgSend(uVar1,@selector(timeIntervalSince1970));
    *(double *)(param_1 + 0x38) = dVar2 + param_3;
    _objc_release(uVar1);
    _objc_msgSend(param_1,@selector(startTimer));
  }
  CallSupervisor(0x7171);
  return;
}



// -[YTPSleepTimer startForEndOfVideo], 0x213300
/* Decompiled from supplied 5.2.2 arm package. VA 0x213300. startForEndOfVideo */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::startForEndOfVideo(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  _objc_msgSend(param_1,@selector(getPlayerIfAvailable));
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 != 0) {
    _objc_msgSend(param_1,@selector(cancel));
    uVar1 = _DAT_00c4c4d0;
    *(undefined8 *)(param_1 + 0x28) = _UNK_00c4c4d8;
    *(undefined8 *)(param_1 + 0x20) = uVar1;
    _objc_msgSend(param_1,@selector(startTimer));
  }
  _objc_release(lVar2);
  CallSupervisor(0x5adb);
  return;
}



// -[YTPSleepTimer startTimer], 0x2133d4
/* Decompiled from supplied 5.2.2 arm package. VA 0x2133d4. startTimer */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::startTimer(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined *puVar2;
  dispatch_queue_t queue;
  dispatch_object_t object;
  dispatch_time_t start;
  undefined8 uVar3;
  undefined *local_a0;
  undefined8 local_98;
  code *local_90;
  undefined *puStack_88;
  undefined1 auStack_80 [8];
  undefined1 auStack_78 [8];
  undefined *local_70;
  undefined8 local_68;
  code *local_60;
  undefined *puStack_58;
  ID local_50;
  undefined8 local_48;
  
  local_48 = _objc_msgSend(param_1,@selector(remainingSeconds));
  puVar2 = PTR___NSConcreteStackBlock_01060660;
  uVar1 = DAT_00c4c228;
  local_70 = PTR___NSConcreteStackBlock_01060660;
  local_68 = DAT_00c4c228;
  local_60 = FUN_00213554;
  puStack_58 = &DAT_01061810;
  local_50 = param_1;
  _dispatch_async(PTR___dispatch_main_q_01060760,&local_70);
  _objc_msgSend(param_1,@selector(timerQueue));
  queue = (dispatch_queue_t)_objc_retainAutoreleasedReturnValue();
  object._os_obj =
       (_os_object_s *)
       _dispatch_source_create
                 ((dispatch_source_type_t)PTR___dispatch_source_type_timer_01060768,0,0,queue);
  _objc_release(queue);
  uVar3 = *(undefined8 *)(param_1 + 8);
  ((dispatch_object_t *)(param_1 + 8))->_os_obj = (_os_object_s *)object;
  _objc_retain(object._os_obj);
  _objc_release(uVar3);
  start = _dispatch_time(0,0);
  _dispatch_source_set_timer((dispatch_source_t)object._os_obj,start,1000000000,100000000);
  _objc_initWeak(auStack_78,param_1);
  local_a0 = puVar2;
  local_98 = uVar1;
  local_90 = FUN_0021373c;
  puStack_88 = &DAT_010627f0;
  _objc_copyWeak(auStack_80,auStack_78);
  _dispatch_source_set_event_handler(object._os_obj,&local_a0);
  _dispatch_resume(object);
  _objc_release(object._os_obj);
  _objc_destroyWeak(auStack_80);
  _objc_destroyWeak(auStack_78);
  CallSupervisor(0x4ed1);
  return;
}



// -[YTPSleepTimer stopWithFadeIfNeeded:], 0x213ac8
/* Decompiled from supplied 5.2.2 arm package. VA 0x213ac8. stopWithFadeIfNeeded: */

/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::stopWithFadeIfNeeded_(ID param_1,SEL param_2,double param_3)

{
  if (*(char *)(param_1 + 0x30) == '\0') {
    *(undefined1 *)(param_1 + 0x30) = 1;
    if (DAT_00c4c2a0 < param_3) {
      if (param_3 < 5.0) {
        _objc_msgSend(0x3ff0000000000000,0x3ff0000000000000,param_1,
                      @selector(stopWithFadeDuration:stopAfter:));
      }
      else {
        _objc_msgSend(0x4014000000000000,param_3 + -1.0,param_1,
                      @selector(stopWithFadeDuration:stopAfter:));
      }
    }
    else {
      _objc_msgSend(param_1,@selector(stop));
    }
  }
  CallSupervisor(0x5f01);
  return;
}



// -[YTPSleepTimer stopWithFadeDuration:stopAfter:], 0x213c18
/* Decompiled from supplied 5.2.2 arm package. VA 0x213c18. stopWithFadeDuration:stopAfter: */

/* Function Stack Size: 0x20 bytes */

void YTPSleepTimer::stopWithFadeDuration_stopAfter_
               (ID param_1,SEL param_2,double param_3,double param_4)

{
  long lVar1;
  
  _objc_msgSend(param_1,@selector(getPlayerIfAvailable));
  lVar1 = _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x00213cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011cc698)[lVar1 == 0] + (int)-(DAT_011cc6a8 ^ 0x1bae69cf)))();
  return;
}



// -[YTPSleepTimer stop], 0x213fd0
/* Decompiled from supplied 5.2.2 arm package. VA 0x213fd0. stop */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::stop(ID param_1,SEL param_2)

{
  _objc_msgSend(param_1,@selector(hideSlimBarWithStyle:),0);
  return;
}



// -[YTPSleepTimer cancel], 0x213fe0
/* Decompiled from supplied 5.2.2 arm package. VA 0x213fe0. cancel */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::cancel(ID param_1,SEL param_2)

{
  _objc_msgSend(param_1,@selector(finishTimerAndCleanup));
  CallSupervisor(0x4d02);
  return;
}



// -[YTPSleepTimer cancelIfPlayerClosed], 0x214014
/* Decompiled from supplied 5.2.2 arm package. VA 0x214014. cancelIfPlayerClosed */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::cancelIfPlayerClosed(ID param_1,SEL param_2)

{
  if (*(long *)(param_1 + 0x20) == 2) {
    _objc_msgSend(param_1,@selector(cancel));
  }
  CallSupervisor(0xbdf1);
  return;
}



// -[YTPSleepTimer remainingSeconds], 0x21409c
/* Decompiled from supplied 5.2.2 arm package. VA 0x21409c. remainingSeconds */

/* Function Stack Size: 0x10 bytes */

double YTPSleepTimer::remainingSeconds(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  long lVar2;
  double dVar3;
  
  lVar2 = *(long *)(param_1 + 0x20);
  if (lVar2 < 2) {
    dVar3 = 0.0;
    if (lVar2 == 1) {
      _objc_msgSend(PTR__OBJC_CLASS___NSDate_0114ebb8,@selector(date));
      uVar1 = _objc_retainAutoreleasedReturnValue();
      dVar3 = (double)_objc_msgSend(uVar1,@selector(timeIntervalSince1970));
      _objc_release(uVar1);
      dVar3 = *(double *)(param_1 + 0x38) - dVar3;
    }
  }
  else {
    dVar3 = 0.0;
    if (lVar2 == 2) {
      dVar3 = (double)_objc_msgSend(param_1,@selector(remainingSecondsForCurrentVideo));
      return dVar3;
    }
  }
  return dVar3;
}



// -[YTPSleepTimer remainingSecondsForCurrentVideo], 0x214200
/* Decompiled from supplied 5.2.2 arm package. VA 0x214200. remainingSecondsForCurrentVideo */

/* Function Stack Size: 0x10 bytes */

double YTPSleepTimer::remainingSecondsForCurrentVideo(ID param_1,SEL param_2)

{
  long lVar1;
  uint uVar2;
  double dVar3;
  
  _objc_msgSend(param_1,@selector(getPlayerIfAvailable));
  lVar1 = _objc_retainAutoreleasedReturnValue();
  if (lVar1 != 0) {
    dVar3 = (double)_objc_msgSend(lVar1,@selector(currentVideoTotalMediaTime));
    _objc_msgSend(lVar1,@selector(currentVideoMediaTime));
    uVar2 = (uint)(ABS(dVar3) == INFINITY);
    if (NAN(ABS(dVar3))) {
      uVar2 = 1;
    }
                    /* WARNING: Could not recover jumptable at 0x00214300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    dVar3 = (double)(*(code *)((&PTR_LAB_011cc7d8)[uVar2] +
                              (int)-(uRam00000000011cc7e8 ^ 0xe9953813)))();
    return dVar3;
  }
  _objc_release((&PTR_LAB_011cc7c0)[lVar1 == 0] + (int)-(DAT_011cc7d0 ^ 0x47ef989d),0);
  return 0.0;
}



// -[YTPSleepTimer secondsForDate:], 0x2143f8
/* Decompiled from supplied 5.2.2 arm package. VA 0x2143f8. secondsForDate: */

/* Function Stack Size: 0x18 bytes */

double YTPSleepTimer::secondsForDate_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  double dVar9;
  
  puVar2 = PTR__OBJC_CLASS___NSCalendar_0114f010;
  puVar1 = @selector(currentCalendar);
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSDate_0114ebb8,@selector(date));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(components:fromDate:);
  _objc_msgSend(uVar3,@selector(components:fromDate:),0x60,param_3);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(uVar3,puVar1,0x1c,uVar4);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uVar7 = _objc_msgSend(uVar5,@selector(hour));
  _objc_msgSend(uVar6,@selector(setHour:),uVar7);
  uVar7 = _objc_msgSend(uVar5,@selector(minute));
  _objc_msgSend(uVar6,@selector(setMinute:),uVar7);
  _objc_msgSend(uVar6,@selector(setSecond:),0);
  _objc_msgSend(uVar3,@selector(dateFromComponents:),uVar6);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(timeIntervalSinceDate:);
  dVar9 = (double)_objc_msgSend(uVar7,@selector(timeIntervalSinceDate:),uVar4);
  if (dVar9 <= 0.0) {
    _objc_msgSend(DAT_00c4c240,uVar7,@selector(dateByAddingTimeInterval:));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    uVar7 = uVar8;
  }
  dVar9 = (double)_objc_msgSend(uVar7,puVar1,uVar4);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  return dVar9;
}



// -[YTPSleepTimer formattedTime:], 0x21462c
/* Decompiled from supplied 5.2.2 arm package. VA 0x21462c. formattedTime: */

/* Function Stack Size: 0x18 bytes */

ID YTPSleepTimer::formattedTime_(ID param_1,SEL param_2,double param_3)

{
  ID IVar1;
  
  if (DAT_012280f8 != -1) {
    _dispatch_once((&PTR_LAB_011cc830)[DAT_012280f8 == -1] + (int)-(DAT_011cc840 ^ 0xc5c08a4f),
                   &DAT_012280f8,&PTR___NSConcreteGlobalBlock_010630c0);
  }
  IVar1 = _objc_msgSend(param_3,DAT_012280f0,@selector(stringFromTimeInterval:));
  return IVar1;
}



// -[YTPSleepTimer getPlayerIfAvailable], 0x214758
/* Decompiled from supplied 5.2.2 arm package. VA 0x214758. getPlayerIfAvailable */

/* Function Stack Size: 0x10 bytes */

ID YTPSleepTimer::getPlayerIfAvailable(ID param_1,SEL param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  
  DAT_01228194 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(delegate));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  _objc_msgSend(uVar3,@selector(responderRoot));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(class));
  _NSStringFromClass();
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar1 = FUN_002197bc(uVar4,@selector(hasPrefix:),
                       @"YTAppViewController");
  _objc_release(uVar4);
  if (iVar1 == 0) {
    uVar4 = 0;
  }
  else {
    _objc_msgSend(uVar2,@selector(appView));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(watchLayerView));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(_viewControllerForAncestor));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_msgSend(uVar6,@selector(playerViewController));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
  }
  _objc_release(uVar2);
  _objc_release(uVar3);
  IVar7 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar7;
}



// -[YTPSleepTimer globalSlimBar], 0x214a90
/* Decompiled from supplied 5.2.2 arm package. VA 0x214a90. globalSlimBar */

/* Function Stack Size: 0x10 bytes */

ID YTPSleepTimer::globalSlimBar(ID param_1,SEL param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  undefined8 uVar6;
  
  DAT_01228198 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(delegate));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  _objc_msgSend(uVar3,@selector(responderRoot));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(class));
  _NSStringFromClass();
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar1 = FUN_002198c4(uVar4,@selector(hasPrefix:),
                       @"YTAppViewController");
  _objc_release(uVar4);
  if (iVar1 == 0) {
    uVar6 = 0;
  }
  else {
    _objc_msgSend(uVar2,@selector(appView));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(slimStatusBarView));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
  }
  _objc_release(uVar2);
  _objc_release(uVar3);
  IVar5 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar6);
  return IVar5;
}



// -[YTPSleepTimer playerSlimBar], 0x214d78
/* Decompiled from supplied 5.2.2 arm package. VA 0x214d78. playerSlimBar */

/* Function Stack Size: 0x10 bytes */

ID YTPSleepTimer::playerSlimBar(ID param_1,SEL param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  undefined8 uVar8;
  
  DAT_0122819c = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(delegate));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  _objc_msgSend(uVar3,@selector(responderRoot));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(class));
  _NSStringFromClass();
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar1 = FUN_00219a0c(uVar4,@selector(hasPrefix:),
                       @"YTAppViewController");
  _objc_release(uVar4);
  if (iVar1 == 0) {
    uVar8 = 0;
  }
  else {
    _objc_msgSend(uVar2,@selector(appView));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(watchLayerView));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(watchCollectionView));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(slimStatusBarView));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar4);
  }
  _objc_release(uVar2);
  _objc_release(uVar3);
  IVar7 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar8);
  return IVar7;
}



// -[YTPSleepTimer globalSlimBarVisibilityChange], 0x2150ac
/* Decompiled from supplied 5.2.2 arm package. VA 0x2150ac. globalSlimBarVisibilityChange */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::globalSlimBarVisibilityChange(ID param_1,SEL param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(delegate));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_msgSend(uVar4,@selector(responderRoot));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(slimStatusBarDisplayStatusDidChange);
  iVar2 = FUN_00219a94(uVar3,@selector(respondsToSelector:),
                       @selector(slimStatusBarDisplayStatusDidChange));
  if (iVar2 != 0) {
    _objc_msgSend(uVar3,@selector(performSelector:),puVar1);
  }
  _objc_release(uVar3);
  _objc_release(uVar4);
  CallSupervisor(0x6055);
  return;
}



// -[YTPSleepTimer playerSlimBarVisibilityChange], 0x2151c8
/* Decompiled from supplied 5.2.2 arm package. VA 0x2151c8. playerSlimBarVisibilityChange */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::playerSlimBarVisibilityChange(ID param_1,SEL param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  DAT_012281a4 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(delegate));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_msgSend(uVar4,@selector(responderRoot));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(class));
  _NSStringFromClass();
  uVar5 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_00219b9c(uVar5,@selector(hasPrefix:),
                       @"YTAppViewController");
  _objc_release(uVar5);
  if (iVar2 != 0) {
    _objc_msgSend(uVar3,@selector(appView));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(watchLayerView));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(watchViewController));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    _objc_release(uVar5);
    puVar1 = @selector(slimStatusBarDisplayStatusDidChange);
    iVar2 = FUN_00219c24(uVar7,@selector(respondsToSelector:),
                         @selector(slimStatusBarDisplayStatusDidChange));
    if (iVar2 != 0) {
      _objc_msgSend(uVar7,@selector(performSelector:),puVar1);
    }
    _objc_release(uVar7);
  }
  _objc_release(uVar3);
  _objc_release(uVar4);
  CallSupervisor(0x93e7);
  return;
}



// -[YTPSleepTimer slimBarForStyle:], 0x215554
/* Decompiled from supplied 5.2.2 arm package. VA 0x215554. slimBarForStyle: */

/* Function Stack Size: 0x18 bytes */

ID YTPSleepTimer::slimBarForStyle_(ID param_1,SEL param_2,unsigned_long_long param_3)

{
  undefined **ppuVar1;
  ID IVar2;
  
  ppuVar1 = &@selector(playerSlimBar);
  if (param_3 != 1) {
    ppuVar1 = &@selector(globalSlimBar);
  }
  _objc_msgSend(param_1,*ppuVar1);
  _objc_retainAutoreleasedReturnValue();
  IVar2 = _objc_autoreleaseReturnValue();
  return IVar2;
}



// -[YTPSleepTimer barsForStyle:], 0x21558c
/* Decompiled from supplied 5.2.2 arm package. VA 0x21558c. barsForStyle: */

/* Function Stack Size: 0x18 bytes */

ID YTPSleepTimer::barsForStyle_(ID param_1,SEL param_2,unsigned_long_long param_3)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  ID IVar4;
  
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(playerSlimBar));
  lVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(globalSlimBar));
  lVar3 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 != 0) {
    _objc_msgSend((&PTR_LAB_011cc998)[lVar2 == 0] + (int)-(DAT_011cc9a8 ^ 0x7dd9959f),uVar1,
                  @selector(addObject:),lVar2);
                    /* WARNING: Could not recover jumptable at 0x002156a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar4 = (*(code *)((&PTR_LAB_011cc9b8)[param_3 == 1 || lVar3 == 0] +
                      (int)-(uRam00000000011cc9c8 ^ 0xc4a4f892)))();
    return IVar4;
  }
                    /* WARNING: Could not recover jumptable at 0x002156d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar4 = (*(code *)((&PTR_LAB_011cc9b8)[param_3 == 1 || lVar3 == 0] +
                    (int)-(uRam00000000011cc9c8 ^ 0xc4a4f892)))();
  return IVar4;
}



// -[YTPSleepTimer attributedTitle:image:], 0x215718
/* Decompiled from supplied 5.2.2 arm package. VA 0x215718. attributedTitle:image: */

/* Function Stack Size: 0x20 bytes */

ID YTPSleepTimer::attributedTitle_image_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  cfstringStruct *pcVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 uVar5;
  ID IVar6;
  undefined8 uVar7;
  
  DAT_012281b0 = 1;
  _objc_retain(param_4);
  puVar4 = PTR__OBJC_CLASS___NSAttributedString_0114ee30;
  puVar3 = PTR__OBJC_CLASS___NSMutableAttributedString_0114ec28;
  puVar2 = @selector(new);
  if (param_4 == 0) {
    _objc_retain(param_3);
    uVar5 = _objc_alloc(puVar4);
    pcVar1 = &cf___;
    if (param_3 != 0) {
      pcVar1 = (cfstringStruct *)param_3;
    }
    uVar5 = _objc_msgSend(uVar5,@selector(initWithString:),pcVar1);
  }
  else {
    _objc_retain(param_3);
    uVar5 = _objc_msgSend(puVar3,puVar2);
    IVar6 = _objc_msgSend(PTR__OBJC_CLASS___NSTextAttachment_0114ee28,puVar2);
    _objc_msgSend(IVar6,@selector(setImage:),param_4);
    _objc_msgSend(0,0xc000000000000000,0x402c000000000000,0x402c000000000000,IVar6,
                  @selector(setBounds:));
    _objc_msgSend(PTR__OBJC_CLASS___NSAttributedString_0114ee30,
                  @selector(attributedStringWithAttachment:),IVar6);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar3 = @selector(appendAttributedString:);
    _objc_msgSend(uVar5,@selector(appendAttributedString:),uVar7);
    _objc_release(uVar7);
    uVar7 = _objc_alloc(PTR__OBJC_CLASS___NSAttributedString_0114ee30);
    puVar2 = @selector(initWithString:);
    uVar7 = _objc_msgSend(uVar7,@selector(initWithString:),
                          @" ");
    _objc_msgSend(uVar5,puVar3,uVar7);
    _objc_release(uVar7);
    uVar7 = _objc_alloc(PTR__OBJC_CLASS___NSAttributedString_0114ee30);
    pcVar1 = &cf___;
    if (param_3 != 0) {
      pcVar1 = (cfstringStruct *)param_3;
    }
    uVar7 = _objc_msgSend(uVar7,puVar2,pcVar1);
    _objc_release(param_3);
    _objc_msgSend(uVar5,puVar3,uVar7);
    _objc_release(uVar7);
    param_3 = IVar6;
  }
  _objc_release(param_3);
  _objc_release(param_4);
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
  return IVar6;
}



// -[YTPSleepTimer applyTitle:image:color:toBar:], 0x2159b8
/* Decompiled from supplied 5.2.2 arm package. VA 0x2159b8. applyTitle:image:color:toBar: */

/* Function Stack Size: 0x30 bytes */

void YTPSleepTimer::applyTitle_image_color_toBar_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  _objc_retain(param_4);
  puVar1 = @selector(attributedTitle:image:);
  if (param_6 != 0) {
    _objc_retain(param_6);
    _objc_retain(param_5);
    _objc_msgSend(param_1,puVar1,param_3,param_4);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_6,@selector(statusLabel));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(setAttributedText:),uVar2);
    _objc_release(uVar3);
    _objc_release(uVar2);
    _objc_msgSend(param_6,@selector(setBackgroundColor:),param_5);
    _objc_release(param_5);
    _objc_msgSend(param_6,@selector(setDisplayed:),1);
    _objc_msgSend(param_6,@selector(setDismissing:),0);
    _objc_release(param_6);
    _objc_storeStrong(param_1 + 0x18,param_4);
  }
  (*(code *)PTR__objc_release_01061028)(param_4);
  return;
}



// -[YTPSleepTimer attachTapHandlerToBar:], 0x215b20
/* Decompiled from supplied 5.2.2 arm package. VA 0x215b20. attachTapHandlerToBar: */

/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::attachTapHandlerToBar_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  
  DAT_012281b8 = 1;
  _objc_retain(param_3);
  if (param_3 != 0) {
    uVar2 = _objc_msgSend(param_3,@selector(class));
    lVar3 = _class_getInstanceVariable(uVar2,s__tapGestureRecognizer_011cb930);
    if (lVar3 != 0) {
      _objc_msgSend(param_3,@selector(valueForKey:),
                    @"_tapGestureRecognizer");
      uVar2 = _objc_retainAutoreleasedReturnValue();
      uVar4 = _objc_alloc_init(PTR__OBJC_CLASS___UITapGestureRecognizer_0114ed98);
      _objc_release(uVar2);
      _objc_msgSend(uVar4,@selector(setNumberOfTapsRequired:),1);
      _objc_msgSend(param_3,@selector(setUserInteractionEnabled:),1);
      _objc_msgSend(param_3,@selector(addGestureRecognizer:),uVar4);
      _objc_msgSend(param_3,@selector(setValue:forKey:),uVar4,
                    @"_tapGestureRecognizer");
      puVar1 = @selector(onSlimBarTap:);
      _objc_msgSend(uVar4,@selector(removeTarget:action:),param_1,@selector(onSlimBarTap:));
      _objc_msgSend(uVar4,@selector(addTarget:action:),param_1,puVar1);
      _objc_release(uVar4);
    }
  }
  _objc_release(param_3);
  CallSupervisor(0x651a);
  return;
}



// -[YTPSleepTimer removeTapHandlerOnBar:], 0x215fe8
/* Decompiled from supplied 5.2.2 arm package. VA 0x215fe8. removeTapHandlerOnBar: */

/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::removeTapHandlerOnBar_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  long lVar2;
  
  DAT_012281bc = 1;
  _objc_retain(param_3);
  if (param_3 != 0) {
    uVar1 = _objc_msgSend(param_3,@selector(class));
    lVar2 = _class_getInstanceVariable(uVar1,s__tapGestureRecognizer_011cb9f0);
    if (lVar2 != 0) {
      _objc_msgSend(param_3,@selector(setValue:forKey:),0,
                    @"_tapGestureRecognizer");
    }
  }
  _objc_release(param_3);
  CallSupervisor(0xbac3);
  return;
}



// -[YTPSleepTimer onSlimBarTap:], 0x2163fc
/* Decompiled from supplied 5.2.2 arm package. VA 0x2163fc. onSlimBarTap: */

/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::onSlimBarTap_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puStack_100;
  undefined8 uStack_f8;
  code *pcStack_f0;
  undefined *puStack_e8;
  ID IStack_e0;
  undefined *puStack_d0;
  undefined8 uStack_c8;
  code *pcStack_c0;
  undefined *puStack_b8;
  ID IStack_b0;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  
  local_78 = &PTR_LAB_011ccaf0;
  local_7c = (uint)(DAT_012281c0 == 0);
  local_90 = &PTR_LAB_011ccb10;
  ppuStack_88 = &PTR_LAB_011cbe30;
  local_a0 = &PTR_LAB_011cbe30;
  DAT_012281c0 = 1;
  lVar4 = _objc_msgSend(param_3,@selector(state));
  uStack_94 = (uint)(lVar4 == 3);
  if (lVar4 == 3) {
    uVar5 = _objc_getClass(local_90[uStack_94] + (int)-(DAT_011ccb20 ^ 0xc82c0595),
                           s_YTAlertView_011cbb0f);
    _objc_msgSend(uVar5,@selector(dialog));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar3 = @selector(ytl_localized);
    _objc_msgSend(@"SleepTimer",@selector(ytl_localized));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(setTitle:),uVar5);
    _objc_release(uVar5);
    _objc_msgSend(@"SleepTimer.Message",puVar3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(setSubtitle:),uVar5);
    _objc_release(uVar5);
    _objc_msgSend(@"SleepTimer.TurnOff",puVar3);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar2 = @selector(addTitle:withAction:);
    puVar1 = PTR___NSConcreteStackBlock_01060660;
    uVar5 = DAT_00c4c228;
    puStack_d0 = PTR___NSConcreteStackBlock_01060660;
    uStack_c8 = DAT_00c4c228;
    pcStack_c0 = FUN_00216d18;
    puStack_b8 = &DAT_01061420;
    IStack_b0 = param_1;
    _objc_msgSend(uVar6,@selector(addTitle:withAction:),uVar7,&puStack_d0);
    _objc_release(uVar7);
    _objc_msgSend(@"SleepTimer.SelectNewTime",puVar3);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puStack_100 = puVar1;
    uStack_f8 = uVar5;
    pcStack_f0 = FUN_00216d50;
    puStack_e8 = &DAT_01061420;
    IStack_e0 = param_1;
    _objc_msgSend(uVar6,puVar2,uVar7,&puStack_100);
    _objc_release(uVar7);
    _objc_msgSend(@"SleepTimer.Dismiss",puVar3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar2,uVar5,0);
    _objc_release(uVar5);
    _objc_msgSend(uVar6,@selector(show));
    _objc_release(uVar6);
  }
  CallSupervisor(0x186);
  return;
}



// -[YTPSleepTimer slimBarVisibilityChange:], 0x216d8c
/* Decompiled from supplied 5.2.2 arm package. VA 0x216d8c. slimBarVisibilityChange: */

/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::slimBarVisibilityChange_(ID param_1,SEL param_2,unsigned_long_long param_3)

{
  if (param_3 != 1) {
    _objc_msgSend(param_1,@selector(globalSlimBarVisibilityChange));
  }
  _objc_msgSend(param_1,@selector(playerSlimBarVisibilityChange));
  return;
}



// -[YTPSleepTimer showSlimBarWithTitle:image:color:style:], 0x216e14
/* Decompiled from supplied 5.2.2 arm package. VA 0x216e14. showSlimBarWithTitle:image:color:style: */

/* Function Stack Size: 0x30 bytes */

void YTPSleepTimer::showSlimBarWithTitle_image_color_style_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,unsigned_long_long param_6)

{
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_msgSend(param_1,@selector(cleanup));
                    /* WARNING: Could not recover jumptable at 0x00216f00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011ccb50)[param_5 == 0] + (int)-(DAT_011ccb60 ^ 0xb853a10d)))();
  return;
}



// -[YTPSleepTimer updateSlimBarTitle:style:], 0x217198
/* Decompiled from supplied 5.2.2 arm package. VA 0x217198. updateSlimBarTitle:style: */

/* Function Stack Size: 0x20 bytes */

void YTPSleepTimer::updateSlimBarTitle_style_
               (ID param_1,SEL param_2,ID param_3,unsigned_long_long param_4)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  uint local_104;
  undefined **local_100;
  undefined1 auStack_f8 [128];
  undefined8 local_78;
  
  local_78 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_100 = &PTR_LAB_011ccbe8;
  _objc_retain(param_3);
  uStack_118 = 0;
  local_120 = 0;
  uStack_138 = 0;
  local_140 = 0;
  uStack_128 = 0;
  uStack_130 = 0;
  uStack_148 = 0;
  local_150 = 0;
  _objc_msgSend(param_1,@selector(barsForStyle:),param_4);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar2 = _objc_msgSend(uVar1,@selector(countByEnumeratingWithState:objects:count:),&local_150,auStack_f8,
                        0x10);
  local_104 = (uint)(lVar2 == 0);
                    /* WARNING: Could not recover jumptable at 0x002172a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_100[local_104] + (int)-(DAT_011ccbf8 ^ 0x3015ab43)))();
  return;
}



// -[YTPSleepTimer hideSlimBarWithStyle:], 0x217570
/* Decompiled from supplied 5.2.2 arm package. VA 0x217570. hideSlimBarWithStyle: */

/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::hideSlimBarWithStyle_(ID param_1,SEL param_2,unsigned_long_long param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  ID IVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 auStack_1f0 [128];
  undefined8 uStack_170;
  undefined8 *puStack_168;
  long *plStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  unsigned_long_long uStack_130;
  ID IStack_128;
  undefined1 *puStack_120;
  undefined *puStack_118;
  undefined8 uStack_110;
  undefined **local_108;
  uint uStack_fc;
  undefined **local_f8;
  undefined **local_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
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
  local_78 = &PTR__objc_msgSend_011ccc80;
  local_7c = (uint)(DAT_012281d8 == 0);
  local_90 = &PTR_LAB_011ccca0;
  local_a0 = &PTR_LAB_011cccb8;
  local_88 = &PTR_LAB_011cbe30;
  local_b8 = &PTR_LAB_011cbe30;
  ppuStack_b0 = &PTR_LAB_011cbe30;
  local_c0 = &PTR_LAB_011ccce0;
  local_d8 = &PTR_LAB_011ccd00;
  ppuStack_d0 = &PTR_LAB_011cbe30;
  local_e8 = &PTR_setVolumeLevel__011ccd18;
  local_f8 = &PTR_LAB_011ccd30;
  local_108 = &PTR_LAB_011cbe30;
  DAT_012281d8 = 1;
  _objc_msgSend(param_1,@selector(barsForStyle:),param_3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  lVar5 = _objc_msgSend(uVar4,@selector(count));
  uStack_94 = (uint)(lVar5 == 0);
  if (lVar5 != 0) {
    uStack_148 = 0;
    uStack_150 = 0;
    uStack_138 = 0;
    uStack_140 = 0;
    puStack_168 = (undefined8 *)0x0;
    uStack_170 = 0;
    uStack_158 = 0;
    plStack_160 = (long *)0x0;
    uStack_130 = param_3;
    IStack_128 = param_1;
    uVar6 = _objc_retain(uVar4);
    puStack_118 = @selector(countByEnumeratingWithState:objects:count:);
    lVar5 = _objc_msgSend(uVar6,@selector(countByEnumeratingWithState:objects:count:),&uStack_170,
                          auStack_1f0,0x10);
    puVar2 = @selector(setDismissing:);
    puVar1 = @selector(setDisplayed:);
    uStack_a4 = (uint)(lVar5 == 0);
    if (lVar5 != 0) {
      uStack_c4 = (uint)(*plStack_160 == *plStack_160);
      puStack_120 = auStack_1f0;
      uStack_110 = uVar4;
      if (*plStack_160 != *plStack_160) {
        _objc_enumerationMutation
                  (local_c0[uStack_c4] + (int)-(uRam00000000011cccf0 ^ 0x5af5c60f),uVar4);
      }
      uVar4 = *puStack_168;
      _objc_msgSend(uVar4,puVar1,0);
      _objc_msgSend(uVar4,puVar2,1);
      uStack_dc = (uint)(lVar5 == 1);
                    /* WARNING: Could not recover jumptable at 0x00217b3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_d8[uStack_dc] + (int)-(uRam00000000011ccd10 ^ 0xf8e2017c)))();
      return;
    }
    _objc_release(local_a0[uStack_a4] + (int)-(uRam00000000011cccc8 ^ 0xf5406681),uVar4);
    IVar3 = IStack_128;
    _objc_msgSend(IStack_128,@selector(slimBarVisibilityChange:),uStack_130);
    _objc_msgSend(IVar3,@selector(finishTimerAndCleanup));
    uStack_fc = FUN_0021a7ac(IVar3,@selector(pausePlayback));
    if (uStack_fc != 0) {
      uVar6 = _objc_getClass(local_f8[uStack_fc] + (int)-(uRam00000000011ccd40 ^ 0x53aef9c3),
                             s_YTAlertView_011cbd19);
      _objc_msgSend(uVar6,@selector(infoDialog));
      uVar6 = _objc_retainAutoreleasedReturnValue();
      puVar1 = @selector(ytl_localized);
      _objc_msgSend(@"SleepTimer",@selector(ytl_localized));
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(setTitle:),uVar7);
      _objc_release(uVar7);
      _objc_msgSend(@"SleepTimer.StopMessage",puVar1);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,@selector(setSubtitle:),uVar7);
      _objc_release(uVar7);
      _objc_msgSend(uVar6,@selector(show));
      _objc_release(uVar6);
    }
  }
  _objc_release(uVar4);
  CallSupervisor(0xaaeb);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}



// -[YTPSleepTimer pausePlayback], 0x217cfc
/* Decompiled from supplied 5.2.2 arm package. VA 0x217cfc. pausePlayback */

/* Function Stack Size: 0x10 bytes */

bool YTPSleepTimer::pausePlayback(ID param_1,SEL param_2)

{
  undefined *puVar1;
  int iVar2;
  bool bVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  DAT_012281dc = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(delegate);
  _objc_msgSend(uVar4,@selector(delegate));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_msgSend(uVar5,@selector(responderRoot));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(class));
  _NSStringFromClass();
  uVar6 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_0021a8fc(uVar6,@selector(hasPrefix:),
                       @"YTAppViewController");
  _objc_release(uVar6);
  if (iVar2 == 0) {
    bVar3 = 0;
  }
  else {
    _objc_msgSend(uVar4,@selector(appView));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    puVar1 = @selector(pausePlayback);
    bVar3 = FUN_0021a834(uVar7,@selector(respondsToSelector:),@selector(pausePlayback));
    if (bVar3 != 0) {
      _objc_msgSend(uVar7,@selector(performSelector:),puVar1);
    }
    _objc_release(uVar7);
  }
  _objc_release(uVar4);
  _objc_release(uVar5);
  return bVar3;
}



// -[YTPSleepTimer finishTimerAndCleanup], 0x218070
/* Decompiled from supplied 5.2.2 arm package. VA 0x218070. finishTimerAndCleanup */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::finishTimerAndCleanup(ID param_1,SEL param_2)

{
  uint uVar1;
  undefined *puVar2;
  dispatch_source_t source;
  undefined8 uVar3;
  undefined *puStack_68;
  undefined8 uStack_60;
  code *pcStack_58;
  undefined *puStack_50;
  ID IStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_011ccdb0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined1 *)(param_1 + 0x30) = 0;
  source = *(dispatch_source_t *)(param_1 + 8);
  local_3c = (uint)(source == (dispatch_source_t)0x0);
  puVar2 = (&PTR_LAB_011ccdb0)[local_3c];
  uVar1 = DAT_011ccdc0 ^ 0x35cfe4c9;
  if (source != (dispatch_source_t)0x0) {
    uVar3 = *(undefined8 *)(param_1 + 8);
    *(undefined8 *)(param_1 + 8) = 0;
    _objc_retain(puVar2 + (int)-uVar1,source);
    _objc_release(uVar3);
    _dispatch_source_cancel(source);
    _objc_release(source);
  }
  puStack_68 = PTR___NSConcreteStackBlock_01060660;
  uStack_60 = DAT_00c4c228;
  pcStack_58 = FUN_00218170;
  puStack_50 = &DAT_01061420;
  IStack_48 = param_1;
  _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_68);
  CallSupervisor(0x5e26);
  return;
}



// -[YTPSleepTimer cleanup], 0x2181a8
/* Decompiled from supplied 5.2.2 arm package. VA 0x2181a8. cleanup */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::cleanup(ID param_1,SEL param_2)

{
  long lVar1;
  long lVar2;
  
  _objc_msgSend(param_1,@selector(globalSlimBar));
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(playerSlimBar));
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar1 != 0) {
    _objc_msgSend((&PTR__objc_msgSend_011ccdd0)[lVar1 == 0] + (int)-(DAT_011ccde0 ^ 0x131129e6),
                  lVar1,@selector(setDisplayed:),0);
    _objc_msgSend(lVar1,@selector(setDismissing:),1);
    _objc_msgSend(param_1,@selector(globalSlimBarVisibilityChange));
    _objc_msgSend(param_1,@selector(removeTapHandlerOnBar:),lVar1);
                    /* WARNING: Could not recover jumptable at 0x002182dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011ccdf0)[lVar2 == 0] + (int)-(uRam00000000011cce00 ^ 0xc481dff0)))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0021830c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011ccdf0)[lVar2 == 0] + (int)-(uRam00000000011cce00 ^ 0xc481dff0)))();
  return;
}



// -[YTPSleepTimer .cxx_destruct], 0x218400
/* Decompiled from supplied 5.2.2 arm package. VA 0x218400. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  _objc_storeStrong(param_1 + 8,0);
  CallSupervisor(0xbeab);
  return;
}



// +[YTPSleepTimer sharedTimer], 0x211404
/* Decompiled from supplied 5.2.2 arm package. VA 0x211404. sharedTimer */

/* Function Stack Size: 0x10 bytes */

ID YTPSleepTimer::sharedTimer(ID param_1,SEL param_2)

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
  
  local_18 = &PTR_LAB_011cc378;
  local_48 = PTR___NSConcreteGlobalBlock_01060658;
  local_40 = DAT_00c4c2a8;
  local_38 = FUN_002114b8;
  puStack_30 = &DAT_01062880;
  local_1c = (uint)(DAT_012280e8 == -1);
  local_28 = param_1;
  if (DAT_012280e8 != -1) {
    _dispatch_once((&PTR_LAB_011cc378)[local_1c] + (int)-(DAT_011cc388 ^ 0x135a59a2),&DAT_012280e8,
                   &local_48);
    param_2 = extraout_x1;
  }
  IVar1 = (*(code *)PTR__objc_retainAutoreleaseReturnValue_01061040)(DAT_012280e0,param_2);
  return IVar1;
}


