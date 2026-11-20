// Decompiled implementation evidence for DVNTableModel. Not compilable source.

// -[DVNTableModel init], 0x18b72c
/* Decompiled from supplied 5.2.2 arm package. VA 0x18b72c. init */

/* Function Stack Size: 0x10 bytes */

ID DVNTableModel::init(ID param_1,SEL param_2)

{
  undefined *puVar1;
  ID IVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID local_60;
  undefined *puStack_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011a8d58;
  puStack_58 = PTR_DVNTableModel_0114f0b8;
  local_60 = param_1;
  IVar2 = _objc_msgSendSuper2(&local_60,@selector(init));
  local_4c = (uint)(IVar2 == 0);
  if (IVar2 != 0) {
    _objc_storeStrong(IVar2 + 0x48,*(undefined8 *)PTR____NSArray0___01060670);
    puVar1 = @selector(systemFontOfSize:weight:);
    uVar5 = *(undefined8 *)PTR__UIFontWeightSemibold_01060580;
    _objc_msgSend(0x402c000000000000,uVar5,PTR__OBJC_CLASS___UIFont_0114ec08,
                  @selector(systemFontOfSize:weight:));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uVar4 = *(undefined8 *)(IVar2 + 0x28);
    *(undefined8 *)(IVar2 + 0x28) = uVar3;
    _objc_release(uVar4);
    _objc_msgSend(0x402a000000000000,uVar5,PTR__OBJC_CLASS___UIFont_0114ec08,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uVar4 = *(undefined8 *)(IVar2 + 0x30);
    *(undefined8 *)(IVar2 + 0x30) = uVar3;
    _objc_release(uVar4);
    *(undefined8 *)(IVar2 + 0x40) = 1;
    *(undefined8 *)(IVar2 + 0x38) = 1;
  }
  return IVar2;
}



// -[DVNTableModel addSection:], 0x18bbb0
/* Decompiled from supplied 5.2.2 arm package. VA 0x18bbb0. addSection: */

/* Function Stack Size: 0x18 bytes */

void DVNTableModel::addSection_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  _objc_msgSend(*(undefined8 *)(param_1 + 0x48),@selector(arrayByAddingObject:));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = *(undefined8 *)(param_1 + 0x48);
  *(undefined8 *)(param_1 + 0x48) = uVar1;
  _objc_release(uVar2);
  CallSupervisor(0x6bbf);
  return;
}



// -[DVNTableModel addSections:], 0x18bc0c
/* Decompiled from supplied 5.2.2 arm package. VA 0x18bc0c. addSections: */

/* Function Stack Size: 0x18 bytes */

void DVNTableModel::addSections_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  _objc_msgSend(*(undefined8 *)(param_1 + 0x48),@selector(arrayByAddingObjectsFromArray:));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = *(undefined8 *)(param_1 + 0x48);
  *(undefined8 *)(param_1 + 0x48) = uVar1;
  _objc_release(uVar2);
  CallSupervisor(0x82dd);
  return;
}



