/* Decompiled from supplied 5.2.2 arm package. VA 0x255e38. _av_get_standard_channel_layout */

undefined8 _av_get_standard_channel_layout(uint param_1,undefined8 *param_2,undefined8 *param_3)

{
  if (0x1b < param_1) {
    return 0xdfb9b0bb;
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = (&DAT_01063768)[(ulong)param_1 * 3];
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = (&PTR_s_mono_01063758)[(ulong)param_1 * 3];
    return 0;
  }
  return 0;
}


