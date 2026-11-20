/* Decompiled from supplied 5.2.2 arm package. VA 0x21bf88. startIfPossible */

/* Function Stack Size: 0x10 bytes */

void YTPDiscordRPC::startIfPossible(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  undefined *puStack_d0;
  undefined8 uStack_c8;
  code *pcStack_c0;
  undefined *puStack_b8;
  ID IStack_b0;
  undefined8 uStack_a8;
  long lStack_a0;
  undefined **local_90;
  undefined **local_88;
  undefined **ppuStack_80;
  uint uStack_74;
  undefined **local_70;
  int iStack_64;
  undefined **local_60;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_switchD_011cdca8;
  local_4c = (uint)(DAT_01228260 == 0);
  local_60 = &PTR_UINT_011cdcc8;
  local_70 = &PTR_UINT_011cdce0;
  local_58 = &PTR_LAB_011cd930;
  local_88 = &PTR_LAB_011cd930;
  ppuStack_80 = &PTR_LAB_011cd930;
  local_90 = &PTR_LAB_011cd930;
  DAT_01228260 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  iStack_64 = FUN_0021ef9c(uVar2,PTR_s_boolForKey__0114ada8,
                           &PTR____CFConstantStringClassReference_011cd0f0);
  if (iStack_64 != 0) {
    _objc_msgSend(uVar2,PTR_s_stringForKey__0114d478,&PTR____CFConstantStringClassReference_011cd0b0
                 );
    lVar3 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_YTPDiscordRPC_0114eac8;
    uStack_74 = (uint)(lVar3 == 0);
    if (lVar3 == 0) {
      _objc_msgSend(param_1,PTR_s_showAlertWithMessage_showSetting_0114e5b0,
                    &PTR____CFConstantStringClassReference_011cd070,0);
    }
    else {
      puStack_d0 = PTR___NSConcreteStackBlock_01060660;
      uStack_c8 = DAT_00c4c228;
      pcStack_c0 = FUN_0021c4a0;
      puStack_b8 = &UNK_01063110;
      IStack_b0 = param_1;
      _objc_retain(uVar2);
      uStack_a8 = uVar2;
      _objc_retain(lVar3);
      lStack_a0 = lVar3;
      _objc_msgSend(puVar1,PTR_s_checkLocalNetworkPermission__0114e5c8,&puStack_d0);
      _objc_release(lStack_a0);
      _objc_release(uStack_a8);
    }
    _objc_release(lVar3);
  }
  _objc_release(uVar2);
  CallSupervisor(0xf530);
  return;
}


