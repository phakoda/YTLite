/* Decompiled from supplied 5.2.2 arm package. VA 0x25ddd4. _av_hwframe_constraints_free */

void _av_hwframe_constraints_free(long *param_1)

{
  if (*param_1 != 0) {
    _av_freep();
    _av_freep(*param_1 + 8);
  }
  _av_freep(param_1);
  return;
}


