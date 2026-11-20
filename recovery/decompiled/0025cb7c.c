/* Decompiled from supplied 5.2.2 arm package. VA 0x25cb7c. _av_hash_final_bin */

void _av_hash_final_bin(long param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  undefined1 auStack_78 [64];
  long local_38;
  
  lVar3 = *(long *)PTR____stack_chk_guard_01060708;
  uVar2 = *(uint *)(&DAT_01064500 + (ulong)*(uint *)(param_1 + 8) * 0x10);
  local_38 = lVar3;
  _av_hash_final(param_1,auStack_78);
  uVar1 = uVar2;
  if (param_3 <= uVar2) {
    uVar1 = param_3;
  }
  _memcpy(param_2,auStack_78,(ulong)uVar1);
  if (uVar2 < param_3) {
    _bzero((void *)((long)param_2 + (ulong)uVar2),(ulong)(param_3 - uVar2));
  }
  if (lVar3 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


