/* Decompiled from supplied 5.2.2 arm package. VA 0x11a6a8. FUN_0011a6a8 */

undefined1  [16] FUN_0011a6a8(long param_1)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_clearColor_0114b680);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_setBackgroundColor__0114b550,uVar1);
  _objc_release(uVar1);
  CallSupervisor(0x1fc6);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


