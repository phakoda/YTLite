/* Decompiled from supplied 5.2.2 arm package. VA 0x25a2f0. _av_fifo_free */

void _av_fifo_free(void *param_1)

{
  if (param_1 != (void *)0x0) {
    _av_freep(param_1);
    _av_free(param_1);
    return;
  }
  return;
}


