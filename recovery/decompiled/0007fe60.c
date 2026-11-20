/* Decompiled from supplied 5.2.2 arm package. VA 0x7fe60. FUN_0007fe60 */

void FUN_0007fe60(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  (*DAT_01226300)();
  uVar1 = _objc_alloc(PTR__OBJC_CLASS___UIPanGestureRecognizer_0114ed90);
  uVar1 = _objc_msgSend(uVar1,PTR_s_initWithTarget_action__0114c530,param_1,
                        PTR_s_handleHorizontalPan__0114be78);
  _objc_msgSend(uVar1,PTR_s_setMinimumNumberOfTouches__0114c870,1);
  _objc_msgSend(uVar1,PTR_s_setMaximumNumberOfTouches__0114c878,1);
  _objc_msgSend(uVar1,PTR_s_setDelegate__0114b7d8,param_1);
  _objc_msgSend(param_1,PTR_s_view_0114b090);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_addGestureRecognizer__0114c540,uVar1);
  _objc_release(uVar2);
  _objc_release(uVar1);
  return;
}


