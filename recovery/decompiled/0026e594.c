/* Decompiled from supplied 5.2.2 arm package. VA 0x26e594. FUN_0026e594 */

void FUN_0026e594(long param_1,undefined8 *param_2,long param_3)

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
  double dVar12;
  undefined8 uVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double local_98 [6];
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
    for (lVar6 = 0; lVar6 != 0x30; lVar6 = lVar6 + 0x10) {
      puVar3 = (undefined8 *)(param_3 + (long)*piVar7 * 0x10);
      uVar13 = *puVar3;
      *(undefined8 *)((long)local_98 + lVar6 + 8) = puVar3[1];
      *(undefined8 *)((long)local_98 + lVar6) = uVar13;
      piVar7 = piVar7 + 1;
    }
    pdVar1 = (double *)
             (*(long *)(param_1 + 0x18) +
             (long)*(int *)(*(long *)(param_1 + 0x28) + lVar4 * 4) * 0x10);
    *pdVar1 = local_98[0] + local_98[2] + local_98[4];
    pdVar1[1] = local_98[3] + local_98[5] + local_98[1];
    dVar12 = (local_98[3] - local_98[5]) * _ff_cos_53_double;
    dVar14 = (local_98[2] - local_98[4]) * DAT_019d3708;
    dVar16 = local_98[0] - (local_98[2] + local_98[4]) * DAT_019d3710;
    dVar15 = local_98[1] - (local_98[3] + local_98[5]) * DAT_019d3710;
    pdVar1[lVar9 * 2] = dVar12 + dVar16;
    (pdVar1 + lVar9 * 2)[1] = dVar15 - dVar14;
    pdVar1[lVar9 * 4] = dVar16 - dVar12;
    (pdVar1 + lVar9 * 4)[1] = dVar14 + dVar15;
    piVar5 = piVar5 + 3;
  }
  lVar6 = 4;
  lVar4 = 0;
  while (lVar6 = lVar6 + -1, lVar6 != 0) {
    (*pcVar11)(*(long *)(param_1 + 0x18) + lVar4);
    lVar4 = lVar4 + lVar9 * 0x10;
  }
  for (lVar4 = 0; lVar4 < lVar9 * 3; lVar4 = lVar4 + 1) {
    puVar3 = (undefined8 *)
             (*(long *)(param_1 + 0x18) + (long)piVar10[(int)(uVar2 * 3) + lVar4] * 0x10);
    uVar13 = *puVar3;
    param_2[1] = puVar3[1];
    *param_2 = uVar13;
    param_2 = param_2 + 2;
  }
  if (lVar8 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


