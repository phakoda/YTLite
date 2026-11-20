/* Decompiled from supplied 5.2.2 arm package. VA 0x25ffd0. FUN_0025ffd0 */

void FUN_0025ffd0(double *param_1,long param_2)

{
  double *pdVar1;
  long lVar2;
  int iVar3;
  double *pdVar4;
  long lVar5;
  
  pdVar1 = param_1 + 0x930;
  iVar3 = *(int *)pdVar1;
  for (lVar2 = 0; pdVar4 = param_1, lVar5 = lVar2, lVar2 <= iVar3; lVar2 = lVar2 + 1) {
    for (; lVar5 <= iVar3; lVar5 = lVar5 + 1) {
      *pdVar4 = *pdVar4 + *(double *)(param_2 + lVar2 * 8) * *(double *)(param_2 + lVar5 * 8);
      iVar3 = *(int *)pdVar1;
      pdVar4 = pdVar4 + 1;
    }
    param_1 = param_1 + 0x25;
  }
  return;
}


