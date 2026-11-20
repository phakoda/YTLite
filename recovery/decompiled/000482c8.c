/* Decompiled from supplied 5.2.2 arm package. VA 0x482c8. _getAdString */

void _getAdString(undefined8 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined1 auStack_290 [128];
  undefined8 uStack_210;
  undefined8 *puStack_208;
  long *plStack_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined **ppuStack_1d0;
  undefined **ppuStack_1c8;
  undefined **ppuStack_1c0;
  undefined **ppuStack_1b8;
  undefined **ppuStack_1b0;
  undefined **ppuStack_1a8;
  undefined **ppuStack_1a0;
  undefined **ppuStack_198;
  undefined **ppuStack_190;
  undefined **ppuStack_188;
  undefined **ppuStack_180;
  undefined **ppuStack_178;
  undefined **ppuStack_170;
  undefined **ppuStack_168;
  undefined **ppuStack_160;
  undefined **ppuStack_158;
  undefined **ppuStack_150;
  undefined **ppuStack_148;
  undefined **ppuStack_140;
  undefined **ppuStack_138;
  undefined **ppuStack_130;
  undefined **ppuStack_128;
  undefined **ppuStack_120;
  undefined *puStack_110;
  undefined1 *puStack_108;
  undefined8 local_100;
  undefined **local_f8;
  undefined **local_e8;
  undefined **local_d8;
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
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_01179ea0;
  local_7c = (uint)(DAT_01226940 == 0);
  local_90 = &PTR_LAB_01179ec0;
  local_88 = &PTR_LAB_01175340;
  local_a8 = &PTR_LAB_01175340;
  ppuStack_a0 = &PTR_LAB_01175340;
  local_b0 = &PTR_LAB_01179ee8;
  local_c8 = &PTR_LAB_01179f08;
  ppuStack_c0 = &PTR_LAB_01175340;
  local_d8 = &PTR_LAB_01179f20;
  local_e8 = &PTR_LAB_01179f38;
  local_f8 = &PTR_LAB_01175340;
  DAT_01226940 = 1;
  local_100 = param_1;
  _objc_retain(param_1);
  ppuStack_1d0 = &PTR____CFConstantStringClassReference_0115d830;
  ppuStack_1c8 = &PTR____CFConstantStringClassReference_0115d7f0;
  ppuStack_1c0 = &PTR____CFConstantStringClassReference_0115d570;
  ppuStack_1b8 = &PTR____CFConstantStringClassReference_0115d3f0;
  ppuStack_1b0 = &PTR____CFConstantStringClassReference_0115d6f0;
  ppuStack_1a8 = &PTR____CFConstantStringClassReference_0115d770;
  ppuStack_1a0 = &PTR____CFConstantStringClassReference_0115d670;
  ppuStack_198 = &PTR____CFConstantStringClassReference_0115d5b0;
  ppuStack_190 = &PTR____CFConstantStringClassReference_0115d4f0;
  ppuStack_188 = &PTR____CFConstantStringClassReference_0115d4b0;
  ppuStack_180 = &PTR____CFConstantStringClassReference_0115d430;
  ppuStack_178 = &PTR____CFConstantStringClassReference_0115d3b0;
  ppuStack_170 = &PTR____CFConstantStringClassReference_0115d530;
  ppuStack_168 = &PTR____CFConstantStringClassReference_0115d470;
  ppuStack_160 = &PTR____CFConstantStringClassReference_0115d370;
  ppuStack_158 = &PTR____CFConstantStringClassReference_0115d730;
  ppuStack_150 = &PTR____CFConstantStringClassReference_0115d2f0;
  ppuStack_148 = &PTR____CFConstantStringClassReference_0115d630;
  ppuStack_140 = &PTR____CFConstantStringClassReference_0115d6b0;
  ppuStack_138 = &PTR____CFConstantStringClassReference_0115d330;
  ppuStack_130 = &PTR____CFConstantStringClassReference_0115d2b0;
  ppuStack_128 = &PTR____CFConstantStringClassReference_0115d7b0;
  ppuStack_120 = &PTR____CFConstantStringClassReference_0115d5f0;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                &ppuStack_1d0,0x17);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puStack_208 = (undefined8 *)0x0;
  uStack_210 = 0;
  uStack_1f8 = 0;
  plStack_200 = (long *)0x0;
  uStack_1e8 = 0;
  uStack_1f0 = 0;
  uStack_1d8 = 0;
  uStack_1e0 = 0;
  uVar4 = _objc_retain();
  puVar2 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  lVar5 = _objc_msgSend(uVar4,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_210,
                        auStack_290,0x10);
  puVar1 = PTR_s_containsString__0114af08;
  uStack_94 = (uint)(lVar5 == 0);
  if (lVar5 != 0) {
    puStack_110 = puVar2;
    uStack_b4 = (uint)(*plStack_200 == *plStack_200);
    puStack_108 = auStack_290;
    if (*plStack_200 != *plStack_200) {
      _objc_enumerationMutation
                (local_b0[uStack_b4] + (int)-(uRam0000000001179ef8 ^ 0x5bb97f08),uVar3);
    }
    uStack_cc = FUN_000cf9c4(local_100,puVar1,*puStack_208);
                    /* WARNING: Could not recover jumptable at 0x0004a270. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_c8[uStack_cc] + (int)-(uRam0000000001179f18 ^ 0x44da0f98)))();
    return;
  }
  _objc_release(local_90[uStack_94] + (int)-(DAT_01179ed0 ^ 0x7ea468bd),uVar3);
  _objc_release(uVar3);
  _objc_release(local_100);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(0);
  return;
}


