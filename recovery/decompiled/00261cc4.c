/* Decompiled from supplied 5.2.2 arm package. VA 0x261cc4. _av_strdup */

void * _av_strdup(char *param_1)

{
  size_t sVar1;
  void *pvVar2;
  void *pvVar3;
  
  if (param_1 == (char *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    sVar1 = _strlen(param_1);
    pvVar2 = (void *)_av_realloc(0,sVar1 + 1);
    pvVar3 = (void *)0x0;
    if (pvVar2 != (void *)0x0) {
      _memcpy(pvVar2,param_1,sVar1 + 1);
      pvVar3 = pvVar2;
    }
  }
  return pvVar3;
}


