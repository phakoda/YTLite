/* Decompiled from supplied 5.2.2 arm package. VA 0x270e0c. FUN_00270e0c */

void FUN_00270e0c(double *param_1)

{
  double dVar1;
  double dVar2;
  
  dVar2 = param_1[1];
  dVar1 = *param_1;
  *param_1 = dVar1 + param_1[2];
  param_1[1] = dVar2 + param_1[3];
  param_1[2] = dVar1 - param_1[2];
  param_1[3] = dVar2 - param_1[3];
  return;
}


