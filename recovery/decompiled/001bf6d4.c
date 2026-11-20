/* Decompiled from supplied 5.2.2 arm package. VA 0x1bf6d4. removeObservers */

/* Function Stack Size: 0x10 bytes */

void ToastView::removeObservers(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  
  puVar1 = PTR_s_defaultCenter_0114b3e0;
  DAT_01227b44 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,PTR_s_defaultCenter_0114b3e0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_removeObserver_name_object__0114ddf0;
  _objc_msgSend(uVar3,PTR_s_removeObserver_name_object__0114ddf0,param_1,
                *(undefined8 *)PTR__UIKeyboardWillShowNotification_010605c0,0);
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,puVar2,param_1,*(undefined8 *)PTR__UIKeyboardWillHideNotification_010605b8,0);
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,puVar2,param_1,&PTR____CFConstantStringClassReference_011b3880,0);
  _objc_release(uVar3);
  return;
}


