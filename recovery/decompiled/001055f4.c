/* Decompiled from supplied 5.2.2 arm package. VA 0x1055f4. downloadVideoWithFormat:withAudioFormats:fileName:extension:videoID:playerVC:sender: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x48 bytes */

void DownloadMenuHelper::
     downloadVideoWithFormat_withAudioFormats_fileName_extension_videoID_playerVC_sender_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,ID param_7,
               ID param_8,ID param_9)

{
  undefined *puVar1;
  undefined *puVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined *puVar8;
  undefined *puStack_2a0;
  undefined8 uStack_298;
  code *pcStack_290;
  undefined *puStack_288;
  undefined8 uStack_280;
  undefined8 *puStack_278;
  undefined *puStack_270;
  undefined8 uStack_268;
  code *pcStack_260;
  undefined *puStack_258;
  ID IStack_250;
  ID IStack_248;
  long lStack_240;
  undefined8 uStack_238;
  ID IStack_230;
  ID IStack_228;
  ID IStack_220;
  undefined8 uStack_218;
  undefined8 *puStack_210;
  undefined8 *puStack_208;
  undefined8 uStack_200;
  undefined8 *puStack_1f8;
  undefined8 uStack_1f0;
  code *pcStack_1e8;
  code *pcStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 *puStack_1c8;
  undefined8 uStack_1c0;
  code *pcStack_1b8;
  code *pcStack_1b0;
  undefined8 uStack_1a8;
  long lStack_198;
  ID local_190;
  ID IStack_188;
  ID IStack_180;
  ID IStack_178;
  undefined **local_170;
  undefined **local_168;
  undefined **local_160;
  undefined **local_158;
  undefined **local_150;
  undefined **local_148;
  uint uStack_13c;
  undefined **local_138;
  undefined **local_130;
  undefined **local_128;
  undefined **local_120;
  uint uStack_114;
  undefined **local_110;
  uint uStack_104;
  undefined **local_100;
  uint uStack_f4;
  undefined **local_f0;
  uint uStack_e4;
  undefined **local_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **local_c8;
  uint uStack_bc;
  undefined **local_b8;
  uint uStack_ac;
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **local_90;
  uint local_84;
  undefined **local_80;
  
  local_80 = &PTR_LAB_0118a770;
  local_84 = (uint)(DAT_012271a4 == 0);
  local_98 = &PTR_LAB_0118a790;
  local_a8 = &PTR_LAB_0118a7a8;
  local_b8 = &PTR_LAB_0118a7c0;
  local_d0 = &PTR_LAB_0118a7e0;
  local_e0 = &PTR_LAB_0118a7f8;
  local_f0 = &PTR_LAB_0118a810;
  local_100 = &PTR_LAB_0118a828;
  local_110 = &PTR_LAB_0118a840;
  local_90 = &PTR_LAB_011882f0;
  local_c8 = &PTR_LAB_011882f0;
  local_120 = &PTR_LAB_011882f0;
  local_128 = &PTR_LAB_011882f0;
  local_130 = &PTR_LAB_011882f0;
  local_138 = &PTR_LAB_0118a870;
  local_148 = &PTR_LAB_011882f0;
  local_150 = &PTR_LAB_011882f0;
  local_158 = &PTR_LAB_011882f0;
  local_160 = &PTR_LAB_011882f0;
  local_168 = &PTR_LAB_011882f0;
  local_170 = &PTR_LAB_011882f0;
  DAT_012271a4 = 1;
  local_190 = param_1;
  IStack_178 = param_3;
  _objc_retain(param_3);
  IStack_188 = param_4;
  _objc_retain(param_4);
  IStack_180 = param_5;
  _objc_retain(param_5);
  _objc_retain(param_6);
  _objc_retain(param_7);
  _objc_retain(param_8);
  _objc_retain(param_9);
  puVar8 = PTR_s_playerResponse_0114c7c0;
  puVar1 = PTR_s_respondsToSelector__0114af58;
  uStack_9c = FUN_00112ed8(param_8,PTR_s_respondsToSelector__0114af58,PTR_s_playerResponse_0114c7c0)
  ;
  puVar2 = PTR_s_contentPlayerResponse_0114c7c8;
  puVar6 = local_98[uStack_9c] + (int)-(uRam000000000118a7a0 ^ 0x39ae2cc7);
  if (uStack_9c == 0) {
    uStack_ac = FUN_00112e70(param_8,puVar1,PTR_s_contentPlayerResponse_0114c7c8);
    puVar6 = local_a8[uStack_ac] + (int)-(uRam000000000118a7b8 ^ 0x5c21ff8a);
    puVar8 = puVar2;
    if (uStack_ac == 0) goto LAB_00105ea8;
  }
  _objc_msgSend(puVar6,param_8,puVar8);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  puVar6 = PTR___NSConcreteStackBlock_01060660;
  uVar5 = DAT_00c4c228;
  uStack_bc = (uint)(lVar3 == 0);
  if (lVar3 == 0) goto LAB_00105ea8;
  uStack_1d0 = 0;
  uStack_1c0 = _UNK_00c4c350;
  pcStack_1b8 = FUN_00105f50;
  pcStack_1b0 = FUN_00105f60;
  uStack_1a8 = 0;
  uStack_200 = 0;
  uStack_1f0 = _UNK_00c4c350;
  pcStack_1e8 = FUN_00105f50;
  pcStack_1e0 = FUN_00105f60;
  uStack_1d8 = 0;
  puStack_270 = PTR___NSConcreteStackBlock_01060660;
  uStack_268 = DAT_00c4c228;
  pcStack_260 = FUN_00105f90;
  puStack_258 = &UNK_010622f0;
  IStack_250 = local_190;
  puStack_210 = &uStack_200;
  puStack_1f8 = &uStack_200;
  puStack_1c8 = &uStack_1d0;
  _objc_retain(param_8);
  IStack_248 = param_8;
  _objc_retain(lVar3);
  lStack_240 = lVar3;
  uStack_238 = _objc_retain(IStack_178);
  puStack_208 = &uStack_1d0;
  _objc_retain(param_6);
  IStack_230 = param_6;
  _objc_retain(param_7);
  IStack_228 = param_7;
  _objc_retain(param_9);
  IStack_220 = param_9;
  uStack_218 = _objc_retain(IStack_180);
  lStack_198 = _objc_retainBlock(&puStack_270);
  lVar4 = _ytpInt(&PTR____CFConstantStringClassReference_011872a0);
  uStack_d4 = (uint)(lVar4 < 2);
  if (lVar4 < 2) {
    uStack_104 = (uint)(lVar4 < 1);
    if (lVar4 < 1) {
      uStack_114 = (uint)(lVar4 == 0);
      if (lVar4 != 0) goto LAB_00105e34;
      _objc_msgSend(local_190,PTR_s_getDefaultAudioTrack__0114cf30,IStack_188);
      uVar5 = _objc_retainAutoreleasedReturnValue();
    }
    else {
      _objc_msgSend(local_190,PTR_s_getBestAudioFormat_playerVC__0114ce98,IStack_188,param_8);
      uVar5 = _objc_retainAutoreleasedReturnValue();
    }
    uVar7 = puStack_1c8[5];
    puStack_1c8[5] = uVar5;
    _objc_release(uVar7);
    (**(code **)(lStack_198 + 0x10))();
  }
  else {
    uStack_e4 = (uint)(lVar4 < 3);
    if (lVar4 < 3) {
      _objc_msgSend(local_190,PTR_s_getEnglishAudioTrack__0114cf38,IStack_188);
      lVar3 = _objc_retainAutoreleasedReturnValue();
      uStack_13c = (uint)(lVar3 == 0);
                    /* WARNING: Could not recover jumptable at 0x00105d30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_138[uStack_13c] + (int)-(uRam000000000118a880 ^ 0xee7e8dd2)))();
      return;
    }
    uStack_f4 = (uint)(lVar4 == 3);
    if (lVar4 == 3) {
      puStack_2a0 = puVar6;
      uStack_298 = uVar5;
      pcStack_290 = FUN_001066e4;
      puStack_288 = &UNK_01062320;
      puStack_278 = &uStack_1d0;
      uStack_280 = _objc_retain(lStack_198);
      _objc_msgSend(local_190,PTR_s_showAudioTrackSelector_sender_pl_0114cf40,IStack_188,param_9,
                    param_8,&puStack_2a0);
      _objc_release(uStack_280);
    }
  }
LAB_00105e34:
  _objc_release(lStack_198);
  _objc_release(uStack_218);
  _objc_release(IStack_220);
  _objc_release(IStack_228);
  _objc_release(IStack_230);
  _objc_release(uStack_238);
  _objc_release(lStack_240);
  _objc_release(IStack_248);
  __Block_object_dispose(&uStack_200,8);
  _objc_release(uStack_1d8);
  __Block_object_dispose(&uStack_1d0,8);
  _objc_release(uStack_1a8);
  _objc_release(lVar3);
LAB_00105ea8:
  _objc_release(param_9);
  _objc_release(param_8);
  _objc_release(param_7);
  _objc_release(param_6);
  _objc_release(IStack_180);
  _objc_release(IStack_188);
  _objc_release(IStack_178);
  return;
}


