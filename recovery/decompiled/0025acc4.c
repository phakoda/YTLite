/* Decompiled from supplied 5.2.2 arm package. VA 0x25acc4. FUN_0025acc4 */

void FUN_0025acc4(long param_1,long param_2,long param_3,long param_4,int param_5)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  param_1 = param_1 + (long)param_5 * 4;
  param_4 = param_4 + (long)param_5 * 4;
  uVar3 = -(ulong)(param_5 - 1U >> 0x1f) & 0xfffffffc00000000 | (ulong)(param_5 - 1U) << 2;
  for (lVar2 = (long)-param_5; lVar2 < 0; lVar2 = lVar2 + 1) {
    iVar1 = *(int *)(param_3 + uVar3);
    lVar4 = (long)*(int *)(param_4 + lVar2 * 4);
    lVar5 = (long)*(int *)(param_4 + uVar3);
    lVar6 = (long)*(int *)(param_2 + (long)param_5 * 4 + lVar2 * 4);
    *(int *)(param_1 + lVar2 * 4) =
         (int)((ulong)((0x40000000 - lVar4 * iVar1) + lVar5 * lVar6) >> 0x1f);
    *(int *)(param_1 + uVar3) = (int)(lVar5 * iVar1 + lVar4 * lVar6 + 0x40000000U >> 0x1f);
    uVar3 = uVar3 - 4;
  }
  return;
}


