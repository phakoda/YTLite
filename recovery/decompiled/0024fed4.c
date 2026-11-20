/* Decompiled from supplied 5.2.2 arm package. VA 0x24fed4. _oggpackB_bytes */

long _oggpackB_bytes(long *param_1)

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


