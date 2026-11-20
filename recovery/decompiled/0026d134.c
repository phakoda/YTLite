/* Decompiled from supplied 5.2.2 arm package. VA 0x26d134. _av_timecode_get_smpte_from_framenum */

uint _av_timecode_get_smpte_from_framenum(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = param_1[1];
  uVar2 = param_1[4];
  uVar7 = *param_1 + param_2;
  if ((uVar1 & 1) != 0) {
    uVar7 = _av_timecode_adjust_ntsc_framenum2(uVar7,uVar2);
  }
  uVar4 = 0;
  if (uVar2 != 0) {
    uVar4 = uVar7 / uVar2;
  }
  uVar5 = 0;
  if (uVar2 * 0x3c != 0) {
    uVar5 = uVar7 / (uVar2 * 0x3c);
  }
  iVar3 = uVar7 - uVar4 * uVar2;
  uVar6 = 0;
  if (uVar2 * 0xe10 != 0) {
    uVar6 = uVar7 / (uVar2 * 0xe10);
  }
  return (iVar3 / 10) * 0x10000000 | (uVar1 & 1) << 0x1e | (iVar3 % 10) * 0x1000000 |
         ((uint)((ulong)(uVar4 % 0x3c) * 0xcccccccd >> 0x20) & 0x7ff8) << 0x11 |
         ((uVar4 % 0x3c) % 10) * 0x10000 |
         ((uint)((ulong)(uVar5 % 0x3c) * 0xcccccccd >> 0x20) & 0x7ffff8) << 9 |
         ((uVar5 % 0x3c) % 10) * 0x100 | (uVar6 % 0x18) % 10 |
         ((uint)((ulong)(uVar6 % 0x18) * 0xcccccccd >> 0x20) & 0x7ffffff8) << 1;
}


