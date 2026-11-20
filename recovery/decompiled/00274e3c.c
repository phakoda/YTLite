/* Decompiled from supplied 5.2.2 arm package. VA 0x274e3c. FUN_00274e3c */

void FUN_00274e3c(float *param_1)

{
  float fVar1;
  float fVar2;
  
  fVar2 = param_1[1];
  fVar1 = *param_1;
  *param_1 = fVar1 + param_1[2];
  param_1[1] = fVar2 + param_1[3];
  param_1[2] = fVar1 - param_1[2];
  param_1[3] = fVar2 - param_1[3];
  return;
}


