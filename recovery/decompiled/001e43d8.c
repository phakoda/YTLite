/* Decompiled from supplied 5.2.2 arm package. VA 0x1e43d8. FUN_001e43d8 */

void FUN_001e43d8(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  
  DAT_01227e6c = 1;
  lVar2 = (long)TranslatorVC::_translateButton;
  _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + lVar2),PTR_s_setEnabled__0114c020,1);
  uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x20) + lVar2);
  _objc_msgSend(&PTR____CFConstantStringClassReference_011ba5e0,PTR_s_ytl_localized_0114d190);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setTitle_forState__0114b6a8,uVar1,0);
  _objc_release(uVar1);
  if (*(long *)(param_1 + 0x28) == 0) {
    lVar2 = (long)TranslatorVC::_textView;
    _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + lVar2),PTR_s_setText__0114b388,
                  *(undefined8 *)(param_1 + 0x30));
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_labelColor_0114aff8);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + lVar2),PTR_s_setTextColor__0114b5d8,
                  uVar1);
    _objc_release(uVar1);
    _objc_msgSend(PTR__OBJC_CLASS___UIFont_0114ec08,PTR_s_preferredFontForTextStyle__0114e0f0,
                  *(undefined8 *)PTR__UIFontTextStyleBody_01060558);
    uVar1 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(*(long *)(param_1 + 0x28),PTR_s_localizedDescription_0114c618);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    lVar2 = (long)TranslatorVC::_textView;
    _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + lVar2),PTR_s_setText__0114b388,uVar1);
    _objc_release(uVar1);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_systemRedColor_0114d8f0);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + lVar2),PTR_s_setTextColor__0114b5d8,
                  uVar1);
    _objc_release(uVar1);
    _objc_msgSend(0x402c000000000000,PTR__OBJC_CLASS___UIFont_0114ec08,
                  PTR_s_italicSystemFontOfSize__0114e110);
    uVar1 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x20) + lVar2),PTR_s_setFont__0114b5e8,uVar1);
  _objc_release(uVar1);
  return;
}


