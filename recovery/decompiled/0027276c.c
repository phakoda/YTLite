/* Decompiled from supplied 5.2.2 arm package. VA 0x27276c. FUN_0027276c */

void FUN_0027276c(long param_1,long param_2,long param_3)

{
  float *pfVar1;
  uint uVar2;
  long lVar3;
  int *piVar4;
  long lVar5;
  int *piVar6;
  long lVar7;
  long lVar8;
  int *piVar9;
  code *pcVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float local_90;
  float fStack_8c;
  float local_88;
  float fStack_84;
  float local_80;
  float fStack_7c;
  float local_78;
  float fStack_74;
  float local_70;
  float fStack_6c;
  long local_68;
  
  lVar7 = *(long *)PTR____stack_chk_guard_01060708;
  uVar2 = *(uint *)(param_1 + 4);
  lVar8 = (long)(int)uVar2;
  piVar9 = *(int **)(param_1 + 0x20);
  pcVar10 = *(code **)(&DAT_0106d428 + (long)(0x1f - (int)LZCOUNT(uVar2 | 1)) * 8);
  piVar4 = piVar9;
  local_68 = lVar7;
  for (lVar3 = 0; lVar3 < lVar8; lVar3 = lVar3 + 1) {
    piVar6 = piVar4;
    for (lVar5 = 0; lVar5 != 0x28; lVar5 = lVar5 + 8) {
      *(undefined8 *)((long)&local_90 + lVar5) = *(undefined8 *)(param_3 + (long)*piVar6 * 8);
      piVar6 = piVar6 + 1;
    }
    fVar11 = local_88 + local_70;
    fVar12 = fStack_84 + fStack_6c;
    fVar13 = local_80 + local_78;
    pfVar1 = (float *)(*(long *)(param_1 + 0x18) +
                      (long)*(int *)(*(long *)(param_1 + 0x28) + lVar3 * 4) * 8);
    *pfVar1 = fVar13 + fVar11 + local_90;
    fVar14 = fStack_7c + fStack_74;
    pfVar1[1] = fVar14 + fVar12 + fStack_8c;
    fVar18 = fVar13 * DAT_01a777b0;
    fVar19 = fVar11 * DAT_01a777b8;
    fVar20 = fVar14 * DAT_01a777b0;
    fVar21 = fVar12 * DAT_01a777b8;
    fVar15 = (fStack_7c - fStack_74) * DAT_01a777b4;
    fVar17 = (fStack_84 - fStack_6c) * DAT_01a777bc;
    fVar22 = (local_80 - local_78) * DAT_01a777b4;
    fVar16 = (local_88 - local_70) * DAT_01a777bc;
    fVar11 = fVar11 * DAT_01a777b0 - fVar13 * DAT_01a777b8;
    fVar12 = fVar12 * DAT_01a777b0 - fVar14 * DAT_01a777b8;
    fVar13 = (fStack_84 - fStack_6c) * DAT_01a777b4 + (fStack_7c - fStack_74) * DAT_01a777bc;
    fVar14 = (local_88 - local_70) * DAT_01a777b4 + (local_80 - local_78) * DAT_01a777bc;
    pfVar1[lVar8 * 2] = local_90 + fVar11 + fVar13;
    (pfVar1 + lVar8 * 2)[1] = fStack_8c + (fVar12 - fVar14);
    fVar18 = fVar18 - fVar19;
    fVar20 = fVar20 - fVar21;
    fVar15 = fVar15 - fVar17;
    fVar22 = fVar22 - fVar16;
    pfVar1[lVar8 * 4] = (fVar18 - fVar15) + local_90;
    (pfVar1 + lVar8 * 4)[1] = fVar20 + fVar22 + fStack_8c;
    pfVar1[lVar8 * 6] = fVar18 + fVar15 + local_90;
    (pfVar1 + lVar8 * 6)[1] = (fVar20 - fVar22) + fStack_8c;
    pfVar1[lVar8 * 8] = (fVar11 - fVar13) + local_90;
    (pfVar1 + lVar8 * 8)[1] = fVar12 + fVar14 + fStack_8c;
    piVar4 = piVar4 + 5;
  }
  lVar5 = 6;
  lVar3 = 0;
  while (lVar5 = lVar5 + -1, lVar5 != 0) {
    (*pcVar10)(*(long *)(param_1 + 0x18) + lVar3);
    lVar3 = lVar3 + lVar8 * 8;
  }
  for (lVar3 = 0; lVar3 < lVar8 * 5; lVar3 = lVar3 + 1) {
    *(undefined8 *)(param_2 + lVar3 * 8) =
         *(undefined8 *)(*(long *)(param_1 + 0x18) + (long)piVar9[(int)(uVar2 * 5) + lVar3] * 8);
  }
  if (lVar7 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


