/* Decompiled from supplied 5.2.2 arm package. VA 0x26d6b0. FUN_0026d6b0 */

int FUN_0026d6b0(long param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = -1;
  if (((int)param_1 != 0) && (iVar3 = (int)((ulong)param_1 >> 0x20), iVar3 != 0)) {
    iVar1 = iVar3;
    if (param_1 < 0) {
      iVar1 = iVar3 + 1;
    }
    iVar2 = 0;
    if (iVar3 != 0) {
      iVar2 = ((int)param_1 + (iVar1 >> 1)) / iVar3;
    }
  }
  return iVar2;
}


