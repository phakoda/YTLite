/* Decompiled from supplied 5.2.2 arm package. VA 0x255d08. _av_get_channel_name */

undefined8 _av_get_channel_name(ulong param_1)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  iVar1 = _av_get_channel_layout_nb_channels();
  if (iVar1 == 1) {
    for (uVar2 = 0; (long)uVar2 < 0x40; uVar2 = uVar2 + 1) {
      if ((1L << (uVar2 & 0x3f) & param_1) != 0) {
        uVar3 = FUN_00255bd8();
        return uVar3;
      }
    }
  }
  return 0;
}


