/* Decompiled from supplied 5.2.2 arm package. VA 0x25afb4. FUN_0025afb4 */

void FUN_0025afb4(float param_1,long param_2,long param_3,int param_4)

{
  long lVar1;
  
  for (lVar1 = 0; lVar1 < param_4; lVar1 = lVar1 + 1) {
    *(float *)(param_2 + lVar1 * 4) = *(float *)(param_3 + lVar1 * 4) * param_1;
  }
  return;
}


