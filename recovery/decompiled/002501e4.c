/* Decompiled from supplied 5.2.2 arm package. VA 0x2501e4. _ff_butterflies_float_neon */

void _ff_butterflies_float_neon(float *param_1,float *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  do {
    fVar3 = *param_1;
    fVar4 = param_1[1];
    fVar5 = param_1[2];
    fVar6 = param_1[3];
    fVar7 = *param_2;
    fVar8 = param_2[1];
    fVar9 = param_2[2];
    fVar10 = param_2[3];
    iVar2 = param_3 + -4;
    *param_2 = fVar3 - fVar7;
    param_2[1] = fVar4 - fVar8;
    param_2[2] = fVar5 - fVar9;
    param_2[3] = fVar6 - fVar10;
    param_2 = param_2 + 4;
    *param_1 = fVar3 + fVar7;
    param_1[1] = fVar4 + fVar8;
    param_1[2] = fVar5 + fVar9;
    param_1[3] = fVar6 + fVar10;
    param_1 = param_1 + 4;
    bVar1 = 3 < param_3;
    param_3 = iVar2;
  } while (iVar2 != 0 && bVar1);
  return;
}


