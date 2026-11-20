/* Decompiled from supplied 5.2.2 arm package. VA 0x10a768. FUN_0010a768 */

undefined1  [16] FUN_0010a768(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  
  DAT_01227204 = 1;
  _objc_retain(param_2);
  if (param_3 == 0) {
    _objc_msgSend(PTR__OBJC_CLASS___UIPasteboard_0114ec78,PTR_s_generalPasteboard_0114b8a0);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,PTR_s_setString__0114b8a8,param_2);
    _objc_release(uVar1);
    uVar2 = *(undefined8 *)(param_1 + 0x20);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_01187ad0,0,0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar3,1);
    _objc_release(uVar3);
  }
  else {
    uVar3 = *(undefined8 *)(param_1 + 0x20);
    _objc_msgSend(param_3,PTR_s_localizedDescription_0114c618);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar1,0);
  }
  _objc_release(uVar1);
  _objc_release(param_2);
  CallSupervisor(0xfcf7);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}


