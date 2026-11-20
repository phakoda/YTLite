/* Decompiled from supplied 5.2.2 arm package. VA 0x25afdc. FUN_0025afdc */

void FUN_0025afdc(double param_1,long param_2,long param_3,int param_4)

{
  long lVar1;
  
  for (lVar1 = 0; lVar1 < param_4; lVar1 = lVar1 + 1) {
    *(double *)(param_2 + lVar1 * 8) =
         *(double *)(param_2 + lVar1 * 8) + *(double *)(param_3 + lVar1 * 8) * param_1;
  }
  return;
}


