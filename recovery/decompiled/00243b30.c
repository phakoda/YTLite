/* Decompiled from supplied 5.2.2 arm package. VA 0x243b30. FUN_00243b30 */

ulong FUN_00243b30(long param_1,uint param_2,uint param_3)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  uint uVar10;
  long lVar11;
  uint *puVar12;
  ulong uVar13;
  undefined1 (*pauVar14) [16];
  ulong uVar15;
  long lVar16;
  uint uVar17;
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  
  if (param_3 <= param_2) {
    return 0;
  }
  lVar16 = (long)(int)param_2;
  uVar9 = (ulong)((param_3 - 1) - param_2);
  uVar15 = uVar9 + 1;
  if ((uVar15 < 8) || (uVar13 = uVar15 & 0x1fffffff8, uVar13 == 0)) {
    uVar17 = 0;
    lVar11 = lVar16;
    uVar10 = param_2;
LAB_00243be4:
    iVar5 = param_3 - uVar10;
    puVar12 = (uint *)(param_1 + lVar11 * 4);
    uVar10 = uVar17;
    do {
      uVar17 = *puVar12;
      if ((int)*puVar12 <= (int)uVar10) {
        uVar17 = uVar10;
      }
      iVar5 = iVar5 + -1;
      puVar12 = puVar12 + 1;
      uVar10 = uVar17;
    } while (iVar5 != 0);
  }
  else {
    lVar11 = lVar16 + uVar13;
    uVar10 = (int)uVar13 + param_2;
    auVar18 = ZEXT816(0);
    uVar9 = uVar9 + 1 & 0x1fffffff8;
    auVar19 = ZEXT816(0);
    pauVar14 = (undefined1 (*) [16])(param_1 + (long)(int)param_2 * 4 + 0x10);
    do {
      uVar9 = uVar9 - 8;
      auVar18 = NEON_smax(auVar18,pauVar14[-1],4);
      auVar19 = NEON_smax(auVar19,*pauVar14,4);
      pauVar14 = pauVar14 + 2;
    } while (uVar9 != 0);
    auVar18 = NEON_smax(auVar18,auVar19,4);
    uVar17 = NEON_smaxv(auVar18,4);
    if (uVar15 != uVar13) goto LAB_00243be4;
  }
  if (uVar17 == 0) {
    return 0;
  }
  if (0xe < (int)uVar17) {
    uVar17 = uVar17 - 0xf;
    if (DAT_010634ec < uVar17) {
      if (DAT_0106350c < uVar17) {
        if (DAT_0106352c < uVar17) {
          if (DAT_0106354c < uVar17) {
            if (DAT_0106356c < uVar17) {
              if (DAT_0106358c < uVar17) {
                if (DAT_010635ac < uVar17) {
                  if (DAT_010635cc < uVar17) {
                    uVar10 = 0;
                    if (uVar17 <= DAT_010635ec) {
                      uVar10 = 0x17;
                    }
                  }
                  else {
                    uVar10 = 0x16;
                  }
                }
                else {
                  uVar10 = 0x15;
                }
              }
              else {
                uVar10 = 0x14;
              }
            }
            else {
              uVar10 = 0x13;
            }
          }
          else {
            uVar10 = 0x12;
          }
        }
        else {
          uVar10 = 0x11;
        }
      }
      else {
        uVar10 = 0x10;
      }
    }
    else {
      uVar10 = 0xf;
    }
    if (DAT_0106360c < uVar17) {
      if (DAT_0106362c < uVar17) {
        if (DAT_0106364c < uVar17) {
          if (DAT_0106366c < uVar17) {
            if (DAT_0106368c < uVar17) {
              if (DAT_010636ac < uVar17) {
                if (DAT_010636cc < uVar17) {
                  bVar2 = uVar17 <= DAT_010636ec;
                  uVar17 = 0x1f;
                  uVar8 = 0;
                  if (bVar2) {
                    uVar8 = 0x1f;
                  }
                }
                else {
                  uVar8 = 0x1e;
                }
              }
              else {
                uVar8 = 0x1d;
              }
            }
            else {
              uVar8 = 0x1c;
            }
          }
          else {
            uVar8 = 0x1b;
          }
        }
        else {
          uVar8 = 0x1a;
        }
      }
      else {
        uVar8 = 0x19;
      }
    }
    else {
      uVar8 = 0x18;
    }
    iVar5 = FUN_002440bc(uVar17,param_1,param_2,param_3,uVar10);
    iVar6 = FUN_002440bc(param_1,param_2,param_3,uVar8);
    if (iVar5 <= iVar6) {
      uVar8 = uVar10;
    }
    return (ulong)uVar8;
  }
  puVar12 = &DAT_010634a0;
  uVar15 = 0xe;
  do {
    uVar9 = uVar15;
    if (uVar9 == 0) {
      return 0;
    }
    uVar10 = *puVar12;
    uVar15 = uVar9 - 1;
    puVar12 = puVar12 + -8;
  } while (uVar10 <= uVar17);
  iVar5 = FUN_002440bc(param_1,param_2,param_3,uVar15 & 0xffffffff);
  uVar10 = (uint)uVar15;
  switch((int)uVar9) {
  case 3:
    iVar6 = 0;
    uVar15 = -(ulong)(param_2 + 1 >> 0x1f) & 0xfffffffc00000000 | (ulong)(param_2 + 1) << 2;
    do {
      iVar7 = *(int *)(param_1 + lVar16 * 4);
      piVar1 = (int *)(param_1 + uVar15);
      lVar16 = lVar16 + 2;
      uVar15 = uVar15 + 8;
      if (iVar7 != 0) {
        iVar6 = iVar6 + 1;
      }
      if (*piVar1 != 0) {
        iVar6 = iVar6 + 1;
      }
      iVar6 = iVar6 + (uint)(byte)PTR_DAT_01063378[(uint)(*piVar1 + iVar7 * DAT_01063364)];
    } while ((uint)lVar16 < param_3);
    bVar3 = SBORROW4(iVar6,iVar5);
    bVar2 = iVar6 - iVar5 < 0;
    bVar4 = iVar6 == iVar5;
    uVar17 = 3;
    break;
  default:
    goto switchD_00243c64_caseD_4;
  case 6:
    iVar6 = 0;
    uVar15 = -(ulong)(param_2 + 1 >> 0x1f) & 0xfffffffc00000000 | (ulong)(param_2 + 1) << 2;
    do {
      iVar7 = *(int *)(param_1 + lVar16 * 4);
      piVar1 = (int *)(param_1 + uVar15);
      lVar16 = lVar16 + 2;
      uVar15 = uVar15 + 8;
      if (iVar7 != 0) {
        iVar6 = iVar6 + 1;
      }
      if (*piVar1 != 0) {
        iVar6 = iVar6 + 1;
      }
      iVar6 = iVar6 + (uint)(byte)PTR_DAT_010633d8[(uint)(*piVar1 + iVar7 * DAT_010633c4)];
    } while ((uint)lVar16 < param_3);
    bVar3 = SBORROW4(iVar6,iVar5);
    bVar2 = iVar6 - iVar5 < 0;
    bVar4 = iVar6 == iVar5;
    uVar17 = 6;
    break;
  case 8:
    iVar6 = 0;
    uVar15 = -(ulong)(param_2 + 1 >> 0x1f) & 0xfffffffc00000000 | (ulong)(param_2 + 1) << 2;
    lVar11 = lVar16;
    do {
      iVar7 = *(int *)(param_1 + lVar11 * 4);
      piVar1 = (int *)(param_1 + uVar15);
      lVar11 = lVar11 + 2;
      uVar15 = uVar15 + 8;
      if (iVar7 != 0) {
        iVar6 = iVar6 + 1;
      }
      if (*piVar1 != 0) {
        iVar6 = iVar6 + 1;
      }
      iVar6 = iVar6 + (uint)(byte)PTR_DAT_01063418[(uint)(*piVar1 + iVar7 * DAT_01063404)];
    } while ((uint)lVar11 < param_3);
    iVar7 = 0;
    if (iVar6 <= iVar5) {
      uVar10 = 8;
      iVar5 = iVar6;
    }
    uVar15 = -(ulong)(param_2 + 1 >> 0x1f) & 0xfffffffc00000000 | (ulong)(param_2 + 1) << 2;
    do {
      iVar6 = *(int *)(param_1 + lVar16 * 4);
      piVar1 = (int *)(param_1 + uVar15);
      lVar16 = lVar16 + 2;
      uVar15 = uVar15 + 8;
      if (iVar6 != 0) {
        iVar7 = iVar7 + 1;
      }
      if (*piVar1 != 0) {
        iVar7 = iVar7 + 1;
      }
      iVar7 = iVar7 + (uint)(byte)PTR_DAT_01063438[(uint)(*piVar1 + iVar6 * DAT_01063424)];
    } while ((uint)lVar16 < param_3);
    if (iVar7 <= iVar5) {
      uVar10 = 9;
    }
    return (ulong)uVar10;
  case 0xb:
    iVar6 = 0;
    uVar15 = -(ulong)(param_2 + 1 >> 0x1f) & 0xfffffffc00000000 | (ulong)(param_2 + 1) << 2;
    lVar11 = lVar16;
    do {
      iVar7 = *(int *)(param_1 + lVar11 * 4);
      piVar1 = (int *)(param_1 + uVar15);
      lVar11 = lVar11 + 2;
      uVar15 = uVar15 + 8;
      if (iVar7 != 0) {
        iVar6 = iVar6 + 1;
      }
      if (*piVar1 != 0) {
        iVar6 = iVar6 + 1;
      }
      iVar6 = iVar6 + (uint)(byte)PTR_DAT_01063478[(uint)(*piVar1 + iVar7 * DAT_01063464)];
    } while ((uint)lVar11 < param_3);
    iVar7 = 0;
    if (iVar6 <= iVar5) {
      uVar10 = 0xb;
      iVar5 = iVar6;
    }
    uVar15 = -(ulong)(param_2 + 1 >> 0x1f) & 0xfffffffc00000000 | (ulong)(param_2 + 1) << 2;
    do {
      iVar6 = *(int *)(param_1 + lVar16 * 4);
      piVar1 = (int *)(param_1 + uVar15);
      lVar16 = lVar16 + 2;
      uVar15 = uVar15 + 8;
      if (iVar6 != 0) {
        iVar7 = iVar7 + 1;
      }
      if (*piVar1 != 0) {
        iVar7 = iVar7 + 1;
      }
      iVar7 = iVar7 + (uint)(byte)PTR_DAT_01063498[(uint)(*piVar1 + iVar6 * DAT_01063484)];
    } while ((uint)lVar16 < param_3);
    if (iVar7 <= iVar5) {
      uVar10 = 0xc;
    }
    return (ulong)uVar10;
  case 0xe:
    iVar6 = 0;
    uVar15 = -(ulong)(param_2 + 1 >> 0x1f) & 0xfffffffc00000000 | (ulong)(param_2 + 1) << 2;
    do {
      iVar7 = *(int *)(param_1 + lVar16 * 4);
      piVar1 = (int *)(param_1 + uVar15);
      lVar16 = lVar16 + 2;
      uVar15 = uVar15 + 8;
      if (iVar7 != 0) {
        iVar6 = iVar6 + 1;
      }
      if (*piVar1 != 0) {
        iVar6 = iVar6 + 1;
      }
      iVar6 = iVar6 + (uint)(byte)PTR_DAT_010634f8[(uint)(*piVar1 + iVar7 * DAT_010634e4)];
    } while ((uint)lVar16 < param_3);
    bVar3 = SBORROW4(iVar6,iVar5);
    bVar2 = iVar6 - iVar5 < 0;
    bVar4 = iVar6 == iVar5;
    uVar17 = 0xf;
  }
  if (bVar4 || bVar2 != bVar3) {
    uVar10 = uVar17;
  }
  uVar15 = (ulong)uVar10;
switchD_00243c64_caseD_4:
  return uVar15 & 0xffffffff;
}


