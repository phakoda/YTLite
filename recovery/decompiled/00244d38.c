/* Decompiled from supplied 5.2.2 arm package. VA 0x244d38. _shine_mpeg_version */

int _shine_mpeg_version(int param_1)

{
  int iVar1;
  
  iVar1 = 3;
  if (2 < param_1) {
    iVar1 = (uint)(param_1 < 6) << 1;
  }
  return iVar1;
}


