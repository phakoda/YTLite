/* Decompiled from supplied 5.2.2 arm package. VA 0x269160. _av_pixelutils_get_sad_fn */

undefined * _av_pixelutils_get_sad_fn(uint param_1,uint param_2)

{
  undefined *puVar1;
  
  if ((int)param_1 < 1) {
    puVar1 = (undefined *)0x0;
  }
  else {
    puVar1 = (undefined *)0x0;
    if ((param_1 == param_2) && (param_2 < 6 && (param_1 < 6 && 0 < (int)param_2))) {
      puVar1 = (&PTR_s_bottom_0106d310)[(int)param_1];
    }
  }
  return puVar1;
}


