/* Decompiled from supplied 5.2.2 arm package. VA 0x277ca4. FUN_00277ca4 */

void FUN_00277ca4(long param_1,long param_2,long param_3,ulong param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  long lVar11;
  int iVar12;
  code *pcVar13;
  long lVar14;
  ulong uVar15;
  int *piVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  long lVar24;
  long lVar25;
  long lVar26;
  int iVar27;
  long lVar28;
  long lVar29;
  int local_90 [10];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar7 = *(uint *)(param_1 + 4);
  lVar24 = (long)(int)uVar7;
  lVar25 = *(long *)(param_1 + 0x10);
  piVar10 = *(int **)(param_1 + 0x20);
  iVar19 = uVar7 * 5;
  iVar18 = uVar7 * 0xf + -1;
  pcVar13 = *(code **)(&DAT_0106d4b8 + (long)(0x1f - (int)LZCOUNT(uVar7 | 1)) * 8);
  piVar16 = piVar10;
  for (lVar11 = 0; lVar11 < lVar24; lVar11 = lVar11 + 1) {
    piVar9 = piVar16;
    for (lVar14 = 0; lVar14 != 0x28; lVar14 = lVar14 + 8) {
      iVar8 = *piVar9;
      iVar6 = *(int *)(param_3 + (long)(iVar8 + iVar19) * 4);
      if (iVar8 < iVar19) {
        iVar6 = (0x20 - iVar6) + *(int *)(param_3 + (long)((iVar19 + -1) - iVar8) * 4);
        iVar12 = (0x20 - *(int *)(param_3 + (long)(int)(iVar8 + uVar7 * 0xf) * 4)) -
                 *(int *)(param_3 + (long)(iVar18 - iVar8) * 4);
      }
      else {
        iVar6 = (0x20 - iVar6) - *(int *)(param_3 + (long)(int)((uVar7 * 0x19 + -1) - iVar8) * 4);
        iVar12 = (*(int *)(param_3 + (long)(int)(iVar8 + uVar7 * -5) * 4) + 0x20) -
                 *(int *)(param_3 + (long)(iVar18 - iVar8) * 4);
      }
      piVar1 = (int *)(lVar25 + (long)(iVar8 >> 1) * 8);
      lVar26 = (long)*piVar1;
      lVar28 = (long)piVar1[1];
      *(int *)((long)local_90 + lVar14 + 4) =
           (int)((ulong)((lVar26 * (iVar6 >> 6) + 0x40000000) - lVar28 * (iVar12 >> 6)) >> 0x1f);
      *(int *)((long)local_90 + lVar14) =
           (int)(lVar26 * (iVar12 >> 6) + lVar28 * (iVar6 >> 6) + 0x40000000U >> 0x1f);
      piVar9 = piVar9 + 1;
    }
    iVar8 = local_90[8] + local_90[2];
    iVar6 = local_90[9] + local_90[3];
    iVar12 = local_90[6] + local_90[4];
    iVar2 = local_90[7] + local_90[5];
    piVar9 = (int *)(*(long *)(param_1 + 0x18) +
                    (long)*(int *)(*(long *)(param_1 + 0x28) + lVar11 * 4) * 8);
    *piVar9 = iVar12 + iVar8 + local_90[0];
    piVar9[1] = iVar2 + iVar6 + local_90[1];
    lVar28 = (long)(int)DAT_01af77b0;
    lVar29 = (long)(int)DAT_01af77b8;
    lVar14 = DAT_01af77b0 >> 0x20;
    lVar26 = DAT_01af77b8 >> 0x20;
    iVar27 = (int)((ulong)((lVar14 * (local_90[5] - local_90[7]) + 0x40000000) -
                          lVar26 * (local_90[3] - local_90[9])) >> 0x1f);
    iVar21 = (int)((ulong)((lVar28 * iVar12 + 0x40000000) - lVar29 * iVar8) >> 0x1f);
    iVar20 = (int)((ulong)((lVar28 * iVar2 + 0x40000000) - lVar29 * iVar6) >> 0x1f);
    iVar23 = (int)((ulong)((lVar14 * (local_90[4] - local_90[6]) + 0x40000000) -
                          lVar26 * (local_90[2] - local_90[8])) >> 0x1f);
    iVar12 = (int)((ulong)((lVar28 * iVar8 + 0x40000000) - lVar29 * iVar12) >> 0x1f);
    iVar22 = (int)(lVar26 * (local_90[5] - local_90[7]) + lVar14 * (local_90[3] - local_90[9]) +
                   0x40000000U >> 0x1f);
    iVar17 = (int)(lVar26 * (local_90[4] - local_90[6]) + lVar14 * (local_90[2] - local_90[8]) +
                   0x40000000U >> 0x1f);
    iVar8 = (int)((ulong)((lVar28 * iVar6 + 0x40000000) - lVar29 * iVar2) >> 0x1f);
    piVar9[lVar24 * 2] = iVar22 + local_90[0] + iVar12;
    (piVar9 + lVar24 * 2)[1] = (local_90[1] - iVar17) + iVar8;
    piVar9[lVar24 * 4] = (local_90[0] - iVar27) + iVar21;
    (piVar9 + lVar24 * 4)[1] = iVar20 + iVar23 + local_90[1];
    piVar9[lVar24 * 6] = iVar21 + iVar27 + local_90[0];
    (piVar9 + lVar24 * 6)[1] = (iVar20 - iVar23) + local_90[1];
    piVar9[lVar24 * 8] = (iVar12 - iVar22) + local_90[0];
    (piVar9 + lVar24 * 8)[1] = iVar8 + iVar17 + local_90[1];
    piVar16 = piVar16 + 5;
  }
  uVar3 = iVar19 >> 1;
  param_4 = param_4 >> 2;
  lVar14 = 6;
  lVar11 = 0;
  while (lVar14 = lVar14 + -1, lVar14 != 0) {
    (*pcVar13)(*(long *)(param_1 + 0x18) + lVar11);
    lVar11 = lVar11 + lVar24 * 8;
  }
  uVar15 = -(ulong)(uVar3 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar3 << 3;
  lVar14 = lVar25 + -4;
  iVar18 = uVar3 * 2;
  lVar25 = lVar25 + 4;
  lVar26 = -4;
  lVar11 = (long)(int)uVar3 + (long)(int)(uVar7 * 5);
  iVar19 = iVar18;
  for (lVar24 = 0; iVar19 = iVar19 + -2, lVar24 < (int)uVar3; lVar24 = lVar24 + 1) {
    piVar16 = (int *)(lVar25 + uVar15);
    piVar9 = (int *)(*(long *)(param_1 + 0x18) + (long)piVar10[lVar11 + lVar24] * 8);
    lVar28 = (long)*piVar9;
    lVar4 = (long)piVar9[1];
    piVar9 = (int *)(*(long *)(param_1 + 0x18) +
                    (long)*(int *)((long)piVar10 + lVar26 + lVar11 * 4) * 8);
    lVar29 = (long)*piVar9;
    lVar5 = (long)piVar9[1];
    *(int *)(param_2 + ((long)iVar19 * param_4 + param_4) * 4) =
         (int)((ulong)((*piVar16 * lVar28 + 0x40000000) - piVar16[-1] * lVar4) >> 0x1f);
    piVar9 = (int *)(lVar14 + uVar15);
    lVar14 = lVar14 + -8;
    *(int *)(param_2 + (long)iVar18 * param_4 * 4) =
         (int)(*piVar16 * lVar4 + piVar16[-1] * lVar28 + 0x40000000U >> 0x1f);
    *(int *)(param_2 + ((long)iVar18 * param_4 + param_4) * 4) =
         (int)((ulong)((*piVar9 * lVar29 + 0x40000000) - piVar9[-1] * lVar5) >> 0x1f);
    lVar26 = lVar26 + -4;
    iVar18 = iVar18 + 2;
    *(int *)(param_2 + (long)iVar19 * param_4 * 4) =
         (int)(*piVar9 * lVar5 + piVar9[-1] * lVar29 + 0x40000000U >> 0x1f);
    lVar25 = lVar25 + 8;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


