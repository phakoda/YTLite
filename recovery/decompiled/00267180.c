/* Decompiled from supplied 5.2.2 arm package. VA 0x267180. _av_get_known_color_name */

undefined * _av_get_known_color_name(uint param_1,undefined8 *param_2)

{
  if (0x8b < param_1) {
    return (undefined *)0x0;
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = &UNK_01064bf0 + (long)(int)param_1 * 0x10;
  }
  return (&PTR_s_AliceBlue_01064be8)[(long)(int)param_1 * 2];
}


