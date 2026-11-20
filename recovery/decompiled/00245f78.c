/* Decompiled from supplied 5.2.2 arm package. VA 0x245f78. FUN_00245f78 */

void FUN_00245f78(uint param_1,int param_2,short *param_3,short *param_4,long param_5,long param_6,
                 uint param_7,ulong param_8)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  short *psVar6;
  undefined2 *puVar7;
  short sVar8;
  
  lVar1 = (-(param_8 >> 0x1f & 1) & 0xfffffffe00000000 | (param_8 & 0xffffffff) << 1) + 2;
  psVar6 = (short *)(param_6 + lVar1);
  puVar7 = (undefined2 *)(param_5 + lVar1);
  for (sVar4 = 0; (int)sVar4 < param_2 + -1; sVar4 = sVar4 + 1) {
    sVar8 = 0;
    param_1 = ((int)*param_3 * (int)*param_3 - (int)*param_4 * (int)*param_4 >> (param_7 & 0x1f)) +
              param_1;
    if ((int)param_1 < 1) {
      param_1 = 0;
    }
    if (param_1 != 0) {
      uVar3 = param_1 ^ (int)param_1 >> 0x1f;
      uVar5 = 0;
      if (uVar3 >> 0xf == 0) {
        uVar5 = 0x10;
      }
      uVar2 = uVar5 | 8;
      if ((0xff800000U >> (ulong)uVar5 & uVar3) != 0) {
        uVar2 = uVar5;
      }
      uVar5 = uVar2 | 4;
      if ((0xf8000000U >> (ulong)uVar2 & uVar3) != 0) {
        uVar5 = uVar2;
      }
      uVar2 = uVar5 | 2;
      if ((0xe0000000U >> (ulong)uVar5 & uVar3) != 0) {
        uVar2 = uVar5;
      }
      sVar8 = (short)uVar2;
      if ((0xc0000000U >> (ulong)(uint)(int)sVar8 & uVar3) == 0) {
        sVar8 = sVar8 + 1;
      }
    }
    *psVar6 = sVar8;
    *puVar7 = (short)((param_1 << (ulong)((int)sVar8 & 0x1f)) >> 0x10);
    param_3 = param_3 + -1;
    param_4 = param_4 + -1;
    psVar6 = psVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  return;
}


