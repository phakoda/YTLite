/* Decompiled from supplied 5.2.2 arm package. VA 0x250040. _ff_vector_fmul_scalar_neon */

void _ff_vector_fmul_scalar_neon(float param_1,float *param_2,float *param_3,uint param_4)

{
  bool bVar1;
  float *pfVar2;
  uint uVar3;
  uint uVar4;
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
  
  uVar4 = param_4 & 0xfffffff0;
  uVar3 = param_4;
  if (uVar4 != 0) {
    fVar5 = *param_3;
    fVar6 = param_3[1];
    fVar7 = param_3[2];
    fVar8 = param_3[3];
    fVar9 = param_3[4];
    fVar10 = param_3[5];
    fVar11 = param_3[6];
    fVar12 = param_3[7];
    pfVar2 = param_3 + 8;
    while( true ) {
      uVar4 = uVar4 - 0x10;
      fVar13 = *pfVar2;
      fVar14 = pfVar2[1];
      fVar15 = pfVar2[2];
      fVar16 = pfVar2[3];
      fVar17 = pfVar2[4];
      fVar18 = pfVar2[5];
      fVar19 = pfVar2[6];
      fVar20 = pfVar2[7];
      param_3 = pfVar2 + 8;
      *param_2 = fVar5 * param_1;
      param_2[1] = fVar6 * param_1;
      param_2[2] = fVar7 * param_1;
      param_2[3] = fVar8 * param_1;
      param_2[4] = fVar9 * param_1;
      param_2[5] = fVar10 * param_1;
      param_2[6] = fVar11 * param_1;
      param_2[7] = fVar12 * param_1;
      if (uVar4 == 0) break;
      fVar5 = *param_3;
      fVar6 = pfVar2[9];
      fVar7 = pfVar2[10];
      fVar8 = pfVar2[0xb];
      fVar9 = pfVar2[0xc];
      fVar10 = pfVar2[0xd];
      fVar11 = pfVar2[0xe];
      fVar12 = pfVar2[0xf];
      pfVar2 = pfVar2 + 0x10;
      param_2[8] = fVar13 * param_1;
      param_2[9] = fVar14 * param_1;
      param_2[10] = fVar15 * param_1;
      param_2[0xb] = fVar16 * param_1;
      param_2[0xc] = fVar17 * param_1;
      param_2[0xd] = fVar18 * param_1;
      param_2[0xe] = fVar19 * param_1;
      param_2[0xf] = fVar20 * param_1;
      param_2 = param_2 + 0x10;
    }
    param_2[8] = fVar13 * param_1;
    param_2[9] = fVar14 * param_1;
    param_2[10] = fVar15 * param_1;
    param_2[0xb] = fVar16 * param_1;
    param_2[0xc] = fVar17 * param_1;
    param_2[0xd] = fVar18 * param_1;
    param_2[0xe] = fVar19 * param_1;
    param_2[0xf] = fVar20 * param_1;
    param_2 = param_2 + 0x10;
    uVar3 = param_4 & 0xf;
    if ((param_4 & 0xf) == 0) {
      return;
    }
  }
  do {
    fVar5 = *param_3;
    fVar6 = param_3[1];
    fVar7 = param_3[2];
    fVar8 = param_3[3];
    param_3 = param_3 + 4;
    *param_2 = fVar5 * param_1;
    param_2[1] = fVar6 * param_1;
    param_2[2] = fVar7 * param_1;
    param_2[3] = fVar8 * param_1;
    param_2 = param_2 + 4;
    uVar4 = uVar3 - 4;
    bVar1 = 3 < (int)uVar3;
    uVar3 = uVar4;
  } while (uVar4 != 0 && bVar1);
  return;
}


