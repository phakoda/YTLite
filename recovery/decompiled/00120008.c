/* Decompiled from supplied 5.2.2 arm package. VA 0x120008. FUN_00120008 */

void FUN_00120008(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 local_30;
  long local_28;
  
  local_28 = *(long *)PTR____stack_chk_guard_01060708;
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  local_30 = *(undefined8 *)(param_1 + 0x28);
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,&local_30,
                1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_reloadRowsAtIndexPaths_withRowAn_0114d4f0,uVar2,5);
  _objc_release(uVar2);
  CallSupervisor(0x1b01);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


