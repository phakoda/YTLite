/* Decompiled from supplied 5.2.2 arm package. VA 0x261128. _av_rescale_rnd */

ulong _av_rescale_rnd(ulong param_1,ulong param_2,ulong param_3,uint param_4)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  
  if ((long)param_2 < 0) {
    return 0x8000000000000000;
  }
  if ((long)param_3 < 1) {
    return 0x8000000000000000;
  }
  if ((param_4 & 0xffffdfff) < 6 && (param_4 & 0xffffdfff) != 4) {
    if ((param_4 >> 0xd & 1) != 0) {
      if (param_1 + 0x8000000000000001 < 2) {
        return param_1;
      }
      param_4 = param_4 - 0x2000;
    }
    if ((long)param_1 < 0) {
      if ((long)param_1 < -0x7ffffffffffffffe) {
        param_1 = 0x8000000000000001;
      }
      lVar9 = _av_rescale_rnd(-param_1,param_2,param_3,param_4 >> 1 & 1 ^ param_4);
      return -lVar9;
    }
    if (param_4 == 5) {
      uVar6 = param_3;
      if ((long)param_3 < 0) {
        uVar6 = param_3 + 1;
      }
      uVar6 = (long)uVar6 >> 1;
    }
    else {
      uVar6 = 0;
      if ((param_4 & 1) != 0) {
        uVar6 = param_3 - 1;
      }
    }
    if (0x7fffffff < (long)param_2 || 0x7fffffff < (long)param_3) {
      uVar8 = (param_2 & 0xffffffff) * (param_1 & 0xffffffff);
      uVar5 = (param_2 & 0xffffffff) * ((long)param_1 >> 0x20) +
              ((long)param_2 >> 0x20) * (param_1 & 0xffffffff);
      uVar1 = uVar8 + (uVar5 << 0x20);
      lVar9 = ((long)param_2 >> 0x20) * ((long)param_1 >> 0x20) + (uVar5 >> 0x20);
      if (CARRY8(uVar8,uVar5 << 0x20)) {
        lVar9 = lVar9 + 1;
      }
      if (CARRY8(uVar6,uVar1)) {
        lVar9 = lVar9 + 1;
      }
      for (uVar7 = 0x3f; -1 < (int)uVar7; uVar7 = uVar7 - 1) {
        uVar8 = uVar6 + uVar1 >> ((ulong)uVar7 & 0x3f) & 1 | lVar9 << 1;
        uVar2 = 0;
        if (uVar8 >= param_3) {
          uVar2 = param_3;
        }
        lVar9 = uVar8 - uVar2;
        uVar5 = ((ulong)(uVar8 < param_3) | uVar5 << 1) ^ 1;
      }
      if ((long)uVar5 < 0) {
        return 0x8000000000000000;
      }
      return uVar5;
    }
    if ((long)param_1 < 0x80000000) {
      if (param_3 == 0) {
        return 0;
      }
      return (long)(uVar6 + param_2 * param_1) / (long)param_3;
    }
    lVar9 = 0;
    if (param_3 != 0) {
      lVar9 = (long)param_1 / (long)param_3;
    }
    lVar3 = 0;
    if (param_3 != 0) {
      lVar3 = (long)(uVar6 + (param_1 - lVar9 * param_3) * param_2) / (long)param_3;
    }
    if ((param_2 != 0) && (0x7ffffffe < lVar9)) {
      lVar4 = 0;
      if (param_2 != 0) {
        lVar4 = (0x7fffffffffffffff - lVar3) / (long)param_2;
      }
      if (lVar4 < lVar9) goto LAB_00261294;
    }
    uVar6 = lVar3 + lVar9 * param_2;
  }
  else {
LAB_00261294:
    uVar6 = 0x8000000000000000;
  }
  return uVar6;
}


