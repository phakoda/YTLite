/* Decompiled from supplied 5.2.2 arm package. VA 0x24eacc. FUN_0024eacc */

int FUN_0024eacc(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  
  iVar3 = -1;
  if ((param_1 != 0) && (0 < param_2)) {
    iVar3 = 0;
    iVar5 = -0x80000000;
    for (lVar4 = 0; param_2 != (int)lVar4; lVar4 = lVar4 + 1) {
      iVar1 = *(int *)(param_1 + lVar4 * 4);
      iVar2 = (int)lVar4;
      if (iVar1 <= iVar5) {
        iVar1 = iVar5;
        iVar2 = iVar3;
      }
      iVar3 = iVar2;
      iVar5 = iVar1;
    }
  }
  return iVar3;
}


