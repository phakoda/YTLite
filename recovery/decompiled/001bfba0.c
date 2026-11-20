/* Decompiled from supplied 5.2.2 arm package. VA 0x1bfba0. keyboardWillShow: */

/* Function Stack Size: 0x18 bytes */

void ToastView::keyboardWillShow_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  
  _objc_msgSend(param_3,PTR_s_userInfo_0114ddf8);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_objectForKeyedSubscript__0114ae80,
                *(undefined8 *)PTR__UIKeyboardFrameEndUserInfoKey_010605b0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_msgSend(uVar2,PTR_s_CGRectValue_0114de00);
  _objc_release(uVar2);
  _objc_msgSend(uVar3,in_d1,in_d2,in_d3,param_1,PTR_s_convertRect_fromView__0114de08,0);
  uVar2 = _CGRectGetHeight();
  *(undefined8 *)(param_1 + (long)_keyboardHeight) = uVar2;
  _objc_msgSend(param_1,PTR_s_updateLayout_0114ddb0);
  _objc_release(uVar1);
  CallSupervisor(0xabc8);
  return;
}


