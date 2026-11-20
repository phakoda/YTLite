/* Decompiled from supplied 5.2.2 arm package. VA 0x1cf858. stopAudio */

/* Function Stack Size: 0x10 bytes */

void AudioManager::stopAudio(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  
  puVar1 = PTR_s_audioPlayer_0114dfa0;
  _objc_msgSend(param_1,PTR_s_audioPlayer_0114dfa0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_001cfd48(uVar3,PTR_s_isPlaying_0114dfb0);
  _objc_release(uVar3);
  if (uVar2 != 0) {
    _objc_msgSend((&PTR_LAB_011b6580)[uVar2] + (int)-(DAT_011b6590 ^ 0xb55d3f89),param_1,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_stop_0114dfb8);
    _objc_release(uVar3);
    _objc_msgSend(param_1,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(0,uVar3,PTR_s_setCurrentTime__0114adb0);
    _objc_release(uVar3);
  }
  CallSupervisor(0xfa53);
  return;
}


