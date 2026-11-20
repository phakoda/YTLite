/* Decompiled from supplied 5.2.2 arm package. VA 0x25b0fc. FUN_0025b0fc */

void FUN_0025b0fc(long param_1,long param_2,int param_3)

{
  long lVar1;
  float fVar2;
  float fVar3;
  
  for (lVar1 = 0; lVar1 < param_3; lVar1 = lVar1 + 1) {
    fVar2 = *(float *)(param_1 + lVar1 * 4);
    fVar3 = *(float *)(param_2 + lVar1 * 4);
    *(float *)(param_1 + lVar1 * 4) = fVar2 + fVar3;
    *(float *)(param_2 + lVar1 * 4) = fVar2 - fVar3;
  }
  return;
}


