/* Decompiled from supplied 5.2.2 arm package. VA 0x24d244. FUN_0024d244 */

void FUN_0024d244(long param_1,uint *param_2,long param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  short sVar5;
  
  uVar2 = *param_2;
  if (uVar2 == 0) {
    sVar5 = 0;
  }
  else {
    uVar2 = uVar2 ^ (int)uVar2 >> 0x1f;
    uVar4 = 0;
    if (uVar2 >> 0xf == 0) {
      uVar4 = 0x10;
    }
    uVar1 = uVar4 | 8;
    if ((0xff800000U >> (ulong)uVar4 & uVar2) != 0) {
      uVar1 = uVar4;
    }
    uVar4 = uVar1 | 4;
    if ((0xf8000000U >> (ulong)uVar1 & uVar2) != 0) {
      uVar4 = uVar1;
    }
    uVar1 = uVar4 | 2;
    if ((0xe0000000U >> (ulong)uVar4 & uVar2) != 0) {
      uVar1 = uVar4;
    }
    sVar5 = (short)uVar1;
    if ((0xc0000000U >> (ulong)(uint)(int)sVar5 & uVar2) == 0) {
      sVar5 = sVar5 + 1;
    }
  }
  FUN_0024f0c0(param_2,param_4,param_2,(int)-sVar5);
  for (lVar3 = 0; lVar3 < param_4; lVar3 = lVar3 + 1) {
    uVar2 = param_2[lVar3];
    uVar4 = *(uint *)(param_3 + lVar3 * 4);
    *(int *)(param_1 + lVar3 * 4) =
         (((int)((uVar2 - (uVar2 & 0x10000)) * 0x8000) >> 0x10) * ((int)uVar4 >> 0x10) >> 0xe) +
         ((int)uVar2 >> 0x10) * ((int)uVar4 >> 0x10) * 2 +
         (((int)((uVar4 - (uVar4 & 0x10000)) * 0x8000) >> 0x10) * ((int)uVar2 >> 0x10) >> 0xe);
  }
  FUN_0024f0c0(param_1,param_4,param_1,sVar5);
  return;
}


