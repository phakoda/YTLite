/* Decompiled from supplied 5.2.2 arm package. VA 0x266dfc. _av_parse_video_rate */

ulong _av_parse_video_rate(int *param_1,char *param_2)

{
  undefined **ppuVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  undefined **ppuVar5;
  long lVar6;
  
  lVar6 = -1;
  ppuVar1 = &PTR_s_ntsc_01064b68;
  while (ppuVar5 = ppuVar1, lVar6 = lVar6 + 1, lVar6 < 8) {
    iVar2 = _strcmp(*ppuVar5,param_2);
    ppuVar1 = ppuVar5 + 2;
    if (iVar2 == 0) {
      *(undefined **)param_1 = ppuVar5[1];
      return 0;
    }
  }
  uVar4 = _av_parse_ratio(param_1,param_2,&LAB_000f4628,0x40,0);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  if (*param_1 < 1) {
    return 0xffffffea;
  }
  uVar3 = 0xffffffea;
  if (0 < param_1[1]) {
    uVar3 = 0;
  }
  return (ulong)uVar3;
}


