/* Decompiled from supplied 5.2.2 arm package. VA 0x21d340. buildBody */

/* Function Stack Size: 0x10 bytes */

ID YTPDiscordRPC::buildBody(ID param_1,SEL param_2)

{
  long lVar1;
  ID IVar2;
  
  DAT_01228288 = 1;
  _objc_msgSend(param_1,PTR_s_media_0114ad90);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0021d968. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar2 = (*(code *)((&PTR_LAB_011cded0)[lVar1 == 0] + (int)-(DAT_011cdee0 ^ 0x29dbff2)))();
  return IVar2;
}


