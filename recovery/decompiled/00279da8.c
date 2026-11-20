/* Decompiled from supplied 5.2.2 arm package. VA 0x279da8. FUN_00279da8 */

void FUN_00279da8(int *param_1,long param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  long lVar14;
  int *piVar15;
  int *piVar16;
  int iVar17;
  long lVar18;
  int *piVar19;
  
  uVar6 = param_3 << 2;
  uVar8 = param_3 * 6;
  piVar19 = param_1 + (long)(int)uVar6 * 2;
  piVar15 = param_1 + (long)(int)uVar8 * 2;
  iVar11 = *piVar15;
  iVar4 = piVar15[1];
  iVar12 = *piVar19;
  iVar5 = piVar19[1];
  iVar9 = iVar11 + iVar12;
  *piVar19 = *param_1 - iVar9;
  uVar7 = param_3 << 1;
  piVar16 = param_1 + (long)(int)uVar7 * 2;
  *param_1 = *param_1 + iVar9;
  iVar11 = iVar11 - iVar12;
  piVar15[1] = piVar16[1] - iVar11;
  iVar9 = iVar5 - iVar4;
  piVar16[1] = piVar16[1] + iVar11;
  *piVar15 = *piVar16 - iVar9;
  *piVar16 = *piVar16 + iVar9;
  lVar10 = param_2 + (long)(int)uVar7 * 4;
  iVar4 = iVar4 + iVar5;
  piVar19[1] = param_1[1] - iVar4;
  piVar19 = param_1 + (long)(int)(param_3 << 2 | 1) * 2;
  param_1[1] = param_1[1] + iVar4;
  lVar14 = (long)*(int *)(param_2 + 4);
  lVar18 = (long)*(int *)(lVar10 + -4);
  iVar4 = *piVar19;
  iVar12 = piVar19[1];
  piVar15 = param_1 + (long)(int)(uVar8 | 1) * 2;
  iVar11 = *piVar15;
  iVar5 = piVar15[1];
  iVar17 = (int)((ulong)(iVar4 * lVar14 + 0x40000000 + lVar18 * iVar12) >> 0x1f);
  iVar13 = (int)((ulong)((iVar11 * lVar14 + 0x40000000) - iVar5 * lVar18) >> 0x1f);
  iVar9 = iVar13 + iVar17;
  *piVar19 = param_1[2] - iVar9;
  piVar16 = param_1 + (long)(int)(param_3 << 1 | 1) * 2;
  param_1[2] = iVar9 + param_1[2];
  iVar13 = iVar13 - iVar17;
  piVar15[1] = piVar16[1] - iVar13;
  iVar12 = (int)((iVar12 * lVar14 - lVar18 * iVar4) + 0x40000000U >> 0x1f);
  iVar9 = (int)(iVar5 * lVar14 + iVar11 * lVar18 + 0x40000000U >> 0x1f);
  iVar4 = iVar12 - iVar9;
  piVar16[1] = piVar16[1] + iVar13;
  *piVar15 = *piVar16 - iVar4;
  piVar15 = (int *)(param_2 + 0xc);
  *piVar16 = *piVar16 + iVar4;
  iVar9 = iVar9 + iVar12;
  piVar19[1] = param_1[3] - iVar9;
  param_3 = 1 - param_3;
  piVar16 = (int *)(lVar10 + -0xc);
  param_1[3] = param_1[3] + iVar9;
  piVar19 = param_1 + 7;
  do {
    lVar10 = (long)piVar15[-1];
    piVar1 = (int *)((long)piVar19 +
                    (-(ulong)(uVar6 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar6 << 3));
    lVar14 = (long)piVar16[1];
    piVar2 = (int *)((long)piVar19 +
                    (-(ulong)(uVar8 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar8 << 3));
    piVar3 = (int *)((long)piVar19 +
                    (-(ulong)(uVar7 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar7 << 3));
    iVar4 = piVar1[-3];
    iVar12 = piVar1[-2];
    iVar11 = piVar2[-3];
    iVar5 = piVar2[-2];
    iVar17 = (int)((ulong)(iVar4 * lVar10 + 0x40000000 + lVar14 * iVar12) >> 0x1f);
    iVar13 = (int)((ulong)((iVar11 * lVar10 + 0x40000000) - iVar5 * lVar14) >> 0x1f);
    iVar9 = iVar13 + iVar17;
    piVar1[-3] = piVar19[-3] - iVar9;
    piVar19[-3] = iVar9 + piVar19[-3];
    iVar13 = iVar13 - iVar17;
    piVar2[-2] = piVar3[-2] - iVar13;
    iVar9 = (int)(iVar5 * lVar10 + iVar11 * lVar14 + 0x40000000U >> 0x1f);
    iVar11 = (int)((iVar12 * lVar10 - lVar14 * iVar4) + 0x40000000U >> 0x1f);
    iVar4 = iVar11 - iVar9;
    piVar3[-2] = piVar3[-2] + iVar13;
    piVar2[-3] = piVar3[-3] - iVar4;
    piVar3[-3] = piVar3[-3] + iVar4;
    iVar9 = iVar9 + iVar11;
    piVar1[-2] = piVar19[-2] - iVar9;
    piVar19[-2] = piVar19[-2] + iVar9;
    lVar10 = (long)*piVar15;
    lVar14 = (long)*piVar16;
    iVar4 = *piVar1;
    iVar12 = piVar1[-1];
    iVar5 = piVar2[-1];
    iVar11 = *piVar2;
    iVar17 = (int)((ulong)(iVar12 * lVar10 + 0x40000000 + lVar14 * iVar4) >> 0x1f);
    iVar13 = (int)((ulong)((iVar5 * lVar10 + 0x40000000) - iVar11 * lVar14) >> 0x1f);
    iVar9 = iVar13 + iVar17;
    piVar1[-1] = piVar19[-1] - iVar9;
    piVar19[-1] = iVar9 + piVar19[-1];
    iVar13 = iVar13 - iVar17;
    *piVar2 = *piVar3 - iVar13;
    iVar9 = (int)(iVar11 * lVar10 + iVar5 * lVar14 + 0x40000000U >> 0x1f);
    iVar11 = (int)((iVar4 * lVar10 - lVar14 * iVar12) + 0x40000000U >> 0x1f);
    iVar4 = iVar11 - iVar9;
    *piVar3 = *piVar3 + iVar13;
    piVar2[-1] = piVar3[-1] - iVar4;
    piVar3[-1] = piVar3[-1] + iVar4;
    iVar9 = iVar9 + iVar11;
    *piVar1 = *piVar19 - iVar9;
    param_3 = param_3 + 1;
    piVar16 = piVar16 + -2;
    piVar15 = piVar15 + 2;
    *piVar19 = *piVar19 + iVar9;
    piVar19 = piVar19 + 4;
  } while (param_3 != 0);
  return;
}


