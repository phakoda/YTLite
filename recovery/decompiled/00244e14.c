/* Decompiled from supplied 5.2.2 arm package. VA 0x244e14. _shine_find_bitrate_index */

undefined4 _shine_find_bitrate_index(int param_1,int param_2)

{
  undefined4 uVar1;
  long lVar2;
  
  if (*(int *)(&_bitrates + (long)param_2 * 4) == param_1) {
    return 0;
  }
  lVar2 = (long)param_2;
  if (*(int *)(&DAT_00c4d7e4 + lVar2 * 4) == param_1) {
    return 1;
  }
  if (*(int *)(&DAT_00c4d7f4 + lVar2 * 4) == param_1) {
    return 2;
  }
  if (*(int *)(&DAT_00c4d804 + lVar2 * 4) == param_1) {
    return 3;
  }
  if (*(int *)(&DAT_00c4d814 + lVar2 * 4) == param_1) {
    return 4;
  }
  if (*(int *)(&DAT_00c4d824 + lVar2 * 4) == param_1) {
    return 5;
  }
  if (*(int *)(&DAT_00c4d834 + lVar2 * 4) == param_1) {
    return 6;
  }
  if (*(int *)(&DAT_00c4d844 + lVar2 * 4) == param_1) {
    return 7;
  }
  if (*(int *)(&DAT_00c4d854 + lVar2 * 4) == param_1) {
    return 8;
  }
  if (*(int *)(&DAT_00c4d864 + lVar2 * 4) == param_1) {
    return 9;
  }
  if (*(int *)(&DAT_00c4d874 + lVar2 * 4) == param_1) {
    return 10;
  }
  if (*(int *)(&DAT_00c4d884 + lVar2 * 4) == param_1) {
    return 0xb;
  }
  if (*(int *)(&DAT_00c4d894 + lVar2 * 4) == param_1) {
    return 0xc;
  }
  if (*(int *)(&DAT_00c4d8a4 + lVar2 * 4) == param_1) {
    return 0xd;
  }
  if (*(int *)(&DAT_00c4d8b4 + lVar2 * 4) == param_1) {
    return 0xe;
  }
  uVar1 = 0xf;
  if (*(int *)(&DAT_00c4d8c4 + lVar2 * 4) != param_1) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


