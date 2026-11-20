/* Decompiled from supplied 5.2.2 arm package. VA 0x25fbf8. FUN_0025fbf8 */

int FUN_0025fbf8(long param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x100);
  iVar1 = *(int *)(param_1 + (ulong)(uVar2 + 9 & 0x3f) * 4) +
          *(int *)(param_1 + (ulong)(uVar2 + 0x28 & 0x3f) * 4);
  *(int *)(param_1 + ((ulong)uVar2 & 0x3f) * 4) = iVar1;
  *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + 1;
  return iVar1;
}


