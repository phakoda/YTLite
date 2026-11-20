/* Decompiled from supplied 5.2.2 arm package. VA 0x274ecc. FUN_00274ecc */

void FUN_00274ecc(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  
  FUN_00274e64();
  dVar7 = (double)(param_1[8] - param_1[10]) * DAT_00c51e40;
  dVar8 = (double)(param_1[9] - param_1[0xb]) * DAT_00c51e40;
  dVar9 = (double)(param_1[0xc] - param_1[0xe]) * DAT_00c51e40;
  dVar6 = (double)(param_1[0xd] - param_1[0xf]) * DAT_00c51e40;
  fVar1 = param_1[8] + param_1[10];
  fVar2 = param_1[9] + param_1[0xb];
  fVar3 = param_1[0xc] + param_1[0xe];
  fVar4 = param_1[0xd] + param_1[0xf];
  fVar5 = fVar3 - fVar1;
  fVar1 = fVar1 + fVar3;
  fVar3 = fVar2 - fVar4;
  fVar2 = fVar2 + fVar4;
  param_1[8] = *param_1 - fVar1;
  param_1[9] = param_1[1] - fVar2;
  *param_1 = fVar1 + *param_1;
  param_1[1] = fVar2 + param_1[1];
  param_1[0xc] = param_1[4] - fVar3;
  param_1[0xd] = param_1[5] - fVar5;
  param_1[4] = fVar3 + param_1[4];
  param_1[5] = fVar5 + param_1[5];
  fVar1 = (float)(dVar7 + dVar8);
  fVar2 = (float)(dVar8 - dVar7);
  fVar3 = (float)(dVar9 - dVar6);
  fVar4 = (float)(dVar9 + dVar6);
  fVar5 = fVar3 - fVar1;
  fVar1 = fVar1 + fVar3;
  fVar3 = fVar2 - fVar4;
  fVar2 = fVar2 + fVar4;
  param_1[10] = param_1[2] - fVar1;
  param_1[0xb] = param_1[3] - fVar2;
  param_1[2] = param_1[2] + fVar1;
  param_1[3] = param_1[3] + fVar2;
  param_1[0xe] = param_1[6] - fVar3;
  param_1[0xf] = param_1[7] - fVar5;
  param_1[6] = param_1[6] + fVar3;
  param_1[7] = param_1[7] + fVar5;
  return;
}


