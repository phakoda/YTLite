/* Decompiled from supplied 5.2.2 arm package. VA 0x18d9f0. _appendCells: */

/* Function Stack Size: 0x18 bytes */

void DVNSection::_appendCells_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uStack_140;
  undefined8 *puStack_138;
  long *plStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  uint local_fc;
  undefined **local_f8;
  undefined1 auStack_f0 [128];
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_f8 = &PTR_LAB_011a9378;
  _objc_retain(param_3);
  lVar2 = _objc_msgSend(param_3,PTR_s_count_0114b840);
  local_fc = (uint)(lVar2 == 0);
  if (lVar2 != 0) {
    uVar3 = _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_mutableCopy_0114b010);
    puStack_138 = (undefined8 *)0x0;
    uStack_140 = 0;
    uStack_128 = 0;
    plStack_130 = (long *)0x0;
    uStack_118 = 0;
    uStack_120 = 0;
    uStack_108 = 0;
    uStack_110 = 0;
    uVar4 = _objc_retain(param_3);
    lVar2 = _objc_msgSend(uVar4,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_140,
                          auStack_f0,0x10);
    puVar1 = PTR_s_title_0114c7f0;
    if (lVar2 != 0) {
      if (*plStack_130 != *plStack_130) {
        _objc_enumerationMutation
                  ((&PTR_LAB_011a93b8)[*plStack_130 == *plStack_130] +
                   (int)-(uRam00000000011a93c8 ^ 0x3d43cd04),param_3);
      }
      _objc_msgSend(*puStack_138,puVar1);
      lVar2 = _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x0018dc14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((&PTR_LAB_011a93d8)[lVar2 == 0] + (int)-(uRam00000000011a93e8 ^ 0x979a6adb)))();
      return;
    }
    _objc_release((&PTR_LAB_011a9390)[lVar2 == 0] + (int)-(uRam00000000011a93a0 ^ 0xa3776277),
                  param_3);
    uVar4 = _objc_msgSend(uVar3,PTR_s_copy_0114b058);
    uVar5 = *(undefined8 *)(param_1 + 0x28);
    *(undefined8 *)(param_1 + 0x28) = uVar4;
    _objc_release(uVar5);
    _objc_release(uVar3);
  }
  _objc_release(param_3);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}


