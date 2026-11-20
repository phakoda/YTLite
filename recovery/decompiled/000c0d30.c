/* Decompiled from supplied 5.2.2 arm package. VA 0xc0d30. FUN_000c0d30 */

undefined1  [16] FUN_000c0d30(void)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  puVar1 = PTR_ToastManager_0114ecd0;
  DAT_01226f7c = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_011723a0,0,0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar3,1);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0x46b5);
  return ZEXT816(0x1f);
}


