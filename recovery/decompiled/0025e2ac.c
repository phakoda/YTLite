/* Decompiled from supplied 5.2.2 arm package. VA 0x25e2ac. _av_map_videotoolbox_format_to_pixfmt */

int _av_map_videotoolbox_format_to_pixfmt(int param_1)

{
  int *piVar1;
  ulong uVar2;
  int *piVar3;
  
  uVar2 = 0xffffffffffffffff;
  piVar1 = &DAT_00c50e40;
  do {
    piVar3 = piVar1;
    uVar2 = uVar2 + 1;
    if (4 < uVar2) {
      return -1;
    }
    piVar1 = piVar3 + 3;
  } while (*piVar3 != param_1);
  return piVar3[2];
}


