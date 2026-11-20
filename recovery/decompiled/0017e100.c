/* Decompiled from supplied 5.2.2 arm package. VA 0x17e100. FUN_0017e100 */

undefined1  [16] FUN_0017e100(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  
  DAT_01227548 = 1;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_objectForKeyedSubscript__0114ae80,
                &PTR____CFConstantStringClassReference_011a6b90);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIPasteboard_0114ec78,PTR_s_generalPasteboard_0114b8a0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setString__0114b8a8,uVar2);
  _objc_release(uVar3);
  _objc_release(uVar2);
  puVar1 = PTR_ToastManager_0114ecd0;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a6b50,PTR_s_ytl_localized_0114d190);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar2,1);
  _objc_release(uVar2);
  CallSupervisor(0xbec6);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}


