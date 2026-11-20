/* Decompiled from supplied 5.2.2 arm package. VA 0x27f53c. FUN_0027f53c */

void FUN_0027f53c(long param_1,long param_2,long param_3,int param_4,int param_5)

{
  long lVar1;
  long lVar2;
  long lVar3;
  float *pfVar4;
  long lVar5;
  float fVar6;
  
  for (lVar1 = 0; lVar1 < param_5; lVar1 = lVar1 + 1) {
    lVar2 = *(long *)(param_3 + lVar1 * 8);
    lVar3 = *(long *)(param_1 + lVar1 * 8);
    pfVar4 = *(float **)(param_2 + lVar1 * 8);
    for (lVar5 = 0; lVar5 < param_4; lVar5 = lVar5 + 1) {
      fVar6 = *(float *)(lVar2 + lVar5 * 4);
      *(float *)(lVar3 + lVar5 * 4) = fVar6 - *pfVar4;
      *pfVar4 = fVar6;
    }
  }
  return;
}


