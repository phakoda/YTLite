// Decompiled implementation evidence for DVNSection. Not compilable source.

// -[DVNSection init], 0x18d94c
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d94c. init */

/* Function Stack Size: 0x10 bytes */

ID DVNSection::init(ID param_1,SEL param_2)

{
  ID IVar1;
  ID local_40;
  undefined *puStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011a9358;
  puStack_38 = PTR_DVNSection_0114f0c0;
  local_40 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_40,@selector(init));
  local_2c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    _objc_storeStrong(IVar1 + 0x28,*(undefined8 *)PTR____NSArray0___01060670);
  }
  return IVar1;
}



// -[DVNSection _appendCells:], 0x18d9f0
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
  lVar2 = _objc_msgSend(param_3,@selector(count));
  local_fc = (uint)(lVar2 == 0);
  if (lVar2 != 0) {
    uVar3 = _objc_msgSend(*(undefined8 *)(param_1 + 0x28),@selector(mutableCopy));
    puStack_138 = (undefined8 *)0x0;
    uStack_140 = 0;
    uStack_128 = 0;
    plStack_130 = (long *)0x0;
    uStack_118 = 0;
    uStack_120 = 0;
    uStack_108 = 0;
    uStack_110 = 0;
    uVar4 = _objc_retain(param_3);
    lVar2 = _objc_msgSend(uVar4,@selector(countByEnumeratingWithState:objects:count:),&uStack_140,
                          auStack_f0,0x10);
    puVar1 = @selector(title);
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
    uVar4 = _objc_msgSend(uVar3,@selector(copy));
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



// -[DVNSection addCell:], 0x18ef44
/* Decompiled from supplied 5.2.2 arm package. VA 0x18ef44. addCell: */

/* Function Stack Size: 0x18 bytes */

void DVNSection::addCell_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  ID local_40;
  long local_38;
  
  puVar2 = PTR__OBJC_CLASS___NSArray_0114ec18;
  puVar1 = @selector(arrayWithObjects:count:);
  local_38 = *(long *)PTR____stack_chk_guard_01060708;
  local_40 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1,&local_40,1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(_appendCells:),uVar3);
  _objc_release(param_3);
  _objc_release(uVar3);
  CallSupervisor(0x7690);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}



// -[DVNSection addCells:], 0x18f018
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f018. addCells: */

/* Function Stack Size: 0x18 bytes */

void DVNSection::addCells_(ID param_1,SEL param_2,ID param_3)

{
  _objc_msgSend(param_1,@selector(_appendCells:));
  CallSupervisor(0xe0e1);
  return;
}



// -[DVNSection header], 0x18f04c
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f04c. header */

/* Function Stack Size: 0x10 bytes */

ID DVNSection::header(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 8);
}



// -[DVNSection setHeader:], 0x18f054
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f054. setHeader: */

/* Function Stack Size: 0x18 bytes */

void DVNSection::setHeader_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 8,param_3);
  CallSupervisor(0x14eb);
  return;
}



// -[DVNSection footer], 0x18f088
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f088. footer */

/* Function Stack Size: 0x10 bytes */

ID DVNSection::footer(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x10);
}



// -[DVNSection setFooter:], 0x18f090
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f090. setFooter: */

/* Function Stack Size: 0x18 bytes */

void DVNSection::setFooter_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x10,param_3);
  CallSupervisor(0x3f8a);
  return;
}



// -[DVNSection identifier], 0x18f0c4
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f0c4. identifier */

/* Function Stack Size: 0x10 bytes */

ID DVNSection::identifier(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x18);
}



// -[DVNSection setIdentifier:], 0x18f0cc
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f0cc. setIdentifier: */

/* Function Stack Size: 0x18 bytes */

void DVNSection::setIdentifier_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x18,param_3);
  return;
}



// -[DVNSection headerIcon], 0x18f0d8
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f0d8. headerIcon */

/* Function Stack Size: 0x10 bytes */

ID DVNSection::headerIcon(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x20);
}



// -[DVNSection setHeaderIcon:], 0x18f0e0
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f0e0. setHeaderIcon: */

/* Function Stack Size: 0x18 bytes */

