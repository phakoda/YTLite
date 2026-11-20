/* Decompiled from supplied 5.2.2 arm package. VA 0x18c80c. _collectMatching:into:visited: */

/* Function Stack Size: 0x28 bytes */

void DVNTableModel::_collectMatching_into_visited_
               (ID param_1,SEL param_2,ID param_3,undefined4 param_4,ID param_5,ID param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uStack_210;
  undefined8 *puStack_208;
  long *plStack_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 *puStack_1c8;
  long *plStack_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  int local_184;
  undefined **local_180;
  undefined1 auStack_178 [128];
  undefined1 auStack_f8 [128];
  long local_78;
  
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  local_180 = &PTR_LAB_011a9018;
  _objc_retain(param_3);
  _objc_retain(param_4);
  uVar3 = _objc_retain(param_5);
  local_184 = FUN_0018d750(uVar3,PTR_s_containsObject__0114c848,param_1);
  if (local_184 == 0) {
    _objc_msgSend(param_5,PTR_s_addObject__0114b3a0,param_1);
    uStack_1a8 = 0;
    uStack_1b0 = 0;
    uStack_198 = 0;
    uStack_1a0 = 0;
    puStack_1c8 = (undefined8 *)0x0;
    uStack_1d0 = 0;
    uStack_1b8 = 0;
    plStack_1c0 = (long *)0x0;
    _objc_msgSend(param_1,PTR_s_sections_0114d240);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
    lVar4 = _objc_msgSend(uVar3,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_1d0,
                          auStack_f8,0x10);
    puVar2 = PTR_s_cells_0114d290;
    if (lVar4 != 0) {
      if (*plStack_1c0 != *plStack_1c0) {
        _objc_enumerationMutation
                  ((&PTR_LAB_011a9058)[*plStack_1c0 == *plStack_1c0] +
                   (int)-(uRam00000000011a9068 ^ 0x6583337c),uVar3);
      }
      puStack_208 = (undefined8 *)0x0;
      uStack_210 = 0;
      uStack_1f8 = 0;
      plStack_200 = (long *)0x0;
      uStack_1e8 = 0;
      uStack_1f0 = 0;
      uStack_1d8 = 0;
      uStack_1e0 = 0;
      _objc_msgSend(*puStack_1c8,puVar2);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      lVar5 = _objc_msgSend(uVar3,puVar1,&uStack_210,auStack_178,0x10);
      if (lVar5 == 0) {
        _objc_release((&PTR_LAB_011a9078)[lVar5 == 0] + (int)-(uRam00000000011a9088 ^ 0xc4800eec),
                      uVar3);
                    /* WARNING: Could not recover jumptable at 0x0018cd90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)((&PTR_LAB_011a9148)[lVar4 == 1] + (int)-(uRam00000000011a9158 ^ 0x56ad02de)))();
        return;
      }
      if (*plStack_200 != *plStack_200) {
        _objc_enumerationMutation
                  ((&PTR_LAB_011a90a0)[*plStack_200 == *plStack_200] +
                   (int)-(DAT_011a90b0 ^ 0x644bf5f4),uVar3);
      }
      uVar6 = (**(code **)(param_3 + 0x10))(param_3,*puStack_208);
                    /* WARNING: Could not recover jumptable at 0x0018cb60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((&PTR_LAB_011a90c0)[uVar6 & 0xffffffff] + (int)-(uRam00000000011a90d0 ^ 0x3e184e7c)
                ))();
      return;
    }
    _objc_release((&PTR_LAB_011a9030)[lVar4 == 0] + (int)-(uRam00000000011a9040 ^ 0x8298cce0),uVar3)
    ;
  }
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x7d13);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_78) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}


