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
  lVar1 = _objc_msgSend(param_3,PTR_s_state_0114c560);
  uStack_94 = (uint)(lVar1 == 1);
  if (lVar1 == 1) {
    _objc_msgSend(local_160,PTR_s_keepalive_node_0114c568);
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


