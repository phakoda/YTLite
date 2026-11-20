/* Decompiled from supplied 5.2.2 arm package. VA 0x24de90. FUN_0024de90 */

void FUN_0024de90(undefined2 *param_1,long param_2,int param_3)

{
  long lVar1;
  
  for (lVar1 = 0; (int)lVar1 < param_3; lVar1 = lVar1 + 1) {
    *param_1 = *(undefined2 *)(param_2 + lVar1 * 2);
    param_1 = param_1 + -1;
  }
  return;
}


