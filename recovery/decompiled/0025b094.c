/* Decompiled from supplied 5.2.2 arm package. VA 0x25b094. FUN_0025b094 */

void FUN_0025b094(long param_1,long param_2,long param_3,long param_4,int param_5)

{
  long lVar1;
  
  for (lVar1 = 0; lVar1 < param_5; lVar1 = lVar1 + 1) {
    *(float *)(param_1 + lVar1 * 4) =
         *(float *)(param_2 + lVar1 * 4) * *(float *)(param_3 + lVar1 * 4) +
         *(float *)(param_4 + lVar1 * 4);
  }
  return;
}


