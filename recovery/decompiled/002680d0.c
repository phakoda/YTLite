/* Decompiled from supplied 5.2.2 arm package. VA 0x2680d0. FUN_002680d0 */

ulong FUN_002680d0(char *param_1)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  undefined **ppuVar4;
  
  ppuVar4 = &PTR_s_yuv420p_01065540;
  uVar1 = 0;
  do {
    uVar3 = uVar1;
    if (0xc5 < (long)uVar3) {
      uVar3 = 0xffffffff;
      break;
    }
    iVar2 = _strcmp(*ppuVar4,param_1);
    if (iVar2 == 0) break;
    iVar2 = _av_match_name(param_1,ppuVar4[0x13]);
    ppuVar4 = ppuVar4 + 0x14;
    uVar1 = uVar3 + 1;
  } while (iVar2 == 0);
  return uVar3 & 0xffffffff;
}


