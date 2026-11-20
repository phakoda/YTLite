/* Decompiled from supplied 5.2.2 arm package. VA 0x194c24. shouldCheckSponsorBlock */

/* Function Stack Size: 0x10 bytes */

bool SBPlaybackController::shouldCheckSponsorBlock(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  bool bVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined *puVar10;
  double dVar11;
  
  puVar3 = PTR_s_boolForKey__0114ada8;
  DAT_01227834 = 1;
  uVar4 = FUN_001989cc(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_011a9da0);
  puVar10 = (&PTR_LAB_011aaa80)[uVar4] + (int)-(DAT_011aaa90 ^ 0x911b0a18);
  if (uVar4 == 0) {
    uVar6 = _objc_loadWeakRetained(puVar10,param_1 + 8);
    puVar1 = PTR_s_parentViewController_0114ad68;
    _objc_msgSend(uVar6,PTR_s_parentViewController_0114ad68);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar8 = _objc_getClass(s_YTWatchViewController_011a9cb0);
    puVar2 = PTR_s_isKindOfClass__0114ad70;
    uVar4 = FUN_00198ba4(uVar7,PTR_s_isKindOfClass__0114ad70,uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    puVar10 = (&PTR_LAB_011aaa98)[uVar4] + (int)-(uRam00000000011aaaa8 ^ 0xfb9621c8);
    if (uVar4 == 0) {
      uVar4 = FUN_00198c0c(puVar10,PTR_YTLUserDefaults_0114ead8,puVar3,
                           &PTR____CFConstantStringClassReference_011a9d60);
      puVar10 = (&PTR_LAB_011aaab0)[uVar4] + (int)-(uRam00000000011aaac0 ^ 0x9a413644);
      if (uVar4 == 0) {
        uVar6 = _objc_loadWeakRetained(puVar10,param_1 + 8);
        _objc_msgSend(uVar6,puVar1);
        uVar7 = _objc_retainAutoreleasedReturnValue();
        uVar8 = _objc_getClass(s_YTWatchMiniBarViewController_011a9c70);
        uVar4 = FUN_00198b3c(uVar7,puVar2,uVar8);
        _objc_release(uVar7);
        _objc_release(uVar6);
        puVar10 = (&PTR_LAB_011aaac8)[uVar4] + (int)-(uRam00000000011aaad8 ^ 0xa6122f68);
        if (uVar4 == 0) {
          return 0;
        }
      }
    }
  }
  uVar6 = _objc_loadWeakRetained(puVar10,param_1 + 8);
  _objc_msgSend(uVar6,PTR_s_contentVideoID_0114cef0);
  lVar9 = _objc_retainAutoreleasedReturnValue();
  if (lVar9 == 0) {
    _objc_release((&PTR_LAB_011aaae0)[lVar9 == 0] + (int)-(uRam00000000011aaaf0 ^ 0xc55c4806),uVar6)
    ;
    return 0;
  }
  uVar7 = _objc_loadWeakRetained(param_1 + 8);
  dVar11 = (double)_objc_msgSend(uVar7,PTR_s_currentVideoMediaTime_0114dab0);
  _objc_release(uVar7);
  _objc_release(lVar9);
  _objc_release(uVar6);
                    /* WARNING: Could not recover jumptable at 0x001954b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  bVar5 = (*(code *)((&PTR_LAB_011aaaf8)[dVar11 == 0.0] + (int)-(uRam00000000011aab08 ^ 0xfd59f773))
          )();
  return bVar5;
}


