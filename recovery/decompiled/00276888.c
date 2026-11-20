/* Decompiled from supplied 5.2.2 arm package. VA 0x276888. FUN_00276888 */

void FUN_00276888(long param_1,long param_2,long param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  int *piVar10;
  int *piVar11;
  long lVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  long lVar16;
  long lVar17;
  code *pcVar18;
  long lVar19;
  long lVar20;
  int local_90;
  int iStack_8c;
  int local_88;
  int iStack_84;
  int local_80;
  int iStack_7c;
  int local_78;
  int iStack_74;
  int local_70;
  int iStack_6c;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar2 = *(uint *)(param_1 + 4);
  lVar16 = (long)(int)uVar2;
  piVar10 = *(int **)(param_1 + 0x20);
  pcVar18 = *(code **)(&DAT_0106d4b8 + (long)(0x1f - (int)LZCOUNT(uVar2 | 1)) * 8);
  piVar11 = piVar10;
  for (lVar9 = 0; lVar9 < lVar16; lVar9 = lVar9 + 1) {
    piVar13 = piVar11;
    for (lVar12 = 0; lVar12 != 0x28; lVar12 = lVar12 + 8) {
      *(undefined8 *)((long)&local_90 + lVar12) = *(undefined8 *)(param_3 + (long)*piVar13 * 8);
      piVar13 = piVar13 + 1;
    }
    iVar3 = local_70 + local_88;
    iVar14 = iStack_6c + iStack_84;
    iVar8 = local_78 + local_80;
    iVar1 = iStack_74 + iStack_7c;
    piVar13 = (int *)(*(long *)(param_1 + 0x18) +
                     (long)*(int *)(*(long *)(param_1 + 0x28) + lVar9 * 4) * 8);
    *piVar13 = iVar8 + iVar3 + local_90;
    piVar13[1] = iVar1 + iVar14 + iStack_8c;
    lVar12 = (long)(int)DAT_01af77b0;
    lVar17 = (long)(int)DAT_01af77b8;
    lVar19 = DAT_01af77b0 >> 0x20;
    lVar20 = DAT_01af77b8 >> 0x20;
    iVar15 = (int)((ulong)((lVar19 * (iStack_7c - iStack_74) + 0x40000000) -
                          lVar20 * (iStack_84 - iStack_6c)) >> 0x1f);
    iVar4 = (int)((ulong)((lVar12 * iVar8 + 0x40000000) - lVar17 * iVar3) >> 0x1f);
    iVar6 = (int)((ulong)((lVar12 * iVar1 + 0x40000000) - lVar17 * iVar14) >> 0x1f);
    iVar7 = (int)((ulong)((lVar19 * (local_80 - local_78) + 0x40000000) -
                         lVar20 * (local_88 - local_70)) >> 0x1f);
    iVar5 = (int)(lVar20 * (iStack_7c - iStack_74) + lVar19 * (iStack_84 - iStack_6c) + 0x40000000U
                 >> 0x1f);
    iVar8 = (int)((ulong)((lVar12 * iVar3 + 0x40000000) - lVar17 * iVar8) >> 0x1f);
    iVar3 = (int)(lVar20 * (local_80 - local_78) + lVar19 * (local_88 - local_70) + 0x40000000U >>
                 0x1f);
    iVar14 = (int)((ulong)((lVar12 * iVar14 + 0x40000000) - lVar17 * iVar1) >> 0x1f);
    piVar13[lVar16 * 2] = iVar5 + local_90 + iVar8;
    (piVar13 + lVar16 * 2)[1] = (iStack_8c - iVar3) + iVar14;
    piVar13[lVar16 * 4] = (local_90 - iVar15) + iVar4;
    (piVar13 + lVar16 * 4)[1] = iVar6 + iVar7 + iStack_8c;
    piVar13[lVar16 * 6] = iVar4 + iVar15 + local_90;
    (piVar13 + lVar16 * 6)[1] = (iVar6 - iVar7) + iStack_8c;
    piVar13[lVar16 * 8] = (iVar8 - iVar5) + local_90;
    (piVar13 + lVar16 * 8)[1] = iVar14 + iVar3 + iStack_8c;
    piVar11 = piVar11 + 5;
  }
  lVar12 = 6;
  lVar9 = 0;
  while (lVar12 = lVar12 + -1, lVar12 != 0) {
    (*pcVar18)(*(long *)(param_1 + 0x18) + lVar9);
    lVar9 = lVar9 + lVar16 * 8;
  }
  for (lVar9 = 0; lVar9 < lVar16 * 5; lVar9 = lVar9 + 1) {
    *(undefined8 *)(param_2 + lVar9 * 8) =
         *(undefined8 *)(*(long *)(param_1 + 0x18) + (long)piVar10[(int)(uVar2 * 5) + lVar9] * 8);
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