// -[DVNTableModel cellForString:], 0x18bc68
/* Decompiled from supplied 5.2.2 arm package. VA 0x18bc68. cellForString: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableModel::cellForString_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  ID IVar13;
  undefined *puVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  undefined *puVar18;
  long lVar19;
  undefined8 uVar20;
  long lStack_2d8;
  undefined8 uStack_200;
  long lStack_1f8;
  long *plStack_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  long lStack_1b8;
  long *plStack_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  uint local_17c;
  undefined **local_178;
  undefined1 auStack_170 [128];
  undefined1 auStack_f0 [128];
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_178 = &PTR_LAB_011a8dd8;
  _objc_retain(param_3);
  uStack_198 = 0;
  local_1a0 = 0;
  uStack_188 = 0;
  uStack_190 = 0;
  lStack_1b8 = 0;
  local_1c0 = 0;
  uStack_1a8 = 0;
  plStack_1b0 = (long *)0x0;
  _objc_msgSend(param_1,@selector(sections));
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(countByEnumeratingWithState:objects:count:);
  lVar9 = _objc_msgSend(uVar8,@selector(countByEnumeratingWithState:objects:count:),&local_1c0,auStack_f0,
                        0x10);
  uVar20 = 0;
  local_17c = (uint)(lVar9 == 0);
  if (lVar9 == 0) {
LAB_0018c1fc:
    _objc_release(uVar8);
    _objc_release(param_3);
    if (*(long *)PTR____stack_chk_guard_01060708 == local_70) {
      IVar13 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar20);
      return IVar13;
    }
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  lVar16 = 0;
  lVar15 = *plStack_1b0;
  bVar5 = *plStack_1b0 == lVar15;
  puVar14 = (&PTR_LAB_011a8e00)[bVar5] + (int)-(uRam00000000011a8e10 ^ 0xcba18ff1);
  puVar18 = @selector(cells);
joined_r0x0400420c:
  if (bVar5) goto LAB_0018be24;
  do {
    _objc_enumerationMutation(puVar14,uVar8);
LAB_0018be24:
    do {
      lStack_1f8 = 0;
      uStack_200 = 0;
      uStack_1e8 = 0;
      plStack_1f0 = (long *)0x0;
      uStack_1d8 = 0;
      uStack_1e0 = 0;
      uStack_1c8 = 0;
      uStack_1d0 = 0;
      _objc_msgSend(*(undefined8 *)(lStack_1b8 + lVar16 * 8),puVar18);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      lStack_2d8 = _objc_msgSend(uVar10,puVar2,&uStack_200,auStack_170,0x10);
      puVar14 = (&PTR_LAB_011a8e20)[lStack_2d8 == 0] + (int)-(uRam00000000011a8e30 ^ 0x58d98643);
      if (lStack_2d8 != 0) {
        lVar19 = *plStack_1f0;
LAB_0018beac:
        puVar4 = @selector(subtitle);
        puVar3 = @selector(title);
        puVar1 = @selector(containsString:);
        lVar17 = 0;
        bVar5 = *plStack_1f0 == lVar19;
        puVar14 = (&PTR_LAB_011a8e48)[bVar5] + (int)-(uRam00000000011a8e58 ^ 0x3f4cd942);
        do {
          if (!bVar5) {
            _objc_enumerationMutation(puVar14,uVar10);
          }
          uVar20 = *(undefined8 *)(lStack_1f8 + lVar17 * 8);
          _objc_msgSend(uVar20,puVar3);
          uVar11 = _objc_retainAutoreleasedReturnValue();
          uVar6 = FUN_0018d548(uVar11,puVar1,param_3);
          if (uVar6 != 0) {
            _objc_release((&PTR_LAB_011a8e68)[uVar6] + (int)-(uRam00000000011a8e78 ^ 0x9bf98f12),
                          uVar11);
LAB_0018c1e4:
            _objc_retain(uVar20);
            _objc_release(uVar10);
            goto LAB_0018c1fc;
          }
          _objc_msgSend(uVar20,puVar4);
          uVar12 = _objc_retainAutoreleasedReturnValue();
          iVar7 = FUN_0018d480(uVar12,puVar1,param_3);
          _objc_release(uVar12);
          _objc_release(uVar11);
          if (iVar7 != 0) goto LAB_0018c1e4;
          lVar17 = lVar17 + 1;
          if (lVar17 == lStack_2d8) goto LAB_0018c050;
          bVar5 = *plStack_1f0 == lVar19;
          puVar14 = (&PTR_LAB_011a8e48)[bVar5] + (int)-(uRam00000000011a8e58 ^ 0x3f4cd942);
        } while( true );
      }
LAB_0018c0b4:
      _objc_release(puVar14,uVar10);
      lVar16 = lVar16 + 1;
      if (lVar16 != lVar9) {
        bVar5 = *plStack_1b0 == lVar15;
        puVar14 = (&PTR_LAB_011a8e00)[bVar5] + (int)-(uRam00000000011a8e10 ^ 0xcba18ff1);
        goto joined_r0x0400420c;
      }
      lVar9 = _objc_msgSend((&PTR_LAB_011a8ed0)[lVar16 == lVar9] +
                            (int)-(uRam00000000011a8ee0 ^ 0x23c8cbef),uVar8,puVar2,&local_1c0,
                            auStack_f0,0x10);
      uVar20 = 0;
      if (lVar9 == 0) goto LAB_0018c1fc;
      lVar16 = 0;
      puVar14 = (&PTR_LAB_011a8e00)[*plStack_1b0 == lVar15] +
                (int)-(uRam00000000011a8e10 ^ 0xcba18ff1);
      puVar18 = @selector(cells);
    } while (*plStack_1b0 == lVar15);
  } while( true );
LAB_0018c050:
  lStack_2d8 = _objc_msgSend((&PTR_LAB_011a8ea0)[lVar17 == lStack_2d8] +
                             (int)-(uRam00000000011a8eb0 ^ 0xae4e0974),uVar10,puVar2,&uStack_200,
                             auStack_170,0x10);
  puVar14 = (&PTR_LAB_011a8eb8)[lStack_2d8 == 0] + (int)-(uRam00000000011a8ec8 ^ 0x9116e18e);
  if (lStack_2d8 == 0) goto LAB_0018c0b4;
  goto LAB_0018beac;
}



// -[DVNTableModel cellsMatching:], 0x18c24c
/* Decompiled from supplied 5.2.2 arm package. VA 0x18c24c. cellsMatching: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableModel::cellsMatching_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  undefined8 uVar1;
  long lVar2;
  ID IVar3;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  uint local_184;
  undefined **local_180;
  undefined1 auStack_f8 [128];
  undefined8 local_78;
  
  local_78 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_180 = &PTR_LAB_011a8f08;
  _objc_retain(param_3,param_2,param_3,param_4);
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
  _objc_retainAutoreleasedReturnValue();
  uStack_1c8 = 0;
  local_1d0 = 0;
  uStack_1b8 = 0;
  uStack_1c0 = 0;
  uStack_1a8 = 0;
  local_1b0 = 0;
  uStack_198 = 0;
  uStack_1a0 = 0;
  _objc_msgSend(param_1,@selector(sections));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar2 = _objc_msgSend(uVar1,@selector(countByEnumeratingWithState:objects:count:),&local_1d0,auStack_f8,
                        0x10);
  local_184 = (uint)(lVar2 == 0);
                    /* WARNING: Could not recover jumptable at 0x0018c3a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar3 = (*(code *)(local_180[local_184] + (int)-(DAT_011a8f18 ^ 0x9bd8315)))();
  return IVar3;
}



// -[DVNTableModel cellsMatchingRecursive:], 0x18c764
/* Decompiled from supplied 5.2.2 arm package. VA 0x18c764. cellsMatchingRecursive: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableModel::cellsMatchingRecursive_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  puVar2 = PTR__OBJC_CLASS___NSMutableArray_0114eb90;
  puVar1 = @selector(array);
  _objc_retain(param_3,param_2,param_3,param_4);
  _objc_msgSend(puVar2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSHashTable_0114eeb8,@selector(weakObjectsHashTable));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,@selector(_collectMatching:into:visited:),param_3,uVar3,uVar4);
  _objc_release(param_3);
  _objc_release(uVar4);
  IVar5 = _objc_autoreleaseReturnValue(uVar3);
  return IVar5;
}



// -[DVNTableModel _collectMatching:into:visited:], 0x18c80c
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
  local_184 = FUN_0018d750(uVar3,@selector(containsObject:),param_1);
  if (local_184 == 0) {
    _objc_msgSend(param_5,@selector(addObject:),param_1);
    uStack_1a8 = 0;
    uStack_1b0 = 0;
    uStack_198 = 0;
    uStack_1a0 = 0;
    puStack_1c8 = (undefined8 *)0x0;
    uStack_1d0 = 0;
    uStack_1b8 = 0;
    plStack_1c0 = (long *)0x0;
    _objc_msgSend(param_1,@selector(sections));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(countByEnumeratingWithState:objects:count:);
    lVar4 = _objc_msgSend(uVar3,@selector(countByEnumeratingWithState:objects:count:),&uStack_1d0,
                          auStack_f8,0x10);
    puVar2 = @selector(cells);
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



// -[DVNTableModel title], 0x18cef8
/* Decompiled from supplied 5.2.2 arm package. VA 0x18cef8. title */