void DVNSection::setHeaderIcon_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x20,param_3);
  return;
}



// -[DVNSection cells], 0x18f0ec
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f0ec. cells */

/* Function Stack Size: 0x10 bytes */

ID DVNSection::cells(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x28);
}



// -[DVNSection setCells:], 0x18f0f4
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f0f4. setCells: */

/* Function Stack Size: 0x18 bytes */

void DVNSection::setCells_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x28,param_3);
  CallSupervisor(0x79d9);
  return;
}



// -[DVNSection cellsProvider], 0x18f128
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f128. cellsProvider */

/* Function Stack Size: 0x10 bytes */

ID DVNSection::cellsProvider(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x30);
}



// -[DVNSection setCellsProvider:], 0x18f130
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f130. setCellsProvider: */

/* Function Stack Size: 0x18 bytes */

void DVNSection::setCellsProvider_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  _objc_setProperty_nonatomic_copy();
  return;
}



// -[DVNSection .cxx_destruct], 0x18f138
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f138. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void DVNSection::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 0x30,0);
  _objc_storeStrong(param_1 + 0x28,0);
  _objc_storeStrong(param_1 + 0x20,0);
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  _objc_storeStrong(param_1 + 8,0);
  CallSupervisor(0x19b7);
  return;
}



// +[DVNSection sectionWithIdentifier:], 0x18dde4
/* Decompiled from supplied 5.2.2 arm package. VA 0x18dde4. sectionWithIdentifier: */

/* Function Stack Size: 0x18 bytes */

