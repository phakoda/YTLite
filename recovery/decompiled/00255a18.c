/* Decompiled from supplied 5.2.2 arm package. VA 0x255a18. _av_get_channel_layout_nb_channels */

int _av_get_channel_layout_nb_channels(ulong param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (int)param_1 - ((uint)(param_1 >> 1) & 0x55555555);
  uVar2 = (uint)(param_1 >> 0x20);
  uVar2 = uVar2 - (uVar2 >> 1 & 0x55555555);
  uVar1 = (uVar1 >> 2 & 0x33333333) + (uVar1 & 0x33333333);
  uVar2 = (uVar2 >> 2 & 0x33333333) + (uVar2 & 0x33333333);
  uVar1 = uVar1 + (uVar1 >> 4) & 0xf0f0f0f;
  uVar2 = uVar2 + (uVar2 >> 4) & 0xf0f0f0f;
  uVar1 = uVar1 + (uVar1 >> 8);
  uVar2 = uVar2 + (uVar2 >> 8);
  return (uVar1 + (uVar1 >> 0x10) & 0x3f) + (uVar2 + (uVar2 >> 0x10) & 0x3f);
}


