/* Decompiled from supplied 5.2.2 arm package. VA 0x25b034. FUN_0025b034 */

void FUN_0025b034(long param_1,long param_2,long param_3,long param_4,int param_5)

{
  long lVar1;
  ulong uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  param_1 = param_1 + (long)param_5 * 4;
  param_4 = param_4 + (long)param_5 * 4;
  uVar2 = -(ulong)(param_5 - 1U >> 0x1f) & 0xfffffffc00000000 | (ulong)(param_5 - 1U) << 2;
  for (lVar1 = (long)-param_5; lVar1 < 0; lVar1 = lVar1 + 1) {
    fVar3 = *(float *)(param_2 + (long)param_5 * 4 + lVar1 * 4);
    fVar4 = *(float *)(param_3 + uVar2);
    fVar5 = *(float *)(param_4 + uVar2);
    fVar6 = *(float *)(param_4 + lVar1 * 4);
    *(float *)(param_1 + lVar1 * 4) = fVar3 * fVar5 - fVar4 * fVar6;
    *(float *)(param_1 + uVar2) = fVar3 * fVar6 + fVar4 * fVar5;
    uVar2 = uVar2 - 4;
  }
  return;
}


