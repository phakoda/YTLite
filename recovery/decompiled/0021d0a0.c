/* Decompiled from supplied 5.2.2 arm package. VA 0x21d0a0. clearPlayback */

/* Function Stack Size: 0x10 bytes */

void YTPDiscordRPC::clearPlayback(ID param_1,SEL param_2)

{
  long lVar1;
  
  DAT_01228284 = 1;
  _objc_msgSend(param_1,PTR_s_media_0114ad90);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0021d280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011cde90)[lVar1 == 0] + (int)-(DAT_011cdea0 ^ 0xa821ccc6)))();
  return;
}


