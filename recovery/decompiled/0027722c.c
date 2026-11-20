/* Decompiled from supplied 5.2.2 arm package. VA 0x27722c. FUN_0027722c */

void FUN_0027722c(long param_1,long param_2,long param_3,ulong param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  int iVar11;
  undefined4 *puVar12;
  int *piVar13;
  long lVar14;
  long lVar15;
  int *piVar16;
  long lVar17;
  code *pcVar18;
  int local_80 [6];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  param_4 = param_4 >> 2;
  uVar4 = *(uint *)(param_1 + 4);
  lVar17 = (long)(int)uVar4;
  lVar15 = *(long *)(param_1 + 0x10);
  piVar16 = *(int **)(param_1 + 0x20);
  pcVar18 = *(code **)(&DAT_0106d4b8 + (long)(0x1f - (int)LZCOUNT(uVar4 | 1)) * 8);
  piVar13 = piVar16;
  for (lVar10 = 0; lVar10 < lVar17; lVar10 = lVar10 + 1) {
    piVar5 = piVar13;
    for (lVar14 = 0; lVar14 != 0x18; lVar14 = lVar14 + 8) {
      iVar11 = *piVar5;
      piVar1 = (int *)(lVar15 + (long)(iVar11 >> 1) * 8);
      lVar9 = (long)*(int *)(param_3 + (long)(int)(uVar4 * 6 + -1) * param_4 * 4 +
                            (long)iVar11 * param_4 * -4);
      lVar6 = (long)*piVar1;
      lVar8 = (long)piVar1[1];
      lVar7 = (long)*(int *)(param_3 + (long)iVar11 * param_4 * 4);
      *(int *)((long)local_80 + lVar14) =
           (int)((ulong)((lVar6 * lVar9 + 0x40000000) - lVar8 * lVar7) >> 0x1f);
      *(int *)((long)local_80 + lVar14 + 4) =
           (int)(lVar6 * lVar7 + lVar8 * lVar9 + 0x40000000U >> 0x1f);
      piVar5 = piVar5 + 1;
    }
    piVar5 = (int *)(*(long *)(param_1 + 0x18) +
                    (long)*(int *)(*(long *)(param_1 + 0x28) + lVar10 * 4) * 8);
    *piVar5 = local_80[0] + local_80[4] + local_80[2];
    piVar5[1] = local_80[1] + local_80[5] + local_80[3];
    lVar8 = (long)DAT_01af77a8 * (long)(local_80[4] + local_80[2]);
    lVar14 = (long)DAT_01af77a8 * (long)(local_80[5] + local_80[3]);
    lVar9 = (long)(int)_ff_cos_53_int32 * (long)(local_80[3] - local_80[5]);
    lVar6 = (_ff_cos_53_int32 >> 0x20) * (long)(local_80[2] - local_80[4]);
    piVar5[lVar17 * 2] = local_80[0] - (int)(lVar9 + lVar8 + 0x40000000U >> 0x1f);
    (piVar5 + lVar17 * 2)[1] = local_80[1] - (int)((ulong)((0x40000000 - lVar6) + lVar14) >> 0x1f);
    piVar5[lVar17 * 4] = local_80[0] - (int)((ulong)((0x40000000 - lVar9) + lVar8) >> 0x1f);
    (piVar5 + lVar17 * 4)[1] = local_80[1] - (int)(lVar6 + lVar14 + 0x40000000U >> 0x1f);
    piVar13 = piVar13 + 3;
  }
  iVar11 = (int)(uVar4 * 3) >> 1;
  lVar14 = 4;
  lVar10 = 0;
  while (lVar14 = lVar14 + -1, lVar14 != 0) {
    (*pcVar18)(*(long *)(param_1 + 0x18) + lVar10);
    lVar10 = lVar10 + lVar17 * 8;
  }
  lVar14 = (long)iVar11;
  puVar12 = (undefined4 *)(param_2 + (long)iVar11 * 8 + 4);
  piVar13 = (int *)(lVar15 + (long)iVar11 * 8 + 4);
  for (lVar10 = 0; iVar11 = iVar11 + -1, lVar10 < lVar14; lVar10 = lVar10 + 1) {
    piVar5 = (int *)(lVar15 + (long)iVar11 * 8);
    iVar3 = piVar5[1];
    piVar1 = (int *)(*(long *)(param_1 + 0x18) + (long)piVar16[lVar17 * 3 + (long)iVar11] * 8);
    lVar6 = (long)*piVar1;
    lVar9 = (long)piVar1[1];
    puVar2 = (undefined4 *)(param_2 + (long)iVar11 * 8);
    piVar1 = (int *)(*(long *)(param_1 + 0x18) +
                    (long)piVar16[lVar14 + (int)(uVar4 * 3) + lVar10] * 8);
    lVar8 = (long)*piVar1;
    lVar7 = (long)piVar1[1];
    *puVar2 = (int)((ulong)((iVar3 * lVar9 + 0x40000000) - *piVar5 * lVar6) >> 0x1f);
    *puVar12 = (int)(iVar3 * lVar6 + *piVar5 * lVar9 + 0x40000000U >> 0x1f);
    iVar3 = *piVar13;
    puVar12[-1] = (int)((ulong)((iVar3 * lVar7 + 0x40000000) - piVar13[-1] * lVar8) >> 0x1f);
    puVar12 = puVar12 + 2;
    puVar2[1] = (int)(iVar3 * lVar8 + piVar13[-1] * lVar7 + 0x40000000U >> 0x1f);
    piVar13 = piVar13 + 2;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


