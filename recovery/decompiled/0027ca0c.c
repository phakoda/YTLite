/* Decompiled from supplied 5.2.2 arm package. VA 0x27ca0c. FUN_0027ca0c */

void FUN_0027ca0c(double param_1,double param_2,double param_3,double *param_4)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar2 = DAT_00c4c370;
  dVar1 = (double)___sincos_stret((param_1 * DAT_00c4c370) / param_3);
  dVar1 = dVar1 / (param_2 + param_2);
  dVar4 = 1.0 / (dVar1 + 1.0);
  dVar3 = (dVar2 + 1.0) * dVar4 * 0.5;
  param_4[2] = dVar3;
  param_4[3] = dVar2 * -2.0 * dVar4;
  *param_4 = dVar3;
  param_4[1] = dVar3 * -2.0;
  param_4[4] = (1.0 - dVar1) * dVar4;
  return;
}


