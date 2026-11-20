/* Decompiled from supplied 5.2.2 arm package. VA 0x27ff14. FUN_0027ff14 */

void FUN_0027ff14(long param_1,long param_2,long param_3,long param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  float *pfVar9;
  int iVar10;
  ulong in_x14;
  float *pfVar11;
  long lVar12;
  int iVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  
  fVar15 = *(float *)(param_1 + 8);
  fVar14 = *(float *)(param_1 + 0xc);
  uVar8 = *(ulong *)(param_1 + 0x30);
  iVar2 = *(int *)(param_1 + 0x40);
  for (lVar7 = 0; lVar7 < param_6; lVar7 = lVar7 + 1) {
    pfVar9 = *(float **)(param_3 + lVar7 * 8);
    lVar12 = *(long *)(param_2 + lVar7 * 8);
    iVar13 = 0;
    in_x14 = uVar8 >> 0x20;
    pfVar11 = *(float **)(param_4 + lVar7 * 8);
    while (iVar13 < param_5) {
      fVar16 = *pfVar9;
      fVar4 = fVar15 * fVar16;
      iVar10 = (int)in_x14;
      for (lVar6 = 0; lVar6 < (int)uVar8; lVar6 = lVar6 + 1) {
        iVar3 = (iVar10 + iVar2) - *(int *)(*(long *)(param_1 + 0x48) + lVar6 * 4);
        iVar1 = iVar2;
        if (iVar3 < iVar2) {
          iVar1 = 0;
        }
        fVar4 = fVar4 + *(float *)(lVar12 + (long)(iVar3 - iVar1) * 4) *
                        *(float *)(*(long *)(param_1 + 0x28) + lVar6 * 4);
      }
      fVar4 = fVar14 * fVar4;
      iVar13 = iVar13 + 1;
      fVar5 = fVar4;
      if (1.0 < fVar4) {
        fVar5 = 1.0;
      }
      fVar17 = -1.0;
      if (-1.0 <= fVar4) {
        fVar17 = fVar5;
      }
      *pfVar11 = fVar17;
      *(float *)(lVar12 + (long)iVar10 * 4) = fVar16;
      iVar1 = iVar2;
      if (iVar10 + 1 < iVar2) {
        iVar1 = 0;
      }
      in_x14 = (ulong)(uint)((iVar10 + 1) - iVar1);
      pfVar9 = pfVar9 + 1;
      pfVar11 = pfVar11 + 1;
    }
  }
  *(int *)(param_1 + 0x34) = (int)in_x14;
  return;
}


