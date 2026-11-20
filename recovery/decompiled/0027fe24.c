/* Decompiled from supplied 5.2.2 arm package. VA 0x27fe24. FUN_0027fe24 */

void FUN_0027fe24(long param_1,long param_2,long param_3,long param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  double *pdVar7;
  int iVar8;
  ulong in_x14;
  double *pdVar9;
  long lVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  
  fVar13 = *(float *)(param_1 + 8);
  fVar12 = *(float *)(param_1 + 0xc);
  uVar6 = *(ulong *)(param_1 + 0x30);
  iVar2 = *(int *)(param_1 + 0x40);
  for (lVar5 = 0; lVar5 < param_6; lVar5 = lVar5 + 1) {
    pdVar7 = *(double **)(param_3 + lVar5 * 8);
    lVar10 = *(long *)(param_2 + lVar5 * 8);
    iVar11 = 0;
    in_x14 = uVar6 >> 0x20;
    pdVar9 = *(double **)(param_4 + lVar5 * 8);
    while (iVar11 < param_5) {
      dVar14 = *pdVar7;
      dVar16 = (double)fVar13 * dVar14;
      iVar8 = (int)in_x14;
      for (lVar4 = 0; lVar4 < (int)uVar6; lVar4 = lVar4 + 1) {
        iVar3 = (iVar8 + iVar2) - *(int *)(*(long *)(param_1 + 0x48) + lVar4 * 4);
        iVar1 = iVar2;
        if (iVar3 < iVar2) {
          iVar1 = 0;
        }
        dVar16 = dVar16 + *(double *)(lVar10 + (long)(iVar3 - iVar1) * 8) *
                          (double)*(float *)(*(long *)(param_1 + 0x28) + lVar4 * 4);
      }
      dVar16 = (double)fVar12 * dVar16;
      iVar11 = iVar11 + 1;
      dVar17 = dVar16;
      if (1.0 < dVar16) {
        dVar17 = 1.0;
      }
      dVar15 = -1.0;
      if (-1.0 <= dVar16) {
        dVar15 = dVar17;
      }
      *pdVar9 = dVar15;
      *(double *)(lVar10 + (long)iVar8 * 8) = dVar14;
      iVar1 = iVar2;
      if (iVar8 + 1 < iVar2) {
        iVar1 = 0;
      }
      in_x14 = (ulong)(uint)((iVar8 + 1) - iVar1);
      pdVar7 = pdVar7 + 1;
      pdVar9 = pdVar9 + 1;
    }
  }
  *(int *)(param_1 + 0x34) = (int)in_x14;
  return;
}


