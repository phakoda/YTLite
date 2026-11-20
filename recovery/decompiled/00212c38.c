/* Decompiled from supplied 5.2.2 arm package. VA 0x212c38. showTimeSelector */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::showTimeSelector(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *puStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined *puStack_78;
  ID IStack_70;
  undefined8 uStack_68;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011cc520;
  local_4c = (uint)(DAT_0122812c == 0);
  local_58 = &PTR_LAB_011cbe30;
  DAT_0122812c = 1;
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIDatePicker_0114f008);
  uVar2 = _objc_msgSend(0,0,DAT_00c4c4a8,0x4064000000000000,uVar2,PTR_s_initWithFrame__0114b770);
  _objc_msgSend(uVar2,PTR_s_setDatePickerMode__0114e3d0,0);
  _objc_msgSend(uVar2,PTR_s_setPreferredDatePickerStyle__0114e3d8,1);
  _objc_msgSend(PTR__OBJC_CLASS___NSLocale_0114ecb0,PTR_s_currentLocale_0114e358);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setLocale__0114b990,uVar3);
  _objc_release(uVar3);
  uVar3 = _objc_getClass(s_YTAlertView_011cb59d);
  puVar1 = PTR_s_ytl_localized_0114d190;
  puStack_90 = PTR___NSConcreteStackBlock_01060660;
  uStack_88 = DAT_00c4c228;
  pcStack_80 = FUN_00213194;
  puStack_78 = &DAT_01061f70;
  IStack_70 = param_1;
  uStack_68 = uVar2;
  _objc_retain(uVar2);
  _objc_msgSend(&PTR____CFConstantStringClassReference_011cb610,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_confirmationDialogWithAction_act_0114e3e8,&puStack_90,uVar4);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_msgSend(&PTR____CFConstantStringClassReference_011cb5d0,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setTitle__0114afc0,uVar4);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,PTR_s_setCustomContentView__0114d638,uVar2);
  _objc_msgSend(uVar3,PTR_s_show_0114b288);
  _objc_release(uVar3);
  _objc_release(uStack_68);
  _objc_release(uVar2);
  return;
}


