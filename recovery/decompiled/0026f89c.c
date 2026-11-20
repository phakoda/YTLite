/* Decompiled from supplied 5.2.2 arm package. VA 0x26f89c. FUN_0026f89c */

void FUN_0026f89c(long param_1,long param_2,long param_3,ulong param_4)

{
  double *pdVar1;
  double *pdVar2;
  double *pdVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  long lVar9;
  int *piVar10;
  long lVar11;
  ulong uVar12;
  int iVar13;
  int iVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  code *pcVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double local_b8 [10];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar6 = *(uint *)(param_1 + 4);
  lVar16 = (long)(int)uVar6;
  lVar17 = *(long *)(param_1 + 0x10);
  piVar7 = *(int **)(param_1 + 0x20);
  iVar14 = uVar6 * 5;
  iVar13 = uVar6 * 0xf + -1;
  pcVar18 = *(code **)(&DAT_0106d398 + (long)(0x1f - (int)LZCOUNT(uVar6 | 1)) * 8);
  piVar8 = piVar7;
  for (lVar11 = 0; lVar11 < lVar16; lVar11 = lVar11 + 1) {
    piVar10 = piVar8;
    for (lVar9 = 0; lVar9 != 0x50; lVar9 = lVar9 + 0x10) {
      iVar5 = *piVar10;
      if (iVar5 < iVar14) {
        dVar23 = *(double *)(param_3 + (long)(int)(iVar5 + uVar6 * 0xf) * 8);
        dVar21 = *(double *)(param_3 + (long)((iVar14 + -1) - iVar5) * 8);
        dVar19 = -*(double *)(param_3 + (long)(iVar13 - iVar5) * 8);
      }
      else {
        dVar19 = *(double *)(param_3 + (long)(int)(iVar5 + uVar6 * -5) * 8);
        dVar23 = *(double *)(param_3 + (long)(iVar13 - iVar5) * 8);
        dVar21 = -*(double *)(param_3 + (long)(int)((uVar6 * 0x19 + -1) - iVar5) * 8);
      }
      dVar21 = dVar21 - *(double *)(param_3 + (long)(iVar5 + iVar14) * 8);
      pdVar1 = (double *)(lVar17 + (long)(iVar5 >> 1) * 0x10);
      dVar20 = *pdVar1;
      dVar22 = pdVar1[1];
      *(double *)((long)local_b8 + lVar9) = dVar21 * dVar22 + (dVar19 - dVar23) * dVar20;
      *(double *)((long)local_b8 + lVar9 + 8) = dVar21 * dVar20 - (dVar19 - dVar23) * dVar22;
      piVar10 = piVar10 + 1;
    }
    dVar21 = local_b8[2] + local_b8[8];
    dVar19 = local_b8[3] + local_b8[9];
    dVar23 = local_b8[4] + local_b8[6];
    pdVar1 = (double *)
             (*(long *)(param_1 + 0x18) +
             (long)*(int *)(*(long *)(param_1 + 0x28) + lVar11 * 4) * 0x10);
    *pdVar1 = dVar23 + dVar21 + local_b8[0];
    dVar20 = local_b8[5] + local_b8[7];
    pdVar1[1] = dVar20 + dVar19 + local_b8[1];
    dVar22 = dVar23 * DAT_019d3720;
    dVar27 = dVar21 * DAT_019d3730;
    dVar28 = dVar20 * DAT_019d3720;
    dVar29 = dVar19 * DAT_019d3730;
    dVar24 = (local_b8[5] - local_b8[7]) * DAT_019d3728;
    dVar26 = (local_b8[3] - local_b8[9]) * DAT_019d3738;
    dVar30 = (local_b8[4] - local_b8[6]) * DAT_019d3728;
    dVar25 = (local_b8[2] - local_b8[8]) * DAT_019d3738;
    dVar21 = dVar21 * DAT_019d3720 - dVar23 * DAT_019d3730;
    dVar19 = dVar19 * DAT_019d3720 - dVar20 * DAT_019d3730;
    dVar23 = (local_b8[3] - local_b8[9]) * DAT_019d3728 + (local_b8[5] - local_b8[7]) * DAT_019d3738
    ;
    dVar20 = (local_b8[2] - local_b8[8]) * DAT_019d3728 + (local_b8[4] - local_b8[6]) * DAT_019d3738
    ;
    pdVar1[lVar16 * 2] = local_b8[0] + dVar21 + dVar23;
    (pdVar1 + lVar16 * 2)[1] = local_b8[1] + (dVar19 - dVar20);
    dVar22 = dVar22 - dVar27;
    dVar28 = dVar28 - dVar29;
    dVar24 = dVar24 - dVar26;
    dVar30 = dVar30 - dVar25;
    pdVar1[lVar16 * 4] = (dVar22 - dVar24) + local_b8[0];
    (pdVar1 + lVar16 * 4)[1] = dVar28 + dVar30 + local_b8[1];
    pdVar1[lVar16 * 6] = dVar22 + dVar24 + local_b8[0];
    (pdVar1 + lVar16 * 6)[1] = (dVar28 - dVar30) + local_b8[1];
    pdVar1[lVar16 * 8] = (dVar21 - dVar23) + local_b8[0];
    (pdVar1 + lVar16 * 8)[1] = dVar19 + dVar20 + local_b8[1];
    piVar8 = piVar8 + 5;
  }
  uVar4 = iVar14 >> 1;
  param_4 = param_4 >> 3;
  lVar9 = 6;
  lVar11 = 0;
  while (lVar9 = lVar9 + -1, lVar9 != 0) {
    (*pcVar18)(*(long *)(param_1 + 0x18) + lVar11);
    lVar11 = lVar11 + lVar16 * 0x10;
  }
  uVar12 = -(ulong)(uVar4 >> 0x1f) & 0xfffffff000000000 | (ulong)uVar4 << 4;
  lVar9 = lVar17 + -8;
  iVar13 = uVar4 * 2;
  lVar17 = lVar17 + 8;
  lVar11 = (long)(int)uVar4 + (long)(int)(uVar6 * 5);
  lVar15 = -4;
  iVar14 = iVar13;
  for (lVar16 = 0; iVar14 = iVar14 + -2, lVar16 < (int)uVar4; lVar16 = lVar16 + 1) {
    pdVar1 = (double *)
             (*(long *)(param_1 + 0x18) + (long)*(int *)((long)piVar7 + lVar15 + lVar11 * 4) * 0x10)
    ;
    pdVar2 = (double *)(*(long *)(param_1 + 0x18) + (long)piVar7[lVar11 + lVar16] * 0x10);
    pdVar3 = (double *)(lVar17 + uVar12);
    dVar21 = *pdVar2;
    dVar19 = pdVar2[1];
    dVar23 = *pdVar1;
    dVar20 = pdVar1[1];
    *(double *)(param_2 + ((long)iVar14 * param_4 + param_4) * 8) =
         dVar21 * *pdVar3 - dVar19 * pdVar3[-1];
    pdVar1 = (double *)(lVar9 + uVar12);
    lVar9 = lVar9 + -0x10;
    *(double *)(param_2 + (long)iVar13 * param_4 * 8) = dVar21 * pdVar3[-1] + dVar19 * *pdVar3;
    *(double *)(param_2 + ((long)iVar13 * param_4 + param_4) * 8) =
         dVar23 * *pdVar1 - dVar20 * pdVar1[-1];
    lVar15 = lVar15 + -4;
    iVar13 = iVar13 + 2;
    *(double *)(param_2 + (long)iVar14 * param_4 * 8) = dVar23 * pdVar1[-1] + dVar20 * *pdVar1;
    lVar17 = lVar17 + 0x10;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


