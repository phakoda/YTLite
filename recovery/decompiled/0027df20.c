/* Decompiled from supplied 5.2.2 arm package. VA 0x27df20. FUN_0027df20 */

undefined8 FUN_0027df20(long param_1,long *param_2,int param_3)

{
  int iVar1;
  long *plVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  double *pdVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  long lVar13;
  void *pvVar14;
  void *pvVar15;
  ulong uVar16;
  ulong uVar17;
  double *pdVar18;
  long lVar19;
  int *piVar20;
  double *pdVar21;
  int iVar22;
  long lVar23;
  long lVar24;
  long lVar25;
  ulong uVar26;
  long lVar27;
  int iVar28;
  long lVar29;
  int *piVar30;
  long lVar31;
  long lVar32;
  double *pdVar33;
  undefined8 *puVar34;
  void *pvVar35;
  long lVar36;
  int *piVar37;
  long lVar38;
  void *pvVar39;
  double *pdVar40;
  long *plVar41;
  long lVar42;
  double dVar43;
  double dVar44;
  
  lVar23 = *(long *)(param_1 + 0x48);
  lVar29 = (long)param_3;
  lVar24 = *(long *)(lVar23 + 0xb8);
  lVar25 = *(long *)(lVar23 + 0x78);
  uVar7 = *(uint *)(lVar23 + 0x3c);
  iVar11 = *(int *)(lVar23 + 0x44);
  lVar36 = *(long *)(*(long *)(*param_2 + 0x60) + (long)param_3 * 8);
  lVar12 = lVar25 + lVar29 * 0x80;
  pvVar39 = *(void **)(*(long *)(*(long *)(lVar23 + 0x58) + 0x60) + (long)param_3 * 8);
  pvVar14 = *(void **)(*(long *)(*(long *)(lVar23 + 0x70) + 0x60) + (long)param_3 * 8);
  pvVar15 = *(void **)(*(long *)(*(long *)(lVar23 + 0x60) + 0x60) + (long)param_3 * 8);
  pvVar35 = *(void **)(*(long *)(*(long *)(lVar23 + 0x68) + 0x60) + (long)param_3 * 8);
  plVar41 = (long *)(lVar12 + 0x10);
  pdVar33 = (double *)*plVar41;
  pdVar18 = *(double **)(lVar12 + 0x18);
  pdVar21 = *(double **)(lVar12 + 0x20);
  _bzero(pdVar21,-(ulong)(uVar7 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar7 << 3);
  FUN_0027e70c(1.0 / (double)iVar11,pvVar39,uVar7,iVar11,pdVar18);
  lVar12 = 0;
  pdVar40 = pdVar18 + 1;
  dVar43 = -*pdVar40 / *pdVar18;
  *pdVar21 = dVar43;
  *pdVar33 = dVar43;
  dVar43 = *pdVar18 * (1.0 - dVar43 * dVar43);
  lVar13 = 1;
  while (lVar13 < (int)uVar7) {
    dVar44 = 0.0;
    pdVar9 = pdVar40;
    for (lVar19 = 0; (int)lVar13 != (int)lVar19; lVar19 = lVar19 + 1) {
      dVar44 = dVar44 + pdVar21[lVar19] * *pdVar9;
      pdVar9 = pdVar9 + -1;
    }
    dVar44 = -(dVar44 + pdVar18[lVar13 + 1]) / dVar43;
    pdVar33[lVar13] = dVar44;
    pdVar9 = pdVar21;
    for (lVar19 = lVar12; 0 < lVar19 + 1; lVar19 = lVar19 + -1) {
      pdVar33[lVar19] = pdVar21[lVar19] + pdVar33[lVar13] * *pdVar9;
      pdVar9 = pdVar9 + 1;
    }
    for (lVar19 = 0; (int)lVar12 + 2 != (int)lVar19; lVar19 = lVar19 + 1) {
      pdVar21[lVar19] = pdVar33[lVar19];
    }
    pdVar40 = pdVar40 + 1;
    dVar43 = dVar43 * (1.0 - dVar44 * dVar44);
    lVar12 = lVar12 + 1;
    lVar13 = lVar13 + 1;
  }
  plVar2 = (long *)(lVar25 + lVar29 * 0x80);
  *pdVar33 = 1.0;
  lVar12 = 0;
  while (lVar12 + 1 <= (long)(int)uVar7) {
    pdVar33[lVar12 + 1] = pdVar21[lVar12];
    lVar12 = lVar12 + 1;
  }
  lVar12 = 0;
  do {
    if ((long)*(int *)(lVar23 + 0x3c) + 1 <= lVar12) {
      lVar12 = lVar25 + lVar29 * 0x80;
      puVar34 = *(undefined8 **)(lVar12 + 0x28);
      piVar37 = *(int **)(lVar12 + 0x68);
      uVar7 = (**(code **)(lVar23 + 0xc0))
                        (SQRT(dVar43),lVar23,plVar2,*(undefined8 *)(lVar12 + 8),*plVar41,
                         *(undefined8 *)(lVar12 + 0x60),piVar37,pvVar39,pvVar15);
      uVar16 = (ulong)uVar7;
      iVar11 = uVar7 - 1;
      if (0 < (int)uVar7) {
        iVar28 = *(int *)(lVar23 + 0x3c);
        lVar19 = *plVar41;
        lVar42 = *plVar2;
        lVar13 = **(long **)(*(long *)(lVar23 + 0x50) + 0x60);
        _av_fast_malloc(lVar12 + 0x30,lVar12 + 0x38,(ulong)(uVar7 * uVar7) << 3);
        pdVar40 = *(double **)(lVar12 + 0x30);
        if (pdVar40 != (double *)0x0) {
          lVar12 = lVar25 + lVar29 * 0x80;
          _av_fast_malloc(lVar12 + 0x40,lVar12 + 0x48);
          lVar12 = *(long *)(lVar12 + 0x40);
          if (lVar12 != 0) {
            lVar38 = (long)(int)uVar7;
            FUN_0027e70c(0x3ff0000000000000,lVar19,iVar28,iVar28 + 1,lVar42);
            uVar17 = -(ulong)(uVar7 >> 0x1f) & 0xfffffff800000000 | uVar16 << 3;
            uVar26 = uVar16;
            piVar20 = piVar37;
            pdVar18 = pdVar40;
            for (lVar19 = 0; lVar19 != lVar38; lVar19 = lVar19 + 1) {
              iVar10 = (int)uVar26;
              piVar30 = piVar20;
              pdVar21 = pdVar18;
              pdVar33 = pdVar18;
              for (; (int)uVar26 != 0; uVar26 = (ulong)((int)uVar26 - 1)) {
                iVar22 = *piVar30 - piVar37[lVar19];
                iVar5 = -iVar22;
                if (-1 < iVar22) {
                  iVar5 = iVar22;
                }
                if (iVar28 < iVar5) {
                  *pdVar21 = 0.0;
                  *pdVar33 = 0.0;
                }
                else {
                  dVar43 = *(double *)(lVar42 + (long)iVar5 * 8);
                  *pdVar21 = dVar43;
                  *pdVar33 = dVar43;
                }
                pdVar33 = (double *)((long)pdVar33 + uVar17);
                pdVar21 = pdVar21 + 1;
                piVar30 = piVar30 + 1;
              }
              pdVar18 = (double *)((long)pdVar18 + uVar17 + 8);
              piVar20 = piVar20 + 1;
              uVar26 = (ulong)(iVar10 - 1);
            }
            for (lVar19 = 0; lVar19 != lVar38; lVar19 = lVar19 + 1) {
              dVar43 = 0.0;
              for (iVar10 = -iVar28; iVar10 <= iVar28; iVar10 = iVar10 + 1) {
                iVar5 = piVar37[lVar19] - iVar10;
                if ((*piVar37 <= iVar5) && (iVar5 <= piVar37[iVar11])) {
                  iVar22 = 0;
                  iVar6 = iVar11;
                  while (iVar22 <= iVar6) {
                    iVar1 = iVar6 + iVar22;
                    if (iVar1 < 0) {
                      iVar1 = iVar1 + 1;
                    }
                    iVar1 = iVar1 >> 1;
                    iVar4 = piVar37[iVar1];
                    if (iVar4 == iVar5) goto LAB_0027e300;
                    iVar3 = iVar1 + -1;
                    if (iVar4 <= iVar5) {
                      iVar3 = iVar6;
                    }
                    iVar6 = iVar3;
                    if (iVar4 < iVar5) {
                      iVar22 = iVar1 + 1;
                    }
                  }
                }
                iVar22 = -iVar10;
                if (-1 < iVar10) {
                  iVar22 = iVar10;
                }
                dVar43 = dVar43 - *(double *)((long)pvVar39 + (long)iVar5 * 8) *
                                  *(double *)(lVar42 + (long)iVar22 * 8);
LAB_0027e300:
              }
              *(double *)(lVar12 + lVar19 * 8) = dVar43;
            }
            uVar26 = -(ulong)(uVar7 >> 0x1f) & 0xfffffff800000000 | uVar16 << 3;
            pdVar18 = pdVar40 + (int)uVar7;
            pdVar21 = pdVar40;
            for (lVar19 = 0; lVar19 < lVar38; lVar19 = lVar19 + 1) {
              lVar27 = 0;
              iVar10 = (int)lVar19;
              lVar42 = lVar19 * lVar38 + (long)iVar10;
              dVar43 = pdVar40[lVar42];
              pdVar33 = pdVar21;
              for (iVar28 = 0; iVar10 != iVar28; iVar28 = iVar28 + 1) {
                dVar43 = dVar43 - *pdVar33 * pdVar40[lVar27 + iVar28] * *pdVar33;
                lVar27 = lVar27 + (int)uVar7;
                pdVar33 = pdVar33 + 1;
              }
              if (dVar43 == 0.0) {
                return 0xffffffff;
              }
              pdVar40[lVar42] = dVar43;
              pdVar33 = pdVar18;
              lVar27 = lVar19;
              while ((int)lVar27 != iVar11) {
                lVar32 = 0;
                lVar27 = lVar27 + 1;
                lVar31 = lVar19 + lVar27 * lVar38;
                dVar43 = pdVar40[lVar31];
                pdVar9 = pdVar33;
                for (lVar8 = 0; iVar10 != (int)lVar8; lVar8 = lVar8 + 1) {
                  dVar43 = dVar43 - pdVar40[lVar32 + (int)lVar8] * pdVar21[lVar8] * *pdVar9;
                  lVar32 = lVar32 + (int)uVar7;
                  pdVar9 = pdVar9 + 1;
                }
                pdVar40[lVar31] = dVar43 / pdVar40[lVar42];
                pdVar33 = (double *)((long)pdVar33 + uVar26);
              }
              pdVar21 = (double *)((long)pdVar21 + uVar26);
              pdVar18 = (double *)((long)pdVar18 + uVar26);
            }
            lVar25 = lVar25 + lVar29 * 0x80;
            _av_fast_malloc(lVar25 + 0x50,lVar25 + 0x58,
                            -(ulong)(uVar7 >> 0x1f) & 0xfffffff800000000 | uVar16 << 3);
            lVar25 = *(long *)(lVar25 + 0x50);
            if (lVar25 != 0) {
              pdVar18 = pdVar40;
              for (lVar29 = 0; lVar29 != lVar38; lVar29 = lVar29 + 1) {
                dVar43 = *(double *)(lVar12 + lVar29 * 8);
                pdVar21 = pdVar18;
                for (lVar19 = 0; (int)lVar29 != (int)lVar19; lVar19 = lVar19 + 1) {
                  dVar43 = dVar43 - *pdVar21 * *(double *)(lVar25 + lVar19 * 8);
                  pdVar21 = pdVar21 + 1;
                }
                *(double *)(lVar25 + lVar29 * 8) = dVar43;
                pdVar18 = (double *)
                          ((long)pdVar18 +
                          (-(ulong)(uVar7 >> 0x1f) & 0xfffffff800000000 | uVar16 << 3));
              }
              pdVar18 = pdVar40 + ((long)(int)uVar7 + 1) * (long)(int)uVar7 + -1;
              lVar12 = lVar38;
              while (lVar29 = lVar12 + -1, 0 < lVar12) {
                dVar43 = *(double *)(lVar25 + lVar29 * 8) /
                         pdVar40[(int)((int)lVar29 + (int)lVar29 * uVar7)];
                puVar34[lVar29] = dVar43;
                pdVar21 = pdVar18;
                for (; lVar12 < lVar38; lVar12 = lVar12 + 1) {
                  dVar43 = dVar43 - *pdVar21 * (double)puVar34[lVar12];
                  puVar34[lVar29] = dVar43;
                  pdVar21 = (double *)
                            ((long)pdVar21 +
                            (-(ulong)(uVar7 >> 0x1f) & 0xfffffff800000000 | uVar16 << 3));
                }
                pdVar18 = pdVar18 + (-1 - (long)(int)uVar7);
                lVar12 = lVar29;
              }
              _av_audio_fifo_peek(*(undefined8 *)(lVar23 + 0xa8),
                                  *(undefined8 *)(*(long *)(lVar23 + 0x50) + 0x60),
                                  *(undefined4 *)(lVar23 + 0x44));
              for (; (int)uVar16 != 0; uVar16 = (ulong)((int)uVar16 - 1)) {
                lVar12 = (long)*piVar37;
                if (*(double *)(lVar13 + lVar12 * 8) != 0.0) {
                  *(undefined8 *)((long)pvVar15 + lVar12 * 8) = *puVar34;
                  *(undefined8 *)((long)pvVar14 + lVar12 * 8) = 0x3ff0000000000000;
                }
                puVar34 = puVar34 + 1;
                piVar37 = piVar37 + 1;
              }
              goto LAB_0027e5e8;
            }
          }
        }
        return 0xfffffff4;
      }
      goto LAB_0027e5e8;
    }
    dVar44 = *(double *)(*plVar41 + lVar12 * 8);
  } while ((!NAN(dVar44)) && (lVar12 = lVar12 + 1, ABS(dVar44) != DAT_00c508f8));
  _memcpy(pvVar15,pvVar39,(long)*(int *)(lVar23 + 0x44) << 3);
LAB_0027e5e8:
  if (*(int *)(lVar23 + 0x30) == 0) {
    iVar11 = *(int *)(lVar23 + 0x44);
    for (lVar12 = 0; lVar12 < iVar11; lVar12 = lVar12 + 1) {
      *(double *)((long)pvVar35 + lVar12 * 8) =
           *(double *)((long)pvVar35 + lVar12 * 8) +
           *(double *)((long)pvVar15 + lVar12 * 8) * *(double *)(lVar24 + lVar12 * 8);
    }
    iVar11 = *(int *)(lVar23 + 0x48);
  }
  else {
    iVar11 = *(int *)(lVar23 + 0x48);
    iVar28 = *(int *)(lVar23 + 0x4c);
    for (lVar12 = 0; lVar12 < iVar11; lVar12 = lVar12 + 1) {
      *(undefined8 *)((long)pvVar35 + lVar12 * 8) =
           *(undefined8 *)((long)pvVar15 + lVar12 * 8 + (long)iVar28 * 8);
    }
  }
  for (lVar12 = 0; lVar12 < iVar11; lVar12 = lVar12 + 1) {
    *(undefined8 *)(lVar36 + lVar12 * 8) = *(undefined8 *)((long)pvVar35 + lVar12 * 8);
  }
  uVar7 = *(int *)(lVar23 + 0x44) * 2 - iVar11;
  _memmove(pvVar35,(void *)((long)pvVar35 + (long)iVar11 * 8),
           -(ulong)(uVar7 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar7 << 3);
  uVar7 = *(int *)(lVar23 + 0x44) - *(int *)(lVar23 + 0x48);
  _memmove(pvVar14,(void *)((long)pvVar14 + (long)*(int *)(lVar23 + 0x48) * 8),
           -(ulong)(uVar7 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar7 << 3);
  _bzero((void *)((long)pvVar35 +
                 (long)*(int *)(lVar23 + 0x48) * -8 + (long)*(int *)(lVar23 + 0x44) * 0x10),
         (long)*(int *)(lVar23 + 0x48) << 3);
  _bzero((void *)((long)pvVar14 +
                 (long)*(int *)(lVar23 + 0x48) * -8 + (long)*(int *)(lVar23 + 0x44) * 8),
         (long)*(int *)(lVar23 + 0x48) << 3);
  return 0;
}