ID DVNSection::sectionWithIdentifier_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNSection_0114ee90;
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setIdentifier:),param_3);
  _objc_release(param_3);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNSection sectionWithCells:identifier:], 0x18de38
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
  puVar2 = @selector(setIdentifier:);
  _objc_msgSend(uVar3,@selector(setIdentifier:),param_4);
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
    puVar1 = @selector(countByEnumeratingWithState:objects:count:);
    lVar5 = _objc_msgSend(uVar4,@selector(countByEnumeratingWithState:objects:count:),&uStack_140,
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
    _objc_msgSend(uVar3,@selector(setCells:),param_3);
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



// +[DVNSection sectionWithHeader:cells:identifier:], 0x18e15c
/* Decompiled from supplied 5.2.2 arm package. VA 0x18e15c. sectionWithHeader:cells:identifier: */

/* Function Stack Size: 0x28 bytes */

ID DVNSection::sectionWithHeader_cells_identifier_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

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
  local_f8 = &PTR_LAB_011a94d0;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  uVar3 = _objc_alloc_init(PTR_DVNSection_0114ee90);
  puVar2 = @selector(setIdentifier:);
  _objc_msgSend(uVar3,@selector(setIdentifier:),param_5);
  _objc_msgSend(uVar3,@selector(setHeader:),param_3);
  local_fc = (uint)(param_4 == 0);
  if (param_4 != 0) {
    uStack_118 = 0;
    uStack_120 = 0;
    uStack_108 = 0;
    uStack_110 = 0;
    puStack_138 = (undefined8 *)0x0;
    uStack_140 = 0;
    uStack_128 = 0;
    plStack_130 = (long *)0x0;
    uVar4 = _objc_retain(local_f8[local_fc] + (int)-(DAT_011a94e0 ^ 0x8728fa4a),param_4);
    puVar1 = @selector(countByEnumeratingWithState:objects:count:);
    lVar5 = _objc_msgSend(uVar4,@selector(countByEnumeratingWithState:objects:count:),&uStack_140,
                          auStack_f0,0x10);
    puVar7 = (&PTR__objc_msgSend_011a94e8)[lVar5 == 0] + (int)-(uRam00000000011a94f8 ^ 0x111f5350);
    if (lVar5 != 0) {
      lVar8 = *plStack_130;
      if (*plStack_130 != lVar8) {
        _objc_enumerationMutation
                  ((&PTR_thunk_FUN_001ce6f8_011a9510)[*plStack_130 == lVar8] +
                   (int)-(uRam00000000011a9520 ^ 0x10b8d402),param_4);
      }
      _objc_msgSend(*puStack_138,puVar2,param_5);
      if (lVar5 != 1) {
                    /* WARNING: Could not recover jumptable at 0x0018e398. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        IVar6 = (*(code *)((&PTR_thunk_FUN_001ce6f8_011a9510)[*plStack_130 == lVar8] +
                          (int)-(uRam00000000011a9520 ^ 0x10b8d402)))();
        return IVar6;
      }
      lVar5 = _objc_msgSend((&PTR_LAB_011a9530)[lVar5 == 1] +
                            (int)-(uRam00000000011a9540 ^ 0xd6061286),param_4,puVar1,&uStack_140,
                            auStack_f0,0x10);
      puVar7 = (&PTR_LAB_011a9548)[lVar5 == 0] + (int)-(uRam00000000011a9558 ^ 0x3eddccd3);
      if (lVar5 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0018e424. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        IVar6 = (*(code *)((&PTR_thunk_FUN_001ce6f8_011a9510)[*plStack_130 == lVar8] +
                          (int)-(uRam00000000011a9520 ^ 0x10b8d402)))();
        return IVar6;
      }
    }
    _objc_release(puVar7,param_4);
    _objc_msgSend(uVar3,@selector(setCells:),param_4);
  }
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



// +[DVNSection sectionWithHeader:footer:cells:identifier:], 0x18e4a8
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
  puVar2 = @selector(setIdentifier:);
  _objc_msgSend(uVar3,@selector(setIdentifier:),param_6);
  _objc_msgSend(uVar3,@selector(setHeader:),param_3);
  _objc_msgSend(uVar3,@selector(setFooter:),param_4);
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
    puVar1 = @selector(countByEnumeratingWithState:objects:count:);
    lVar5 = _objc_msgSend(uVar4,@selector(countByEnumeratingWithState:objects:count:),&uStack_140,
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
    _objc_msgSend(uVar3,@selector(setCells:),param_5);
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



// +[DVNSection sectionWithHeader:headerIcon:cells:identifier:], 0x18e824
/* Decompiled from supplied 5.2.2 arm package. VA 0x18e824. sectionWithHeader:headerIcon:cells:identifier: */

/* Function Stack Size: 0x30 bytes */

ID DVNSection::sectionWithHeader_headerIcon_cells_identifier_
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
  local_f8 = &PTR_LAB_011a9600;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_retain(param_6);
  uVar3 = _objc_alloc_init(PTR_DVNSection_0114ee90);
  puVar2 = @selector(setIdentifier:);
  _objc_msgSend(uVar3,@selector(setIdentifier:),param_6);
  _objc_msgSend(uVar3,@selector(setHeader:),param_3);
  _objc_msgSend(uVar3,@selector(setHeaderIcon:),param_4);
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
    uVar4 = _objc_retain(local_f8[local_fc] + (int)-(DAT_011a9610 ^ 0xa8f36117),param_5);
    puVar1 = @selector(countByEnumeratingWithState:objects:count:);
    lVar5 = _objc_msgSend(uVar4,@selector(countByEnumeratingWithState:objects:count:),&uStack_140,
                          auStack_f0,0x10);
    puVar7 = (&PTR_LAB_011a9618)[lVar5 == 0] + (int)-(uRam00000000011a9628 ^ 0x6e3c4dd3);
    if (lVar5 != 0) {
      lVar8 = *plStack_130;
      if (*plStack_130 != lVar8) {
        _objc_enumerationMutation
                  ((&PTR_LAB_011a9640)[*plStack_130 == lVar8] +
                   (int)-(uRam00000000011a9650 ^ 0x201cd23f),param_5);
      }
      _objc_msgSend(*puStack_138,puVar2,param_6);
      if (lVar5 != 1) {
                    /* WARNING: Could not recover jumptable at 0x0018ea84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        IVar6 = (*(code *)((&PTR_LAB_011a9640)[*plStack_130 == lVar8] +
                          (int)-(uRam00000000011a9650 ^ 0x201cd23f)))();
        return IVar6;
      }
      lVar5 = _objc_msgSend((&PTR_LAB_011a9660)[lVar5 == 1] +
                            (int)-(uRam00000000011a9670 ^ 0xbeeafb51),param_5,puVar1,&uStack_140,
                            auStack_f0,0x10);
      puVar7 = (&PTR_LAB_011a9678)[lVar5 == 0] + (int)-(uRam00000000011a9688 ^ 0xa03b2f3c);
      if (lVar5 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0018eb10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        IVar6 = (*(code *)((&PTR_LAB_011a9640)[*plStack_130 == lVar8] +
                          (int)-(uRam00000000011a9650 ^ 0x201cd23f)))();
        return IVar6;
      }
    }
    _objc_release(puVar7,param_5);
    _objc_msgSend(uVar3,@selector(setCells:),param_5);
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



// +[DVNSection sectionWithHeader:headerIcon:footer:cells:identifier:], 0x18eba0
/* Decompiled from supplied 5.2.2 arm package. VA 0x18eba0. sectionWithHeader:headerIcon:footer:cells:identifier: */

/* Function Stack Size: 0x38 bytes */

ID DVNSection::sectionWithHeader_headerIcon_footer_cells_identifier_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,ID param_7)

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
  local_f8 = &PTR_LAB_011a9698;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_retain(param_6);
  _objc_retain(param_7);
  uVar3 = _objc_alloc_init(PTR_DVNSection_0114ee90);
  puVar2 = @selector(setIdentifier:);
  _objc_msgSend(uVar3,@selector(setIdentifier:),param_7);
  _objc_msgSend(uVar3,@selector(setHeader:),param_3);
  _objc_msgSend(uVar3,@selector(setHeaderIcon:),param_4);
  _objc_msgSend(uVar3,@selector(setFooter:),param_5);
  local_fc = (uint)(param_6 == 0);
  if (param_6 != 0) {
    uStack_118 = 0;
    uStack_120 = 0;
    uStack_108 = 0;
    uStack_110 = 0;
    puStack_138 = (undefined8 *)0x0;
    uStack_140 = 0;
    uStack_128 = 0;
    plStack_130 = (long *)0x0;
    uVar4 = _objc_retain(local_f8[local_fc] + (int)-(DAT_011a96a8 ^ 0xbeb8312d),param_6);
    puVar1 = @selector(countByEnumeratingWithState:objects:count:);
    lVar5 = _objc_msgSend(uVar4,@selector(countByEnumeratingWithState:objects:count:),&uStack_140,
                          auStack_f0,0x10);
    puVar7 = (&PTR_LAB_011a96b0)[lVar5 == 0] + (int)-(uRam00000000011a96c0 ^ 0xb965a313);
    if (lVar5 != 0) {
      lVar8 = *plStack_130;
      if (*plStack_130 != lVar8) {
        _objc_enumerationMutation
                  ((&PTR_LAB_011a96d8)[*plStack_130 == lVar8] +
                   (int)-(uRam00000000011a96e8 ^ 0xe8dc3dca),param_6);
      }
      _objc_msgSend(*puStack_138,puVar2,param_7);
      if (lVar5 != 1) {
                    /* WARNING: Could not recover jumptable at 0x0018ee20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        IVar6 = (*(code *)((&PTR_LAB_011a96d8)[*plStack_130 == lVar8] +
                          (int)-(uRam00000000011a96e8 ^ 0xe8dc3dca)))();
        return IVar6;
      }
      lVar5 = _objc_msgSend((&PTR_LAB_011a96f8)[lVar5 == 1] +
                            (int)-(uRam00000000011a9708 ^ 0x269751ba),param_6,puVar1,&uStack_140,
                            auStack_f0,0x10);
      puVar7 = (&PTR_LAB_011a9710)[lVar5 == 0] + (int)-(uRam00000000011a9720 ^ 0x358e4754);
      if (lVar5 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0018eeac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        IVar6 = (*(code *)((&PTR_LAB_011a96d8)[*plStack_130 == lVar8] +
                          (int)-(uRam00000000011a96e8 ^ 0xe8dc3dca)))();
        return IVar6;
      }
    }
    _objc_release(puVar7,param_6);
    _objc_msgSend(uVar3,@selector(setCells:),param_6);
  }
  _objc_release(param_7);
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


