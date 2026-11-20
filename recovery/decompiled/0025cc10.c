/* Decompiled from supplied 5.2.2 arm package. VA 0x25cc10. _av_hash_final_hex */

void _av_hash_final_hex(long param_1,long param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  undefined1 local_98 [64];
  long local_58;
  
  lVar4 = *(long *)PTR____stack_chk_guard_01060708;
  uVar3 = *(uint *)(&DAT_01064500 + (ulong)*(uint *)(param_1 + 8) * 0x10);
  local_58 = lVar4;
  _av_hash_final(param_1,local_98);
  uVar5 = 0;
  uVar6 = 0;
  iVar1 = param_3;
  if (param_3 < 0) {
    iVar1 = param_3 + 1;
  }
  uVar2 = iVar1 >> 1;
  if (uVar3 <= (uint)(iVar1 >> 1)) {
    uVar2 = uVar3;
  }
  for (; uVar6 < uVar2; uVar6 = uVar6 + 1) {
    ___snprintf_chk(param_2 + (ulong)uVar5,param_3,0,0xffffffffffffffff,"%02x");
    param_3 = param_3 + -2;
    uVar5 = uVar5 + 2;
  }
  if (lVar4 == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


