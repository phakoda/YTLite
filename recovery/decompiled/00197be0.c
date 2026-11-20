/* Decompiled from supplied 5.2.2 arm package. VA 0x197be0. showSkipPromptToast:timeBeforeSkip:target: */

/* Function Stack Size: 0x28 bytes */

void SBPlaybackController::showSkipPromptToast_timeBeforeSkip_target_
               (ID param_1,SEL param_2,ID param_3,double param_4,double param_5)

{
  undefined **ppuVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined *puStack_100;
  undefined8 uStack_f8;
  code *pcStack_f0;
  undefined *puStack_e8;
  ID IStack_e0;
  ID IStack_d8;
  double dStack_d0;
  double dStack_c8;
  ID IStack_b8;
  undefined **local_b0;
  int iStack_a4;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint local_8c;
  undefined **local_88;
  
  local_88 = &PTR_LAB_011aaf50;
  local_8c = (uint)(DAT_01227868 == 0);
  local_a0 = &PTR_LAB_011aaf70;
  ppuStack_98 = &PTR__objc_msgSend_011aa770;
  local_b0 = &PTR__objc_msgSend_011aa770;
  DAT_01227868 = 1;
  _objc_retain(param_3);
  iStack_a4 = FUN_0019976c(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                           &PTR____CFConstantStringClassReference_011aa700);
  puVar4 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar3 = PTR_s_category_0114dad0;
  if (iStack_a4 != 0) {
    IStack_b8 = param_1;
    _objc_msgSend(param_3,PTR_s_category_0114dad0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_stringWithFormat__0114b378;
    thunk_FUN_001995b8(puVar4,PTR_s_stringWithFormat__0114b378,
                       &PTR____CFConstantStringClassReference_011aa680,uVar6);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    uVar14 = _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_floatForKey__0114c308,
                           &PTR____CFConstantStringClassReference_011aa640);
    _objc_msgSend(param_3,puVar3);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    iVar5 = FUN_00199638(uVar6,PTR_s_isEqualToString__0114ae48,
                         &PTR____CFConstantStringClassReference_011aa600);
    _objc_release(uVar6);
    puVar3 = PTR_ToastView_0114ec98;
    ppuVar1 = &PTR____CFConstantStringClassReference_011aa6c0;
    if (iVar5 == 0) {
      ppuVar1 = &PTR____CFConstantStringClassReference_011aa580;
    }
    _objc_retain(ppuVar1);
    uVar6 = _objc_alloc_init(puVar3);
    puVar4 = PTR__OBJC_CLASS___NSString_0114eb38;
    puVar3 = PTR_s_ytl_localized_0114d190;
    _objc_msgSend(&PTR____CFConstantStringClassReference_011aa540,PTR_s_ytl_localized_0114d190);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puVar3);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(ppuVar1,puVar3);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_release(ppuVar1);
    thunk_FUN_001996cc(puVar4,puVar2,uVar8,uVar9,uVar10);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar12,PTR_s_imageWithName__0114c5b0,
                  &PTR____CFConstantStringClassReference_011aa5c0);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    puStack_100 = PTR___NSConcreteStackBlock_01060660;
    uStack_f8 = DAT_00c4c228;
    pcStack_f0 = FUN_001985c4;
    puStack_e8 = &DAT_01062850;
    IStack_e0 = IStack_b8;
    dStack_d0 = param_5;
    _objc_retain(param_3);
    IStack_d8 = param_3;
    dStack_c8 = param_4;
    _objc_msgSend(uVar14,uVar6,PTR_s_showProgressiveToastWithText_dur_0114db18,uVar11,uVar13,
                  &puStack_100);
    _objc_release(uVar13);
    _objc_release(uVar12);
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar6);
    _objc_release(IStack_d8);
    _objc_release(uVar7);
  }
  _objc_release(param_3);
  return;
}


