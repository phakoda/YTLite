/* Decompiled from supplied 5.2.2 arm package. VA 0x23ef0. _DVNPatreonLogin */

undefined1  [16] _DVNPatreonLogin(undefined8 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined1 auVar17 [16];
  
  DAT_01225db8 = 1;
  _objc_retain(param_1);
  thunk_FUN_0002495c();
  uVar4 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00024f34();
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIDevice_0114eb58,PTR_s_currentDevice_0114b2b0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_systemVersion_0114b3b8);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar6);
  _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithUTF8String__0114b220,
                s_com_dvntm_ytplus_01156ac0);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar1 = PTR_s_URLQueryAllowedCharacterSet_0114b3c0;
  _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,PTR_s_URLQueryAllowedCharacterSet_0114b3c0
               );
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_stringByAddingPercentEncodingWit_0114b3c8;
  _objc_msgSend(uVar4,PTR_s_stringByAddingPercentEncodingWit_0114b3c8,uVar6);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,puVar1);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar2,uVar10);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,puVar2,uVar12);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,puVar1);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar2,uVar14);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_000317bc(puVar3,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_01156b40,
                     s_https___dvntm_com_api_account_lo_01156a70,uVar9,uVar11,uVar13,uVar15);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar15);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar6);
  _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0,uVar16);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  uVar6 = _objc_alloc(PTR__OBJC_CLASS___ASWebAuthenticationSession_0114eb80);
  uVar10 = _objc_msgSend(uVar6,PTR_s_initWithURL_callbackURLScheme_co_0114b3f8,uVar9,
                         &PTR____CFConstantStringClassReference_01156b00,
                         &PTR___NSConcreteGlobalBlock_010614e0);
  uVar6 = DAT_01225d18;
  DAT_01225d18 = uVar10;
  _objc_release(uVar6);
  _objc_msgSend(DAT_01225d18,PTR_s_setPrefersEphemeralWebBrowserSes_0114b400,0);
  _objc_msgSend(DAT_01225d18,PTR_s_setPresentationContextProvider__0114b408,param_1);
  _objc_release(param_1);
  FUN_000318a4(DAT_01225d18,PTR_s_start_0114b410);
  _objc_release(uVar9);
  _objc_release(uVar16);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar5);
  _objc_release(uVar4);
  CallSupervisor(0x65fa);
  auVar17._8_8_ = 0x1f;
  auVar17._0_8_ = 0x1a;
  return auVar17;
}


