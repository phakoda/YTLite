/* Decompiled from supplied 5.2.2 arm package. VA 0x255cb8. _av_get_channel_layout_channel_index */

undefined8 _av_get_channel_layout_channel_index(ulong param_1,ulong param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (((param_2 & param_1) != 0) &&
     (iVar1 = _av_get_channel_layout_nb_channels(param_2), iVar1 == 1)) {
    uVar2 = _av_get_channel_layout_nb_channels(param_2 - 1 & param_1);
    return uVar2;
  }
  return 0xffffffea;
}


