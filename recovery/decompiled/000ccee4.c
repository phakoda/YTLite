/* Decompiled from supplied 5.2.2 arm package. VA 0xccee4. FUN_000ccee4 */

undefined1  [16] FUN_000ccee4(void)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  
  puVar1 = PTR_ToastManager_0114ecd0;
  DAT_01227040 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_01174c10,0,0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar3,1);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0xfe64);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}


