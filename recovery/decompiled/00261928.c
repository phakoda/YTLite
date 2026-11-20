/* Decompiled from supplied 5.2.2 arm package. VA 0x261928. _av_md5_sum */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _av_md5_sum(undefined8 param_1)

{
  long lVar1;
  undefined8 local_80 [9];
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = *(long *)PTR____stack_chk_guard_01060708;
  local_80[0] = 0;
  uStack_30 = _UNK_00c510a8;
  local_38 = _DAT_00c510a0;
  local_28 = lVar1;
  _av_md5_update(local_80);
  _av_md5_final(local_80,param_1);
  if (lVar1 == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


