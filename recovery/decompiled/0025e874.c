/* Decompiled from supplied 5.2.2 arm package. VA 0x25e874. FUN_0025e874 */

int FUN_0025e874(int param_1,int param_2,int param_3,long param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = -0x16;
  if ((-1 < param_1) && (param_4 != 0)) {
    if (param_3 - 1U < 2) {
      uVar2 = (uint)*(byte *)(param_4 + 9);
    }
    else {
      uVar2 = 0;
    }
    iVar1 = param_1 + (1 << (ulong)(uVar2 & 0x1f)) + -1 >> (uVar2 & 0x1f);
    if (iVar1 != 0) {
      iVar3 = 0;
      if (iVar1 != 0) {
        iVar3 = 0x7fffffff / iVar1;
      }
      if (iVar3 < param_2) {
        return -0x16;
      }
    }
    iVar3 = iVar1 * param_2;
    if ((*(byte *)(param_4 + 0x10) & 4) != 0) {
      iVar3 = iVar1 * param_2 + 7 >> 3;
    }
  }
  return iVar3;
}


