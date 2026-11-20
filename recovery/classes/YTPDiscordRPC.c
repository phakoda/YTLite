// Decompiled implementation evidence for YTPDiscordRPC. Not compilable source.

// -[YTPDiscordRPC setServerURL:], 0x21b934
/* Decompiled from supplied 5.2.2 arm package. VA 0x21b934. setServerURL: */

/* Function Stack Size: 0x18 bytes */

void YTPDiscordRPC::setServerURL_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  ID IVar5;
  ID IVar6;
  long lVar7;
  
  DAT_0122825c = 1;
  _objc_retain(param_3);
  uVar4 = _objc_retain();
  puVar1 = @selector(hasPrefix:);
  uVar2 = FUN_0021ee4c(uVar4,@selector(hasPrefix:),
                       @"https://");
  if (uVar2 == 0) {
    iVar3 = FUN_0021eeb4((&PTR_LAB_011cdbe8)[uVar2] + (int)-(DAT_011cdbf8 ^ 0xdeb14243),param_3,
                         puVar1,@"http://");
    if (iVar3 != 0) goto LAB_0021bcf8;
    _objc_msgSend(@"http://",
                  @selector(stringByAppendingString:),param_3);
    IVar5 = _objc_retainAutoreleasedReturnValue();
    IVar6 = param_3;
  }
  else {
    _objc_msgSend(param_3,@selector(substringFromIndex:),8);
    IVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(@"http://",
                  @selector(stringByAppendingString:),IVar6);
    IVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(param_3);
  }
  param_3 = IVar5;
  _objc_release(IVar6);
LAB_0021bcf8:
  _objc_msgSend(PTR__OBJC_CLASS___NSURLComponents_0114edc8,@selector(componentsWithString:),
                param_3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(port));
  lVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0021bd64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR__objc_msgSend_011cdc30)[lVar7 == 0] + (int)-(DAT_011cdc40 ^ 0x8fd12330)))();
  return;
}



// -[YTPDiscordRPC startIfPossible], 0x21bf88
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
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  iStack_64 = FUN_0021ef9c(uVar2,@selector(boolForKey:),
                           @"discordRPC");
  if (iStack_64 != 0) {
    _objc_msgSend(uVar2,@selector(stringForKey:),@"rpcAddress"
                 );
    lVar3 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_YTPDiscordRPC_0114eac8;
    uStack_74 = (uint)(lVar3 == 0);
    if (lVar3 == 0) {
      _objc_msgSend(param_1,@selector(showAlertWithMessage:showSettingsButton:),
                    @"RPC.MissingServerAddress",0);
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
      _objc_msgSend(puVar1,@selector(checkLocalNetworkPermission:),&puStack_d0);
      _objc_release(lStack_a0);
      _objc_release(uStack_a8);
    }
    _objc_release(lVar3);
  }
  _objc_release(uVar2);
  CallSupervisor(0xf530);
  return;
}



// -[YTPDiscordRPC startRPC], 0x21cb00
/* Decompiled from supplied 5.2.2 arm package. VA 0x21cb00. startRPC */

/* Function Stack Size: 0x10 bytes */

void YTPDiscordRPC::startRPC(ID param_1,SEL param_2)

{
  long lVar1;
  
  _objc_msgSend(param_1,@selector(media));
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0021cb8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011cdda8)[lVar1 == 0] + (int)-(DAT_011cddb8 ^ 0x225cd9b1)))();
  return;
}



// -[YTPDiscordRPC updateTime], 0x21ce10
/* Decompiled from supplied 5.2.2 arm package. VA 0x21ce10. updateTime */

/* Function Stack Size: 0x10 bytes */

void YTPDiscordRPC::updateTime(ID param_1,SEL param_2)

{
  long lVar1;
  
  _objc_msgSend(param_1,@selector(media));
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0021ce98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011cde00)[lVar1 == 0] + (int)-(DAT_011cde10 ^ 0xdcfae566)))();
  return;
}



// -[YTPDiscordRPC updateState], 0x21cf58
/* Decompiled from supplied 5.2.2 arm package. VA 0x21cf58. updateState */

/* Function Stack Size: 0x10 bytes */

void YTPDiscordRPC::updateState(ID param_1,SEL param_2)

{
  long lVar1;
  
  _objc_msgSend(param_1,@selector(media));
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0021cfe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011cde38)[lVar1 == 0] + (int)-(DAT_011cde48 ^ 0x9d8eaf0f)))();
  return;
}



