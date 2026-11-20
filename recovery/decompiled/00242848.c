/* Decompiled from supplied 5.2.2 arm package. VA 0x242848. _shine_inner_loop */

void _shine_inner_loop(long param_1,int param_2,long param_3,undefined8 param_4,undefined8 param_5,
                      long param_6)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  long lVar10;
  int *piVar11;
  long lVar12;
  double dVar13;
  
  if (param_2 < 0) {
    *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + -1;
  }
  dVar4 = DAT_00c4d5e0;
  do {
    do {
      do {
        lVar1 = (long)*(int *)(param_3 + 0x48) + 0x80;
        *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 1;
        iVar5 = *(int *)(&LAB_00009e30 + param_6 + lVar1 * 4);
      } while (0x28514 < (int)((ulong)((long)*(int *)(&DAT_000098c8 + param_6) * (long)iVar5 +
                                      0x80000000) >> 0x20));
      lVar10 = 0;
      iVar6 = 0;
      do {
        iVar7 = *(int *)(*(long *)(&LAB_000086c0 + param_6) + lVar10);
        lVar12 = -(long)iVar7;
        if (-1 < iVar7) {
          lVar12 = (long)iVar7;
        }
        lVar12 = lVar12 * iVar5 + 0x80000000;
        if ((int)((ulong)lVar12 >> 0x20) < 10000) {
          iVar7 = *(int *)(&LAB_0000a030 + param_6 + (lVar12 >> 0x20) * 4);
        }
        else {
          dVar13 = *(double *)(param_6 + lVar1 * 8 + 0x9a30) *
                   (double)(long)*(int *)(param_6 + 0x8fc8 + lVar10) * dVar4;
          iVar7 = (int)SQRT(SQRT(dVar13) * dVar13);
        }
        *(int *)(param_1 + lVar10) = iVar7;
        lVar10 = lVar10 + 4;
        if (iVar7 <= iVar6) {
          iVar7 = iVar6;
        }
        iVar6 = iVar7;
      } while (lVar10 != 0x900);
      lVar1 = 0;
    } while (0x2000 < iVar7);
    do {
      lVar10 = lVar1;
      if ((lVar10 + 0x240 < 2) || (lVar12 = param_1 + lVar10 * 4, *(int *)(lVar12 + 0x8fc) != 0))
      break;
      lVar1 = lVar10 + -2;
    } while (*(int *)(lVar12 + 0x8f8) == 0);
    lVar10 = lVar10 + 0x240;
    *(undefined4 *)(param_3 + 8) = 0;
    iVar5 = (int)lVar10;
    if (3 < iVar5) {
      piVar9 = (int *)(param_1 + -8 + (long)iVar5 * 4);
      lVar10 = (long)iVar5;
      piVar11 = (int *)(param_1 + (long)(iVar5 + -1) * 4);
      iVar5 = 1;
      do {
        if ((((1 < *piVar11) || (1 < *piVar9)) || (1 < piVar9[-1])) || (1 < piVar9[-2])) break;
        lVar10 = lVar10 + -4;
        *(int *)(param_3 + 8) = iVar5;
        piVar9 = piVar9 + -4;
        piVar11 = piVar11 + -4;
        iVar5 = iVar5 + 1;
      } while (3 < lVar10);
    }
    *(int *)(param_3 + 4) = (int)lVar10 >> 1;
    iVar5 = FUN_00242b84(param_1,param_3);
    FUN_00242c54(param_3,param_6);
    uVar2 = *(uint *)(param_3 + 0x3c);
    iVar6 = 0;
    *(undefined8 *)(param_3 + 0x14) = 0;
    *(undefined4 *)(param_3 + 0x1c) = 0;
    if (uVar2 != 0) {
      iVar6 = FUN_00243b30(param_1,0,uVar2);
      *(int *)(param_3 + 0x14) = iVar6;
    }
    uVar3 = *(uint *)(param_3 + 0x40);
    if (uVar2 < uVar3) {
      iVar7 = FUN_00243b30(param_1,uVar2,uVar3);
      *(int *)(param_3 + 0x18) = iVar7;
    }
    else {
      iVar7 = 0;
    }
    if (uVar3 < (uint)(*(int *)(param_3 + 4) << 1)) {
      iVar8 = FUN_00243b30(param_1,uVar3);
      *(int *)(param_3 + 0x1c) = iVar8;
    }
    else {
      iVar8 = 0;
    }
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_002440bc(param_1,0,uVar2,iVar6);
    }
    if (iVar7 != 0) {
      iVar7 = FUN_002440bc(param_1,uVar2,uVar3);
      iVar6 = iVar7 + iVar6;
    }
    if (iVar8 != 0) {
      iVar7 = FUN_002440bc(param_1,uVar3,*(undefined4 *)(param_3 + 0x44));
      iVar6 = iVar7 + iVar6;
    }
    if (iVar6 + iVar5 <= param_2) {
      return;
    }
  } while( true );
}


