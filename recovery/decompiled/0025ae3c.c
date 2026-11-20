/* Decompiled from supplied 5.2.2 arm package. VA 0x25ae3c. _avpriv_scalarproduct_float_c */

float _avpriv_scalarproduct_float_c(long param_1,long param_2,int param_3)

{
  long lVar1;
  float fVar2;
  
  fVar2 = 0.0;
  for (lVar1 = 0; lVar1 < param_3; lVar1 = lVar1 + 1) {
    fVar2 = fVar2 + *(float *)(param_1 + lVar1 * 4) * *(float *)(param_2 + lVar1 * 4);
  }
  return fVar2;
}


