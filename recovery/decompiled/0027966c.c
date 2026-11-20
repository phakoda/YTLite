/* Decompiled from supplied 5.2.2 arm package. VA 0x27966c. FUN_0027966c */

void FUN_0027966c(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar5 = *param_1 - param_1[2];
  iVar1 = param_1[2] + *param_1;
  iVar6 = param_1[6] - param_1[4];
  iVar2 = param_1[4] + param_1[6];
  iVar7 = param_1[1] - param_1[3];
  iVar3 = param_1[3] + param_1[1];
  iVar8 = param_1[5] - param_1[7];
  iVar4 = param_1[7] + param_1[5];
  param_1[3] = iVar7 + iVar6;
  param_1[4] = iVar1 - iVar2;
  *param_1 = iVar2 + iVar1;
  param_1[1] = iVar4 + iVar3;
  param_1[6] = iVar5 - iVar8;
  param_1[7] = iVar7 - iVar6;
  param_1[2] = iVar8 + iVar5;
  param_1[5] = iVar3 - iVar4;
  return;
}


