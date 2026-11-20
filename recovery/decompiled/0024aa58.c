/* Decompiled from supplied 5.2.2 arm package. VA 0x24aa58. FUN_0024aa58 */

void FUN_0024aa58(ushort *param_1,short *param_2,short param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  ushort *puVar8;
  short *psVar9;
  ushort *puVar10;
  ushort *puVar11;
  short *psVar12;
  long lVar13;
  uint uVar14;
  uint uVar15;
  
  sVar4 = *param_2;
  *param_1 = sVar4 << 10;
  uVar6 = param_2[1] << 3 | sVar4 << 10;
  *param_1 = uVar6;
  *param_1 = uVar6 | (ushort)param_2[2] >> 4 & 7;
  uVar6 = param_2[2] << 0xc;
  param_1[1] = uVar6;
  if (param_3 == 0x14) {
    uVar6 = uVar6 | param_2[0x61] << 10;
    param_1[1] = uVar6;
    uVar6 = uVar6 | param_2[0x25] << 9;
    param_1[1] = uVar6;
    uVar6 = uVar6 | param_2[0x24] << 3;
    param_1[1] = uVar6;
    param_1[1] = uVar6 | (ushort)param_2[6] >> 4 & 7;
    uVar6 = (param_2[6] & 0xeU) << 0xc;
    param_1[2] = uVar6;
    uVar6 = uVar6 | ((ushort)param_2[0x15] >> 3 & 3) << 0xb;
    param_1[2] = uVar6;
    uVar6 = uVar6 | ((ushort)param_2[0x16] >> 3 & 1) << 10;
    param_1[2] = uVar6;
    uVar6 = uVar6 | ((ushort)param_2[9] >> 1 & 0x7f) << 3;
    param_1[2] = uVar6;
    uVar6 = (ushort)param_2[0x18] >> 2 & 4 | uVar6;
    param_1[2] = uVar6;
    uVar6 = (ushort)param_2[0x19] >> 2 & 2 | uVar6;
    param_1[2] = uVar6;
    puVar10 = param_1 + 2;
    param_1[2] = (ushort)param_2[0x1b] >> 4 & 1 | uVar6;
  }
  else {
    uVar6 = uVar6 | param_2[3] << 6;
    param_1[1] = uVar6;
    param_1[1] = (ushort)param_2[4] >> 1 & 0x3f | uVar6;
    sVar4 = param_2[4];
    param_1[2] = sVar4 << 0xf;
    uVar6 = param_2[5] << 8 | sVar4 << 0xf;
    param_1[2] = uVar6;
    uVar6 = uVar6 | param_2[0x61] << 5;
    param_1[2] = uVar6;
    uVar6 = uVar6 | param_2[0x25] << 4;
    param_1[2] = uVar6;
    param_1[2] = uVar6 | (ushort)param_2[0x24] >> 2 & 0xf;
    uVar5 = param_2[0x24] << 0xe;
    param_1[3] = uVar5;
    uVar6 = ((ushort)param_2[6] >> 3 & 0xf) << 10;
    uVar3 = uVar5 | uVar6;
    param_1[3] = uVar3;
    uVar1 = ((ushort)param_2[0x15] >> 4 & 1) << 9;
    uVar3 = uVar3 | uVar1;
    param_1[3] = uVar3;
    uVar2 = ((ushort)param_2[0x16] >> 3 & 1) << 8;
    param_1[3] = uVar3 | uVar2;
    uVar6 = uVar5 | uVar6 | uVar1 | uVar2 | param_2[9] & 0xfcU;
    param_1[3] = uVar6;
    uVar6 = (ushort)param_2[0x18] >> 3 & 2 | uVar6;
    param_1[3] = uVar6;
    puVar10 = param_1 + 3;
    param_1[3] = uVar6 | (ushort)param_2[0x19] >> 3 & 1;
  }
  iVar7 = 0;
  psVar9 = param_2 + 0x26;
  puVar11 = (ushort *)(param_2 + 0x56);
  puVar8 = puVar10;
  psVar12 = psVar9;
  while( true ) {
    puVar8 = puVar8 + 1;
    *puVar8 = 0;
    if (iVar7 == 3) break;
    lVar13 = 0;
    uVar15 = 0;
    for (uVar14 = 0xf; -1 < (int)uVar14; uVar14 = uVar14 - 1) {
      uVar15 = (*(ushort *)((long)psVar12 + lVar13) >> 2 & 1) << (ulong)(uVar14 & 0x1f) |
               uVar15 & 0xffff;
      *puVar8 = (ushort)uVar15;
      lVar13 = lVar13 + 2;
    }
    psVar12 = psVar12 + 0x10;
    iVar7 = iVar7 + 1;
  }
  puVar8 = puVar10 + 4;
  uVar15 = 0xf;
  if (param_3 == 0x14) {
    for (; 6 < (int)uVar15; uVar15 = uVar15 - 1) {
      *puVar8 = (ushort)((*puVar11 >> 2 & 1) << (ulong)(uVar15 & 0x1f)) | *puVar8;
      puVar11 = puVar11 + 1;
    }
    uVar6 = (param_2[0x16] & 4U) << 4 | *puVar8;
    *puVar8 = uVar6;
    uVar6 = (param_2[0x18] & 0xcU) << 2 | uVar6;
    *puVar8 = uVar6;
    uVar6 = (param_2[0x19] & 4U) << 1 | uVar6;
    *puVar8 = uVar6;
    uVar6 = (ushort)param_2[0x1b] >> 1 & 4 | uVar6;
    *puVar8 = uVar6;
    *puVar8 = (ushort)param_2[0x1c] >> 2 & 3 | uVar6;
  }
  else {
    for (; 5 < (int)uVar15; uVar15 = uVar15 - 1) {
      *puVar8 = (ushort)((*puVar11 >> 2 & 1) << (ulong)(uVar15 & 0x1f)) | *puVar8;
      puVar11 = puVar11 + 1;
    }
    uVar6 = (param_2[6] & 6U) << 3 | puVar10[4];
    puVar10[4] = uVar6;
    uVar6 = param_2[0x15] & 8U | uVar6;
    puVar10[4] = uVar6;
    uVar6 = param_2[0x16] & 4U | uVar6;
    puVar10[4] = uVar6;
    uVar6 = param_2[9] & 2U | uVar6;
    puVar10[4] = uVar6;
    puVar10[4] = (ushort)param_2[0xc] >> 7 & 1 | uVar6;
    uVar6 = (param_2[0xc] & 0x7eU) << 9;
    puVar10[5] = uVar6;
    uVar6 = uVar6 | ((ushort)param_2[0xf] >> 1 & 0x7f) << 3;
    puVar10[5] = uVar6;
    puVar10[5] = uVar6 | (ushort)param_2[0x12] >> 5 & 7;
    uVar6 = (param_2[0x12] & 0x1eU) << 0xb;
    puVar10[6] = uVar6;
    uVar6 = uVar6 | ((ushort)param_2[0x18] >> 2 & 3) << 10;
    puVar10[6] = uVar6;
    uVar6 = uVar6 | ((ushort)param_2[0x19] >> 1 & 3) << 8;
    puVar10[6] = uVar6;
    uVar6 = uVar6 | ((ushort)param_2[0x1b] >> 3 & 3) << 6;
    puVar10[6] = uVar6;
    uVar6 = uVar6 | ((ushort)param_2[0x1c] >> 2 & 3) << 4;
    puVar10[6] = uVar6;
    uVar6 = (ushort)param_2[0x1e] >> 1 & 8 | uVar6;
    puVar10[6] = uVar6;
    uVar6 = (ushort)param_2[0x1f] >> 1 & 4 | uVar6;
    puVar10[6] = uVar6;
    uVar6 = (ushort)param_2[0x21] >> 3 & 2 | uVar6;
    puVar10[6] = uVar6;
    puVar8 = puVar10 + 6;
    puVar10[6] = (ushort)param_2[0x22] >> 3 & 1 | uVar6;
  }
  puVar10 = puVar8;
  for (iVar7 = 0; iVar7 != 7; iVar7 = iVar7 + 1) {
    lVar13 = 0;
    uVar15 = 0;
    puVar10 = puVar10 + 1;
    *puVar10 = 0;
    for (uVar14 = 0xe; -1 < (int)uVar14; uVar14 = uVar14 - 2) {
      uVar15 = (*(ushort *)((long)psVar9 + lVar13) & 3) << (ulong)(uVar14 & 0x1f) | uVar15 & 0xffff;
      *puVar10 = (ushort)uVar15;
      lVar13 = lVar13 + 2;
    }
    psVar9 = psVar9 + 8;
  }
  uVar6 = param_2[0x5e] << 0xe;
  puVar8[8] = uVar6;
  if (param_3 != 0x14) {
    uVar6 = (param_2[0x5f] & 3U) << 0xc | uVar6;
    puVar8[8] = uVar6;
    uVar6 = (param_2[6] & 1U) << 0xb | uVar6;
    puVar8[8] = uVar6;
    uVar6 = uVar6 | param_2[7] << 4;
    puVar8[8] = uVar6;
    puVar8[8] = uVar6 | (ushort)param_2[8] >> 3 & 0xf;
    uVar5 = param_2[8] << 0xd;
    puVar8[9] = uVar5;
    uVar6 = (param_2[0x15] & 7U) << 10;
    uVar3 = uVar5 | uVar6;
    puVar8[9] = uVar3;
    uVar1 = (param_2[0x16] & 3U) << 8;
    uVar3 = uVar3 | uVar1;
    puVar8[9] = uVar3;
    uVar2 = (param_2[0x17] & 7U) << 5;
    puVar8[9] = uVar3 | uVar2;
    uVar6 = uVar5 | uVar6 | uVar1 | uVar2 | (param_2[9] & 1U) << 4;
    puVar8[9] = uVar6;
    puVar8[9] = uVar6 | (ushort)param_2[10] >> 3 & 0xf;
    sVar4 = param_2[10];
    puVar8[10] = sVar4 << 0xd;
    uVar6 = param_2[0xb] << 6 | sVar4 << 0xd;
    puVar8[10] = uVar6;
    uVar6 = uVar6 | (param_2[0xc] & 1U) << 5;
    puVar8[10] = uVar6;
    puVar8[10] = uVar6 | (ushort)param_2[0xd] >> 3 & 0x1f;
    sVar4 = param_2[0xd];
    puVar8[0xb] = sVar4 << 0xd;
    uVar6 = param_2[0xe] << 5 | sVar4 << 0xd;
    puVar8[0xb] = uVar6;
    uVar6 = uVar6 | (param_2[0xf] & 1U) << 4;
    puVar8[0xb] = uVar6;
    puVar8[0xb] = uVar6 | (ushort)param_2[0x10] >> 4 & 0xf;
    sVar4 = param_2[0x10];
    puVar8[0xc] = sVar4 << 0xc;
    uVar6 = param_2[0x11] << 4 | sVar4 << 0xc;
    puVar8[0xc] = uVar6;
    uVar6 = uVar6 | (param_2[0x12] & 1U) << 3;
    puVar8[0xc] = uVar6;
    puVar8[0xc] = uVar6 | (ushort)param_2[0x13] >> 5 & 7;
    sVar4 = param_2[0x13];
    puVar8[0xd] = sVar4 << 0xb;
    uVar6 = param_2[0x14] << 3 | sVar4 << 0xb;
    puVar8[0xd] = uVar6;
    uVar6 = uVar6 | (param_2[0x18] & 3U) << 1;
    puVar8[0xd] = uVar6;
    puVar8[0xd] = uVar6 | param_2[0x19] & 1U;
    sVar4 = param_2[0x1a];
    puVar8[0xe] = sVar4 << 0xd;
    uVar6 = sVar4 << 0xd | (param_2[0x1b] & 7U) << 10;
    puVar8[0xe] = uVar6;
    uVar6 = uVar6 | (param_2[0x1c] & 3U) << 8;
    puVar8[0xe] = uVar6;
    uVar6 = uVar6 | param_2[0x1d] << 5;
    puVar8[0xe] = uVar6;
    uVar6 = uVar6 | (param_2[0x1e] & 0xfU) << 1;
    puVar8[0xe] = uVar6;
    puVar8[0xe] = uVar6 | (ushort)param_2[0x1f] >> 2 & 1;
    sVar4 = param_2[0x1f];
    puVar8[0xf] = sVar4 << 0xe;
    uVar6 = param_2[0x20] << 0xb | sVar4 << 0xe;
    puVar8[0xf] = uVar6;
    uVar6 = uVar6 | (param_2[0x21] & 0xfU) << 7;
    puVar8[0xf] = uVar6;
    uVar6 = uVar6 | (param_2[0x22] & 7U) << 4;
    puVar8[0xf] = uVar6;
    puVar8[0xf] = uVar6 | param_2[0x23] << 1;
    return;
  }
  uVar6 = (param_2[6] & 1U) << 0xd | uVar6;
  puVar8[8] = uVar6;
  uVar6 = uVar6 | param_2[7] << 6;
  puVar8[8] = uVar6;
  puVar8[8] = (ushort)param_2[8] >> 1 & 0x3f | uVar6;
  sVar4 = param_2[8];
  puVar8[9] = sVar4 << 0xf;
  uVar6 = sVar4 << 0xf | (param_2[0x15] & 7U) << 0xc;
  puVar8[9] = uVar6;
  uVar6 = uVar6 | (param_2[0x16] & 3U) << 10;
  puVar8[9] = uVar6;
  uVar6 = uVar6 | param_2[0x17] << 7;
  puVar8[9] = uVar6;
  uVar6 = uVar6 | (param_2[9] & 1U) << 6;
  puVar8[9] = uVar6;
  puVar8[9] = uVar6 | (ushort)param_2[10] >> 1 & 0x3f;
  sVar4 = param_2[10];
  puVar8[10] = sVar4 << 0xf;
  uVar6 = param_2[0xb] << 8 | sVar4 << 0xf;
  puVar8[10] = uVar6;
  puVar8[10] = uVar6 | param_2[0xc];
  sVar4 = param_2[0xd];
  puVar8[0xb] = sVar4 << 8;
  puVar8[0xb] = param_2[0xe] | sVar4 << 8;
  sVar4 = param_2[0x18];
  puVar8[0xc] = sVar4 << 0xe;
  uVar1 = sVar4 << 0xe | (param_2[0x19] & 3U) << 0xc;
  puVar8[0xc] = uVar1;
  uVar1 = uVar1 | param_2[0x1a] << 9;
  puVar8[0xc] = uVar1;
  uVar6 = (param_2[0x1b] & 7U) << 6;
  puVar8[0xc] = uVar1 | uVar6;
  uVar6 = uVar1 | uVar6 | (param_2[0x1c] & 3U) << 4;
  puVar8[0xc] = uVar6;
  puVar8[0xc] = uVar6 | param_2[0x1d] << 1;
  return;
}


