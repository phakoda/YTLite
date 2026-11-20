/* Decompiled from supplied 5.2.2 arm package. VA 0x2688d0. FUN_002688d0 */

int FUN_002688d0(uint param_1,uint param_2,uint *param_3,uint param_4)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  undefined **ppuVar7;
  bool bVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined **ppuVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  undefined **ppuVar18;
  undefined1 auStack_60 [4];
  undefined1 auStack_5c [4];
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  
  ppuVar2 = (undefined **)0x0;
  if (param_2 < 0xc6) {
    ppuVar2 = &PTR_s_yuv420p_01065540 + (long)(int)param_2 * 0x14;
  }
  ppuVar3 = (undefined **)0x0;
  if (param_1 < 0xc6) {
    ppuVar3 = &PTR_s_yuv420p_01065540 + (long)(int)param_1 * 0x14;
  }
  if (ppuVar3 == (undefined **)0x0) {
    return -4;
  }
  if (ppuVar2 == (undefined **)0x0) {
    return -4;
  }
  if (((*(byte *)(ppuVar2 + 2) >> 3 & 1) != 0) || ((*(byte *)(ppuVar3 + 2) >> 3 & 1) != 0)) {
    if (param_1 != param_2) {
      return -2;
    }
    return -1;
  }
  *param_3 = 0;
  if (param_1 == param_2) {
    return 0x7fffffff;
  }
  iVar9 = FUN_00269024(auStack_54,auStack_58,param_2);
  if ((iVar9 < 0) || (iVar9 = FUN_00269024(auStack_5c,auStack_60,param_1), iVar9 < 0)) {
    return -3;
  }
  uVar10 = FUN_002690bc(ppuVar2);
  uVar11 = FUN_002690bc(ppuVar3);
  uVar15 = *(uint *)(ppuVar2 + 1);
  if (param_1 == 0xb) {
    uVar16 = uVar15;
    if (3 < (uVar15 & 0xff)) {
      uVar16 = 4;
    }
  }
  else {
    uVar16 = (uint)*(byte *)(ppuVar3 + 1);
    if ((uVar15 & 0xff) <= (uint)*(byte *)(ppuVar3 + 1)) {
      uVar16 = uVar15;
    }
  }
  uVar14 = 0;
  uVar16 = uVar16 & 0xff;
  iVar17 = 0x7ffffffe;
  iVar9 = uVar16 + 1;
  uVar6 = 0;
  ppuVar12 = ppuVar3 + 5;
  ppuVar7 = ppuVar2 + 5;
  if (uVar16 != 0) {
    uVar6 = 7 / uVar16;
  }
  while (ppuVar18 = ppuVar7, iVar9 = iVar9 + -1, iVar9 != 0) {
    ppuVar7 = ppuVar18 + 4;
    ppuVar1 = ppuVar12 + 4;
    uVar13 = uVar6;
    if (param_1 != 0xb) {
      uVar13 = *(int *)ppuVar12 - 1;
    }
    ppuVar12 = ppuVar1;
    if (((param_4 & 2) != 0) && ((int)uVar13 < *(int *)ppuVar18 + -1)) {
      uVar14 = 2;
      iVar17 = iVar17 - (0x10000U >> (ulong)(uVar13 & 0x1f));
    }
  }
  iVar9 = iVar17;
  if ((param_4 & 1) != 0) {
    bVar4 = *(byte *)((long)ppuVar3 + 9);
    if ((uVar15 & 0xff00) >> 8 < (uint)bVar4) {
      uVar14 = uVar14 | 1;
      iVar17 = iVar17 - (0x100 << (ulong)(bVar4 & 0x1f));
    }
    bVar5 = *(byte *)((long)ppuVar3 + 10);
    if ((uVar15 >> 0x10 & 0xff) < (uint)bVar5) {
      uVar14 = uVar14 | 1;
      iVar17 = iVar17 - (0x100 << (ulong)(bVar5 & 0x1f));
    }
    iVar9 = iVar17;
    if (((bVar4 == 1) && (*(ushort *)(ppuVar2 + 1) < 0x100 && bVar5 == 1)) &&
       (iVar9 = iVar17 + 0x200, (uVar15 >> 0x10 & 0xff) != 0)) {
      iVar9 = iVar17;
    }
  }
  uVar15 = uVar14;
  if ((param_4 >> 2 & 1) == 0) goto LAB_00268b54;
  switch(uVar11) {
  case 0:
    uVar15 = uVar14 | 4;
    if (uVar10 < 2) {
      uVar15 = uVar14;
    }
    goto LAB_00268b54;
  case 1:
    bVar8 = uVar10 == 1;
    break;
  case 2:
    bVar8 = uVar10 == 2;
    break;
  case 3:
    if (2 < uVar10 - 1) {
      uVar15 = uVar14 | 4;
    }
    goto LAB_00268b54;
  default:
    bVar8 = uVar10 == uVar11;
  }
  if (!bVar8) {
    uVar15 = uVar14 | 4;
  }
LAB_00268b54:
  if (uVar15 >> 2 != 0) {
    iVar17 = *(int *)(ppuVar2 + 5);
    if (*(int *)(ppuVar3 + 5) <= *(int *)(ppuVar2 + 5)) {
      iVar17 = *(int *)(ppuVar3 + 5);
    }
    iVar9 = iVar9 - ((uVar16 << 0x10) >> (ulong)(iVar17 - 1U & 0x1f));
  }
  if ((param_4 & 0x20) != 0 && (uVar10 != 1 && uVar11 == 1)) {
    iVar9 = iVar9 + -0x20000;
    uVar15 = uVar15 | 0x20;
  }
  if (((-1 < *(char *)(ppuVar3 + 2)) && ((param_4 >> 3 & 1) != 0)) &&
     (((ulong)ppuVar2[2] & 0x80) != 0)) {
    uVar15 = uVar15 | 8;
    iVar9 = iVar9 + -0x10000;
  }
  if (((param_1 == 0xb && param_2 != 0xb) && ((param_4 & 0x10) != 0)) &&
     ((uVar10 != 1 || (((param_4 >> 3 & 1) != 0 && (((ulong)ppuVar2[2] & 0x80) != 0)))))) {
    uVar15 = uVar15 | 0x10;
    iVar9 = iVar9 + -0x10000;
  }
  *param_3 = uVar15;
  return iVar9;
}


