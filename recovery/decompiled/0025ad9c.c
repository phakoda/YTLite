/* Decompiled from supplied 5.2.2 arm package. VA 0x25ad9c. FUN_0025ad9c */

void FUN_0025ad9c(long param_1,long param_2,long param_3,int param_4)

{
  long lVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_3 + (long)(param_4 + -1) * 4);
  for (lVar1 = 0; lVar1 < param_4; lVar1 = lVar1 + 1) {
    *(int *)(param_1 + lVar1 * 4) =
         (int)((long)*piVar2 * (long)*(int *)(param_2 + lVar1 * 4) + 0x40000000U >> 0x1f);
    piVar2 = piVar2 + -1;
  }
  return;
}


