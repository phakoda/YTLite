/* Decompiled from supplied 5.2.2 arm package. VA 0xbfae8. FUN_000bfae8 */

undefined1  [16] FUN_000bfae8(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 auVar10 [16];
  undefined *puStack_1e0;
  undefined8 uStack_1d8;
  code *pcStack_1d0;
  undefined *puStack_1c8;
  long lStack_1c0;
  undefined8 uStack_1b8;
  undefined *puStack_1b0;
  undefined8 uStack_1a8;
  code *pcStack_1a0;
  undefined *puStack_198;
  long lStack_190;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined *puStack_170;
  undefined *puStack_168;
  undefined *puStack_160;
  undefined *puStack_158;
  undefined *puStack_150;
  undefined8 uStack_148;
  undefined **local_140;
  undefined **local_138;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  undefined **local_118;
  uint uStack_10c;
  undefined **local_108;
  undefined **ppuStack_100;
  uint uStack_f4;
  undefined **local_f0;
  undefined **local_e8;
  uint uStack_dc;
  undefined **local_d8;
  uint uStack_cc;
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
  
  local_80 = &PTR_LAB_01182930;
  local_84 = (uint)(DAT_01226f74 == 0);
  local_98 = &PTR_LAB_01182950;
  local_a8 = &PTR_LAB_01182968;
  local_b8 = &PTR_LAB_01182980;
  local_c8 = &PTR_LAB_01182998;
  local_d8 = &PTR__objc_msgSend_011829b0;
  local_f0 = &PTR_LAB_011829d0;
  local_90 = &PTR_LAB_01175340;
  local_e8 = &PTR_LAB_01175340;
  local_108 = &PTR_LAB_011829f0;
  ppuStack_100 = &PTR_LAB_01175340;
  local_118 = &PTR_LAB_01175340;
  local_120 = &PTR_LAB_01182a10;
  local_130 = &PTR_LAB_01175340;
  local_138 = &PTR_LAB_01175340;
  local_140 = &PTR_LAB_01175340;
  DAT_01226f74 = 1;
  _objc_retain(param_1);
  _objc_msgSend(param_2,PTR_s_URL_0114c578);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_absoluteString_0114c580);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  uStack_9c = (uint)(lVar3 == 0);
  if (lVar3 != 0) {
    lVar4 = _objc_msgSend(lVar3,PTR_s_rangeOfString__0114b670,
                          &PTR____CFConstantStringClassReference_01172350);
    uStack_ac = (uint)(lVar4 == 0x7fffffffffffffff);
    if (lVar4 != 0x7fffffffffffffff) {
      lVar5 = _objc_msgSend(lVar3,PTR_s_length_0114b438);
      lVar5 = _objc_msgSend(lVar3,PTR_s_rangeOfString_options_range__0114c588,
                            &PTR____CFConstantStringClassReference_011722d0,0,lVar4,lVar5 - lVar4);
      uStack_bc = (uint)(lVar5 == 0x7fffffffffffffff);
      if (lVar5 != 0x7fffffffffffffff) {
        _objc_msgSend(lVar3,PTR_s_stringByReplacingCharactersInRan_0114c590,lVar4 + 2,
                      (lVar5 - lVar4) + -2,&PTR____CFConstantStringClassReference_01172290);
        uVar2 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0,uVar2);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        puVar1 = PTR__OBJC_CLASS___UIImage_0114ebf8;
        _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,PTR_s_dataWithContentsOfURL__0114c598,uVar6)
        ;
        uVar7 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(puVar1,PTR_s_imageWithData__0114c5a0,uVar7);
        lVar4 = _objc_retainAutoreleasedReturnValue();
        _objc_release(uVar7);
        uStack_cc = (uint)(lVar4 == 0);
        if (lVar4 != 0) {
          uStack_dc = (uint)(lRam0000000001226868 == 0);
          if (lRam0000000001226868 == 0) {
            lRam0000000001226868 =
                 _objc_getClass(local_d8[uStack_dc] + (int)-(uRam00000000011829c0 ^ 0x2b4efe9a),
                                s_YTDefaultSheetController_011720b0);
          }
          uVar7 = _objc_retainAutorelease();
          _objc_msgSend(uVar7,PTR_s_sheetControllerWithParentRespond_0114c5a8,0);
          uStack_148 = _objc_retainAutoreleasedReturnValue();
          uStack_f4 = (uint)(lRam0000000001226870 == 0);
          uStack_180 = uVar6;
          uStack_178 = uVar2;
          if (lRam0000000001226870 == 0) {
            lRam0000000001226870 = _objc_getClass(s_YTActionSheetAction_01172100);
          }
          lVar3 = lRam0000000001226870;
          _objc_retainAutorelease(lRam0000000001226870);
          puStack_150 = PTR_s_ytl_defaultBundle_0114ae50;
          _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8);
          uVar6 = _objc_retainAutoreleasedReturnValue();
          puStack_158 = PTR_s_localizedStringForKey_value_tabl_0114b278;
          _objc_msgSend(uVar6,PTR_s_localizedStringForKey_value_tabl_0114b278,
                        &PTR____CFConstantStringClassReference_01172310,0,0);
          uVar7 = _objc_retainAutoreleasedReturnValue();
          puStack_160 = PTR_s_imageWithName__0114c5b0;
          _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_imageWithName__0114c5b0,
                        &PTR____CFConstantStringClassReference_01172250);
          uVar8 = _objc_retainAutoreleasedReturnValue();
          uVar2 = DAT_00c4c228;
          puStack_1b0 = PTR___NSConcreteStackBlock_01060660;
          uStack_1a8 = DAT_00c4c228;
          pcStack_1a0 = FUN_000c0ce0;
          puStack_198 = &DAT_010618c0;
          _objc_retain(lVar4);
          puStack_168 = PTR_s_actionWithTitle_iconImage_style__0114c5c0;
          lStack_190 = lVar4;
          _objc_msgSend(lVar3,PTR_s_actionWithTitle_iconImage_style__0114c5c0,uVar7,uVar8,0,
                        &puStack_1b0);
          uVar9 = _objc_retainAutoreleasedReturnValue();
          puStack_170 = PTR_s_addAction__0114b898;
          _objc_msgSend(uStack_148,PTR_s_addAction__0114b898,uVar9);
          _objc_release(uVar9);
          _objc_release(uVar8);
          _objc_release(uVar7);
          _objc_release(uVar6);
          uStack_10c = (uint)(lRam0000000001226870 == 0);
          if (lRam0000000001226870 == 0) {
            lRam0000000001226870 =
                 _objc_getClass(local_108[uStack_10c] + (int)-(uRam0000000001182a00 ^ 0x24d0d88c),
                                s_YTActionSheetAction_01172100);
          }
          lVar3 = lRam0000000001226870;
          _objc_retainAutorelease(lRam0000000001226870);
          _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_150);
          uVar6 = _objc_retainAutoreleasedReturnValue();
          _objc_msgSend(uVar6,puStack_158,&PTR____CFConstantStringClassReference_01172210,0,0);
          uVar7 = _objc_retainAutoreleasedReturnValue();
          _objc_msgSend(PTR_YTPMedia_0114eae0,puStack_160,
                        &PTR____CFConstantStringClassReference_011721d0);
          uVar8 = _objc_retainAutoreleasedReturnValue();
          puStack_1e0 = PTR___NSConcreteStackBlock_01060660;
          uStack_1d8 = uVar2;
          pcStack_1d0 = FUN_000c0eb0;
          puStack_1c8 = &DAT_01061c60;
          _objc_retain(lVar4);
          lStack_1c0 = lVar4;
          _objc_retain(param_1);
          uStack_1b8 = param_1;
          _objc_msgSend(lVar3,puStack_168,uVar7,uVar8,0,&puStack_1e0);
          uVar2 = _objc_retainAutoreleasedReturnValue();
          _objc_msgSend(uStack_148,puStack_170,uVar2);
          _objc_release(uVar2);
          _objc_release(uVar8);
          _objc_release(uVar7);
          _objc_release(uVar6);
          uStack_124 = (uint)(lRam0000000001226870 == 0);
                    /* WARNING: Could not recover jumptable at 0x000c0a90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          auVar10 = (*(code *)(local_120[uStack_124] + (int)-(uRam0000000001182a20 ^ 0xd8ba6c6e)))()
          ;
          return auVar10;
        }
        _objc_release(local_c8[uStack_cc] + (int)-(uRam00000000011829a8 ^ 0xab1919ba),0);
        _objc_release(uVar6);
        _objc_release(uVar2);
      }
    }
  }
  _objc_release(lVar3);
  _objc_release(param_1);
  CallSupervisor(0x7def);
  auVar10._8_8_ = 0x1f;
  auVar10._0_8_ = 0x1a;
  return auVar10;
}


