/* Decompiled from supplied 5.2.2 arm package. VA 0x242b84. FUN_00242b84 */

int FUN_00242b84(long param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  
  if (*(uint *)(param_2 + 8) == 0) {
    iVar4 = 0;
    iVar5 = 0;
  }
  else {
    iVar4 = 0;
    iVar5 = 0;
    uVar6 = 0;
    iVar3 = *(int *)(param_2 + 4) * 2;
    piVar7 = (int *)(param_1 + (long)iVar3 * 4 + 4);
    piVar8 = (int *)(param_1 + (long)(iVar3 + 3) * 4);
    piVar9 = (int *)(param_1 + (long)(iVar3 + 2) * 4);
    do {
      iVar3 = piVar7[-1];
      uVar6 = uVar6 + 1;
      uVar10 = 1;
      if (iVar3 != 0) {
        uVar10 = 2;
      }
      iVar1 = iVar3 + *piVar7 * 2 + *piVar9 * 4 + *piVar8 * 8;
      uVar2 = (uint)(iVar3 != 0);
      if (*piVar7 != 0) {
        uVar2 = uVar10;
      }
      if (*piVar9 != 0) {
        uVar2 = uVar2 + 1;
      }
      if (*piVar8 != 0) {
        uVar2 = uVar2 + 1;
      }
      iVar5 = uVar2 + iVar5 + (uint)(byte)PTR_DAT_01063718[iVar1];
      iVar4 = uVar2 + iVar4 + (uint)(byte)PTR_DAT_01063738[iVar1];
      piVar7 = piVar7 + 4;
      piVar8 = piVar8 + 4;
      piVar9 = piVar9 + 4;
    } while (uVar6 < *(uint *)(param_2 + 8));
  }
  iVar3 = iVar5;
  if (iVar4 <= iVar5) {
    iVar3 = iVar4;
  }
  *(uint *)(param_2 + 0x30) = (uint)(iVar4 <= iVar5);
  return iVar3;
}


