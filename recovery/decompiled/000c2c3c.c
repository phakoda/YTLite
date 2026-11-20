/* Decompiled from supplied 5.2.2 arm package. VA 0xc2c3c. FUN_000c2c3c */

undefined1  [16] FUN_000c2c3c(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  undefined1 auVar3 [16];
  
  lVar2 = *(long *)(param_1 + 0x20);
  if (lVar2 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___UIPasteboard_0114ec78,PTR_s_generalPasteboard_0114b8a0);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,PTR_s_setString__0114b8a8,lVar2);
    _objc_release(uVar1);
    _dispatch_async(PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_01061df0);
  }
  CallSupervisor(0x63f3);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


