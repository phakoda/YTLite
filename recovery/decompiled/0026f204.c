/* Decompiled from supplied 5.2.2 arm package. VA 0x26f204. FUN_0026f204 */

void FUN_0026f204(long param_1,long param_2,long param_3,ulong param_4)

{
  double *pdVar1;
  double *pdVar2;
  double *pdVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  int *piVar8;
  long lVar9;
  ulong uVar10;
  int iVar11;
  int iVar12;
  long lVar13;
  int *piVar14;
  int *piVar15;
  long lVar16;
  long lVar17;
  code *pcVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double local_98 [6];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar6 = *(uint *)(param_1 + 4);
  lVar17 = (long)(int)uVar6;
  lVar16 = *(long *)(param_1 + 0x10);
  piVar14 = *(int **)(param_1 + 0x20);
  iVar12 = uVar6 * 3;
  iVar11 = uVar6 * 9 + -1;
  pcVar18 = *(code **)(&DAT_0106d398 + (long)(0x1f - (int)LZCOUNT(uVar6 | 1)) * 8);
  piVar15 = piVar14;
  for (lVar9 = 0; lVar9 < lVar17; lVar9 = lVar9 + 1) {
    piVar8 = piVar15;
    for (lVar7 = 0; lVar7 != 0x30; lVar7 = lVar7 + 0x10) {
      iVar5 = *piVar8;
      if (iVar5 < iVar12) {
        dVar23 = *(double *)(param_3 + (long)(int)(iVar5 + uVar6 * 9) * 8);
        dVar21 = *(double *)(param_3 + (long)((iVar12 + -1) - iVar5) * 8);
        dVar19 = -*(double *)(param_3 + (long)(iVar11 - iVar5) * 8);
      }
      else {
        dVar19 = *(double *)(param_3 + (long)(int)(iVar5 + uVar6 * -3) * 8);
        dVar23 = *(double *)(param_3 + (long)(iVar11 - iVar5) * 8);
        dVar21 = -*(double *)(param_3 + (long)(int)((uVar6 * 0xf + -1) - iVar5) * 8);
      }
      dVar21 = dVar21 - *(double *)(param_3 + (long)(iVar5 + iVar12) * 8);
      pdVar1 = (double *)(lVar16 + (long)(iVar5 >> 1) * 0x10);
      dVar20 = *pdVar1;
      dVar22 = pdVar1[1];
      *(double *)((long)local_98 + lVar7) = dVar21 * dVar22 + (dVar19 - dVar23) * dVar20;
      *(double *)((long)local_98 + lVar7 + 8) = dVar21 * dVar20 - (dVar19 - dVar23) * dVar22;
      piVar8 = piVar8 + 1;
    }
    pdVar1 = (double *)
             (*(long *)(param_1 + 0x18) +
             (long)*(int *)(*(long *)(param_1 + 0x28) + lVar9 * 4) * 0x10);
    *pdVar1 = local_98[0] + local_98[2] + local_98[4];
    pdVar1[1] = local_98[3] + local_98[5] + local_98[1];
    dVar21 = (local_98[3] - local_98[5]) * _ff_cos_53_double;
    dVar19 = (local_98[2] - local_98[4]) * DAT_019d3708;
    dVar20 = local_98[0] - (local_98[2] + local_98[4]) * DAT_019d3710;
    dVar23 = local_98[1] - (local_98[3] + local_98[5]) * DAT_019d3710;
    pdVar1[lVar17 * 2] = dVar21 + dVar20;
    (pdVar1 + lVar17 * 2)[1] = dVar23 - dVar19;
    pdVar1[lVar17 * 4] = dVar20 - dVar21;
    (pdVar1 + lVar17 * 4)[1] = dVar19 + dVar23;
    piVar15 = piVar15 + 3;
  }
  uVar4 = iVar12 >> 1;
  param_4 = param_4 >> 3;
  lVar7 = 4;
  lVar9 = 0;
  while (lVar7 = lVar7 + -1, lVar7 != 0) {
    (*pcVar18)(*(long *)(param_1 + 0x18) + lVar9);
    lVar9 = lVar9 + lVar17 * 0x10;
  }
  uVar10 = -(ulong)(uVar4 >> 0x1f) & 0xfffffff000000000 | (ulong)uVar4 << 4;
  lVar7 = lVar16 + -8;
  iVar11 = uVar4 * 2;
  lVar16 = lVar16 + 8;
  lVar9 = (long)(int)uVar4 + (long)(int)(uVar6 * 3);
  lVar13 = -4;
  iVar12 = iVar11;
  for (lVar17 = 0; iVar12 = iVar12 + -2, lVar17 < (int)uVar4; lVar17 = lVar17 + 1) {
    pdVar1 = (double *)
             (*(long *)(param_1 + 0x18) + (long)*(int *)((long)piVar14 + lVar13 + lVar9 * 4) * 0x10)
    ;
    pdVar2 = (double *)(*(long *)(param_1 + 0x18) + (long)piVar14[lVar9 + lVar17] * 0x10);
    pdVar3 = (double *)(lVar16 + uVar10);
    dVar21 = *pdVar2;
    dVar19 = pdVar2[1];
    dVar23 = *pdVar1;
    dVar20 = pdVar1[1];
    *(double *)(param_2 + ((long)iVar12 * param_4 + param_4) * 8) =
         dVar21 * *pdVar3 - dVar19 * pdVar3[-1];
    pdVar1 = (double *)(lVar7 + uVar10);
    lVar7 = lVar7 + -0x10;
    *(double *)(param_2 + (long)iVar11 * param_4 * 8) = dVar21 * pdVar3[-1] + dVar19 * *pdVar3;
    *(double *)(param_2 + ((long)iVar11 * param_4 + param_4) * 8) =
         dVar23 * *pdVar1 - dVar20 * pdVar1[-1];
    lVar13 = lVar13 + -4;
    iVar11 = iVar11 + 2;
    *(double *)(param_2 + (long)iVar12 * param_4 * 8) = dVar23 * pdVar1[-1] + dVar20 * *pdVar1;
    lVar16 = lVar16 + 0x10;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


