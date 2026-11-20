/* Decompiled from supplied 5.2.2 arm package. VA 0x24a720. FUN_0024a720 */

void FUN_0024a720(undefined2 *param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined2 *puVar4;
  int *piVar5;
  long lVar6;
  undefined1 auStack_8c [2];
  undefined1 auStack_8a [18];
  undefined1 auStack_78 [4];
  int local_74 [5];
  undefined1 auStack_60 [4];
  int aiStack_5c [5];
  long local_48;
  
  lVar6 = *(long *)PTR____stack_chk_guard_01060708;
  local_48 = lVar6;
  FUN_0024a6bc(param_2,auStack_8c,10);
  FUN_00249bc8(auStack_8c,auStack_78);
  FUN_00249bc8(auStack_8a,auStack_60);
  for (lVar3 = 0; 0 < (int)lVar3 + 5; lVar3 = lVar3 + -1) {
    iVar1 = aiStack_5c[lVar3 + 3];
    iVar2 = aiStack_5c[lVar3 + 4];
    *(int *)(auStack_60 + lVar3 * 4 + -4) =
         *(int *)(auStack_60 + lVar3 * 4 + -4) + local_74[lVar3 + 3];
    aiStack_5c[lVar3 + 4] = iVar2 - iVar1;
  }
  *param_1 = 0x1000;
  piVar5 = aiStack_5c;
  puVar4 = param_1;
  for (lVar3 = 0; puVar4 = puVar4 + 1, 0 < (int)lVar3 + 5; lVar3 = lVar3 + -1) {
    iVar1 = piVar5[-6];
    iVar2 = *piVar5;
    *puVar4 = (short)((uint)(iVar1 + 0x1000 + iVar2) >> 0xd);
    param_1[lVar3 + 10] = (short)((uint)((iVar1 + 0x1000) - iVar2) >> 0xd);
    piVar5 = piVar5 + 1;
  }
  if (lVar6 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


