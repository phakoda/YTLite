/* Decompiled from supplied 5.2.2 arm package. VA 0x25015c. _ff_vector_fmul_add_neon */

float * _ff_vector_fmul_add_neon
                  (float *param_1,float *param_2,float *param_3,float *param_4,int param_5)

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
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = param_2[3];
  fVar5 = param_2[4];
  fVar6 = param_2[5];
  fVar7 = param_2[6];
  fVar8 = param_2[7];
  fVar9 = *param_3;
  fVar10 = param_3[1];
  fVar11 = param_3[2];
  fVar12 = param_3[3];
  fVar13 = param_3[4];
  fVar14 = param_3[5];
  fVar15 = param_3[6];
  fVar16 = param_3[7];
  fVar17 = *param_4;
  fVar18 = param_4[1];
  fVar19 = param_4[2];
  fVar20 = param_4[3];
  fVar21 = param_4[4];
  fVar22 = param_4[5];
  fVar23 = param_4[6];
  fVar24 = param_4[7];
  while( true ) {
    param_5 = param_5 + -8;
    fVar17 = fVar17 + fVar1 * fVar9;
    fVar18 = fVar18 + fVar2 * fVar10;
    fVar19 = fVar19 + fVar3 * fVar11;
    fVar20 = fVar20 + fVar4 * fVar12;
    fVar21 = fVar21 + fVar5 * fVar13;
    fVar22 = fVar22 + fVar6 * fVar14;
    fVar23 = fVar23 + fVar7 * fVar15;
    fVar24 = fVar24 + fVar8 * fVar16;
    if (param_5 == 0) break;
    fVar1 = param_2[8];
    fVar2 = param_2[9];
    fVar3 = param_2[10];
    fVar4 = param_2[0xb];
    fVar5 = param_2[0xc];
    fVar6 = param_2[0xd];
    fVar7 = param_2[0xe];
    fVar8 = param_2[0xf];
    fVar9 = param_3[8];
    fVar10 = param_3[9];
    fVar11 = param_3[10];
    fVar12 = param_3[0xb];
    fVar13 = param_3[0xc];
    fVar14 = param_3[0xd];
    fVar15 = param_3[0xe];
    fVar16 = param_3[0xf];
    *param_1 = fVar17;
    param_1[1] = fVar18;
    param_1[2] = fVar19;
    param_1[3] = fVar20;
    param_1[4] = fVar21;
    param_1[5] = fVar22;
    param_1[6] = fVar23;
    param_1[7] = fVar24;
    param_1 = param_1 + 8;
    fVar17 = param_4[8];
    fVar18 = param_4[9];
    fVar19 = param_4[10];
    fVar20 = param_4[0xb];
    fVar21 = param_4[0xc];
    fVar22 = param_4[0xd];
    fVar23 = param_4[0xe];
    fVar24 = param_4[0xf];
    param_2 = param_2 + 8;
    param_3 = param_3 + 8;
    param_4 = param_4 + 8;
  }
  *param_1 = fVar17;
  param_1[1] = fVar18;
  param_1[2] = fVar19;
  param_1[3] = fVar20;
  param_1[4] = fVar21;
  param_1[5] = fVar22;
  param_1[6] = fVar23;
  param_1[7] = fVar24;
  return param_1 + 8;
}


