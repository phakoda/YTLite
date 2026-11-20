/* Decompiled from supplied 5.2.2 arm package. VA 0x27af6c. _av_video_enc_params_alloc */

uint * _av_video_enc_params_alloc(uint param_1,uint param_2,long *param_3)

{
  uint *puVar1;
  long lVar2;
  
  lVar2 = (ulong)param_2 * 0x14 + 0x40;
  puVar1 = (uint *)_av_mallocz(lVar2);
  if (puVar1 == (uint *)0x0) {
    puVar1 = (uint *)0x0;
  }
  else {
    puVar1[6] = param_1;
    *puVar1 = param_2;
    puVar1[2] = 0x40;
    puVar1[3] = 0;
    puVar1[4] = 0x14;
    puVar1[5] = 0;
    if (param_3 != (long *)0x0) {
      *param_3 = lVar2;
    }
  }
  return puVar1;
}


