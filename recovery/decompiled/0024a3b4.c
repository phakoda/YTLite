/* Decompiled from supplied 5.2.2 arm package. VA 0x24a3b4. FUN_0024a3b4 */

void FUN_0024a3b4(long param_1,long param_2,long param_3,int param_4,int param_5)

{
  long lVar1;
  
  for (lVar1 = 0; lVar1 < param_5; lVar1 = lVar1 + 1) {
    *(short *)(param_1 + lVar1 * 2) =
         (short)((int)*(short *)(param_3 + lVar1 * 2) * (int)(short)(0x4000 - (short)param_4) +
                 *(short *)(param_2 + lVar1 * 2) * param_4 + 0x2000U >> 0xe);
  }
  return;
}


