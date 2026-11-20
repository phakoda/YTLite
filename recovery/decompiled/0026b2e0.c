/* Decompiled from supplied 5.2.2 arm package. VA 0x26b2e0. _av_samples_alloc */

int _av_samples_alloc(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = _av_samples_get_buffer_size(0,param_3,param_4,param_5,param_6);
  if (-1 < iVar1) {
    pvVar2 = (void *)_av_malloc((long)iVar1);
    if (pvVar2 == (void *)0x0) {
      iVar1 = -0xc;
    }
    else {
      iVar1 = _av_samples_fill_arrays(param_1,param_2,pvVar2,param_3,param_4,param_5,param_6);
      if (iVar1 < 0) {
        _av_free(pvVar2);
      }
      else {
        _av_samples_set_silence(param_1,0,param_4,param_3,param_5);
      }
    }
  }
  return iVar1;
}


