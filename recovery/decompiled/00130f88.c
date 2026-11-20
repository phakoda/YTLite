/* Decompiled from supplied 5.2.2 arm package. VA 0x130f88. initTabs */

/* Function Stack Size: 0x10 bytes */

void TabbarVC::initTabs(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined1 auStack_240 [128];
  undefined8 uStack_1c0;
  undefined8 *puStack_1b8;
  long *plStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  long lStack_180;
  long lStack_178;
  ID IStack_170;
  undefined1 *puStack_168;
  undefined *puStack_160;
  undefined8 uStack_158;
  undefined *puStack_150;
  undefined *puStack_148;
  undefined *puStack_140;
  long lStack_138;
  undefined *puStack_130;
  undefined *puStack_128;
  undefined *puStack_120;
  undefined8 uStack_118;
  undefined **local_110;
  undefined **local_100;
  undefined **local_f0;
  undefined **ppuStack_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
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
  
  puVar1 = PTR_s_removeAllObjects_0114b4e0;
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0118fec0;
  local_7c = (uint)(DAT_012273d8 == 0);
  local_90 = &PTR_LAB_0118fee0;
  local_a0 = &PTR_LAB_0118fef8;
  local_88 = &PTR_LAB_0118faf0;
  local_b8 = &PTR_LAB_0118faf0;
  ppuStack_b0 = &PTR_LAB_0118faf0;
  local_c0 = &PTR_LAB_0118ff20;
  local_d8 = &PTR_LAB_0118ff40;
  ppuStack_d0 = &PTR_LAB_0118faf0;
  local_f0 = &PTR_LAB_0118ff60;
  ppuStack_e8 = &PTR_LAB_0118faf0;
  local_100 = &PTR_LAB_0118ff78;
  local_110 = &PTR_LAB_0118faf0;
  DAT_012273d8 = 1;
  lVar5 = (long)_activeTabs;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar5),PTR_s_removeAllObjects_0114b4e0);
  lVar6 = (long)_inactiveTabs;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar6),puVar1);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_objectForKey__0114b238,&PTR____CFConstantStringClassReference_0118ed40);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,PTR_s_array_0114c388);
  uStack_158 = _objc_retainAutoreleasedReturnValue();
  uStack_118 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_tabs),PTR_s_mutableCopy_0114b010);
  uStack_94 = (uint)(lVar4 == 0);
  if (lVar4 != 0) {
    uStack_198 = 0;
    uStack_1a0 = 0;
    uStack_188 = 0;
    uStack_190 = 0;
    puStack_1b8 = (undefined8 *)0x0;
    uStack_1c0 = 0;
    uStack_1a8 = 0;
    plStack_1b0 = (long *)0x0;
    lStack_180 = lVar6;
    lStack_178 = lVar5;
    IStack_170 = param_1;
    uVar3 = _objc_retain(lVar4);
    puStack_160 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
    lVar5 = _objc_msgSend(uVar3,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_1c0,
                          auStack_240,0x10);
    uStack_a4 = (uint)(lVar5 == 0);
    if (lVar5 != 0) {
      lStack_138 = *plStack_1b0;
      puStack_120 = PTR_s_predicateWithFormat__0114c720;
      puStack_128 = PTR_s_filteredArrayUsingPredicate__0114c728;
      puStack_130 = PTR_s_count_0114b840;
      puStack_140 = PTR_s_firstObject_0114b748;
      puStack_148 = PTR_s_addObject__0114b3a0;
      puStack_150 = PTR_s_removeObject__0114cad0;
      uStack_c4 = (uint)(*plStack_1b0 == lStack_138);
      puStack_168 = auStack_240;
      if (*plStack_1b0 != lStack_138) {
        _objc_enumerationMutation
                  (local_c0[uStack_c4] + (int)-(uRam000000000118ff30 ^ 0x47682186),lVar4);
      }
      thunk_FUN_00136ad4(PTR__OBJC_CLASS___NSPredicate_0114ed68,puStack_120,
                         &PTR____CFConstantStringClassReference_0118ed00,*puStack_1b8);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uStack_118,puStack_128,uVar3);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      lVar5 = _objc_msgSend(uVar3,puStack_130);
      uStack_dc = (uint)(lVar5 == 0);
                    /* WARNING: Could not recover jumptable at 0x00131490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_d8[uStack_dc] + (int)-(uRam000000000118ff50 ^ 0xbd74a23e)))();
      return;
    }
    _objc_release(local_a0[uStack_a4] + (int)-(uRam000000000118ff08 ^ 0x5389751f),lVar4);
    param_1 = IStack_170;
    lVar5 = lStack_178;
    lVar6 = lStack_180;
  }
  uVar3 = uStack_158;
  puVar1 = PTR_s_addObjectsFromArray__0114d000;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar5),PTR_s_addObjectsFromArray__0114d000,uStack_158);
  uVar2 = uStack_118;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar6),puVar1,uStack_118);
  _objc_release(uVar2);
  _objc_release(uVar3);
  _objc_release(lVar4);
  CallSupervisor(0xea61);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}


