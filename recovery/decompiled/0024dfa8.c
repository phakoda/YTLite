/* Decompiled from supplied 5.2.2 arm package. VA 0x24dfa8. FUN_0024dfa8 */

uint FUN_0024dfa8(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 != 0) {
    uVar4 = 0;
    iVar5 = -param_1;
    if (-1 < param_1) {
      iVar5 = param_1;
    }
    iVar1 = -param_2;
    if (-1 < param_2) {
      iVar1 = param_2;
    }
    iVar6 = -0x20;
    while (iVar6 = iVar6 + 1, iVar6 != 0) {
      iVar3 = iVar5 * 2;
      iVar5 = 0;
      if (iVar1 <= iVar3) {
        iVar5 = iVar1;
      }
      iVar5 = iVar3 - iVar5;
      uVar4 = ((uint)(iVar3 < iVar1) | uVar4 << 1) ^ 1;
    }
    uVar2 = -uVar4;
    if (-(param_1 >> 0x1f) - (param_2 >> 0x1f) != 1) {
      uVar2 = uVar4;
    }
    return uVar2;
  }
  return 0;
}


