/* Decompiled from supplied 5.2.2 arm package. VA 0x2612d4. _av_compare_ts */

uint _av_compare_ts(ulong param_1,long param_2,ulong param_3,long param_4)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  
  uVar1 = -param_1;
  if (-1 < (long)param_1) {
    uVar1 = param_1;
  }
  uVar6 = (param_4 >> 0x20) * (long)(int)param_2;
  uVar7 = (long)(int)param_4 * (param_2 >> 0x20);
  uVar2 = -param_3;
  if (-1 < (long)param_3) {
    uVar2 = param_3;
  }
  if ((long)(uVar2 | uVar1 | uVar6 | uVar7) < 0x80000000) {
    lVar4 = uVar6 * param_1;
    lVar5 = uVar7 * param_3;
    uVar3 = (uint)(lVar4 - lVar5 != 0 && lVar5 <= lVar4) - (uint)(lVar4 < lVar5);
  }
  else {
    lVar4 = _av_rescale_rnd(param_1,uVar6,uVar7,2);
    if (lVar4 < (long)param_3) {
      uVar3 = 0xffffffff;
    }
    else {
      lVar4 = _av_rescale_rnd(param_3,uVar7,uVar6,2);
      uVar3 = (uint)(lVar4 < (long)param_1);
    }
  }
  return uVar3;
}


