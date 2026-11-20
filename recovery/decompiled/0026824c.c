/* Decompiled from supplied 5.2.2 arm package. VA 0x26824c. _av_get_pix_fmt_string */

undefined8 _av_get_pix_fmt_string(undefined8 param_1,int param_2,int param_3)

{
  char *pcVar1;
  
  if (param_3 < 0) {
    pcVar1 = "name nb_components nb_bits";
  }
  else {
    _av_get_bits_per_pixel(&PTR_s_yuv420p_01065540 + (long)param_3 * 0x14);
    pcVar1 = "%-11s %7d %10d";
  }
  ___snprintf_chk(param_1,(long)param_2,0,0xffffffffffffffff,pcVar1);
  return param_1;
}


