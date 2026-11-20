/* Decompiled from supplied 5.2.2 arm package. VA 0x24ebec. FUN_0024ebec */

undefined4 FUN_0024ebec(uint *param_1,long param_2,void *param_3)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  undefined2 *puVar6;
  long lVar7;
  undefined2 local_1048 [2048];
  long local_48;
  
  lVar7 = *(long *)PTR____stack_chk_guard_01060708;
  iVar3 = 1 << (ulong)(*param_1 & 0x1f);
  puVar6 = local_1048 + 1;
  local_48 = lVar7;
  for (lVar5 = 0; lVar5 < iVar3; lVar5 = lVar5 + 1) {
    uVar2 = *(undefined2 *)(param_2 + lVar5 * 2);
    *puVar6 = 0;
    puVar6[-1] = uVar2;
    puVar6 = puVar6 + 2;
  }
  FUN_0024d8fc(local_1048);
  uVar4 = FUN_0024d9c8(local_1048,*param_1,1);
  uVar1 = iVar3 + 2;
  _memcpy(param_3,local_1048,-(ulong)(uVar1 >> 0x1f) & 0xfffffffe00000000 | (ulong)uVar1 << 1);
  if (lVar7 == local_48) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


