/* Decompiled from supplied 5.2.2 arm package. VA 0x24f1d8. FUN_0024f1d8 */

void FUN_0024f1d8(long param_1,int param_2,uint param_3,long param_4,int param_5,uint param_6,
                 long param_7,int param_8)

{
  long lVar1;
  
  for (lVar1 = 0; (int)lVar1 < param_8; lVar1 = lVar1 + 1) {
    *(short *)(param_7 + lVar1 * 2) =
         (short)(*(short *)(param_4 + lVar1 * 2) * param_5 >> (param_6 & 0x1f)) +
         (short)(*(short *)(param_1 + lVar1 * 2) * param_2 >> (param_3 & 0x1f));
  }
  return;
}


