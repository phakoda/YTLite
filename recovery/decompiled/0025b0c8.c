/* Decompiled from supplied 5.2.2 arm package. VA 0x25b0c8. FUN_0025b0c8 */

void FUN_0025b0c8(long param_1,long param_2,long param_3,int param_4)

{
  long lVar1;
  float *pfVar2;
  
  pfVar2 = (float *)(param_3 + (long)(param_4 + -1) * 4);
  for (lVar1 = 0; lVar1 < param_4; lVar1 = lVar1 + 1) {
    *(float *)(param_1 + lVar1 * 4) = *(float *)(param_2 + lVar1 * 4) * *pfVar2;
    pfVar2 = pfVar2 + -1;
  }
  return;
}


