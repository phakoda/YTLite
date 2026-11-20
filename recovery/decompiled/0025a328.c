/* Decompiled from supplied 5.2.2 arm package. VA 0x25a328. _av_fifo_freep */

void _av_fifo_freep(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    _av_fifo_free(*param_1);
    *param_1 = 0;
  }
  return;
}


