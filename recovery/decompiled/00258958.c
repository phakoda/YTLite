/* Decompiled from supplied 5.2.2 arm package. VA 0x258958. FUN_00258958 */

undefined1  [16] FUN_00258958(long param_1,undefined4 *param_2)

{
  uint uVar1;
  code *pcVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  long lVar7;
  double *pdVar8;
  ulong uVar9;
  int iVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  undefined1 auVar18 [16];
  double dVar19;
  undefined8 uVar20;
  double dVar21;
  double dVar22;
  
  switch(*param_2) {
  case 0:
    uVar20 = 0;
    dVar19 = *(double *)(param_2 + 2);
    goto switchD_00258b64_caseD_18;
  case 1:
    uVar20 = 0;
    dVar19 = *(double *)(param_2 + 2) *
             *(double *)(*(long *)(param_1 + 0x18) + (long)(int)param_2[4] * 8);
    goto switchD_00258b64_caseD_18;
  case 2:
    dVar19 = *(double *)(param_2 + 2);
    pcVar2 = *(code **)(param_2 + 6);
    FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar17 = (double)(*pcVar2)();
    break;
  case 3:
    dVar19 = *(double *)(param_2 + 2);
    uVar20 = *(undefined8 *)(param_1 + 0x48);
    pcVar2 = *(code **)(param_2 + 6);
    FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar17 = (double)(*pcVar2)(uVar20);
    break;
  case 4:
    dVar19 = *(double *)(param_2 + 2);
    uVar20 = *(undefined8 *)(param_1 + 0x48);
    pcVar2 = *(code **)(param_2 + 6);
    uVar11 = FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    uVar12 = FUN_00258958(param_1,*(undefined8 *)(param_2 + 10));
    dVar17 = (double)(*pcVar2)(uVar11,uVar12,uVar20);
    dVar19 = dVar19 * dVar17;
    uVar20 = 0;
    goto LAB_0025924c;
  case 5:
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar17 = (double)_exp(dVar17 * 4.0);
    dVar19 = 1.0 / (dVar17 + 1.0);
    uVar20 = 0;
    goto LAB_0025924c;
  case 6:
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar19 = (double)_exp(dVar17 * dVar17 * -0.5);
    dVar19 = dVar19 / DAT_00c50900;
    uVar20 = 0;
    goto LAB_0025924c;
  case 7:
    dVar19 = *(double *)(param_2 + 2);
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    iVar10 = (int)dVar17;
    iVar6 = 9;
    if (iVar10 < 10) {
      iVar6 = iVar10;
    }
    lVar7 = 0;
    if (-1 < iVar10) {
      lVar7 = (long)iVar6;
    }
    dVar17 = *(double *)(*(long *)(param_1 + 0x60) + lVar7 * 8);
    break;
  case 8:
    dVar19 = *(double *)(param_2 + 2);
    dVar13 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar17 = 1.0;
    if (!NAN(dVar13)) {
      dVar17 = 0.0;
    }
    break;
  case 9:
    dVar19 = *(double *)(param_2 + 2);
    dVar13 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar17 = 1.0;
    if (ABS(dVar13) != DAT_00c508f8) {
      dVar17 = 0.0;
    }
    break;
  default:
    dVar13 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar14 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 10));
    uVar20 = 0;
    dVar19 = DAT_00c502d8;
    dVar17 = dVar13;
    switch(*param_2) {
    case 10:
      dVar19 = *(double *)(param_2 + 2) * (dVar13 - dVar14 * (double)(long)(dVar13 / dVar14));
      uVar20 = 0;
      goto switchD_00258b64_caseD_18;
    case 0xb:
      dVar19 = *(double *)(param_2 + 2);
      if (dVar13 <= dVar14) {
        dVar17 = dVar14;
      }
      break;
    case 0xc:
      dVar19 = *(double *)(param_2 + 2);
      if (dVar14 <= dVar13) {
        dVar17 = dVar14;
      }
      break;
    case 0xd:
      dVar19 = *(double *)(param_2 + 2);
      dVar17 = 1.0;
      if (dVar13 != dVar14) {
        dVar17 = 0.0;
      }
      break;
    case 0xe:
      dVar19 = *(double *)(param_2 + 2);
      dVar17 = 1.0;
      if (dVar13 <= dVar14) {
        dVar17 = 0.0;
      }
      break;
    case 0xf:
      dVar19 = *(double *)(param_2 + 2);
      dVar17 = 1.0;
      if (dVar13 < dVar14) {
        dVar17 = 0.0;
      }
      break;
    case 0x10:
      dVar19 = *(double *)(param_2 + 2);
      dVar17 = 1.0;
      if (dVar14 < dVar13) {
        dVar17 = 0.0;
      }
      break;
    case 0x11:
      dVar19 = *(double *)(param_2 + 2);
      dVar17 = 1.0;
      if (dVar14 <= dVar13) {
        dVar17 = 0.0;
      }
      break;
    case 0x12:
      dVar19 = *(double *)(param_2 + 2);
      dVar17 = (double)_pow(dVar13);
      goto LAB_00259004;
    case 0x13:
      dVar19 = *(double *)(param_2 + 2);
      dVar17 = dVar13 * dVar14;
      break;
    case 0x14:
      dVar19 = *(double *)(param_2 + 2);
      dVar17 = dVar13 / dVar14;
      break;
    case 0x15:
      dVar19 = *(double *)(param_2 + 2);
      dVar17 = dVar13 + dVar14;
      break;
    case 0x16:
      dVar19 = *(double *)(param_2 + 2);
      dVar17 = dVar14;
      break;
    case 0x17:
      dVar19 = *(double *)(param_2 + 2);
      iVar10 = (int)dVar13;
      iVar6 = 9;
      if (iVar10 < 10) {
        iVar6 = iVar10;
      }
      lVar7 = 0;
      if (-1 < iVar10) {
        lVar7 = (long)iVar6;
      }
      *(double *)(*(long *)(param_1 + 0x60) + lVar7 * 8) = dVar14;
      dVar17 = dVar14;
      break;
    default:
      goto switchD_00258b64_caseD_18;
    case 0x22:
      dVar19 = *(double *)(param_2 + 2);
      dVar17 = (double)_hypot(dVar13);
      goto LAB_00259004;
    case 0x23:
      dVar19 = *(double *)(param_2 + 2);
      lVar7 = _av_gcd((long)dVar13,(long)dVar14);
      dVar17 = (double)lVar7;
      goto LAB_00259004;
    case 0x27:
      if (!NAN(dVar13) && !NAN(dVar14)) {
        dVar19 = *(double *)(param_2 + 2);
        uVar9 = (long)dVar14 & (long)dVar13;
LAB_00259240:
        dVar17 = (double)(long)uVar9;
        break;
      }
      goto switchD_00258b64_caseD_18;
    case 0x28:
      if (!NAN(dVar13) && !NAN(dVar14)) {
        dVar19 = *(double *)(param_2 + 2);
        uVar9 = (long)dVar14 | (long)dVar13;
        goto LAB_00259240;
      }
      goto switchD_00258b64_caseD_18;
    case 0x2b:
      dVar19 = *(double *)(param_2 + 2);
      dVar17 = (double)_atan2(dVar13);
LAB_00259004:
      uVar20 = 0;
      dVar19 = dVar19 * dVar17;
      goto switchD_00258b64_caseD_18;
    }
    uVar20 = 0;
    dVar19 = dVar17 * dVar19;
    goto switchD_00258b64_caseD_18;
  case 0x18:
    uVar20 = 0;
    dVar19 = DAT_00c502d8;
    while (dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8)), dVar17 != 0.0) {
      auVar18 = FUN_00258958(param_1,*(undefined8 *)(param_2 + 10));
      uVar20 = auVar18._8_8_;
      dVar19 = auVar18._0_8_;
    }
    goto switchD_00258b64_caseD_18;
  case 0x19:
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 10));
    if (*(long *)(param_2 + 0xc) == 0) {
      lVar7 = 0;
    }
    else {
      dVar19 = (double)FUN_00258958(param_1);
      iVar10 = (int)dVar19;
      iVar6 = 9;
      if (iVar10 < 10) {
        iVar6 = iVar10;
      }
      lVar7 = 0;
      if (-1 < iVar10) {
        lVar7 = (long)iVar6;
      }
    }
    uVar11 = *(undefined8 *)(*(long *)(param_1 + 0x60) + lVar7 * 8);
    iVar6 = 0;
    dVar14 = 1.0;
    dVar13 = 0.0;
    while (dVar19 = dVar13, iVar6 < 1000) {
      *(double *)(*(long *)(param_1 + 0x60) + lVar7 * 8) = (double)iVar6;
      dVar15 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
      dVar19 = dVar13 + dVar14 * dVar15;
      bVar3 = false;
      if ((dVar15 != 0.0) && (bVar3 = false, !NAN(dVar13) && !NAN(dVar19))) {
        bVar3 = dVar13 == dVar19;
      }
      if (bVar3) break;
      iVar6 = iVar6 + 1;
      dVar14 = dVar14 * (dVar17 / (double)iVar6);
      dVar13 = dVar19;
    }
    uVar20 = 0;
    *(undefined8 *)(*(long *)(param_1 + 0x60) + lVar7 * 8) = uVar11;
    goto switchD_00258b64_caseD_18;
  case 0x1a:
    uVar11 = **(undefined8 **)(param_1 + 0x60);
    dVar15 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 10));
    dVar17 = DAT_00c508e0;
    uVar20 = DAT_00c4c2f8;
    dVar21 = -1.0;
    iVar6 = -0x100;
    dVar22 = -1.0;
    dVar13 = DAT_00c502c8;
    dVar14 = DAT_00c508d8;
    do {
      uVar1 = iVar6 + 0xff;
      dVar19 = dVar21;
      dVar16 = dVar22;
      if (0x3ff < (int)uVar1) goto LAB_00258d68;
      if ((int)uVar1 < 0xff) {
        pdVar8 = *(double **)(param_1 + 0x60);
        dVar19 = (double)NEON_ucvtf((ulong)(byte)(&_ff_reverse)[uVar1 & 0xff]);
        dVar19 = (dVar15 * dVar19) / dVar17;
      }
      else {
        dVar16 = (double)_pow(uVar20,(double)iVar6);
        pdVar8 = *(double **)(param_1 + 0x60);
        dVar19 = dVar15 * dVar16;
        if ((uVar1 & 1) != 0) {
          dVar19 = -(dVar15 * dVar16);
        }
        *pdVar8 = dVar19;
        if ((uVar1 >> 1 & 1) == 0) {
          dVar19 = dVar22 + dVar19;
        }
        else {
          dVar19 = dVar21 + dVar19;
        }
      }
      *pdVar8 = dVar19;
      dVar19 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
      bVar3 = false;
      bVar4 = true;
      bVar5 = false;
      if (dVar19 <= 0.0) {
        bVar3 = false;
        bVar4 = false;
        bVar5 = true;
        if (!NAN(dVar19) && !NAN(dVar14)) {
          bVar3 = dVar19 < dVar14;
          bVar4 = dVar19 == dVar14;
          bVar5 = false;
        }
      }
      if (!bVar4 && bVar3 == bVar5) {
        dVar21 = **(double **)(param_1 + 0x60);
        dVar14 = dVar19;
      }
      bVar3 = false;
      if ((0.0 <= dVar19) && (bVar3 = false, !NAN(dVar19) && !NAN(dVar13))) {
        bVar3 = dVar19 < dVar13;
      }
      if (bVar3) {
        dVar22 = **(double **)(param_1 + 0x60);
        dVar13 = dVar19;
      }
      iVar6 = iVar6 + 1;
    } while ((dVar21 < 0.0) || (dVar22 < 0.0));
    iVar6 = -1;
    do {
      iVar6 = iVar6 + 1;
      dVar19 = dVar21;
      dVar16 = dVar22;
      if (999 < iVar6) break;
      dVar17 = (dVar21 + dVar22) * 0.5;
      **(double **)(param_1 + 0x60) = dVar17;
      bVar3 = true;
      if ((dVar21 != dVar17) && (bVar3 = false, !NAN(dVar22) && !NAN(dVar17))) {
        bVar3 = dVar22 == dVar17;
      }
      if (bVar3) break;
      dVar19 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
      if (dVar19 <= 0.0) {
        dVar21 = **(double **)(param_1 + 0x60);
      }
      if (0.0 <= dVar19) {
        dVar22 = **(double **)(param_1 + 0x60);
      }
      dVar16 = dVar19;
    } while (!NAN(dVar19));
