/* Decompiled from supplied 5.2.2 arm package. VA 0x245af8. FUN_00245af8 */

void FUN_00245af8(undefined2 *param_1,undefined2 *param_2,long param_3,int param_4)

{
  long lVar1;
  
  *param_1 = *param_2;
  for (lVar1 = 1; lVar1 < param_4; lVar1 = lVar1 + 1) {
    param_1[lVar1] =
         (short)((int)(short)param_2[lVar1] * (int)*(short *)(param_3 + lVar1 * 2) + 0x4000U >> 0xf)
    ;
  }
  return;
}


