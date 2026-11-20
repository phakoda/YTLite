/* Decompiled from supplied 5.2.2 arm package. VA 0x256a58. _av_crc */

uint _av_crc(long param_1,uint param_2,byte *param_3,long param_4)

{
  byte *pbVar1;
  
  pbVar1 = param_3 + param_4;
  for (; param_3 < pbVar1; param_3 = param_3 + 1) {
    param_2 = *(uint *)(param_1 + (ulong)((uint)*param_3 ^ param_2 & 0xff) * 4) ^ param_2 >> 8;
  }
  return param_2;
}


