/* Decompiled from supplied 5.2.2 arm package. VA 0x10b9a4. captionsForDownloading: */

/* Function Stack Size: 0x18 bytes */

ID DownloadMenuHelper::captionsForDownloading_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  undefined1 auStack_240 [128];
  undefined8 uStack_1c0;
  undefined8 *puStack_1b8;
  long *plStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined *puStack_180;
  undefined1 *puStack_178;
  undefined8 uStack_170;
  undefined *puStack_168;
  ID local_160;
  undefined *puStack_158;
  long lStack_150;
  undefined *puStack_148;
  undefined **local_140;
  uint uStack_134;
  undefined **local_130;
  undefined **local_120;
  undefined **local_110;
  undefined **ppuStack_108;
  undefined **local_f8;
  undefined **ppuStack_f0;
  undefined **local_e0;
  undefined **ppuStack_d8;
  uint uStack_cc;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  undefined8 local_70;
  
  local_70 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0118b120;
  local_7c = (uint)(DAT_01227214 == 0);
  local_90 = &PTR_LAB_0118b140;
  local_88 = &PTR_LAB_011882f0;
  local_a8 = &PTR_LAB_011882f0;
  ppuStack_a0 = &PTR_LAB_011882f0;
  local_b0 = &PTR_LAB_0118b168;
  local_c8 = &PTR_LAB_0118b188;
  ppuStack_c0 = &PTR_LAB_011882f0;
  local_e0 = &PTR_LAB_0118b1a8;
  ppuStack_d8 = &PTR_LAB_011882f0;
  local_f8 = &PTR_LAB_0118b1c8;
  ppuStack_f0 = &PTR_LAB_011882f0;
  local_110 = &PTR_LAB_0118b1e8;
  ppuStack_108 = &PTR_LAB_011882f0;
  local_120 = &PTR_LAB_0118b200;
  local_130 = &PTR_LAB_0118b218;
  local_140 = &PTR_LAB_011882f0;
  DAT_01227214 = 1;
  local_160 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,PTR_s_array_0114c388);
  uStack_170 = _objc_retainAutoreleasedReturnValue();
  puStack_1b8 = (undefined8 *)0x0;
  uStack_1c0 = 0;
  uStack_1a8 = 0;
  plStack_1b0 = (long *)0x0;
  uStack_198 = 0;
  uStack_1a0 = 0;
  uStack_188 = 0;
  uStack_190 = 0;
  uVar2 = _objc_retain(param_3);
  puStack_180 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  puStack_178 = auStack_240;
  lStack_150 = _objc_msgSend(uVar2,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_1c0,
                             auStack_240,0x10);
  puVar1 = PTR_s_VSSID_0114d078;
  uStack_94 = (uint)(lStack_150 == 0);
  if (lStack_150 == 0) {
    _objc_release(local_160);
    uStack_134 = FUN_00114a10(&PTR____CFConstantStringClassReference_01187d50);
                    /* WARNING: Could not recover jumptable at 0x0010c0c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar3 = (*(code *)(local_130[uStack_134] + (int)-(uRam000000000118b228 ^ 0x27aea731)))();
    return IVar3;
  }
  puStack_148 = PTR_s_hasPrefix__0114aea0;
  puStack_168 = PTR_s_addObject__0114b3a0;
  lStack_150 = lStack_150 + -1;
  uStack_b4 = (uint)(*plStack_1b0 == *plStack_1b0);
  puStack_158 = PTR_s_VSSID_0114d078;
  if (*plStack_1b0 != *plStack_1b0) {
    _objc_enumerationMutation(local_160);
  }
  _objc_msgSend(*puStack_1b8,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uStack_cc = FUN_00114ac0(uVar2,puStack_148,&PTR____CFConstantStringClassReference_01187e10);
                    /* WARNING: Could not recover jumptable at 0x0010be40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar3 = (*(code *)(local_c8[uStack_cc] + (int)-(uRam000000000118b198 ^ 0x9679f7ad)))();
  return IVar3;
}


