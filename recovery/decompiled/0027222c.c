/* Decompiled from supplied 5.2.2 arm package. VA 0x27222c. _ff_tx_init_mdct_fft_float */

undefined8
_ff_tx_init_mdct_fft_float
          (int *param_1,undefined8 *param_2,int param_3,int param_4,int param_5,float *param_6)

{
  uint uVar1;
  uint uVar2;
  double dVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  uint uVar7;
  code *pcVar8;
  code *pcVar9;
  long lVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  float fVar17;
  double dVar18;
  
  iVar4 = _ff_tx_type_is_mdct(param_3);
  uVar7 = param_5 >> (iVar4 != 0);
  if ((int)uVar7 % 0xf == 0) {
    uVar7 = (int)uVar7 / 0xf;
    iVar13 = 0xf;
  }
  else if ((int)uVar7 % 5 == 0) {
    uVar7 = (int)uVar7 / 5;
    iVar13 = 5;
  }
  else if ((int)uVar7 % 3 == 0) {
    uVar7 = (int)uVar7 / 3;
    iVar13 = 3;
  }
  else {
    iVar13 = 1;
  }
  param_1[2] = param_4;
  param_1[3] = param_3;
  uVar1 = uVar7;
  uVar2 = 1;
  if (0x1fffe < uVar7 - 2 || (uVar7 - 1 & uVar7) != 0) {
    uVar1 = 1;
    uVar2 = uVar7;
  }
  *param_1 = iVar13;
  param_1[1] = uVar1;
  if (1 < (int)uVar2 || uVar1 == 1) {
    _av_log(0,0x10,"Unsupported transform size: n = %i, m = %i, residual = %i!\n");
    return 0xffffffea;
  }
  if (iVar13 == 1 || (int)uVar1 < 2) {
    *param_2 = FUN_00274a68;
    if (iVar4 != 0) {
      pcVar8 = FUN_00274c2c;
      pcVar9 = FUN_00274ab4;
LAB_00272464:
      if (param_4 == 0) {
        pcVar9 = pcVar8;
      }
LAB_0027246c:
      *param_2 = pcVar9;
    }
LAB_00272470:
    if (iVar13 != 1) {
      FUN_00274e20(0);
    }
    _ff_tx_gen_ptwo_revtab(param_1);
    for (iVar12 = 4; iVar12 <= 0x1f - (int)LZCOUNT(uVar1 | 1); iVar12 = iVar12 + 1) {
      FUN_00274e20(iVar12);
    }
    if (iVar4 != 0) {
      iVar13 = uVar1 * iVar13;
      fVar17 = *param_6;
      dVar15 = (double)iVar13 + 0.125;
      dVar16 = dVar15;
      if (0.0 <= fVar17) {
        dVar16 = 0.125;
      }
      lVar6 = _av_malloc_array((long)iVar13,8);
      *(long *)(param_1 + 4) = lVar6;
      dVar3 = DAT_00c51e38;
      if (lVar6 == 0) goto LAB_00272588;
      dVar18 = SQRT((double)ABS(fVar17));
      pfVar11 = (float *)(lVar6 + 4);
      for (lVar10 = 0; lVar10 < iVar13; lVar10 = lVar10 + 1) {
        dVar14 = (double)___sincos_stret(((dVar16 + (double)(int)lVar10) * dVar3) / (double)iVar13);
        fVar17 = (float)(dVar18 * dVar15);
        dVar15 = (double)(ulong)(uint)fVar17;
        pfVar11[-1] = fVar17;
        *pfVar11 = (float)(dVar18 * dVar14);
        pfVar11 = pfVar11 + 2;
      }
    }
    uVar5 = 0;
  }
  else {
    uVar5 = _ff_tx_gen_compound_mapping(param_1);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
    lVar6 = _av_malloc(-(ulong)(uVar1 * iVar13 >> 0x1f) & 0xfffffff800000000 |
                       (ulong)(uVar1 * iVar13) << 3);
    *(long *)(param_1 + 6) = lVar6;
    if (lVar6 != 0) {
      pcVar8 = FUN_0027276c;
      if (iVar13 != 5) {
        pcVar8 = FUN_002729dc;
      }
      pcVar9 = FUN_002725b0;
      if (iVar13 != 3) {
        pcVar9 = pcVar8;
      }
      *param_2 = pcVar9;
      if (iVar4 != 0) {
        if (iVar13 == 3) {
          pcVar8 = FUN_00273224;
          pcVar9 = FUN_00272f68;
          goto LAB_00272464;
        }
        pcVar8 = FUN_00273c9c;
        pcVar9 = FUN_0027354c;
        if (param_4 == 0) {
          pcVar8 = FUN_0027432c;
          pcVar9 = FUN_002738bc;
        }
        if (iVar13 != 5) {
          pcVar9 = pcVar8;
        }
        goto LAB_0027246c;
      }
      goto LAB_00272470;
    }
LAB_00272588:
    uVar5 = 0xfffffff4;
  }
  return uVar5;
}


