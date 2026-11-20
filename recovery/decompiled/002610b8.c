/* Decompiled from supplied 5.2.2 arm package. VA 0x2610b8. _av_gcd */

ulong _av_gcd(ulong param_1,ulong param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  
  uVar3 = param_2;
  if ((param_1 != 0) && (uVar3 = param_1, param_2 != 0)) {
    uVar3 = (param_1 & 0xaaaaaaaaaaaaaaaa) >> 1 | (param_1 & 0x5555555555555555) << 1;
    uVar3 = (uVar3 & 0xcccccccccccccccc) >> 2 | (uVar3 & 0x3333333333333333) << 2;
    uVar3 = (uVar3 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar3 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar3 = (uVar3 & 0xff00ff00ff00ff00) >> 8 | (uVar3 & 0xff00ff00ff00ff) << 8;
    uVar3 = (uVar3 & 0xffff0000ffff0000) >> 0x10 | (uVar3 & 0xffff0000ffff) << 0x10;
    uVar1 = (param_2 & 0xaaaaaaaaaaaaaaaa) >> 1 | (param_2 & 0x5555555555555555) << 1;
    uVar1 = (uVar1 & 0xcccccccccccccccc) >> 2 | (uVar1 & 0x3333333333333333) << 2;
    uVar1 = (uVar1 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar1 = (uVar1 & 0xff00ff00ff00ff00) >> 8 | (uVar1 & 0xff00ff00ff00ff) << 8;
    uVar1 = (uVar1 & 0xffff0000ffff0000) >> 0x10 | (uVar1 & 0xffff0000ffff) << 0x10;
    uVar2 = LZCOUNT(uVar3 >> 0x20 | uVar3 << 0x20);
    uVar3 = LZCOUNT(uVar1 >> 0x20 | uVar1 << 0x20);
    lVar4 = (long)param_1 >> (uVar2 & 0x3f);
    lVar6 = (long)param_2 >> (uVar3 & 0x3f);
    lVar5 = -lVar4;
    if (-1 < lVar4) {
      lVar5 = lVar4;
    }
    lVar4 = -lVar6;
    if (-1 < lVar6) {
      lVar4 = lVar6;
    }
    while (lVar5 != lVar4) {
      lVar6 = lVar4;
      if (lVar5 <= lVar4) {
        lVar6 = lVar5;
        lVar5 = lVar4;
      }
      uVar7 = lVar5 - lVar6;
      uVar1 = (uVar7 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar7 & 0x5555555555555555) << 1;
      uVar1 = (uVar1 & 0xcccccccccccccccc) >> 2 | (uVar1 & 0x3333333333333333) << 2;
      uVar1 = (uVar1 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar1 = (uVar1 & 0xff00ff00ff00ff00) >> 8 | (uVar1 & 0xff00ff00ff00ff) << 8;
      uVar1 = (uVar1 & 0xffff0000ffff0000) >> 0x10 | (uVar1 & 0xffff0000ffff) << 0x10;
      lVar5 = lVar6;
      lVar4 = (long)uVar7 >> (LZCOUNT(uVar1 >> 0x20 | uVar1 << 0x20) & 0x3fU);
    }
    if ((uint)uVar2 <= (uint)uVar3) {
      uVar3 = uVar2;
    }
    uVar3 = lVar5 << (uVar3 & 0x3f);
  }
  return uVar3;
}


