/* Decompiled from supplied 5.2.2 arm package. VA 0x2571e4. _av_dict_set_int */

void _av_dict_set_int(undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  long lVar1;
  undefined1 auStack_4e [22];
  long local_38;
  
  lVar1 = *(long *)PTR____stack_chk_guard_01060708;
  local_38 = lVar1;
  ___snprintf_chk(auStack_4e,0x16,0,0x16,"%lld");
  _av_dict_set(param_1,param_2,auStack_4e,param_4 & 0xfffffff7);
  if (lVar1 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


