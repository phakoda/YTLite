/* Decompiled from supplied 5.2.2 arm package. VA 0x2163fc. onSlimBarTap: */

/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::onSlimBarTap_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puStack_100;
  undefined8 uStack_f8;
  code *pcStack_f0;
  undefined *puStack_e8;
  ID IStack_e0;
  undefined *puStack_d0;
  undefined8 uStack_c8;
  code *pcStack_c0;
  undefined *puStack_b8;
  ID IStack_b0;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  
  local_78 = &PTR_LAB_011ccaf0;
  local_7c = (uint)(DAT_012281c0 == 0);
  local_90 = &PTR_LAB_011ccb10;
  ppuStack_88 = &PTR_LAB_011cbe30;
  local_a0 = &PTR_LAB_011cbe30;
  DAT_012281c0 = 1;
  lVar4 = _objc_msgSend(param_3,PTR_s_state_0114c560);
  uStack_94 = (uint)(lVar4 == 3);
  if (lVar4 == 3) {
    uVar5 = _objc_getClass(local_90[uStack_94] + (int)-(DAT_011ccb20 ^ 0xc82c0595),
                           s_YTAlertView_011cbb0f);
    _objc_msgSend(uVar5,PTR_s_dialog_0114b2a0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar3 = PTR_s_ytl_localized_0114d190;
    _objc_msgSend(&PTR____CFConstantStringClassReference_011cbca0,PTR_s_ytl_localized_0114d190);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_setTitle__0114afc0,uVar5);
    _objc_release(uVar5);
    _objc_msgSend(&PTR____CFConstantStringClassReference_011cbc60,puVar3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_setSubtitle__0114b280,uVar5);
    _objc_release(uVar5);
    _objc_msgSend(&PTR____CFConstantStringClassReference_011cbc20,puVar3);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_addTitle_withAction__0114b2a8;
    puVar1 = PTR___NSConcreteStackBlock_01060660;
    uVar5 = DAT_00c4c228;
    puStack_d0 = PTR___NSConcreteStackBlock_01060660;
    uStack_c8 = DAT_00c4c228;
    pcStack_c0 = FUN_00216d18;
    puStack_b8 = &DAT_01061420;
    IStack_b0 = param_1;
    _objc_msgSend(uVar6,PTR_s_addTitle_withAction__0114b2a8,uVar7,&puStack_d0);
    _objc_release(uVar7);
    _objc_msgSend(&PTR____CFConstantStringClassReference_011cbbe0,puVar3);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puStack_100 = puVar1;
    uStack_f8 = uVar5;
    pcStack_f0 = FUN_00216d50;
    puStack_e8 = &DAT_01061420;
    IStack_e0 = param_1;
    _objc_msgSend(uVar6,puVar2,uVar7,&puStack_100);
    _objc_release(uVar7);
    _objc_msgSend(&PTR____CFConstantStringClassReference_011cbba0,puVar3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar2,uVar5,0);
    _objc_release(uVar5);
    _objc_msgSend(uVar6,PTR_s_show_0114b288);
    _objc_release(uVar6);
  }
  CallSupervisor(0x186);
  return;
}


