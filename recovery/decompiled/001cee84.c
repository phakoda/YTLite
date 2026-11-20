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
  IVar4 = _objc_msgSendSuper2(&IStack_d0,PTR_s_init_0114d960);
  uStack_74 = (uint)(IVar4 == 0);
  if (IVar4 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___AVAudioSession_0114ed08,PTR_s_sharedInstance_0114c418);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    alStack_e0[0] = 0;
    FUN_001cfc70(uVar5,PTR_s_setCategory_withOptions_error__0114c420,
                 *(undefined8 *)PTR__AVAudioSessionCategoryPlayback_01060000,1,alStack_e0);
    lVar3 = alStack_e0[0];
    _objc_retain(alStack_e0[0]);
    _objc_release(uVar5);
    uStack_84 = (uint)(lVar3 == 0);
    if (lVar3 != 0) {
      _objc_msgSend(local_80[uStack_84] + (int)-(uRam00000000011b6520 ^ 0x429d472d),lVar3,
                    PTR_s_localizedDescription_0114c618);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      thunk_FUN_001cfb04(&PTR____CFConstantStringClassReference_011b6410,uVar5);
      _objc_release(uVar5);
    }
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_pathForResource_ofType__0114df88,
                  &PTR____CFConstantStringClassReference_011b63d0,
                  &PTR____CFConstantStringClassReference_011b6350);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_fileURLWithPath__0114c430,uVar6);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar7 = _objc_alloc(PTR__OBJC_CLASS___AVAudioPlayer_0114efa0);
    alStack_f0[0] = lVar3;
    uVar7 = _objc_msgSend(uVar7,PTR_s_initWithContentsOfURL_error__0114df90,uVar5,alStack_f0);
    lVar2 = alStack_f0[0];
    _objc_retain(alStack_f0[0]);
    _objc_release(lVar3);
    _objc_msgSend(IVar4,PTR_s_setAudioPlayer__0114df98,uVar7);
    _objc_release(uVar7);
    puVar1 = PTR_s_audioPlayer_0114dfa0;
    uStack_9c = (uint)(lVar2 == 0);
    if (lVar2 != 0) {
      _objc_msgSend(local_98[uStack_9c] + (int)-(uRam00000000011b6540 ^ 0xacb3d327),lVar2,
                    PTR_s_localizedDescription_0114c618);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      thunk_FUN_001cfc10(&PTR____CFConstantStringClassReference_011b6390,uVar7);
      _objc_release(uVar7);
      _objc_release(uVar5);
      _objc_release(uVar6);
      _objc_release(lVar2);
      IVar8 = 0;
      goto LAB_001cf748;
    }
    _objc_msgSend(IVar4,PTR_s_audioPlayer_0114dfa0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_setDelegate__0114b7d8,IVar4);
    _objc_release(uVar7);
    _objc_msgSend(IVar4,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    FUN_001cfab0(uVar7,PTR_s_prepareToPlay_0114dfa8);
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


