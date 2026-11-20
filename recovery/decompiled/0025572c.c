/* Decompiled from supplied 5.2.2 arm package. VA 0x25572c. _av_buffer_pool_buffer_get_opaque */

undefined8 _av_buffer_pool_buffer_get_opaque(long *param_1)

{
  if (*(long *)(*param_1 + 0x18) != 0) {
    return *(undefined8 *)(*(long *)(*param_1 + 0x18) + 8);
  }
  _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
  _abort();
}


