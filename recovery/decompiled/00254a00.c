/* Decompiled from supplied 5.2.2 arm package. VA 0x254a00. _av_bprint_append_data */

void _av_bprint_append_data(long *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  do {
    uVar1 = *(uint *)((long)param_1 + 0xc);
    uVar2 = uVar1;
    if (*(uint *)(param_1 + 1) <= uVar1) {
      uVar2 = *(uint *)(param_1 + 1);
    }
  } while ((uVar1 - uVar2 <= param_3) && (iVar3 = FUN_00254704(param_1,param_3), iVar3 == 0));
  if (uVar1 != uVar2) {
    uVar2 = (uVar1 - uVar2) - 1;
    if (param_3 <= uVar2) {
      uVar2 = param_3;
    }
    _memcpy((void *)(*param_1 + (ulong)*(uint *)(param_1 + 1)),param_2,(ulong)uVar2);
  }
  FUN_00254898(param_1,param_3);
  return;
}


