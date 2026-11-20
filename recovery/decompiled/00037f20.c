/* Decompiled from supplied 5.2.2 arm package. VA 0x37f20. FUN_00037f20 */

void FUN_00037f20(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  bool bVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  undefined1 auStack_320 [16];
  undefined1 auStack_310 [128];
  undefined8 uStack_290;
  long lStack_288;
  long *plStack_280;
  undefined8 uStack_278;
  undefined8 uStack_270;
  undefined8 uStack_268;
  undefined8 uStack_260;
  undefined8 uStack_258;
  undefined **ppuStack_250;
  undefined **ppuStack_248;
  undefined **ppuStack_240;
  undefined **ppuStack_238;
  undefined **ppuStack_230;
  undefined **ppuStack_228;
  undefined **ppuStack_220;
  undefined **ppuStack_218;
  undefined **ppuStack_210;
  undefined **ppuStack_208;
  undefined1 *puStack_1f8;
  undefined1 *puStack_1f0;
  undefined *puStack_1e8;
  undefined *puStack_1e0;
  ulong uStack_1d8;
  int iStack_1d0;
  int iStack_1cc;
  undefined8 uStack_1c8;
  undefined **local_1c0;
  undefined **ppuStack_1b8;
  undefined **local_1b0;
  undefined **ppuStack_1a8;
  undefined **local_198;
  undefined **local_188;
  undefined **local_178;
  undefined **local_168;
  undefined **local_158;
  undefined **ppuStack_150;
  undefined **local_140;
  undefined **ppuStack_138;
  uint uStack_12c;
  undefined **local_128;
  uint uStack_11c;
  undefined **local_118;
  uint uStack_10c;
  undefined **local_108;
  uint uStack_fc;
  undefined **local_f8;
  uint uStack_ec;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0115aef0;
  local_7c = (uint)(DAT_01225e90 == 0);
  local_90 = &PTR__objc_msgSend_0115af10;
  ppuStack_88 = &PTR_LAB_0115acd0;
  local_a8 = &PTR_LAB_0115acd0;
  ppuStack_a0 = &PTR_LAB_0115acd0;
  local_b0 = &PTR_LAB_0115af38;
  local_c8 = &PTR_LAB_0115acd0;
  ppuStack_c0 = &PTR_LAB_0115acd0;
  local_d0 = &PTR_LAB_0115af60;
  local_e8 = &PTR__objc_msgSend_0115af80;
  ppuStack_e0 = &PTR_LAB_0115acd0;
  local_f8 = &PTR_LAB_0115af98;
  local_108 = &PTR_LAB_0115afb0;
  local_118 = &PTR__objc_msgSend_0115afc8;
  local_128 = &PTR_LAB_0115afe0;
  local_140 = &PTR_LAB_0115b000;
  ppuStack_138 = &PTR_LAB_0115acd0;
  local_158 = &PTR_LAB_0115b020;
  ppuStack_150 = &PTR_LAB_0115acd0;
  local_168 = &PTR_LAB_0115b038;
  local_178 = &PTR_LAB_0115b050;
  local_188 = &PTR_LAB_0115b068;
  local_198 = &PTR_LAB_0115b080;
  local_1b0 = &PTR_LAB_0115acd0;
  ppuStack_1a8 = &PTR_LAB_0115acd0;
  local_1c0 = &PTR_LAB_0115acd0;
  ppuStack_1b8 = &PTR_LAB_0115acd0;
  DAT_01225e90 = 1;
  ppuStack_250 = &PTR____CFConstantStringClassReference_0115abf0;
  ppuStack_248 = &PTR____CFConstantStringClassReference_0115ac30;
  ppuStack_240 = &PTR____CFConstantStringClassReference_0115acb0;
  ppuStack_238 = &PTR____CFConstantStringClassReference_0115abb0;
  ppuStack_230 = &PTR____CFConstantStringClassReference_0115ac70;
  ppuStack_228 = &PTR____CFConstantStringClassReference_0115ab70;
  ppuStack_220 = &PTR____CFConstantStringClassReference_0115aaf0;
  ppuStack_218 = &PTR____CFConstantStringClassReference_0115a9f0;
  ppuStack_210 = &PTR____CFConstantStringClassReference_0115aa70;
  ppuStack_208 = &PTR____CFConstantStringClassReference_0115aab0;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                &ppuStack_250,10);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  iStack_1cc = __dyld_image_count();
  puVar3 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  puVar2 = PTR_s_stringWithUTF8String__0114b220;
  uStack_94 = (uint)(iStack_1cc == 0);
  if (iStack_1cc == 0) {
    _objc_release(local_90[uStack_94] + (int)-(DAT_0115af20 ^ 0x562a8268),uVar7);
    CallSupervisor(0x5477);
    if (*(long *)PTR____stack_chk_guard_01060708 == local_70) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  puStack_1e8 = PTR_s_stringWithUTF8String__0114b220;
  puStack_1e0 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  uStack_1d8 = 1;
  iStack_1d0 = 0;
  puStack_1f8 = auStack_320;
  uVar8 = __dyld_get_image_name();
  _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,puVar2,uVar8);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  lStack_288 = 0;
  uStack_290 = 0;
  uStack_278 = 0;
  plStack_280 = (long *)0x0;
  uStack_268 = 0;
  uStack_270 = 0;
  uStack_258 = 0;
  uStack_260 = 0;
  uVar9 = _objc_retain(uVar7);
  lVar10 = _objc_msgSend(uVar9,puVar3,&uStack_290,auStack_310,0x10);
  iVar4 = iStack_1cc;
  puVar3 = PTR_s_lastPathComponent_0114b500;
  puVar2 = PTR_s_isEqualToString__0114ae48;
  uStack_b4 = (uint)(lVar10 == 0);
  if (lVar10 != 0) {
    lVar11 = *plStack_280;
    lVar12 = 0;
    bVar5 = *plStack_280 == lVar11;
    uStack_d4 = (uint)bVar5;
    puVar1 = local_d0[uStack_d4] + (int)-(uRam000000000115af70 ^ 0xf72f7ad);
    uStack_b4 = 0;
    puStack_1f0 = auStack_310;
    uStack_1c8 = uVar7;
    while( true ) {
      if (!bVar5) {
        _objc_enumerationMutation(puVar1,uStack_1c8);
      }
      uVar9 = *(undefined8 *)(lStack_288 + lVar12 * 8);
      _objc_msgSend(uVar8,puVar3);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      uVar6 = FUN_0003bfc0(uVar7,puVar2,uVar9);
      _objc_release(uVar7);
      uVar7 = uStack_1c8;
      uStack_ec = uVar6;
      if (uVar6 != 0) break;
      bVar5 = lVar10 + -1 == lVar12;
      uStack_fc = (uint)bVar5;
      if (bVar5) {
        lVar10 = _objc_msgSend(local_f8[uStack_fc] + (int)-(uRam000000000115afa8 ^ 0xaf582e6e),
                               uStack_1c8,puStack_1e0,&uStack_290,puStack_1f0,0x10);
        uStack_10c = (uint)(lVar10 == 0);
                    /* WARNING: Could not recover jumptable at 0x00038fc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(local_108[uStack_10c] + (int)-(uRam000000000115afc0 ^ 0x4ec8e3c3)))();
        return;
      }
      lVar12 = lVar12 + 1;
      bVar5 = *plStack_280 == lVar11;
      uStack_d4 = (uint)bVar5;
      puVar1 = local_d0[uStack_d4] + (int)-(uRam000000000115af70 ^ 0xf72f7ad);
      uStack_ec = 0;
      uStack_fc = 0;
    }
    _objc_release(local_e8[uVar6] + (int)-(uRam000000000115af90 ^ 0x3641965e),uStack_1c8);
    _objc_release(uVar8);
    _objc_release(uVar7);
    uStack_12c = (uint)uStack_1d8 & 1;
                    /* WARNING: Could not recover jumptable at 0x0003915c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_128[uStack_1d8 & 1] + (int)-(uRam000000000115aff0 ^ 0xff5095ed)))();
    return;
  }
  _objc_release(local_b0[uStack_b4] + (int)-(uRam000000000115af48 ^ 0xe681ea24),uVar7);
  _objc_release(uVar8);
  uStack_11c = (uint)(iStack_1d0 + 1 == iVar4);
                    /* WARNING: Could not recover jumptable at 0x000390f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_118[uStack_11c] + (int)-(uRam000000000115afd8 ^ 0x1dddd46f)))();
  return;
}


