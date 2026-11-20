/* Decompiled from supplied 5.2.2 arm package. VA 0x198608. playSkipAudioIfNeeded */

/* Function Stack Size: 0x10 bytes */

void SBPlaybackController::playSkipAudioIfNeeded(ID param_1,SEL param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01227878 = 1;
  iVar1 = FUN_001997f4(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_011aa750);
  if (iVar1 != 0) {
    _objc_msgSend(PTR_AudioManager_0114eef0,PTR_s_sharedInstance_0114c418);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_playAudio_0114db20);
    _objc_release(uVar2);
  }
  CallSupervisor(0x4a51);
  return;
}


