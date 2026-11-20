/* Decompiled from supplied 5.2.2 arm package. VA 0x260088. _av_log_format_line2 */

undefined4 _av_log_format_line2(void)

{
  undefined4 uVar1;
  undefined8 in_x4;
  int in_w5;
  long lVar2;
  undefined1 local_448 [1024];
  long local_48;
  
  lVar2 = *(long *)PTR____stack_chk_guard_01060708;
  local_48 = lVar2;
  FUN_00260144();
  uVar1 = ___snprintf_chk(in_x4,(long)in_w5,0,0xffffffffffffffff,"%s%s%s%s");
  _av_bprint_finalize(local_448,0);
  if (lVar2 == local_48) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


