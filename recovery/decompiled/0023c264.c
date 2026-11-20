/* Decompiled from supplied 5.2.2 arm package. VA 0x23c264. updateToastText:value: */

/* Function Stack Size: 0x20 bytes */

void PlayerToast::updateToastText_value_(ID param_1,SEL param_2,ID param_3,double param_4)

{
  ID IVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  undefined *puStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined *puStack_78;
  ID IStack_70;
  undefined8 uStack_68;
  int local_5c;
  undefined **local_58;
  
  puVar2 = PTR_s_image_0114aeb8;
  local_58 = &PTR_LAB_011d2850;
  lVar7 = (long)_toastImage;
  uVar6 = *(undefined8 *)(param_1 + lVar7);
  _objc_retain(param_3);
  _objc_msgSend(uVar6,puVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar7),PTR_s_setImage__0114b8f8,uVar6);
  _objc_release(uVar6);
  _objc_msgSend(param_4,param_1,PTR_s_setProgress__0114b330);
  puVar3 = PTR_s_setText__0114b388;
  IVar1 = param_3;
  if (*(char *)(param_1 + (long)_isCompact) != '\0') {
    IVar1 = 0;
  }
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastLabel),PTR_s_setText__0114b388,IVar1);
  _objc_release(param_3);
  lVar8 = (long)_style;
  _objc_msgSend((double)(long)(param_4 * 100.0),param_1,PTR_s_subLabelForVal_style__0114e898,
                *(undefined8 *)(param_1 + lVar8));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastSubLabel),puVar3,uVar6);
  _objc_release(uVar6);
  _objc_msgSend(param_4,param_1,PTR_s_setValue_forEventWithStyle__0114e8c0,
                *(undefined8 *)(param_1 + lVar8));
  _objc_msgSend((double)(long)(param_4 * 100.0),param_1,PTR_s_imgForVal__0114e890);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar7),puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  iVar4 = FUN_0023f18c(uVar5,PTR_s_isEqual__0114b060,uVar6);
  _objc_release(uVar5);
  puVar2 = PTR__OBJC_CLASS___UIView_0114ec30;
  local_5c = iVar4;
  if (iVar4 == 0) {
    uVar5 = *(undefined8 *)(param_1 + lVar7);
    puStack_90 = PTR___NSConcreteStackBlock_01060660;
    uStack_88 = DAT_00c4c228;
    pcStack_80 = FUN_0023c4e8;
    puStack_78 = &DAT_01061f70;
    IStack_70 = param_1;
    _objc_retain(uVar6);
    uStack_68 = uVar6;
    _objc_msgSend(0x3fe0000000000000,puVar2,PTR_s_transitionWithView_duration_opti_0114e8c8,uVar5,
                  0x500000,&puStack_90,0);
    _objc_release(uStack_68);
  }
  _objc_release(uVar6);
  CallSupervisor(0x6e0b);
  return;
}


