/* Decompiled from supplied 5.2.2 arm package. VA 0x24be5c. FUN_0024be5c */

void FUN_0024be5c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  short sVar12;
  int iVar13;
  
  iVar6 = (*DAT_0191b7d0)(param_2,0x50);
  iVar7 = (*DAT_0191b7d0)(param_3,0x50);
  if (iVar6 <= iVar7) {
    iVar6 = iVar7;
  }
  iVar6 = FUN_0024c22c(iVar6);
  iVar6 = iVar6 * 0x20000 + -0x1a0000 >> 0x10;
  iVar7 = 0;
  if (-1 < iVar6) {
    iVar7 = iVar6;
  }
  iVar8 = FUN_0024e098(param_2,param_2,0x50,iVar7);
  iVar9 = FUN_0024e098(param_3,param_3,0x50,iVar7);
  iVar10 = FUN_0024e098(param_3,param_2,0x50,iVar7);
  iVar6 = -iVar10;
  if (-1 < iVar10) {
    iVar6 = iVar10;
  }
  iVar3 = 0x7fffffff;
  if (-1 < iVar8) {
    iVar3 = iVar8;
  }
  iVar8 = 0x7fffffff;
  if (-1 < iVar9) {
    iVar8 = iVar9;
  }
  iVar9 = FUN_0024c22c(iVar3);
  iVar11 = FUN_0024c22c(iVar8);
  sVar4 = FUN_0024c22c(iVar6);
  sVar12 = 0x1f - (short)iVar9;
  sVar5 = (short)(0xf - iVar11);
  iVar6 = sVar12 + -0x10;
  if (sVar5 <= iVar6) {
    sVar12 = sVar5 + 0x10;
    iVar6 = 0xf - iVar11;
  }
  iVar13 = iVar3 << (ulong)((int)sVar12 & 0x1f);
  sVar5 = (short)(iVar8 << (ulong)((int)(short)iVar6 & 0x1f));
  if (iVar6 * 0x10000 < -0xffff) {
    sVar5 = (short)(iVar8 >> (-(int)(short)iVar6 & 0x1fU));
  }
  if (sVar5 < 0x41) {
    sVar5 = 1;
  }
  else {
    iVar6 = FUN_0024df78(iVar13);
    sVar5 = FUN_0024eebc(iVar6 << 6);
  }
  iVar6 = FUN_0024c2ac(param_1,param_2,param_3,(int)sVar5);
  uVar1 = (int)sVar12 + (6 - iVar7);
  if ((int)uVar1 < 0x20) {
    iVar7 = (iVar13 >> 0xe) * 0x333;
    iVar13 = iVar7 << (ulong)(-uVar1 & 0x1f);
    if (0 < (int)uVar1) {
      iVar13 = iVar7 >> (uVar1 & 0x1f);
    }
  }
  else {
    iVar13 = 0;
  }
  if (iVar6 <= iVar13) {
    return;
  }
  iVar6 = 1;
  if (0 < iVar3) {
    iVar6 = iVar3;
  }
  iVar7 = iVar11 + 0xfff1;
  if ((iVar11 + 0xfff1) * 0x10000 <= (iVar9 + 0xfff1) * 0x10000) {
    iVar7 = iVar9 + 0xfff1;
  }
  iVar3 = iVar7 * 0x10000;
  uVar1 = (uint)(short)iVar7;
  uVar2 = -(int)(short)iVar7;
  sVar12 = (short)(iVar6 << (ulong)(uVar2 & 0x1f));
  if (0xffff < iVar3) {
    sVar12 = (short)(iVar6 >> (uVar1 & 0x1f));
  }
  iVar7 = (int)sVar12;
  sVar12 = (short)(iVar10 << (ulong)(uVar2 & 0x1f));
  if (0xffff < iVar3) {
    sVar12 = (short)(iVar10 >> (uVar1 & 0x1f));
  }
  if ((uint)(iVar7 * iVar7) < 0x10001) {
    iVar7 = 0x10000;
LAB_0024c0fc:
    iVar8 = FUN_0024c22c(iVar7);
    iVar8 = iVar8 * 0x10000 + -0xf0000;
    uVar1 = iVar8 >> 0x10;
    uVar2 = 0x328f5c29 >> (ulong)(uVar1 & 0x1f);
    if (iVar8 < 1) {
      uVar1 = 0;
      uVar2 = 0x328f5c29;
    }
    FUN_0024df78(uVar2,(int)(short)(iVar7 >> (uVar1 & 0x1f)));
    sVar5 = FUN_0024eebc();
    iVar3 = 0x15 - (short)(0x1f - sVar4);
    sVar12 = (short)iVar3;
    iVar7 = (iVar9 - sVar12) * 0x10000 + -0xf0000;
    iVar8 = iVar6 << (ulong)(-(int)sVar12 & 0x1f);
    if (0xffff < iVar3 * 0x10000) {
      iVar8 = iVar6 >> ((int)sVar12 & 0x1fU);
    }
    uVar1 = iVar7 >> 0x10;
    if (iVar7 < 1) {
      uVar1 = 0;
    }
    iVar8 = iVar8 >> (uVar1 & 0x1f);
    iVar6 = (iVar10 << (ulong)((int)(short)(0x1f - sVar4) & 0x1f)) >> (uVar1 & 0x1f);
    if (0 < iVar8 && 0 < iVar6) {
      iVar6 = FUN_0024df78(iVar6,(int)(short)iVar8);
      iVar7 = FUN_0024c22c();
      iVar8 = FUN_0024c22c((int)sVar5);
      if (iVar8 + iVar7 < 0x20) {
        sVar12 = (short)((uint)(0x3e666666 - iVar6 * sVar5) >> 0x10);
      }
      else {
        sVar12 = 0;
      }
      goto LAB_0024c1f0;
    }
  }
  else {
    sVar5 = (short)(iVar8 << (ulong)(uVar2 & 0x1f));
    if (0xffff < iVar3) {
      sVar5 = (short)(iVar8 >> (uVar1 & 0x1f));
    }
    iVar3 = sVar5 * iVar7 - (int)sVar12 * (int)sVar12;
    iVar8 = 0;
    if (-1 < iVar3) {
      iVar8 = iVar3;
    }
    iVar7 = FUN_0024df78(iVar8,iVar7 * iVar7 >> 0x10);
    if (7 < iVar7) goto LAB_0024c0fc;
  }
  sVar5 = 0;
  sVar12 = 0x4000;
LAB_0024c1f0:
  FUN_0024f1d8(param_3,(int)sVar5,9,param_2,(int)sVar12,0xe,param_1,0x50);
  return;
}


