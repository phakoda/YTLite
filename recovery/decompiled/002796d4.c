/* Decompiled from supplied 5.2.2 arm package. VA 0x2796d4. FUN_002796d4 */

void FUN_002796d4(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  int iVar11;
  long lVar12;
  int iVar13;
  int iVar14;
  long lVar15;
  long lVar16;
  
  FUN_0027966c();
  iVar4 = param_1[9];
  iVar5 = param_1[0xb];
  iVar11 = param_1[0xc];
  iVar6 = param_1[0xd];
  iVar3 = param_1[0xe];
  iVar7 = param_1[0xf];
  iVar13 = param_1[10] + param_1[8];
  iVar8 = param_1[8] - param_1[10];
  iVar14 = iVar5 + iVar4;
  iVar1 = iVar3 + iVar11;
  iVar2 = iVar7 + iVar6;
  iVar9 = iVar1 - iVar13;
  iVar1 = iVar1 + iVar13;
  iVar13 = iVar14 - iVar2;
  iVar2 = iVar2 + iVar14;
  param_1[8] = *param_1 - iVar1;
  param_1[9] = param_1[1] - iVar2;
  *param_1 = *param_1 + iVar1;
  param_1[1] = param_1[1] + iVar2;
  param_1[0xc] = param_1[4] - iVar13;
  param_1[0xd] = param_1[5] - iVar9;
  param_1[4] = param_1[4] + iVar13;
  param_1[5] = param_1[5] + iVar9;
  lVar10 = _lrintf(DAT_00c51f08);
  lVar12 = (long)(iVar4 - iVar5);
  lVar16 = (iVar6 - iVar7) * lVar10;
  lVar15 = (iVar11 - iVar3) * lVar10 + 0x40000000;
  iVar13 = (int)((ulong)(lVar15 - lVar16) >> 0x1f);
  iVar14 = (int)((lVar12 + iVar8) * lVar10 + 0x40000000U >> 0x1f);
  iVar1 = iVar13 - iVar14;
  iVar13 = iVar13 + iVar14;
  iVar11 = (int)((lVar12 - iVar8) * lVar10 + 0x40000000U >> 0x1f);
  iVar14 = (int)((ulong)(lVar15 + lVar16) >> 0x1f);
  iVar2 = iVar11 - iVar14;
  iVar14 = iVar14 + iVar11;
  param_1[10] = param_1[2] - iVar13;
  param_1[0xb] = param_1[3] - iVar14;
  param_1[2] = iVar13 + param_1[2];
  param_1[3] = iVar14 + param_1[3];
  param_1[0xe] = param_1[6] - iVar2;
  param_1[0xf] = param_1[7] - iVar1;
  param_1[6] = iVar2 + param_1[6];
  param_1[7] = iVar1 + param_1[7];
  return;
}


