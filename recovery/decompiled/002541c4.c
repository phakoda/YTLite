/* Decompiled from supplied 5.2.2 arm package. VA 0x2541c4. _av_utf8_decode */

undefined4 _av_utf8_decode(undefined4 *param_1,long *param_2,byte *param_3,uint param_4)

{
  undefined4 uVar1;
  long lVar2;
  byte *pbVar3;
  undefined4 uVar4;
  byte *pbVar5;
  ulong uVar6;
  uint uVar7;
  long lVar8;
  
  pbVar5 = (byte *)*param_2;
  if (pbVar5 < param_3) {
    pbVar3 = pbVar5 + 1;
    uVar6 = (ulong)*pbVar5;
    uVar1 = 0xffffffa4;
    if ((uVar6 < 0xfe) && ((uVar6 & 0xc0) != 0x80)) {
      lVar2 = 0;
      uVar7 = *pbVar5 >> 1 & 0x40;
      for (; (uVar6 & uVar7) != 0; uVar6 = lVar8 + uVar6 * 0x40) {
        if ((param_3 <= pbVar5 + lVar2 + 1) ||
           (lVar8 = (ulong)pbVar5[lVar2 + 1] - 0x80, 0x3f < (uint)lVar8)) {
          *param_2 = (long)pbVar3;
          return 0xffffffa4;
        }
        uVar7 = uVar7 << 5;
        lVar2 = lVar2 + 1;
      }
      if (5 < (int)lVar2) {
        _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
        _abort();
      }
      uVar6 = uVar7 * 2 - 1 & uVar6;
      pbVar3 = pbVar5 + lVar2 + 1;
      uVar1 = 0xffffffa4;
      if ((uVar6 >> 0x1f == 0) && (*(uint *)(&UNK_00c5042c + lVar2 * 4) <= uVar6)) {
        *param_1 = (int)uVar6;
        uVar4 = 0xffffffa4;
        if (uVar6 >> 0x10 < 0x11 || (param_4 & 1) != 0) {
          uVar4 = 0;
        }
        if ((uVar6 < 0x20) &&
           (((0xd < uVar6 || ((1L << (uVar6 & 0x3f) & 0x2600U) == 0)) && ((param_4 & 8) != 0)))) {
          uVar4 = 0xffffffa4;
        }
        uVar1 = 0xffffffa4;
        if (((param_4 & 2) != 0 || (uVar6 & 0xfffffffe) != 0xfffe) &&
            ((param_4 & 4) != 0 || (uVar6 & 0xfffff800) != 0xd800)) {
          uVar1 = uVar4;
        }
      }
    }
    *param_2 = (long)pbVar3;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


