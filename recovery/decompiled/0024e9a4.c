/* Decompiled from supplied 5.2.2 arm package. VA 0x24e9a4. FUN_0024e9a4 */

void FUN_0024e9a4(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != (int *)0x0) && (iVar2 = -0x80000000, 0 < param_2)) {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      iVar1 = *param_1;
      if (*param_1 <= iVar2) {
        iVar1 = iVar2;
      }
      param_1 = param_1 + 1;
      iVar2 = iVar1;
    }
  }
  return;
}


