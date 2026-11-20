/* Decompiled from supplied 5.2.2 arm package. VA 0x25c68c. FUN_0025c68c */

void FUN_0025c68c(long param_1,long param_2,long param_3)

{
  uint *puVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  int *piVar6;
  
  uVar2 = 0;
  while( true ) {
    if (*(long *)(param_2 + uVar2 * 8) == 0) {
      return;
    }
    if ((int)uVar2 - 1U < 2) {
      uVar3 = (ulong)*(byte *)(param_3 + 9);
      uVar4 = (ulong)*(byte *)(param_3 + 10);
    }
    else {
      uVar3 = 0;
      uVar4 = 0;
    }
    if ((uVar2 == 1) && ((*(ulong *)(param_3 + 0x10) & 0x42) != 0)) break;
    lVar5 = -1;
    piVar6 = (int *)(param_3 + -4);
    do {
      lVar5 = lVar5 + 1;
      if ((long)(ulong)*(byte *)(param_3 + 8) <= lVar5) {
        return;
      }
      puVar1 = (uint *)(piVar6 + 7);
      piVar6 = piVar6 + 8;
    } while (*puVar1 != uVar2);
    *(ulong *)(param_1 + uVar2 * 8) =
         (long)*(int *)(param_2 + uVar2 * 4 + 0x40) *
         (*(ulong *)(param_2 + 0x1f0) >> (uVar4 & 0x3f)) +
         (long)*piVar6 * (*(ulong *)(param_2 + 0x200) >> (uVar3 & 0x3f));
    uVar2 = uVar2 + 1;
  }
  *(undefined8 *)(param_1 + 8) = 0;
  return;
}


