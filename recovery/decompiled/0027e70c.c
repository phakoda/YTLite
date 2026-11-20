/* Decompiled from supplied 5.2.2 arm package. VA 0x27e70c. FUN_0027e70c */

void FUN_0027e70c(double param_1,double *param_2,int param_3,int param_4,long param_5)

{
  long lVar1;
  long lVar2;
  double *pdVar3;
  double dVar4;
  
  for (lVar1 = 0; lVar1 <= param_3; lVar1 = lVar1 + 1) {
    dVar4 = 0.0;
    pdVar3 = param_2;
    for (lVar2 = 0; lVar1 + lVar2 < (long)param_4; lVar2 = lVar2 + 1) {
      dVar4 = dVar4 + pdVar3[lVar1] * *pdVar3;
      pdVar3 = pdVar3 + 1;
    }
    *(double *)(param_5 + lVar1 * 8) = dVar4 * param_1;
  }
  return;
}


