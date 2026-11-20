/* Decompiled from supplied 5.2.2 arm package. VA 0x27cb1c. FUN_0027cb1c */

undefined8 FUN_0027cb1c(long param_1,long *param_2)

{
  double *pdVar1;
  undefined8 *puVar2;
  double dVar3;
  double dVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  long *plVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  long lVar12;
  double *pdVar13;
  double *pdVar14;
  long lVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  long *local_a8;
  
  lVar12 = *(long *)(*(long *)(param_1 + 0x10) + 0x48);
  pdVar13 = (double *)*param_2;
  uVar10 = **(undefined8 **)(*(long *)(param_1 + 0x10) + 0x38);
  dVar16 = *(double *)(lVar12 + 8);
  dVar21 = *(double *)(lVar12 + 0x10);
  dVar23 = *(double *)(lVar12 + 0x20);
  local_a8 = param_2;
  iVar7 = _av_frame_is_writable(param_2);
  plVar8 = param_2;
  if (iVar7 == 0) {
    plVar8 = (long *)_ff_get_audio_buffer(param_1,(int)param_2[0xe]);
    if (plVar8 == (long *)0x0) {
      _av_frame_free(&local_a8);
      return 0xfffffff4;
    }
    _av_frame_copy_props(plVar8,param_2);
  }
  dVar4 = DAT_00c537a8;
  dVar3 = DAT_00c508b0;
  pdVar14 = (double *)*plVar8;
  for (iVar7 = 0; iVar7 < (int)param_2[0xe]; iVar7 = iVar7 + 1) {
    if (*(int *)(lVar12 + 0x50) != 0) {
      dVar17 = *(double *)(lVar12 + 0xc0);
      dVar18 = DAT_00c4c3c0;
      if (DAT_00c4c3c0 <= dVar17 && DAT_00c53790 <= dVar17) {
        dVar18 = DAT_00c53790;
      }
      if (DAT_00c4c3c0 <= dVar17 && DAT_00c53790 > dVar17) {
        dVar18 = dVar17;
      }
      dVar22 = *(double *)(lVar12 + 0x90);
      dVar24 = *(double *)(lVar12 + 0x98);
      dVar17 = *(double *)(lVar12 + 0xa8) + *(double *)(lVar12 + 200) / dVar18;
      dVar18 = DAT_00c53798;
      if ((DAT_00c53798 <= dVar17) || (dVar18 = dVar17, 1.0 < dVar17)) {
        dVar17 = (double)_fmod(dVar18,0x3ff0000000000000);
      }
      dVar18 = (double)_sin((dVar17 * DAT_00c537a0 * dVar3) / DAT_00c508c0);
      dVar22 = dVar22 + dVar24 * (dVar18 * *(double *)(lVar12 + 0xb8) + 0.5);
      *(double *)(lVar12 + 0x48) = dVar22;
      *(int *)(lVar12 + 0x80) = (int)dVar22;
    }
    lVar15 = 0;
    lVar11 = 0;
    while (lVar11 < *(int *)(param_1 + 0xc4)) {
      lVar9 = *(long *)(lVar12 + 0xd0);
      pdVar1 = (double *)(lVar9 + lVar15);
      dVar17 = pdVar1[2];
      dVar18 = *pdVar13;
      pdVar1[2] = dVar17 + 1.0;
      if ((double)*(int *)(lVar12 + 0x80) <= dVar17 + 1.0) {
        dVar22 = *(double *)(lVar12 + 0x48);
        dVar24 = dVar22 + *pdVar1;
        dVar17 = (double)*(int *)(lVar12 + 0x80) + pdVar1[1];
        *pdVar1 = dVar24;
        pdVar1[1] = dVar17;
        if (dVar17 + 1.0 <= dVar22 + dVar24) {
          puVar2 = (undefined8 *)(lVar9 + lVar15);
          puVar2[3] = dVar16 * dVar18;
          *puVar2 = 0;
          puVar2[1] = 0;
        }
        pdVar1[2] = 0.0;
      }
      dVar27 = *(double *)(lVar12 + 0x30);
      dVar18 = *(double *)(lVar12 + 0x38);
      dVar24 = *(double *)(lVar12 + 0x40);
      dVar28 = *(double *)(lVar12 + 0x70);
      dVar22 = dVar23 * pdVar1[3] + dVar16 * (1.0 - dVar23) * *pdVar13;
      dVar17 = dVar27;
      if (dVar22 <= 0.0) {
        dVar17 = dVar18;
      }
      dVar22 = dVar22 * dVar17;
      if (*(int *)(lVar12 + 0x28) == 1) {
        dVar26 = *(double *)(lVar12 + 0x68);
        dVar19 = (double)_log();
        dVar17 = 0.0;
        if (dVar22 != 0.0) {
          dVar25 = dVar26 * dVar26 + dVar26 * dVar19;
          dVar19 = (double)(float)(int)dVar25;
          dVar17 = dVar28 + dVar19;
          bVar5 = false;
          bVar6 = true;
          if (dVar19 - dVar28 <= dVar25) {
            bVar5 = false;
            bVar6 = true;
            if (!NAN(dVar25) && !NAN(dVar17)) {
              bVar5 = dVar25 == dVar17;
              bVar6 = dVar17 <= dVar25;
            }
          }
          if (bVar6 && !bVar5) {
            dVar20 = (double)_exp(dVar19 / dVar26 - dVar26);
            if (dVar25 <= dVar17) {
              dVar17 = (double)_exp((dVar19 + -1.0) / dVar26 - dVar26);
              dVar24 = (double)_sin(((ABS(dVar25 - dVar19) - dVar28) * dVar3) / dVar24 + dVar4);
              dVar17 = (dVar22 / ABS(dVar22)) * (dVar20 + (dVar20 - dVar17) * (dVar24 + 1.0) * -0.5)
              ;
            }
            else {
              dVar17 = 1.0;
              if (dVar22 <= 0.0) {
                dVar17 = -1.0;
              }
              dVar26 = (double)_exp((dVar19 + 1.0) / dVar26 - dVar26);
              dVar24 = (double)_sin(((ABS(dVar25 - dVar19) - dVar28) * dVar3) / dVar24 + dVar4);
              dVar17 = dVar17 * (dVar20 + (dVar26 - dVar20) * (dVar24 + 1.0) * 0.5);
            }
          }
          else {
            dVar17 = (double)_exp(dVar19 / dVar26 - dVar26);
            dVar17 = (dVar22 / ABS(dVar22)) * dVar17;
          }
        }
      }
      else {
        dVar19 = *(double *)(lVar12 + 0x78);
        dVar26 = dVar19 * dVar22;
        dVar17 = (double)(float)(int)dVar26;
        dVar25 = dVar28 + dVar17;
        bVar5 = false;
        bVar6 = true;
        if (dVar17 - dVar28 <= dVar26) {
          bVar5 = false;
          bVar6 = true;
          if (!NAN(dVar26) && !NAN(dVar25)) {
            bVar5 = dVar26 == dVar25;
            bVar6 = dVar25 <= dVar26;
          }
        }
        if (bVar6 && !bVar5) {
          dVar20 = dVar17 / dVar19;
          if (dVar26 <= dVar25) {
            dVar19 = dVar20 - (dVar17 + -1.0) / dVar19;
            dVar17 = (double)_sin(((ABS(dVar26 - dVar17) - dVar28) * dVar3) / dVar24 + dVar4);
            dVar24 = -0.5;
          }
          else {
            dVar19 = (dVar17 + 1.0) / dVar19 - dVar20;
            dVar17 = (double)_sin(((ABS(dVar26 - dVar17) - dVar28) * dVar3) / dVar24 + dVar4);
            dVar24 = 0.5;
          }
          dVar17 = dVar20 + dVar19 * (dVar17 + 1.0) * dVar24;
        }
        else {
          dVar17 = dVar17 / dVar19;
        }
      }
      lVar11 = lVar11 + 1;
      lVar15 = lVar15 + 0x20;
      dVar17 = dVar17 + (dVar22 - dVar17) * *(double *)(lVar12 + 0x20);
      if (dVar17 <= 0.0) {
        dVar18 = dVar27;
      }
      *pdVar14 = dVar21 * dVar17 * dVar18;
      pdVar13 = pdVar13 + 1;
      pdVar14 = pdVar14 + 1;
    }
    if (*(int *)(lVar12 + 0x50) != 0) {
      dVar18 = ABS(*(double *)(lVar12 + 200) +
                   *(double *)(lVar12 + 0xa0) * (1.0 / (double)*(int *)(lVar12 + 0xb0)));
      if (1.0 <= dVar18) {
        dVar18 = (double)_fmod(dVar18,0x3ff0000000000000);
      }
      *(double *)(lVar12 + 200) = dVar18;
    }
  }
  if (plVar8 != param_2) {
    _av_frame_free(&local_a8);
  }
  uVar10 = _ff_filter_frame(uVar10,plVar8);
  return uVar10;
}


