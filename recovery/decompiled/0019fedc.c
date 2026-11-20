/* Decompiled from supplied 5.2.2 arm package. VA 0x19fedc. drawSegmentableSegments:playerBar:playerVC: */

/* Function Stack Size: 0x28 bytes */

void SBPlayerDecorator::drawSegmentableSegments_playerBar_playerVC_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  double dVar5;
  undefined8 in_d2;
  undefined1 auStack_530 [192];
  undefined1 auStack_470 [128];
  undefined8 uStack_3f0;
  undefined8 uStack_3e8;
  long *plStack_3e0;
  undefined8 uStack_3d8;
  undefined8 uStack_3d0;
  undefined8 uStack_3c8;
  undefined8 uStack_3c0;
  undefined8 uStack_3b8;
  ID IStack_3b0;
  ID IStack_3a8;
  ID IStack_3a0;
  undefined1 *puStack_398;
  undefined *puStack_390;
  undefined *puStack_388;
  undefined *puStack_380;
  undefined *puStack_378;
  undefined *puStack_370;
  undefined *puStack_368;
  long lStack_360;
  long lStack_348;
  undefined *puStack_340;
  undefined *puStack_338;
  undefined8 *puStack_330;
  undefined *puStack_320;
  undefined *puStack_318;
  undefined8 uStack_300;
  long lStack_2e8;
  undefined1 *puStack_2e0;
  undefined *puStack_2b0;
  undefined8 uStack_288;
  undefined *puStack_280;
  undefined **local_278;
  undefined **local_270;
  undefined **ppuStack_268;
  undefined **local_258;
  undefined **local_248;
  undefined **ppuStack_240;
  undefined **local_230;
  undefined **local_220;
  undefined **local_218;
  undefined **ppuStack_210;
  undefined **local_200;
  undefined **local_1f0;
  undefined **local_1e0;
  undefined **local_1d0;
  undefined **local_1c0;
  undefined **local_1b0;
  undefined **local_1a0;
  undefined **local_190;
  undefined **local_180;
  undefined **local_178;
  undefined **local_168;
  undefined **local_160;
  undefined **local_158;
  undefined **local_148;
  undefined **local_138;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  undefined **local_118;
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
  uint local_bc;
  undefined **local_b8;
  long local_b0;
  
  local_b0 = *(long *)PTR____stack_chk_guard_01060708;
  local_b8 = &PTR_LAB_011accf8;
  local_bc = (uint)(DAT_012278f0 == 0);
  local_d0 = &PTR_LAB_011acd18;
  local_e0 = &PTR_LAB_011acd30;
  local_f0 = &PTR_LAB_011acd48;
  local_100 = &PTR_LAB_011acd60;
  local_c8 = &PTR_LAB_011ac130;
  local_110 = &PTR_LAB_011ac130;
  local_118 = &PTR_LAB_011ac130;
  local_120 = &PTR__objc_msgSend_011acd88;
  local_130 = &PTR_LAB_011ac130;
  local_138 = &PTR_LAB_011acda8;
  local_148 = &PTR_LAB_011acdc0;
  local_158 = &PTR_LAB_011ac130;
  local_160 = &PTR_LAB_011ac130;
  local_168 = &PTR_LAB_011acde8;
  local_178 = &PTR_LAB_011ac130;
  local_180 = &PTR_LAB_011ace08;
  local_190 = &PTR__objc_msgSend_011ace20;
  local_1a0 = &PTR__objc_msgSend_011ace38;
  local_1b0 = &PTR___Block_object_assign_011ace50;
  local_1c0 = &PTR___Block_object_assign_011ace68;
  local_1d0 = &PTR___Block_object_assign_011ace80;
  local_1e0 = &PTR___Block_object_assign_011ace98;
  local_1f0 = &PTR_LAB_011aceb0;
  local_200 = &PTR__objc_msgSend_011acec8;
  local_218 = &PTR_LAB_011ac130;
  ppuStack_210 = &PTR_LAB_011ac130;
  local_220 = &PTR__objc_msgSend_011acef0;
  local_230 = &PTR_LAB_011acf08;
  local_248 = &PTR_LAB_011acf28;
  ppuStack_240 = &PTR_LAB_011ac130;
  local_258 = &PTR_LAB_011acf40;
  local_270 = &PTR_LAB_011ac130;
  ppuStack_268 = &PTR_LAB_011ac130;
  local_278 = &PTR_LAB_011ac130;
  DAT_012278f0 = 1;
  puStack_398 = auStack_470;
  puStack_2e0 = auStack_530;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  puStack_388 = PTR_s_class_0114ae88;
  uVar1 = _objc_msgSend(param_4);
  lVar2 = _class_getInstanceVariable(uVar1,s__segmentViews_011ac01a);
  uStack_d4 = (uint)(lVar2 == 0);
  if (lVar2 != 0) {
    _objc_msgSend(PTR_SBManager_0114eee8,PTR_s_sharedManager_0114c320);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,PTR_s_segments_0114dac0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_5,PTR_s_contentVideoID_0114cef0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puStack_390 = PTR_s_objectForKey__0114b238;
    _objc_msgSend(uVar3,PTR_s_objectForKey__0114b238,uVar4);
    lVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_release(uVar3);
    _objc_release(uVar1);
    uStack_e4 = (uint)(lVar2 == 0);
    lStack_360 = lVar2;
    if (lVar2 != 0) {
      _objc_msgSend(PTR__OBJC_CLASS___NSMutableSet_0114eee0,PTR_s_set_0114da98);
      uStack_300 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_4,PTR_s_valueForKey__0114ae90,
                    &PTR____CFConstantStringClassReference_011ac110);
      uStack_288 = _objc_retainAutoreleasedReturnValue();
      uVar1 = _objc_msgSend(param_5,PTR_s_currentVideoTotalMediaTime_0114c9f8);
      puStack_280 = PTR_s_bounds_0114b568;
      _objc_msgSend(param_3);
      dVar5 = (double)NEON_fminnm(uVar1,in_d2);
      uStack_f4 = (uint)(dVar5 <= 0.0);
      if (0.0 < dVar5) {
        uStack_3c8 = 0;
        uStack_3d0 = 0;
        uStack_3b8 = 0;
        uStack_3c0 = 0;
        uStack_3e8 = 0;
        uStack_3f0 = 0;
        uStack_3d8 = 0;
        plStack_3e0 = (long *)0x0;
        IStack_3b0 = param_5;
        IStack_3a8 = param_4;
        IStack_3a0 = param_3;
        uVar1 = _objc_retain(local_f0[uStack_f4] + (int)-(DAT_011acd58 ^ 0xc7a1112b),lStack_360);
        puStack_2b0 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
        lStack_2e8 = _objc_msgSend(uVar1,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_3f0
                                   ,puStack_398,0x10);
        uStack_104 = (uint)(lStack_2e8 == 0);
        if (lStack_2e8 != 0) {
          lStack_348 = *plStack_3e0;
          puStack_320 = PTR_s_standardUserDefaults_0114afa0;
          puStack_318 = PTR_s_category_0114dad0;
          puStack_340 = PTR_s_integerForKey__0114b3a8;
          puStack_338 = PTR_s_stringWithFormat__0114b378;
          puStack_370 = PTR_s_start_0114b410;
          puStack_368 = PTR_s_unarchivedObjectOfClass_fromData_0114b758;
          puStack_380 = PTR_s_isEqualToString__0114ae48;
          puStack_378 = PTR_s_end_0114dae0;
          uStack_124 = (uint)(*plStack_3e0 == lStack_348);
          puStack_330 = &uStack_3f0;
                    /* WARNING: Could not recover jumptable at 0x001a0778. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)(local_120[uStack_124] + (int)-(uRam00000000011acd98 ^ 0xf57be3d2)))();
          return;
        }
        _objc_release(local_100[uStack_104] + (int)-(uRam00000000011acd70 ^ 0xd4e7b3d3),lStack_360);
        param_3 = IStack_3a0;
        param_4 = IStack_3a8;
        param_5 = IStack_3b0;
      }
      _objc_release(uStack_288);
      _objc_release(uStack_300);
    }
    _objc_release(lStack_360);
  }
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x1894);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_b0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


