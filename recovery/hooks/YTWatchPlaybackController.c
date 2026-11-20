// Decompiled hook evidence for YTWatchPlaybackController. This is not compilable Logos source.

// -[YTWatchPlaybackController playbackControllerDidPlay], original IMP slot 0x1225880
/* Decompiled from supplied 5.2.2 arm package. VA 0xad54. FUN_0000ad54 */

undefined1  [16] FUN_0000ad54(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_012258c0 = 1;
  iVar1 = FUN_0000c1e0(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                       @"discordRPC");
  if (iVar1 != 0) {
    _objc_msgSend(PTR_YTPDiscordRPC_0114eac8,@selector(sharedPresence));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(media));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(setIsPaused:),0);
    _objc_release(uVar3);
    _objc_msgSend(uVar2,@selector(updateState));
    _objc_release(uVar2);
  }
  (*pcRam0000000001225880)(param_1,param_2);
  CallSupervisor(0x77f4);
  return ZEXT816(0x1f);
}



// -[YTWatchPlaybackController playbackControllerDidPause], original IMP slot 0x01225888
/* Decompiled from supplied 5.2.2 arm package. VA 0xaf78. FUN_0000af78 */

undefined1  [16] FUN_0000af78(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_012258c4 = 1;
  iVar1 = FUN_0000c308(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                       @"discordRPC");
  if (iVar1 != 0) {
    _objc_msgSend(PTR_YTPDiscordRPC_0114eac8,@selector(sharedPresence));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(media));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(setIsPaused:),1);
    _objc_release(uVar3);
    _objc_msgSend(uVar2,@selector(updateState));
    _objc_release(uVar2);
  }
  (*DAT_01225888)(param_1,param_2);
  CallSupervisor(0x963b);
  return ZEXT816(0x1f);
}



// -[YTWatchPlaybackController playbackControllerDidFinishPlaybackAndWillTransitionInternallyToNextPlayback:], original IMP slot 0x01225890
/* Decompiled from supplied 5.2.2 arm package. VA 0xb19c. FUN_0000b19c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0000b19c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_012258c8 = 1;
  iVar1 = FUN_0000c330(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                       @"discordRPC");
  if (iVar1 != 0) {
    _objc_msgSend(PTR_YTPDiscordRPC_0114eac8,@selector(sharedPresence));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(clearPlayback));
    _objc_release(uVar2);
  }
  (*_DAT_01225890)(param_1,param_2,param_3);
  CallSupervisor(0x17b5);
  return ZEXT816(0x1f);
}



// -[YTWatchPlaybackController clearPlaybackController], original IMP slot 0x01225898
/* Decompiled from supplied 5.2.2 arm package. VA 0xb3a0. FUN_0000b3a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0000b3a0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_012258cc = 1;
  iVar1 = FUN_0000c3d8(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                       @"discordRPC");
  if (iVar1 != 0) {
    _objc_msgSend(PTR_YTPDiscordRPC_0114eac8,@selector(sharedPresence));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(clearPlayback));
    _objc_release(uVar2);
  }
  (*_DAT_01225898)(param_1,param_2);
  CallSupervisor(0x84d9);
  return ZEXT816(0x1f);
}


