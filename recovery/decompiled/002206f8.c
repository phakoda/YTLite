/* Decompiled from supplied 5.2.2 arm package. VA 0x2206f8. FUN_002206f8 */

undefined1  [16] FUN_002206f8(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_hapticFeedback_0114e628);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_fullImage_0114e630);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIPasteboard_0114ec78,PTR_s_generalPasteboard_0114b8a0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setImage__0114b8f8,uVar1);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0x7887);
  return ZEXT816(0x1f);
}


