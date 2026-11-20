/* Decompiled from supplied 5.2.2 arm package. VA 0x24a470. FUN_0024a470 */

void FUN_0024a470(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 long param_5)

{
  long lVar1;
  undefined1 auStack_98 [40];
  undefined1 auStack_70 [40];
  long local_48;
  
  lVar1 = *(long *)PTR____stack_chk_guard_01060708;
  local_48 = lVar1;
  FUN_0024bb2c(auStack_70,param_4,param_5);
  FUN_0024bdd4(auStack_98,param_3,auStack_70,(long)*(short *)(param_5 + 0xc));
  FUN_0024a528(auStack_98,10,(long)*(short *)(param_5 + 0xc));
  FUN_0024b878(param_1,param_2,auStack_70,auStack_98,param_5 + 0x24,param_5 + 0x38,10,param_5);
  if (lVar1 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


