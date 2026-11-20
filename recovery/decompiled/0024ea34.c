/* Decompiled from supplied 5.2.2 arm package. VA 0x24ea34. FUN_0024ea34 */

int FUN_0024ea34(long param_1,int param_2)

{
  int iVar1;
  short sVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = -1;
  if ((param_1 != 0) && (0 < param_2)) {
    iVar5 = 0;
    iVar3 = 0;
    for (lVar4 = 0; param_2 != (int)lVar4; lVar4 = lVar4 + 1) {
      sVar2 = *(short *)(param_1 + lVar4 * 2);
      iVar6 = -(int)sVar2;
      if (-1 < sVar2) {
        iVar6 = (int)sVar2;
      }
      iVar1 = (int)lVar4;
      if (iVar6 <= iVar5) {
        iVar1 = iVar3;
        iVar6 = iVar5;
      }
      iVar5 = iVar6;
      iVar3 = iVar1;
    }
  }
  return iVar3;
}


