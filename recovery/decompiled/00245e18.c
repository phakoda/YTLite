/* Decompiled from supplied 5.2.2 arm package. VA 0x245e18. FUN_00245e18 */

void FUN_00245e18(long param_1,long param_2,uint param_3,ulong param_4,long param_5,long param_6)

{
  uint uVar1;
  short *psVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  short sVar9;
  uint uVar10;
  int iVar11;
  undefined2 *puVar12;
  short *psVar13;
  long lVar14;
  
  lVar8 = (-(param_4 >> 0x1f & 1) & 0xfffffffe00000000 | (param_4 & 0xffffffff) << 1) - 0x28;
  iVar5 = FUN_0024e098(param_2 + 0x100,param_2 + 0x100,0xf,param_3);
  iVar11 = 0x14;
  puVar12 = (undefined2 *)(param_5 + lVar8);
  psVar13 = (short *)(param_6 + lVar8);
  for (lVar14 = 0; lVar14 != -0x28; lVar14 = lVar14 + -2) {
    psVar2 = (short *)(param_2 + 0xfe + lVar14);
    iVar5 = ((uint)((int)*psVar2 * (int)*psVar2) >> (ulong)(param_3 & 0x1f)) + iVar5;
    iVar6 = FUN_0024e098(param_1,param_1,4,param_3);
    param_1 = param_1 + 8;
    iVar7 = FUN_0024e098(psVar2,psVar2,iVar11,param_3);
    uVar1 = iVar7 + iVar6 + iVar5;
    if (uVar1 == 0) {
      sVar9 = 0;
    }
    else {
      uVar4 = uVar1 ^ (int)uVar1 >> 0x1f;
      uVar10 = 0;
      if (uVar4 >> 0xf == 0) {
        uVar10 = 0x10;
      }
      uVar3 = uVar10 | 8;
      if ((0xff800000U >> (ulong)uVar10 & uVar4) != 0) {
        uVar3 = uVar10;
      }
      uVar10 = uVar3 | 4;
      if ((0xf8000000U >> (ulong)uVar3 & uVar4) != 0) {
        uVar10 = uVar3;
      }
      uVar3 = uVar10 | 2;
      if ((0xe0000000U >> (ulong)uVar10 & uVar4) != 0) {
        uVar3 = uVar10;
      }
      sVar9 = (short)uVar3;
      if ((0xc0000000U >> (ulong)(uint)(int)sVar9 & uVar4) == 0) {
        sVar9 = sVar9 + 1;
      }
    }
    *psVar13 = sVar9;
    *puVar12 = (short)((uVar1 << (ulong)((int)sVar9 & 0x1f)) >> 0x10);
    iVar11 = iVar11 + -1;
    puVar12 = puVar12 + 1;
    psVar13 = psVar13 + 1;
  }
  return;
}


