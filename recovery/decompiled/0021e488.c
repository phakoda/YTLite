/* Decompiled from supplied 5.2.2 arm package. VA 0x21e488. showAlertWithMessage:showSettingsButton: */

/* Function Stack Size: 0x1c bytes */

void YTPDiscordRPC::showAlertWithMessage_showSettingsButton_
               (ID param_1,SEL param_2,ID param_3,bool param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_01228298 = 1;
  _objc_retain(param_3);
  uVar2 = _objc_getClass(s_YTAlertView_011cd855);
  _objc_msgSend(uVar2,PTR_s_dialog_0114b2a0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_ytl_localized_0114d190;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011cd910,PTR_s_ytl_localized_0114d190);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setTitle__0114afc0,uVar3);
  _objc_release(uVar3);
  _objc_msgSend(param_3,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(uVar2,PTR_s_setSubtitle__0114b280,uVar3);
  _objc_release(uVar3);
                    /* WARNING: Could not recover jumptable at 0x0021e964. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011cdfc8)[param_4] + (int)-(DAT_011cdfd8 ^ 0x79489921)))();
  return;
}


