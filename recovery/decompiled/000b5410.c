/* Decompiled from supplied 5.2.2 arm package. VA 0xb5410. FUN_000b5410 */

undefined1  [16] FUN_000b5410(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  
  DAT_01226eb0 = 1;
  lVar1 = _objc_msgSend(param_3,PTR_s_state_0114c560);
  if (lVar1 == 1) {
    _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_setBool_forKey__0114add8,0,
                  &PTR____CFConstantStringClassReference_01170640);
    _objc_release(uVar2);
    _dispatch_async(PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_01062090);
    _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_delegate_0114b530);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_window_0114b3b0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar3);
    _objc_release(uVar2);
    _objc_msgSend(uVar4,PTR_s_rootViewController_0114b968);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(0x3ff0000000000000,uVar2,PTR_s_performSelector_withObject_after_0114cb48,
                  PTR_s_showPivotBar_0114c268,0);
    _objc_release(uVar2);
    _objc_release(uVar4);
  }
  CallSupervisor(0x3c1b);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}