// -[YTPDiscordRPC clearPlayback], 0x21d0a0
/* Decompiled from supplied 5.2.2 arm package. VA 0x21d0a0. clearPlayback */

/* Function Stack Size: 0x10 bytes */

void YTPDiscordRPC::clearPlayback(ID param_1,SEL param_2)

{
  long lVar1;
  
  DAT_01228284 = 1;
  _objc_msgSend(param_1,@selector(media));
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0021d280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011cde90)[lVar1 == 0] + (int)-(DAT_011cdea0 ^ 0xa821ccc6)))();
  return;
}



// -[YTPDiscordRPC buildBody], 0x21d340
/* Decompiled from supplied 5.2.2 arm package. VA 0x21d340. buildBody */

/* Function Stack Size: 0x10 bytes */

ID YTPDiscordRPC::buildBody(ID param_1,SEL param_2)

{
  long lVar1;
  ID IVar2;
  
  DAT_01228288 = 1;
  _objc_msgSend(param_1,@selector(media));
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0021d968. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar2 = (*(code *)((&PTR_LAB_011cded0)[lVar1 == 0] + (int)-(DAT_011cdee0 ^ 0x29dbff2)))();
  return IVar2;
}



// -[YTPDiscordRPC sendBody], 0x21dc68
/* Decompiled from supplied 5.2.2 arm package. VA 0x21dc68. sendBody */

/* Function Stack Size: 0x10 bytes */

void YTPDiscordRPC::sendBody(ID param_1,SEL param_2)

{
  bool bVar1;
  long lVar2;
  undefined8 uVar3;
  undefined *puVar4;
  double dVar5;
  
  _objc_msgSend(param_1,@selector(buildBody));
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 == 0) goto LAB_0021ddc8;
  _objc_msgSend(PTR__OBJC_CLASS___NSDate_0114ebb8,@selector(date));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  bVar1 = *(long *)(param_1 + 0x10) == 0;
  puVar4 = (&PTR_LAB_011cdf08)[bVar1] + (int)-(uRam00000000011cdf18 ^ 0x98709ab4);
  if (bVar1) {
LAB_0021dda0:
    _objc_storeStrong(puVar4,(long *)(param_1 + 0x10),uVar3);
    _objc_msgSend(param_1,@selector(_send:),lVar2);
  }
  else {
    dVar5 = (double)_objc_msgSend(uVar3,@selector(timeIntervalSinceDate:));
    puVar4 = (&PTR_LAB_011cdf20)[dVar5 < 1.0] + (int)-(uRam00000000011cdf30 ^ 0x5489e549);
    if (dVar5 >= 1.0) goto LAB_0021dda0;
  }
  _objc_release(uVar3);
LAB_0021ddc8:
  (*(code *)PTR__objc_release_01061028)(lVar2);
  return;
}



// -[YTPDiscordRPC _send:], 0x21dde0
/* Decompiled from supplied 5.2.2 arm package. VA 0x21dde0. _send: */

/* Function Stack Size: 0x18 bytes */

void YTPDiscordRPC::_send_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  puVar2 = PTR__OBJC_CLASS___NSURL_0114eb78;
  puVar1 = @selector(serverURL);
  DAT_01228290 = 1;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,@selector(URLWithString:),uVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableURLRequest_0114ef80,@selector(requestWithURL:),uVar4)
  ;
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(setHTTPMethod:),@"POST")
  ;
  _objc_msgSend(0x4014000000000000,uVar3,@selector(setTimeoutInterval:));
  _objc_msgSend(uVar3,@selector(setValue:forHTTPHeaderField:),
                @"application/json",
                @"Content-Type");
  _objc_msgSend(PTR__OBJC_CLASS___NSJSONSerialization_0114ebb0,
                @selector(dataWithJSONObject:options:error:),param_3,0,0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(uVar3,@selector(setHTTPBody:),uVar5);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,@selector(sharedSession));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(dataTaskWithRequest:completionHandler:),uVar3,
                &PTR___NSConcreteGlobalBlock_01063160);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(resume));
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar3);
  _objc_release(uVar4);
  CallSupervisor(0xe178);
  return;
}



