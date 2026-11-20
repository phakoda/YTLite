/* Decompiled from supplied 5.2.2 arm package. VA 0x255d64. _av_get_channel_description */

undefined8 _av_get_channel_description(ulong param_1)

{
  ulong uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  
  iVar2 = _av_get_channel_layout_nb_channels();
  uVar3 = 0;
  if (iVar2 == 1) {
    uVar5 = 0;
    puVar4 = (undefined8 *)&UNK_010639f0;
    do {
      if (0x23 < uVar5) {
        return 0;
      }
      uVar1 = uVar5 & 0x3f;
      uVar5 = uVar5 + 1;
      puVar4 = puVar4 + 2;
    } while ((1L << uVar1 & param_1) == 0);
    uVar3 = *puVar4;
  }
  return uVar3;
}


