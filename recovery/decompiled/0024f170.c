/* Decompiled from supplied 5.2.2 arm package. VA 0x24f170. FUN_0024f170 */

void FUN_0024f170(long param_1,long param_2,int param_3,int param_4,uint param_5)

{
  long lVar1;
  
  for (lVar1 = 0; (int)lVar1 < param_4; lVar1 = lVar1 + 1) {
    *(short *)(param_2 + lVar1 * 2) =
         (short)(*(short *)(param_1 + lVar1 * 2) * param_3 >> (param_5 & 0x1f));
  }
  return;
}


