/* Decompiled from supplied 5.2.2 arm package. VA 0x261bac. _av_mallocz */

void * _av_mallocz(size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)_av_malloc();
  if (pvVar1 != (void *)0x0) {
    _bzero(pvVar1,param_1);
  }
  return pvVar1;
}


