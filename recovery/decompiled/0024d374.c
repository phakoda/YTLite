/* Decompiled from supplied 5.2.2 arm package. VA 0x24d374. FUN_0024d374 */

int FUN_0024d374(undefined8 param_1,long param_2,undefined8 param_3,int param_4,int param_5,
                uint param_6)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  long lVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  long local_88;
  int local_64;
  
  iVar15 = (int)param_3;
  if ((param_6 & 0xffff) == 1) {
    iVar8 = (*DAT_0191b7d0)(param_2,(param_4 + iVar15) * 0x10000 + -0x10000 >> 0x10);
    local_88 = param_2;
  }
  else {
    iVar8 = (*DAT_0191b7d0)(param_2 + (long)-param_4 * 2,
                            (param_4 + iVar15) * 0x10000 + -0x10000 >> 0x10);
    local_88 = param_2 + -2;
    iVar15 = iVar15 + -1;
  }
  iVar3 = (uint)(5000 < iVar8) << 1;
  iVar9 = FUN_0024e098(param_2,param_2,param_3,(ulong)(5000 < iVar8) << 1);
  lVar14 = 0;
  uVar13 = 0;
  uVar18 = 0;
  local_64 = 0;
  iVar17 = 0xfe0c;
  iVar16 = 0x7fff;
  for (iVar8 = 0; iVar8 < param_4; iVar8 = iVar8 + 1) {
    iVar10 = FUN_0024e098(param_1,param_2 + (long)(short)uVar18 * 2,param_3,iVar3);
    iVar11 = iVar16;
    uVar4 = uVar13;
    iVar7 = iVar17;
    iVar6 = local_64;
    if (0 < iVar9 && 0 < iVar10) {
      iVar11 = FUN_0024d60c(iVar10);
      uVar5 = iVar11 * 0x10000 - 0x100000;
      sVar2 = (short)(iVar10 << (ulong)((int)uVar5 >> 0x10 & 0x1f));
      if ((int)uVar5 < -0xffff) {
        sVar2 = (short)(iVar10 >> (-((int)uVar5 >> 0x10) & 0x1fU));
      }
      iVar11 = FUN_0024d60c(iVar9);
      iVar6 = iVar11 * 0x10000 + -0x100000;
      uVar1 = iVar6 >> 0x10;
      uVar4 = (uint)((int)sVar2 * (int)sVar2) >> 0x10;
      iVar7 = uVar1 - (uVar5 >> 0xf);
      iVar11 = iVar9 << (ulong)(uVar1 & 0x1f);
      if (iVar6 < -0xffff) {
        iVar11 = iVar9 >> (-uVar1 & 0x1f);
      }
      uVar5 = (uint)(short)((short)iVar7 - (short)iVar17);
      if (0x1e < (int)uVar5) {
        uVar5 = 0x1f;
      }
      if ((int)uVar5 < -0x1e) {
        uVar5 = 0xffffffe1;
      }
      iVar10 = uVar4 * (int)(short)iVar16;
      if ((int)uVar5 < 0) {
        iVar10 = iVar10 >> (-uVar5 & 0x1f);
        iVar12 = (int)(short)iVar11 * (int)(short)uVar13;
      }
      else {
        iVar12 = (int)(short)iVar11 * (int)(short)uVar13 >> (uVar5 & 0x1f);
      }
      iVar6 = iVar8;
      if (iVar10 <= iVar12) {
        iVar11 = iVar16;
        uVar4 = uVar13;
        iVar7 = iVar17;
        iVar6 = local_64;
      }
    }
    local_64 = iVar6;
    iVar17 = iVar7;
    uVar13 = uVar4;
    iVar16 = iVar11;
    uVar18 = param_6 + (uVar18 & 0xffff);
    iVar11 = (int)*(short *)(param_2 + (long)iVar15 * 2 + lVar14);
    iVar9 = iVar9 + (iVar11 * iVar11 -
                     (int)*(short *)(local_88 + lVar14) * (int)*(short *)(local_88 + lVar14) >>
                    iVar3) * param_6;
    lVar14 = lVar14 + (-(ulong)(param_6 >> 0x1f) & 0xfffffffe00000000 | (ulong)param_6 << 1);
  }
  return param_5 + (short)local_64;
}


