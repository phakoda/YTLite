/* Decompiled from supplied 5.2.2 arm package. VA 0x24ea04. FUN_0024ea04 */

void FUN_0024ea04(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != (int *)0x0) && (iVar2 = 0x7fffffff, 0 < param_2)) {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      iVar1 = *param_1;
      if (iVar2 <= *param_1) {
        iVar1 = iVar2;
      }
      param_1 = param_1 + 1;
      iVar2 = iVar1;
    }
  }
  return;
}


