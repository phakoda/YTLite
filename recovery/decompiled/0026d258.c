/* Decompiled from supplied 5.2.2 arm package. VA 0x26d258. _av_timecode_get_smpte */

uint _av_timecode_get_smpte
               (undefined8 param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_0026d3a4(param_1,0x10000001e);
  if (iVar1 == 1) {
    uVar3 = param_6;
    if ((int)param_6 < 0) {
      uVar3 = param_6 + 1;
    }
    uVar3 = (int)uVar3 >> 1;
    if ((int)param_6 % 2 == 1) {
      iVar1 = FUN_0026d3a4(param_1,0x100000032);
      uVar2 = 0x80;
      if (iVar1 != 0) {
        uVar2 = 0x800000;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
    uVar3 = param_6;
  }
  return param_3 % 10 | param_2 << 0x1e | (param_3 / 10) * 0x10 | (param_4 / 10) * 0x1000 |
         (param_4 % 10) * 0x100 | (param_5 / 10) * 0x100000 | (param_5 % 10) * 0x10000 | uVar2 |
         ((uint)((ulong)uVar3 * 0xcccccccd >> 0x20) & 0x78) << 0x19 | (uVar3 % 10) * 0x1000000;
}


