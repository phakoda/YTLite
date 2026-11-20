/* Decompiled from supplied 5.2.2 arm package. VA 0x26e0cc. _av_tx_uninit */

void _av_tx_uninit(long *param_1)

{
  if (*param_1 != 0) {
    _av_free(*(void **)(*param_1 + 0x20));
    _av_free(*(void **)(*param_1 + 0x10));
    _av_free(*(void **)(*param_1 + 0x28));
    _av_free(*(void **)(*param_1 + 0x18));
    _av_freep(param_1);
    return;
  }
  return;
}


