/* Decompiled from supplied 5.2.2 arm package. VA 0x1f16e0. FUN_001f16e0 */

undefined1  [16] FUN_001f16e0(long param_1)

{
  undefined8 uVar1;
  
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_dimmingView_0114e1d8);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_removeFromSuperview_0114b708);
  _objc_release(uVar1);
  CallSupervisor(0x2bca);
  return ZEXT816(0x1f);
}


