/* Decompiled from supplied 5.2.2 arm package. VA 0x2793f8. FUN_002793f8 */

void FUN_002793f8(long param_1,long param_2,long param_3,ulong param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  int iVar10;
  long lVar11;
  int iVar12;
  long lVar13;
  int *piVar14;
  uint uVar15;
  code *pcVar16;
  long lVar17;
  int iVar18;
  uint uVar19;
  long lVar20;
  
  iVar12 = 0;
  uVar15 = *(uint *)(param_1 + 4);
  lVar20 = *(long *)(param_1 + 0x10);
  piVar14 = (int *)(lVar20 + 4);
  iVar7 = uVar15 * 3;
  pcVar16 = *(code **)(&DAT_0106d4b8 + (long)(0x1f - (int)LZCOUNT(uVar15 | 1)) * 8);
  iVar18 = -1;
  for (lVar13 = 0; lVar13 < (int)uVar15; lVar13 = lVar13 + 1) {
    iVar4 = *(int *)(param_3 + (long)(int)(uVar15 + iVar12) * 4);
    if (iVar12 < (int)uVar15) {
      iVar10 = *(int *)(param_3 + (long)(iVar7 + iVar18) * 4);
      iVar4 = (0x20 - iVar4) + *(int *)(param_3 + (long)(int)(uVar15 + iVar18) * 4);
      iVar5 = -*(int *)(param_3 + (long)(iVar7 + iVar12) * 4);
    }
    else {
      iVar5 = *(int *)(param_3 + (long)(int)(iVar12 - uVar15) * 4);
      iVar10 = *(int *)(param_3 + (long)(iVar7 + iVar18) * 4);
      iVar4 = (0x20 - iVar4) - *(int *)(param_3 + (long)(int)(uVar15 * 5 + iVar18) * 4);
    }
    iVar6 = piVar14[-1];
    lVar11 = *(long *)(param_1 + 0x28);
    lVar9 = (long)((iVar5 + 0x20) - iVar10 >> 6);
    iVar18 = iVar18 + -2;
    *(int *)(param_2 + (long)*(int *)(lVar11 + lVar13 * 4) * 8 + 4) =
         (int)((ulong)(((long)iVar6 * (long)(iVar4 >> 6) + 0x40000000) - *piVar14 * lVar9) >> 0x1f);
    iVar10 = *piVar14;
    piVar14 = piVar14 + 2;
    *(int *)(param_2 + (long)*(int *)(lVar11 + lVar13 * 4) * 8) =
         (int)(iVar6 * lVar9 + (long)iVar10 * (long)(iVar4 >> 6) + 0x40000000U >> 0x1f);
    iVar12 = iVar12 + 2;
  }
  iVar12 = (int)uVar15 >> 1;
  param_4 = param_4 >> 2;
  (*pcVar16)(param_2);
  lVar17 = 0;
  lVar20 = lVar20 + (long)iVar12 * 8;
  uVar15 = uVar15 & 0xfffffffe;
  lVar13 = param_2 + (long)iVar12 * 8;
  lVar11 = -1;
  lVar9 = 4;
  uVar19 = uVar15;
  while( true ) {
    uVar19 = uVar19 - 2;
    lVar11 = lVar11 + 1;
    if (iVar12 <= lVar11) break;
    lVar8 = (long)*(int *)(lVar13 + lVar9 + -4);
    iVar18 = *(int *)(lVar13 + lVar9);
    lVar2 = (long)*(int *)(lVar13 + lVar17 + -8);
    lVar3 = (long)*(int *)(lVar13 + lVar17 + -4);
    *(int *)(param_2 + ((long)(int)uVar19 * param_4 + param_4) * 4) =
         (int)((ulong)((*(int *)(lVar20 + lVar9) * lVar8 + 0x40000000) -
                      (long)*(int *)(lVar20 + lVar9 + -4) * (long)iVar18) >> 0x1f);
    lVar1 = lVar20 + lVar17;
    *(int *)(param_2 + (long)(int)uVar15 * param_4 * 4) =
         (int)((long)*(int *)(lVar20 + lVar9) * (long)iVar18 + *(int *)(lVar20 + lVar9 + -4) * lVar8
               + 0x40000000U >> 0x1f);
    lVar17 = lVar17 + -8;
    *(int *)(param_2 + ((long)(int)uVar15 * param_4 + param_4) * 4) =
         (int)((ulong)((*(int *)(lVar1 + -4) * lVar2 + 0x40000000) - *(int *)(lVar1 + -8) * lVar3)
              >> 0x1f);
    uVar15 = uVar15 + 2;
    lVar9 = lVar9 + 8;
    *(int *)(param_2 + (long)(int)uVar19 * param_4 * 4) =
         (int)(*(int *)(lVar1 + -4) * lVar3 + *(int *)(lVar1 + -8) * lVar2 + 0x40000000U >> 0x1f);
  }
  return;
}


