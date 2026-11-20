/* Decompiled from supplied 5.2.2 arm package. VA 0x247a9c. FUN_00247a9c */

void FUN_00247a9c(void *param_1,undefined8 *param_2,short param_3,void *param_4,undefined8 *param_5,
                 int param_6,long param_7)

{
  short *psVar1;
  long lVar2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  short sVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  short sVar15;
  short sVar16;
  short sVar17;
  int iVar18;
  long lVar19;
  long lVar20;
  short *psVar21;
  undefined8 uVar22;
  short asStack_10248 [32742];
  uint local_27c;
  uint local_260;
  uint local_25c;
  int local_258;
  int local_254;
  int local_250;
  int local_24c;
  short asStack_248 [240];
  long local_68;
  
  lVar20 = *(long *)PTR____stack_chk_guard_01060708;
  local_68 = lVar20;
  local_258 = 0;
  if (param_3 == 1) {
    *(int *)(param_7 + 0x3c) = *(int *)(param_7 + 0x3c) + 1;
    if ((*(uint *)(param_7 + 0x48) & 0xffff) == 1) {
      sVar9 = *(short *)(param_7 + 0x44);
      local_27c = *(uint *)(param_7 + 0x48) >> 0x10;
    }
    else {
      lVar20 = param_7 + 0x62;
      (*DAT_0191b7d0)(lVar20,(long)*(short *)(param_7 + 2));
      sVar9 = FUN_00248168();
      uVar3 = sVar9 * 2 - 0x19;
      uVar5 = 0;
      if ((uVar3 & 0x8000) == 0) {
        uVar5 = uVar3;
      }
      *(ushort *)(param_7 + 0x46) = uVar5;
      local_27c = param_6 + 0xfffd;
      iVar14 = (int)*(short *)(param_7 + 2) - (param_6 + 3);
      iVar13 = 0x3c;
      if (iVar14 < 0x3d) {
        iVar13 = iVar14;
      }
      sVar9 = (short)iVar13;
      FUN_00246e88(&local_24c,&local_250,lVar20,(int)(short)local_27c);
      iVar14 = local_24c;
      iVar13 = -local_24c;
      if (-1 < local_24c) {
        iVar13 = local_24c;
      }
      uVar10 = FUN_00248168(iVar13);
      local_25c = (uVar10 & 0xffff) + 0xfff1;
      uVar10 = param_6 + 0xfffe;
      sVar6 = (short)(iVar14 << (ulong)(-(int)(short)local_25c & 0x1f));
      if (0xffff < (int)(local_25c * 0x10000)) {
        sVar6 = (short)(iVar14 >> ((int)(short)local_25c & 0x1fU));
      }
      local_260 = (uint)((int)sVar6 * (int)sVar6) >> 0xf;
      while( true ) {
        if (param_6 + 3 < (int)(short)uVar10) break;
        FUN_00246e88(&local_254,&local_258,lVar20,(int)(short)uVar10,(long)*(short *)(param_7 + 2),
                     (int)sVar9,(int)(short)uVar5);
        iVar14 = local_254;
        iVar13 = -local_254;
        if (-1 < local_254) {
          iVar13 = local_254;
        }
        uVar11 = FUN_00248168(iVar13);
        iVar13 = local_250;
        uVar11 = (uVar11 & 0xffff) + 0xfff1;
        sVar6 = (short)(iVar14 << (ulong)(-(int)(short)uVar11 & 0x1f));
        if (0xffff < (int)(uVar11 * 0x10000)) {
          sVar6 = (short)(iVar14 >> ((int)(short)uVar11 & 0x1fU));
        }
        uVar8 = (uint)((int)sVar6 * (int)sVar6) >> 0xf;
        iVar12 = FUN_00248168(local_250);
        iVar18 = local_258;
        iVar12 = iVar12 * 0x10000 + -0xf0000;
        uVar7 = iVar12 >> 0x10;
        sVar6 = (short)(iVar13 << (ulong)(-uVar7 & 0x1f));
        if (0xffff < iVar12) {
          sVar6 = (short)(iVar13 >> (uVar7 & 0x1f));
        }
        iVar12 = FUN_00248168(local_258);
        iVar13 = uVar7 + ((int)(uVar11 * 0x10000) >> 0xf);
        iVar12 = iVar12 * 0x10000 + -0xf0000;
        uVar4 = iVar12 >> 0x10;
        sVar15 = (short)(iVar18 << (ulong)(-uVar4 & 0x1f));
        if (0xffff < iVar12) {
          sVar15 = (short)(iVar18 >> (uVar4 & 0x1f));
        }
        iVar12 = uVar4 + (short)local_25c * 2;
        if (iVar13 < iVar12) {
          sVar16 = 0;
          iVar12 = (iVar12 - (-(uVar11 >> 0xf & 1) & 0xfffe0000 | (uVar11 & 0xffff) << 1)) - uVar7;
          iVar13 = 0x1f;
          if (iVar12 < 0x20) {
            iVar13 = iVar12;
          }
          sVar17 = (short)iVar13;
        }
        else {
          sVar17 = 0;
          iVar12 = (iVar13 - (-(local_25c >> 0xf & 1) & 0xfffe0000 | (local_25c & 0xffff) << 1)) -
                   uVar4;
          iVar13 = 0x1f;
          if (iVar12 < 0x20) {
            iVar13 = iVar12;
          }
          sVar16 = (short)iVar13;
        }
        if ((int)sVar15 * (int)(short)local_260 >> ((int)sVar16 & 0x1fU) <
            (int)(short)uVar8 * (int)sVar6 >> ((int)sVar17 & 0x1fU)) {
          local_25c = uVar11;
          local_27c = uVar10;
          local_260 = uVar8;
          local_250 = iVar18;
          local_24c = iVar14;
        }
        uVar10 = uVar10 + 1;
      }
      lVar20 = param_7 + (long)((int)*(short *)(param_7 + 2) - (int)sVar9) * 2 + 0x62;
      iVar13 = FUN_0024e098(lVar20,lVar20,(int)sVar9,(int)(short)uVar5);
      if (iVar13 < 1 || local_258 < 1) {
        sVar9 = 0;
      }
      else {
        iVar14 = FUN_002481e8(iVar13);
        iVar18 = local_250;
        iVar14 = iVar14 * 0x10000 + -0x100000;
        uVar10 = iVar14 >> 0x10;
        sVar9 = (short)(iVar13 << (ulong)(uVar10 & 0x1f));
        if (iVar14 < -0xffff) {
          sVar9 = (short)(iVar13 >> (-uVar10 & 0x1f));
        }
        iVar13 = FUN_002481e8(local_250);
        iVar13 = iVar13 * 0x10000 + -0x100000;
        uVar11 = iVar13 >> 0x10;
        sVar6 = (short)(iVar18 << (ulong)(uVar11 & 0x1f));
        if (iVar13 < -0xffff) {
          sVar6 = (short)(iVar18 >> (-uVar11 & 0x1f));
        }
        iVar13 = (uVar11 + uVar10) * 0x10000 + -0x10000;
        uVar10 = iVar13 >> 0x11;
        uVar11 = (iVar13 >> 0x10) - uVar10;
        sVar15 = (short)(local_24c << (ulong)(uVar10 & 0x1f));
        if ((int)uVar10 < 0) {
          sVar15 = (short)(local_24c >> (-uVar10 & 0x1f));
        }
        sVar17 = (short)(local_24c << (ulong)(uVar11 & 0x1f));
        if ((int)uVar11 < 0) {
          sVar17 = (short)(local_24c >> (-uVar11 & 0x1f));
        }
        sVar9 = FUN_0024df78((int)sVar17 * (int)sVar15,(int)sVar6 * (int)sVar9 >> 0x10);
      }
      lVar20 = *(long *)PTR____stack_chk_guard_01060708;
    }
    psVar21 = (short *)(param_7 + 2);
    sVar6 = *psVar21;
    uVar10 = 0x7333;
    if ((int)sVar6 * *(int *)(param_7 + 0x3c) < 0x141) {
      uVar10 = 0x7fff;
    }
    iVar13 = 0x7fff;
    if (sVar9 < 0x1ebd) {
      if (sVar9 < 0x348) {
        iVar13 = 0;
      }
      else {
        lVar19 = 0;
        do {
          psVar1 = &DAT_00c4f676 + lVar19;
          lVar2 = lVar19 + 5;
          lVar19 = lVar19 + -1;
        } while (0 < lVar2 && sVar9 < *psVar1);
        iVar13 = (int)*(short *)(&UNK_00c4f684 + lVar19 * 2) +
                 ((int)(short)(&DAT_00c4f690)[lVar19] * (int)(short)(sVar9 - *psVar1) >> 0xb);
        if (0x7ffe < iVar13) {
          iVar13 = 0x7fff;
        }
        iVar13 = (int)(short)iVar13;
      }
    }
    iVar18 = 0;
    iVar14 = 0;
    uVar11 = local_27c << 1;
    if (0x4f < (short)local_27c) {
      uVar11 = local_27c;
    }
    for (; iVar14 = (int)(short)iVar14, iVar14 < sVar6; iVar14 = iVar14 + 1) {
      uVar7 = *(short *)(param_7 + 0x242) * 0x7c4d + 0x3619;
      *(short *)(param_7 + 0x242) = (short)uVar7;
      uVar7 = (iVar14 + -0x35) - (uVar7 & 0x3f);
      iVar12 = uVar7 * 0x10000;
      if (iVar12 < 0) {
        lVar19 = (long)((iVar12 >> 0x10) + (int)sVar6) * 2;
      }
      else {
        lVar19 = (long)((ulong)uVar7 << 0x30) >> 0x2f;
      }
      asStack_248[iVar14] = *(short *)(param_7 + lVar19 + 0x62);
      uVar7 = iVar14 - (uVar11 & 0xffff);
      if ((int)(uVar7 * 0x10000) < 0) {
        sVar6 = *(short *)(param_7 + (long)(((int)(uVar7 * 0x10000) >> 0x10) + (int)sVar6) * 2 +
                          0x62);
      }
      else {
        sVar6 = *(short *)((long)param_1 +
                          (-((ulong)(uVar7 >> 0xf) & 1) & 0xfffffffffffe0000 |
                          ((ulong)uVar7 & 0xffff) << 1));
      }
      *(short *)((long)param_1 + (long)iVar14 * 2) = sVar6;
      iVar12 = 0x799a;
      if (0x9f < iVar14) {
        iVar12 = 0x7333;
      }
      uVar7 = uVar10;
      if (0x4f < iVar14) {
        uVar7 = uVar10 * iVar12 >> 0xf;
      }
      sVar15 = (short)(((sVar6 * iVar13 + (int)asStack_248[iVar14] * (0x7fff - iVar13)) * 2 + 0x8000
                       >> 0x10) * uVar7 >> 0xf);
      *(short *)((long)param_1 + (long)iVar14 * 2) = sVar15;
      sVar6 = *psVar21;
      iVar18 = ((uint)((int)sVar15 * (int)sVar15) >>
               (ulong)((int)*(short *)(param_7 + 0x46) + 1U & 0x1f)) + iVar18;
    }
    sVar15 = *(short *)(param_7 + 0x46);
    iVar13 = sVar6 * 900 << (ulong)(~(int)sVar15 & 0x1f);
    if (-1 < sVar15) {
      iVar13 = sVar6 * 900 >> ((int)sVar15 + 1U & 0x1f);
    }
    if (iVar18 < iVar13) {
      for (sVar15 = 0; sVar15 < sVar6; sVar15 = sVar15 + 1) {
        *(short *)((long)param_1 + (long)sVar15 * 2) = asStack_248[sVar15];
        sVar6 = *psVar21;
      }
    }
    *(undefined8 *)((long)param_2 + 0xe) = *(undefined8 *)(param_7 + 0x5a);
    uVar22 = *(undefined8 *)(param_7 + 0x4c);
    param_2[1] = *(undefined8 *)(param_7 + 0x54);
    *param_2 = uVar22;
    *(short *)(param_7 + 0x4a) = (short)local_27c;
    *(short *)(param_7 + 0x44) = sVar9;
  }
  else {
    _memcpy(param_1,param_4,(long)*(short *)(param_7 + 2) << 1);
    *(undefined8 *)((long)param_2 + 0xe) = *(undefined8 *)((long)param_5 + 0xe);
    uVar22 = *param_5;
    param_2[1] = param_5[1];
    *param_2 = uVar22;
    *(undefined4 *)(param_7 + 0x3c) = 0;
  }
  *(short *)(param_7 + 0x48) = param_3;
  *(undefined8 *)(param_7 + 0x5a) = *(undefined8 *)((long)param_2 + 0xe);
  uVar22 = *param_2;
  *(undefined8 *)(param_7 + 0x54) = param_2[1];
  *(undefined8 *)(param_7 + 0x4c) = uVar22;
  _memcpy((void *)(param_7 + 0x62),param_1,(long)*(short *)(param_7 + 2) << 1);
  if (lVar20 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


