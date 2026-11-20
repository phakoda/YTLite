/* Decompiled from supplied 5.2.2 arm package. VA 0x21ce10. updateTime */

/* Function Stack Size: 0x10 bytes */

void YTPDiscordRPC::updateTime(ID param_1,SEL param_2)

{
  long lVar1;
  
  _objc_msgSend(param_1,PTR_s_media_0114ad90);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0021ce98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011cde00)[lVar1 == 0] + (int)-(DAT_011cde10 ^ 0xdcfae566)))();
  return;
}


