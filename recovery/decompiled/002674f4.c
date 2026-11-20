/* Decompiled from supplied 5.2.2 arm package. VA 0x2674f4. FUN_002674f4 */

int FUN_002674f4(long *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  long lVar2;
  int iVar3;
  
  lVar2 = 0;
  iVar1 = 0;
  while (((int)lVar2 < param_4 && (iVar3 = (int)*(char *)(*param_1 + lVar2), iVar3 - 0x30U < 10))) {
    iVar1 = iVar3 + iVar1 * 10 + -0x30;
    lVar2 = lVar2 + 1;
  }
  if ((lVar2 != 0) && (param_2 <= iVar1 && iVar1 <= param_3)) {
    *param_1 = *param_1 + lVar2;
    return iVar1;
  }
  return -1;
}


