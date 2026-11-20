/* Decompiled from supplied 5.2.2 arm package. VA 0x24df78. FUN_0024df78 */

int FUN_0024df78(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 != 0) {
    iVar2 = param_1 / (int)param_2;
  }
  iVar1 = 0x7fffffff;
  if ((param_2 & 0xffff) != 0) {
    iVar1 = iVar2;
  }
  return iVar1;
}


