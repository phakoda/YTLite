/* Decompiled from supplied 5.2.2 arm package. VA 0x25af2c. FUN_0025af2c */

void FUN_0025af2c(long param_1,long param_2,long param_3,int param_4)

{
  long lVar1;
  
  for (lVar1 = 0; lVar1 < param_4; lVar1 = lVar1 + 1) {
    *(float *)(param_1 + lVar1 * 4) =
         *(float *)(param_2 + lVar1 * 4) * *(float *)(param_3 + lVar1 * 4);
  }
  return;
}


