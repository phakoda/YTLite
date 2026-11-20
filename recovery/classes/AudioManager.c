// Decompiled implementation evidence for AudioManager. Not compilable source.

// -[AudioManager init], 0x1cee84
/* Decompiled from supplied 5.2.2 arm package. VA 0x1cee84. init */

/* Function Stack Size: 0x10 bytes */

ID AudioManager::init(ID param_1,SEL param_2)

{
  undefined *puVar1;
  long lVar2;
  long lVar3;
  ID IVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ID IVar8;
  long alStack_f0 [2];
  long alStack_e0 [2];
  ID IStack_d0;
  undefined *puStack_c8;
  undefined **local_b8;
  undefined **local_b0;
  undefined **ppuStack_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **local_90;
  uint uStack_84;
  undefined **local_80;
  uint uStack_74;
  undefined **local_70;
  undefined **local_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011b64d8;
  local_5c = (uint)(DAT_01227d38 == 0);
  local_70 = &PTR_LAB_011b64f8;
  local_80 = &PTR_LAB_011b6510;
  local_98 = &PTR_LAB_011b6530;
  local_68 = &PTR_LAB_011b6430;
  local_90 = &PTR_LAB_011b6430;
  local_b0 = &PTR_LAB_011b6430;
  ppuStack_a8 = &PTR_LAB_011b6430;
  local_b8 = &PTR_LAB_011b6430;
  DAT_01227d38 = 1;
  puStack_c8 = PTR_AudioManager_0114f108;
  IStack_d0 = param_1;
  IVar4 = _objc_msgSendSuper2(&IStack_d0,@selector(init));
  uStack_74 = (uint)(IVar4 == 0);
  if (IVar4 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___AVAudioSession_0114ed08,@selector(sharedInstance));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    alStack_e0[0] = 0;
    FUN_001cfc70(uVar5,@selector(setCategory:withOptions:error:),
                 *(undefined8 *)PTR__AVAudioSessionCategoryPlayback_01060000,1,alStack_e0);
    lVar3 = alStack_e0[0];
    _objc_retain(alStack_e0[0]);
    _objc_release(uVar5);
    uStack_84 = (uint)(lVar3 == 0);
    if (lVar3 != 0) {
      _objc_msgSend(local_80[uStack_84] + (int)-(uRam00000000011b6520 ^ 0x429d472d),lVar3,
                    @selector(localizedDescription));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      thunk_FUN_001cfb04(@"DVN --- Unable to set category: %@",uVar5);
      _objc_release(uVar5);
    }
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(pathForResource:ofType:),
                  @"SponsorAudio",
                  @"m4a");
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,@selector(fileURLWithPath:),uVar6);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar7 = _objc_alloc(PTR__OBJC_CLASS___AVAudioPlayer_0114efa0);
    alStack_f0[0] = lVar3;
    uVar7 = _objc_msgSend(uVar7,@selector(initWithContentsOfURL:error:),uVar5,alStack_f0);
    lVar2 = alStack_f0[0];
    _objc_retain(alStack_f0[0]);
    _objc_release(lVar3);
    _objc_msgSend(IVar4,@selector(setAudioPlayer:),uVar7);
    _objc_release(uVar7);
    puVar1 = @selector(audioPlayer);
    uStack_9c = (uint)(lVar2 == 0);
    if (lVar2 != 0) {
      _objc_msgSend(local_98[uStack_9c] + (int)-(uRam00000000011b6540 ^ 0xacb3d327),lVar2,
                    @selector(localizedDescription));
      uVar7 = _objc_retainAutoreleasedReturnValue();
      thunk_FUN_001cfc10(@"DVN --- Unable to init player: %@",uVar7);
      _objc_release(uVar7);
      _objc_release(uVar5);
      _objc_release(uVar6);
      _objc_release(lVar2);
      IVar8 = 0;
      goto LAB_001cf748;
    }
    _objc_msgSend(IVar4,@selector(audioPlayer));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(setDelegate:),IVar4);
    _objc_release(uVar7);
    _objc_msgSend(IVar4,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    FUN_001cfab0(uVar7,@selector(prepareToPlay));
    _objc_release(uVar7);
    _objc_release(uVar5);
    _objc_release(uVar6);
  }
  _objc_retain(IVar4);
  IVar8 = IVar4;
