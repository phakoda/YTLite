/* Decompiled from supplied 5.2.2 arm package. VA 0x25401c. _av_escape */

void _av_escape(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long lVar1;
  undefined1 auStack_458 [8];
  uint local_450;
  uint uStack_44c;
  long local_58;
  
  lVar1 = *(long *)PTR____stack_chk_guard_01060708;
  local_58 = lVar1;
  _av_bprint_init(auStack_458,1,0xffffffff);
  _av_bprint_escape(auStack_458,param_2,param_3,param_4,param_5);
  if (local_450 < uStack_44c) {
    _av_bprint_finalize(auStack_458,param_1);
  }
  else {
    _av_bprint_finalize(auStack_458,0);
    local_450 = 0xfffffff4;
  }
  if (lVar1 == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(local_450);
}


