/* Decompiled from supplied 5.2.2 arm package. VA 0x269854. _av_q2intfloat */

uint _av_q2intfloat(long param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  iVar3 = (int)((ulong)param_1 >> 0x20);
  uVar7 = iVar3 >> 0x1f;
  uVar7 = iVar3 + uVar7 ^ uVar7;
  uVar6 = (uint)param_1;
  uVar1 = -uVar6;
  if (-1 < param_1) {
    uVar1 = uVar6;
  }
  uVar2 = -uVar1;
  if (-1 < (int)uVar1) {
    uVar2 = uVar1;
  }
  uVar8 = 0xffc00000;
  if (uVar7 != 0 || uVar6 != 0) {
    uVar8 = 0;
  }
  if (uVar6 != 0) {
    if (uVar7 == 0) {
      uVar8 = uVar2 & 0x80000000 | 0x7f800000;
    }
    else {
      iVar3 = (int)LZCOUNT(uVar2 | 1) + (0x1f - (int)LZCOUNT(uVar7 | 1));
      uVar6 = iVar3 - 8;
      if ((int)uVar6 < 0) {
        lVar5 = (long)(int)uVar7 << ((ulong)(8 - iVar3) & 0x3f);
        lVar4 = 1;
      }
      else {
        lVar4 = 1L << ((ulong)uVar6 & 0x3f);
        lVar5 = (long)(int)uVar7;
      }
      lVar4 = _av_rescale((long)(int)uVar2,lVar4,lVar5);
      uVar6 = uVar6 - (0xffffff < lVar4);
      if (lVar4 < 0x800000) {
        uVar6 = uVar6 + 1;
      }
      if ((int)uVar6 < 0) {
        lVar5 = (long)(int)uVar7 << ((ulong)-uVar6 & 0x3f);
        lVar4 = 1;
      }
      else {
        lVar4 = 1L << ((ulong)uVar6 & 0x3f);
        lVar5 = (long)(int)uVar7;
      }
      iVar3 = _av_rescale((long)(int)uVar2,lVar4,lVar5);
      uVar8 = iVar3 - 0x800000U | uVar1 & 0x80000000 | (0x96 - uVar6) * 0x800000;
    }
  }
  return uVar8;
}


