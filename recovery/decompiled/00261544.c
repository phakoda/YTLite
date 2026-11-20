/* Decompiled from supplied 5.2.2 arm package. VA 0x261544. _av_add_stable */

long _av_add_stable(long param_1,long param_2,long param_3,ulong param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  if (param_4 != 1) {
    param_3 = _av_mul_q(param_3,param_4 & 0xffffffff | 0x100000000);
  }
  lVar2 = (long)(int)param_3 * (param_1 >> 0x20);
  lVar3 = (param_3 >> 0x20) * (long)(int)param_1;
  lVar1 = 0;
  if (lVar3 != 0) {
    lVar1 = lVar2 / lVar3;
  }
  if ((lVar2 - lVar1 * lVar3 == 0) && (param_2 <= 0x7fffffffffffffff - lVar1)) {
    param_2 = lVar1 + param_2;
  }
  else if (lVar3 <= lVar2) {
    lVar1 = _av_rescale_q_rnd(param_2,param_1,param_3,5);
    lVar2 = _av_rescale_q_rnd(lVar1,param_3,param_1,5);
    if (1 < lVar1 + 0x8000000000000001U && lVar2 != -0x8000000000000000) {
      lVar1 = _av_rescale_q_rnd(lVar1 + 1,param_3,param_1,5);
      param_2 = (param_2 - lVar2) + lVar1;
    }
  }
  return param_2;
}


