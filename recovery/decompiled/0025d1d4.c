/* Decompiled from supplied 5.2.2 arm package. VA 0x25d1d4. _av_hmac_calc */

void _av_hmac_calc(undefined8 *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                  undefined4 param_5,undefined8 param_6,undefined4 param_7)

{
  _av_hmac_init(param_1,param_4,param_5);
  (*(code *)param_1[3])(*param_1,param_2,param_3);
  _av_hmac_final(param_1,param_6,param_7);
  return;
}


