/* Decompiled from supplied 5.2.2 arm package. VA 0x26d408. _av_timecode_make_string */

undefined8 _av_timecode_make_string(int *param_1,undefined8 param_2,int param_3)

{
  if ((param_1[1] & 1U) != 0) {
    _av_timecode_adjust_ntsc_framenum2(*param_1 + param_3,param_1[4]);
  }
  ___snprintf_chk(param_2,0x17,0,0xffffffffffffffff,"%s%02d:%02d:%02d%c%02d");
  return param_2;
}


