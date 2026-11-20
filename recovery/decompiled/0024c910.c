/* Decompiled from supplied 5.2.2 arm package. VA 0x24c910. FUN_0024c910 */

ushort FUN_0024c910(ushort *param_1,ushort *param_2,short param_3)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  long lVar7;
  uint uVar8;
  
  *param_2 = *param_1 >> 10;
  param_2[1] = *param_1 >> 3 & 0x7f;
  uVar1 = *param_1;
  param_2[2] = (ushort)((uVar1 & 7) << 4);
  param_2[2] = param_1[1] >> 0xc | (ushort)((uVar1 & 7) << 4);
  if (param_3 == 0x14) {
    param_2[0x61] = param_1[1] >> 10 & 3;
    param_2[0x25] = param_1[1] >> 9 & 1;
    param_2[0x24] = param_1[1] >> 3 & 0x3f;
    uVar1 = param_1[1];
    param_2[6] = (ushort)((uVar1 & 7) << 4);
    param_1 = param_1 + 2;
    param_2[6] = *param_1 >> 0xc & 0xe | (ushort)((uVar1 & 7) << 4);
    param_2[0x15] = *param_1 >> 8 & 0x18;
    param_2[0x16] = *param_1 >> 7 & 8;
    param_2[9] = *param_1 >> 2 & 0xfe;
    param_2[0x18] = (*param_1 & 4) << 2;
    param_2[0x19] = (*param_1 & 2) << 2;
    param_2[0x1b] = (*param_1 & 1) << 4;
  }
  else {
    param_2[3] = param_1[1] >> 6 & 0x3f;
    uVar1 = param_1[1];
    param_2[4] = (ushort)((uVar1 & 0x3f) << 1);
    param_2[4] = param_1[2] >> 0xf | (ushort)((uVar1 & 0x3f) << 1);
    param_2[5] = param_1[2] >> 8 & 0x7f;
    param_2[0x61] = param_1[2] >> 5 & 7;
    param_2[0x25] = param_1[2] >> 4 & 1;
    uVar1 = param_1[2];
    param_2[0x24] = (ushort)((uVar1 & 0xf) << 2);
    param_1 = param_1 + 3;
    param_2[0x24] = *param_1 >> 0xe | (ushort)((uVar1 & 0xf) << 2);
    param_2[6] = *param_1 >> 7 & 0x78;
    param_2[0x15] = *param_1 >> 5 & 0x10;
    param_2[0x16] = *param_1 >> 5 & 8;
    param_2[9] = *param_1 & 0xfc;
    param_2[0x18] = (*param_1 & 2) << 3;
    param_2[0x19] = (*param_1 & 1) << 3;
  }
  puVar4 = param_2 + 0x26;
  puVar5 = param_2 + 0x56;
  puVar6 = param_1;
  puVar3 = puVar4;
  for (iVar2 = 0; iVar2 != 3; iVar2 = iVar2 + 1) {
    lVar7 = 0;
    puVar6 = puVar6 + 1;
    for (uVar8 = 0xf; -1 < (int)uVar8; uVar8 = uVar8 - 1) {
      *(ushort *)((long)puVar3 + lVar7) = (*puVar6 >> (ulong)(uVar8 & 0x1f) & 1) << 2;
      lVar7 = lVar7 + 2;
    }
    puVar3 = puVar3 + 0x10;
  }
  puVar3 = param_1 + 4;
  uVar8 = 0xf;
  if (param_3 == 0x14) {
    for (; 6 < (int)uVar8; uVar8 = uVar8 - 1) {
      *puVar5 = (*puVar3 >> (ulong)(uVar8 & 0x1f) & 1) << 2;
      puVar5 = puVar5 + 1;
    }
    param_2[0x16] = param_2[0x16] | *puVar3 >> 4 & 4;
    param_2[0x18] = *puVar3 >> 2 & 0xc | param_2[0x18];
    param_2[0x19] = *puVar3 >> 1 & 4 | param_2[0x19];
    param_2[0x1b] = (*puVar3 & 4) << 1 | param_2[0x1b];
    param_2[0x1c] = (*puVar3 & 3) << 2;
  }
  else {
    for (; 5 < (int)uVar8; uVar8 = uVar8 - 1) {
      *puVar5 = (*puVar3 >> (ulong)(uVar8 & 0x1f) & 1) << 2;
      puVar5 = puVar5 + 1;
    }
    param_2[6] = param_2[6] | *puVar3 >> 3 & 6;
    param_2[0x15] = param_2[0x15] | param_1[4] & 8;
    param_2[0x16] = param_2[0x16] | param_1[4] & 4;
    param_2[9] = param_2[9] | param_1[4] & 2;
    uVar1 = param_1[4];
    param_2[0xc] = (ushort)((uVar1 & 1) << 7);
    param_2[0xc] = param_1[5] >> 9 & 0x7e | (ushort)((uVar1 & 1) << 7);
    param_2[0xf] = param_1[5] >> 2 & 0xfe;
    uVar1 = param_1[5];
    param_2[0x12] = (ushort)((uVar1 & 7) << 5);
    puVar3 = param_1 + 6;
    param_2[0x12] = *puVar3 >> 0xb & 0x1e | (ushort)((uVar1 & 7) << 5);
    param_2[0x18] = *puVar3 >> 8 & 0xc | param_2[0x18];
    param_2[0x19] = *puVar3 >> 7 & 6 | param_2[0x19];
    param_2[0x1b] = *puVar3 >> 3 & 0x18;
    param_2[0x1c] = *puVar3 >> 2 & 0xc;
    param_2[0x1e] = (*puVar3 & 8) << 1;
    param_2[0x1f] = (*puVar3 & 4) << 1;
    param_2[0x21] = (*puVar3 & 2) << 3;
    param_2[0x22] = (*puVar3 & 1) << 3;
  }
  puVar5 = puVar3;
  for (iVar2 = 0; iVar2 != 7; iVar2 = iVar2 + 1) {
    lVar7 = 0;
    puVar5 = puVar5 + 1;
    for (uVar8 = 0xe; -1 < (int)uVar8; uVar8 = uVar8 - 2) {
      *(ushort *)((long)puVar4 + lVar7) =
           *puVar5 >> (ulong)(uVar8 & 0x1f) & 3 | *(ushort *)((long)puVar4 + lVar7);
      lVar7 = lVar7 + 2;
    }
    puVar4 = puVar4 + 8;
  }
  param_2[0x5e] = param_2[0x5e] | puVar3[8] >> 0xe;
  if (param_3 == 0x14) {
    param_2[6] = param_2[6] | puVar3[8] >> 0xd & 1;
    param_2[7] = puVar3[8] >> 6 & 0x7f;
    uVar1 = puVar3[8];
    param_2[8] = (ushort)((uVar1 & 0x3f) << 1);
    param_2[8] = puVar3[9] >> 0xf | (ushort)((uVar1 & 0x3f) << 1);
    param_2[0x15] = puVar3[9] >> 0xc & 7 | param_2[0x15];
    param_2[0x16] = puVar3[9] >> 10 & 3 | param_2[0x16];
    param_2[0x17] = puVar3[9] >> 7 & 7;
    param_2[9] = puVar3[9] >> 6 & 1 | param_2[9];
    uVar1 = puVar3[9];
    param_2[10] = (ushort)((uVar1 & 0x3f) << 1);
    param_2[10] = puVar3[10] >> 0xf | (ushort)((uVar1 & 0x3f) << 1);
    param_2[0xb] = puVar3[10] >> 8 & 0x7f;
    param_2[0xc] = (ushort)(byte)puVar3[10];
    param_2[0xd] = (ushort)*(byte *)((long)puVar3 + 0x17);
    param_2[0xe] = (ushort)(byte)puVar3[0xb];
    puVar3 = puVar3 + 0xc;
    param_2[0x18] = param_2[0x18] | *puVar3 >> 0xe;
    param_2[0x19] = *puVar3 >> 0xc & 3 | param_2[0x19];
    param_2[0x1a] = *puVar3 >> 9 & 7;
    param_2[0x1b] = *puVar3 >> 6 & 7 | param_2[0x1b];
    param_2[0x1c] = *puVar3 >> 4 & 3 | param_2[0x1c];
    param_2[0x1d] = *puVar3 >> 1 & 7;
  }
  else {
    param_2[0x5f] = param_2[0x5f] | puVar3[8] >> 0xc & 3;
    param_2[6] = puVar3[8] >> 0xb & 1 | param_2[6];
    param_2[7] = puVar3[8] >> 4 & 0x7f;
    uVar1 = puVar3[8];
    param_2[8] = (ushort)((uVar1 & 0xf) << 3);
    param_2[8] = puVar3[9] >> 0xd | (ushort)((uVar1 & 0xf) << 3);
    param_2[0x15] = puVar3[9] >> 10 & 7 | param_2[0x15];
    param_2[0x16] = puVar3[9] >> 8 & 3 | param_2[0x16];
    param_2[0x17] = puVar3[9] >> 5 & 7;
    param_2[9] = puVar3[9] >> 4 & 1 | param_2[9];
    uVar1 = puVar3[9];
    param_2[10] = (ushort)((uVar1 & 0xf) << 3);
    param_2[10] = puVar3[10] >> 0xd | (ushort)((uVar1 & 0xf) << 3);
    param_2[0xb] = puVar3[10] >> 6 & 0x7f;
    param_2[0xc] = puVar3[10] >> 5 & 1 | param_2[0xc];
    uVar1 = puVar3[10];
    param_2[0xd] = (ushort)((uVar1 & 0x1f) << 3);
    param_2[0xd] = puVar3[0xb] >> 0xd | (ushort)((uVar1 & 0x1f) << 3);
    param_2[0xe] = puVar3[0xb] >> 5 & 0xff;
    param_2[0xf] = puVar3[0xb] >> 4 & 1 | param_2[0xf];
    uVar1 = puVar3[0xb];
    param_2[0x10] = (ushort)((uVar1 & 0xf) << 4);
    param_2[0x10] = puVar3[0xc] >> 0xc | (ushort)((uVar1 & 0xf) << 4);
    param_2[0x11] = puVar3[0xc] >> 4 & 0xff;
    param_2[0x12] = puVar3[0xc] >> 3 & 1 | param_2[0x12];
    uVar1 = puVar3[0xc];
    param_2[0x13] = (ushort)((uVar1 & 7) << 5);
    param_2[0x13] = puVar3[0xd] >> 0xb | (ushort)((uVar1 & 7) << 5);
    param_2[0x14] = puVar3[0xd] >> 3 & 0xff;
    param_2[0x18] = puVar3[0xd] >> 1 & 3 | param_2[0x18];
    param_2[0x19] = param_2[0x19] | puVar3[0xd] & 1;
    param_2[0x1a] = puVar3[0xe] >> 0xd;
    param_2[0x1b] = puVar3[0xe] >> 10 & 7 | param_2[0x1b];
    param_2[0x1c] = puVar3[0xe] >> 8 & 3 | param_2[0x1c];
    param_2[0x1d] = puVar3[0xe] >> 5 & 7;
    param_2[0x1e] = puVar3[0xe] >> 1 & 0xf | param_2[0x1e];
    uVar1 = (puVar3[0xe] & 1) << 2 | param_2[0x1f];
    param_2[0x1f] = uVar1;
    puVar3 = puVar3 + 0xf;
    param_2[0x1f] = uVar1 | *puVar3 >> 0xe;
    param_2[0x20] = *puVar3 >> 0xb & 7;
    param_2[0x21] = *puVar3 >> 7 & 0xf | param_2[0x21];
    param_2[0x22] = *puVar3 >> 4 & 7 | param_2[0x22];
    param_2[0x23] = *puVar3 >> 1 & 7;
  }
  return *puVar3 & 1;
}


