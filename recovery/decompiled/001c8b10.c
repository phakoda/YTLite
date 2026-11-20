/* Decompiled from supplied 5.2.2 arm package. VA 0x1c8b10. initWithWindowScene: */

/* Function Stack Size: 0x18 bytes */

ID ToastWindow::initWithWindowScene_(ID param_1,SEL param_2,ID param_3)

{
  ID IVar1;
  undefined8 uVar2;
  ID local_40;
  undefined *puStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011b4c68;
  puStack_38 = PTR_ToastWindow_0114f0f0;
  local_40 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_40,PTR_s_initWithWindowScene__0114dcd8);
  local_2c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    _objc_msgSend(*(double *)PTR__UIWindowLevelAlert_010605e0 + -1.0,IVar1,
                  PTR_s_setWindowLevel__0114b778);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_clearColor_0114b680);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(IVar1,PTR_s_setBackgroundColor__0114b550,uVar2);
    _objc_release(uVar2);
  }
  return IVar1;
}


