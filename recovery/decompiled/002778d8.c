/* Decompiled from supplied 5.2.2 arm package. VA 0x2778d8. FUN_002778d8 */

void FUN_002778d8(long param_1,long param_2,long param_3,ulong param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  long lVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  int iVar13;
  code *pcVar14;
  int iVar15;
  long lVar16;
  undefined4 *puVar17;
  int iVar18;
  long lVar19;
  int iVar20;
  long lVar21;
  long lVar22;
  int iVar23;
  long lVar24;
  long lVar25;
  int local_90 [10];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  param_4 = param_4 >> 2;
  uVar4 = *(uint *)(param_1 + 4);
  lVar22 = (long)(int)uVar4;
  lVar19 = *(long *)(param_1 + 0x10);
  piVar5 = *(int **)(param_1 + 0x20);
  pcVar14 = *(code **)(&DAT_0106d4b8 + (long)(0x1f - (int)LZCOUNT(uVar4 | 1)) * 8);
  piVar6 = piVar5;
  for (lVar12 = 0; lVar12 < lVar22; lVar12 = lVar12 + 1) {
    piVar8 = piVar6;
    for (lVar7 = 0; lVar7 != 0x28; lVar7 = lVar7 + 8) {
      iVar13 = *piVar8;
      piVar1 = (int *)(lVar19 + (long)(iVar13 >> 1) * 8);
      lVar16 = (long)*(int *)(param_3 + (long)(int)(uVar4 * 10 + -1) * param_4 * 4 +
                             (long)iVar13 * param_4 * -4);
      lVar21 = (long)*piVar1;
      lVar24 = (long)piVar1[1];
      lVar25 = (long)*(int *)(param_3 + (long)iVar13 * param_4 * 4);
      *(int *)((long)local_90 + lVar7) =
           (int)((ulong)((lVar21 * lVar16 + 0x40000000) - lVar24 * lVar25) >> 0x1f);
      *(int *)((long)local_90 + lVar7 + 4) =
           (int)(lVar21 * lVar25 + lVar24 * lVar16 + 0x40000000U >> 0x1f);
      piVar8 = piVar8 + 1;
    }
    iVar13 = local_90[8] + local_90[2];
    iVar18 = local_90[9] + local_90[3];
    iVar9 = local_90[6] + local_90[4];
    iVar3 = local_90[7] + local_90[5];
    piVar8 = (int *)(*(long *)(param_1 + 0x18) +
                    (long)*(int *)(*(long *)(param_1 + 0x28) + lVar12 * 4) * 8);
    *piVar8 = iVar9 + iVar13 + local_90[0];
    piVar8[1] = iVar3 + iVar18 + local_90[1];
    lVar7 = (long)(int)DAT_01af77b0;
    lVar24 = (long)(int)DAT_01af77b8;
    lVar21 = DAT_01af77b0 >> 0x20;
    lVar25 = DAT_01af77b8 >> 0x20;
    iVar20 = (int)((ulong)((lVar21 * (local_90[5] - local_90[7]) + 0x40000000) -
                          lVar25 * (local_90[3] - local_90[9])) >> 0x1f);
    iVar15 = (int)((ulong)((lVar7 * iVar9 + 0x40000000) - lVar24 * iVar13) >> 0x1f);
    iVar11 = (int)((ulong)((lVar7 * iVar3 + 0x40000000) - lVar24 * iVar18) >> 0x1f);
    iVar23 = (int)((ulong)((lVar21 * (local_90[4] - local_90[6]) + 0x40000000) -
                          lVar25 * (local_90[2] - local_90[8])) >> 0x1f);
    iVar9 = (int)((ulong)((lVar7 * iVar13 + 0x40000000) - lVar24 * iVar9) >> 0x1f);
    iVar10 = (int)(lVar25 * (local_90[5] - local_90[7]) + lVar21 * (local_90[3] - local_90[9]) +
                   0x40000000U >> 0x1f);
    iVar13 = (int)(lVar25 * (local_90[4] - local_90[6]) + lVar21 * (local_90[2] - local_90[8]) +
                   0x40000000U >> 0x1f);
    iVar18 = (int)((ulong)((lVar7 * iVar18 + 0x40000000) - lVar24 * iVar3) >> 0x1f);
    piVar8[lVar22 * 2] = iVar10 + local_90[0] + iVar9;
    (piVar8 + lVar22 * 2)[1] = (local_90[1] - iVar13) + iVar18;
    piVar8[lVar22 * 4] = (local_90[0] - iVar20) + iVar15;
    (piVar8 + lVar22 * 4)[1] = iVar11 + iVar23 + local_90[1];
    piVar8[lVar22 * 6] = iVar15 + iVar20 + local_90[0];
    (piVar8 + lVar22 * 6)[1] = (iVar11 - iVar23) + local_90[1];
    (piVar8 + lVar22 * 8)[1] = iVar18 + iVar13 + local_90[1];
    piVar8[lVar22 * 8] = (iVar9 - iVar10) + local_90[0];
    piVar6 = piVar6 + 5;
  }
  iVar13 = (int)(uVar4 * 5) >> 1;
  lVar7 = 6;
  lVar12 = 0;
  while (lVar7 = lVar7 + -1, lVar7 != 0) {
    (*pcVar14)(*(long *)(param_1 + 0x18) + lVar12);
    lVar12 = lVar12 + lVar22 * 8;
  }
  lVar7 = (long)iVar13;
  puVar17 = (undefined4 *)(param_2 + (long)iVar13 * 8 + 4);
  piVar6 = (int *)(lVar19 + (long)iVar13 * 8 + 4);
  for (lVar12 = 0; iVar13 = iVar13 + -1, lVar12 < lVar7; lVar12 = lVar12 + 1) {
    piVar8 = (int *)(lVar19 + (long)iVar13 * 8);
    iVar18 = piVar8[1];
    piVar1 = (int *)(*(long *)(param_1 + 0x18) + (long)piVar5[lVar22 * 5 + (long)iVar13] * 8);
    lVar21 = (long)*piVar1;
    lVar25 = (long)piVar1[1];
    puVar2 = (undefined4 *)(param_2 + (long)iVar13 * 8);
    piVar1 = (int *)(*(long *)(param_1 + 0x18) + (long)piVar5[lVar7 + (int)(uVar4 * 5) + lVar12] * 8
                    );
    lVar24 = (long)*piVar1;
    lVar16 = (long)piVar1[1];
    *puVar2 = (int)((ulong)((iVar18 * lVar25 + 0x40000000) - *piVar8 * lVar21) >> 0x1f);
    *puVar17 = (int)(iVar18 * lVar21 + *piVar8 * lVar25 + 0x40000000U >> 0x1f);
    iVar18 = *piVar6;
    puVar17[-1] = (int)((ulong)((iVar18 * lVar16 + 0x40000000) - piVar6[-1] * lVar24) >> 0x1f);
    puVar17 = puVar17 + 2;
    puVar2[1] = (int)(iVar18 * lVar24 + piVar6[-1] * lVar16 + 0x40000000U >> 0x1f);
    piVar6 = piVar6 + 2;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


