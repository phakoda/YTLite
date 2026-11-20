/* Decompiled from supplied 5.2.2 arm package. VA 0x27c940. FUN_0027c940 */

undefined1  [16] FUN_0027c940(double param_1,double *param_2)

{
  undefined1 auVar1 [16];
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar2 = param_2[5];
  dVar3 = param_2[6];
  dVar4 = param_2[7];
  param_2[5] = param_1;
  param_2[6] = dVar2;
  dVar2 = ((*param_2 * param_1 + dVar2 * param_2[1] + dVar3 * param_2[2]) - dVar4 * param_2[3]) -
          param_2[8] * param_2[4];
  param_2[7] = dVar2;
  param_2[8] = dVar4;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = dVar2;
  return auVar1;
}


