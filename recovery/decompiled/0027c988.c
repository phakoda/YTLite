/* Decompiled from supplied 5.2.2 arm package. VA 0x27c988. FUN_0027c988 */

void FUN_0027c988(double param_1,double param_2,double param_3,double *param_4)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar2 = DAT_00c4c370;
  dVar1 = (double)___sincos_stret((param_1 * DAT_00c4c370) / param_3);
  dVar1 = dVar1 / (param_2 + param_2);
  dVar3 = 1.0 / (dVar1 + 1.0);
  dVar4 = (1.0 - dVar2) * 0.5 * dVar3;
  *param_4 = dVar4;
  param_4[1] = (1.0 - dVar2) * dVar3;
  param_4[2] = dVar4;
  param_4[3] = dVar2 * -2.0 * dVar3;
  param_4[4] = (1.0 - dVar1) * dVar3;
  return;
}


