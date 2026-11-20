/* Decompiled from supplied 5.2.2 arm package. VA 0x24e44c. FUN_0024e44c */

void FUN_0024e44c(undefined4 *param_1,undefined2 *param_2,short *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  short sVar8;
  uint uVar9;
  long lVar10;
  int iVar11;
  long lVar12;
  int iVar13;
  long lVar14;
  ushort auStack_10164 [21];
  ushort auStack_1013a [21];
  ushort auStack_10110 [21];
  ushort auStack_100e6 [21];
  ushort auStack_100bc [21];
  ushort auStack_10092 [32663];
  ushort auStack_164 [21];
  ushort auStack_13a [21];
  ushort auStack_110 [21];
  ushort auStack_e6 [21];
  ushort local_bc [21];
  ushort local_92 [25];
  
  lVar10 = *(long *)PTR____stack_chk_guard_01060708;
  uVar3 = FUN_0024e86c(*param_1);
  for (iVar11 = param_4; sVar8 = (short)iVar11, -1 < sVar8; iVar11 = iVar11 + -1) {
    uVar4 = param_1[sVar8] << (ulong)(uVar3 & 0x1f);
    local_92[sVar8] = (ushort)(uVar4 >> 0x10);
    local_bc[sVar8] = (ushort)(uVar4 >> 1) & 0x7fff;
  }
  iVar11 = (short)local_bc[1] * 2 + (uint)local_92[1] * 0x10000;
  iVar6 = -iVar11;
  if (-1 < iVar11) {
    iVar6 = iVar11;
  }
  uVar4 = FUN_0024e008(iVar6,(int)(short)local_92[0],(int)(short)local_bc[0]);
  uVar3 = -uVar4;
  if (iVar11 < 1) {
    uVar3 = uVar4;
  }
  sVar8 = (short)(uVar3 >> 0x10);
  *param_3 = sVar8;
  auStack_e6[1] = sVar8 >> 4;
  iVar11 = (int)uVar3 >> 0x10;
  auStack_110[1] = (ushort)((uVar3 >> 4) + ((int)uVar3 >> 0x14) * -0x10000 >> 1);
  iVar11 = iVar11 * iVar11 + (((int)((uVar3 - (uVar3 & 0x10000)) * 0x8000) >> 0x10) * iVar11 >> 0xe)
  ;
  iVar6 = iVar11 * 2;
  iVar11 = iVar11 * -2;
  if (-1 < iVar6) {
    iVar11 = iVar6;
  }
  uVar3 = 0x7fffffff - iVar11;
  iVar11 = (((int)uVar3 >> 0x10) * (int)(short)local_92[0] +
            (((int)uVar3 >> 0x10) * (int)(short)local_bc[0] >> 0xf) +
           (((int)((uVar3 - (uVar3 & 0x10000)) * 0x8000) >> 0x10) * (int)(short)local_92[0] >> 0xf))
           * 2;
  uVar3 = FUN_0024e86c(iVar11);
  uVar4 = iVar11 << (ulong)(uVar3 & 0x1f);
  iVar11 = 2;
  do {
    iVar11 = (int)(short)iVar11;
    if (param_4 < iVar11) {
      *param_2 = 0x1000;
      lVar12 = *(long *)PTR____stack_chk_guard_01060708;
      for (sVar8 = 1; sVar8 <= param_4; sVar8 = sVar8 + 1) {
        param_2[sVar8] =
             (short)(((short)auStack_110[sVar8] * 2 + (uint)auStack_e6[sVar8] * 0x10000) * 2 +
                     0x8000 >> 0x10);
      }
      uVar7 = 1;
LAB_0024e83c:
      if (lVar12 == lVar10) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail(uVar7);
    }
    iVar6 = 0;
    iVar13 = iVar11 + -1;
    lVar14 = (long)iVar11;
    iVar2 = iVar13;
    for (lVar12 = 1; lVar12 < lVar14; lVar12 = lVar12 + 1) {
      iVar6 = iVar6 + ((int)(short)auStack_e6[iVar2] * (int)(short)local_92[lVar12] +
                       ((int)(short)auStack_110[iVar2] * (int)(short)local_92[lVar12] >> 0xf) +
                      ((int)(short)local_bc[lVar12] * (int)(short)auStack_e6[iVar2] >> 0xf)) * 2;
      iVar2 = iVar2 + -1;
    }
    iVar6 = (uint)local_92[lVar14] * 0x10000 + iVar6 * 0x10 + (short)local_bc[lVar14] * 2;
    iVar2 = -iVar6;
    if (-1 < iVar6) {
      iVar2 = iVar6;
    }
    iVar5 = FUN_0024e008(iVar2,(int)uVar4 >> 0x10);
    iVar2 = -iVar5;
    if (iVar6 < 1) {
      iVar2 = iVar5;
    }
    iVar6 = FUN_0024e86c(iVar2);
    uVar3 = (uint)(short)uVar3;
    uVar9 = 0x7fffffff;
    if (iVar2 < 1) {
      uVar9 = 0x80000000;
    }
    uVar1 = iVar2 << (ulong)(uVar3 & 0x1f);
    if (iVar2 != 0 && iVar6 < (int)uVar3) {
      uVar1 = uVar9;
    }
    iVar6 = (int)uVar1 >> 0x10;
    sVar8 = (short)(uVar1 >> 0x10);
    param_3[iVar13] = sVar8;
    if (0x7fee < (iVar6 + ((int)uVar1 >> 0x1f) ^ (int)uVar1 >> 0x1f)) {
      uVar7 = 0;
      lVar12 = *(long *)PTR____stack_chk_guard_01060708;
      goto LAB_0024e83c;
    }
    iVar2 = (int)(short)(uVar1 + iVar6 * -0x10000 >> 1);
    for (lVar12 = 1; lVar12 < lVar14; lVar12 = lVar12 + 1) {
      uVar9 = (short)auStack_110[lVar12] * 2 + (uint)auStack_e6[lVar12] * 0x10000 +
              ((short)auStack_e6[iVar13] * iVar6 + ((short)auStack_e6[iVar13] * iVar2 >> 0xf) +
              ((short)auStack_110[iVar13] * iVar6 >> 0xf)) * 2;
      auStack_13a[lVar12] = (ushort)(uVar9 >> 0x10);
      auStack_164[lVar12] = (ushort)(uVar9 >> 1) & 0x7fff;
      iVar13 = iVar13 + -1;
    }
    iVar5 = (int)(short)(uVar4 >> 0x10);
    auStack_13a[lVar14] = sVar8 >> 4;
    iVar6 = iVar6 * iVar6 + (iVar2 * iVar6 >> 0xe);
    iVar13 = iVar6 * 2;
    auStack_164[lVar14] = (ushort)((uVar1 >> 4) + ((int)uVar1 >> 0x14) * -0x10000 >> 1);
    iVar6 = iVar6 * -2;
    if (-1 < iVar13) {
      iVar6 = iVar13;
    }
    uVar9 = 0x7fffffff - iVar6;
    iVar6 = (((int)uVar9 >> 0x10) * iVar5 +
             ((int)(((int)uVar9 >> 0x10) * (uVar4 >> 1 & 0x7fff)) >> 0xf) +
            (((int)((uVar9 - (uVar9 & 0x10000)) * 0x8000) >> 0x10) * iVar5 >> 0xf)) * 2;
    uVar4 = FUN_0024e86c(iVar6);
    uVar3 = uVar4 + uVar3;
    for (sVar8 = 1; sVar8 <= iVar11; sVar8 = sVar8 + 1) {
      auStack_e6[sVar8] = auStack_13a[sVar8];
      auStack_110[sVar8] = auStack_164[sVar8];
    }
    uVar4 = iVar6 << (ulong)(uVar4 & 0x1f);
    iVar11 = iVar11 + 1;
  } while( true );
}


