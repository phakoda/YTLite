/* Decompiled from supplied 5.2.2 arm package. VA 0x9c084. FUN_0009c084 */

void FUN_0009c084(undefined8 param_1)

{
  undefined1 auStack_370 [312];
  undefined1 *puStack_238;
  undefined **local_230;
  undefined **ppuStack_228;
  undefined **local_218;
  undefined **local_208;
  undefined **ppuStack_200;
  undefined **local_1f0;
  undefined **ppuStack_1e8;
  undefined **local_1d8;
  undefined **local_1d0;
  undefined **ppuStack_1c8;
  undefined **local_1b8;
  undefined **ppuStack_1b0;
  undefined **local_1a0;
  undefined **local_190;
  undefined **local_180;
  undefined **local_170;
  undefined **local_160;
  undefined **ppuStack_158;
  undefined **local_148;
  undefined **local_138;
  undefined **ppuStack_130;
  undefined **local_120;
  undefined **ppuStack_118;
  undefined **local_108;
  undefined **local_100;
  undefined **ppuStack_f8;
  undefined **local_e8;
  undefined **local_e0;
  undefined **local_d0;
  undefined **local_c0;
  undefined **local_b0;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  undefined8 local_70;
  
  local_70 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR__objc_msgSend_0117f828;
  local_7c = (uint)(DAT_01226dd4 == 0);
  local_90 = &PTR__objc_msgSend_0117f848;
  local_a0 = &PTR__objc_msgSend_0117f860;
  local_b0 = &PTR__objc_msgSend_0117f878;
  local_c0 = &PTR_LAB_0117f890;
  local_d0 = &PTR_LAB_0117f8a8;
  local_e8 = &PTR_LAB_0117f8c8;
  local_88 = &PTR_LAB_01175340;
  local_e0 = &PTR_LAB_01175340;
  local_100 = &PTR_LAB_01175340;
  ppuStack_f8 = &PTR_LAB_01175340;
  local_108 = &PTR_LAB_0117f8f0;
  local_120 = &PTR_LAB_0117f910;
  ppuStack_118 = &PTR_LAB_01175340;
  local_138 = &PTR_LAB_0117f930;
  ppuStack_130 = &PTR_LAB_01175340;
  local_148 = &PTR_LAB_0117f948;
  local_160 = &PTR_LAB_0117f968;
  ppuStack_158 = &PTR_LAB_01175340;
  local_170 = &PTR_LAB_0117f980;
  local_180 = &PTR__objc_msgSend_0117f998;
  local_190 = &PTR_LAB_0117f9b0;
  local_1a0 = &PTR_LAB_0117f9c8;
  local_1b8 = &PTR_LAB_0117f9e8;
  ppuStack_1b0 = &PTR_LAB_01175340;
  local_1d0 = &PTR_LAB_01175340;
  ppuStack_1c8 = &PTR_LAB_01175340;
  local_1d8 = &PTR_LAB_0117fa10;
  local_1f0 = &PTR_LAB_0117fa30;
  ppuStack_1e8 = &PTR_LAB_01175340;
  local_208 = &PTR_LAB_0117fa50;
  ppuStack_200 = &PTR_LAB_01175340;
  local_218 = &PTR_LAB_0117fa68;
  local_230 = &PTR_LAB_01175340;
  ppuStack_228 = &PTR_LAB_01175340;
  DAT_01226dd4 = 1;
  puStack_238 = auStack_370;
  (*DAT_012265e8)(param_1);
  uStack_94 = FUN_000e4120(&PTR____CFConstantStringClassReference_0116bca0);
                    /* WARNING: Could not recover jumptable at 0x0009cbc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_90[uStack_94] + (int)-(DAT_0117f858 ^ 0xbfb82ddb)))();
  return;
}


