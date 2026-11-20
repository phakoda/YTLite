/* Decompiled from supplied 5.2.2 arm package. VA 0xc0fec. FUN_000c0fec */

undefined1  [16] FUN_000c0fec(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0x20);
  _objc_msgSend(PTR__OBJC_CLASS___UIPasteboard_0114ec78,PTR_s_generalPasteboard_0114b8a0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_setImage__0114b8f8,uVar2);
  _objc_release(uVar1);
  _dispatch_async(PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_01061c90);
  CallSupervisor(0xba7c);
  return ZEXT816(0x1f);
}


