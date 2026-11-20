/* Decompiled from supplied 5.2.2 arm package. VA 0x24e3f4. FUN_0024e3f4 */

void FUN_0024e3f4(long param_1,long param_2,int param_3,int param_4,uint param_5,int param_6)

{
  long lVar1;
  
  for (lVar1 = 0; (int)lVar1 < param_6; lVar1 = lVar1 + 1) {
    *(short *)(param_1 + lVar1 * 2) =
         (short)(param_4 + *(short *)(param_2 + lVar1 * 2) * param_3 >> (param_5 & 0x1f)) +
         *(short *)(param_1 + lVar1 * 2);
  }
  return;
}


