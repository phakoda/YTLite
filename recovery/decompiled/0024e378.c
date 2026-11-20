/* Decompiled from supplied 5.2.2 arm package. VA 0x24e378. FUN_0024e378 */

void FUN_0024e378(long param_1,long param_2,short *param_3,int param_4,uint param_5)

{
  long lVar1;
  
  for (lVar1 = 0; (int)lVar1 < param_4; lVar1 = lVar1 + 1) {
    *(short *)(param_1 + lVar1 * 2) =
         (short)((int)*param_3 * (int)*(short *)(param_2 + lVar1 * 2) >> (param_5 & 0x1f));
    param_3 = param_3 + -1;
  }
  return;
}


