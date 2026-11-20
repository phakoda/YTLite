/* Decompiled from supplied 5.2.2 arm package. VA 0x26f52c. FUN_0026f52c */

void FUN_0026f52c(long param_1,long param_2,long param_3,ulong param_4)

{
  double *pdVar1;
  double *pdVar2;
  uint uVar3;
  long lVar4;
  int *piVar5;
  int *piVar6;
  long lVar7;
  int iVar8;
  double *pdVar9;
  double *pdVar10;
  int *piVar11;
  long lVar12;
  long lVar13;
  code *pcVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double local_b8 [10];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  param_4 = param_4 >> 3;
  uVar3 = *(uint *)(param_1 + 4);
  lVar13 = (long)(int)uVar3;
  lVar12 = *(long *)(param_1 + 0x10);
  piVar6 = *(int **)(param_1 + 0x20);
  pcVar14 = *(code **)(&DAT_0106d398 + (long)(0x1f - (int)LZCOUNT(uVar3 | 1)) * 8);
  piVar11 = piVar6;
  for (lVar7 = 0; lVar7 < lVar13; lVar7 = lVar7 + 1) {
    piVar5 = piVar11;
    for (lVar4 = 0; lVar4 != 0x50; lVar4 = lVar4 + 0x10) {
      iVar8 = *piVar5;
      dVar15 = *(double *)
                (param_3 + (long)(int)(uVar3 * 10 + -1) * param_4 * 8 + (long)iVar8 * param_4 * -8);
      dVar16 = *(double *)(param_3 + (long)iVar8 * param_4 * 8);
      pdVar9 = (double *)(lVar12 + (long)(iVar8 >> 1) * 0x10);
      dVar17 = *pdVar9;
      dVar18 = pdVar9[1];
      *(double *)((long)local_b8 + lVar4) = dVar15 * dVar17 - dVar16 * dVar18;
      *(double *)((long)local_b8 + lVar4 + 8) = dVar15 * dVar18 + dVar16 * dVar17;
      piVar5 = piVar5 + 1;
    }
    dVar15 = local_b8[2] + local_b8[8];
    dVar16 = local_b8[3] + local_b8[9];
    dVar17 = local_b8[4] + local_b8[6];
    pdVar9 = (double *)
             (*(long *)(param_1 + 0x18) +
             (long)*(int *)(*(long *)(param_1 + 0x28) + lVar7 * 4) * 0x10);
    *pdVar9 = dVar17 + dVar15 + local_b8[0];
    dVar18 = local_b8[5] + local_b8[7];
    pdVar9[1] = dVar18 + dVar16 + local_b8[1];
    dVar22 = dVar17 * DAT_019d3720;
    dVar23 = dVar15 * DAT_019d3730;
    dVar24 = dVar18 * DAT_019d3720;
    dVar25 = dVar16 * DAT_019d3730;
    dVar19 = (local_b8[5] - local_b8[7]) * DAT_019d3728;
    dVar21 = (local_b8[3] - local_b8[9]) * DAT_019d3738;
    dVar26 = (local_b8[4] - local_b8[6]) * DAT_019d3728;
    dVar20 = (local_b8[2] - local_b8[8]) * DAT_019d3738;
    dVar15 = dVar15 * DAT_019d3720 - dVar17 * DAT_019d3730;
    dVar16 = dVar16 * DAT_019d3720 - dVar18 * DAT_019d3730;
    dVar17 = (local_b8[3] - local_b8[9]) * DAT_019d3728 + (local_b8[5] - local_b8[7]) * DAT_019d3738
    ;
    dVar18 = (local_b8[2] - local_b8[8]) * DAT_019d3728 + (local_b8[4] - local_b8[6]) * DAT_019d3738
    ;
    pdVar9[lVar13 * 2] = local_b8[0] + dVar15 + dVar17;
    (pdVar9 + lVar13 * 2)[1] = local_b8[1] + (dVar16 - dVar18);
    dVar22 = dVar22 - dVar23;
    dVar24 = dVar24 - dVar25;
    dVar19 = dVar19 - dVar21;
    dVar26 = dVar26 - dVar20;
    pdVar9[lVar13 * 4] = (dVar22 - dVar19) + local_b8[0];
    (pdVar9 + lVar13 * 4)[1] = dVar24 + dVar26 + local_b8[1];
    pdVar9[lVar13 * 6] = dVar22 + dVar19 + local_b8[0];
    (pdVar9 + lVar13 * 6)[1] = (dVar24 - dVar26) + local_b8[1];
    pdVar9[lVar13 * 8] = (dVar15 - dVar17) + local_b8[0];
    (pdVar9 + lVar13 * 8)[1] = dVar16 + dVar18 + local_b8[1];
    piVar11 = piVar11 + 5;
  }
  iVar8 = (int)(uVar3 * 5) >> 1;
  lVar4 = 6;
  lVar7 = 0;
  while (lVar4 = lVar4 + -1, lVar4 != 0) {
    (*pcVar14)(*(long *)(param_1 + 0x18) + lVar7);
    lVar7 = lVar7 + lVar13 * 0x10;
  }
  lVar4 = (long)iVar8;
  pdVar9 = (double *)(param_2 + (long)iVar8 * 0x10 + 8);
  pdVar10 = (double *)(lVar12 + (long)iVar8 * 0x10 + 8);
  for (lVar7 = 0; iVar8 = iVar8 + -1, lVar7 < lVar4; lVar7 = lVar7 + 1) {
    pdVar1 = (double *)(*(long *)(param_1 + 0x18) + (long)piVar6[lVar13 * 5 + (long)iVar8] * 0x10);
    pdVar2 = (double *)
             (*(long *)(param_1 + 0x18) + (long)piVar6[lVar4 + (int)(uVar3 * 5) + lVar7] * 0x10);
    dVar15 = *pdVar1;
    dVar16 = pdVar1[1];
    pdVar1 = (double *)(lVar12 + (long)iVar8 * 0x10);
    dVar17 = pdVar1[1];
    dVar18 = *pdVar2;
    dVar22 = pdVar2[1];
    pdVar2 = (double *)(param_2 + (long)iVar8 * 0x10);
    *pdVar2 = dVar16 * dVar17 - dVar15 * *pdVar1;
    *pdVar9 = dVar16 * *pdVar1 + dVar15 * dVar17;
    dVar15 = *pdVar10;
    pdVar9[-1] = dVar22 * dVar15 - dVar18 * pdVar10[-1];
    pdVar9 = pdVar9 + 2;
    pdVar2[1] = dVar22 * pdVar10[-1] + dVar18 * dVar15;
    pdVar10 = pdVar10 + 2;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


