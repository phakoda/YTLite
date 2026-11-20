/* Decompiled from supplied 5.2.2 arm package. VA 0x279264. FUN_00279264 */

void FUN_00279264(long param_1,long param_2,long param_3,ulong param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  int *piVar12;
  code *pcVar13;
  int *piVar14;
  long lVar15;
  long lVar16;
  
  lVar10 = 0;
  lVar16 = *(long *)(param_1 + 0x10);
  uVar5 = *(uint *)(param_1 + 4);
  param_4 = param_4 >> 2;
  pcVar13 = *(code **)(&DAT_0106d4b8 + (long)(0x1f - (int)LZCOUNT(uVar5 | 1)) * 8);
  piVar12 = (int *)(param_3 + param_4 * (long)(int)(uVar5 * 2 + -1) * 4);
  for (lVar11 = 0; lVar11 < (int)uVar5; lVar11 = lVar11 + 1) {
    piVar14 = (int *)(lVar16 + lVar10 * 4);
    iVar3 = *piVar12;
    lVar8 = *(long *)(param_1 + 0x28);
    iVar9 = piVar14[1];
    lVar15 = (long)*(int *)(param_3 + (long)(int)lVar10 * param_4 * 4);
    *(int *)(param_2 + (long)*(int *)(lVar8 + lVar11 * 4) * 8) =
         (int)((ulong)(((long)*piVar14 * (long)iVar3 + 0x40000000) - iVar9 * lVar15) >> 0x1f);
    lVar10 = lVar10 + 2;
    *(int *)(param_2 + (long)*(int *)(lVar8 + lVar11 * 4) * 8 + 4) =
         (int)(*piVar14 * lVar15 + (long)iVar9 * (long)iVar3 + 0x40000000U >> 0x1f);
    piVar12 = piVar12 + param_4 * -2;
  }
  iVar9 = (int)uVar5 >> 1;
  (*pcVar13)(param_2);
  lVar11 = (long)iVar9;
  piVar12 = (int *)(param_2 + (long)iVar9 * 8 + 4);
  piVar14 = (int *)(lVar16 + (long)iVar9 * 8 + 4);
  for (lVar10 = 0; iVar9 = iVar9 + -1, lVar10 < lVar11; lVar10 = lVar10 + 1) {
    piVar1 = (int *)(param_2 + (long)iVar9 * 8);
    piVar2 = (int *)(lVar16 + (long)iVar9 * 8);
    iVar4 = piVar2[1];
    iVar3 = *piVar1;
    iVar6 = *piVar12;
    iVar7 = piVar12[-1];
    *piVar1 = (int)((ulong)(((long)iVar4 * (long)piVar1[1] + 0x40000000) -
                           (long)*piVar2 * (long)iVar3) >> 0x1f);
    *piVar12 = (int)((long)iVar4 * (long)iVar3 + (long)*piVar2 * (long)piVar1[1] + 0x40000000U >>
                    0x1f);
    iVar3 = *piVar14;
    piVar12[-1] = (int)((ulong)(((long)iVar3 * (long)iVar6 + 0x40000000) -
                               (long)piVar14[-1] * (long)iVar7) >> 0x1f);
    piVar2 = piVar14 + -1;
    piVar14 = piVar14 + 2;
    piVar1[1] = (int)((long)iVar3 * (long)iVar7 + (long)*piVar2 * (long)iVar6 + 0x40000000U >> 0x1f)
    ;
    piVar12 = piVar12 + 2;
  }
  return;
}


