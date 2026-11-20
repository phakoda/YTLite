/* Decompiled from supplied 5.2.2 arm package. VA 0x25ad60. FUN_0025ad60 */

void FUN_0025ad60(long param_1,long param_2,long param_3,long param_4,int param_5)

{
  long lVar1;
  
  for (lVar1 = 0; lVar1 < param_5; lVar1 = lVar1 + 1) {
    *(int *)(param_1 + lVar1 * 4) =
         (int)((long)*(int *)(param_3 + lVar1 * 4) * (long)*(int *)(param_2 + lVar1 * 4) +
               0x40000000U >> 0x1f) + *(int *)(param_4 + lVar1 * 4);
  }
  return;
}


