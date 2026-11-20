/* Decompiled from supplied 5.2.2 arm package. VA 0x18de38. sectionWithCells:identifier: */

/* Function Stack Size: 0x20 bytes */

ID DVNSection::sectionWithCells_identifier_(ID param_1,SEL param_2,ID param_3,ID param_4)

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
  uint local_f4;
  undefined **local_f0;
  undefined1 auStack_e8 [128];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_f0 = &PTR_LAB_011a9438;
  _objc_retain(param_3);
  _objc_retain(param_4);
  uVar3 = _objc_alloc_init(PTR_DVNSection_0114ee90);
  puVar2 = PTR_s_setIdentifier__0114d998;
  _objc_msgSend(uVar3,PTR_s_setIdentifier__0114d998,param_4);
  local_f4 = (uint)(param_3 == 0);
  if (param_3 != 0) {
    uStack_118 = 0;
    uStack_120 = 0;
    uStack_108 = 0;
    uStack_110 = 0;
    puStack_138 = (undefined8 *)0x0;
    uStack_140 = 0;
    uStack_128 = 0;
    plStack_130 = (long *)0x0;
    uVar4 = _objc_retain(local_f0[local_f4] + (int)-(DAT_011a9448 ^ 0x59f9dad4),param_3);
    puVar1 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
    lVar5 = _objc_msgSend(uVar4,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_140,
                          auStack_e8,0x10);
    puVar7 = (&PTR_LAB_011a9450)[lVar5 == 0] + (int)-(uRam00000000011a9460 ^ 0xf8e5e8e6);
    if (lVar5 != 0) {
      lVar8 = *plStack_130;
      if (*plStack_130 != lVar8) {
        _objc_enumerationMutation
                  ((&PTR_LAB_011a9478)[*plStack_130 == lVar8] +
                   (int)-(uRam00000000011a9488 ^ 0x39ad631d),param_3);
      }
      _objc_msgSend(*puStack_138,puVar2,param_4);
      if (lVar5 != 1) {
                    /* WARNING: Could not recover jumptable at 0x0018e054. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        IVar6 = (*(code *)((&PTR_LAB_011a9478)[*plStack_130 == lVar8] +
                          (int)-(uRam00000000011a9488 ^ 0x39ad631d)))();
        return IVar6;
      }
      lVar5 = _objc_msgSend((&PTR_LAB_011a9498)[lVar5 == 1] +
                            (int)-(uRam00000000011a94a8 ^ 0xd289c024),param_3,puVar1,&uStack_140,
                            auStack_e8,0x10);
      puVar7 = (&PTR_LAB_011a94b0)[lVar5 == 0] + (int)-(uRam00000000011a94c0 ^ 0xb8248c16);
      if (lVar5 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0018e0e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        IVar6 = (*(code *)((&PTR_LAB_011a9478)[*plStack_130 == lVar8] +
                          (int)-(uRam00000000011a9488 ^ 0x39ad631d)))();
        return IVar6;
      }
    }
    _objc_release(puVar7,param_3);
    _objc_msgSend(uVar3,PTR_s_setCells__0114d9a0,param_3);
  }
  _objc_release(param_4);
  _objc_release(param_3);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar3);
  return IVar6;
}


