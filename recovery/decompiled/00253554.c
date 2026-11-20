/* Decompiled from supplied 5.2.2 arm package. VA 0x253554. FUN_00253554 */

long FUN_00253554(long param_1)

{
  bool bVar1;
  uint uVar2;
  long lVar3;
  byte *pbVar4;
  int iVar5;
  long lVar6;
  
  pbVar4 = *(byte **)(param_1 + 0x10);
  if (pbVar4 == *(byte **)(param_1 + 0x20)) {
    uVar2 = FUN_00253410(param_1);
  }
  else {
    *(byte **)(param_1 + 0x10) = pbVar4 + 1;
    uVar2 = (uint)*pbVar4;
  }
  if ((uVar2 == 0x2d) || (uVar2 == 0x2b)) {
    pbVar4 = *(byte **)(param_1 + 0x10);
    bVar1 = uVar2 == 0x2d;
    if (pbVar4 == *(byte **)(param_1 + 0x20)) {
      uVar2 = FUN_00253410(param_1);
    }
    else {
      *(byte **)(param_1 + 0x10) = pbVar4 + 1;
      uVar2 = (uint)*pbVar4;
    }
  }
  else {
    bVar1 = false;
  }
  if (uVar2 - 0x30 < 10) {
    iVar5 = 0;
    while (uVar2 - 0x30 < 10 && iVar5 < 0xccccccc) {
      pbVar4 = *(byte **)(param_1 + 0x10);
      iVar5 = (uVar2 - 0x30) + iVar5 * 10;
      if (pbVar4 == *(byte **)(param_1 + 0x20)) {
        uVar2 = FUN_00253410(param_1);
      }
      else {
        *(byte **)(param_1 + 0x10) = pbVar4 + 1;
        uVar2 = (uint)*pbVar4;
      }
    }
    lVar6 = (long)iVar5;
    while (uVar2 - 0x30 < 10 && lVar6 < 0x147ae147ae147ae) {
      pbVar4 = *(byte **)(param_1 + 0x10);
      lVar6 = lVar6 * 10 + (long)(int)(uVar2 - 0x30);
      if (pbVar4 == *(byte **)(param_1 + 0x20)) {
        uVar2 = FUN_00253410(param_1);
      }
      else {
        *(byte **)(param_1 + 0x10) = pbVar4 + 1;
        uVar2 = (uint)*pbVar4;
      }
    }
    while (uVar2 - 0x30 < 10) {
      pbVar4 = *(byte **)(param_1 + 0x10);
      if (pbVar4 == *(byte **)(param_1 + 0x20)) {
        uVar2 = FUN_00253410(param_1);
      }
      else {
        *(byte **)(param_1 + 0x10) = pbVar4 + 1;
        uVar2 = (uint)*pbVar4;
      }
    }
    if (*(long *)(param_1 + 0x20) != 0) {
      *(long *)(param_1 + 0x10) = *(long *)(param_1 + 0x10) + -1;
    }
    lVar3 = -lVar6;
    if (!bVar1) {
      lVar3 = lVar6;
    }
  }
  else {
    if (*(long *)(param_1 + 0x20) != 0) {
      *(long *)(param_1 + 0x10) = *(long *)(param_1 + 0x10) + -1;
    }
    lVar3 = -0x8000000000000000;
  }
  return lVar3;
}


