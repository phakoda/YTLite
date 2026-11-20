/* Decompiled from supplied 5.2.2 arm package. VA 0x24d8fc. FUN_0024d8fc */

void FUN_0024d8fc(long param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 *puVar3;
  long lVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  int iVar9;
  
  if (param_2 - 7 < 2) {
    lVar4 = 0;
    lVar7 = 0xf0;
    puVar3 = (undefined2 *)&UNK_00c4f770;
    if (param_2 != 8) {
      lVar7 = 0x70;
      puVar3 = &DAT_00c4f690;
    }
    for (; lVar4 < lVar7; lVar4 = lVar4 + 2) {
      lVar8 = (long)(short)(puVar3 + lVar4)[1];
      lVar6 = (long)(short)puVar3[lVar4];
      uVar1 = *(undefined4 *)(param_1 + lVar6 * 4);
      *(undefined4 *)(param_1 + lVar6 * 4) = *(undefined4 *)(param_1 + lVar8 * 4);
      *(undefined4 *)(param_1 + lVar8 * 4) = uVar1;
    }
  }
  else {
    uVar5 = 0;
    iVar2 = 1 << (ulong)(param_2 & 0x1f);
    for (lVar4 = 1; lVar4 < iVar2; lVar4 = lVar4 + 1) {
      iVar9 = iVar2;
      do {
        iVar9 = iVar9 >> 1;
      } while ((int)((iVar2 + -1) - uVar5) < iVar9);
      uVar5 = (iVar9 - 1U & uVar5) + iVar9;
      lVar7 = (long)(int)uVar5;
      if (lVar4 < lVar7) {
        uVar1 = *(undefined4 *)(param_1 + lVar4 * 4);
        *(undefined4 *)(param_1 + lVar4 * 4) = *(undefined4 *)(param_1 + lVar7 * 4);
        *(undefined4 *)(param_1 + lVar7 * 4) = uVar1;
      }
    }
  }
  return;
}


