/* Decompiled from supplied 5.2.2 arm package. VA 0x255dd0. _av_channel_layout_extract_channel */

ulong _av_channel_layout_extract_channel(ulong param_1,int param_2)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  
  iVar1 = _av_get_channel_layout_nb_channels();
  uVar3 = 0;
  if (param_2 < iVar1) {
    for (; (long)uVar3 < 0x40; uVar3 = uVar3 + 1) {
      uVar2 = 1L << (uVar3 & 0x3f);
      if ((uVar2 & param_1) != 0) {
        if (param_2 == 0) {
          return uVar2;
        }
        param_2 = param_2 + -1;
      }
    }
  }
  return 0;
}


