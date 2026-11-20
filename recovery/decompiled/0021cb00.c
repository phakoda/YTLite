/* Decompiled from supplied 5.2.2 arm package. VA 0x21cb00. startRPC */

/* Function Stack Size: 0x10 bytes */

void YTPDiscordRPC::startRPC(ID param_1,SEL param_2)

{
  long lVar1;
  
  _objc_msgSend(param_1,PTR_s_media_0114ad90);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0021cb8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011cdda8)[lVar1 == 0] + (int)-(DAT_011cddb8 ^ 0x225cd9b1)))();
  return;
}


