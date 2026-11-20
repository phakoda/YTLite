/* Decompiled from supplied 5.2.2 arm package. VA 0x42024. FUN_00042024 */

undefined1  [16] FUN_00042024(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  
  DAT_01225ec8 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIPasteboard_0114ec78,PTR_s_generalPasteboard_0114b8a0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_setString__0114b8a8,&PTR____CFConstantStringClassReference_0115c4d0);
  _objc_release(uVar1);
  uVar3 = *(undefined8 *)(param_1 + 0x20);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_0115c490,0,0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_showAlertWithTitle_imageName__0114b8b0,uVar2,
                &PTR____CFConstantStringClassReference_0115c450);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0xadb2);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}


