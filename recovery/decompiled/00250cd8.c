/* Decompiled from supplied 5.2.2 arm package. VA 0x250cd8. _av_aes_ctr_free */

void _av_aes_ctr_free(void *param_1)

{
  if (param_1 != (void *)0x0) {
    _av_freep(param_1);
    _av_free(param_1);
    return;
  }
  return;
}


