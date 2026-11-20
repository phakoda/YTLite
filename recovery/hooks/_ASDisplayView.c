// Decompiled hook evidence for _ASDisplayView. This is not compilable Logos source.

// -[_ASDisplayView didMoveToWindow], original IMP slot 0x012260a8
/* Decompiled from supplied 5.2.2 arm package. VA 0x67fd4. recovered_hook_00067fd4 */

void recovered_hook_00067fd4(undefined8 param_1)

{
  ulong uVar1;
  
  uRam0000000001226ac4 = 1;
  (*DAT_012260a8)(param_1);
  uVar1 = FUN_000d7228(@"noAds");
                    /* WARNING: Could not recover jumptable at 0x000682c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117af48)[uVar1 & 0xffffffff] + (int)-(DAT_0117af58 ^ 0x83adb2f9)))();
  return;
}



// -[_ASDisplayView setKeepalive_node:], original IMP slot 0x012260b0
/* Decompiled from supplied 5.2.2 arm package. VA 0x68370. FUN_00068370 */

void FUN_00068370(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStack_4e0 [16];
  undefined1 auStack_4d0 [16];
  undefined1 auStack_4c0 [128];
  undefined1 auStack_440 [64];
  undefined1 auStack_400 [32];
  undefined1 auStack_3e0 [32];
  undefined1 auStack_3c0 [32];
  undefined1 auStack_3a0 [32];
  undefined1 auStack_380 [32];
  undefined1 auStack_360 [96];
  undefined1 auStack_300 [32];
  undefined1 *puStack_2e0;
  undefined1 *puStack_2d8;
  undefined1 *puStack_2d0;
  undefined1 *puStack_2b0;
  undefined8 local_2a8;
  undefined1 *puStack_2a0;
  undefined1 *puStack_298;
  undefined1 *puStack_290;
  undefined1 *puStack_288;
  undefined8 local_280;
  undefined1 *puStack_278;
  undefined1 *puStack_270;
  undefined1 *puStack_268;
  undefined **local_260;
  undefined **ppuStack_258;
  undefined **local_248;
  undefined **ppuStack_240;
  undefined **local_230;
  undefined **local_220;
  undefined **local_210;
  undefined **local_200;
  undefined **local_1f0;
  undefined **ppuStack_1e8;
  undefined **local_1d8;
  undefined **ppuStack_1d0;
  undefined **local_1c0;
  undefined **ppuStack_1b8;
  undefined **local_1a8;
  undefined **local_1a0;
  undefined **ppuStack_198;
  undefined **local_188;
  undefined **ppuStack_180;
  undefined **local_170;
  undefined **local_160;
  undefined **local_150;
  undefined **ppuStack_148;
  undefined **local_138;
  undefined **ppuStack_130;
  undefined **local_120;
  undefined **local_110;
  undefined **local_100;
  undefined **ppuStack_f8;
  undefined **local_e8;
  undefined **ppuStack_e0;
  undefined **local_d0;
  undefined **ppuStack_c8;
  undefined **local_b8;
  undefined **local_a8;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  undefined8 local_70;
  
  local_70 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0117af80;
  local_7c = (uint)(DAT_01226ac8 == 0);
  local_90 = &PTR_LAB_0117afa0;
  local_a8 = &PTR_LAB_0117afc0;
  local_b8 = &PTR_LAB_0117afd8;
  local_88 = &PTR_LAB_01175340;
  local_a0 = &PTR_LAB_01175340;
  local_d0 = &PTR_LAB_0117aff8;
  ppuStack_c8 = &PTR_LAB_01175340;
  local_e8 = &PTR_LAB_0117b018;
  ppuStack_e0 = &PTR_LAB_01175340;
  local_100 = &PTR_LAB_0117b038;
  ppuStack_f8 = &PTR_LAB_01175340;
  local_110 = &PTR_LAB_0117b050;
  local_120 = &PTR_LAB_0117b068;
  local_138 = &PTR_LAB_0117b088;
  ppuStack_130 = &PTR_LAB_01175340;
  local_150 = &PTR_LAB_0117b0a8;
  ppuStack_148 = &PTR_LAB_01175340;
  local_160 = &PTR_LAB_0117b0c0;
  local_170 = &PTR_LAB_0117b0d8;
  local_188 = &PTR_LAB_0117b0f8;
  ppuStack_180 = &PTR_LAB_01175340;
  local_1a0 = &PTR_LAB_01175340;
  ppuStack_198 = &PTR_LAB_01175340;
  local_1a8 = &PTR_LAB_0117b120;
  local_1c0 = &PTR_LAB_0117b140;
  ppuStack_1b8 = &PTR_LAB_01175340;
  local_1d8 = &PTR_LAB_0117b160;
  ppuStack_1d0 = &PTR_LAB_01175340;
  local_1f0 = &PTR_LAB_0117b180;
  ppuStack_1e8 = &PTR_LAB_01175340;
  local_200 = &PTR_LAB_0117b198;
  local_210 = &PTR_LAB_0117b1b0;
  local_220 = &PTR_LAB_0117b1c8;
  local_230 = &PTR_LAB_0117b1e0;
  local_248 = &PTR_LAB_0117b200;
  ppuStack_240 = &PTR_LAB_01175340;
  local_260 = &PTR_LAB_01175340;
  ppuStack_258 = &PTR_LAB_01175340;
  if (DAT_01226ac8 == 0) {
    s_oledTheme_011623ec[0] = DAT_011623e2 ^ 0x51;
    s_oledTheme_011623ec[1] = bRam00000000011623e3 ^ 0xef;
    s_oledTheme_011623ec[2] = bRam00000000011623e4 ^ 0x5c;
    s_oledTheme_011623ec[3] = bRam00000000011623e5 ^ 0xf8;
    s_oledTheme_011623ec[4] = bRam00000000011623e6 ^ 0x80;
    s_oledTheme_011623ec[5] = bRam00000000011623e7 ^ 0xe1;
    s_oledTheme_011623ec[6] = bRam00000000011623e8 ^ 0xa3;
    s_oledTheme_011623ec[7] = bRam00000000011623e9 ^ 0xbe;
    s_oledTheme_011623ec[8] = bRam00000000011623ea ^ 0x8e;
    s_oledTheme_011623ec[9] = bRam00000000011623eb ^ 0xcc;
    s_selector_011623d9[0] = DAT_011623d0 ^ 0x75;
    s_selector_011623d9[1] = bRam00000000011623d1 ^ 0xb4;
    s_selector_011623d9[2] = bRam00000000011623d2 ^ 0x42;
    s_selector_011623d9[3] = bRam00000000011623d3 ^ 0x77;
    s_selector_011623d9[4] = bRam00000000011623d4 ^ 0xcd;
    s_selector_011623d9[5] = bRam00000000011623d5 ^ 0x96;
    s_selector_011623d9[6] = bRam00000000011623d6 ^ 0x96;
    s_selector_011623d9[7] = bRam00000000011623d7 ^ 0x41;
    s_selector_011623d9[8] = bRam00000000011623d8 ^ 0x31;
    s_savePFP__011623c7[0] = DAT_011623be ^ 0x19;
    s_savePFP__011623c7[1] = bRam00000000011623bf ^ 2;
    s_savePFP__011623c7[2] = bRam00000000011623c0 ^ 200;
    s_savePFP__011623c7[3] = bRam00000000011623c1 ^ 0x6b;
    s_savePFP__011623c7[4] = bRam00000000011623c2 ^ 0xfd;
    s_savePFP__011623c7[5] = bRam00000000011623c3 ^ 0xe7;
    s_savePFP__011623c7[6] = bRam00000000011623c4 ^ 0xde;
    s_savePFP__011623c7[7] = bRam00000000011623c5 ^ 0x35;
    s_savePFP__011623c7[8] = bRam00000000011623c6 ^ 0x5d;
    s_eml_animated_subscribe_button_011623a0[0] = DAT_01162380 ^ 0xcb;
    s_eml_animated_subscribe_button_011623a0[1] = bRam0000000001162381 ^ 100;
    s_eml_animated_subscribe_button_011623a0[2] = bRam0000000001162382 ^ 0x6f;
    s_eml_animated_subscribe_button_011623a0[3] = bRam0000000001162383 ^ 0x22;
    s_eml_animated_subscribe_button_011623a0[4] = bRam0000000001162384 ^ 0xd2;
    s_eml_animated_subscribe_button_011623a0[5] = bRam0000000001162385 ^ 0xa1;
    s_eml_animated_subscribe_button_011623a0[6] = bRam0000000001162386 ^ 0x54;
    s_eml_animated_subscribe_button_011623a0[7] = bRam0000000001162387 ^ 0x35;
    s_eml_animated_subscribe_button_011623a0[8] = bRam0000000001162388 ^ 0x1f;
    s_eml_animated_subscribe_button_011623a0[9] = bRam0000000001162389 ^ 0x11;
    s_eml_animated_subscribe_button_011623a0[10] = bRam000000000116238a ^ 0xd2;
    s_eml_animated_subscribe_button_011623a0[0xb] = bRam000000000116238b ^ 0x52;
    s_eml_animated_subscribe_button_011623a0[0xc] = bRam000000000116238c ^ 0x39;
    s_eml_animated_subscribe_button_011623a0[0xd] = bRam000000000116238d ^ 0x36;
    s_eml_animated_subscribe_button_011623a0[0xe] = bRam000000000116238e ^ 0x1d;
    s_eml_animated_subscribe_button_011623a0[0xf] = bRam000000000116238f ^ 0x8d;
    s_eml_animated_subscribe_button_011623a0[0x10] = bRam0000000001162390 ^ 0x68;
    s_eml_animated_subscribe_button_011623a0[0x11] = bRam0000000001162391 ^ 0x66;
    s_eml_animated_subscribe_button_011623a0[0x12] = bRam0000000001162392 ^ 0x23;
    s_eml_animated_subscribe_button_011623a0[0x13] = bRam0000000001162393 ^ 0xd2;
    s_eml_animated_subscribe_button_011623a0[0x14] = bRam0000000001162394 ^ 0xa0;
    s_eml_animated_subscribe_button_011623a0[0x15] = bRam0000000001162395 ^ 0x71;
    s_eml_animated_subscribe_button_011623a0[0x16] = bRam0000000001162396 ^ 0xcd;
    s_eml_animated_subscribe_button_011623a0[0x17] = bRam0000000001162397 ^ 0xc3;
    s_eml_animated_subscribe_button_011623a0[0x18] = bRam0000000001162398 ^ 0xbc;
    s_eml_animated_subscribe_button_011623a0[0x19] = bRam0000000001162399 ^ 0x35;
    s_eml_animated_subscribe_button_011623a0[0x1a] = bRam000000000116239a ^ 0x94;
    s_eml_animated_subscribe_button_011623a0[0x1b] = bRam000000000116239b ^ 0x94;
    s_eml_animated_subscribe_button_011623a0[0x1c] = bRam000000000116239c ^ 0x7d;
    s_eml_animated_subscribe_button_011623a0[0x1d] = bRam000000000116239d ^ 0xac;
    s_eml_compact_subscribe_button_01162360[0] = DAT_01162340 ^ 0x32;
    s_eml_compact_subscribe_button_01162360[1] = bRam0000000001162341 ^ 0xeb;
    s_eml_compact_subscribe_button_01162360[2] = bRam0000000001162342 ^ 0xae;
    s_eml_compact_subscribe_button_01162360[3] = bRam0000000001162343 ^ 0x67;
    s_eml_compact_subscribe_button_01162360[4] = bRam0000000001162344 ^ 1;
    s_eml_compact_subscribe_button_01162360[5] = bRam0000000001162345 ^ 6;
    s_eml_compact_subscribe_button_01162360[6] = bRam0000000001162346 ^ 0x33;
    s_eml_compact_subscribe_button_01162360[7] = bRam0000000001162347 ^ 0x6d;
    s_eml_compact_subscribe_button_01162360[8] = bRam0000000001162348 ^ 100;
    s_eml_compact_subscribe_button_01162360[9] = bRam0000000001162349 ^ 0xf5;
    s_eml_compact_subscribe_button_01162360[10] = bRam000000000116234a ^ 0xe2;
    s_eml_compact_subscribe_button_01162360[0xb] = bRam000000000116234b ^ 0xe5;
    s_eml_compact_subscribe_button_01162360[0xc] = bRam000000000116234c ^ 0xa0;
    s_eml_compact_subscribe_button_01162360[0xd] = bRam000000000116234d ^ 0x29;
    s_eml_compact_subscribe_button_01162360[0xe] = bRam000000000116234e ^ 0x16;
    s_eml_compact_subscribe_button_01162360[0xf] = bRam000000000116234f ^ 0x22;
    s_eml_compact_subscribe_button_01162360[0x10] = bRam0000000001162350 ^ 0x82;
    s_eml_compact_subscribe_button_01162360[0x11] = bRam0000000001162351 ^ 0xd5;
    s_eml_compact_subscribe_button_01162360[0x12] = bRam0000000001162352 ^ 0xc0;
    s_eml_compact_subscribe_button_01162360[0x13] = bRam0000000001162353 ^ 0x6c;
    s_eml_compact_subscribe_button_01162360[0x14] = bRam0000000001162354 ^ 0x3f;
    s_eml_compact_subscribe_button_01162360[0x15] = bRam0000000001162355 ^ 0x51;
    s_eml_compact_subscribe_button_01162360[0x16] = bRam0000000001162356 ^ 0xd6;
    s_eml_compact_subscribe_button_01162360[0x17] = bRam0000000001162357 ^ 0xc6;
    s_eml_compact_subscribe_button_01162360[0x18] = bRam0000000001162358 ^ 0x66;
    s_eml_compact_subscribe_button_01162360[0x19] = bRam0000000001162359 ^ 0x78;
    s_eml_compact_subscribe_button_01162360[0x1a] = bRam000000000116235a ^ 0x6b;
    s_eml_compact_subscribe_button_01162360[0x1b] = bRam000000000116235b ^ 0x26;
    s_eml_compact_subscribe_button_01162360[0x1c] = bRam000000000116235c ^ 0xc1;
    s_ELMImageNode_View_01162320[0] = DAT_01162300 ^ 0x8c;
    s_ELMImageNode_View_01162320[1] = bRam0000000001162301 ^ 0x79;
    s_ELMImageNode_View_01162320[2] = bRam0000000001162302 ^ 0x98;
    s_ELMImageNode_View_01162320[3] = bRam0000000001162303 ^ 8;
    s_ELMImageNode_View_01162320[4] = bRam0000000001162304 ^ 0x5f;
    s_ELMImageNode_View_01162320[5] = bRam0000000001162305 ^ 0x36;
    s_ELMImageNode_View_01162320[6] = bRam0000000001162306 ^ 0x8e;
    s_ELMImageNode_View_01162320[7] = bRam0000000001162307 ^ 0x8a;
    s_ELMImageNode_View_01162320[8] = bRam0000000001162308 ^ 0x2b;
    s_ELMImageNode_View_01162320[9] = bRam0000000001162309 ^ 0x54;
    s_ELMImageNode_View_01162320[10] = bRam000000000116230a ^ 0x7b;
    s_ELMImageNode_View_01162320[0xb] = bRam000000000116230b ^ 7;
    s_ELMImageNode_View_01162320[0xc] = bRam000000000116230c ^ 0x44;
    s_ELMImageNode_View_01162320[0xd] = bRam000000000116230d ^ 0x32;
    s_ELMImageNode_View_01162320[0xe] = bRam000000000116230e ^ 0x6e;
    s_ELMImageNode_View_01162320[0xf] = bRam000000000116230f ^ 0x79;
    s_ELMImageNode_View_01162320[0x10] = bRam0000000001162310 ^ 0x62;
    s_ELMImageNode_View_01162320[0x11] = bRam0000000001162311 ^ 0xf9;
    s_noPlayerSubButton_01162420[0] = DAT_01162400 ^ 0xa1;
    s_noPlayerSubButton_01162420[1] = bRam0000000001162401 ^ 0x22;
    s_noPlayerSubButton_01162420[2] = bRam0000000001162402 ^ 0x96;
    s_noPlayerSubButton_01162420[3] = bRam0000000001162403 ^ 0xf0;
    s_noPlayerSubButton_01162420[4] = bRam0000000001162404 ^ 0xf8;
    s_noPlayerSubButton_01162420[5] = bRam0000000001162405 ^ 0xfa;
    s_noPlayerSubButton_01162420[6] = bRam0000000001162406 ^ 0xda;
    s_noPlayerSubButton_01162420[7] = bRam0000000001162407 ^ 0x49;
    s_noPlayerSubButton_01162420[8] = bRam0000000001162408 ^ 0x52;
    s_noPlayerSubButton_01162420[9] = bRam0000000001162409 ^ 100;
    s_noPlayerSubButton_01162420[10] = bRam000000000116240a ^ 0x9f;
    s_noPlayerSubButton_01162420[0xb] = bRam000000000116240b ^ 0x18;
    s_noPlayerSubButton_01162420[0xc] = bRam000000000116240c ^ 0xaf;
    s_noPlayerSubButton_01162420[0xd] = bRam000000000116240d ^ 0x6a;
    s_noPlayerSubButton_01162420[0xe] = bRam000000000116240e ^ 0x5a;
    s_noPlayerSubButton_01162420[0xf] = bRam000000000116240f ^ 0xc3;
    s_noPlayerSubButton_01162420[0x10] = bRam0000000001162410 ^ 0xaa;
    s_noPlayerSubButton_01162420[0x11] = bRam0000000001162411 ^ 0xbe;
    s_YTWatchNextResultsViewController_011622d0[0] = bRam00000000011622a0 ^ 0xe2;
    s_YTWatchNextResultsViewController_011622d0[1] = bRam00000000011622a1 ^ 0x43;
    s_YTWatchNextResultsViewController_011622d0[2] = bRam00000000011622a2 ^ 0x29;
    s_YTWatchNextResultsViewController_011622d0[3] = bRam00000000011622a3 ^ 0x96;
    s_YTWatchNextResultsViewController_011622d0[4] = bRam00000000011622a4 ^ 0xac;
    s_YTWatchNextResultsViewController_011622d0[5] = bRam00000000011622a5 ^ 0xd2;
    s_YTWatchNextResultsViewController_011622d0[6] = bRam00000000011622a6 ^ 0x96;
    s_YTWatchNextResultsViewController_011622d0[7] = bRam00000000011622a7 ^ 0x19;
    s_YTWatchNextResultsViewController_011622d0[8] = bRam00000000011622a8 ^ 6;
    s_YTWatchNextResultsViewController_011622d0[9] = bRam00000000011622a9 ^ 0xa9;
    s_YTWatchNextResultsViewController_011622d0[10] = bRam00000000011622aa ^ 0x5c;
    s_YTWatchNextResultsViewController_011622d0[0xb] = bRam00000000011622ab ^ 0x49;
    s_YTWatchNextResultsViewController_011622d0[0xc] = bRam00000000011622ac ^ 0x99;
    s_YTWatchNextResultsViewController_011622d0[0xd] = bRam00000000011622ad ^ 0x7c;
    s_YTWatchNextResultsViewController_011622d0[0xe] = bRam00000000011622ae ^ 0xcf;
    s_YTWatchNextResultsViewController_011622d0[0xf] = bRam00000000011622af ^ 0xfa;
    s_YTWatchNextResultsViewController_011622d0[0x10] = bRam00000000011622b0 ^ 0x24;
    s_YTWatchNextResultsViewController_011622d0[0x11] = bRam00000000011622b1 ^ 5;
    s_YTWatchNextResultsViewController_011622d0[0x12] = bRam00000000011622b2 ^ 0x75;
    s_YTWatchNextResultsViewController_011622d0[0x13] = bRam00000000011622b3 ^ 0xe2;
    s_YTWatchNextResultsViewController_011622d0[0x14] = bRam00000000011622b4 ^ 0x6a;
    s_YTWatchNextResultsViewController_011622d0[0x15] = bRam00000000011622b5 ^ 0x42;
    s_YTWatchNextResultsViewController_011622d0[0x16] = bRam00000000011622b6 ^ 0x12;
    s_YTWatchNextResultsViewController_011622d0[0x17] = bRam00000000011622b7 ^ 0xcc;
    s_YTWatchNextResultsViewController_011622d0[0x18] = bRam00000000011622b8 ^ 0x6d;
    s_YTWatchNextResultsViewController_011622d0[0x19] = bRam00000000011622b9 ^ 0x18;
    s_YTWatchNextResultsViewController_011622d0[0x1a] = bRam00000000011622ba ^ 0xee;
    s_YTWatchNextResultsViewController_011622d0[0x1b] = bRam00000000011622bb ^ 0x35;
    s_YTWatchNextResultsViewController_011622d0[0x1c] = bRam00000000011622bc ^ 0xc6;
    s_YTWatchNextResultsViewController_011622d0[0x1d] = bRam00000000011622bd ^ 0x9c;
    s_YTWatchNextResultsViewController_011622d0[0x1e] = bRam00000000011622be ^ 0x42;
    s_YTWatchNextResultsViewController_011622d0[0x1f] = bRam00000000011622bf ^ 0xe3;
    s_YTWatchNextResultsViewController_011622d0[0x20] = bRam00000000011622c0 ^ 0x12;
    s_postManager__0116222a[0] = DAT_0116221d ^ 0xda;
    s_postManager__0116222a[1] = bRam000000000116221e ^ 0x8d;
    s_postManager__0116222a[2] = bRam000000000116221f ^ 0xdb;
    s_postManager__0116222a[3] = bRam0000000001162220 ^ 0x79;
    s_postManager__0116222a[4] = bRam0000000001162221 ^ 0xe5;
    s_postManager__0116222a[5] = bRam0000000001162222 ^ 0x2e;
    s_postManager__0116222a[6] = bRam0000000001162223 ^ 0x4f;
    s_postManager__0116222a[7] = bRam0000000001162224 ^ 0xcc;
    s_postManager__0116222a[8] = bRam0000000001162225 ^ 0xa5;
    s_postManager__0116222a[9] = bRam0000000001162226 ^ 9;
    s_postManager__0116222a[10] = bRam0000000001162227 ^ 0x41;
    s_postManager__0116222a[0xb] = bRam0000000001162228 ^ 0x15;
    s_postManager__0116222a[0xc] = bRam0000000001162229 ^ 0xf6;
    s_key_011621d0[0] = DAT_011621cc ^ 0x1f;
    s_key_011621d0[1] = bRam00000000011621cd ^ 0x2c;
    s_key_011621d0[2] = bRam00000000011621ce ^ 0x71;
    s_key_011621d0[3] = bRam00000000011621cf ^ 0xc0;
    s_YTShortsPlayerViewController_01162200[0] = bRam00000000011621e0 ^ 0x1e;
    s_YTShortsPlayerViewController_01162200[1] = bRam00000000011621e1 ^ 0xa1;
    s_YTShortsPlayerViewController_01162200[2] = bRam00000000011621e2 ^ 0xd8;
    s_YTShortsPlayerViewController_01162200[3] = bRam00000000011621e3 ^ 0xdb;
    s_YTShortsPlayerViewController_01162200[4] = bRam00000000011621e4 ^ 0x2b;
    s_YTShortsPlayerViewController_01162200[5] = bRam00000000011621e5 ^ 0x59;
    s_YTShortsPlayerViewController_01162200[6] = bRam00000000011621e6 ^ 0x9c;
    s_YTShortsPlayerViewController_01162200[7] = bRam00000000011621e7 ^ 0xb4;
    s_YTShortsPlayerViewController_01162200[8] = bRam00000000011621e8 ^ 0x55;
    s_YTShortsPlayerViewController_01162200[9] = bRam00000000011621e9 ^ 0xec;
    s_YTShortsPlayerViewController_01162200[10] = bRam00000000011621ea ^ 0xa7;
    s_YTShortsPlayerViewController_01162200[0xb] = bRam00000000011621eb ^ 0xc3;
    s_YTShortsPlayerViewController_01162200[0xc] = bRam00000000011621ec ^ 0x4d;
    s_YTShortsPlayerViewController_01162200[0xd] = bRam00000000011621ed ^ 0x66;
    s_YTShortsPlayerViewController_01162200[0xe] = bRam00000000011621ee ^ 0x62;
    s_YTShortsPlayerViewController_01162200[0xf] = bRam00000000011621ef ^ 0x3a;
    s_YTShortsPlayerViewController_01162200[0x10] = bRam00000000011621f0 ^ 0xd9;
    s_YTShortsPlayerViewController_01162200[0x11] = bRam00000000011621f1 ^ 0x39;
    s_YTShortsPlayerViewController_01162200[0x12] = bRam00000000011621f2 ^ 0xfb;
    s_YTShortsPlayerViewController_01162200[0x13] = bRam00000000011621f3 ^ 0x24;
    s_YTShortsPlayerViewController_01162200[0x14] = bRam00000000011621f4 ^ 0x9b;
    s_YTShortsPlayerViewController_01162200[0x15] = bRam00000000011621f5 ^ 0x4b;
    s_YTShortsPlayerViewController_01162200[0x16] = bRam00000000011621f6 ^ 0xa4;
    s_YTShortsPlayerViewController_01162200[0x17] = bRam00000000011621f7 ^ 0xfe;
    s_YTShortsPlayerViewController_01162200[0x18] = bRam00000000011621f8 ^ 0x1c;
    s_YTShortsPlayerViewController_01162200[0x19] = bRam00000000011621f9 ^ 0xdf;
    s_YTShortsPlayerViewController_01162200[0x1a] = bRam00000000011621fa ^ 0x4b;
    s_YTShortsPlayerViewController_01162200[0x1b] = bRam00000000011621fb ^ 0x7f;
    s_YTShortsPlayerViewController_01162200[0x1c] = bRam00000000011621fc ^ 0xad;
    s_eml_live_chat_text_message_01162460[0] = DAT_01162440 ^ 0xe8;
    s_eml_live_chat_text_message_01162460[1] = bRam0000000001162441 ^ 0x81;
    s_eml_live_chat_text_message_01162460[2] = bRam0000000001162442 ^ 0x85;
    s_eml_live_chat_text_message_01162460[3] = bRam0000000001162443 ^ 0x5c;
    s_eml_live_chat_text_message_01162460[4] = bRam0000000001162444 ^ 0x6c;
    s_eml_live_chat_text_message_01162460[5] = bRam0000000001162445 ^ 99;
    s_eml_live_chat_text_message_01162460[6] = bRam0000000001162446 ^ 0x8d;
    s_eml_live_chat_text_message_01162460[7] = bRam0000000001162447 ^ 0x53;
    s_eml_live_chat_text_message_01162460[8] = bRam0000000001162448 ^ 0xe6;
    s_eml_live_chat_text_message_01162460[9] = bRam0000000001162449 ^ 0xb3;
    s_eml_live_chat_text_message_01162460[10] = bRam000000000116244a ^ 0xf6;
    s_eml_live_chat_text_message_01162460[0xb] = bRam000000000116244b ^ 0x4b;
    s_eml_live_chat_text_message_01162460[0xc] = bRam000000000116244c ^ 0x21;
    s_eml_live_chat_text_message_01162460[0xd] = bRam000000000116244d ^ 0x92;
    s_eml_live_chat_text_message_01162460[0xe] = bRam000000000116244e ^ 0xd;
    s_eml_live_chat_text_message_01162460[0xf] = bRam000000000116244f ^ 0x8f;
    s_eml_live_chat_text_message_01162460[0x10] = bRam0000000001162450 ^ 0x37;
    s_eml_live_chat_text_message_01162460[0x11] = bRam0000000001162451 ^ 0x5c;
    s_eml_live_chat_text_message_01162460[0x12] = bRam0000000001162452 ^ 0x51;
    s_eml_live_chat_text_message_01162460[0x13] = bRam0000000001162453 ^ 0x9d;
    s_eml_live_chat_text_message_01162460[0x14] = bRam0000000001162454 ^ 2;
    s_eml_live_chat_text_message_01162460[0x15] = bRam0000000001162455 ^ 0xe4;
    s_eml_live_chat_text_message_01162460[0x16] = bRam0000000001162456 ^ 0xdb;
    s_eml_live_chat_text_message_01162460[0x17] = bRam0000000001162457 ^ 199;
    s_eml_live_chat_text_message_01162460[0x18] = bRam0000000001162458 ^ 0xca;
    s_eml_live_chat_text_message_01162460[0x19] = bRam0000000001162459 ^ 0x5b;
    s_eml_live_chat_text_message_01162460[0x1a] = bRam000000000116245a ^ 0x61;
    s_text_011621d9[0] = DAT_011621d4 ^ 0x84;
    s_text_011621d9[1] = bRam00000000011621d5 ^ 0x6a;
    s_text_011621d9[2] = bRam00000000011621d6 ^ 0x72;
    s_text_011621d9[3] = bRam00000000011621d7 ^ 0xf2;
    s_text_011621d9[4] = bRam00000000011621d8 ^ 0x41;
    s_decorated_avatar_id_011621a0[0] = DAT_01162180 ^ 0x3a;
    s_decorated_avatar_id_011621a0[1] = bRam0000000001162181 ^ 0xb7;
    s_decorated_avatar_id_011621a0[2] = bRam0000000001162182 ^ 0xec;
    s_decorated_avatar_id_011621a0[3] = bRam0000000001162183 ^ 0xe7;
    s_decorated_avatar_id_011621a0[4] = bRam0000000001162184 ^ 0xed;
    s_decorated_avatar_id_011621a0[5] = bRam0000000001162185 ^ 0xdb;
    s_decorated_avatar_id_011621a0[6] = bRam0000000001162186 ^ 0xe8;
    s_decorated_avatar_id_011621a0[7] = bRam0000000001162187 ^ 0xdd;
    s_decorated_avatar_id_011621a0[8] = bRam0000000001162188 ^ 0xaf;
    s_decorated_avatar_id_011621a0[9] = bRam0000000001162189 ^ 0x88;
    s_decorated_avatar_id_011621a0[10] = bRam000000000116218a ^ 0xd4;
    s_decorated_avatar_id_011621a0[0xb] = bRam000000000116218b ^ 0xf5;
    s_decorated_avatar_id_011621a0[0xc] = bRam000000000116218c ^ 0x81;
    s_decorated_avatar_id_011621a0[0xd] = bRam000000000116218d ^ 0x9b;
    s_decorated_avatar_id_011621a0[0xe] = bRam000000000116218e ^ 0x69;
    s_decorated_avatar_id_011621a0[0xf] = bRam000000000116218f ^ 0xe2;
    s_decorated_avatar_id_011621a0[0x10] = bRam0000000001162190 ^ 0xd;
    s_decorated_avatar_id_011621a0[0x11] = bRam0000000001162191 ^ 200;
    s_decorated_avatar_id_011621a0[0x12] = bRam0000000001162192 ^ 0xcc;
    s_decorated_avatar_id_011621a0[0x13] = bRam0000000001162193 ^ 0x15;
    s_commentManager_01162246[0] = DAT_01162237 ^ 0xa9;
    s_commentManager_01162246[1] = bRam0000000001162238 ^ 0x6d;
    s_commentManager_01162246[2] = bRam0000000001162239 ^ 0x7b;
    s_commentManager_01162246[3] = bRam000000000116223a ^ 0xae;
    s_commentManager_01162246[4] = bRam000000000116223b ^ 0x1a;
    s_commentManager_01162246[5] = bRam000000000116223c ^ 0x6e;
    s_commentManager_01162246[6] = bRam000000000116223d ^ 0xd8;
    s_commentManager_01162246[7] = bRam000000000116223e ^ 0x7d;
    s_commentManager_01162246[8] = bRam000000000116223f ^ 0xb;
    s_commentManager_01162246[9] = bRam0000000001162240 ^ 0xed;
    s_commentManager_01162246[10] = bRam0000000001162241 ^ 0x5c;
    s_commentManager_01162246[0xb] = bRam0000000001162242 ^ 0x9a;
    s_commentManager_01162246[0xc] = bRam0000000001162243 ^ 0x94;
    s_commentManager_01162246[0xd] = bRam0000000001162244 ^ 0x59;
    s_commentManager_01162246[0xe] = bRam0000000001162245 ^ 0xc9;
    s_id_ui_backstage_original_post_011624a0[0] = DAT_01162480 ^ 0x5c;
    s_id_ui_backstage_original_post_011624a0[1] = bRam0000000001162481 ^ 0xe7;
    s_id_ui_backstage_original_post_011624a0[2] = bRam0000000001162482 ^ 0x41;
    s_id_ui_backstage_original_post_011624a0[3] = bRam0000000001162483 ^ 0x7f;
    s_id_ui_backstage_original_post_011624a0[4] = bRam0000000001162484 ^ 0x60;
    s_id_ui_backstage_original_post_011624a0[5] = bRam0000000001162485 ^ 0x3a;
    s_id_ui_backstage_original_post_011624a0[6] = bRam0000000001162486 ^ 0xbf;
    s_id_ui_backstage_original_post_011624a0[7] = bRam0000000001162487 ^ 0x86;
    s_id_ui_backstage_original_post_011624a0[8] = bRam0000000001162488 ^ 0x4d;
    s_id_ui_backstage_original_post_011624a0[9] = bRam0000000001162489 ^ 0xf9;
    s_id_ui_backstage_original_post_011624a0[10] = bRam000000000116248a ^ 0x36;
    s_id_ui_backstage_original_post_011624a0[0xb] = bRam000000000116248b ^ 0xfa;
    s_id_ui_backstage_original_post_011624a0[0xc] = bRam000000000116248c ^ 0xfe;
    s_id_ui_backstage_original_post_011624a0[0xd] = bRam000000000116248d ^ 0x19;
    s_id_ui_backstage_original_post_011624a0[0xe] = bRam000000000116248e ^ 0x4c;
    s_id_ui_backstage_original_post_011624a0[0xf] = bRam000000000116248f ^ 0x33;
    s_id_ui_backstage_original_post_011624a0[0x10] = bRam0000000001162490 ^ 0x2e;
    s_id_ui_backstage_original_post_011624a0[0x11] = bRam0000000001162491 ^ 4;
    s_id_ui_backstage_original_post_011624a0[0x12] = bRam0000000001162492 ^ 0x3e;
    s_id_ui_backstage_original_post_011624a0[0x13] = bRam0000000001162493 ^ 0xe3;
    s_id_ui_backstage_original_post_011624a0[0x14] = bRam0000000001162494 ^ 0xd0;
    s_id_ui_backstage_original_post_011624a0[0x15] = bRam0000000001162495 ^ 0x36;
    s_id_ui_backstage_original_post_011624a0[0x16] = bRam0000000001162496 ^ 0x36;
    s_id_ui_backstage_original_post_011624a0[0x17] = bRam0000000001162497 ^ 0x6a;
    s_id_ui_backstage_original_post_011624a0[0x18] = bRam0000000001162498 ^ 0x89;
    s_id_ui_backstage_original_post_011624a0[0x19] = bRam0000000001162499 ^ 0xd7;
    s_id_ui_backstage_original_post_011624a0[0x1a] = bRam000000000116249a ^ 0x59;
    s_id_ui_backstage_original_post_011624a0[0x1b] = bRam000000000116249b ^ 0xd5;
    s_id_ui_backstage_original_post_011624a0[0x1c] = bRam000000000116249c ^ 0xf2;
    s_id_ui_backstage_original_post_011624a0[0x1d] = bRam000000000116249d ^ 0x1a;
    s_saveProfilePhoto_01162160[0] = DAT_01162140 ^ 0x23;
    s_saveProfilePhoto_01162160[1] = bRam0000000001162141 ^ 0xbd;
    s_saveProfilePhoto_01162160[2] = bRam0000000001162142 ^ 0xe7;
    s_saveProfilePhoto_01162160[3] = bRam0000000001162143 ^ 0xec;
    s_saveProfilePhoto_01162160[4] = bRam0000000001162144 ^ 0xc3;
    s_saveProfilePhoto_01162160[5] = bRam0000000001162145 ^ 0xdd;
    s_saveProfilePhoto_01162160[6] = bRam0000000001162146 ^ 0xa8;
    s_saveProfilePhoto_01162160[7] = bRam0000000001162147 ^ 0x9b;
    s_saveProfilePhoto_01162160[8] = bRam0000000001162148 ^ 5;
    s_saveProfilePhoto_01162160[9] = bRam0000000001162149 ^ 0xfd;
    s_saveProfilePhoto_01162160[10] = bRam000000000116214a ^ 0xa9;
    s_saveProfilePhoto_01162160[0xb] = bRam000000000116214b ^ 0xc3;
    s_saveProfilePhoto_01162160[0xc] = bRam000000000116214c ^ 0x24;
    s_saveProfilePhoto_01162160[0xd] = bRam000000000116214d ^ 0x52;
    s_saveProfilePhoto_01162160[0xe] = bRam000000000116214e ^ 0xc;
    s_saveProfilePhoto_01162160[0xf] = bRam000000000116214f ^ 0x77;
    s_saveProfilePhoto_01162160[0x10] = bRam0000000001162150 ^ 0x39;
    s_postManager_011621c0[0] = DAT_011621b4 ^ 0xb7;
    s_postManager_011621c0[1] = bRam00000000011621b5 ^ 0xce;
    s_postManager_011621c0[2] = bRam00000000011621b6 ^ 0x5d;
    s_postManager_011621c0[3] = bRam00000000011621b7 ^ 0x41;
    s_postManager_011621c0[4] = bRam00000000011621b8 ^ 0xf4;
    s_postManager_011621c0[5] = bRam00000000011621b9 ^ 0x14;
    s_postManager_011621c0[6] = bRam00000000011621ba ^ 0x1f;
    s_postManager_011621c0[7] = bRam00000000011621bb ^ 0x7b;
    s_postManager_011621c0[8] = bRam00000000011621bc ^ 0x21;
    s_postManager_011621c0[9] = bRam00000000011621bd ^ 0xc1;
    s_postManager_011621c0[10] = bRam00000000011621be ^ 0xcb;
    s_postManager_011621c0[0xb] = bRam00000000011621bf ^ 0x46;
    s_shortsNoSubButton_01162280[0] = DAT_01162260 ^ 0xec;
    s_shortsNoSubButton_01162280[1] = bRam0000000001162261 ^ 0x6b;
    s_shortsNoSubButton_01162280[2] = bRam0000000001162262 ^ 0x19;
    s_shortsNoSubButton_01162280[3] = bRam0000000001162263 ^ 0x56;
    s_shortsNoSubButton_01162280[4] = bRam0000000001162264 ^ 0xf5;
    s_shortsNoSubButton_01162280[5] = bRam0000000001162265 ^ 0x55;
    s_shortsNoSubButton_01162280[6] = bRam0000000001162266 ^ 0x87;
    s_shortsNoSubButton_01162280[7] = bRam0000000001162267 ^ 0x99;
    s_shortsNoSubButton_01162280[8] = bRam0000000001162268 ^ 0xc1;
    s_shortsNoSubButton_01162280[9] = bRam0000000001162269 ^ 0xb6;
    s_shortsNoSubButton_01162280[10] = bRam000000000116226a ^ 0x69;
    s_shortsNoSubButton_01162280[0xb] = bRam000000000116226b ^ 0xf9;
    s_shortsNoSubButton_01162280[0xc] = bRam000000000116226c ^ 0xa4;
    s_shortsNoSubButton_01162280[0xd] = bRam000000000116226d ^ 0x36;
    s_shortsNoSubButton_01162280[0xe] = bRam000000000116226e ^ 0xf2;
    s_shortsNoSubButton_01162280[0xf] = bRam000000000116226f ^ 0x1f;
    s_shortsNoSubButton_01162280[0x10] = bRam0000000001162270 ^ 0x33;
    s_shortsNoSubButton_01162280[0x11] = bRam0000000001162271 ^ 0xb;
    s_commentManager__01162123[0] = DAT_01162113 ^ 0x70;
    s_commentManager__01162123[1] = bRam0000000001162114 ^ 0xeb;
    s_commentManager__01162123[2] = bRam0000000001162115 ^ 0xd2;
    s_commentManager__01162123[3] = bRam0000000001162116 ^ 0xa0;
    s_commentManager__01162123[4] = bRam0000000001162117 ^ 9;
    s_commentManager__01162123[5] = bRam0000000001162118 ^ 0xfe;
    s_commentManager__01162123[6] = bRam0000000001162119 ^ 0x1c;
    s_commentManager__01162123[7] = bRam000000000116211a ^ 0xc9;
    s_commentManager__01162123[8] = bRam000000000116211b ^ 0x26;
    s_commentManager__01162123[9] = bRam000000000116211c ^ 0x13;
    s_commentManager__01162123[10] = bRam000000000116211d ^ 0xc6;
    s_commentManager__01162123[0xb] = bRam000000000116211e ^ 0x74;
    s_commentManager__01162123[0xc] = bRam000000000116211f ^ 0x1f;
    s_commentManager__01162123[0xd] = bRam0000000001162120 ^ 0xbe;
    s_commentManager__01162123[0xe] = bRam0000000001162121 ^ 0x21;
    s_commentManager__01162123[0xf] = bRam0000000001162122 ^ 0x66;
    s_id_ui_comment_cell_01162100[0] = DAT_011620e0 ^ 0x74;
    s_id_ui_comment_cell_01162100[1] = DAT_011620e1 ^ 0x10;
    s_id_ui_comment_cell_01162100[2] = DAT_011620e2 ^ 0xd9;
    s_id_ui_comment_cell_01162100[3] = DAT_011620e3 ^ 0xa2;
    s_id_ui_comment_cell_01162100[4] = DAT_011620e4 ^ 0x9c;
    s_id_ui_comment_cell_01162100[5] = DAT_011620e5 ^ 0x81;
    s_id_ui_comment_cell_01162100[6] = DAT_011620e6 ^ 0xd0;
    s_id_ui_comment_cell_01162100[7] = DAT_011620e7 ^ 0xf8;
    s_id_ui_comment_cell_01162100[8] = DAT_011620e8 ^ 0x89;
    s_id_ui_comment_cell_01162100[9] = DAT_011620e9 ^ 0x23;
    s_id_ui_comment_cell_01162100[10] = DAT_011620ea ^ 0xe6;
    s_id_ui_comment_cell_01162100[0xb] = DAT_011620eb ^ 0xd6;
    s_id_ui_comment_cell_01162100[0xc] = DAT_011620ec ^ 0x3c;
    s_id_ui_comment_cell_01162100[0xd] = DAT_011620ed ^ 0x90;
    s_id_ui_comment_cell_01162100[0xe] = DAT_011620ee ^ 0x73;
    s_id_ui_comment_cell_01162100[0xf] = DAT_011620ef ^ 0x13;
    s_id_ui_comment_cell_01162100[0x10] = DAT_011620f0 ^ 0xa5;
    s_id_ui_comment_cell_01162100[0x11] = DAT_011620f1 ^ 0x7d;
    s_id_ui_comment_cell_01162100[0x12] = DAT_011620f2 ^ 0x51;
  }
  DAT_01226ac8 = 1;
  puStack_268 = auStack_300;
  puStack_2b0 = auStack_360;
  puStack_2d0 = auStack_380;
  puStack_290 = auStack_3a0;
  puStack_298 = auStack_3c0;
  puStack_270 = auStack_3e0;
  puStack_278 = auStack_400;
  puStack_288 = auStack_440;
  puStack_2a0 = auStack_4c0;
  puStack_2e0 = auStack_4d0;
  puStack_2d8 = auStack_4e0;
  local_2a8 = param_3;
  local_280 = param_1;
  _objc_retain(param_3);
  (*DAT_012260b0)(param_1,param_2,param_3);
  uStack_94 = FUN_000d7710(@"oledTheme");
                    /* WARNING: Could not recover jumptable at 0x00069c5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_90[uStack_94] + (int)-(DAT_0117afb0 ^ 0xf403c73b)))();
  return;
}



// -[_ASDisplayView savePFP:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x6a920. FUN_0006a920 */

void FUN_0006a920(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined1 auStack_240 [216];
  undefined1 *puStack_168;
  undefined8 local_160;
  undefined **local_150;
  undefined **local_140;
  undefined **local_130;
  undefined **local_128;
  undefined **local_118;
  undefined **local_110;
  undefined **local_100;
  undefined **local_f8;
  undefined **ppuStack_f0;
  undefined **local_e0;
  undefined **local_d0;
  undefined **ppuStack_c8;
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
  local_78 = &PTR_LAB_0117b228;
  local_7c = (uint)(DAT_01226acc == 0);
  local_90 = &PTR_LAB_0117b248;
  local_a0 = &PTR_LAB_0117b260;
  local_88 = &PTR_LAB_01175340;
  local_b8 = &PTR_LAB_0117b280;
  ppuStack_b0 = &PTR_LAB_01175340;
  local_d0 = &PTR_LAB_0117b2a0;
  ppuStack_c8 = &PTR_LAB_01175340;
  local_e0 = &PTR_LAB_0117b2b8;
  local_f8 = &PTR_LAB_01175340;
  ppuStack_f0 = &PTR_LAB_01175340;
  local_100 = &PTR_LAB_0117b2e0;
  local_110 = &PTR_LAB_01175340;
  local_118 = &PTR_LAB_0117b300;
  local_128 = &PTR_LAB_01175340;
  local_130 = &PTR_LAB_0117b320;
  local_140 = &PTR_LAB_0117b338;
  local_150 = &PTR_LAB_01175340;
  DAT_01226acc = 1;
  puStack_168 = auStack_240;
  local_160 = param_1;
  lVar1 = _objc_msgSend(param_3,@selector(state));
  uStack_94 = (uint)(lVar1 == 1);
  if (lVar1 == 1) {
    _objc_msgSend(local_160,@selector(keepalive_node));
    _objc_retainAutoreleasedReturnValue();
    uStack_a4 = (uint)(DAT_01226860 == 0);
                    /* WARNING: Could not recover jumptable at 0x0006ae48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_a0[uStack_a4] + (int)-(uRam000000000117b270 ^ 0x71130439)))();
    return;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_70) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}



// -[_ASDisplayView postManager:], original IMP slot None
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
  lVar4 = _objc_msgSend(param_3,@selector(state));
  uStack_9c = (uint)(lVar4 == 1);
  if (lVar4 != 1) {
    CallSupervisor(0xd31f);
    return ZEXT816(0x1f);
  }
  puStack_208 = auStack_2a0;
  puStack_200 = auStack_360;
  _objc_msgSend(param_1,@selector(keepalive_node));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(copiedComment));
  uStack_1c0 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(copiedURL));
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(layer));
  uStack_1e8 = _objc_retainAutoreleasedReturnValue();
  uStack_1f8 = uVar5;
  _objc_msgSend(uVar5,@selector(closestViewController));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(view));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(backgroundColor));
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
  _objc_msgSend(uVar5,@selector(sheetControllerWithParentResponder:),0);
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
  puStack_190 = @selector(ytl_defaultBundle);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puStack_198 = @selector(localizedStringForKey:value:table:);
  _objc_msgSend(uVar7,@selector(localizedStringForKey:value:table:),
                @"TranslatePost",0,0);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(localization));
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
  puStack_1d0 = @selector(actionWithTitle:iconImage:style:handler:);
  _objc_msgSend(lVar4,@selector(actionWithTitle:iconImage:style:handler:),uVar8,uVar9,0,puVar3);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(addAction:);
  _objc_msgSend(uStack_188,@selector(addAction:),uVar6);
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
  _objc_msgSend(uVar6,puStack_198,@"CopyPostText",0,0);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puStack_1a0 = @selector(imageWithName:);
  _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(imageWithName:),
                @"message");
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
  _objc_msgSend(uVar6,puStack_198,@"SaveCurrentImage",0,0);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,puStack_1a0,@"image");
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



// -[_ASDisplayView commentManager:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x6cd2c. FUN_0006cd2c */

undefined1  [16] FUN_0006cd2c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 auVar10 [16];
  undefined *puStack_240;
  undefined8 uStack_238;
  code *pcStack_230;
  undefined *puStack_228;
  undefined8 uStack_220;
  undefined8 uStack_218;
  undefined *puStack_210;
  undefined8 uStack_208;
  code *pcStack_200;
  undefined *puStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined *puStack_1e0;
  undefined8 uStack_1d8;
  code *pcStack_1d0;
  undefined *puStack_1c8;
  undefined8 uStack_1c0;
  undefined *puStack_1b0;
  undefined8 uStack_1a8;
  code *pcStack_1a0;
  undefined *puStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined **ppuStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined *puStack_150;
  undefined *puStack_148;
  undefined *puStack_140;
  undefined *puStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined **local_120;
  undefined **local_118;
  uint uStack_10c;
  undefined **local_108;
  undefined **ppuStack_100;
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
  
  local_80 = &PTR_LAB_0117b4b8;
  local_84 = (uint)(DAT_01226ad4 == 0);
  local_98 = &PTR_LAB_0117b4d8;
  local_a8 = &PTR_LAB_0117b4f0;
  local_c0 = &PTR_LAB_0117b510;
  local_90 = &PTR_LAB_01175340;
  local_b8 = &PTR_LAB_01175340;
  local_d8 = &PTR_LAB_0117b530;
  ppuStack_d0 = &PTR_LAB_01175340;
  local_f0 = &PTR_LAB_0117b550;
  ppuStack_e8 = &PTR_LAB_01175340;
  local_108 = &PTR_LAB_0117b570;
  ppuStack_100 = &PTR_LAB_01175340;
  local_118 = &PTR_LAB_01175340;
  local_120 = &PTR_LAB_01175340;
  DAT_01226ad4 = 1;
  lVar2 = _objc_msgSend(param_3,@selector(state));
  uStack_9c = (uint)(lVar2 == 1);
  if (lVar2 == 1) {
    _objc_msgSend(param_1,@selector(keepalive_node));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(copiedComment));
    uStack_128 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,@selector(layer));
    uStack_158 = _objc_retainAutoreleasedReturnValue();
    uStack_170 = uVar3;
    _objc_msgSend(uVar3,@selector(closestViewController));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(view));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(backgroundColor));
    uStack_160 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_release(uVar3);
    uStack_ac = (uint)(lRam0000000001226868 == 0);
    if (lRam0000000001226868 == 0) {
      lRam0000000001226868 =
           _objc_getClass(local_a8[uStack_ac] + (int)-(uRam000000000117b500 ^ 0x2d91e111),
                          s_YTDefaultSheetController_011630d0);
    }
    uVar3 = _objc_retainAutorelease();
    _objc_msgSend(uVar3,@selector(sheetControllerWithParentResponder:),0);
    uStack_130 = _objc_retainAutoreleasedReturnValue();
    uStack_c4 = (uint)(lRam0000000001226870 == 0);
    if (lRam0000000001226870 == 0) {
      lRam0000000001226870 =
           _objc_getClass(local_c0[uStack_c4] + (int)-(uRam000000000117b520 ^ 0x3daede5),
                          s_YTActionSheetAction_01163070);
    }
    lVar2 = lRam0000000001226870;
    _objc_retainAutorelease(lRam0000000001226870);
    puStack_138 = @selector(ytl_defaultBundle);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puStack_140 = @selector(localizedStringForKey:value:table:);
    _objc_msgSend(uVar4,@selector(localizedStringForKey:value:table:),
                  @"TranslateComment",0,0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(localization));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar3 = DAT_00c4c228;
    puStack_1b0 = PTR___NSConcreteStackBlock_01060660;
    uStack_1a8 = DAT_00c4c228;
    pcStack_1a0 = FUN_000c2724;
    puStack_198 = &DAT_01061cb0;
    uStack_190 = _objc_retain(uStack_128);
    puStack_148 = @selector(actionWithTitle:iconImage:style:handler:);
    uStack_188 = param_1;
    _objc_msgSend(lVar2,@selector(actionWithTitle:iconImage:style:handler:),uVar5,uVar6,0,&puStack_1b0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puStack_150 = @selector(addAction:);
    _objc_msgSend(uStack_130,@selector(addAction:),uVar7);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar4);
    uStack_dc = (uint)(lRam0000000001226870 == 0);
    uStack_168 = param_1;
    if (lRam0000000001226870 == 0) {
      lRam0000000001226870 =
           _objc_getClass(local_d8[uStack_dc] + (int)-(uRam000000000117b540 ^ 0xf5208888),
                          s_YTActionSheetAction_01163070);
    }
    lVar2 = lRam0000000001226870;
    _objc_retainAutorelease(lRam0000000001226870);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_138);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puStack_140,@"CopyCommentText",0,0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(imageWithName:);
    _objc_msgSend(PTR_YTPMedia_0114eae0,@selector(imageWithName:),
                  @"message");
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puStack_1e0 = PTR___NSConcreteStackBlock_01060660;
    uStack_1d8 = uVar3;
    pcStack_1d0 = FUN_000c2c3c;
    puStack_1c8 = &DAT_010618c0;
    uStack_1c0 = _objc_retain(uStack_128);
    _objc_msgSend(lVar2,puStack_148,uVar5,uVar6,0,&puStack_1e0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uStack_130,puStack_150,uVar7);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar4);
    uStack_f4 = (uint)(lRam0000000001226870 == 0);
    if (lRam0000000001226870 == 0) {
      lRam0000000001226870 =
           _objc_getClass(local_f0[uStack_f4] + (int)-(uRam000000000117b560 ^ 0xde4b5483),
                          s_YTActionSheetAction_01163070);
    }
    lVar2 = lRam0000000001226870;
    ppuStack_178 = &puStack_1e0;
    _objc_retainAutorelease(lRam0000000001226870);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_138);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puStack_140,@"SaveCommentAsImage",0,0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_YTPMedia_0114eae0,puVar1,@"image");
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puStack_210 = PTR___NSConcreteStackBlock_01060660;
    uStack_208 = uVar3;
    pcStack_200 = FUN_000c2e9c;
    puStack_1f8 = &DAT_01061c60;
    uStack_1f0 = _objc_retain(uStack_158);
    uStack_1e8 = _objc_retain(uStack_160);
    _objc_msgSend(lVar2,puStack_148,uVar6,uVar7,0,&puStack_210);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    uVar4 = uStack_130;
    _objc_msgSend(uStack_130,puStack_150,uVar8);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    uStack_10c = (uint)(lRam0000000001226870 == 0);
    if (lRam0000000001226870 == 0) {
      lRam0000000001226870 =
           _objc_getClass(local_108[uStack_10c] + (int)-(uRam000000000117b580 ^ 0x6ddd4207),
                          s_YTActionSheetAction_01163070);
    }
    lVar2 = lRam0000000001226870;
    _objc_retainAutorelease(lRam0000000001226870);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_138);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puStack_140,@"CopyCommentAsImage",0,0);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_YTPMedia_0114eae0,puVar1,@"image_library");
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uVar6 = uStack_158;
    uVar5 = uStack_160;
    puStack_240 = PTR___NSConcreteStackBlock_01060660;
    uStack_238 = uVar3;
    pcStack_230 = FUN_000c34e0;
    puStack_228 = &DAT_01061c60;
    uStack_220 = uStack_158;
    uStack_218 = uStack_160;
    _objc_retain(uStack_160);
    _objc_retain(uVar6);
    _objc_msgSend(lVar2,puStack_148,uVar8,uVar9,0,&puStack_240);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puStack_150,uVar3);
    _objc_release(uVar3);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_msgSend(uVar4,@selector(setSourceView:),uStack_168);
    _objc_msgSend(PTR_ToastView_0114ec98,@selector(toastWindow));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(rootViewController));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(presentFromViewController:animated:completion:),uVar7,1,0);
    _objc_release(uVar7);
    _objc_release(uVar3);
    _objc_release(uStack_218);
    _objc_release(uStack_220);
    _objc_release(uStack_1e8);
    _objc_release(uStack_1f0);
    _objc_release(ppuStack_178[4]);
    _objc_release(uStack_190);
    _objc_release(uVar5);
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_release(uStack_128);
    _objc_release(uStack_170);
  }
  CallSupervisor(0xfa2c);
  auVar10._8_8_ = 0x1f;
  auVar10._0_8_ = 0x1a;
  return auVar10;
}


