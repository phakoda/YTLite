/* Decompiled from supplied 5.2.2 arm package. VA 0x6b2d0. FUN_0006b2d0 */

undefined1  [16] FUN_0006b2d0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  long lVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined1 auVar11 [16];
  undefined1 auStack_360 [48];
  undefined1 auStack_330 [96];
  undefined1 auStack_2d0 [48];
  undefined8 auStack_2a0 [6];
  undefined8 auStack_270 [6];
  undefined8 auStack_240 [6];
  undefined1 *puStack_210;
  undefined8 *puStack_208;
  undefined1 *puStack_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  long lStack_1e0;
  undefined8 uStack_1d8;
  undefined *puStack_1d0;
  undefined *puStack_1c8;
  undefined8 uStack_1c0;
  undefined1 *puStack_1b8;
  undefined8 *puStack_1b0;
  undefined8 *puStack_1a8;
  undefined *puStack_1a0;
  undefined *puStack_198;
  undefined *puStack_190;
  undefined8 uStack_188;
  undefined **local_180;
  undefined **ppuStack_178;
  undefined **local_168;
  undefined **ppuStack_160;
  uint uStack_154;
  undefined **local_150;
  undefined **local_148;
  undefined **ppuStack_140;
  undefined **local_130;
  undefined **ppuStack_128;
  uint uStack_11c;
  undefined **local_118;
  undefined **ppuStack_110;
  uint uStack_104;
  undefined **local_100;
  uint uStack_f4;
  undefined **local_f0;
  undefined **ppuStack_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **local_b8;
  uint uStack_ac;
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **local_90;
  uint local_84;
  undefined **local_80;
  
  local_80 = &PTR_LAB_0117b358;
  local_84 = (uint)(DAT_01226ad0 == 0);
  local_98 = &PTR_LAB_0117b378;
  local_a8 = &PTR_LAB_0117b390;
  local_c0 = &PTR_LAB_0117b3b0;
  local_90 = &PTR_LAB_01175340;
  local_b8 = &PTR_LAB_01175340;
  local_d8 = &PTR_LAB_0117b3d0;
  ppuStack_d0 = &PTR_LAB_01175340;
  local_f0 = &PTR_LAB_0117b3f0;
  ppuStack_e8 = &PTR_LAB_01175340;
  local_100 = &PTR_LAB_0117b408;
  local_118 = &PTR_LAB_0117b428;
  ppuStack_110 = &PTR_LAB_01175340;
  local_130 = &PTR_LAB_0117b448;
  ppuStack_128 = &PTR_LAB_01175340;
  local_148 = &PTR_LAB_01175340;
  ppuStack_140 = &PTR_LAB_01175340;
  local_150 = &PTR_LAB_0117b470;
  local_168 = &PTR_LAB_0117b490;
  ppuStack_160 = &PTR_LAB_01175340;
  local_180 = &PTR_LAB_01175340;
  ppuStack_178 = &PTR_LAB_01175340;
  DAT_01226ad0 = 1;
  puStack_1a8 = auStack_240;
  puStack_1b0 = auStack_270;
  puStack_1b8 = auStack_330;
  lVar4 = _objc_msgSend(param_3,PTR_s_state_0114c560);
  uStack_9c = (uint)(lVar4 == 1);
  if (lVar4 != 1) {
    CallSupervisor(0xd31f);
    return ZEXT816(0x1f);
  }
  puStack_208 = auStack_2a0;
  puStack_200 = auStack_360;
  _objc_msgSend(param_1,PTR_s_keepalive_node_0114c568);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_copiedComment_0114c0d0);
  uStack_1c0 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_copiedURL_0114c0e0);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_layer_0114ae60);
  uStack_1e8 = _objc_retainAutoreleasedReturnValue();
  uStack_1f8 = uVar5;
  _objc_msgSend(uVar5,PTR_s_closestViewController_0114aec8);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_view_0114b090);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_backgroundColor_0114c520);
  uStack_1f0 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar6);
  _objc_release(uVar5);
  uStack_ac = (uint)(lRam0000000001226868 == 0);
  lStack_1e0 = lVar4;
  if (lRam0000000001226868 == 0) {
    lRam0000000001226868 =
         _objc_getClass(local_a8[uStack_ac] + (int)-(uRam000000000117b3a0 ^ 0x4fca6ce8),
                        s_YTDefaultSheetController_01162c70);
  }
  uVar5 = _objc_retainAutorelease();
  _objc_msgSend(uVar5,PTR_s_sheetControllerWithParentRespond_0114c5a8,0);
  uStack_188 = _objc_retainAutoreleasedReturnValue();
  uStack_c4 = (uint)(lRam0000000001226870 == 0);
  uStack_1d8 = param_1;
  if (lRam0000000001226870 == 0) {
    lRam0000000001226870 =
         _objc_getClass(local_c0[uStack_c4] + (int)-(uRam000000000117b3c0 ^ 0x37cdacf0),
                        s_YTActionSheetAction_01162b40);
  }
  lVar4 = lRam0000000001226870;
  _objc_retainAutorelease(lRam0000000001226870);
  puStack_190 = PTR_s_ytl_defaultBundle_0114ae50;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puStack_198 = PTR_s_localizedStringForKey_value_tabl_0114b278;
  _objc_msgSend(uVar7,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_01162f30,0,0);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_localization_0114c5d0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar3 = puStack_1a8;
  uVar5 = DAT_00c4c228;
  *puStack_1a8 = PTR___NSConcreteStackBlock_01060660;
  puVar3[1] = DAT_00c4c228;
  puVar3[2] = FUN_000c1200;
  puVar3[3] = &DAT_01061cb0;
  uVar10 = _objc_retain(uStack_1c0);
  uVar6 = uStack_1d8;
  puVar3[4] = uVar10;
  puVar3[5] = uVar6;
  puStack_1d0 = PTR_s_actionWithTitle_iconImage_style__0114c5c0;
  _objc_msgSend(lVar4,PTR_s_actionWithTitle_iconImage_style__0114c5c0,uVar8,uVar9,0,puVar3);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_addAction__0114b898;
  _objc_msgSend(uStack_188,PTR_s_addAction__0114b898,uVar6);
  _objc_release(uVar6);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
  uStack_dc = (uint)(lRam0000000001226870 == 0);
  if (lRam0000000001226870 == 0) {
    lRam0000000001226870 =
         _objc_getClass(local_d8[uStack_dc] + (int)-(DAT_0117b3e0 ^ 0x1eb2e3a5),
                        s_YTActionSheetAction_01162b40);
  }
  lVar4 = lRam0000000001226870;
  _objc_retainAutorelease(lRam0000000001226870);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_190);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,puStack_198,&PTR____CFConstantStringClassReference_01162df0,0,0);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puStack_1a0 = PTR_s_imageWithName__0114c5b0;
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_imageWithName__0114c5b0,
                &PTR____CFConstantStringClassReference_01162e30);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar3 = puStack_1b0;
  *puStack_1b0 = PTR___NSConcreteStackBlock_01060660;
  puVar3[1] = uVar5;
  puVar3[2] = FUN_000c1708;
  puVar3[3] = &DAT_010618c0;
  uVar9 = _objc_retain(uStack_1c0);
  puVar3[4] = uVar9;
  _objc_msgSend(lVar4,puStack_1d0,uVar7,uVar8,0,puVar3);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uStack_188,puVar1,uVar9);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar6);
  lVar4 = lStack_1e0;
  uStack_f4 = (uint)(lStack_1e0 == 0);
  puStack_1c8 = puVar1;
  if (lStack_1e0 == 0) {
    uStack_154 = (uint)(lRam0000000001226870 == 0);
                    /* WARNING: Could not recover jumptable at 0x0006c4a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    auVar11 = (*(code *)(local_150[lRam0000000001226870 == 0] +
                        (int)-(uRam000000000117b480 ^ 0x8fb7073)))();
    return auVar11;
  }
  uStack_104 = (uint)(lRam0000000001226870 == 0);
  puStack_210 = auStack_2d0;
  if (lRam0000000001226870 == 0) {
    lRam0000000001226870 =
         _objc_getClass(local_100[uStack_104] + (int)-(uRam000000000117b418 ^ 0x2b9d54ff),
                        s_YTActionSheetAction_01162b40);
  }
  lVar2 = lRam0000000001226870;
  _objc_retainAutorelease(lRam0000000001226870);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_190);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,puStack_198,&PTR____CFConstantStringClassReference_01162eb0,0,0);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,puStack_1a0,&PTR____CFConstantStringClassReference_01162e70);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar3 = puStack_208;
  *puStack_208 = PTR___NSConcreteStackBlock_01060660;
  puVar3[1] = uVar5;
  puVar3[2] = FUN_000c194c;
  puVar3[3] = &DAT_010618c0;
  _objc_retain(lVar4);
  puVar3[4] = lVar4;
  _objc_msgSend(lVar2,puStack_1d0,uVar7,uVar8,0,puVar3);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uStack_188,puVar1,uVar5);
  _objc_release(uVar5);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar6);
  uStack_11c = (uint)(lRam0000000001226870 == 0);
                    /* WARNING: Could not recover jumptable at 0x0006c5f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  auVar11 = (*(code *)(local_118[uStack_11c] + (int)-(uRam000000000117b438 ^ 0xbe90890)))();
  return auVar11;
}


