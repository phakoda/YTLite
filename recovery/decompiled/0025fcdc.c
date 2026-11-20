/* Decompiled from supplied 5.2.2 arm package. VA 0x25fcdc. _avpriv_solve_lls */

void _avpriv_solve_lls(double param_1,double *param_2,long param_3)

{
  double *pdVar1;
  int iVar2;
  double *pdVar3;
  long lVar4;
  double *pdVar5;
  double *pdVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  double *pdVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  double dVar15;
  double dVar16;
  
  pdVar1 = param_2 + 0x24;
  iVar7 = *(int *)(param_2 + 0x930);
  uVar8 = (ulong)iVar7;
  pdVar10 = pdVar1;
  for (uVar9 = 0; (long)uVar9 < (long)uVar8; uVar9 = uVar9 + 1) {
    pdVar6 = pdVar10;
    for (uVar13 = uVar9; (int)uVar13 != iVar7; uVar13 = uVar13 + 1) {
      dVar15 = param_2[uVar9 * 0x24 + uVar13 + 0x25];
      pdVar3 = pdVar10;
      pdVar5 = pdVar6;
      for (iVar2 = 0; (int)uVar9 != iVar2; iVar2 = iVar2 + 1) {
        dVar15 = dVar15 - *pdVar3 * *pdVar5;
        pdVar3 = pdVar3 + 1;
        pdVar5 = pdVar5 + 1;
      }
      if ((uVar9 & 0xffffffff) == uVar13) {
        dVar16 = 1.0;
        if (param_1 <= dVar15) {
          dVar16 = dVar15;
        }
        pdVar1[uVar9 * 0x25] = SQRT(dVar16);
      }
      else {
        pdVar1[uVar13 * 0x24 + uVar9] = dVar15 / pdVar1[uVar9 * 0x25];
      }
      pdVar6 = pdVar6 + 0x24;
    }
    pdVar10 = pdVar10 + 0x24;
  }
  lVar11 = 0;
  pdVar10 = param_2;
  while (pdVar10 = pdVar10 + 0x24, lVar11 < (long)uVar8) {
    dVar15 = param_2[lVar11 + 1];
    pdVar6 = pdVar10;
    for (lVar12 = 0; (int)lVar11 != (int)lVar12; lVar12 = lVar12 + 1) {
      dVar15 = dVar15 - *pdVar6 * param_2[lVar12 + 0x510];
      pdVar6 = pdVar6 + 1;
    }
    param_2[lVar11 + 0x510] = dVar15 / pdVar1[lVar11 * 0x25];
    lVar11 = lVar11 + 1;
  }
  lVar11 = (long)(iVar7 + -1);
  pdVar10 = param_2 + (long)(iVar7 + -1) + 0x24;
  while (param_3 < (long)uVar8) {
    uVar9 = uVar8 & 0xffffffff;
    lVar4 = (long)(int)(uVar8 - 1);
    pdVar6 = pdVar10;
    for (lVar12 = lVar11; -1 < lVar12; lVar12 = lVar12 + -1) {
      dVar15 = param_2[lVar12 + 0x510];
      iVar7 = (int)uVar9;
      pdVar3 = pdVar6 + (long)iVar7 * 0x24;
      pdVar5 = param_2 + (long)(int)lVar11 * 0x20 + (long)iVar7 + 0x510;
      for (lVar14 = lVar12; lVar14 < lVar4; lVar14 = lVar14 + 1) {
        dVar15 = dVar15 - *pdVar3 * *pdVar5;
        pdVar3 = pdVar3 + 0x24;
        pdVar5 = pdVar5 + 1;
      }
      uVar9 = (ulong)(iVar7 - 1);
      param_2[lVar4 * 0x20 + lVar12 + 0x510] = dVar15 / pdVar1[lVar12 * 0x25];
      pdVar6 = pdVar6 + -1;
    }
    dVar15 = *param_2;
    param_2[lVar4 + 0x910] = dVar15;
    lVar12 = 0;
    pdVar6 = param_2 + 0x25;
    while ((int)lVar12 != (int)uVar8) {
      dVar16 = param_2[lVar4 * 0x20 + lVar12 + 0x510] * param_2[lVar12 * 0x25 + 0x25] +
               param_2[lVar12 + 1] * -2.0;
      pdVar3 = pdVar6;
      for (lVar14 = 0; (int)lVar12 != (int)lVar14; lVar14 = lVar14 + 1) {
        dVar16 = dVar16 + (param_2[(long)(int)lVar11 * 0x20 + lVar14 + 0x510] +
                          param_2[(long)(int)lVar11 * 0x20 + lVar14 + 0x510]) * *pdVar3;
        pdVar3 = pdVar3 + 0x24;
      }
      dVar15 = dVar15 + dVar16 * param_2[lVar4 * 0x20 + lVar12 + 0x510];
      param_2[lVar4 + 0x910] = dVar15;
      pdVar6 = pdVar6 + 1;
      lVar12 = lVar12 + 1;
    }
    lVar11 = lVar11 + -1;
    pdVar10 = pdVar10 + -1;
    uVar8 = uVar8 - 1;
  }
  return;
}


