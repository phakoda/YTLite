/* Decompiled from supplied 5.2.2 arm package. VA 0x26096c. _av_log_once */

void _av_log_once(undefined8 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                 undefined8 param_5)

{
  if (*param_4 == 0) {
    param_3 = param_2;
  }
  _av_vlog(param_1,param_3,param_5,&stack0x00000000);
  *param_4 = 1;
  return;
}


