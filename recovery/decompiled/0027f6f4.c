/* Decompiled from supplied 5.2.2 arm package. VA 0x27f6f4. FUN_0027f6f4 */

void FUN_0027f6f4(long param_1,long param_2,long param_3,int param_4,int param_5)

{
  long lVar1;
  long lVar2;
  long lVar3;
  double *pdVar4;
  long lVar5;
  double dVar6;
  
  for (lVar1 = 0; lVar1 < param_5; lVar1 = lVar1 + 1) {
    lVar2 = *(long *)(param_3 + lVar1 * 8);
    lVar3 = *(long *)(param_1 + lVar1 * 8);
    pdVar4 = *(double **)(param_2 + lVar1 * 8);
    for (lVar5 = 0; lVar5 < param_4; lVar5 = lVar5 + 1) {
      dVar6 = *(double *)(lVar2 + lVar5 * 8) + *pdVar4;
      *(double *)(lVar3 + lVar5 * 8) = dVar6;
      *pdVar4 = dVar6;
    }
  }
  return;
}


