/* Decompiled from supplied 5.2.2 arm package. VA 0x19b24. FUN_00019b24 */

undefined1  [16] FUN_00019b24(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  DAT_01225bb4 = 1;
  uVar1 = _objc_getClass(s_NSMutableURLRequest_011547f0);
  uVar2 = _object_getClass();
  _MSHookMessageEx(uVar2,PTR_s_ak_clientInfoHeader_0114b150,FUN_0001ad14,&DAT_01225a68);
  _MSHookMessageEx(uVar1,PTR_s_allHTTPHeaderFields_0114b158,FUN_0001b16c,&DAT_01225a70);
  uVar1 = _objc_getClass(s_LSApplicationProxy_011546b0);
  _MSHookMessageEx(uVar1,PTR_s_teamID_0114b160,FUN_0001b564,&DAT_01225a78);
  _MSHookMessageEx(uVar1,PTR_s_appIDPrefix_0114b168,FUN_0001b688,&DAT_01225a80);
  _MSHookMessageEx(uVar1,PTR_s_applicationIdentifier_0114b170,FUN_0001b7b0,&DAT_01225a88);
  uVar1 = _objc_getClass(s_LSBundleProxy_0115475c);
  _MSHookMessageEx(uVar1,PTR_s_bundleIdentifier_0114b110,FUN_0001ba30,&DAT_01225a90);
  uVar1 = _objc_getClass(s_YTIIosPlayerAttestationConfig_01154670);
  _MSHookMessageEx(uVar1,PTR_s_iosguardEnable_0114b178,FUN_0001bcb8,&DAT_01225a98);
  _MSHookMessageEx(uVar1,PTR_s_hasIosguardEnable_0114b180,FUN_0001bcc0,&DAT_01225aa0);
  uVar1 = _objc_getClass(s_YTIHeartbeatAttestationConfig_01154730);
  _MSHookMessageEx(uVar1,PTR_s_requiresAttestation_0114b188,FUN_0001bcc8,&DAT_01225aa8);
  _MSHookMessageEx(uVar1,PTR_s_hasRequiresAttestation_0114b190,FUN_0001bcd0,&DAT_01225ab0);
  uVar1 = _objc_getClass(s_YTIIosPlayerConfig_01154630);
  _MSHookMessageEx(uVar1,PTR_s_heartbeatPolicyErrorIsNonFatal_0114b198,FUN_0001bcd8,&DAT_01225ab8);
  _MSHookMessageEx(uVar1,PTR_s_hasHeartbeatPolicyErrorIsNonFata_0114b1a0,FUN_0001bce0,&DAT_01225ac0)
  ;
  _MSHookMessageEx(uVar1,PTR_s_requestIosguardDataAfterPlayback_0114b1a8,FUN_0001bce8,&DAT_01225ac8)
  ;
  _MSHookMessageEx(uVar1,PTR_s_hasRequestIosguardDataAfterPlayb_0114b1b0,FUN_0001bcf0,&DAT_01225ad0)
  ;
  uVar1 = _objc_getClass(s_YTIHeartbeatResponse_011546f0);
  _MSHookMessageEx(uVar1,PTR_s_stopHeartbeat_0114b1b8,FUN_0001bcf8,&DAT_01225ad8);
  _MSHookMessageEx(uVar1,PTR_s_hasStopHeartbeat_0114b1c0,FUN_0001bd00,&DAT_01225ae0);
  _MSHookMessageEx(uVar1,PTR_s_authenticationMismatch_0114b1c8,FUN_0001bd08,&DAT_01225ae8);
  _MSHookMessageEx(uVar1,PTR_s_hasAuthenticationMismatch_0114b1d0,FUN_0001bd10,&DAT_01225af0);
  uVar1 = _objc_getClass(s_YTSingleVideoHeartbeatController_011547a0);
  _MSHookMessageEx(uVar1,PTR_s_haltIfNeeded_0114b1d8,FUN_0001bd18,&DAT_01225af8);
  uVar1 = _objc_getClass(s_YTPlaybackHeartbeatController_011545f0);
  _MSHookMessageEx(uVar1,PTR_s_haltPlaybackWithError_forHeartbe_0114b1e0,FUN_0001bd1c,&DAT_01225b00)
  ;
  uVar1 = _objc_getClass(s_MDXLocalNetworkPermissions_011545b0);
  _MSHookMessageEx(uVar1,PTR_s_lastKnownPermissionsStatus_0114b1e8,FUN_0001bd20,&DAT_01225b08);
  _MSHookMessageEx(uVar1,PTR_s_isAuthorized_0114b1f0,FUN_0001bd28,&DAT_01225b10);
  _MSHookMessageEx(uVar1,PTR_s_localNetworkPermissionCheckRequi_0114b1f8,FUN_0001bd30,&DAT_01225b18)
  ;
  _MSHookMessageEx(uVar1,PTR_s_verifyAccessWithCompletion__0114b200,FUN_0001bd38,&DAT_01225b20);
  CallSupervisor(0x3c8b);
  return ZEXT816(0x1f);
}


