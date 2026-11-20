/* Decompiled from supplied 5.2.2 arm package. VA 0xc1708. FUN_000c1708 */

undefined1  [16] FUN_000c1708(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20);
  if (lVar2 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___UIPasteboard_0114ec78,PTR_s_generalPasteboard_0114b8a0);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,PTR_s_setString__0114b8a8,lVar2);
    _objc_release(uVar1);
    _dispatch_async(PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_01061ce0);
  }
  CallSupervisor(0xe912);
  return ZEXT816(0x1f);
}


