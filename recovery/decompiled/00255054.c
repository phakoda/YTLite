/* Decompiled from supplied 5.2.2 arm package. VA 0x255054. _av_buffer_alloc */

long _av_buffer_alloc(int param_1)

{
  long lVar1;
  long local_28;
  
  local_28 = _av_malloc((long)param_1);
  if (local_28 != 0) {
    lVar1 = _av_buffer_create(local_28,param_1,_av_buffer_default_free,0,0);
    if (lVar1 != 0) {
      return lVar1;
    }
    _av_freep(&local_28);
  }
  return 0;
}


