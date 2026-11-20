/* Decompiled from supplied 5.2.2 arm package. VA 0x19ce04. _decorationDataForBarView: */

/* Function Stack Size: 0x18 bytes */

ID SBPlayerDecorator::_decorationDataForBarView_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  ID IVar11;
  undefined8 in_d2;
  
  DAT_012278d8 = 1;
  _objc_retain(param_3);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  iVar3 = FUN_001a1a50(uVar5,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_011abc50);
  _objc_release(uVar5);
  puVar1 = PTR_s__viewControllerForAncestor_0114ade0;
  uVar5 = 0;
  if (iVar3 != 0) {
    _objc_msgSend(param_3,PTR_s__viewControllerForAncestor_0114ade0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar6 = _NSClassFromString(&PTR____CFConstantStringClassReference_011abc10);
    puVar2 = PTR_s_isKindOfClass__0114ad70;
    uVar4 = FUN_001a1908(uVar5,PTR_s_isKindOfClass__0114ad70,uVar6);
    _objc_release(uVar5);
    uVar5 = 0;
    if (uVar4 != 0) {
      _objc_msgSend((&PTR_LAB_011ac848)[uVar4] + (int)-(uRam00000000011ac858 ^ 0x2115012f),param_3,
                    puVar1);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      puVar1 = PTR_s_parentViewController_0114ad68;
      _objc_msgSend(uVar6,PTR_s_parentViewController_0114ad68);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      uVar7 = _NSClassFromString(&PTR____CFConstantStringClassReference_011abbd0);
      uVar4 = FUN_001a1b78(uVar5,puVar2,uVar7);
      _objc_release(uVar5);
      if (uVar4 == 0) {
        uVar5 = 0;
      }
      else {
        _objc_msgSend((&PTR_LAB_011ac860)[uVar4] + (int)-(uRam00000000011ac870 ^ 0xae4747a7),uVar6,
                      puVar1);
        uVar7 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(PTR_SBManager_0114eee8,PTR_s_sharedManager_0114c320);
        uVar5 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar5,PTR_s_segments_0114dac0);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar7,PTR_s_contentVideoID_0114cef0);
        uVar9 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,PTR_s_objectForKey__0114b238,uVar9);
        lVar10 = _objc_retainAutoreleasedReturnValue();
        _objc_release(uVar9);
        _objc_release(uVar8);
        _objc_release(uVar5);
        if (lVar10 == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = _objc_msgSend(PTR_SBPlayerDecorationData_0114eef8,PTR_s_new_0114b030);
          _objc_msgSend(uVar5,PTR_s_setBarView__0114db60,param_3);
          _objc_msgSend(param_3,PTR_s_superview_0114c820);
          uVar8 = _objc_retainAutoreleasedReturnValue();
          _objc_msgSend(uVar8,PTR_s_bounds_0114b568);
          _objc_msgSend(in_d2,uVar5,PTR_s_setPlayerBarWidth__0114db68);
          _objc_release(uVar8);
          _objc_msgSend(uVar7,PTR_s_currentVideoTotalMediaTime_0114c9f8);
          _objc_msgSend(uVar5,PTR_s_setMediaDuration__0114db70);
          _objc_msgSend(uVar5,PTR_s_setSegments__0114db30,lVar10);
        }
        _objc_release(lVar10);
        _objc_release(uVar7);
      }
      _objc_release(uVar6);
    }
  }
  _objc_release(param_3);
  IVar11 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
  return IVar11;
}


