/* Decompiled from supplied 5.2.2 arm package. VA 0x24fea0. _oggpack_bytes */

long _oggpack_bytes(long *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)param_1[1] + 7;
  iVar2 = (int)param_1[1] + 0xe;
  if (-1 < iVar1) {
    iVar2 = iVar1;
  }
  return *param_1 + (long)(iVar2 >> 3);
}


