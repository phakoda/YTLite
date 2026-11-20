/* Decompiled from supplied 5.2.2 arm package. VA 0x26d534. _av_timecode_make_smpte_tc_string */

undefined8 _av_timecode_make_smpte_tc_string(undefined8 param_1,uint param_2)

{
  FUN_0026d5dc(param_2 & 0x3f);
  FUN_0026d5dc(param_2 >> 8 & 0x7f);
  FUN_0026d5dc(param_2 >> 0x10 & 0x7f);
  FUN_0026d5dc(param_2 >> 0x18 & 0x3f);
  ___snprintf_chk(param_1,0x17,0,0xffffffffffffffff,"%02u:%02u:%02u%c%02u");
  return param_1;
}


