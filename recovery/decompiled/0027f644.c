/* Decompiled from supplied 5.2.2 arm package. VA 0x27f644. FUN_0027f644 */

void FUN_0027f644(long param_1,long param_2,long param_3,int param_4,int param_5)

{
  short sVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  short *psVar5;
  long lVar6;
  
  for (lVar2 = 0; lVar2 < param_5; lVar2 = lVar2 + 1) {
    lVar3 = *(long *)(param_3 + lVar2 * 8);
    lVar4 = *(long *)(param_1 + lVar2 * 8);
    psVar5 = *(short **)(param_2 + lVar2 * 8);
    for (lVar6 = 0; lVar6 < param_4; lVar6 = lVar6 + 1) {
      sVar1 = *(short *)(lVar3 + lVar6 * 2);
      *(short *)(lVar4 + lVar6 * 2) = sVar1 - *psVar5;
      *psVar5 = sVar1;
    }
  }
  return;
}