LAB_001cf748:
  _objc_release(IVar4);
  return IVar8;
}



// -[AudioManager playAudio], 0x1cf770
/* Decompiled from supplied 5.2.2 arm package. VA 0x1cf770. playAudio */

/* Function Stack Size: 0x10 bytes */

void AudioManager::playAudio(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  
  puVar1 = @selector(audioPlayer);
  _objc_msgSend(param_1,@selector(audioPlayer));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_001cfcb8(uVar3,@selector(isPlaying));
  _objc_release(uVar3);
  if (uVar2 == 0) {
    _objc_msgSend((&PTR_LAB_011b6560)[uVar2] + (int)-(DAT_011b6570 ^ 0x291abf53),param_1,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    FUN_001cfd00(uVar3,@selector(play));
    _objc_release(uVar3);
  }
  CallSupervisor(0x7b00);
  return;
}



// -[AudioManager stopAudio], 0x1cf858
/* Decompiled from supplied 5.2.2 arm package. VA 0x1cf858. stopAudio */

/* Function Stack Size: 0x10 bytes */

void AudioManager::stopAudio(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  
  puVar1 = @selector(audioPlayer);
  _objc_msgSend(param_1,@selector(audioPlayer));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_001cfd48(uVar3,@selector(isPlaying));
  _objc_release(uVar3);
  if (uVar2 != 0) {
    _objc_msgSend((&PTR_LAB_011b6580)[uVar2] + (int)-(DAT_011b6590 ^ 0xb55d3f89),param_1,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(stop));
    _objc_release(uVar3);
    _objc_msgSend(param_1,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(0,uVar3,@selector(setCurrentTime:));
    _objc_release(uVar3);
  }
  CallSupervisor(0xfa53);
  return;
}



// -[AudioManager audioPlayerDidFinishPlaying:successfully:], 0x1cf970
/* Decompiled from supplied 5.2.2 arm package. VA 0x1cf970. audioPlayerDidFinishPlaying:successfully: */

/* Function Stack Size: 0x1c bytes */

void AudioManager::audioPlayerDidFinishPlaying_successfully_
               (ID param_1,SEL param_2,ID param_3,bool param_4)

{
  CallSupervisor(0xa80a);
  return;
}



// -[AudioManager audioPlayer], 0x1cf98c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1cf98c. audioPlayer */

/* Function Stack Size: 0x10 bytes */

ID AudioManager::audioPlayer(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 8);
}



// -[AudioManager setAudioPlayer:], 0x1cf994
/* Decompiled from supplied 5.2.2 arm package. VA 0x1cf994. setAudioPlayer: */

/* Function Stack Size: 0x18 bytes */

void AudioManager::setAudioPlayer_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 8,param_3);
  CallSupervisor(0x219c);
  return;
}



// -[AudioManager .cxx_destruct], 0x1cf9c8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1cf9c8. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void AudioManager::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 8,0);
  CallSupervisor(0xf894);
  return;
}



// +[AudioManager sharedInstance], 0x1ced8c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ced8c. sharedInstance */

/* Function Stack Size: 0x10 bytes */

ID AudioManager::sharedInstance(ID param_1,SEL param_2)

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
  
  local_18 = &PTR_LAB_011b64b0;
  local_48 = PTR___NSConcreteGlobalBlock_01060658;
  local_40 = DAT_00c4c2a8;
  local_38 = FUN_001cee40;
  puStack_30 = &DAT_01062880;
  local_1c = (uint)(DAT_01227d28 == -1);
  local_28 = param_1;
  if (DAT_01227d28 != -1) {
    _dispatch_once((&PTR_LAB_011b64b0)[local_1c] + (int)-(DAT_011b64c0 ^ 0xbd877638),&DAT_01227d28,
                   &local_48);
    param_2 = extraout_x1;
  }
  IVar1 = (*(code *)PTR__objc_retainAutoreleaseReturnValue_01061040)(DAT_01227d20,param_2);
  return IVar1;
}


