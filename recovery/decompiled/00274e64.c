/* Decompiled from supplied 5.2.2 arm package. VA 0x274e64. FUN_00274e64 */

void FUN_00274e64(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar8 = *param_1 - param_1[2];
  fVar1 = *param_1 + param_1[2];
  fVar3 = param_1[6] - param_1[4];
  fVar5 = param_1[6] + param_1[4];
  fVar7 = param_1[1] - param_1[3];
  fVar2 = param_1[1] + param_1[3];
  fVar4 = param_1[5] - param_1[7];
  fVar6 = param_1[5] + param_1[7];
  param_1[3] = fVar3 + fVar7;
  param_1[4] = fVar1 - fVar5;
  *param_1 = fVar1 + fVar5;
  param_1[1] = fVar2 + fVar6;
  param_1[6] = fVar8 - fVar4;
  param_1[7] = fVar7 - fVar3;
  param_1[2] = fVar8 + fVar4;
  param_1[5] = fVar2 - fVar6;
  return;
}


