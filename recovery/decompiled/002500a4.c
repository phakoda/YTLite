/* Decompiled from supplied 5.2.2 arm package. VA 0x2500a4. _ff_vector_dmul_scalar_neon */

void _ff_vector_dmul_scalar_neon(double param_1,double *param_2,double *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  
  dVar3 = *param_3;
  dVar4 = param_3[1];
  dVar5 = param_3[2];
  dVar6 = param_3[3];
  param_3 = param_3 + 4;
  do {
    iVar2 = param_4 + -8;
    dVar7 = *param_3;
    dVar8 = param_3[1];
    dVar9 = param_3[2];
    dVar10 = param_3[3];
    *param_2 = dVar3 * param_1;
    param_2[1] = dVar4 * param_1;
    param_2[2] = dVar5 * param_1;
    param_2[3] = dVar6 * param_1;
    dVar3 = param_3[4];
    dVar4 = param_3[5];
    dVar5 = param_3[6];
    dVar6 = param_3[7];
    param_3 = param_3 + 8;
    param_2[4] = dVar7 * param_1;
    param_2[5] = dVar8 * param_1;
    param_2[6] = dVar9 * param_1;
    param_2[7] = dVar10 * param_1;
    param_2 = param_2 + 8;
    bVar1 = 7 < param_4;
    param_4 = iVar2;
  } while (iVar2 != 0 && bVar1);
  return;
}


