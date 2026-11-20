/* Decompiled from supplied 5.2.2 arm package. VA 0x1cf770. playAudio */

/* Function Stack Size: 0x10 bytes */

void AudioManager::playAudio(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  
  puVar1 = PTR_s_audioPlayer_0114dfa0;
  _objc_msgSend(param_1,PTR_s_audioPlayer_0114dfa0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_001cfcb8(uVar3,PTR_s_isPlaying_0114dfb0);
  _objc_release(uVar3);
  if (uVar2 == 0) {
    _objc_msgSend((&PTR_LAB_011b6560)[uVar2] + (int)-(DAT_011b6570 ^ 0x291abf53),param_1,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    FUN_001cfd00(uVar3,PTR_s_play_0114c460);
    _objc_release(uVar3);
  }
  CallSupervisor(0x7b00);
  return;
}


