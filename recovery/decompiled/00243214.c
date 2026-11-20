/* Decompiled from supplied 5.2.2 arm package. VA 0x243214. _shine_iteration_loop */

void _shine_iteration_loop(int *param_1)

{
  long *plVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined1 auVar6 [16];
  double dVar7;
  double dVar8;
  undefined4 uVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  int *piVar13;
  int *piVar14;
  long lVar15;
  ulong uVar16;
  int *piVar17;
  undefined1 (*pauVar18) [16];
  long lVar19;
  ulong uVar20;
  long lVar21;
  long lVar22;
  long lVar23;
  int iVar24;
  int iVar29;
  double dVar25;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  int iVar34;
  int iVar37;
  int iVar38;
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  int iVar39;
  int iVar40;
  int iVar41;
  int iVar44;
  int iVar45;
  int iVar46;
  int iVar47;
  int iVar48;
  int iVar49;
  int iVar50;
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  int iVar51;
  int iVar52;
  int iVar53;
  int iVar54;
  undefined1 auVar55 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  int iVar59;
  int iVar60;
  int iVar61;
  long local_3e0;
  double adStack_310 [84];
  
  dVar8 = DAT_00c4d5f0;
  dVar7 = DAT_00c4d5e8;
  iVar4 = *param_1;
  if (iVar4 != 0) {
    local_3e0 = 0;
    iVar5 = iVar4 + -1;
    uVar10 = (ulong)(uint)param_1[4];
    plVar1 = (long *)(param_1 + 0x21b0);
    piVar2 = param_1 + 0x2632;
    do {
      iVar4 = iVar4 + -1;
      if (0 < (int)uVar10) {
        lVar21 = 0;
        lVar11 = iVar5 - local_3e0;
        lVar22 = (long)iVar4;
        do {
          lVar12 = 0;
          piVar14 = param_1 + (long)(&UNK_000018ae + lVar22 * 0x480 + lVar21 * 0x240);
          *plVar1 = (long)piVar14;
          *piVar2 = 0;
          while( true ) {
            param_1[(long)(&UNK_000023f1 + lVar12)] =
                 (int)((long)piVar14[lVar12 + 0x23f] * (long)piVar14[lVar12 + 0x23f] + 0x40000000U
                      >> 0x1f);
            iVar24 = *(int *)(*plVar1 + lVar12 * 4 + 0x8fc);
            iVar41 = -iVar24;
            if (-1 < iVar24) {
              iVar41 = iVar24;
            }
            param_1[(long)(&UNK_00002631 + lVar12)] = iVar41;
            if (*piVar2 < iVar41) {
              *piVar2 = iVar41;
            }
            lVar12 = lVar12 + -1;
            if (lVar12 == -0x240) break;
            piVar14 = (int *)*plVar1;
          }
          piVar14 = param_1 + lVar21 * 0x2e + lVar22 * 0x17 + 0x28;
          param_1[lVar21 * 0x2e + lVar22 * 0x17 + 0x36] = 0x15;
          _memset(adStack_310 + lVar21 * 0x2a + lVar22 * 0x15,0,0xa8);
          if (param_1[2] == 3) {
            iVar41 = param_1[0x12];
            iVar24 = 0;
            iVar29 = 0;
            iVar30 = 0;
            iVar32 = 0;
            lVar12 = 0x240;
            param_1[(long)(&UNK_00002689 + lVar21)] = *piVar2;
            piVar13 = param_1 + 0x23ee;
            auVar28 = ZEXT816(0);
            do {
              lVar12 = lVar12 + -8;
              auVar56._0_4_ = *piVar13 >> 10;
              auVar56._4_4_ = piVar13[1] >> 10;
              auVar56._8_4_ = piVar13[2] >> 10;
              auVar56._12_4_ = piVar13[3] >> 10;
              auVar55._0_4_ = piVar13[-4] >> 10;
              auVar55._4_4_ = piVar13[-3] >> 10;
              auVar55._8_4_ = piVar13[-2] >> 10;
              auVar55._12_4_ = piVar13[-1] >> 10;
              auVar42 = NEON_rev64(auVar56,4);
              auVar56 = NEON_rev64(auVar55,4);
              auVar42 = NEON_ext(auVar42,auVar42,8,1);
              auVar56 = NEON_ext(auVar56,auVar56,8,1);
              iVar24 = auVar42._0_4_ + iVar24;
              iVar29 = auVar42._4_4_ + iVar29;
              iVar30 = auVar42._8_4_ + iVar30;
              iVar32 = auVar42._12_4_ + iVar32;
              auVar42._0_4_ = auVar56._0_4_ + auVar28._0_4_;
              auVar42._4_4_ = auVar56._4_4_ + auVar28._4_4_;
              auVar42._8_4_ = auVar56._8_4_ + auVar28._8_4_;
              auVar42._12_4_ = auVar56._12_4_ + auVar28._12_4_;
              piVar13 = piVar13 + -8;
              auVar28 = auVar42;
            } while (lVar12 != 0);
            iVar24 = auVar42._0_4_ + iVar24 + auVar42._4_4_ + iVar29 +
                     auVar42._8_4_ + iVar30 + auVar42._12_4_ + iVar32;
            if (iVar24 == 0) {
              iVar24 = 0;
            }
            else {
              auVar28._0_8_ = (double)iVar24 * dVar7;
              auVar28._8_8_ = 0;
              dVar25 = (double)_log(auVar28);
              iVar24 = (int)(dVar25 / dVar8);
            }
            lVar23 = 0x15;
            param_1[(long)(&UNK_00002633 + lVar21)] = iVar24;
            lVar12 = 0x14;
            do {
              iVar29 = *(int *)(&_shine_scale_fact_band_index + lVar12 * 4 + (long)iVar41 * 0x5c);
              lVar19 = (long)iVar29;
              iVar24 = *(int *)(&_shine_scale_fact_band_index + lVar23 * 4 + (long)iVar41 * 0x5c);
              if (iVar29 < iVar24) {
                uVar10 = (ulong)(uint)((iVar24 + -1) - iVar29) + 1;
                if ((uVar10 < 8) || (uVar16 = uVar10 & 0x1fffffff8, uVar16 == 0)) {
                  iVar29 = 0;
                  lVar15 = lVar19;
LAB_002435c4:
                  iVar24 = iVar24 - (int)lVar15;
                  piVar13 = param_1 + (long)(&UNK_000021b2 + lVar15);
                  do {
                    iVar29 = iVar29 + (*piVar13 >> 10);
                    iVar24 = iVar24 + -1;
                    piVar13 = piVar13 + 1;
                  } while (iVar24 != 0);
                }
                else {
                  lVar15 = lVar19 + uVar16;
                  iVar30 = 0;
                  iVar32 = 0;
                  iVar31 = 0;
                  iVar33 = 0;
                  uVar20 = (ulong)(uint)((iVar24 + -1) - iVar29) + 1 & 0x1fffffff8;
                  pauVar18 = (undefined1 (*) [16])(param_1 + (long)(&UNK_000021b6 + lVar19));
                  auVar28 = ZEXT816(0);
                  do {
                    auVar42 = pauVar18[-1];
                    auVar56 = *pauVar18;
                    uVar20 = uVar20 - 8;
                    iVar30 = iVar30 + (auVar42._0_4_ >> 10);
                    iVar32 = iVar32 + (auVar42._4_4_ >> 10);
                    iVar31 = iVar31 + (auVar42._8_4_ >> 10);
                    iVar33 = iVar33 + (auVar42._12_4_ >> 10);
                    auVar35._0_4_ = auVar28._0_4_ + (auVar56._0_4_ >> 10);
                    auVar35._4_4_ = auVar28._4_4_ + (auVar56._4_4_ >> 10);
                    auVar35._8_4_ = auVar28._8_4_ + (auVar56._8_4_ >> 10);
                    auVar35._12_4_ = auVar28._12_4_ + (auVar56._12_4_ >> 10);
                    pauVar18 = pauVar18 + 2;
                    auVar28 = auVar35;
                  } while (uVar20 != 0);
                  iVar29 = auVar35._0_4_ + iVar30 + auVar35._4_4_ + iVar32 +
                           auVar35._8_4_ + iVar31 + auVar35._12_4_ + iVar33;
                  if (uVar10 != uVar16) goto LAB_002435c4;
                }
                if (iVar29 == 0) {
                  iVar24 = 0;
                }
                else {
                  auVar26._0_8_ = (double)iVar29 * dVar7;
                  auVar26._8_8_ = 0;
                  dVar25 = (double)_log(auVar26);
                  iVar24 = (int)(dVar25 / dVar8);
                }
              }
              else {
                iVar24 = 0;
              }
              param_1[(long)(&UNK_00002635 + lVar21 * 0x15 + lVar12)] = iVar24;
              if (adStack_310[lVar21 * 0x2a + lVar22 * 0x15 + lVar12] == 0.0) {
                iVar24 = 0;
              }
              else {
                dVar25 = (double)_log();
                iVar24 = (int)(dVar25 / dVar8);
              }
              param_1[(long)(&UNK_0000265f + lVar21 * 0x15 + lVar12)] = iVar24;
              lVar23 = lVar23 + -1;
              bVar3 = lVar12 != 0;
              lVar12 = lVar12 + -1;
            } while (bVar3);
            if (lVar21 == 1) {
              auVar27._0_4_ = param_1[0x2646] - param_1[0x265b];
              auVar27._4_4_ = param_1[0x2647] - param_1[0x265c];
              auVar27._8_4_ = param_1[0x2648] - param_1[0x265d];
              auVar27._12_4_ = param_1[0x2649] - param_1[0x265e];
              auVar43._0_4_ = param_1[0x2642] - param_1[0x2657];
              auVar43._4_4_ = param_1[0x2643] - param_1[0x2658];
              auVar43._8_4_ = param_1[0x2644] - param_1[0x2659];
              auVar43._12_4_ = param_1[0x2645] - param_1[0x265a];
              auVar57._0_4_ =
                   (int)*(undefined8 *)(param_1 + 0x263e) - (int)*(undefined8 *)(param_1 + 0x2653);
              auVar57._4_4_ =
                   (int)((ulong)*(undefined8 *)(param_1 + 0x263e) >> 0x20) -
                   (int)((ulong)*(undefined8 *)(param_1 + 0x2653) >> 0x20);
              auVar57._8_4_ =
                   (int)*(undefined8 *)(param_1 + 0x2640) - (int)*(undefined8 *)(param_1 + 0x2655);
              auVar57._12_4_ =
                   (int)((ulong)*(undefined8 *)(param_1 + 0x2640) >> 0x20) -
                   (int)((ulong)*(undefined8 *)(param_1 + 0x2655) >> 0x20);
              auVar36._0_4_ = (int)*(undefined8 *)(param_1 + 0x2636) - param_1[0x264b];
              auVar36._4_4_ =
                   (int)((ulong)*(undefined8 *)(param_1 + 0x2636) >> 0x20) - param_1[0x264c];
              auVar36._8_4_ = (int)*(undefined8 *)(param_1 + 0x2638) - param_1[0x264d];
              auVar36._12_4_ =
                   (int)((ulong)*(undefined8 *)(param_1 + 0x2638) >> 0x20) - param_1[0x264e];
              auVar28 = NEON_rev64(auVar27,4);
              auVar42 = NEON_rev64(auVar43,4);
              auVar28 = NEON_ext(auVar28,auVar28,8,1);
              auVar42 = NEON_ext(auVar42,auVar42,8,1);
              iVar24 = MP_INT_ABS(auVar28._0_4_);
              iVar29 = MP_INT_ABS(auVar28._4_4_);
              iVar30 = MP_INT_ABS(auVar28._8_4_);
              iVar32 = MP_INT_ABS(auVar28._12_4_);
              iVar31 = MP_INT_ABS(auVar42._0_4_);
              iVar44 = MP_INT_ABS(auVar42._4_4_);
              iVar47 = MP_INT_ABS(auVar42._8_4_);
              iVar51 = MP_INT_ABS(auVar42._12_4_);
              auVar28 = NEON_rev64(auVar57,4);
              auVar28 = NEON_ext(auVar28,auVar28,8,1);
              iVar33 = MP_INT_ABS(auVar28._0_4_);
              iVar45 = MP_INT_ABS(auVar28._4_4_);
              iVar48 = MP_INT_ABS(auVar28._8_4_);
              iVar52 = MP_INT_ABS(auVar28._12_4_);
              iVar41 = 2;
              if (param_1[0x268a] != 0) {
                iVar41 = 3;
              }
              iVar54 = param_1[0x2633] - param_1[0x2634];
              auVar6._4_4_ = (int)((ulong)*(undefined8 *)(param_1 + 0x263a) >> 0x20) -
                             (int)((ulong)*(undefined8 *)(param_1 + 0x264f) >> 0x20);
              auVar6._0_4_ = (int)*(undefined8 *)(param_1 + 0x263a) -
                             (int)*(undefined8 *)(param_1 + 0x264f);
              auVar6._8_4_ = (int)*(undefined8 *)(param_1 + 0x263c) -
                             (int)*(undefined8 *)(param_1 + 0x2651);
              auVar6._12_4_ =
                   (int)((ulong)*(undefined8 *)(param_1 + 0x263c) >> 0x20) -
                   (int)((ulong)*(undefined8 *)(param_1 + 0x2651) >> 0x20);
              auVar42 = NEON_rev64(auVar6,4);
              auVar28 = NEON_rev64(auVar36,4);
              iVar50 = -iVar54;
              if (-1 < iVar54) {
                iVar50 = iVar54;
              }
              auVar42 = NEON_ext(auVar42,auVar42,8,1);
              auVar28 = NEON_ext(auVar28,auVar28,8,1);
              iVar59 = param_1[0x2635] - param_1[0x264a];
              iVar40 = MP_INT_ABS(auVar42._0_4_);
              iVar46 = MP_INT_ABS(auVar42._4_4_);
              iVar49 = MP_INT_ABS(auVar42._8_4_);
              iVar53 = MP_INT_ABS(auVar42._12_4_);
              iVar34 = MP_INT_ABS(auVar28._0_4_);
              iVar37 = MP_INT_ABS(auVar28._4_4_);
              iVar38 = MP_INT_ABS(auVar28._8_4_);
              iVar39 = MP_INT_ABS(auVar28._12_4_);
              iVar54 = -iVar59;
              if (-1 < iVar59) {
                iVar54 = iVar59;
              }
              if (param_1[0x2689] != 0) {
                iVar41 = iVar41 + 1;
              }
              if (iVar50 < 10) {
                iVar41 = iVar41 + 1;
              }
              if (iVar54 + iVar34 + iVar40 + iVar33 + iVar31 + iVar24 +
                           iVar37 + iVar46 + iVar45 + iVar44 + iVar29 +
                           iVar38 + iVar49 + iVar48 + iVar47 + iVar30 +
                           iVar39 + iVar53 + iVar52 + iVar51 + iVar32 < 100) {
                iVar41 = iVar41 + 1;
              }
              if (iVar41 == 6) {
                lVar12 = 0;
LAB_0024379c:
                lVar23 = (long)(int)lVar12;
                do {
                  iVar24 = 0;
                  iVar41 = 0;
                  lVar12 = lVar23 + 1;
                  iVar30 = (&DAT_00c4d608)[lVar23];
                  lVar19 = (long)iVar30;
                  iVar32 = (int)lVar12;
                  iVar29 = (&DAT_00c4d608)[iVar32];
                  piVar13 = param_1 + lVar22 * 4 + lVar23 + 0x20;
                  *piVar13 = 0;
                  if (iVar30 < iVar29) {
                    uVar10 = (ulong)(uint)((iVar29 + -1) - iVar30) + 1;
                    if ((uVar10 < 8) || (uVar16 = uVar10 & 0x1fffffff8, uVar16 == 0)) {
                      iVar24 = 0;
                      iVar41 = 0;
                      lVar23 = lVar19;
                    }
                    else {
                      lVar23 = lVar19 + uVar16;
                      piVar17 = param_1 + 0x2635 + lVar19;
                      iVar24 = 0;
                      iVar31 = 0;
                      iVar33 = 0;
                      iVar44 = 0;
                      iVar45 = 0;
                      iVar47 = 0;
                      iVar48 = 0;
                      iVar51 = 0;
                      iVar41 = 0;
                      iVar52 = 0;
                      iVar50 = 0;
                      iVar54 = 0;
                      uVar20 = (ulong)(uint)((iVar29 + -1) - iVar30) + 1 & 0x1fffffff8;
                      auVar28 = ZEXT816(0);
                      do {
                        uVar20 = uVar20 - 8;
                        iVar30 = MP_INT_ABS((int)*(undefined8 *)piVar17 -
                                            (int)*(undefined8 *)(piVar17 + 0x15));
                        iVar59 = MP_INT_ABS((int)((ulong)*(undefined8 *)piVar17 >> 0x20) -
                                            (int)((ulong)*(undefined8 *)(piVar17 + 0x15) >> 0x20));
                        iVar34 = MP_INT_ABS((int)*(undefined8 *)(piVar17 + 2) -
                                            (int)*(undefined8 *)(piVar17 + 0x17));
                        iVar37 = MP_INT_ABS((int)((ulong)*(undefined8 *)(piVar17 + 2) >> 0x20) -
                                            (int)((ulong)*(undefined8 *)(piVar17 + 0x17) >> 0x20));
                        iVar38 = MP_INT_ABS((int)*(undefined8 *)(piVar17 + 4) -
                                            (int)*(undefined8 *)(piVar17 + 0x19));
                        iVar39 = MP_INT_ABS((int)((ulong)*(undefined8 *)(piVar17 + 4) >> 0x20) -
                                            (int)((ulong)*(undefined8 *)(piVar17 + 0x19) >> 0x20));
                        iVar40 = MP_INT_ABS((int)*(undefined8 *)(piVar17 + 6) -
                                            (int)*(undefined8 *)(piVar17 + 0x1b));
                        iVar46 = MP_INT_ABS((int)((ulong)*(undefined8 *)(piVar17 + 6) >> 0x20) -
                                            (int)((ulong)*(undefined8 *)(piVar17 + 0x1b) >> 0x20));
                        iVar49 = MP_INT_ABS((int)*(undefined8 *)(piVar17 + 0x2a) -
                                            (int)*(undefined8 *)(piVar17 + 0x3f));
                        iVar53 = MP_INT_ABS((int)((ulong)*(undefined8 *)(piVar17 + 0x2a) >> 0x20) -
                                            (int)((ulong)*(undefined8 *)(piVar17 + 0x3f) >> 0x20));
                        iVar60 = MP_INT_ABS((int)*(undefined8 *)(piVar17 + 0x2c) -
                                            (int)*(undefined8 *)(piVar17 + 0x41));
                        iVar61 = MP_INT_ABS((int)((ulong)*(undefined8 *)(piVar17 + 0x2c) >> 0x20) -
                                            (int)((ulong)*(undefined8 *)(piVar17 + 0x41) >> 0x20));
                        iVar41 = iVar30 + iVar41;
                        iVar52 = iVar59 + iVar52;
                        iVar50 = iVar34 + iVar50;
                        iVar54 = iVar37 + iVar54;
                        auVar58._0_4_ = iVar38 + auVar28._0_4_;
                        auVar58._4_4_ = iVar39 + auVar28._4_4_;
                        auVar58._8_4_ = iVar40 + auVar28._8_4_;
                        auVar58._12_4_ = iVar46 + auVar28._12_4_;
                        iVar30 = MP_INT_ABS((int)*(undefined8 *)(piVar17 + 0x2e) -
                                            (int)*(undefined8 *)(piVar17 + 0x43));
                        iVar59 = MP_INT_ABS((int)((ulong)*(undefined8 *)(piVar17 + 0x2e) >> 0x20) -
                                            (int)((ulong)*(undefined8 *)(piVar17 + 0x43) >> 0x20));
                        iVar34 = MP_INT_ABS((int)*(undefined8 *)(piVar17 + 0x30) -
                                            (int)*(undefined8 *)(piVar17 + 0x45));
                        iVar37 = MP_INT_ABS((int)((ulong)*(undefined8 *)(piVar17 + 0x30) >> 0x20) -
                                            (int)((ulong)*(undefined8 *)(piVar17 + 0x45) >> 0x20));
                        iVar24 = iVar49 + iVar24;
                        iVar31 = iVar53 + iVar31;
                        iVar33 = iVar60 + iVar33;
                        iVar44 = iVar61 + iVar44;
                        iVar45 = iVar30 + iVar45;
                        iVar47 = iVar59 + iVar47;
                        iVar48 = iVar34 + iVar48;
                        iVar51 = iVar37 + iVar51;
                        piVar17 = piVar17 + 8;
                        auVar28 = auVar58;
                      } while (uVar20 != 0);
                      iVar41 = auVar58._0_4_ + iVar41 + auVar58._4_4_ + iVar52 +
                               auVar58._8_4_ + iVar50 + auVar58._12_4_ + iVar54;
                      iVar24 = iVar45 + iVar24 + iVar47 + iVar31 + iVar48 + iVar33 + iVar51 + iVar44
                      ;
                      if (uVar10 == uVar16) goto LAB_002438dc;
                    }
                    iVar29 = iVar29 - (int)lVar23;
                    piVar17 = param_1 + (long)(&UNK_0000265f + lVar23);
                    do {
                      iVar29 = iVar29 + -1;
                      iVar31 = piVar17[-0x2a] - piVar17[-0x15];
                      iVar30 = -iVar31;
                      if (-1 < iVar31) {
                        iVar30 = iVar31;
                      }
                      iVar31 = *piVar17 - piVar17[0x15];
                      iVar41 = iVar30 + iVar41;
                      iVar30 = -iVar31;
                      if (-1 < iVar31) {
                        iVar30 = iVar31;
                      }
                      iVar24 = iVar30 + iVar24;
                      piVar17 = piVar17 + 1;
                    } while (iVar29 != 0);
                  }
LAB_002438dc:
                  if ((iVar24 < 10) && (iVar41 < 10)) goto LAB_002438fc;
                  *piVar13 = 0;
                  lVar23 = lVar12;
                  if (3 < iVar32) goto LAB_00243918;
                } while( true );
              }
              (param_1 + (long)iVar4 * 4 + 0x20)[0] = 0;
              (param_1 + (long)iVar4 * 4 + 0x20)[1] = 0;
              (param_1 + (long)iVar4 * 4 + 0x22)[0] = 0;
              (param_1 + (long)iVar4 * 4 + 0x22)[1] = 0;
            }
          }
LAB_00243918:
          uVar9 = _shine_max_reservoir_bits(param_1 + lVar22 * 4 + lVar21 * 2 + 0x226,param_1);
          _memset(param_1 + lVar21 * 0x2c + lVar22 * 0x16 + 0x12e,0,0x58);
          _memset(param_1 + lVar21 * 0x4e + lVar22 * 0x27 + 0x186,0,0x9c);
          (param_1 + lVar21 * 0x2e + lVar11 * 0x17 + 0x3b)[0] = 0;
          (param_1 + lVar21 * 0x2e + lVar11 * 0x17 + 0x3b)[1] = 0;
          (param_1 + lVar21 * 0x2e + lVar11 * 0x17 + 0x3d)[0] = 0;
          (param_1 + lVar21 * 0x2e + lVar11 * 0x17 + 0x3d)[1] = 0;
          *piVar14 = 0;
          (param_1 + lVar21 * 0x2e + lVar22 * 0x17 + 0x29)[0] = 0;
          (param_1 + lVar21 * 0x2e + lVar22 * 0x17 + 0x29)[1] = 0;
          (param_1 + lVar21 * 0x2e + lVar22 * 0x17 + 0x32)[0] = 0;
          (param_1 + lVar21 * 0x2e + lVar22 * 0x17 + 0x32)[1] = 0;
          (param_1 + lVar21 * 0x2e + lVar22 * 0x17 + 0x34)[0] = 0;
          (param_1 + lVar21 * 0x2e + lVar22 * 0x17 + 0x34)[1] = 0;
          (param_1 + lVar21 * 0x2e + lVar22 * 0x17 + 0x2e)[0] = 0;
          (param_1 + lVar21 * 0x2e + lVar22 * 0x17 + 0x2e)[1] = 0;
          (param_1 + lVar21 * 0x2e + lVar22 * 0x17 + 0x30)[0] = 0;
          (param_1 + lVar21 * 0x2e + lVar22 * 0x17 + 0x30)[1] = 0;
          (param_1 + lVar21 * 0x2e + lVar22 * 0x17 + 0x2c)[0] = 0;
          (param_1 + lVar21 * 0x2e + lVar22 * 0x17 + 0x2c)[1] = 0;
          if (*piVar2 != 0) {
            iVar41 = _shine_outer_loop(uVar9);
            *piVar14 = iVar41;
          }
          _shine_ResvAdjust(piVar14,param_1);
          param_1[lVar21 * 0x2e + lVar22 * 0x17 + 0x2b] =
               param_1[lVar21 * 0x2e + lVar22 * 0x17 + 0x3a] + 0xd2;
          uVar10 = (ulong)param_1[4];
          lVar21 = lVar21 + 1;
        } while (lVar21 < (long)uVar10);
      }
      local_3e0 = local_3e0 + 1;
    } while (iVar4 != 0);
  }
  _shine_ResvFrameEnd(param_1);
  return;
LAB_002438fc:
  *piVar13 = 1;
  if (3 < iVar32) goto LAB_00243918;
  goto LAB_0024379c;
}


