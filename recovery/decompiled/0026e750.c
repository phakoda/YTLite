/* Decompiled from supplied 5.2.2 arm package. VA 0x26e750. FUN_0026e750 */

void FUN_0026e750(long param_1,undefined8 *param_2,long param_3)

{
  double *pdVar1;
  uint uVar2;
  undefined8 *puVar3;
  long lVar4;
  int *piVar5;
  long lVar6;
  int *piVar7;
  long lVar8;
  long lVar9;
  int *piVar10;
  code *pcVar11;
  undefined8 uVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double local_b8 [10];
  long local_68;
  
  lVar8 = *(long *)PTR____stack_chk_guard_01060708;
  uVar2 = *(uint *)(param_1 + 4);
  lVar9 = (long)(int)uVar2;
  piVar10 = *(int **)(param_1 + 0x20);
  pcVar11 = *(code **)(&DAT_0106d398 + (long)(0x1f - (int)LZCOUNT(uVar2 | 1)) * 8);
  piVar5 = piVar10;
  local_68 = lVar8;
  for (lVar4 = 0; lVar4 < lVar9; lVar4 = lVar4 + 1) {
    piVar7 = piVar5;
    for (lVar6 = 0; lVar6 != 0x50; lVar6 = lVar6 + 0x10) {
      puVar3 = (undefined8 *)(param_3 + (long)*piVar7 * 0x10);
      uVar12 = *puVar3;
      *(undefined8 *)((long)local_b8 + lVar6 + 8) = puVar3[1];
      *(undefined8 *)((long)local_b8 + lVar6) = uVar12;
      piVar7 = piVar7 + 1;
    }
    dVar13 = local_b8[2] + local_b8[8];
    dVar14 = local_b8[3] + local_b8[9];
    dVar15 = local_b8[4] + local_b8[6];
    pdVar1 = (double *)
             (*(long *)(param_1 + 0x18) +
             (long)*(int *)(*(long *)(param_1 + 0x28) + lVar4 * 4) * 0x10);
    *pdVar1 = dVar15 + dVar13 + local_b8[0];
    dVar16 = local_b8[5] + local_b8[7];
    pdVar1[1] = dVar16 + dVar14 + local_b8[1];
    dVar20 = dVar15 * DAT_019d3720;
    dVar21 = dVar13 * DAT_019d3730;
    dVar22 = dVar16 * DAT_019d3720;
    dVar23 = dVar14 * DAT_019d3730;
    dVar17 = (local_b8[5] - local_b8[7]) * DAT_019d3728;
    dVar19 = (local_b8[3] - local_b8[9]) * DAT_019d3738;
    dVar24 = (local_b8[4] - local_b8[6]) * DAT_019d3728;
    dVar18 = (local_b8[2] - local_b8[8]) * DAT_019d3738;
    dVar13 = dVar13 * DAT_019d3720 - dVar15 * DAT_019d3730;
    dVar14 = dVar14 * DAT_019d3720 - dVar16 * DAT_019d3730;
    dVar15 = (local_b8[3] - local_b8[9]) * DAT_019d3728 + (local_b8[5] - local_b8[7]) * DAT_019d3738
    ;
    dVar16 = (local_b8[2] - local_b8[8]) * DAT_019d3728 + (local_b8[4] - local_b8[6]) * DAT_019d3738
    ;
    pdVar1[lVar9 * 2] = local_b8[0] + dVar13 + dVar15;
    (pdVar1 + lVar9 * 2)[1] = local_b8[1] + (dVar14 - dVar16);
    dVar20 = dVar20 - dVar21;
    dVar22 = dVar22 - dVar23;
    dVar17 = dVar17 - dVar19;
    dVar24 = dVar24 - dVar18;
    pdVar1[lVar9 * 4] = (dVar20 - dVar17) + local_b8[0];
    (pdVar1 + lVar9 * 4)[1] = dVar22 + dVar24 + local_b8[1];
    pdVar1[lVar9 * 6] = dVar20 + dVar17 + local_b8[0];
    (pdVar1 + lVar9 * 6)[1] = (dVar22 - dVar24) + local_b8[1];
    pdVar1[lVar9 * 8] = (dVar13 - dVar15) + local_b8[0];
    (pdVar1 + lVar9 * 8)[1] = dVar14 + dVar16 + local_b8[1];
    piVar5 = piVar5 + 5;
  }
  lVar6 = 6;
  lVar4 = 0;
  while (lVar6 = lVar6 + -1, lVar6 != 0) {
    (*pcVar11)(*(long *)(param_1 + 0x18) + lVar4);
    lVar4 = lVar4 + lVar9 * 0x10;
  }
  for (lVar4 = 0; lVar4 < lVar9 * 5; lVar4 = lVar4 + 1) {
    puVar3 = (undefined8 *)
             (*(long *)(param_1 + 0x18) + (long)piVar10[(int)(uVar2 * 5) + lVar4] * 0x10);
    uVar12 = *puVar3;
    param_2[1] = puVar3[1];
    *param_2 = uVar12;
    param_2 = param_2 + 2;
  }
  if (lVar8 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


