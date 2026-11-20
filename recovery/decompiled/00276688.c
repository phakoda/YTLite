/* Decompiled from supplied 5.2.2 arm package. VA 0x276688. FUN_00276688 */

void FUN_00276688(long param_1,long param_2,long param_3)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  int *piVar5;
  long lVar6;
  int *piVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  int *piVar11;
  code *pcVar12;
  int local_80;
  int iStack_7c;
  int local_78;
  int iStack_74;
  int local_70;
  int iStack_6c;
  long local_68;
  
  lVar9 = *(long *)PTR____stack_chk_guard_01060708;
  uVar1 = *(uint *)(param_1 + 4);
  lVar10 = (long)(int)uVar1;
  piVar11 = *(int **)(param_1 + 0x20);
  pcVar12 = *(code **)(&DAT_0106d4b8 + (long)(0x1f - (int)LZCOUNT(uVar1 | 1)) * 8);
  piVar5 = piVar11;
  local_68 = lVar9;
  for (lVar4 = 0; lVar4 < lVar10; lVar4 = lVar4 + 1) {
    piVar7 = piVar5;
    for (lVar6 = 0; lVar6 != 0x18; lVar6 = lVar6 + 8) {
      *(undefined8 *)((long)&local_80 + lVar6) = *(undefined8 *)(param_3 + (long)*piVar7 * 8);
      piVar7 = piVar7 + 1;
    }
    piVar7 = (int *)(*(long *)(param_1 + 0x18) +
                    (long)*(int *)(*(long *)(param_1 + 0x28) + lVar4 * 4) * 8);
    *piVar7 = local_80 + local_70 + local_78;
    piVar7[1] = iStack_7c + iStack_6c + iStack_74;
    lVar2 = (long)DAT_01af77a8 * (long)(local_70 + local_78);
    lVar8 = (long)DAT_01af77a8 * (long)(iStack_6c + iStack_74);
    lVar3 = (long)(int)_ff_cos_53_int32 * (long)(iStack_74 - iStack_6c);
    lVar6 = (_ff_cos_53_int32 >> 0x20) * (long)(local_78 - local_70);
    piVar7[lVar10 * 2] = local_80 - (int)(lVar3 + lVar2 + 0x40000000U >> 0x1f);
    (piVar7 + lVar10 * 2)[1] = iStack_7c - (int)((ulong)((0x40000000 - lVar6) + lVar8) >> 0x1f);
    piVar7[lVar10 * 4] = local_80 - (int)((ulong)((0x40000000 - lVar3) + lVar2) >> 0x1f);
    (piVar7 + lVar10 * 4)[1] = iStack_7c - (int)(lVar6 + lVar8 + 0x40000000U >> 0x1f);
    piVar5 = piVar5 + 3;
  }
  lVar6 = 4;
  lVar4 = 0;
  while (lVar6 = lVar6 + -1, lVar6 != 0) {
    (*pcVar12)(*(long *)(param_1 + 0x18) + lVar4);
    lVar4 = lVar4 + lVar10 * 8;
  }
  for (lVar4 = 0; lVar4 < lVar10 * 3; lVar4 = lVar4 + 1) {
    *(undefined8 *)(param_2 + lVar4 * 8) =
         *(undefined8 *)(*(long *)(param_1 + 0x18) + (long)piVar11[(int)(uVar1 * 3) + lVar4] * 8);
  }
  if (lVar9 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


