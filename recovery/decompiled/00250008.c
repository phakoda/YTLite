/* Decompiled from supplied 5.2.2 arm package. VA 0x250008. _ff_vector_fmac_scalar_neon */

void _ff_vector_fmac_scalar_neon(float param_1,float *param_2,float *param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  
  do {
    param_4 = param_4 + -0x10;
    fVar1 = *param_3;
    fVar2 = param_3[1];
    fVar3 = param_3[2];
    fVar4 = param_3[3];
    fVar5 = param_3[4];
    fVar6 = param_3[5];
    fVar7 = param_3[6];
    fVar8 = param_3[7];
    fVar9 = param_3[8];
    fVar10 = param_3[9];
    fVar11 = param_3[10];
    fVar12 = param_3[0xb];
    fVar13 = param_3[0xc];
    fVar14 = param_3[0xd];
    fVar15 = param_3[0xe];
    fVar16 = param_3[0xf];
    param_3 = param_3 + 0x10;
    *param_2 = *param_2 + fVar1 * param_1;
    param_2[1] = param_2[1] + fVar2 * param_1;
    param_2[2] = param_2[2] + fVar3 * param_1;
    param_2[3] = param_2[3] + fVar4 * param_1;
    param_2[4] = param_2[4] + fVar5 * param_1;
    param_2[5] = param_2[5] + fVar6 * param_1;
    param_2[6] = param_2[6] + fVar7 * param_1;
    param_2[7] = param_2[7] + fVar8 * param_1;
    param_2[8] = param_2[8] + fVar9 * param_1;
    param_2[9] = param_2[9] + fVar10 * param_1;
    param_2[10] = param_2[10] + fVar11 * param_1;
    param_2[0xb] = param_2[0xb] + fVar12 * param_1;
    param_2[0xc] = param_2[0xc] + fVar13 * param_1;
    param_2[0xd] = param_2[0xd] + fVar14 * param_1;
    param_2[0xe] = param_2[0xe] + fVar15 * param_1;
    param_2[0xf] = param_2[0xf] + fVar16 * param_1;
    param_2 = param_2 + 0x10;
  } while (param_4 != 0);
  return;
}


