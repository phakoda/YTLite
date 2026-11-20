/* Decompiled from supplied 5.2.2 arm package. VA 0x248b70. FUN_00248b70 */

void FUN_00248b70(undefined8 param_1,long param_2,undefined4 param_3,int param_4,undefined8 param_5,
                 undefined8 param_6,undefined4 param_7)

{
  long lVar1;
  undefined1 auStack_108 [160];
  long local_68;
  
  lVar1 = *(long *)PTR____stack_chk_guard_01060708;
  local_68 = lVar1;
  thunk_FUN_0024de70(auStack_108,0,0x50);
  FUN_00249c80(param_2,param_3,param_4,param_5,param_6,param_7,3,auStack_108);
  FUN_0024be5c(param_1,param_2 + (long)param_4 * 2,auStack_108);
  if (lVar1 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


