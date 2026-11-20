/* Decompiled from supplied 5.2.2 arm package. VA 0x17959c. FUN_0017959c */

undefined1  [16] FUN_0017959c(long param_1,undefined8 param_2)

{
  undefined *puVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auVar7 [16];
  
  DAT_0122751c = 1;
  _objc_retain(param_2);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_selfViewController_0114d7d8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  if (*(char *)(param_1 + 0x28) == '\0') {
    bVar2 = *(char *)(param_1 + 0x29) == '\0';
    if (bVar2) {
      if (*(char *)(param_1 + 0x2a) == '\0') goto LAB_00179c18;
      _objc_msgSend(param_2,PTR_s_sourceView_0114d878);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      uVar5 = _objc_alloc(PTR__OBJC_CLASS___UIActivityIndicatorView_0114eb20);
      uVar5 = _objc_msgSend(uVar5,PTR_s_initWithActivityIndicatorStyle__0114b078,100);
      _objc_msgSend(uVar5,PTR_s_startAnimating_0114b0b0);
      _objc_msgSend(uVar4,PTR_s_setAccessoryView__0114d3b0,uVar5);
      _objc_msgSend(uVar4,PTR_s_setUserInteractionEnabled__0114b820,0);
      _isYTPFirstTime = 0;
      _DVNPatreonLogin(uVar3);
      _objc_release(uVar5);
    }
    else {
      uVar4 = _objc_getClass((&PTR_LAB_011a86d8)[bVar2] + (int)-(uRam00000000011a86e8 ^ 0x544fff61),
                             s_YTAlertView_011a57fc);
      puVar1 = PTR_s_ytl_localized_0114d190;
      _objc_msgSend(&PTR____CFConstantStringClassReference_011a58f0,PTR_s_ytl_localized_0114d190);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(&PTR____CFConstantStringClassReference_011a58b0,puVar1);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_confirmationDialogWithAction_act_0114d8e0,
                    &PTR___NSConcreteGlobalBlock_010626e0,uVar5,uVar6);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar6);
      _objc_release(uVar5);
      _objc_msgSend(&PTR____CFConstantStringClassReference_011a5870,puVar1);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_setTitle__0114afc0,uVar5);
      _objc_release(uVar5);
      _objc_msgSend(&PTR____CFConstantStringClassReference_011a5830,puVar1);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_setSubtitle__0114b280,uVar5);
      _objc_release(uVar5);
      _objc_msgSend(uVar4,PTR_s_show_0114b288);
    }
    _objc_release(uVar4);
  }
  else {
    _isYTPFirstTime = 0;
    _DVNPatreonOpenDevices(uVar3);
  }
LAB_00179c18:
  _objc_release(uVar3);
  _objc_release(param_2);
  CallSupervisor(0x68d9);
  auVar7._8_8_ = 0x1f;
  auVar7._0_8_ = 0x1a;
  return auVar7;
}


