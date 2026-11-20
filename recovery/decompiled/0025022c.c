/* Decompiled from supplied 5.2.2 arm package. VA 0x25022c. _av_adler32_update */

ulong _av_adler32_update(ulong param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  long lVar3;
  ulong uVar4;
  byte bVar5;
  ulong uVar6;
  
  uVar6 = param_1 & 0xffff;
  param_1 = param_1 >> 0x10;
  while (param_3 != 0) {
    param_2 = param_2 + 1;
    param_3 = param_3 + -1;
    while( true ) {
      uVar4 = param_2[-1] + uVar6;
      if ((param_3 + 1U < 5) || (param_1 >> 0x1f != 0)) break;
      bVar5 = *param_2;
      pbVar1 = param_2 + 1;
      pbVar2 = param_2 + 2;
      param_2 = param_2 + 4;
      lVar3 = bVar5 + uVar4 + (ulong)*pbVar1;
      uVar6 = lVar3 + (ulong)*pbVar2;
      param_1 = bVar5 + uVar4 + uVar4 + param_1 + lVar3 + uVar6;
      param_3 = param_3 + -4;
    }
    uVar6 = uVar4 % 0xfff1;
    param_1 = (uVar4 + param_1) % 0xfff1;
  }
  return uVar6 | param_1 << 0x10;
}


