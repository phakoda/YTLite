/* Decompiled from supplied 5.2.2 arm package. VA 0x270fa4. FUN_00270fa4 */

void FUN_00270fa4(double *param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  
  dVar11 = DAT_019aca58;
  dVar9 = DAT_019aca48;
  FUN_00270e9c();
  FUN_00270e34(param_1 + 0x10);
  FUN_00270e34(param_1 + 0x18);
  dVar3 = param_1[0x14] * DAT_00c51e40;
  dVar10 = param_1[0x15] * DAT_00c51e40;
  dVar2 = param_1[0x1c] * DAT_00c51e40;
  dVar8 = param_1[0x1d] * DAT_00c51e40;
  dVar1 = param_1[5];
  dVar12 = dVar9 * param_1[0x12] + param_1[0x13] * dVar11;
  dVar13 = dVar9 * param_1[0x13] - param_1[0x12] * dVar11;
  dVar14 = dVar9 * param_1[0x1a] - dVar11 * param_1[0x1b];
  dVar4 = param_1[0x18] - param_1[0x10];
  dVar5 = param_1[0x10] + param_1[0x18];
  dVar7 = param_1[0x11] - param_1[0x19];
  dVar6 = param_1[0x11] + param_1[0x19];
  dVar16 = dVar11 * param_1[0x1a] + dVar9 * param_1[0x1b];
  dVar17 = dVar11 * param_1[0x16] + param_1[0x17] * dVar9;
  dVar18 = dVar11 * param_1[0x17] - param_1[0x16] * dVar9;
  dVar19 = dVar11 * param_1[0x1e] - dVar9 * param_1[0x1f];
  dVar15 = dVar9 * param_1[0x1e] + dVar11 * param_1[0x1f];
  param_1[0x10] = *param_1 - dVar5;
  param_1[0x11] = param_1[1] - dVar6;
  *param_1 = dVar5 + *param_1;
  param_1[1] = dVar6 + param_1[1];
  param_1[0x18] = param_1[8] - dVar7;
  param_1[0x19] = param_1[9] - dVar4;
  param_1[8] = dVar7 + param_1[8];
  param_1[9] = dVar4 + param_1[9];
  dVar4 = dVar3 + dVar10;
  dVar10 = dVar10 - dVar3;
  dVar11 = dVar2 - dVar8;
  dVar2 = dVar2 + dVar8;
  dVar9 = dVar14 - dVar12;
  dVar12 = dVar12 + dVar14;
  dVar3 = dVar13 - dVar16;
  dVar13 = dVar13 + dVar16;
  dVar5 = dVar19 - dVar17;
  dVar17 = dVar17 + dVar19;
  dVar7 = dVar18 - dVar15;
  dVar18 = dVar18 + dVar15;
  dVar6 = dVar11 - dVar4;
  dVar4 = dVar4 + dVar11;
  dVar11 = dVar10 - dVar2;
  dVar10 = dVar10 + dVar2;
  param_1[0x12] = param_1[2] - dVar12;
  param_1[0x13] = param_1[3] - dVar13;
  param_1[2] = param_1[2] + dVar12;
  param_1[3] = param_1[3] + dVar13;
  param_1[0x1a] = param_1[10] - dVar3;
  param_1[0x1b] = param_1[0xb] - dVar9;
  param_1[10] = param_1[10] + dVar3;
  param_1[0xb] = dVar9 + param_1[0xb];
  param_1[0x16] = param_1[6] - dVar17;
  param_1[0x17] = param_1[7] - dVar18;
  param_1[5] = dVar1 + dVar10;
  param_1[6] = param_1[6] + dVar17;
  param_1[0x1e] = param_1[0xe] - dVar7;
  param_1[0x1f] = param_1[0xf] - dVar5;
  param_1[0xe] = param_1[0xe] + dVar7;
  param_1[0xf] = dVar5 + param_1[0xf];
  param_1[0x14] = param_1[4] - dVar4;
  param_1[0x15] = dVar1 - dVar10;
  param_1[4] = param_1[4] + dVar4;
  param_1[0x1c] = param_1[0xc] - dVar11;
  param_1[0x1d] = param_1[0xd] - dVar6;
  param_1[0xc] = param_1[0xc] + dVar11;
  param_1[0xd] = dVar6 + param_1[0xd];
  param_1[7] = param_1[7] + dVar18;
  return;
}


