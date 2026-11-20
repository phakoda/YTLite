/* Decompiled from supplied 5.2.2 arm package. VA 0x254898. FUN_00254898 */

void FUN_00254898(long *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = -(int)param_1[1] - 6;
  if (param_2 <= uVar2) {
    uVar2 = param_2;
  }
  uVar2 = uVar2 + (int)param_1[1];
  *(uint *)(param_1 + 1) = uVar2;
  if (*(int *)((long)param_1 + 0xc) != 0) {
    uVar1 = *(int *)((long)param_1 + 0xc) - 1;
    if (uVar2 <= uVar1) {
      uVar1 = uVar2;
    }
    *(undefined1 *)(*param_1 + (ulong)uVar1) = 0;
  }
  return;
}


