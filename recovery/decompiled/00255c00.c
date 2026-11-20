/* Decompiled from supplied 5.2.2 arm package. VA 0x255c00. _av_get_channel_layout_string */

void _av_get_channel_layout_string
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  long lVar1;
  undefined1 auStack_438 [1024];
  long local_38;
  
  lVar1 = *(long *)PTR____stack_chk_guard_01060708;
  local_38 = lVar1;
  _av_bprint_init_for_buffer(auStack_438,param_1,param_2);
  _av_bprint_channel_layout(auStack_438,param_3,param_4);
  if (lVar1 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


