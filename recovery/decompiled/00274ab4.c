/* Decompiled from supplied 5.2.2 arm package. VA 0x274ab4. FUN_00274ab4 */

void FUN_00274ab4(long param_1,long param_2,long param_3,ulong param_4)

{
  float *pfVar1;
  float *pfVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  float *pfVar7;
  code *pcVar8;
  float *pfVar9;
  long lVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  
  lVar5 = 0;
  lVar10 = *(long *)(param_1 + 0x10);
  uVar3 = *(uint *)(param_1 + 4);
  param_4 = param_4 >> 2;
  pcVar8 = *(code **)(&DAT_0106d428 + (long)(0x1f - (int)LZCOUNT(uVar3 | 1)) * 8);
  pfVar7 = (float *)(param_3 + param_4 * (long)(int)(uVar3 * 2 + -1) * 4);
  for (lVar6 = 0; lVar6 < (int)uVar3; lVar6 = lVar6 + 1) {
    fVar11 = *pfVar7;
    pfVar9 = (float *)(lVar10 + lVar5 * 4);
    fVar12 = *(float *)(param_3 + (long)(int)lVar5 * param_4 * 4);
    fVar13 = pfVar9[1];
    pfVar2 = (float *)(param_2 + (long)*(int *)(*(long *)(param_1 + 0x28) + lVar6 * 4) * 8);
    *pfVar2 = fVar11 * *pfVar9 - fVar12 * fVar13;
    lVar5 = lVar5 + 2;
    pfVar2[1] = fVar11 * fVar13 + fVar12 * *pfVar9;
    pfVar7 = pfVar7 + param_4 * -2;
  }
  iVar4 = (int)uVar3 >> 1;
  (*pcVar8)(param_2);
  lVar6 = (long)iVar4;
  pfVar7 = (float *)(lVar10 + (long)iVar4 * 8 + 4);
  pfVar9 = (float *)(param_2 + (long)iVar4 * 8 + 4);
  for (lVar5 = 0; iVar4 = iVar4 + -1, lVar5 < lVar6; lVar5 = lVar5 + 1) {
    pfVar1 = (float *)(param_2 + (long)iVar4 * 8);
    pfVar2 = (float *)(lVar10 + (long)iVar4 * 8);
    fVar11 = *pfVar1;
    fVar12 = pfVar2[1];
    fVar13 = *pfVar9;
    fVar14 = pfVar9[-1];
    *pfVar1 = pfVar1[1] * fVar12 - fVar11 * *pfVar2;
    *pfVar9 = pfVar1[1] * *pfVar2 + fVar11 * fVar12;
    fVar11 = *pfVar7;
    pfVar9[-1] = fVar13 * fVar11 - fVar14 * pfVar7[-1];
    pfVar2 = pfVar7 + -1;
    pfVar7 = pfVar7 + 2;
    pfVar1[1] = fVar13 * *pfVar2 + fVar14 * fVar11;
    pfVar9 = pfVar9 + 2;
  }
  return;
}


