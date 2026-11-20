/* Decompiled from supplied 5.2.2 arm package. VA 0x270bfc. FUN_00270bfc */

void FUN_00270bfc(long param_1,long param_2,long param_3,ulong param_4)

{
  double *pdVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  double *pdVar6;
  uint uVar7;
  code *pcVar8;
  long lVar9;
  long lVar10;
  uint uVar11;
  int iVar12;
  long lVar13;
  long lVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  
  iVar4 = 0;
  uVar7 = *(uint *)(param_1 + 4);
  lVar14 = *(long *)(param_1 + 0x10);
  pcVar8 = *(code **)(&DAT_0106d398 + (long)(0x1f - (int)LZCOUNT(uVar7 | 1)) * 8);
  iVar3 = uVar7 * 3;
  iVar12 = -1;
  pdVar6 = (double *)(lVar14 + 8);
  for (lVar5 = 0; lVar5 < (int)uVar7; lVar5 = lVar5 + 1) {
    if (iVar4 < (int)uVar7) {
      dVar17 = *(double *)(param_3 + (long)(int)(uVar7 + iVar12) * 8);
      dVar15 = -*(double *)(param_3 + (long)(iVar3 + iVar12) * 8) -
               *(double *)(param_3 + (long)(iVar3 + iVar4) * 8);
    }
    else {
      dVar17 = -*(double *)(param_3 + (long)(int)(uVar7 * 5 + iVar12) * 8);
      dVar15 = *(double *)(param_3 + (long)(int)(iVar4 - uVar7) * 8) -
               *(double *)(param_3 + (long)(iVar3 + iVar12) * 8);
    }
    dVar17 = dVar17 - *(double *)(param_3 + (long)(int)(uVar7 + iVar4) * 8);
    dVar16 = pdVar6[-1];
    iVar12 = iVar12 + -2;
    pdVar1 = (double *)(param_2 + (long)*(int *)(*(long *)(param_1 + 0x28) + lVar5 * 4) * 0x10);
    pdVar1[1] = dVar17 * dVar16 - dVar15 * *pdVar6;
    *pdVar1 = dVar17 * *pdVar6 + dVar15 * dVar16;
    iVar4 = iVar4 + 2;
    pdVar6 = pdVar6 + 2;
  }
  iVar4 = (int)uVar7 >> 1;
  param_4 = param_4 >> 3;
  (*pcVar8)(param_2);
  lVar13 = 0;
  lVar14 = lVar14 + (long)iVar4 * 0x10;
  uVar7 = uVar7 & 0xfffffffe;
  lVar5 = param_2 + (long)iVar4 * 0x10;
  lVar9 = -1;
  lVar10 = 8;
  uVar11 = uVar7;
  while( true ) {
    uVar11 = uVar11 - 2;
    lVar9 = lVar9 + 1;
    if (iVar4 <= lVar9) break;
    dVar15 = *(double *)(lVar5 + lVar10 + -8);
    dVar17 = *(double *)(lVar5 + lVar10);
    dVar16 = *(double *)(lVar5 + lVar13 + -0x10);
    dVar18 = *(double *)(lVar5 + lVar13 + -8);
    *(double *)(param_2 + ((long)(int)uVar11 * param_4 + param_4) * 8) =
         dVar15 * *(double *)(lVar14 + lVar10) - dVar17 * *(double *)(lVar14 + lVar10 + -8);
    *(double *)(param_2 + (long)(int)uVar7 * param_4 * 8) =
         dVar15 * *(double *)(lVar14 + lVar10 + -8) + dVar17 * *(double *)(lVar14 + lVar10);
    lVar2 = lVar14 + lVar13;
    lVar13 = lVar13 + -0x10;
    *(double *)(param_2 + ((long)(int)uVar7 * param_4 + param_4) * 8) =
         dVar16 * *(double *)(lVar2 + -8) - dVar18 * *(double *)(lVar2 + -0x10);
    uVar7 = uVar7 + 2;
    lVar10 = lVar10 + 0x10;
    *(double *)(param_2 + (long)(int)uVar11 * param_4 * 8) =
         dVar16 * *(double *)(lVar2 + -0x10) + dVar18 * *(double *)(lVar2 + -8);
  }
  return;
}


