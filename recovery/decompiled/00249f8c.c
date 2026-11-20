/* Decompiled from supplied 5.2.2 arm package. VA 0x249f8c. FUN_00249f8c */

void FUN_00249f8c(long param_1,short *param_2,short *param_3,short *param_4,int param_5)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  short sVar15;
  int iVar16;
  long lVar17;
  
  for (lVar17 = 0; lVar17 < param_5; lVar17 = lVar17 + 1) {
    sVar4 = param_3[1];
    sVar5 = param_2[3];
    sVar6 = param_3[3];
    sVar7 = param_2[4];
    sVar8 = *param_3;
    sVar9 = param_3[2];
    sVar15 = *(short *)(param_1 + lVar17 * 2);
    sVar10 = *param_2;
    sVar11 = *param_4;
    sVar12 = param_2[1];
    sVar13 = param_4[1];
    sVar14 = param_2[2];
    param_4[1] = sVar11;
    *param_4 = *(short *)(param_1 + lVar17 * 2);
    iVar16 = (int)sVar10 * (int)sVar15 +
             ((int)sVar8 * (int)sVar5 + ((int)sVar5 * (int)sVar4 + (int)sVar7 * (int)sVar6 >> 0xf) +
             (int)sVar9 * (int)sVar7) * 2 + (int)sVar12 * (int)sVar11 + (int)sVar14 * (int)sVar13;
    uVar1 = iVar16 + 0x400;
    uVar3 = 0xfc000000;
    if (-0x4000001 < (int)uVar1) {
      uVar3 = uVar1;
    }
    uVar2 = 0x7fff;
    if ((int)uVar1 < 0x4000000) {
      uVar2 = (short)(uVar3 >> 0xb);
    }
    *(undefined2 *)(param_1 + lVar17 * 2) = uVar2;
    param_3[2] = *param_3;
    param_3[3] = param_3[1];
    if (iVar16 < 0x10000000) {
      uVar1 = 0x80000000;
      if (-0x10000001 < iVar16) {
        uVar1 = iVar16 * 8;
      }
    }
    else {
      uVar1 = 0x7fffffff;
    }
    *param_3 = (short)(uVar1 >> 0x10);
    param_3[1] = (ushort)(uVar1 >> 1) & 0x7fff;
  }
  return;
}


