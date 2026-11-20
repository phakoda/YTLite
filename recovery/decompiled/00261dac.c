/* Decompiled from supplied 5.2.2 arm package. VA 0x261dac. _av_memdup */

void * _av_memdup(void *param_1,size_t param_2)

{
  void *pvVar1;
  
  if ((param_1 == (void *)0x0) || (pvVar1 = (void *)_av_malloc(param_2), pvVar1 == (void *)0x0)) {
    pvVar1 = (void *)0x0;
  }
  else {
    _memcpy(pvVar1,param_1,param_2);
  }
  return pvVar1;
}


