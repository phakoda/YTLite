/* Decompiled from supplied 5.2.2 arm package. VA 0x261d2c. _av_strndup */

void * _av_strndup(void *param_1,size_t param_2)

{
  void *pvVar1;
  void *pvVar2;
  
  if (param_1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = _memchr(param_1,0,param_2);
    if (pvVar1 != (void *)0x0) {
      param_2 = (long)pvVar1 - (long)param_1;
    }
    pvVar2 = (void *)_av_realloc(0,param_2 + 1);
    pvVar1 = (void *)0x0;
    if (pvVar2 != (void *)0x0) {
      _memcpy(pvVar2,param_1,param_2);
      *(undefined1 *)((long)pvVar2 + param_2) = 0;
      pvVar1 = pvVar2;
    }
  }
  return pvVar1;
}


