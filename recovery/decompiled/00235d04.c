/* Decompiled from supplied 5.2.2 arm package. VA 0x235d04. FUN_00235d04 */

undefined1  [16] FUN_00235d04(long param_1)

{
  undefined8 uVar1;
  
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_view_0114b090);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_layoutIfNeeded_0114b928);
  _objc_release(uVar1);
  CallSupervisor(0x4f16);
  return ZEXT816(0x1f);
}


