/* Decompiled from supplied 5.2.2 arm package. VA 0x24a9d0. FUN_0024a9d0 */

void FUN_0024a9d0(undefined2 *param_1,long param_2,short param_3,int param_4)

{
  int iVar1;
  undefined2 uVar2;
  long lVar3;
  long lVar4;
  int local_48 [8];
  long local_28;
  
  lVar4 = *(long *)PTR____stack_chk_guard_01060708;
  local_28 = lVar4;
  for (lVar3 = 0; lVar3 < param_4; lVar3 = lVar3 + 1) {
    iVar1 = (int)(short)(*(short *)(param_2 + lVar3 * 2) - param_3);
    local_48[lVar3] = iVar1 * iVar1;
  }
  uVar2 = FUN_0024eb5c(local_48,param_4);
  *param_1 = uVar2;
  if (lVar4 == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


