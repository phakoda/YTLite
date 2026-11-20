/* Decompiled from supplied 5.2.2 arm package. VA 0x261998. _av_malloc */

void * _av_malloc(ulong param_1)

{
  int iVar1;
  void *pvVar2;
  void *local_18;
  
  local_18 = (void *)0x0;
  pvVar2 = (void *)0x0;
  if (param_1 <= DAT_011d3248) {
    if (param_1 == 0) {
      pvVar2 = (void *)_av_malloc(1);
    }
    else {
      iVar1 = _posix_memalign(&local_18,0x10,param_1);
      pvVar2 = local_18;
      if (iVar1 != 0) {
        pvVar2 = (void *)0x0;
      }
    }
  }
  return pvVar2;
}


