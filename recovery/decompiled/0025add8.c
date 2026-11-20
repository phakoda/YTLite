/* Decompiled from supplied 5.2.2 arm package. VA 0x25add8. FUN_0025add8 */

void FUN_0025add8(long param_1,long param_2,int param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  for (lVar3 = 0; lVar3 < param_3; lVar3 = lVar3 + 1) {
    iVar1 = *(int *)(param_1 + lVar3 * 4);
    iVar2 = *(int *)(param_2 + lVar3 * 4);
    *(int *)(param_1 + lVar3 * 4) = iVar2 + iVar1;
    *(int *)(param_2 + lVar3 * 4) = iVar1 - iVar2;
  }
  return;
}


