/* Decompiled from supplied 5.2.2 arm package. VA 0x255a84. _av_bprint_channel_layout */

void _av_bprint_channel_layout(undefined8 param_1,int param_2,ulong param_3)

{
  ulong *puVar1;
  long lVar2;
  char *pcVar3;
  ulong uVar4;
  ulong *puVar5;
  int iVar6;
  
  if (param_2 < 1) {
    param_2 = _av_get_channel_layout_nb_channels(param_3);
  }
  uVar4 = 0xffffffffffffffff;
  puVar1 = &DAT_01063768;
  do {
    puVar5 = puVar1;
    uVar4 = uVar4 + 1;
    if (0x1b < uVar4) {
      _av_bprintf(param_1,"%d channels");
      if (param_3 == 0) {
        return;
      }
      _av_bprintf(param_1," (");
      iVar6 = 0;
      for (uVar4 = 0; uVar4 != 0x40; uVar4 = uVar4 + 1) {
        if ((1L << (uVar4 & 0x3f) & param_3) != 0) {
          lVar2 = FUN_00255bd8(uVar4 & 0xffffffff);
          if (lVar2 != 0) {
            if (0 < iVar6) {
              _av_bprintf(param_1,"+");
            }
            _av_bprintf(param_1,"%s");
          }
          iVar6 = iVar6 + 1;
        }
      }
      pcVar3 = ")";
      goto LAB_00255bb4;
    }
    puVar1 = puVar5 + 3;
  } while ((param_2 != (int)puVar5[-1]) || (*puVar5 != param_3));
  pcVar3 = "%s";
LAB_00255bb4:
  _av_bprintf(param_1,pcVar3);
  return;
}


