/* Decompiled from supplied 5.2.2 arm package. VA 0x250c28. _av_aes_ctr_set_random_iv */

void _av_aes_ctr_set_random_iv(undefined8 param_1)

{
  long lVar1;
  u_int32_t local_30;
  u_int32_t local_2c;
  long local_28;
  
  lVar1 = *(long *)PTR____stack_chk_guard_01060708;
  local_28 = lVar1;
  local_30 = _av_get_random_seed();
  local_2c = _av_get_random_seed();
  _av_aes_ctr_set_iv(param_1,&local_30);
  if (lVar1 == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


