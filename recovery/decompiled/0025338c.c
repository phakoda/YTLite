/* Decompiled from supplied 5.2.2 arm package. VA 0x25338c. FUN_0025338c */

size_t FUN_0025338c(long param_1,void *param_2,ulong param_3)

{
  ulong uVar1;
  size_t sVar2;
  void *pvVar3;
  void *pvVar4;
  
  pvVar4 = *(void **)(param_1 + 0x38);
  pvVar3 = _memchr(pvVar4,0,param_3 + 0x100);
  uVar1 = param_3 + 0x100;
  if (pvVar3 != (void *)0x0) {
    uVar1 = (long)pvVar3 - (long)pvVar4;
  }
  sVar2 = uVar1;
  if (param_3 <= uVar1) {
    sVar2 = param_3;
  }
  _memcpy(param_2,pvVar4,sVar2);
  *(size_t *)(param_1 + 0x10) = (long)pvVar4 + sVar2;
  *(ulong *)(param_1 + 0x18) = (long)pvVar4 + uVar1;
  *(ulong *)(param_1 + 0x38) = (long)pvVar4 + uVar1;
  return sVar2;
}


