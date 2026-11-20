/* Decompiled from supplied 5.2.2 arm package. VA 0x24b1cc. FUN_0024b1cc */

void FUN_0024b1cc(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined1 auStack_3c [20];
  long local_28;
  
  lVar1 = *(long *)PTR____stack_chk_guard_01060708;
  local_28 = lVar1;
  FUN_0024b238(param_2,auStack_3c,&DAT_00c4f0f4);
  FUN_0024a830(auStack_3c,param_1,10);
  if (lVar1 == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