/* Function Stack Size: 0x10 bytes */

ID DVNTableModel::title(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x10);
}



// -[DVNTableModel setTitle:], 0x18cf00
/* Decompiled from supplied 5.2.2 arm package. VA 0x18cf00. setTitle: */

/* Function Stack Size: 0x18 bytes */

void DVNTableModel::setTitle_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x10,param_3);
  CallSupervisor(0xc834);
  return;
}



// -[DVNTableModel header], 0x18cf34
/* Decompiled from supplied 5.2.2 arm package. VA 0x18cf34. header */

/* Function Stack Size: 0x10 bytes */

ID DVNTableModel::header(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x18);
}



// -[DVNTableModel setHeader:], 0x18cf3c
/* Decompiled from supplied 5.2.2 arm package. VA 0x18cf3c. setHeader: */

/* Function Stack Size: 0x18 bytes */

void DVNTableModel::setHeader_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x18,param_3);
  CallSupervisor(0x81d8);
  return;
}



// -[DVNTableModel footer], 0x18cf70
/* Decompiled from supplied 5.2.2 arm package. VA 0x18cf70. footer */

/* Function Stack Size: 0x10 bytes */

ID DVNTableModel::footer(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x20);
}



// -[DVNTableModel setFooter:], 0x18cf78
/* Decompiled from supplied 5.2.2 arm package. VA 0x18cf78. setFooter: */

