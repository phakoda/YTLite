/* Decompiled from supplied 5.2.2 arm package. VA 0x11558c. FUN_0011558c */

undefined1  [16] FUN_0011558c(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_clearColor_0114b680);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_retainAutorelease();
  uVar2 = _objc_msgSend(uVar2,PTR_s_CGColor_0114c8c0);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_layer_0114ae60);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setBorderColor__0114d0d0,uVar2);
  _objc_release(uVar3);
  _objc_release(uVar1);
  CallSupervisor(0x9bc9);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}


