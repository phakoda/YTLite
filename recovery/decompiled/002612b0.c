/* Decompiled from supplied 5.2.2 arm package. VA 0x2612b0. _av_rescale_q_rnd */

void _av_rescale_q_rnd(undefined8 param_1,long param_2,long param_3)

{
  _av_rescale_rnd(param_1,(long)(int)param_2 * (param_3 >> 0x20),
                  (long)(int)param_3 * (param_2 >> 0x20));
  return;
}


