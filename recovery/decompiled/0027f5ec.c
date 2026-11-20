/* Decompiled from supplied 5.2.2 arm package. VA 0x27f5ec. FUN_0027f5ec */

void FUN_0027f5ec(long param_1,long param_2,long param_3,int param_4,int param_5)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  int *piVar5;
  long lVar6;
  
  for (lVar2 = 0; lVar2 < param_5; lVar2 = lVar2 + 1) {
    lVar3 = *(long *)(param_3 + lVar2 * 8);
    lVar4 = *(long *)(param_1 + lVar2 * 8);
    piVar5 = *(int **)(param_2 + lVar2 * 8);
    for (lVar6 = 0; lVar6 < param_4; lVar6 = lVar6 + 1) {
      iVar1 = *(int *)(lVar3 + lVar6 * 4);
      *(int *)(lVar4 + lVar6 * 4) = iVar1 - *piVar5;
      *piVar5 = iVar1;
    }
  }
  return;
}


