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
  _objc_msgSend(param_1,PTR_s_sections_0114d240);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  lVar9 = _objc_msgSend(uVar8,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&local_1c0,auStack_f0,
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
  puVar18 = PTR_s_cells_0114d290;
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
        puVar4 = PTR_s_subtitle_0114d1e8;
        puVar3 = PTR_s_title_0114c7f0;
        puVar1 = PTR_s_containsString__0114af08;
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
      puVar18 = PTR_s_cells_0114d290;
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


