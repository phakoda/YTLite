/* Decompiled from supplied 5.2.2 arm package. VA 0x2725b0. FUN_002725b0 */

void FUN_002725b0(long param_1,long param_2,long param_3)

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
    for (lVar5 = 0; lVar5 != 0x18; lVar5 = lVar5 + 8) {
      *(undefined8 *)((long)&local_80 + lVar5) = *(undefined8 *)(param_3 + (long)*piVar6 * 8);
      piVar6 = piVar6 + 1;
    }
    pfVar1 = (float *)(*(long *)(param_1 + 0x18) +
                      (long)*(int *)(*(long *)(param_1 + 0x28) + lVar3 * 4) * 8);
    *pfVar1 = local_80 + local_78 + local_70;
    pfVar1[1] = fStack_74 + fStack_6c + fStack_7c;
    fVar11 = (fStack_74 - fStack_6c) * _ff_cos_53_float;
    fVar12 = (local_78 - local_70) * DAT_01a777a4;
    fVar14 = local_80 - (local_78 + local_70) * DAT_01a777a8;
    fVar13 = fStack_7c - (fStack_74 + fStack_6c) * DAT_01a777a8;
    pfVar1[lVar8 * 2] = fVar11 + fVar14;
    (pfVar1 + lVar8 * 2)[1] = fVar13 - fVar12;
    pfVar1[lVar8 * 4] = fVar14 - fVar11;
    (pfVar1 + lVar8 * 4)[1] = fVar12 + fVar13;
    piVar4 = piVar4 + 3;
  }
  lVar5 = 4;
  lVar3 = 0;
  while (lVar5 = lVar5 + -1, lVar5 != 0) {
    (*pcVar10)(*(long *)(param_1 + 0x18) + lVar3);
    lVar3 = lVar3 + lVar8 * 8;
  }
  for (lVar3 = 0; lVar3 < lVar8 * 3; lVar3 = lVar3 + 1) {
    *(undefined8 *)(param_2 + lVar3 * 8) =
         *(undefined8 *)(*(long *)(param_1 + 0x18) + (long)piVar9[(int)(uVar2 * 3) + lVar3] * 8);
  }
  if (lVar7 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


