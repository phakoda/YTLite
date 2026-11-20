/* Decompiled from supplied 5.2.2 arm package. VA 0x1c9fd8. updateAllToasts */

/* Function Stack Size: 0x10 bytes */

void ToastManager::updateAllToasts(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 local_140;
  undefined8 *puStack_138;
  long *plStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  uint local_fc;
  undefined **local_f8;
  undefined1 auStack_f0 [128];
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_f8 = &PTR_LAB_011b4ef8;
  uVar2 = _objc_retain(*(undefined8 *)(param_1 + 0x10));
  _objc_sync_enter();
  puStack_138 = (undefined8 *)0x0;
  local_140 = 0;
  uStack_128 = 0;
  plStack_130 = (long *)0x0;
  uStack_118 = 0;
  local_120 = 0;
  uStack_108 = 0;
  uStack_110 = 0;
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  uVar3 = _objc_retain(uVar5);
  lVar4 = _objc_msgSend(uVar3,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&local_140,auStack_f0,
                        0x10);
  puVar1 = PTR_s_updateLayout_0114ddb0;
  local_fc = (uint)(lVar4 == 0);
  if (lVar4 != 0) {
    if (*plStack_130 != *plStack_130) {
      _objc_enumerationMutation
                ((&PTR_LAB_011b4f20)[*plStack_130 == *plStack_130] +
                 (int)-(uRam00000000011b4f30 ^ 0xac7c3314),uVar5);
    }
    _objc_msgSend(*puStack_138,puVar1);
                    /* WARNING: Could not recover jumptable at 0x001ca164. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011b4f38)[lVar4 == 1] + (int)-(uRam00000000011b4f48 ^ 0x90de16ec)))();
    return;
  }
  _objc_release(local_f8[local_fc] + (int)-(DAT_011b4f08 ^ 0x1c0760ac),uVar5);
  _objc_sync_exit(uVar2);
  _objc_release(uVar2);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}


