/* Decompiled from supplied 5.2.2 arm package. VA 0x25d0cc. _av_hmac_final */

void _av_hmac_final(undefined8 *param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  byte local_b8 [128];
  long local_38;
  
  lVar5 = *(long *)PTR____stack_chk_guard_01060708;
  local_38 = lVar5;
  if (param_3 < *(uint *)((long)param_1 + 0xc)) {
    uVar2 = 0xffffffea;
  }
  else {
    (*(code *)param_1[2])(*param_1,param_2);
    (*(code *)param_1[4])(*param_1);
    lVar3 = (long)*(int *)(param_1 + 0x15);
    for (lVar4 = 0; lVar4 < lVar3; lVar4 = lVar4 + 1) {
      local_b8[lVar4] = *(byte *)((long)param_1 + lVar4 + 0x28) ^ 0x5c;
    }
    iVar1 = *(int *)(param_1 + 1);
    for (; lVar3 < iVar1; lVar3 = lVar3 + 1) {
      local_b8[lVar3] = 0x5c;
    }
    (*(code *)param_1[3])(*param_1,local_b8);
    (*(code *)param_1[3])(*param_1,param_2,*(undefined4 *)((long)param_1 + 0xc));
    (*(code *)param_1[2])(*param_1,param_2);
    uVar2 = *(undefined4 *)((long)param_1 + 0xc);
  }
  if (lVar5 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar2);
}


