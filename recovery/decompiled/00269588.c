/* Decompiled from supplied 5.2.2 arm package. VA 0x269588. _av_sub_q */

void _av_sub_q(undefined8 param_1,ulong param_2)

{
  _av_add_q(param_1,param_2 & 0xffffffff00000000 | (ulong)(uint)-(int)param_2);
  return;
}


