/* Decompiled from supplied 5.2.2 arm package. VA 0x24a664. FUN_0024a664 */

void FUN_0024a664(undefined8 param_1)

{
  long lVar1;
  undefined1 auStack_3c [20];
  long local_28;
  
  lVar1 = *(long *)PTR____stack_chk_guard_01060708;
  local_28 = lVar1;
  FUN_0024a3b4(auStack_3c);
  FUN_0024a720(param_1,auStack_3c);
  if (lVar1 == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


