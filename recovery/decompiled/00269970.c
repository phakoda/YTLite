/* Decompiled from supplied 5.2.2 arm package. VA 0x269970. _av_gcd_q */

ulong _av_gcd_q(long param_1,long param_2,int param_3,ulong param_4)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  lVar1 = _av_gcd(param_1 >> 0x20,param_2 >> 0x20);
  lVar3 = 0;
  if (lVar1 != 0) {
    lVar3 = (param_1 >> 0x20) / lVar1;
  }
  lVar3 = lVar3 * (param_2 >> 0x20);
  if (lVar3 < param_3) {
    uVar2 = _av_gcd((long)(int)param_1,(long)(int)param_2);
    param_4 = uVar2 & 0xffffffff | lVar3 << 0x20;
  }
  return param_4;
}


