/* Decompiled from supplied 5.2.2 arm package. VA 0x2762e0. _ff_tx_init_mdct_fft_int32 */

undefined8
_ff_tx_init_mdct_fft_int32
          (int *param_1,undefined8 *param_2,int param_3,int param_4,int param_5,float *param_6)

{
  uint uVar1;
  uint uVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  long lVar8;
  uint uVar9;
  code *pcVar10;
  code *pcVar11;
  long lVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  double dVar16;
  double dVar17;
  float fVar18;
  double dVar19;
  double dVar20;
  
  iVar5 = _ff_tx_type_is_mdct(param_3);
  uVar9 = param_5 >> (iVar5 != 0);
  if ((int)uVar9 % 0xf == 0) {
    uVar9 = (int)uVar9 / 0xf;
    iVar15 = 0xf;
  }
  else if ((int)uVar9 % 5 == 0) {
    uVar9 = (int)uVar9 / 5;
    iVar15 = 5;
  }
  else if ((int)uVar9 % 3 == 0) {
    uVar9 = (int)uVar9 / 3;
    iVar15 = 3;
  }
  else {
    iVar15 = 1;
  }
  param_1[2] = param_4;
  param_1[3] = param_3;
  uVar1 = uVar9;
  uVar2 = 1;
  if (0x1fffe < uVar9 - 2 || (uVar9 - 1 & uVar9) != 0) {
    uVar1 = 1;
    uVar2 = uVar9;
  }
  *param_1 = iVar15;
  param_1[1] = uVar1;
  if (1 < (int)uVar2 || uVar1 == 1) {
    _av_log(0,0x10,"Unsupported transform size: n = %i, m = %i, residual = %i!\n");
    return 0xffffffea;
  }
  if (iVar15 == 1 || (int)uVar1 < 2) {
    *param_2 = FUN_00279218;
    if (iVar5 != 0) {
      pcVar10 = FUN_002793f8;
      pcVar11 = FUN_00279264;
LAB_0027651c:
      if (param_4 == 0) {
        pcVar11 = pcVar10;
      }
LAB_00276524:
      *param_2 = pcVar11;
    }
LAB_00276528:
    if (iVar15 != 1) {
      FUN_00279628(0);
    }
    _ff_tx_gen_ptwo_revtab(param_1);
    for (iVar14 = 4; iVar14 <= 0x1f - (int)LZCOUNT(uVar1 | 1); iVar14 = iVar14 + 1) {
      FUN_00279628(iVar14);
    }
    if (iVar5 != 0) {
      iVar15 = uVar1 * iVar15;
      fVar18 = *param_6;
      dVar17 = (double)iVar15 + 0.125;
      dVar19 = dVar17;
      if (0.0 <= fVar18) {
        dVar19 = 0.125;
      }
      lVar8 = _av_malloc_array((long)iVar15,8);
      *(long *)(param_1 + 4) = lVar8;
      dVar4 = DAT_00c51f00;
      dVar3 = DAT_00c51e38;
      if (lVar8 == 0) goto LAB_0027665c;
      dVar20 = SQRT((double)ABS(fVar18));
      puVar13 = (undefined4 *)(lVar8 + 4);
      for (lVar12 = 0; lVar12 < iVar15; lVar12 = lVar12 + 1) {
        dVar16 = (double)___sincos_stret(((dVar19 + (double)(int)lVar12) * dVar3) / (double)iVar15);
        uVar6 = _lrintf((float)(dVar20 * dVar17 * dVar4));
        puVar13[-1] = uVar6;
        uVar6 = _lrintf((float)(dVar20 * dVar16 * dVar4));
        *puVar13 = uVar6;
        puVar13 = puVar13 + 2;
      }
    }
    uVar7 = 0;
  }
  else {
    uVar7 = _ff_tx_gen_compound_mapping(param_1);
    if ((int)uVar7 != 0) {
      return uVar7;
    }
    lVar8 = _av_malloc(-(ulong)(uVar1 * iVar15 >> 0x1f) & 0xfffffff800000000 |
                       (ulong)(uVar1 * iVar15) << 3);
    *(long *)(param_1 + 6) = lVar8;
    if (lVar8 != 0) {
      pcVar10 = FUN_00276888;
      if (iVar15 != 5) {
        pcVar10 = FUN_00276b40;
      }
      pcVar11 = FUN_00276688;
      if (iVar15 != 3) {
        pcVar11 = pcVar10;
      }
      *param_2 = pcVar11;
      if (iVar5 != 0) {
        if (iVar15 == 3) {
          pcVar10 = FUN_0027753c;
          pcVar11 = FUN_0027722c;
          goto LAB_0027651c;
        }
        pcVar10 = FUN_00278138;
        pcVar11 = FUN_002778d8;
        if (param_4 == 0) {
          pcVar10 = FUN_0027894c;
          pcVar11 = FUN_00277ca4;
        }
        if (iVar15 != 5) {
          pcVar11 = pcVar10;
        }
        goto LAB_00276524;
      }
      goto LAB_00276528;
    }
LAB_0027665c:
    uVar7 = 0xfffffff4;
  }
  return uVar7;
}


