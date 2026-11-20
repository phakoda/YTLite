/* Decompiled from supplied 5.2.2 arm package. VA 0x261a04. _av_realloc */

void * _av_realloc(void *param_1,size_t param_2)

{
  void *pvVar1;
  
  if (DAT_011d3248 < param_2) {
    return (void *)0x0;
  }
  if (param_2 == 0) {
    param_2 = 1;
  }
  pvVar1 = _realloc(param_1,param_2);
  return pvVar1;
}


