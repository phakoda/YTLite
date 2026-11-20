/* Decompiled from supplied 5.2.2 arm package. VA 0x24d9c8. FUN_0024d9c8 */

undefined8 FUN_0024d9c8(long param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  
  iVar7 = 1 << (ulong)(param_2 & 0x1f);
  if (iVar7 < 0x401) {
    uVar13 = 9;
    iVar14 = 1;
    if (param_3 == 0) {
      while (iVar14 < iVar7) {
        iVar15 = 0;
        iVar8 = iVar14 * 2;
        lVar10 = -(long)iVar8;
        for (iVar16 = 0; iVar16 < iVar14; iVar16 = iVar16 + 1) {
          lVar11 = (long)(iVar16 << (ulong)(uVar13 & 0x1f)) * 2;
          sVar5 = *(short *)(&DAT_00c4f950 + lVar11);
          sVar6 = *(short *)(&DAT_00c4fb50 + lVar11);
          lVar11 = lVar10;
          iVar4 = iVar15;
          while (lVar11 = lVar11 + iVar8, lVar11 < iVar7) {
            iVar3 = iVar8 + iVar4;
            iVar2 = iVar4 + 1;
            iVar17 = (int)*(short *)(param_1 + (long)iVar3 * 2);
            iVar12 = (int)*(short *)(param_1 + (long)(iVar3 + 1) * 2);
            iVar1 = iVar17 * -sVar5 + iVar12 * sVar6 >> 0xf;
            iVar18 = (int)*(short *)(param_1 + (long)iVar2 * 2);
            iVar17 = iVar17 * sVar6 - iVar12 * -sVar5 >> 0xf;
            iVar12 = (int)*(short *)(param_1 + (long)iVar4 * 2);
            *(short *)(param_1 + (long)iVar3 * 2) = (short)((uint)(iVar12 - iVar17) >> 1);
            *(short *)(param_1 + (long)(iVar3 + 1) * 2) = (short)((uint)(iVar18 - iVar1) >> 1);
            *(short *)(param_1 + (long)iVar4 * 2) = (short)((uint)(iVar12 + iVar17) >> 1);
            iVar4 = iVar4 + iVar14 * 4;
            *(short *)(param_1 + (long)iVar2 * 2) = (short)((uint)(iVar18 + iVar1) >> 1);
          }
          iVar15 = iVar15 + 2;
          lVar10 = lVar10 + 1;
        }
        uVar13 = uVar13 - 1;
        iVar14 = iVar8;
      }
    }
    else {
      while (iVar14 < iVar7) {
        iVar15 = 0;
        iVar8 = iVar14 * 2;
        lVar10 = -(long)iVar8;
        for (iVar16 = 0; iVar16 < iVar14; iVar16 = iVar16 + 1) {
          lVar11 = (long)(iVar16 << (ulong)(uVar13 & 0x1f)) * 2;
          sVar5 = *(short *)(&DAT_00c4f950 + lVar11);
          sVar6 = *(short *)(&DAT_00c4fb50 + lVar11);
          lVar11 = lVar10;
          iVar4 = iVar15;
          while (lVar11 = lVar11 + iVar8, lVar11 < iVar7) {
            iVar18 = iVar8 + iVar4;
            iVar2 = iVar4 + 1;
            iVar17 = (int)*(short *)(param_1 + (long)iVar18 * 2);
            iVar3 = *(short *)(param_1 + (long)iVar4 * 2) * 0x4000 + 0x4000;
            iVar19 = (int)*(short *)(param_1 + (long)(iVar18 + 1) * 2);
            iVar12 = *(short *)(param_1 + (long)iVar2 * 2) * 0x4000 + 0x4000;
            iVar1 = (iVar17 * sVar6 + 1) - iVar19 * -sVar5 >> 1;
            *(short *)(param_1 + (long)iVar18 * 2) = (short)((uint)(iVar3 - iVar1) >> 0xf);
            iVar17 = iVar19 * sVar6 + iVar17 * -sVar5 + 1 >> 1;
            *(short *)(param_1 + (long)(iVar18 + 1) * 2) = (short)((uint)(iVar12 - iVar17) >> 0xf);
            *(short *)(param_1 + (long)iVar4 * 2) = (short)((uint)(iVar3 + iVar1) >> 0xf);
            iVar4 = iVar4 + iVar14 * 4;
            *(short *)(param_1 + (long)iVar2 * 2) = (short)((uint)(iVar12 + iVar17) >> 0xf);
          }
          iVar15 = iVar15 + 2;
          lVar10 = lVar10 + 1;
        }
        uVar13 = uVar13 - 1;
        iVar14 = iVar8;
      }
    }
    uVar9 = 0;
  }
  else {
    uVar9 = 0xffffffff;
  }
  return uVar9;
}


