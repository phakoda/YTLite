/* Decompiled from supplied 5.2.2 arm package. VA 0x2579d8. _av_encryption_info_free */

void _av_encryption_info_free(void *param_1)

{
  if (param_1 != (void *)0x0) {
    _av_free(*(void **)((long)param_1 + 0x10));
    _av_free(*(void **)((long)param_1 + 0x20));
    _av_free(*(void **)((long)param_1 + 0x30));
    _av_free(param_1);
    return;
  }
  return;
}