/* Function Stack Size: 0x18 bytes */

void DVNTableModel::setFooter_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x20,param_3);
  CallSupervisor(0xb536);
  return;
}



// -[DVNTableModel headerFont], 0x18cfac
/* Decompiled from supplied 5.2.2 arm package. VA 0x18cfac. headerFont */

/* Function Stack Size: 0x10 bytes */

ID DVNTableModel::headerFont(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x28);
}



// -[DVNTableModel setHeaderFont:], 0x18cfb4
/* Decompiled from supplied 5.2.2 arm package. VA 0x18cfb4. setHeaderFont: */

/* Function Stack Size: 0x18 bytes */

void DVNTableModel::setHeaderFont_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x28,param_3);
  CallSupervisor(0xa9f7);
  return;
}



// -[DVNTableModel footerFont], 0x18cfe8
/* Decompiled from supplied 5.2.2 arm package. VA 0x18cfe8. footerFont */

/* Function Stack Size: 0x10 bytes */

ID DVNTableModel::footerFont(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x30);
}



// -[DVNTableModel setFooterFont:], 0x18cff0
/* Decompiled from supplied 5.2.2 arm package. VA 0x18cff0. setFooterFont: */

/* Function Stack Size: 0x18 bytes */

void DVNTableModel::setFooterFont_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x30,param_3);
  return;
}



// -[DVNTableModel headerAlignment], 0x18cffc
/* Decompiled from supplied 5.2.2 arm package. VA 0x18cffc. headerAlignment */

/* Function Stack Size: 0x10 bytes */

long_long DVNTableModel::headerAlignment(ID param_1,SEL param_2)

{
  return *(long_long *)(param_1 + 0x38);
}



// -[DVNTableModel setHeaderAlignment:], 0x18d004
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d004. setHeaderAlignment: */

/* Function Stack Size: 0x18 bytes */

void DVNTableModel::setHeaderAlignment_(ID param_1,SEL param_2,long_long param_3)

{
  *(long_long *)(param_1 + 0x38) = param_3;
  CallSupervisor(0x82ab);
  return;
}



// -[DVNTableModel footerAlignment], 0x18d024
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d024. footerAlignment */

/* Function Stack Size: 0x10 bytes */

long_long DVNTableModel::footerAlignment(ID param_1,SEL param_2)

{
  return *(long_long *)(param_1 + 0x40);
}



// -[DVNTableModel setFooterAlignment:], 0x18d02c
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d02c. setFooterAlignment: */

/* Function Stack Size: 0x18 bytes */

void DVNTableModel::setFooterAlignment_(ID param_1,SEL param_2,long_long param_3)

{
  *(long_long *)(param_1 + 0x40) = param_3;
  CallSupervisor(0x5c6a);
  return;
}



// -[DVNTableModel showsThanksHeart], 0x18d04c
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d04c. showsThanksHeart */

/* Function Stack Size: 0x10 bytes */

bool DVNTableModel::showsThanksHeart(ID param_1,SEL param_2)

{
  return (bool)*(byte *)(param_1 + 8);
}



// -[DVNTableModel setShowsThanksHeart:], 0x18d054
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d054. setShowsThanksHeart: */

/* Function Stack Size: 0x14 bytes */

void DVNTableModel::setShowsThanksHeart_(ID param_1,SEL param_2,bool param_3)

{
  *(char *)(param_1 + 8) = (char)param_3;
  CallSupervisor(0xd0c5);
  return;
}



// -[DVNTableModel supportsSearching], 0x18d074
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d074. supportsSearching */

/* Function Stack Size: 0x10 bytes */

bool DVNTableModel::supportsSearching(ID param_1,SEL param_2)

{
  return (bool)*(byte *)(param_1 + 9);
}



// -[DVNTableModel setSupportsSearching:], 0x18d07c
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d07c. setSupportsSearching: */

/* Function Stack Size: 0x14 bytes */

void DVNTableModel::setSupportsSearching_(ID param_1,SEL param_2,bool param_3)

