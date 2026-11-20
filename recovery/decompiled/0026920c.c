/* Decompiled from supplied 5.2.2 arm package. VA 0x26920c. FUN_0026920c */

int FUN_0026920c(long param_1,long param_2,long param_3,long param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  
  iVar3 = 0;
  for (iVar4 = 0; iVar4 != 4; iVar4 = iVar4 + 1) {
    for (lVar5 = 0; lVar5 != 4; lVar5 = lVar5 + 1) {
      iVar2 = (uint)*(byte *)(param_1 + lVar5) - (uint)*(byte *)(param_3 + lVar5);
      iVar1 = -iVar2;
      if (-1 < iVar2) {
        iVar1 = iVar2;
      }
      iVar3 = iVar1 + iVar3;
    }
    param_1 = param_1 + param_2;
    param_3 = param_3 + param_4;
  }
  return iVar3;
}


