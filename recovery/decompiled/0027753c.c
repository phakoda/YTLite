/* Decompiled from supplied 5.2.2 arm package. VA 0x27753c. FUN_0027753c */

void FUN_0027753c(long param_1,long param_2,long param_3,ulong param_4)

{
  int *piVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  long lVar11;
  int *piVar12;
  long lVar13;
  ulong uVar14;
  int iVar15;
  int iVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  code *pcVar21;
  long lVar22;
  int iVar23;
  int local_80 [6];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar8 = *(uint *)(param_1 + 4);
  lVar20 = (long)(int)uVar8;
  lVar19 = *(long *)(param_1 + 0x10);
  piVar9 = *(int **)(param_1 + 0x20);
  iVar16 = uVar8 * 3;
  iVar15 = uVar8 * 9 + -1;
  pcVar21 = *(code **)(&DAT_0106d4b8 + (long)(0x1f - (int)LZCOUNT(uVar8 | 1)) * 8);
  piVar10 = piVar9;
  for (lVar13 = 0; lVar13 < lVar20; lVar13 = lVar13 + 1) {
    piVar12 = piVar10;
    for (lVar11 = 0; lVar11 != 0x18; lVar11 = lVar11 + 8) {
      iVar5 = *piVar12;
      iVar6 = *(int *)(param_3 + (long)(iVar5 + iVar16) * 4);
      if (iVar5 < iVar16) {
        iVar23 = *(int *)(param_3 + (long)(iVar15 - iVar5) * 4);
        iVar6 = (0x20 - iVar6) + *(int *)(param_3 + (long)((iVar16 + -1) - iVar5) * 4);
        iVar7 = -*(int *)(param_3 + (long)(int)(iVar5 + uVar8 * 9) * 4);
      }
      else {
        iVar7 = *(int *)(param_3 + (long)(int)(iVar5 + uVar8 * -3) * 4);
        iVar23 = *(int *)(param_3 + (long)(iVar15 - iVar5) * 4);
        iVar6 = (0x20 - iVar6) - *(int *)(param_3 + (long)(int)((uVar8 * 0xf + -1) - iVar5) * 4);
      }
      piVar1 = (int *)(lVar19 + (long)(iVar5 >> 1) * 8);
      lVar17 = (long)*piVar1;
      lVar22 = (long)piVar1[1];
      lVar18 = (long)((iVar7 + 0x20) - iVar23 >> 6);
      *(int *)((long)local_80 + lVar11) =
           (int)(lVar17 * lVar18 + lVar22 * (iVar6 >> 6) + 0x40000000U >> 0x1f);
      *(int *)((long)local_80 + lVar11 + 4) =
           (int)((ulong)((lVar17 * (iVar6 >> 6) + 0x40000000) - lVar22 * lVar18) >> 0x1f);
      piVar12 = piVar12 + 1;
    }
    piVar12 = (int *)(*(long *)(param_1 + 0x18) +
                     (long)*(int *)(*(long *)(param_1 + 0x28) + lVar13 * 4) * 8);
    *piVar12 = local_80[0] + local_80[4] + local_80[2];
    piVar12[1] = local_80[1] + local_80[5] + local_80[3];
    lVar22 = (long)DAT_01af77a8 * (long)(local_80[4] + local_80[2]);
    lVar11 = (long)DAT_01af77a8 * (long)(local_80[5] + local_80[3]);
    lVar18 = (long)(int)_ff_cos_53_int32 * (long)(local_80[3] - local_80[5]);
    lVar17 = (_ff_cos_53_int32 >> 0x20) * (long)(local_80[2] - local_80[4]);
    piVar12[lVar20 * 2] = local_80[0] - (int)(lVar18 + lVar22 + 0x40000000U >> 0x1f);
    (piVar12 + lVar20 * 2)[1] = local_80[1] - (int)((ulong)((0x40000000 - lVar17) + lVar11) >> 0x1f)
    ;
    piVar12[lVar20 * 4] = local_80[0] - (int)((ulong)((0x40000000 - lVar18) + lVar22) >> 0x1f);
    (piVar12 + lVar20 * 4)[1] = local_80[1] - (int)(lVar17 + lVar11 + 0x40000000U >> 0x1f);
    piVar10 = piVar10 + 3;
  }
  uVar2 = iVar16 >> 1;
  param_4 = param_4 >> 2;
  lVar11 = 4;
  lVar13 = 0;
  while (lVar11 = lVar11 + -1, lVar11 != 0) {
    (*pcVar21)(*(long *)(param_1 + 0x18) + lVar13);
    lVar13 = lVar13 + lVar20 * 8;
  }
  uVar14 = -(ulong)(uVar2 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar2 << 3;
  lVar11 = lVar19 + -4;
  iVar15 = uVar2 * 2;
  lVar19 = lVar19 + 4;
  lVar17 = -4;
  lVar13 = (long)(int)uVar2 + (long)(int)(uVar8 * 3);
  iVar16 = iVar15;
  for (lVar20 = 0; iVar16 = iVar16 + -2, lVar20 < (int)uVar2; lVar20 = lVar20 + 1) {
    piVar10 = (int *)(lVar19 + uVar14);
    piVar12 = (int *)(*(long *)(param_1 + 0x18) + (long)piVar9[lVar13 + lVar20] * 8);
    lVar22 = (long)*piVar12;
    lVar3 = (long)piVar12[1];
    piVar12 = (int *)(*(long *)(param_1 + 0x18) +
                     (long)*(int *)((long)piVar9 + lVar17 + lVar13 * 4) * 8);
    lVar18 = (long)*piVar12;
    lVar4 = (long)piVar12[1];
    *(int *)(param_2 + ((long)iVar16 * param_4 + param_4) * 4) =
         (int)((ulong)((*piVar10 * lVar22 + 0x40000000) - piVar10[-1] * lVar3) >> 0x1f);
    piVar12 = (int *)(lVar11 + uVar14);
    lVar11 = lVar11 + -8;
    *(int *)(param_2 + (long)iVar15 * param_4 * 4) =
         (int)(*piVar10 * lVar3 + piVar10[-1] * lVar22 + 0x40000000U >> 0x1f);
    *(int *)(param_2 + ((long)iVar15 * param_4 + param_4) * 4) =
         (int)((ulong)((*piVar12 * lVar18 + 0x40000000) - piVar12[-1] * lVar4) >> 0x1f);
    lVar17 = lVar17 + -4;
    iVar15 = iVar15 + 2;
    *(int *)(param_2 + (long)iVar16 * param_4 * 4) =
         (int)(*piVar12 * lVar4 + piVar12[-1] * lVar18 + 0x40000000U >> 0x1f);
    lVar19 = lVar19 + 8;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