{
  *(char *)(param_1 + 9) = (char)param_3;
  CallSupervisor(0xd478);
  return;
}



// -[DVNTableModel sections], 0x18d09c
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d09c. sections */

/* Function Stack Size: 0x10 bytes */

ID DVNTableModel::sections(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x48);
}



// -[DVNTableModel setSections:], 0x18d0a4
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d0a4. setSections: */

/* Function Stack Size: 0x18 bytes */

void DVNTableModel::setSections_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x48,param_3);
  CallSupervisor(0x2dd2);
  return;
}



// -[DVNTableModel viewController], 0x18d0d8
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d0d8. viewController */

/* Function Stack Size: 0x10 bytes */

ID DVNTableModel::viewController(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x50);
}



// -[DVNTableModel setViewController:], 0x18d0e0
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d0e0. setViewController: */

/* Function Stack Size: 0x18 bytes */

void DVNTableModel::setViewController_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x50,param_3);
  CallSupervisor(0xbbe0);
  return;
}



// -[DVNTableModel selfViewController], 0x18d114
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d114. selfViewController */

/* Function Stack Size: 0x10 bytes */

ID DVNTableModel::selfViewController(ID param_1,SEL param_2)

{
  ID IVar1;
  
  _objc_loadWeakRetained(param_1 + 0x58);
  IVar1 = _objc_autoreleaseReturnValue();
  return IVar1;
}



// -[DVNTableModel setSelfViewController:], 0x18d12c
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d12c. setSelfViewController: */

/* Function Stack Size: 0x18 bytes */

void DVNTableModel::setSelfViewController_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeWeak(param_1 + 0x58,param_3);
  return;
}



// -[DVNTableModel .cxx_destruct], 0x18d138
/* Decompiled from supplied 5.2.2 arm package. VA 0x18d138. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void DVNTableModel::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_destroyWeak(param_1 + 0x58);
  _objc_storeStrong(param_1 + 0x50,0);
  _objc_storeStrong(param_1 + 0x48,0);
  _objc_storeStrong(param_1 + 0x30,0);
  _objc_storeStrong(param_1 + 0x28,0);
  _objc_storeStrong(param_1 + 0x20,0);
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  return;
}



// +[DVNTableModel model], 0x18b85c
/* Decompiled from supplied 5.2.2 arm package. VA 0x18b85c. model */

/* Function Stack Size: 0x10 bytes */

ID DVNTableModel::model(ID param_1,SEL param_2)

{
  ID IVar1;
  
  _objc_alloc_init(PTR_DVNTableModel_0114ee88);
  IVar1 = _objc_autoreleaseReturnValue();
  return IVar1;
}



// +[DVNTableModel modelWithTitle:sections:], 0x18b878
/* Decompiled from supplied 5.2.2 arm package. VA 0x18b878. modelWithTitle:sections: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableModel::modelWithTitle_sections_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  _objc_retain(param_4);
  puVar1 = PTR_DVNTableModel_0114ee88;
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  if (param_4 != 0) {
    _objc_msgSend(uVar2,@selector(setSections:),param_4);
  }
  _objc_release(param_4);
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return IVar3;
}



// +[DVNTableModel modelWithTitle:header:footer:sections:], 0x18b950
/* Decompiled from supplied 5.2.2 arm package. VA 0x18b950. modelWithTitle:header:footer:sections: */

/* Function Stack Size: 0x30 bytes */

ID DVNTableModel::modelWithTitle_header_footer_sections_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  _objc_retain(param_6);
  puVar1 = PTR_DVNTableModel_0114ee88;
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setHeader:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setFooter:),param_5);
  _objc_release(param_5);
  if (param_6 != 0) {
    _objc_msgSend(uVar2,@selector(setSections:),param_6);
  }
  _objc_release(param_6);
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return IVar3;
}



// +[DVNTableModel modelWithTitle:header:footer:viewController:], 0x18ba80
/* Decompiled from supplied 5.2.2 arm package. VA 0x18ba80. modelWithTitle:header:footer:viewController: */

/* Function Stack Size: 0x30 bytes */

ID DVNTableModel::modelWithTitle_header_footer_viewController_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  _objc_retain(param_6);
  puVar1 = PTR_DVNTableModel_0114ee88;
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setHeader:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setFooter:),param_5);
  _objc_release(param_5);
  if (param_6 != 0) {
    _objc_msgSend(uVar2,@selector(setViewController:),param_6);
  }
  _objc_release(param_6);
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return IVar3;
}


