/* Decompiled from supplied 5.2.2 arm package. VA 0x24ffd4. _ff_vector_fmul_neon */

void _ff_vector_fmul_neon(float *param_1,float *param_2,float *param_3,int param_4)

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
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  
  do {
    param_4 = param_4 + -0x10;
    fVar1 = *param_2;
    fVar2 = param_2[1];
    fVar3 = param_2[2];
    fVar4 = param_2[3];
    fVar5 = param_2[4];
    fVar6 = param_2[5];
    fVar7 = param_2[6];
    fVar8 = param_2[7];
    fVar9 = param_2[8];
    fVar10 = param_2[9];
    fVar11 = param_2[10];
    fVar12 = param_2[0xb];
    fVar13 = param_2[0xc];
    fVar14 = param_2[0xd];
    fVar15 = param_2[0xe];
    fVar16 = param_2[0xf];
    param_2 = param_2 + 0x10;
    fVar17 = *param_3;
    fVar18 = param_3[1];
    fVar19 = param_3[2];
    fVar20 = param_3[3];
    fVar21 = param_3[4];
    fVar22 = param_3[5];
    fVar23 = param_3[6];
    fVar24 = param_3[7];
    fVar25 = param_3[8];
    fVar26 = param_3[9];
    fVar27 = param_3[10];
    fVar28 = param_3[0xb];
    fVar29 = param_3[0xc];
    fVar30 = param_3[0xd];
    fVar31 = param_3[0xe];
    fVar32 = param_3[0xf];
    param_3 = param_3 + 0x10;
    *param_1 = fVar1 * fVar17;
    param_1[1] = fVar2 * fVar18;
    param_1[2] = fVar3 * fVar19;
    param_1[3] = fVar4 * fVar20;
    param_1[4] = fVar5 * fVar21;
    param_1[5] = fVar6 * fVar22;
    param_1[6] = fVar7 * fVar23;
    param_1[7] = fVar8 * fVar24;
    param_1[8] = fVar9 * fVar25;
    param_1[9] = fVar10 * fVar26;
    param_1[10] = fVar11 * fVar27;
    param_1[0xb] = fVar12 * fVar28;
    param_1[0xc] = fVar13 * fVar29;
    param_1[0xd] = fVar14 * fVar30;
    param_1[0xe] = fVar15 * fVar31;
    param_1[0xf] = fVar16 * fVar32;
    param_1 = param_1 + 0x10;
  } while (param_4 != 0);
  return;
}


