/* Decompiled from supplied 5.2.2 arm package. VA 0x26dfcc. _ff_tx_gen_ptwo_revtab */

undefined8 _ff_tx_gen_ptwo_revtab(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  int iVar6;
  
  iVar1 = *(int *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 8);
  lVar4 = _av_malloc((long)iVar1 << 2);
  *(long *)(param_1 + 0x28) = lVar4;
  if (lVar4 == 0) {
    uVar5 = 0xfffffff4;
  }
  else {
    for (iVar6 = 0; iVar6 < iVar1; iVar6 = iVar6 + 1) {
      iVar3 = FUN_0026e054(iVar6,iVar1,uVar2);
      *(int *)(lVar4 + (long)(int)(iVar1 - 1U & -iVar3) * 4) = iVar6;
    }
    uVar5 = 0;
  }
  return uVar5;
}


