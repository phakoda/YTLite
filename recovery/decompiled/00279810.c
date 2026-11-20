/* Decompiled from supplied 5.2.2 arm package. VA 0x279810. FUN_00279810 */

void FUN_00279810(int *param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  
  lVar10 = (long)DAT_01ae4144;
  lVar11 = (long)DAT_01ae414c;
  FUN_002796d4();
  FUN_0027966c(param_1 + 0x10);
  FUN_0027966c(param_1 + 0x18);
  iVar5 = param_1[0x18] - param_1[0x10];
  iVar7 = param_1[0x18] + param_1[0x10];
  iVar1 = param_1[0x11] - param_1[0x19];
  iVar4 = param_1[0x19] + param_1[0x11];
  param_1[0x10] = *param_1 - iVar7;
  param_1[0x11] = param_1[1] - iVar4;
  *param_1 = *param_1 + iVar7;
  param_1[1] = param_1[1] + iVar4;
  param_1[0x18] = param_1[8] - iVar1;
  param_1[0x19] = param_1[9] - iVar5;
  param_1[8] = param_1[8] + iVar1;
  param_1[9] = param_1[9] + iVar5;
  lVar3 = _lrintf(DAT_00c51f08);
  lVar8 = param_1[0x1c] * lVar3 + 0x40000000;
  iVar4 = (int)(((long)param_1[0x15] + (long)param_1[0x14]) * lVar3 + 0x40000000U >> 0x1f);
  iVar7 = (int)((ulong)(lVar8 - param_1[0x1d] * lVar3) >> 0x1f);
  iVar5 = iVar7 - iVar4;
  iVar7 = iVar7 + iVar4;
  iVar4 = (int)((ulong)(lVar8 + param_1[0x1d] * lVar3) >> 0x1f);
  iVar9 = (int)(((long)param_1[0x15] - (long)param_1[0x14]) * lVar3 + 0x40000000U >> 0x1f);
  iVar1 = iVar9 - iVar4;
  iVar4 = iVar4 + iVar9;
  param_1[0x14] = param_1[4] - iVar7;
  param_1[0x15] = param_1[5] - iVar4;
  param_1[4] = iVar7 + param_1[4];
  param_1[5] = iVar4 + param_1[5];
  param_1[0x1c] = param_1[0xc] - iVar1;
  param_1[0x1d] = param_1[0xd] - iVar5;
  param_1[0xc] = iVar1 + param_1[0xc];
  param_1[0xd] = iVar5 + param_1[0xd];
  iVar7 = (int)((ulong)((param_1[0x1a] * lVar10 + 0x40000000) - param_1[0x1b] * lVar11) >> 0x1f);
  iVar4 = (int)((ulong)(param_1[0x12] * lVar10 + 0x40000000 + lVar11 * param_1[0x13]) >> 0x1f);
  iVar1 = iVar7 - iVar4;
  iVar7 = iVar7 + iVar4;
  iVar5 = (int)((param_1[0x13] * lVar10 - lVar11 * param_1[0x12]) + 0x40000000U >> 0x1f);
  iVar4 = (int)(param_1[0x1b] * lVar10 + param_1[0x1a] * lVar11 + 0x40000000U >> 0x1f);
  iVar9 = iVar5 - iVar4;
  iVar4 = iVar4 + iVar5;
  param_1[0x12] = param_1[2] - iVar7;
  iVar5 = param_1[6];
  param_1[2] = iVar7 + param_1[2];
  param_1[0x1b] = param_1[0xb] - iVar1;
  param_1[0x1a] = param_1[10] - iVar9;
  param_1[10] = iVar9 + param_1[10];
  param_1[0xb] = iVar1 + param_1[0xb];
  param_1[0x13] = param_1[3] - iVar4;
  param_1[3] = iVar4 + param_1[3];
  iVar1 = param_1[0xf];
  iVar7 = (int)((ulong)((param_1[0x1e] * lVar11 + 0x40000000) - param_1[0x1f] * lVar10) >> 0x1f);
  iVar4 = (int)((ulong)(param_1[0x16] * lVar11 + 0x40000000 + lVar10 * param_1[0x17]) >> 0x1f);
  iVar9 = iVar7 - iVar4;
  iVar7 = iVar7 + iVar4;
  iVar4 = (int)(param_1[0x1f] * lVar11 + param_1[0x1e] * lVar10 + 0x40000000U >> 0x1f);
  iVar6 = (int)((param_1[0x17] * lVar11 - lVar10 * param_1[0x16]) + 0x40000000U >> 0x1f);
  iVar2 = iVar6 - iVar4;
  iVar4 = iVar4 + iVar6;
  param_1[6] = iVar7 + iVar5;
  param_1[0xf] = iVar9 + iVar1;
  param_1[0x1e] = param_1[0xe] - iVar2;
  param_1[0x1f] = iVar1 - iVar9;
  param_1[0xe] = iVar2 + param_1[0xe];
  param_1[0x16] = iVar5 - iVar7;
  param_1[0x17] = param_1[7] - iVar4;
  param_1[7] = iVar4 + param_1[7];
  return;
}