LAB_00258d68:
    **(undefined8 **)(param_1 + 0x60) = uVar11;
    if (dVar13 <= -dVar14) {
      dVar19 = dVar16;
    }
    uVar20 = 0;
    goto switchD_00258b64_caseD_18;
  case 0x1b:
    dVar19 = *(double *)(param_2 + 2);
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar17 = (double)(long)dVar17;
    break;
  case 0x1c:
    dVar19 = *(double *)(param_2 + 2);
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar17 = (double)(long)dVar17;
    break;
  case 0x1d:
    dVar19 = *(double *)(param_2 + 2);
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar17 = (double)(long)dVar17;
    break;
  case 0x1e:
    dVar19 = *(double *)(param_2 + 2);
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar17 = (double)(long)dVar17;
    break;
  case 0x1f:
    dVar19 = *(double *)(param_2 + 2);
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar17 = SQRT(dVar17);
    break;
  case 0x20:
    dVar19 = *(double *)(param_2 + 2);
    dVar13 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar17 = 1.0;
    if (dVar13 != 0.0) {
      dVar17 = 0.0;
    }
    break;
  case 0x21:
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    iVar10 = (int)dVar17;
    iVar6 = 9;
    if (iVar10 < 10) {
      iVar6 = iVar10;
    }
    lVar7 = 0;
    if (-1 < iVar10) {
      lVar7 = (long)iVar6;
    }
    dVar19 = *(double *)(*(long *)(param_1 + 0x60) + lVar7 * 8);
    dVar17 = DAT_00c508e8;
    if (!NAN(dVar19)) {
      dVar17 = (double)((long)dVar19 * 0x19660d + 0x3c6ef35f);
    }
    *(double *)(*(long *)(param_1 + 0x60) + lVar7 * 8) = dVar17;
    uVar20 = 0;
    dVar19 = dVar17 * DAT_00c508f0 * *(double *)(param_2 + 2);
    goto switchD_00258b64_caseD_18;
  case 0x24:
    dVar19 = *(double *)(param_2 + 2);
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    if (dVar17 != 0.0) goto LAB_00258ff8;
LAB_00258ea8:
    lVar7 = *(long *)(param_2 + 0xc);
    if (lVar7 == 0) {
      dVar17 = 0.0;
      goto LAB_00259004;
    }
    goto LAB_00258ffc;
  case 0x25:
    dVar19 = *(double *)(param_2 + 2);
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    if (dVar17 != 0.0) goto LAB_00258ea8;
LAB_00258ff8:
    lVar7 = *(long *)(param_2 + 10);
