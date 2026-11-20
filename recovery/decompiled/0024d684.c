/* Decompiled from supplied 5.2.2 arm package. VA 0x24d684. FUN_0024d684 */

int FUN_0024d684(short *param_1,uint param_2,uint param_3,int *param_4,uint *param_5)

{
  short *psVar1;
  short *psVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  bool bVar7;
  uint uVar8;
  long lVar9;
  short *psVar10;
  short *psVar11;
  long lVar12;
  short sVar13;
  int iVar14;
  uint uVar15;
  short *psVar16;
  long lVar17;
  int iVar18;
  undefined8 uVar19;
  
  if ((int)param_2 < (int)param_3) {
    return -1;
  }
  uVar3 = param_2;
  if (-1 < (int)param_3) {
    uVar3 = param_3;
  }
  uVar8 = (*DAT_0191b7d0)(param_1,param_2);
  if ((uVar8 & 0xffff) != 0) {
    bVar7 = param_2 >> 0x10 != 0;
    lVar12 = (ulong)bVar7 << 4;
    uVar15 = (uint)lVar12;
    if ((0xff00 << lVar12 & param_2) != 0) {
      uVar15 = (uint)bVar7 << 4 | 8;
    }
    if ((0xf0 << (ulong)uVar15 & param_2) != 0) {
      uVar15 = uVar15 | 4;
    }
    uVar6 = (ushort)uVar15;
    if ((0xc << (ulong)uVar15 & param_2) != 0) {
      uVar6 = (ushort)uVar15 | 2;
    }
    if ((2 << (ulong)(uint)(int)(short)uVar6 & param_2) != 0) {
      uVar6 = uVar6 + 1;
    }
    if ((1 << (ulong)((int)(short)uVar6 & 0x1f) & param_2) != 0) {
      uVar6 = uVar6 + 1;
    }
    uVar8 = uVar8 * uVar8;
    if (uVar8 == 0) {
      sVar13 = 0;
    }
    else {
      uVar15 = 0;
      if (uVar8 >> 0xf == 0) {
        uVar15 = 0x10;
      }
      uVar4 = uVar15 | 8;
      if ((0xff800000U >> (ulong)uVar15 & uVar8) != 0) {
        uVar4 = uVar15;
      }
      uVar15 = uVar4 | 4;
      if ((0xf8000000U >> (ulong)uVar4 & uVar8) != 0) {
        uVar15 = uVar4;
      }
      uVar4 = uVar15 | 2;
      if ((0xe0000000U >> (ulong)uVar15 & uVar8) != 0) {
        uVar4 = uVar15;
      }
      sVar13 = (short)uVar4;
      if ((0xc0000000U >> (ulong)(uint)(int)sVar13 & uVar8) == 0) {
        sVar13 = sVar13 + 1;
      }
    }
    uVar8 = (int)(short)uVar6 - (int)sVar13;
    if ((uint)(int)sVar13 <= (uint)(int)(short)uVar6) goto LAB_0024d7d8;
  }
  uVar8 = 0;
LAB_0024d7d8:
  lVar12 = 0;
  iVar14 = param_2 - 3;
  psVar16 = param_1;
  while( true ) {
    iVar5 = iVar14;
    if (iVar14 < 1) {
      iVar5 = 0;
    }
    if ((int)uVar3 < lVar12) break;
    iVar18 = 0;
    lVar17 = (long)(int)(iVar5 + 3U & 0xfffffffc);
    psVar10 = psVar16;
    psVar11 = param_1 + 3;
    for (lVar9 = 0; lVar9 < ((int)param_2 - lVar12) + -3; lVar9 = lVar9 + 4) {
      psVar1 = psVar11 + -3;
      sVar13 = *psVar11;
      psVar2 = psVar11 + lVar12;
      uVar19 = NEON_sshl(CONCAT44((int)psVar10[2] * (int)psVar11[-1],
                                  (int)psVar10[1] * (int)psVar11[-2]),CONCAT44(-uVar8,-uVar8),4);
      psVar11 = psVar11 + 4;
      iVar18 = ((int)*psVar10 * (int)*psVar1 >> (uVar8 & 0x1f)) + iVar18 + (int)uVar19 +
               (int)((ulong)uVar19 >> 0x20) + ((int)*psVar2 * (int)sVar13 >> (uVar8 & 0x1f));
      psVar10 = psVar10 + 4;
    }
    for (; lVar17 < (int)param_2 - lVar12; lVar17 = lVar17 + 1) {
      iVar18 = ((int)psVar16[lVar17] * (int)param_1[lVar17] >> (uVar8 & 0x1f)) + iVar18;
    }
    *param_4 = iVar18;
    lVar12 = lVar12 + 1;
    iVar14 = iVar14 + -1;
    psVar16 = psVar16 + 1;
    param_4 = param_4 + 1;
  }
  *param_5 = uVar8;
  return uVar3 + 1;
}


