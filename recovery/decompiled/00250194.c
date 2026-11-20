/* Decompiled from supplied 5.2.2 arm package. VA 0x250194. _ff_vector_fmul_reverse_neon */

float * _ff_vector_fmul_reverse_neon(float *param_1,float *param_2,long param_3,int param_4)

{
  undefined1 (*pauVar1) [16];
  long lVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  
  lVar2 = (long)param_4;
  param_3 = param_3 + lVar2 * 4;
  auVar11 = *(undefined1 (*) [16])(param_3 + -0x20);
  auVar12 = *(undefined1 (*) [16])(param_3 + -0x10);
  pauVar1 = (undefined1 (*) [16])(param_3 + -0x40);
  fVar3 = *param_2;
  fVar4 = param_2[1];
  fVar5 = param_2[2];
  fVar6 = param_2[3];
  fVar7 = param_2[4];
  fVar8 = param_2[5];
  fVar9 = param_2[6];
  fVar10 = param_2[7];
  while( true ) {
    lVar2 = lVar2 + -8;
    auVar12 = NEON_rev64(auVar12,4);
    auVar11 = NEON_rev64(auVar11,4);
    auVar12 = NEON_ext(auVar12,auVar12,8,1);
    auVar11 = NEON_ext(auVar11,auVar11,8,1);
    fVar13 = fVar3 * auVar12._0_4_;
    fVar14 = fVar4 * auVar12._4_4_;
    fVar15 = fVar5 * auVar12._8_4_;
    fVar16 = fVar6 * auVar12._12_4_;
    fVar17 = fVar7 * auVar11._0_4_;
    fVar18 = fVar8 * auVar11._4_4_;
    fVar19 = fVar9 * auVar11._8_4_;
    fVar20 = fVar10 * auVar11._12_4_;
    if (lVar2 == 0) break;
    auVar11 = *pauVar1;
    auVar12 = pauVar1[1];
    pauVar1 = pauVar1 + -2;
    fVar3 = param_2[8];
    fVar4 = param_2[9];
    fVar5 = param_2[10];
    fVar6 = param_2[0xb];
    fVar7 = param_2[0xc];
    fVar8 = param_2[0xd];
    fVar9 = param_2[0xe];
    fVar10 = param_2[0xf];
    *param_1 = fVar13;
    param_1[1] = fVar14;
    param_1[2] = fVar15;
    param_1[3] = fVar16;
    param_1[4] = fVar17;
    param_1[5] = fVar18;
    param_1[6] = fVar19;
    param_1[7] = fVar20;
    param_1 = param_1 + 8;
    param_2 = param_2 + 8;
  }
  *param_1 = fVar13;
  param_1[1] = fVar14;
  param_1[2] = fVar15;
  param_1[3] = fVar16;
  param_1[4] = fVar17;
  param_1[5] = fVar18;
  param_1[6] = fVar19;
  param_1[7] = fVar20;
  return param_1 + 8;
}


