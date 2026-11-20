/* Decompiled from supplied 5.2.2 arm package. VA 0x231550. FUN_00231550 */

void FUN_00231550(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_01228424 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,PTR_s_imageWithData__0114c5a0,
                *(undefined8 *)(param_1 + 0x20));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIPasteboard_0114ec78,PTR_s_generalPasteboard_0114b8a0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setImage__0114b8f8,uVar2);
  _objc_release(uVar3);
  _objc_release(uVar2);
  puVar1 = PTR_ToastManager_0114ecd0;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_011d0f20,0,0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar3,1);
  _objc_release(uVar3);
  (*(code *)PTR__objc_release_01061028)(uVar2);
  return;
}