// -[YTPDiscordRPC showAlertWithMessage:showSettingsButton:], 0x21e488
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
  _objc_msgSend(uVar2,@selector(dialog));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(ytl_localized);
  _objc_msgSend(@"YouTube Plus Discord RPC",@selector(ytl_localized));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(setTitle:),uVar3);
  _objc_release(uVar3);
  _objc_msgSend(param_3,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setSubtitle:),uVar3);
  _objc_release(uVar3);
                    /* WARNING: Could not recover jumptable at 0x0021e964. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011cdfc8)[param_4] + (int)-(DAT_011cdfd8 ^ 0x79489921)))();
  return;
}



// -[YTPDiscordRPC media], 0x21eac8
/* Decompiled from supplied 5.2.2 arm package. VA 0x21eac8. media */

/* Function Stack Size: 0x10 bytes */

ID YTPDiscordRPC::media(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x18);
}



// -[YTPDiscordRPC setMedia:], 0x21ead0
/* Decompiled from supplied 5.2.2 arm package. VA 0x21ead0. setMedia: */

/* Function Stack Size: 0x18 bytes */

void YTPDiscordRPC::setMedia_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x18,param_3);
  CallSupervisor(0x1062);
  return;
}



// -[YTPDiscordRPC serverURL], 0x21eb04
/* Decompiled from supplied 5.2.2 arm package. VA 0x21eb04. serverURL */

/* Function Stack Size: 0x10 bytes */

ID YTPDiscordRPC::serverURL(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x20);
}



// -[YTPDiscordRPC .cxx_destruct], 0x21eb0c
/* Decompiled from supplied 5.2.2 arm package. VA 0x21eb0c. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void YTPDiscordRPC::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 0x20,0);
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  _objc_storeStrong(param_1 + 8,0);
  CallSupervisor(0x2a65);
  return;
}



// +[YTPDiscordRPC sharedPresence], 0x21b498
/* Decompiled from supplied 5.2.2 arm package. VA 0x21b498. sharedPresence */

/* Function Stack Size: 0x10 bytes */

ID YTPDiscordRPC::sharedPresence(ID param_1,SEL param_2)

{
  ID IVar1;
  SEL extraout_x1;
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  ID local_28;
  uint local_1c;
  undefined **local_18;
  
  local_18 = &PTR_LAB_011cdb68;
  local_48 = PTR___NSConcreteGlobalBlock_01060658;
  local_40 = DAT_00c4c2a8;
  local_38 = FUN_0021b54c;
  puStack_30 = &DAT_01062880;
  local_1c = (uint)(DAT_01228238 == -1);
  local_28 = param_1;
  if (DAT_01228238 != -1) {
    _dispatch_once((&PTR_LAB_011cdb68)[local_1c] + (int)-(DAT_011cdb78 ^ 0xc9822e42),&DAT_01228238,
                   &local_48);
    param_2 = extraout_x1;
  }
  IVar1 = (*(code *)PTR__objc_retainAutoreleaseReturnValue_01061040)(DAT_01228230,param_2);
  return IVar1;
}



// +[YTPDiscordRPC checkLocalNetworkPermission:], 0x21b590
/* Decompiled from supplied 5.2.2 arm package. VA 0x21b590. checkLocalNetworkPermission: */

/* Function Stack Size: 0x18 bytes */

void YTPDiscordRPC::checkLocalNetworkPermission_
               (ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined *local_68;
  undefined8 local_60;
  code *local_58;
  undefined *puStack_50;
  ID local_48;
  
  _objc_retain(param_3,param_2,param_3,param_4);
  puVar1 = PTR__OBJC_CLASS___NSURL_0114eb78;
  _objc_msgSend(PTR_YTPDiscordRPC_0114eac8,@selector(sharedPresence));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(serverURL));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,@selector(URLWithString:),uVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableURLRequest_0114ef80,@selector(requestWithURL:),uVar4)
  ;
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4008000000000000,uVar2,@selector(setTimeoutInterval:));
  _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,@selector(sharedSession));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(dataTaskWithRequest:completionHandler:);
  local_68 = PTR___NSConcreteStackBlock_01060660;
  local_60 = DAT_00c4c228;
  local_58 = FUN_0021b744;
  puStack_50 = &DAT_01062cf0;
  local_48 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(uVar3,puVar1,uVar2,&local_68);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,@selector(resume));
  _objc_release(uVar5);
  _objc_release(uVar3);
  _objc_release(local_48);
  _objc_release(param_3);
  _objc_release(uVar2);
  _objc_release(uVar4);
  CallSupervisor(0xad3f);
  return;
}


