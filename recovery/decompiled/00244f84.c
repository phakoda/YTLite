/* Decompiled from supplied 5.2.2 arm package. VA 0x244f84. _shine_check_config */

int _shine_check_config(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (_samplerates == param_1) {
    uVar4 = 0;
  }
  else if (DAT_00c4d7b4 == param_1) {
    uVar4 = 1;
  }
  else if (DAT_00c4d7b8 == param_1) {
    uVar4 = 2;
  }
  else if (DAT_00c4d7bc == param_1) {
    uVar4 = 3;
  }
  else if (DAT_00c4d7c0 == param_1) {
    uVar4 = 4;
  }
  else if (DAT_00c4d7c4 == param_1) {
    uVar4 = 5;
  }
  else if (DAT_00c4d7c8 == param_1) {
    uVar4 = 6;
  }
  else if (DAT_00c4d7cc == param_1) {
    uVar4 = 7;
  }
  else {
    if (DAT_00c4d7d0 != param_1) {
      return -1;
    }
    uVar4 = 8;
  }
  iVar1 = 3;
  if (2 < uVar4) {
    iVar1 = (uint)(uVar4 < 6) << 1;
  }
  iVar3 = _shine_find_bitrate_index(param_2,iVar1);
  iVar2 = -1;
  if (-1 < iVar3) {
    iVar2 = iVar1;
  }
  return iVar2;
}


