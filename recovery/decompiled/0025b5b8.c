/* Decompiled from supplied 5.2.2 arm package. VA 0x25b5b8. _av_frame_free */

void _av_frame_free(long *param_1)

{
  if ((param_1 != (long *)0x0) && (*param_1 != 0)) {
    _av_frame_unref();
    _av_freep(param_1);
    return;
  }
  return;
}


