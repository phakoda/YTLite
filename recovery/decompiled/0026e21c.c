/* Decompiled from supplied 5.2.2 arm package. VA 0x26e21c. _ff_tx_init_mdct_fft_double */

undefined8
_ff_tx_init_mdct_fft_double
          (int *param_1,undefined8 *param_2,int param_3,int param_4,int param_5,double *param_6)

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
  double *pdVar11;
  int iVar12;
  int iVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  
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
    *param_2 = FUN_00270a38;
    if (iVar4 != 0) {
      pcVar8 = FUN_00270bfc;
      pcVar9 = FUN_00270a84;
LAB_0026e454:
      if (param_4 == 0) {
        pcVar9 = pcVar8;
      }
LAB_0026e45c:
      *param_2 = pcVar9;
    }
LAB_0026e460:
    if (iVar13 != 1) {
      FUN_00270df0(0);
    }
    _ff_tx_gen_ptwo_revtab(param_1);
    for (iVar12 = 4; iVar12 <= 0x1f - (int)LZCOUNT(uVar1 | 1); iVar12 = iVar12 + 1) {
      FUN_00270df0(iVar12);
    }
    if (iVar4 != 0) {
      iVar13 = uVar1 * iVar13;
      dVar17 = *param_6;
      dVar15 = (double)iVar13 + 0.125;
      dVar16 = dVar15;
      if (0.0 <= dVar17) {
        dVar16 = 0.125;
      }
      lVar6 = _av_malloc_array((long)iVar13,0x10);
      *(long *)(param_1 + 4) = lVar6;
      dVar3 = DAT_00c51e38;
      if (lVar6 == 0) goto LAB_0026e56c;
      dVar17 = SQRT(ABS(dVar17));
      pdVar11 = (double *)(lVar6 + 8);
      for (lVar10 = 0; lVar10 < iVar13; lVar10 = lVar10 + 1) {
        dVar14 = (double)___sincos_stret(((dVar16 + (double)(int)lVar10) * dVar3) / (double)iVar13);
        dVar15 = dVar17 * dVar15;
        pdVar11[-1] = dVar15;
        *pdVar11 = dVar17 * dVar14;
        pdVar11 = pdVar11 + 2;
      }
    }
    uVar5 = 0;
  }
  else {
    uVar5 = _ff_tx_gen_compound_mapping(param_1);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
    lVar6 = _av_malloc(-(ulong)(uVar1 * iVar13 >> 0x1f) & 0xfffffff000000000 |
                       (ulong)(uVar1 * iVar13) << 4);
    *(long *)(param_1 + 6) = lVar6;
    if (lVar6 != 0) {
      pcVar8 = FUN_0026e750;
      if (iVar13 != 5) {
        pcVar8 = FUN_0026e9c0;
      }
      pcVar9 = FUN_0026e594;
      if (iVar13 != 3) {
        pcVar9 = pcVar8;
      }
      *param_2 = pcVar9;
      if (iVar4 != 0) {
        if (iVar13 == 3) {
          pcVar8 = FUN_0026f204;
          pcVar9 = FUN_0026ef48;
          goto LAB_0026e454;
        }
        pcVar8 = FUN_0026fc7c;
        pcVar9 = FUN_0026f52c;
        if (param_4 == 0) {
          pcVar8 = FUN_00270308;
          pcVar9 = FUN_0026f89c;
        }
        if (iVar13 != 5) {
          pcVar9 = pcVar8;
        }
        goto LAB_0026e45c;
      }
      goto LAB_0026e460;
    }
LAB_0026e56c:
    uVar5 = 0xfffffff4;
  }
  return uVar5;
}


