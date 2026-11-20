/* Decompiled from supplied 5.2.2 arm package. VA 0x2500d8. _ff_vector_fmul_window_neon */

float * _ff_vector_fmul_window_neon
                  (float *param_1,float *param_2,long param_3,float *param_4,int param_5)

{
  float *pfVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  long lVar6;
  long lVar7;
  float *pfVar8;
  undefined1 (*pauVar9) [16];
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
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  undefined1 auVar32 [16];
  
  lVar6 = (long)param_5;
  lVar7 = lVar6 + -2;
  pfVar1 = (float *)(param_3 + -8 + lVar7 * 4);
  pauVar9 = (undefined1 (*) [16])(param_4 + lVar7 * 2);
  pfVar8 = param_1 + lVar7 * 2;
  fVar14 = *param_2;
  fVar15 = param_2[1];
  fVar16 = param_2[2];
  fVar17 = param_2[3];
  fVar22 = *param_4;
  fVar23 = param_4[1];
  fVar24 = param_4[2];
  fVar25 = param_4[3];
  fVar18 = *pfVar1;
  fVar19 = pfVar1[1];
  fVar20 = pfVar1[2];
  fVar21 = pfVar1[3];
  while( true ) {
    puVar2 = *pauVar9;
    puVar3 = *pauVar9;
    puVar4 = *pauVar9;
    puVar5 = *pauVar9;
    auVar27 = *pauVar9;
    pauVar9 = pauVar9 + -1;
    lVar6 = lVar6 + -4;
    auVar32._0_4_ = fVar14 * fVar22;
    auVar32._4_4_ = fVar15 * fVar23;
    auVar32._8_4_ = fVar16 * fVar24;
    auVar32._12_4_ = fVar17 * fVar25;
    auVar26._4_4_ = fVar19;
    auVar26._0_4_ = fVar18;
    auVar26._8_4_ = fVar20;
    auVar26._12_4_ = fVar21;
    auVar26 = NEON_rev64(auVar26,4);
    auVar27 = NEON_rev64(auVar27,4);
    auVar32 = NEON_rev64(auVar32,4);
    auVar26 = NEON_ext(auVar26,auVar26,8,1);
    auVar27 = NEON_ext(auVar27,auVar27,8,1);
    auVar32 = NEON_ext(auVar32,auVar32,8,1);
    fVar28 = fVar14 * auVar27._0_4_;
    fVar29 = fVar15 * auVar27._4_4_;
    fVar30 = fVar16 * auVar27._8_4_;
    fVar31 = fVar17 * auVar27._12_4_;
    fVar18 = auVar32._0_4_ + fVar18 * *(float *)puVar2;
    fVar19 = auVar32._4_4_ + fVar19 * *(float *)(puVar3 + 4);
    fVar20 = auVar32._8_4_ + fVar20 * *(float *)(puVar4 + 8);
    fVar21 = auVar32._12_4_ + fVar21 * *(float *)(puVar5 + 0xc);
    if (lVar6 == 0) break;
    fVar14 = param_2[4];
    fVar15 = param_2[5];
    fVar16 = param_2[6];
    fVar17 = param_2[7];
    fVar10 = auVar26._0_4_ * fVar22;
    fVar11 = auVar26._4_4_ * fVar23;
    fVar12 = auVar26._8_4_ * fVar24;
    fVar13 = auVar26._12_4_ * fVar25;
    *pfVar8 = fVar18;
    pfVar8[1] = fVar19;
    pfVar8[2] = fVar20;
    pfVar8[3] = fVar21;
    pfVar8 = pfVar8 + -4;
    fVar22 = param_4[4];
    fVar23 = param_4[5];
    fVar24 = param_4[6];
    fVar25 = param_4[7];
    fVar18 = pfVar1[-4];
    fVar19 = pfVar1[-3];
    fVar20 = pfVar1[-2];
    fVar21 = pfVar1[-1];
    *param_1 = fVar28 - fVar10;
    param_1[1] = fVar29 - fVar11;
    param_1[2] = fVar30 - fVar12;
    param_1[3] = fVar31 - fVar13;
    param_1 = param_1 + 4;
    pfVar1 = pfVar1 + -4;
    param_2 = param_2 + 4;
    param_4 = param_4 + 4;
  }
  *pfVar8 = fVar18;
  pfVar8[1] = fVar19;
  pfVar8[2] = fVar20;
  pfVar8[3] = fVar21;
  *param_1 = fVar28 - auVar26._0_4_ * fVar22;
  param_1[1] = fVar29 - auVar26._4_4_ * fVar23;
  param_1[2] = fVar30 - auVar26._8_4_ * fVar24;
  param_1[3] = fVar31 - auVar26._12_4_ * fVar25;
  return param_1 + 4;
}


