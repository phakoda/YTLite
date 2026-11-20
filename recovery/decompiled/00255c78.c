/* Decompiled from supplied 5.2.2 arm package. VA 0x255c78. _av_get_default_channel_layout */

undefined8 _av_get_default_channel_layout(int param_1)

{
  int *piVar1;
  ulong uVar2;
  int *piVar3;
  
  uVar2 = 0xffffffffffffffff;
  piVar1 = &DAT_01063760;
  do {
    piVar3 = piVar1;
    uVar2 = uVar2 + 1;
    if (0x1b < uVar2) {
      return 0;
    }
    piVar1 = piVar3 + 6;
  } while (*piVar3 != param_1);
  return *(undefined8 *)(piVar3 + 2);
}


