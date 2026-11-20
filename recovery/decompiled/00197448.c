/* Decompiled from supplied 5.2.2 arm package. VA 0x197448. showSkippedToast:undoTime: */

/* Function Stack Size: 0x20 bytes */

void SBPlaybackController::showSkippedToast_undoTime_
               (ID param_1,SEL param_2,ID param_3,double param_4)

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
  undefined *puStack_d0;
  undefined8 uStack_c8;
  code *pcStack_c0;
  undefined *puStack_b8;
  ID IStack_b0;
  double dStack_a8;
  undefined **local_a0;
  int iStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  
  local_78 = &PTR_LAB_011aaf10;
  local_7c = (uint)(DAT_01227858 == 0);
  local_90 = &PTR_LAB_011aaf30;
  ppuStack_88 = &PTR__objc_msgSend_011aa770;
  local_a0 = &PTR__objc_msgSend_011aa770;
  DAT_01227858 = 1;
  _objc_retain(param_3);
  iStack_94 = FUN_00199564(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                           &PTR____CFConstantStringClassReference_011aa430);
  puVar2 = PTR__OBJC_CLASS___NSString_0114eb38;
  if (iStack_94 != 0) {
    _objc_msgSend(param_3,PTR_s_category_0114dad0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_stringWithFormat__0114b378;
    thunk_FUN_00199418(puVar2,PTR_s_stringWithFormat__0114b378,
                       &PTR____CFConstantStringClassReference_011aa3f0,uVar4);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    uVar11 = _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_floatForKey__0114c308,
                           &PTR____CFConstantStringClassReference_011aa3b0);
    uVar4 = _objc_alloc_init(PTR_ToastView_0114ec98);
    puVar3 = PTR__OBJC_CLASS___NSString_0114eb38;
    puVar2 = PTR_s_ytl_localized_0114d190;
    _objc_msgSend(&PTR____CFConstantStringClassReference_011aa370,PTR_s_ytl_localized_0114d190);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar2);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_001994c4(puVar3,puVar1,uVar6,uVar7);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,PTR_s_imageWithName__0114c5b0,
                  &PTR____CFConstantStringClassReference_011aa330);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    puStack_d0 = PTR___NSConcreteStackBlock_01060660;
    uStack_c8 = DAT_00c4c228;
    pcStack_c0 = FUN_00197b84;
    puStack_b8 = &DAT_01061810;
    IStack_b0 = param_1;
    dStack_a8 = param_4;
    _objc_msgSend(uVar11,uVar4,PTR_s_showProgressiveToastWithText_dur_0114db18,uVar8,uVar10,
                  &puStack_d0);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_release(uVar5);
  }
  _objc_release(param_3);
  CallSupervisor(0x5500);
  return;
}


