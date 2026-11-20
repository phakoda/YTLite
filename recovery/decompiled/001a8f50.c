/* Decompiled from supplied 5.2.2 arm package. VA 0x1a8f50. FUN_001a8f50 */

void FUN_001a8f50(void)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  undefined1 auStack_200 [128];
  undefined8 uStack_180;
  long lStack_178;
  long *plStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined *puStack_140;
  undefined1 *puStack_138;
  undefined *puStack_130;
  undefined8 uStack_128;
  undefined *puStack_120;
  undefined *puStack_118;
  long lStack_110;
  undefined *puStack_108;
  undefined *puStack_100;
  uint uStack_f4;
  undefined **local_f0;
  uint uStack_e4;
  undefined **local_e0;
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
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_011aebf8;
  local_7c = (uint)(DAT_01227980 == 0);
  local_90 = &PTR_LAB_011aec18;
  ppuStack_88 = &PTR_LAB_011ae4f0;
  local_a8 = &PTR_LAB_011ae4f0;
  ppuStack_a0 = &PTR_LAB_011ae4f0;
  local_b0 = &PTR_LAB_011aec40;
  local_c8 = &PTR_LAB_011aec60;
  ppuStack_c0 = &PTR_LAB_011ae4f0;
  local_d8 = &PTR_LAB_011ae4f0;
  local_e0 = &PTR_LAB_011aec80;
  local_f0 = &PTR_LAB_011aec98;
  DAT_01227980 = 1;
  puStack_130 = PTR_s_defaultManager_0114b240;
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _NSTemporaryDirectory();
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_contentsOfDirectoryAtPath_error__0114d930,uVar7,0);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar7);
  _objc_release(uVar6);
  uStack_158 = 0;
  uStack_160 = 0;
  uStack_148 = 0;
  uStack_150 = 0;
  lStack_178 = 0;
  uStack_180 = 0;
  uStack_168 = 0;
  plStack_170 = (long *)0x0;
  uVar6 = _objc_retain(uVar8);
  puStack_140 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  puStack_138 = auStack_200;
  uStack_128 = uVar8;
  lVar9 = _objc_msgSend(uVar6,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_180,
                        auStack_200,0x10);
  uStack_94 = (uint)(lVar9 == 0);
  if (lVar9 == 0) {
LAB_001a9494:
    uVar6 = uStack_128;
    _objc_release(uStack_128);
    _objc_release(uVar6);
    CallSupervisor(0x5f74);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail(0x1a,0x1f,0,0);
    }
    return;
  }
  lStack_110 = *plStack_170;
LAB_001a91b8:
  puVar3 = PTR_s_stringWithFormat__0114b378;
  puVar2 = PTR_s_hasPrefix__0114aea0;
  lVar11 = 0;
  puStack_108 = PTR_s_bundleIdentifier_0114b110;
  puStack_100 = PTR_s_mainBundle_0114adf8;
  puStack_118 = PTR_s_stringByAppendingPathComponent__0114b6e8;
  puStack_120 = PTR_s_removeItemAtPath_error__0114c378;
  uStack_b4 = (uint)(*plStack_170 == lStack_110);
  if (*plStack_170 == lStack_110) goto LAB_001a9244;
  do {
    _objc_enumerationMutation(uStack_128);
LAB_001a9244:
    do {
      puVar4 = PTR__OBJC_CLASS___NSString_0114eb38;
      uVar10 = *(undefined8 *)(lStack_178 + lVar11 * 8);
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_100);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,puStack_108);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      thunk_FUN_001aa5d8(puVar4,puVar3,&PTR____CFConstantStringClassReference_011ae4d0,uVar7);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      uVar5 = FUN_001aa618(uVar10,puVar2,uVar8);
      _objc_release(uVar8);
      _objc_release(uVar7);
      _objc_release(uVar6);
      uStack_cc = uVar5;
      if (uVar5 != 0) {
        _NSTemporaryDirectory(local_c8[uVar5] + (int)-(uRam00000000011aec70 ^ 0x80b8126c));
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,puStack_118,uVar10);
        uVar7 = _objc_retainAutoreleasedReturnValue();
        _objc_release(uVar6);
        _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,puStack_130);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        FUN_001aa760(uVar6,puStack_120,uVar7,0);
        _objc_release(uVar6);
        _objc_release(uVar7);
      }
      bVar1 = lVar9 + -1 == lVar11;
      uStack_e4 = (uint)bVar1;
      if (bVar1) {
        lVar9 = _objc_msgSend(uStack_128,puStack_140,&uStack_180,puStack_138,0x10);
        uStack_f4 = (uint)(lVar9 == 0);
        if (lVar9 != 0) goto LAB_001a91b8;
        uStack_f4 = 1;
        goto LAB_001a9494;
      }
      lVar11 = lVar11 + 1;
      uStack_b4 = (uint)(*plStack_170 == lStack_110);
    } while (*plStack_170 == lStack_110);
  } while( true );
}


