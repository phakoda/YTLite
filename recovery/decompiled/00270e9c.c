/* Decompiled from supplied 5.2.2 arm package. VA 0x270e9c. FUN_00270e9c */

void FUN_00270e9c(double *param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  
  FUN_00270e34();
  dVar1 = param_1[8] + param_1[10];
  dVar2 = param_1[9] + param_1[0xb];
  dVar3 = param_1[0xc] + param_1[0xe];
  dVar5 = param_1[0xd] + param_1[0xf];
  dVar6 = dVar3 - dVar1;
  dVar1 = dVar1 + dVar3;
  dVar4 = dVar2 - dVar5;
  dVar2 = dVar2 + dVar5;
  dVar8 = (param_1[8] - param_1[10]) * DAT_00c51e40;
  dVar5 = (param_1[9] - param_1[0xb]) * DAT_00c51e40;
  dVar9 = (param_1[0xc] - param_1[0xe]) * DAT_00c51e40;
  dVar7 = (param_1[0xd] - param_1[0xf]) * DAT_00c51e40;
  dVar3 = dVar8 + dVar5;
  dVar5 = dVar5 - dVar8;
  dVar8 = dVar9 - dVar7;
  dVar9 = dVar9 + dVar7;
  param_1[8] = *param_1 - dVar1;
  param_1[9] = param_1[1] - dVar2;
  *param_1 = dVar1 + *param_1;
  param_1[1] = dVar2 + param_1[1];
  param_1[0xc] = param_1[4] - dVar4;
  param_1[0xd] = param_1[5] - dVar6;
  param_1[4] = dVar4 + param_1[4];
  param_1[5] = dVar6 + param_1[5];
  dVar1 = dVar8 - dVar3;
  dVar3 = dVar3 + dVar8;
  dVar2 = dVar5 - dVar9;
  dVar5 = dVar5 + dVar9;
  param_1[10] = param_1[2] - dVar3;
  param_1[0xb] = param_1[3] - dVar5;
  param_1[2] = param_1[2] + dVar3;
  param_1[3] = param_1[3] + dVar5;
  param_1[0xe] = param_1[6] - dVar2;
  param_1[0xf] = param_1[7] - dVar1;
  param_1[6] = param_1[6] + dVar2;
  param_1[7] = dVar1 + param_1[7];
  return;
}


