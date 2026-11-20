/* Decompiled from supplied 5.2.2 arm package. VA 0x1f1554. FUN_001f1554 */

undefined1  [16] FUN_001f1554(long param_1)

{
  undefined8 uVar1;
  
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_dimmingView_0114e1d8);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x3ff0000000000000,uVar1,PTR_s_setAlpha__0114b698);
  _objc_release(uVar1);
  CallSupervisor(0xf7ba);
  return ZEXT816(0x1f);
}


