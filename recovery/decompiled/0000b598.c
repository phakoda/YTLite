/* Decompiled from supplied 5.2.2 arm package. VA 0xb598. FUN_0000b598 */

undefined1  [16] FUN_0000b598(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auVar7 [16];
  
  puVar2 = PTR_YTLUserDefaults_0114ead8;
  puVar1 = PTR_s_boolForKey__0114ada8;
  DAT_012258d0 = 1;
  _objc_retain(param_3);
  uVar3 = FUN_0000c500(puVar2,puVar1,&PTR____CFConstantStringClassReference_011510c0);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_setBool_forKey__0114add8,uVar3 ^ 1,
                &PTR____CFConstantStringClassReference_011510c0);
  _objc_msgSend(PTR_YTPDiscordRPC_0114eac8,PTR_s_sharedPresence_0114ad78);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  if (uVar3 == 0) {
    _objc_msgSend(param_1,PTR_s__viewControllerForAncestor_0114ade0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_parentViewController_0114ad68);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    _objc_msgSend(PTR_RPCMedia_0114ead0,PTR_s_mediaWithPlayer__0114ad80,uVar6);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_setMedia__0114ad88,uVar5);
    _objc_release(uVar5);
    _objc_msgSend(uVar4,PTR_s_startIfPossible_0114ada0);
    _objc_release(uVar6);
  }
  else {
    _objc_msgSend(uVar4,PTR_s_clearPlayback_0114add0);
  }
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_adaptiveDiscord_0114ade8);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,PTR_s_setImage_forState__0114adf0,uVar5,0);
  _objc_release(param_3);
  _objc_release(uVar5);
  _objc_release(uVar4);
  CallSupervisor(0x37eb);
  auVar7._8_8_ = 0x1f;
  auVar7._0_8_ = 0x1a;
  return auVar7;
}


