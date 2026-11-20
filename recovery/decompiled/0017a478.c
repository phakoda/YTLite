/* Decompiled from supplied 5.2.2 arm package. VA 0x17a478. resetSettings */

/* Function Stack Size: 0x10 bytes */

void YTPSettingsBuilder::resetSettings(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  DAT_01227530 = 1;
  uVar2 = _objc_getClass(s_YTAlertView_011a5b94);
  puVar1 = PTR_s_ytl_localized_0114d190;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a5c80,PTR_s_ytl_localized_0114d190);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a5c40,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_confirmationDialogWithAction_act_0114d8e0,
                &PTR___NSConcreteGlobalBlock_01062770,uVar3,uVar4);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a5c00,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setTitle__0114afc0,uVar3);
  _objc_release(uVar3);
  _objc_msgSend(&PTR____CFConstantStringClassReference_011a5bc0,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setSubtitle__0114b280,uVar3);
  _objc_release(uVar3);
  _objc_msgSend(uVar2,PTR_s_show_0114b288);
  _objc_release(uVar2);
  CallSupervisor(0xf68d);
  return;
}


