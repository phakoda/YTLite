/* Decompiled from supplied 5.2.2 arm package. VA 0x19a7c8. FUN_0019a7c8 */

void FUN_0019a7c8(long param_1,long param_2,undefined8 param_3,long param_4)

{
  undefined *puVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 auStack_240 [128];
  undefined8 uStack_1c0;
  undefined8 *puStack_1b8;
  long *plStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  long lStack_178;
  undefined8 uStack_170;
  long lStack_168;
  long lStack_160;
  undefined *puStack_158;
  undefined1 *puStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined **local_138;
  undefined **local_130;
  undefined **local_120;
  undefined **local_110;
  undefined **ppuStack_108;
  uint uStack_fc;
  undefined **local_f8;
  undefined **ppuStack_f0;
  uint uStack_e4;
  undefined **local_e0;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **ppuStack_b8;
  uint uStack_ac;
  undefined **local_a8;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_011ab680;
  local_7c = (uint)(DAT_012278a8 == 0);
  local_90 = &PTR_LAB_011ab6a0;
  local_a8 = &PTR_LAB_011ab6c0;
  local_88 = &PTR_LAB_011ab4e0;
  local_a0 = &PTR_LAB_011ab4e0;
  local_c0 = &PTR_LAB_011ab6e0;
  ppuStack_b8 = &PTR_LAB_011ab4e0;
  local_d8 = &PTR_LAB_011ab4e0;
  ppuStack_d0 = &PTR_LAB_011ab4e0;
  local_e0 = &PTR_LAB_011ab708;
  local_f8 = &PTR_LAB_011ab728;
  ppuStack_f0 = &PTR_LAB_011ab4e0;
  local_110 = &PTR_LAB_011ab748;
  ppuStack_108 = &PTR_LAB_011ab4e0;
  local_120 = &PTR_LAB_011ab760;
  local_130 = &PTR_LAB_011ab4e0;
  local_138 = &PTR_LAB_011ab4e0;
  DAT_012278a8 = 1;
  puStack_150 = auStack_240;
  _objc_retain(param_2);
  _objc_retain(param_3);
  _objc_retain(param_4);
  bVar2 = param_2 != 0 && param_4 == 0;
  uStack_94 = (uint)bVar2;
  if (bVar2) {
    _objc_msgSend(PTR__OBJC_CLASS___NSJSONSerialization_0114ebb0,
                  PTR_s_JSONObjectWithData_options_error_0114b4a0,param_2,0,0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uVar4 = _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_class_0114ae88);
    uStack_ac = FUN_0019b534(uVar3,PTR_s_isKindOfClass__0114ad70,uVar4);
    if (uStack_ac == 0) {
      _NSLog(local_a8[uStack_ac] + (int)-(uRam00000000011ab6d0 ^ 0xa68133ca),
             &PTR____CFConstantStringClassReference_011ab480);
    }
    else {
      lStack_178 = param_4;
      uStack_170 = param_3;
      lStack_168 = param_2;
      lStack_160 = param_1;
      _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,PTR_s_array_0114c388);
      uStack_148 = _objc_retainAutoreleasedReturnValue();
      puStack_1b8 = (undefined8 *)0x0;
      uStack_1c0 = 0;
      uStack_1a8 = 0;
      plStack_1b0 = (long *)0x0;
      uStack_198 = 0;
      uStack_1a0 = 0;
      uStack_188 = 0;
      uStack_190 = 0;
      uVar4 = _objc_retain(uVar3);
      puStack_158 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
      lVar5 = _objc_msgSend(uVar4,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_1c0,
                            puStack_150,0x10);
      puVar1 = PTR_s_segmentWithDictionary__0114db38;
      uStack_c4 = (uint)(lVar5 == 0);
      if (lVar5 != 0) {
        uStack_e4 = (uint)(*plStack_1b0 == *plStack_1b0);
        uStack_140 = uVar3;
        if (*plStack_1b0 != *plStack_1b0) {
          _objc_enumerationMutation(uVar3);
        }
        _objc_msgSend(PTR_SBSegment_0114eed8,puVar1,*puStack_1b8);
        lVar5 = _objc_retainAutoreleasedReturnValue();
        uStack_fc = (uint)(lVar5 == 0);
                    /* WARNING: Could not recover jumptable at 0x0019b008. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(local_f8[uStack_fc] + (int)-(uRam00000000011ab738 ^ 0x50b52b72)))();
        return;
      }
      _objc_release(local_c0[uStack_c4] + (int)-(uRam00000000011ab6f0 ^ 0xab0994cc),uVar3);
      lVar5 = lStack_160;
      puVar1 = PTR_s_segments_0114dac0;
      _objc_msgSend(*(undefined8 *)(lStack_160 + 0x20),PTR_s_segments_0114dac0);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_sync_enter();
      _objc_msgSend(*(undefined8 *)(lVar5 + 0x20),puVar1);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      uVar4 = uStack_148;
      _objc_msgSend(uVar7,PTR_s_setObject_forKeyedSubscript__0114b068,uStack_148,
                    *(undefined8 *)(lVar5 + 0x28));
      _objc_release(uVar7);
      _objc_sync_exit(uVar6);
      _objc_release(uVar6);
      _objc_release(uVar4);
      param_2 = lStack_168;
      param_3 = uStack_170;
      param_4 = lStack_178;
    }
    _objc_release(uVar3);
  }
  else {
    thunk_FUN_0019b668(local_90[uStack_94] + (int)-(DAT_011ab6b0 ^ 0x7623e927),
                       &PTR____CFConstantStringClassReference_011ab4c0,param_4);
  }
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_release(param_2);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_70) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


