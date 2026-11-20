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
  _objc_msgSend(PTR_YTPDiscordRPC_0114eac8,PTR_s_sharedPresence_0114ad78);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_serverURL_0114e588);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_URLWithString__0114b3d0,uVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableURLRequest_0114ef80,PTR_s_requestWithURL__0114da38,uVar4)
  ;
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4008000000000000,uVar2,PTR_s_setTimeoutInterval__0114e590);
  _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,PTR_s_sharedSession_0114d910);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_dataTaskWithRequest_completionHa_0114db40;
  local_68 = PTR___NSConcreteStackBlock_01060660;
  local_60 = DAT_00c4c228;
  local_58 = FUN_0021b744;
  puStack_50 = &DAT_01062cf0;
  local_48 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(uVar3,puVar1,uVar2,&local_68);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_resume_0114d928);
  _objc_release(uVar5);
  _objc_release(uVar3);
  _objc_release(local_48);
  _objc_release(param_3);
  _objc_release(uVar2);
  _objc_release(uVar4);
  CallSupervisor(0xad3f);
  return;
}


