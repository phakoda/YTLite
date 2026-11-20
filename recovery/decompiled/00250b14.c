/* Decompiled from supplied 5.2.2 arm package. VA 0x250b14. FUN_00250b14 */

void FUN_00250b14(long param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  ulong *puVar2;
  
  lVar1 = (long)*(int *)(param_1 + 0x110) + 1;
  puVar2 = (ulong *)(param_1 + (long)(*(int *)(param_1 + 0x110) + -1) * 0x10 + 8);
  while (lVar1 = lVar1 + -1, 1 < lVar1) {
    FUN_00250a68(param_1 + 0xf0,param_4,3 - param_2,param_2 + 1);
    *(ulong *)(param_1 + 0x100) = puVar2[-1] ^ *(ulong *)(param_1 + 0xf0);
    *(ulong *)(param_1 + 0x108) = *puVar2 ^ *(ulong *)(param_1 + 0xf8);
    puVar2 = puVar2 + -2;
  }
  FUN_00250994(param_1 + 0xf0,param_2,param_3);
  return;
}


