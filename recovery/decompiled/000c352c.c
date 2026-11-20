/* Decompiled from supplied 5.2.2 arm package. VA 0xc352c. FUN_000c352c */

undefined1  [16] FUN_000c352c(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  
  puVar2 = PTR__OBJC_CLASS___UIPasteboard_0114ec78;
  puVar1 = PTR_s_generalPasteboard_0114b8a0;
  _objc_retain(param_2);
  _objc_msgSend(puVar2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setImage__0114b8f8,param_2);
  _objc_release(param_2);
  _objc_release(uVar3);
  _dispatch_async(PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_01061e70);
  CallSupervisor(0xec8d);
  return ZEXT816(0x1f);
}