LAB_00258ffc:
    dVar17 = (double)FUN_00258958(param_1,lVar7);
    goto LAB_00259004;
  case 0x26:
    auVar18 = FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    uVar20 = auVar18._8_8_;
    if (*(long *)(param_2 + 10) == 0) {
      iVar6 = 0x20;
    }
    else {
      dVar17 = (double)FUN_00258958(param_1);
      iVar6 = (int)dVar17;
    }
    _av_log(param_1,iVar6,"%f\n");
    dVar19 = auVar18._0_8_;
    goto switchD_00258b64_caseD_18;
  case 0x29:
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar13 = *(double *)(param_2 + 2);
    dVar19 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 10));
    if (dVar19 <= dVar17) {
      dVar19 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 0xc));
      dVar14 = 1.0;
      if (dVar19 < dVar17) {
        dVar14 = 0.0;
      }
    }
    else {
      dVar14 = 0.0;
    }
    uVar20 = 0;
    dVar19 = dVar13 * dVar14;
    goto switchD_00258b64_caseD_18;
  case 0x2a:
    dVar14 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 10));
    dVar13 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 0xc));
    uVar20 = 0;
    dVar19 = DAT_00c502d8;
    if (!NAN(dVar17) && !NAN(dVar13)) {
      bVar3 = false;
      bVar4 = false;
      bVar5 = false;
      if (!NAN(dVar14)) {
        bVar3 = false;
        bVar4 = false;
        bVar5 = true;
        if (!NAN(dVar17) && !NAN(dVar13)) {
          bVar3 = dVar17 < dVar13;
          bVar4 = dVar17 == dVar13;
          bVar5 = false;
        }
      }
      if (bVar4 || bVar3 != bVar5) {
        dVar19 = *(double *)(param_2 + 2);
        dVar14 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
        if (dVar14 <= dVar13) {
          dVar13 = dVar14;
        }
        if (dVar17 <= dVar14) {
          dVar17 = dVar13;
        }
        break;
      }
    }
switchD_00258b64_caseD_18:
    goto LAB_0025924c;
  case 0x2c:
    dVar19 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 10));
    dVar13 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 0xc));
    dVar19 = dVar19 + (dVar17 - dVar19) * dVar13;
    uVar20 = 0;
    goto LAB_0025924c;
  case 0x2d:
    dVar19 = *(double *)(param_2 + 2);
    dVar17 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar13 = (double)FUN_00258958(param_1,*(undefined8 *)(param_2 + 8));
    dVar17 = (double)(int)((uint)(0.0 < dVar17) - (uint)(dVar13 < 0.0));
  }
  dVar19 = dVar19 * dVar17;
  uVar20 = 0;
LAB_0025924c:
  auVar18._8_8_ = uVar20;
  auVar18._0_8_ = dVar19;
  return auVar18;
}


