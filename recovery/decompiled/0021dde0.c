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
  puVar1 = PTR_s_serverURL_0114e588;
  DAT_01228290 = 1;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,PTR_s_URLWithString__0114b3d0,uVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableURLRequest_0114ef80,PTR_s_requestWithURL__0114da38,uVar4)
  ;
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setHTTPMethod__0114dee8,&PTR____CFConstantStringClassReference_011cd720)
  ;
  _objc_msgSend(0x4014000000000000,uVar3,PTR_s_setTimeoutInterval__0114e590);
  _objc_msgSend(uVar3,PTR_s_setValue_forHTTPHeaderField__0114def0,
                &PTR____CFConstantStringClassReference_011cd6e0,
                &PTR____CFConstantStringClassReference_011cd6a0);
  _objc_msgSend(PTR__OBJC_CLASS___NSJSONSerialization_0114ebb0,
                PTR_s_dataWithJSONObject_options_error_0114b4f0,param_3,0,0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(uVar3,PTR_s_setHTTPBody__0114def8,uVar5);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,PTR_s_sharedSession_0114d910);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_dataTaskWithRequest_completionHa_0114db40,uVar3,
                &PTR___NSConcreteGlobalBlock_01063160);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_resume_0114d928);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar3);
  _objc_release(uVar4);
  CallSupervisor(0xe178);
  return;
}


