/* Decompiled from supplied 5.2.2 arm package. VA 0x2550b0. _av_buffer_allocz */

long _av_buffer_allocz(int param_1)

{
  long lVar1;
  
  lVar1 = _av_buffer_alloc();
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    _bzero(*(void **)(lVar1 + 8),(long)param_1);
  }
  return lVar1;
}


