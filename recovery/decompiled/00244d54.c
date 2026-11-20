/* Decompiled from supplied 5.2.2 arm package. VA 0x244d54. _shine_find_samplerate_index */

undefined4 _shine_find_samplerate_index(int param_1)

{
  undefined4 uVar1;
  
  if (_samplerates == param_1) {
    return 0;
  }
  if (DAT_00c4d7b4 == param_1) {
    return 1;
  }
  if (DAT_00c4d7b8 == param_1) {
    return 2;
  }
  if (DAT_00c4d7bc == param_1) {
    return 3;
  }
  if (DAT_00c4d7c0 == param_1) {
    return 4;
  }
  if (DAT_00c4d7c4 == param_1) {
    return 5;
  }
  if (DAT_00c4d7c8 == param_1) {
    return 6;
  }
  if (DAT_00c4d7cc == param_1) {
    return 7;
  }
  uVar1 = 8;
  if (DAT_00c4d7d0 != param_1) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


