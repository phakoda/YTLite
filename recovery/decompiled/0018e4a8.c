/* Decompiled from supplied 5.2.2 arm package. VA 0x18e4a8. sectionWithHeader:footer:cells:identifier: */

/* Function Stack Size: 0x30 bytes */

ID DVNSection::sectionWithHeader_footer_cells_identifier_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  ID IVar6;
  undefined *puVar7;
  long lVar8;
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
  local_f8 = &PTR_LAB_011a9568;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_retain(param_6);
  uVar3 = _objc_alloc_init(PTR_DVNSection_0114ee90);
  puVar2 = PTR_s_setIdentifier__0114d998;
  _objc_msgSend(uVar3,PTR_s_setIdentifier__0114d998,param_6);
  _objc_msgSend(uVar3,PTR_s_setHeader__0114d7b8,param_3);
  _objc_msgSend(uVar3,PTR_s_setFooter__0114d6f0,param_4);
  local_fc = (uint)(param_5 == 0);
  if (param_5 != 0) {
    uStack_118 = 0;
    uStack_120 = 0;
    uStack_108 = 0;
    uStack_110 = 0;
    puStack_138 = (undefined8 *)0x0;
    uStack_140 = 0;
    uStack_128 = 0;
    plStack_130 = (long *)0x0;
    uVar4 = _objc_retain(local_f8[local_fc] + (int)-(DAT_011a9578 ^ 0x7f39bd6b),param_5);
    puVar1 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
    lVar5 = _objc_msgSend(uVar4,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_140,
                          auStack_f0,0x10);
    puVar7 = (&PTR_LAB_011a9580)[lVar5 == 0] + (int)-(uRam00000000011a9590 ^ 0x7bdaae07);
    if (lVar5 != 0) {
      lVar8 = *plStack_130;
      if (*plStack_130 != lVar8) {
        _objc_enumerationMutation
                  ((&PTR_LAB_011a95a8)[*plStack_130 == lVar8] +
                   (int)-(uRam00000000011a95b8 ^ 0x97039233),param_5);
      }
      _objc_msgSend(*puStack_138,puVar2,param_6);
      if (lVar5 != 1) {
                    /* WARNING: Could not recover jumptable at 0x0018e708. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        IVar6 = (*(code *)((&PTR_LAB_011a95a8)[*plStack_130 == lVar8] +
                          (int)-(uRam00000000011a95b8 ^ 0x97039233)))();
        return IVar6;
      }
      lVar5 = _objc_msgSend((&PTR_watchLaterTabSelected_011a95c8)[lVar5 == 1] +
                            (int)-(uRam00000000011a95d8 ^ 0x2e64b60d),param_5,puVar1,&uStack_140,
                            auStack_f0,0x10);
      puVar7 = (&PTR_LAB_011a95e0)[lVar5 == 0] + (int)-(uRam00000000011a95f0 ^ 0xd8f7efac);
      if (lVar5 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0018e794. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        IVar6 = (*(code *)((&PTR_LAB_011a95a8)[*plStack_130 == lVar8] +
                          (int)-(uRam00000000011a95b8 ^ 0x97039233)))();
        return IVar6;
      }
    }
    _objc_release(puVar7,param_5);
    _objc_msgSend(uVar3,PTR_s_setCells__0114d9a0,param_5);
  }
  _objc_release(param_6);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar3);
  return IVar6;
}


