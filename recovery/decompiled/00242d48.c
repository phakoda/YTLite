/* Decompiled from supplied 5.2.2 arm package. VA 0x242d48. _shine_outer_loop */

void _shine_outer_loop(int param_1,undefined8 param_2,long param_3,int param_4,int param_5,
                      long param_6)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  double dVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  long lVar13;
  int *piVar14;
  long lVar15;
  int *piVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  int iVar20;
  double dVar21;
  
  dVar7 = DAT_00c4d5e0;
  lVar18 = (long)param_5;
  lVar19 = (long)param_4;
  iVar12 = 0x78;
  iVar20 = -0x78;
  lVar13 = param_6 + lVar19 * 0xb8 + lVar18 * 0x5c;
  piVar1 = (int *)(lVar13 + 0xa0);
  do {
    iVar4 = iVar12;
    if (iVar12 < 0) {
      iVar4 = iVar12 + 1;
    }
    iVar4 = iVar4 >> 1;
    iVar2 = iVar4 + iVar20;
    iVar8 = *(int *)(&LAB_00009e30 + param_6 + ((long)iVar2 + 0x7f) * 4);
    iVar9 = 100000;
    if ((int)((ulong)((long)*(int *)(&DAT_000098c8 + param_6) * (long)iVar8 + 0x80000000) >> 0x20) <
        0x28515) {
      lVar15 = 0;
      iVar9 = 0;
      do {
        iVar10 = *(int *)(*(long *)(&LAB_000086c0 + param_6) + lVar15);
        lVar17 = -(long)iVar10;
        if (-1 < iVar10) {
          lVar17 = (long)iVar10;
        }
        lVar17 = lVar17 * iVar8 + 0x80000000;
        if ((int)((ulong)lVar17 >> 0x20) < 10000) {
          iVar10 = *(int *)(&LAB_0000a030 + param_6 + (lVar17 >> 0x20) * 4);
        }
        else {
          dVar21 = *(double *)(param_6 + ((long)iVar2 + 0x7f) * 8 + 0x9a30) *
                   (double)(long)*(int *)(param_6 + 0x8fc8 + lVar15) * dVar7;
          iVar10 = (int)SQRT(SQRT(dVar21) * dVar21);
        }
        *(int *)(param_3 + lVar15) = iVar10;
        lVar15 = lVar15 + 4;
        if (iVar10 <= iVar9) {
          iVar10 = iVar9;
        }
        iVar9 = iVar10;
      } while (lVar15 != 0x900);
      iVar9 = 100000;
      if (iVar10 < 0x2001) {
        lVar15 = 0;
        do {
          lVar17 = lVar15;
          if ((lVar17 + 0x240 < 2) || (lVar3 = param_3 + lVar17 * 4, *(int *)(lVar3 + 0x8fc) != 0))
          break;
          lVar15 = lVar17 + -2;
        } while (*(int *)(lVar3 + 0x8f8) == 0);
        lVar17 = lVar17 + 0x240;
        *(int *)(lVar13 + 0xa8) = 0;
        iVar9 = (int)lVar17;
        if (3 < iVar9) {
          piVar14 = (int *)(param_3 + -8 + (long)iVar9 * 4);
          lVar17 = (long)iVar9;
          piVar16 = (int *)(param_3 + (long)(iVar9 + -1) * 4);
          iVar9 = 1;
          do {
            if ((((1 < *piVar16) || (1 < *piVar14)) || (1 < piVar14[-1])) || (1 < piVar14[-2]))
            break;
            lVar17 = lVar17 + -4;
            *(int *)(lVar13 + 0xa8) = iVar9;
            piVar14 = piVar14 + -4;
            piVar16 = piVar16 + -4;
            iVar9 = iVar9 + 1;
          } while (3 < lVar17);
        }
        *(int *)(lVar13 + 0xa4) = (int)lVar17 >> 1;
        iVar8 = FUN_00242b84(param_3,piVar1);
        FUN_00242c54(piVar1,param_6);
        *(int *)(lVar13 + 0xb4) = 0;
        *(int *)(lVar13 + 0xb8) = 0;
        *(int *)(lVar13 + 0xbc) = 0;
        uVar5 = *(uint *)(lVar13 + 0xdc);
        iVar9 = 0;
        if (uVar5 != 0) {
          iVar9 = FUN_00243b30(param_3,0,uVar5);
          *(int *)(lVar13 + 0xb4) = iVar9;
        }
        uVar6 = *(uint *)(lVar13 + 0xe0);
        if (uVar5 < uVar6) {
          iVar10 = FUN_00243b30(param_3,uVar5,uVar6);
          *(int *)(lVar13 + 0xb8) = iVar10;
        }
        else {
          iVar10 = 0;
        }
        if (uVar6 < (uint)(*(int *)(lVar13 + 0xa4) << 1)) {
          iVar11 = FUN_00243b30(param_3,uVar6);
          *(int *)(lVar13 + 0xbc) = iVar11;
        }
        else {
          iVar11 = 0;
        }
        if (iVar9 == 0) {
          iVar9 = 0;
        }
        else {
          iVar9 = FUN_002440bc(param_3,0,uVar5);
        }
        if (iVar10 != 0) {
          iVar10 = FUN_002440bc(param_3,uVar5,uVar6);
          iVar9 = iVar10 + iVar9;
        }
        if (iVar11 != 0) {
          iVar10 = FUN_002440bc(param_3,uVar6,*(undefined4 *)(lVar13 + 0xe4));
          iVar9 = iVar10 + iVar9;
        }
        iVar9 = iVar9 + iVar8;
      }
    }
    iVar8 = iVar12 - iVar4;
    iVar12 = iVar4;
    if (param_1 <= iVar9) {
      iVar12 = iVar8;
      iVar20 = iVar2;
    }
  } while (1 < iVar12);
  lVar15 = param_6 + lVar19 * 0xb8 + lVar18 * 0x5c;
  lVar13 = (ulong)*(uint *)(lVar15 + 0xb0) * 4;
  iVar12 = *(int *)(&_shine_slen1_tab + lVar13);
  iVar9 = *(int *)(&_shine_slen2_tab + lVar13);
  *(int *)(lVar15 + 0xe8) = iVar20;
  if (param_4 == 0) {
    iVar20 = iVar9 * 5 + iVar12 * 0xb;
  }
  else {
    lVar13 = param_6 + lVar18 * 0x10;
    iVar8 = iVar12 * 6;
    iVar12 = iVar12 * 5;
    if (*(int *)(lVar13 + 0x80) != 0) {
      iVar8 = 0;
    }
    iVar20 = iVar9 * 5;
    if (*(int *)(lVar13 + 0x84) != 0) {
      iVar12 = 0;
    }
    if (*(int *)(lVar13 + 0x88) != 0) {
      iVar20 = 0;
    }
    iVar20 = iVar12 + iVar8 + iVar20;
    if (*(int *)(lVar13 + 0x8c) != 0) goto LAB_002431b8;
  }
  iVar20 = iVar20 + iVar9 * 5;
LAB_002431b8:
  lVar13 = param_6 + lVar19 * 0xb8 + lVar18 * 0x5c;
  *(int *)(lVar13 + 0xd4) = iVar20;
  iVar12 = _shine_inner_loop(param_3,param_1 - iVar20,piVar1,iVar4,iVar2,param_6);
  *piVar1 = *(int *)(lVar13 + 0xd4) + iVar12;
  return;
}


