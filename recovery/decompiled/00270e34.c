/* Decompiled from supplied 5.2.2 arm package. VA 0x270e34. FUN_00270e34 */

void FUN_00270e34(double *param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  dVar8 = *param_1 - param_1[2];
  dVar1 = *param_1 + param_1[2];
  dVar3 = param_1[6] - param_1[4];
  dVar5 = param_1[6] + param_1[4];
  dVar7 = param_1[1] - param_1[3];
  dVar2 = param_1[1] + param_1[3];
  dVar4 = param_1[5] - param_1[7];
  dVar6 = param_1[5] + param_1[7];
  param_1[3] = dVar3 + dVar7;
  param_1[4] = dVar1 - dVar5;
  *param_1 = dVar1 + dVar5;
  param_1[1] = dVar2 + dVar6;
  param_1[6] = dVar8 - dVar4;
  param_1[7] = dVar7 - dVar3;
  param_1[2] = dVar8 + dVar4;
  param_1[5] = dVar2 - dVar6;
  return;
}


