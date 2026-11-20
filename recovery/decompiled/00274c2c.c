/* Decompiled from supplied 5.2.2 arm package. VA 0x274c2c. FUN_00274c2c */

void FUN_00274c2c(long param_1,long param_2,long param_3,ulong param_4)

{
  float *pfVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  float *pfVar6;
  uint uVar7;
  code *pcVar8;
  long lVar9;
  long lVar10;
  uint uVar11;
  int iVar12;
  long lVar13;
  long lVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  
  iVar4 = 0;
  uVar7 = *(uint *)(param_1 + 4);
  lVar14 = *(long *)(param_1 + 0x10);
  pcVar8 = *(code **)(&DAT_0106d428 + (long)(0x1f - (int)LZCOUNT(uVar7 | 1)) * 8);
  iVar3 = uVar7 * 3;
  iVar12 = -1;
  pfVar6 = (float *)(lVar14 + 4);
  for (lVar5 = 0; lVar5 < (int)uVar7; lVar5 = lVar5 + 1) {
    if (iVar4 < (int)uVar7) {
      fVar17 = *(float *)(param_3 + (long)(int)(uVar7 + iVar12) * 4);
      fVar15 = -*(float *)(param_3 + (long)(iVar3 + iVar12) * 4) -
               *(float *)(param_3 + (long)(iVar3 + iVar4) * 4);
    }
    else {
      fVar17 = -*(float *)(param_3 + (long)(int)(uVar7 * 5 + iVar12) * 4);
      fVar15 = *(float *)(param_3 + (long)(int)(iVar4 - uVar7) * 4) -
               *(float *)(param_3 + (long)(iVar3 + iVar12) * 4);
    }
    fVar17 = fVar17 - *(float *)(param_3 + (long)(int)(uVar7 + iVar4) * 4);
    fVar16 = pfVar6[-1];
    iVar12 = iVar12 + -2;
    pfVar1 = (float *)(param_2 + (long)*(int *)(*(long *)(param_1 + 0x28) + lVar5 * 4) * 8);
    pfVar1[1] = fVar17 * fVar16 - fVar15 * *pfVar6;
    *pfVar1 = fVar17 * *pfVar6 + fVar15 * fVar16;
    iVar4 = iVar4 + 2;
    pfVar6 = pfVar6 + 2;
  }
  iVar4 = (int)uVar7 >> 1;
  param_4 = param_4 >> 2;
  (*pcVar8)(param_2);
  lVar13 = 0;
  lVar14 = lVar14 + (long)iVar4 * 8;
  uVar7 = uVar7 & 0xfffffffe;
  lVar5 = param_2 + (long)iVar4 * 8;
  lVar9 = -1;
  lVar10 = 4;
  uVar11 = uVar7;
  while( true ) {
    uVar11 = uVar11 - 2;
    lVar9 = lVar9 + 1;
    if (iVar4 <= lVar9) break;
    fVar15 = *(float *)(lVar5 + lVar10 + -4);
    fVar17 = *(float *)(lVar5 + lVar10);
    fVar16 = *(float *)(lVar5 + lVar13 + -8);
    fVar18 = *(float *)(lVar5 + lVar13 + -4);
    *(float *)(param_2 + ((long)(int)uVar11 * param_4 + param_4) * 4) =
         fVar15 * *(float *)(lVar14 + lVar10) - fVar17 * *(float *)(lVar14 + lVar10 + -4);
    *(float *)(param_2 + (long)(int)uVar7 * param_4 * 4) =
         fVar15 * *(float *)(lVar14 + lVar10 + -4) + fVar17 * *(float *)(lVar14 + lVar10);
    lVar2 = lVar14 + lVar13;
    lVar13 = lVar13 + -8;
    *(float *)(param_2 + ((long)(int)uVar7 * param_4 + param_4) * 4) =
         fVar16 * *(float *)(lVar2 + -4) - fVar18 * *(float *)(lVar2 + -8);
    uVar7 = uVar7 + 2;
    lVar10 = lVar10 + 8;
    *(float *)(param_2 + (long)(int)uVar11 * param_4 * 4) =
         fVar16 * *(float *)(lVar2 + -8) + fVar18 * *(float *)(lVar2 + -4);
  }
  return;
}


