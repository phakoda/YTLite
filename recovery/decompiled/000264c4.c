/* Decompiled from supplied 5.2.2 arm package. VA 0x264c4. _DVNPatreonOpenDevices */

undefined1  [16] _DVNPatreonOpenDevices(undefined8 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined1 auVar14 [16];
  
  DAT_01225dd8 = 1;
  _objc_retain(param_1);
  thunk_FUN_000236c0();
  lVar4 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_000287c0();
  uVar5 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00027078(&PTR____CFConstantStringClassReference_01157250,uVar5);
  lVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithUTF8String__0114b220,
                s_com_dvntm_ytplus_01157180);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar1 = PTR_s_URLQueryAllowedCharacterSet_0114b3c0;
  if (lVar4 != 0 && lVar6 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,
                  PTR_s_URLQueryAllowedCharacterSet_0114b3c0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_stringByAddingPercentEncodingWit_0114b3c8;
    _objc_msgSend(lVar4,PTR_s_stringByAddingPercentEncodingWit_0114b3c8,uVar7);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,puVar1);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar6,puVar2,uVar9);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,puVar1);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar2,uVar11);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_0003230c(puVar3,PTR_s_stringWithFormat__0114b378,
                       &PTR____CFConstantStringClassReference_011571d0,
                       s_https___dvntm_com_account_device_011570d0,uVar8,uVar10,uVar12);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar12);
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0,uVar13);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    uVar7 = _objc_alloc(PTR__OBJC_CLASS___ASWebAuthenticationSession_0114eb80);
    uVar9 = _objc_msgSend(uVar7,PTR_s_initWithURL_callbackURLScheme_co_0114b3f8,uVar8,
                          &PTR____CFConstantStringClassReference_01157210,
                          &PTR___NSConcreteGlobalBlock_01061520);
    uVar7 = DAT_01225d18;
    DAT_01225d18 = uVar9;
    _objc_release(uVar7);
    _objc_msgSend(DAT_01225d18,PTR_s_setPrefersEphemeralWebBrowserSes_0114b400,0);
    _objc_msgSend(DAT_01225d18,PTR_s_setPresentationContextProvider__0114b408,param_1);
    FUN_000323f0(DAT_01225d18,PTR_s_start_0114b410);
    _objc_release(uVar8);
    _objc_release(uVar13);
  }
  _objc_release(uVar5);
  _objc_release(lVar6);
  _objc_release(lVar4);
  _objc_release(param_1);
  CallSupervisor(0xad08);
  auVar14._8_8_ = 0x1f;
  auVar14._0_8_ = 0x1a;
  return auVar14;
}


