/* Decompiled from supplied 5.2.2 arm package. VA 0x24dbf0. FUN_0024dbf0 */

int FUN_0024dbf0(long param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  long lVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  
  iVar6 = 1 << (ulong)(param_2 & 0x1f);
  if (iVar6 < 0x401) {
    iVar19 = 0;
    uVar21 = 9;
    iVar20 = 1;
    while (iVar20 < iVar6) {
      iVar7 = (*DAT_0191b7d0)(param_1,iVar6 << 1);
      uVar14 = (uint)(0x3505 < iVar7);
      if (0x3505 < iVar7) {
        iVar19 = iVar19 + 1;
      }
      iVar13 = 0x4000;
      if (iVar7 < 0x3506) {
        iVar13 = 0x2000;
      }
      if (0x6a0a < iVar7) {
        iVar19 = iVar19 + 1;
        uVar14 = 1;
        if (0x3505 < iVar7) {
          uVar14 = 2;
        }
        iVar13 = iVar13 << 1;
      }
      iVar7 = iVar20 * 2;
      if (param_3 == 0) {
        iVar15 = 0;
        lVar18 = -(long)iVar7;
        for (iVar13 = 0; iVar13 < iVar20; iVar13 = iVar13 + 1) {
          lVar8 = (long)(iVar13 << (ulong)(uVar21 & 0x1f)) * 2;
          sVar4 = *(short *)(&DAT_00c4fb50 + lVar8);
          sVar5 = *(short *)(&DAT_00c4f950 + lVar8);
          lVar8 = lVar18;
          iVar17 = iVar15;
          while (lVar8 = lVar8 + iVar7, lVar8 < iVar6) {
            iVar11 = iVar7 + iVar17;
            iVar1 = iVar17 + 1;
            iVar10 = (int)*(short *)(param_1 + (long)iVar11 * 2);
            iVar9 = (int)*(short *)(param_1 + (long)(iVar11 + 1) * 2);
            iVar16 = iVar10 * sVar5 + iVar9 * sVar4 >> 0xf;
            iVar12 = (int)*(short *)(param_1 + (long)iVar1 * 2);
            iVar10 = iVar10 * sVar4 - iVar9 * sVar5 >> 0xf;
            iVar9 = (int)*(short *)(param_1 + (long)iVar17 * 2);
            *(short *)(param_1 + (long)iVar11 * 2) = (short)(iVar9 - iVar10 >> uVar14);
            *(short *)(param_1 + (long)(iVar11 + 1) * 2) = (short)(iVar12 - iVar16 >> uVar14);
            *(short *)(param_1 + (long)iVar17 * 2) = (short)(iVar9 + iVar10 >> uVar14);
            iVar17 = iVar17 + iVar20 * 4;
            *(short *)(param_1 + (long)iVar1 * 2) = (short)(iVar12 + iVar16 >> uVar14);
          }
          iVar15 = iVar15 + 2;
          lVar18 = lVar18 + 1;
        }
      }
      else {
        iVar16 = 0;
        iVar15 = uVar14 + 0xe;
        lVar18 = -(long)iVar7;
        for (iVar17 = 0; iVar17 < iVar20; iVar17 = iVar17 + 1) {
          lVar8 = (long)(iVar17 << (ulong)(uVar21 & 0x1f)) * 2;
          sVar4 = *(short *)(&DAT_00c4fb50 + lVar8);
          sVar5 = *(short *)(&DAT_00c4f950 + lVar8);
          lVar8 = lVar18;
          iVar10 = iVar16;
          while (lVar8 = lVar8 + iVar7, lVar8 < iVar6) {
            iVar12 = iVar7 + iVar10;
            iVar9 = iVar10 + 1;
            iVar2 = iVar13 + *(short *)(param_1 + (long)iVar10 * 2) * 0x4000;
            iVar11 = (int)*(short *)(param_1 + (long)iVar12 * 2);
            iVar3 = iVar13 + *(short *)(param_1 + (long)iVar9 * 2) * 0x4000;
            iVar22 = (int)*(short *)(param_1 + (long)(iVar12 + 1) * 2);
            iVar1 = (iVar11 * sVar4 + 1) - iVar22 * sVar5 >> 1;
            *(short *)(param_1 + (long)iVar12 * 2) = (short)(iVar2 - iVar1 >> iVar15);
            iVar11 = iVar22 * sVar4 + iVar11 * sVar5 + 1 >> 1;
            *(short *)(param_1 + (long)(iVar12 + 1) * 2) = (short)(iVar3 - iVar11 >> iVar15);
            *(short *)(param_1 + (long)iVar10 * 2) = (short)(iVar2 + iVar1 >> iVar15);
            iVar10 = iVar10 + iVar20 * 4;
            *(short *)(param_1 + (long)iVar9 * 2) = (short)(iVar3 + iVar11 >> iVar15);
          }
          iVar16 = iVar16 + 2;
          lVar18 = lVar18 + 1;
        }
      }
      uVar21 = uVar21 - 1;
      iVar20 = iVar7;
    }
  }
  else {
    iVar19 = -1;
  }
  return iVar19;
}


