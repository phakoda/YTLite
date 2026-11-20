/* Decompiled from supplied 5.2.2 arm package. VA 0x26ef48. FUN_0026ef48 */

void FUN_0026ef48(long param_1,long param_2,long param_3,ulong param_4)

{
  double *pdVar1;
  double *pdVar2;
  uint uVar3;
  int *piVar4;
  long lVar5;
  int iVar6;
  double *pdVar7;
  double *pdVar8;
  int *piVar9;
  long lVar10;
  int *piVar11;
  long lVar12;
  long lVar13;
  code *pcVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double local_98 [6];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  param_4 = param_4 >> 3;
  uVar3 = *(uint *)(param_1 + 4);
  lVar13 = (long)(int)uVar3;
  lVar12 = *(long *)(param_1 + 0x10);
  piVar4 = *(int **)(param_1 + 0x20);
  pcVar14 = *(code **)(&DAT_0106d398 + (long)(0x1f - (int)LZCOUNT(uVar3 | 1)) * 8);
  piVar9 = piVar4;
  for (lVar5 = 0; lVar5 < lVar13; lVar5 = lVar5 + 1) {
    piVar11 = piVar9;
    for (lVar10 = 0; lVar10 != 0x30; lVar10 = lVar10 + 0x10) {
      iVar6 = *piVar11;
      dVar15 = *(double *)
                (param_3 + (long)(int)(uVar3 * 6 + -1) * param_4 * 8 + (long)iVar6 * param_4 * -8);
      dVar16 = *(double *)(param_3 + (long)iVar6 * param_4 * 8);
      pdVar7 = (double *)(lVar12 + (long)(iVar6 >> 1) * 0x10);
      dVar17 = *pdVar7;
      dVar18 = pdVar7[1];
      *(double *)((long)local_98 + lVar10) = dVar15 * dVar17 - dVar16 * dVar18;
      *(double *)((long)local_98 + lVar10 + 8) = dVar15 * dVar18 + dVar16 * dVar17;
      piVar11 = piVar11 + 1;
    }
    pdVar7 = (double *)
             (*(long *)(param_1 + 0x18) +
             (long)*(int *)(*(long *)(param_1 + 0x28) + lVar5 * 4) * 0x10);
    *pdVar7 = local_98[0] + local_98[2] + local_98[4];
    pdVar7[1] = local_98[3] + local_98[5] + local_98[1];
    dVar15 = (local_98[3] - local_98[5]) * _ff_cos_53_double;
    dVar16 = (local_98[2] - local_98[4]) * DAT_019d3708;
    dVar18 = local_98[0] - (local_98[2] + local_98[4]) * DAT_019d3710;
    dVar17 = local_98[1] - (local_98[3] + local_98[5]) * DAT_019d3710;
    pdVar7[lVar13 * 2] = dVar15 + dVar18;
    (pdVar7 + lVar13 * 2)[1] = dVar17 - dVar16;
    pdVar7[lVar13 * 4] = dVar18 - dVar15;
    (pdVar7 + lVar13 * 4)[1] = dVar16 + dVar17;
    piVar9 = piVar9 + 3;
  }
  iVar6 = (int)(uVar3 * 3) >> 1;
  lVar10 = 4;
  lVar5 = 0;
  while (lVar10 = lVar10 + -1, lVar10 != 0) {
    (*pcVar14)(*(long *)(param_1 + 0x18) + lVar5);
    lVar5 = lVar5 + lVar13 * 0x10;
  }
  lVar10 = (long)iVar6;
  pdVar7 = (double *)(param_2 + (long)iVar6 * 0x10 + 8);
  pdVar8 = (double *)(lVar12 + (long)iVar6 * 0x10 + 8);
  for (lVar5 = 0; iVar6 = iVar6 + -1, lVar5 < lVar10; lVar5 = lVar5 + 1) {
    pdVar1 = (double *)(*(long *)(param_1 + 0x18) + (long)piVar4[lVar13 * 3 + (long)iVar6] * 0x10);
    pdVar2 = (double *)
             (*(long *)(param_1 + 0x18) + (long)piVar4[lVar10 + (int)(uVar3 * 3) + lVar5] * 0x10);
    dVar15 = *pdVar1;
    dVar16 = pdVar1[1];
    pdVar1 = (double *)(lVar12 + (long)iVar6 * 0x10);
    dVar17 = pdVar1[1];
    dVar18 = *pdVar2;
    dVar19 = pdVar2[1];
    pdVar2 = (double *)(param_2 + (long)iVar6 * 0x10);
    *pdVar2 = dVar16 * dVar17 - dVar15 * *pdVar1;
    *pdVar7 = dVar16 * *pdVar1 + dVar15 * dVar17;
    dVar15 = *pdVar8;
    pdVar7[-1] = dVar19 * dVar15 - dVar18 * pdVar8[-1];
    pdVar7 = pdVar7 + 2;
    pdVar2[1] = dVar19 * pdVar8[-1] + dVar18 * dVar15;
    pdVar8 = pdVar8 + 2;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


