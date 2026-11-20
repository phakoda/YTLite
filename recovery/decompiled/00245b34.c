/* Decompiled from supplied 5.2.2 arm package. VA 0x245b34. FUN_00245b34 */

void FUN_00245b34(long param_1,short *param_2,short *param_3,undefined8 param_4,undefined4 param_5,
                 int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  short local_158 [40];
  short local_108 [40];
  short local_b8 [40];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  iVar1 = FUN_00249904((int)*param_3,0x4000,0);
  iVar2 = FUN_00249904((int)param_3[1],iVar1,1);
  iVar3 = FUN_00249904((int)param_3[2],iVar2,2);
  FUN_00249a1c(local_b8,param_4,(long)*param_2,param_5,param_6);
  FUN_00249a1c(local_108,param_4,(long)param_2[1],param_5,param_6);
  FUN_00249a1c(local_158,param_4,(long)param_2[2],param_5,param_6);
  for (lVar4 = 0; lVar4 < param_6; lVar4 = lVar4 + 1) {
    *(short *)(param_1 + lVar4 * 2) =
         (short)(local_108[lVar4] * iVar2 + local_b8[lVar4] * iVar1 + local_158[lVar4] * iVar3 +
                 0x2000U >> 0xe);
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


