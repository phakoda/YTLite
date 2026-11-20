/* Decompiled from supplied 5.2.2 arm package. VA 0x19ee38. drawSegments:layer:playerVC: */

/* Function Stack Size: 0x28 bytes */

void SBPlayerDecorator::drawSegments_layer_playerVC_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  undefined1 auStack_400 [368];
  ID local_290;
  undefined1 *puStack_268;
  undefined **local_250;
  undefined **ppuStack_248;
  undefined **local_238;
  undefined **local_228;
  undefined **local_220;
  undefined **ppuStack_218;
  undefined **local_210;
  undefined **ppuStack_208;
  undefined **local_1f8;
  undefined **local_1e8;
  undefined **local_1d8;
  undefined **local_1c8;
  undefined **ppuStack_1c0;
  undefined **local_1b0;
  undefined **local_1a8;
  undefined **ppuStack_1a0;
  undefined **local_190;
  undefined **local_180;
  undefined **local_170;
  undefined **local_160;
  undefined **local_150;
  undefined **ppuStack_148;
  undefined **local_138;
  undefined **local_130;
  undefined **local_128;
  undefined **local_120;
  undefined **local_110;
  undefined **local_100;
  undefined **local_f0;
  undefined **local_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  undefined **local_a8;
  uint local_9c;
  undefined **local_98;
  undefined8 local_90;
  
  local_90 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_98 = &PTR_LAB_011aca98;
  local_9c = (uint)(DAT_012278e8 == 0);
  local_b0 = &PTR_LAB_011acab8;
  local_d0 = &PTR_LAB_011acae0;
  local_e0 = &PTR_LAB_011acaf8;
  local_f0 = &PTR_LAB_011acb10;
  local_100 = &PTR_LAB_011acb28;
  local_a8 = &PTR_LAB_011ac130;
  local_c8 = &PTR_LAB_011ac130;
  ppuStack_c0 = &PTR_LAB_011ac130;
  local_110 = &PTR_LAB_011acb40;
  local_120 = &PTR_LAB_011ac130;
  local_128 = &PTR_LAB_011ac130;
  local_130 = &PTR_LAB_011ac130;
  local_138 = &PTR_LAB_011acb70;
  local_150 = &PTR_LAB_011acb90;
  ppuStack_148 = &PTR_LAB_011ac130;
  local_160 = &PTR_LAB_011acba8;
  local_170 = &PTR_LAB_011acbc0;
  local_180 = &PTR_LAB_011acbd8;
  local_190 = &PTR_LAB_011acbf0;
  local_1a8 = &PTR_LAB_011ac130;
  ppuStack_1a0 = &PTR_LAB_011ac130;
  local_1b0 = &PTR_LAB_011acc18;
  local_1c8 = &PTR_LAB_011acc38;
  ppuStack_1c0 = &PTR_LAB_011ac130;
  local_1d8 = &PTR_LAB_011acc50;
  local_1e8 = &PTR_LAB_011acc68;
  local_1f8 = &PTR_LAB_011acc80;
  local_210 = &PTR_LAB_011ac130;
  ppuStack_208 = &PTR_LAB_011ac130;
  local_220 = &PTR_LAB_011ac130;
  ppuStack_218 = &PTR_LAB_011ac130;
  local_228 = &PTR_LAB_011accb8;
  local_238 = &PTR_LAB_011accd0;
  local_250 = &PTR_LAB_011ac130;
  ppuStack_248 = &PTR_LAB_011ac130;
  DAT_012278e8 = 1;
  puStack_268 = auStack_400;
  local_290 = param_5;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(local_290);
  uStack_b4 = (uint)(lRam00000000012278c8 == -1);
  if (lRam00000000012278c8 != -1) {
    _dispatch_once(local_b0[uStack_b4] + (int)-(uRam00000000011acac8 ^ 0xec94ae09),0x12278c8,
                   &PTR___NSConcreteGlobalBlock_010628a0);
    uStack_d4 = (uint)(param_4 == 0);
                    /* WARNING: Could not recover jumptable at 0x0019f2b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_d0[param_4 == 0] + (int)-(uRam00000000011acaf0 ^ 0x243ae6a4)))();
    return;
  }
  uStack_d4 = (uint)(param_4 == 0);
                    /* WARNING: Could not recover jumptable at 0x0019f2e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_d0[param_4 == 0] + (int)-(uRam00000000011acaf0 ^ 0x243ae6a4)))();
  return;
}


