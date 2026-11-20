/* Decompiled from supplied 5.2.2 arm package. VA 0x26dcd0. _ff_tx_gen_compound_mapping */

void _ff_tx_gen_compound_mapping(ulong *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  int *piVar8;
  undefined8 uVar9;
  ulong uVar10;
  long lVar11;
  int *piVar12;
  int *piVar13;
  long lVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  int iVar18;
  int iVar19;
  long lVar20;
  long lVar21;
  long lVar22;
  int iVar23;
  ulong uVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined4 uStack_88;
  undefined4 local_84;
  undefined4 uStack_80;
  undefined8 uStack_7c;
  long local_68;
  
  lVar22 = *(long *)PTR____stack_chk_guard_01060708;
  uVar24 = *param_1;
  uVar6 = param_1[1];
  iVar23 = (int)uVar24;
  iVar25 = (int)(uVar24 >> 0x20);
  iVar18 = iVar25 * iVar23;
  iVar26 = 0;
  if (iVar23 != 0) {
    iVar26 = iVar25 / iVar23;
  }
  iVar27 = 1;
  while( true ) {
    local_68 = lVar22;
    if (iVar23 <= iVar27) goto LAB_0026df94;
    iVar16 = iVar27 * (iVar25 - iVar26 * iVar23);
    iVar15 = 0;
    if (iVar23 != 0) {
      iVar15 = iVar16 / iVar23;
    }
    if (iVar16 - iVar15 * iVar23 == 1) break;
    iVar27 = iVar27 + 1;
  }
  iVar26 = 0;
  if (iVar25 != 0) {
    iVar26 = iVar23 / iVar25;
  }
  iVar15 = iVar23 - iVar26 * iVar25;
  iVar16 = iVar15;
  for (iVar26 = 1; iVar26 < iVar25; iVar26 = iVar26 + 1) {
    iVar2 = 0;
    if (iVar25 != 0) {
      iVar2 = iVar16 / iVar25;
    }
    if (iVar16 - iVar2 * iVar25 == 1) {
      uVar7 = _ff_tx_type_is_mdct(*(undefined4 *)((long)param_1 + 0xc));
      piVar8 = (int *)_av_malloc(-(ulong)((uint)(iVar18 * 2) >> 0x1f) & 0xfffffffc00000000 |
                                 (ulong)(uint)(iVar18 * 2) << 2);
      param_1[4] = (ulong)piVar8;
      if (piVar8 == (int *)0x0) {
        uVar9 = 0xfffffff4;
      }
      else {
        iVar15 = 0;
        lVar14 = (long)iVar23;
        piVar17 = piVar8;
        for (iVar16 = 0; iVar16 != iVar25; iVar16 = iVar16 + 1) {
          lVar20 = 0;
          piVar12 = piVar17;
          iVar2 = iVar15;
          for (uVar10 = uVar24 & 0xffffffff; (int)uVar10 != 0; uVar10 = (ulong)((int)uVar10 - 1)) {
            iVar3 = 0;
            if (iVar18 != 0) {
              iVar3 = iVar2 / iVar18;
            }
            iVar19 = (int)lVar20;
            iVar1 = iVar16 * iVar23 * iVar26 + iVar19 * iVar27;
            lVar20 = lVar20 + ((long)uVar24 >> 0x20);
            iVar3 = iVar2 - iVar3 * iVar18;
            iVar4 = 0;
            if (iVar18 != 0) {
              iVar4 = iVar1 / iVar18;
            }
            iVar2 = iVar2 + iVar25;
            *piVar12 = iVar3 << (ulong)(uVar7 & 0x1f);
            piVar8[(long)iVar18 + (long)(iVar1 - iVar4 * iVar18)] = iVar16 + iVar19;
            piVar12 = piVar12 + 1;
          }
          piVar17 = piVar17 + lVar14;
          iVar15 = iVar15 + iVar23;
        }
        if ((int)uVar6 != 0) {
          piVar17 = piVar8 + 1;
          for (lVar20 = 0; (int)lVar20 != iVar25; lVar20 = lVar20 + 1) {
            lVar5 = lVar20 * lVar14 * 4 + 4;
            lVar11 = (uVar24 << 0x20) + -0x200000000;
            piVar12 = piVar17;
            for (lVar21 = 0; lVar21 < iVar23 + -1 >> 1; lVar21 = lVar21 + 1) {
              iVar18 = *(int *)((long)piVar8 + (lVar11 >> 0x1e) + lVar5);
              *(int *)((long)piVar8 + (lVar11 >> 0x1e) + lVar5) = *piVar12;
              *piVar12 = iVar18;
              lVar11 = lVar11 + -0x100000000;
              piVar12 = piVar12 + 1;
            }
            piVar17 = piVar17 + lVar14;
          }
        }
        if (iVar23 == 0xf) {
          piVar17 = piVar8;
          for (lVar14 = 0; lVar14 < (long)uVar24 >> 0x20; lVar14 = lVar14 + 1) {
            iVar18 = 0;
            lVar20 = 0;
            piVar12 = piVar8 + lVar14 * 0xf;
            uStack_7c = *(undefined8 *)(piVar12 + 0xd);
            uStack_80 = (undefined4)((ulong)*(undefined8 *)(piVar12 + 0xb) >> 0x20);
            uStack_98 = *(undefined8 *)(piVar12 + 6);
            local_a0 = *(undefined8 *)(piVar12 + 4);
            uStack_88 = (undefined4)*(undefined8 *)(piVar12 + 10);
            local_84 = (undefined4)((ulong)*(undefined8 *)(piVar12 + 10) >> 0x20);
            uStack_90 = *(undefined8 *)(piVar12 + 8);
            uStack_a8 = *(undefined8 *)(piVar12 + 2);
            local_b0 = *(undefined8 *)piVar12;
            piVar12 = piVar17;
            while( true ) {
              lVar21 = 3;
              piVar13 = piVar12;
              iVar26 = iVar18;
              if (lVar20 == 5) break;
              for (; lVar21 != 0; lVar21 = lVar21 + -1) {
                iVar23 = iVar26 % 0xf;
                iVar26 = iVar26 + 5;
                *piVar13 = *(int *)((long)&local_b0 + (long)iVar23 * 4);
                piVar13 = piVar13 + 1;
              }
              lVar20 = lVar20 + 1;
              piVar12 = piVar12 + 3;
              iVar18 = iVar18 + 3;
            }
            piVar17 = piVar17 + 0xf;
          }
        }
        uVar9 = 0;
      }
      if (lVar22 == local_68) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail(uVar9);
    }
    iVar16 = iVar16 + iVar15;
  }
LAB_0026df94:
  _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
  _abort();
}


