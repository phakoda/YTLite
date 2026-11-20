/* Decompiled from supplied 5.2.2 arm package. VA 0x25cfa8. _av_hmac_init */

void _av_hmac_init(undefined8 *param_1,void *param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  byte local_b8 [128];
  long local_38;
  
  lVar4 = *(long *)PTR____stack_chk_guard_01060708;
  local_38 = lVar4;
  if (*(uint *)(param_1 + 1) < param_3) {
    (*(code *)param_1[4])(*param_1);
    (*(code *)param_1[3])(*param_1,param_2,param_3);
    (*(code *)param_1[2])(*param_1,param_1 + 5);
    param_3 = *(uint *)((long)param_1 + 0xc);
  }
  else {
    _memcpy(param_1 + 5,param_2,(ulong)param_3);
  }
  *(uint *)(param_1 + 0x15) = param_3;
  (*(code *)param_1[4])(*param_1);
  lVar2 = (long)*(int *)(param_1 + 0x15);
  for (lVar3 = 0; lVar3 < lVar2; lVar3 = lVar3 + 1) {
    local_b8[lVar3] = *(byte *)((long)param_1 + lVar3 + 0x28) ^ 0x36;
  }
  iVar1 = *(int *)(param_1 + 1);
  for (; lVar2 < iVar1; lVar2 = lVar2 + 1) {
    local_b8[lVar2] = 0x36;
  }
  (*(code *)param_1[3])(*param_1,local_b8);
  if (lVar4 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


