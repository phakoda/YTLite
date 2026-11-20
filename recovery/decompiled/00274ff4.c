/* Decompiled from supplied 5.2.2 arm package. VA 0x274ff4. FUN_00274ff4 */

void FUN_00274ff4(float *param_1)

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
  double dVar11;
  double dVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  
  fVar4 = DAT_01a6414c;
  fVar13 = DAT_01a64144;
  FUN_00274ecc();
  FUN_00274e64(param_1 + 0x10);
  FUN_00274e64(param_1 + 0x18);
  dVar11 = (double)param_1[0x1c] * DAT_00c51e40;
  dVar12 = (double)param_1[0x1d] * DAT_00c51e40;
  fVar6 = (float)((double)param_1[0x14] * DAT_00c51e40 + (double)param_1[0x15] * DAT_00c51e40);
  fVar5 = (float)((double)param_1[0x15] * DAT_00c51e40 - (double)param_1[0x14] * DAT_00c51e40);
  fVar15 = fVar13 * param_1[0x12] + param_1[0x13] * fVar4;
  fVar14 = fVar13 * param_1[0x13] - param_1[0x12] * fVar4;
  fVar17 = fVar13 * param_1[0x1a] - fVar4 * param_1[0x1b];
  fVar16 = fVar4 * param_1[0x1a] + fVar13 * param_1[0x1b];
  fVar8 = param_1[0x18] - param_1[0x10];
  fVar9 = param_1[0x10] + param_1[0x18];
  fVar3 = param_1[0x11] - param_1[0x19];
  fVar2 = param_1[0x11] + param_1[0x19];
  fVar7 = fVar4 * param_1[0x16] + param_1[0x17] * fVar13;
  fVar10 = fVar4 * param_1[0x17] - param_1[0x16] * fVar13;
  fVar1 = fVar4 * param_1[0x1e] - fVar13 * param_1[0x1f];
  fVar13 = fVar13 * param_1[0x1e] + fVar4 * param_1[0x1f];
  param_1[0x10] = *param_1 - fVar9;
  param_1[0x11] = param_1[1] - fVar2;
  *param_1 = fVar9 + *param_1;
  param_1[1] = fVar2 + param_1[1];
  param_1[0x18] = param_1[8] - fVar3;
  param_1[0x19] = param_1[9] - fVar8;
  param_1[8] = fVar3 + param_1[8];
  param_1[9] = fVar8 + param_1[9];
  fVar2 = fVar17 - fVar15;
  fVar15 = fVar15 + fVar17;
  fVar3 = fVar14 - fVar16;
  fVar14 = fVar14 + fVar16;
  fVar8 = fVar1 - fVar7;
  fVar7 = fVar7 + fVar1;
  fVar1 = fVar10 - fVar13;
  fVar10 = fVar10 + fVar13;
  fVar13 = (float)(dVar11 - dVar12);
  fVar4 = (float)(dVar11 + dVar12);
  fVar9 = fVar13 - fVar6;
  fVar6 = fVar6 + fVar13;
  fVar13 = fVar5 - fVar4;
  fVar5 = fVar5 + fVar4;
  param_1[0x12] = param_1[2] - fVar15;
  param_1[0x13] = param_1[3] - fVar14;
  param_1[2] = param_1[2] + fVar15;
  param_1[3] = param_1[3] + fVar14;
  param_1[0x1a] = param_1[10] - fVar3;
  param_1[0x1b] = param_1[0xb] - fVar2;
  param_1[10] = param_1[10] + fVar3;
  param_1[0xb] = fVar2 + param_1[0xb];
  param_1[0x16] = param_1[6] - fVar7;
  param_1[0x17] = param_1[7] - fVar10;
  param_1[6] = param_1[6] + fVar7;
  param_1[0x1e] = param_1[0xe] - fVar1;
  param_1[0x1f] = param_1[0xf] - fVar8;
  param_1[0xe] = param_1[0xe] + fVar1;
  param_1[0xf] = fVar8 + param_1[0xf];
  param_1[0x14] = param_1[4] - fVar6;
  param_1[0x15] = param_1[5] - fVar5;
  param_1[4] = param_1[4] + fVar6;
  param_1[5] = param_1[5] + fVar5;
  param_1[0x1c] = param_1[0xc] - fVar13;
  param_1[0x1d] = param_1[0xd] - fVar9;
  param_1[0xc] = param_1[0xc] + fVar13;
  param_1[0xd] = param_1[0xd] + fVar9;
  param_1[7] = param_1[7] + fVar10;
  return;
}


