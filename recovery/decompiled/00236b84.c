/* Decompiled from supplied 5.2.2 arm package. VA 0x236b84. FUN_00236b84 */

void FUN_00236b84(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_clearColor_0114b680);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_view_0114b090;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_view_0114b090);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setBackgroundColor__0114b550,uVar2);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_layoutIfNeeded_0114b928);
  _objc_release(uVar2);
  return;
}


