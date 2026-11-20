/* Decompiled from supplied 5.2.2 arm package. VA 0x25cdbc. _av_hash_freep */

void _av_hash_freep(long *param_1)

{
  if (*param_1 != 0) {
    _av_freep();
  }
  _av_freep(param_1);
  return;
}


