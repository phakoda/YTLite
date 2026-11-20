/* Decompiled from supplied 5.2.2 arm package. VA 0x24eb14. FUN_0024eb14 */

int FUN_0024eb14(long param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  short sVar5;
  
  iVar3 = -1;
  if ((param_1 != 0) && (0 < param_2)) {
    iVar3 = 0;
    sVar5 = 0x7fff;
    for (lVar4 = 0; param_2 != (int)lVar4; lVar4 = lVar4 + 1) {
      sVar1 = *(short *)(param_1 + lVar4 * 2);
      iVar2 = (int)lVar4;
      if (sVar5 <= sVar1) {
        sVar1 = sVar5;
        iVar2 = iVar3;
      }
      iVar3 = iVar2;
      sVar5 = sVar1;
    }
  }
  return iVar3;
}


