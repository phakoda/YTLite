/* Decompiled from supplied 5.2.2 arm package. VA 0x1e004. _configureMutedPlayerBar */

void _configureMutedPlayerBar(undefined8 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 uVar10;
  
  DAT_01225cd0 = 1;
  _objc_retain(param_1);
  uVar3 = FUN_0002267c(&PTR____CFConstantStringClassReference_01155880);
  if ((uVar3 != 0) &&
     (iVar4 = FUN_00022720((&PTR_LAB_011562c0)[uVar3] + (int)-(DAT_011562d0 ^ 0x7917ec0),
                           &PTR____CFConstantStringClassReference_01155840),
     puVar1 = PTR_s__viewControllerForAncestor_0114ade0, iVar4 != 0)) {
    _objc_msgSend(param_1,PTR_s__viewControllerForAncestor_0114ade0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    if (lRam0000000001225c90 == 0) {
      lRam0000000001225c90 =
           _objc_getClass((&PTR_LAB_011562f0)[lRam0000000001225c90 == 0] +
                          (int)-(uRam0000000001156300 ^ 0x6b8cbcf9),
                          s_YTInlineMutedPlaybackScrubberVie_01155700);
    }
    lVar9 = lRam0000000001225c90;
    _objc_retainAutorelease(lRam0000000001225c90);
    puVar2 = PTR_s_isKindOfClass__0114ad70;
    uVar3 = FUN_00022830(uVar5,PTR_s_isKindOfClass__0114ad70,lVar9);
    _objc_release(uVar5);
    if (uVar3 != 0) {
      _objc_msgSend((&PTR_LAB_01156310)[uVar3] + (int)-(uRam0000000001156320 ^ 0xdc766132),param_1,
                    puVar1);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      puVar1 = PTR_s_parentViewController_0114ad68;
      _objc_msgSend(uVar5,PTR_s_parentViewController_0114ad68);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      if (lRam0000000001225c98 == 0) {
        lRam0000000001225c98 =
             _objc_getClass((&PTR_LAB_01156328)[lRam0000000001225c98 == 0] +
                            (int)-(uRam0000000001156338 ^ 0x8c60b8ca),
                            s_YTInlineMutedPlaybackPlayerOverl_01155770);
      }
      lVar9 = lRam0000000001225c98;
      _objc_retainAutorelease(lRam0000000001225c98);
      uVar3 = FUN_000227e8(uVar6,puVar2,lVar9);
      _objc_release(uVar6);
      if (uVar3 != 0) {
        _objc_msgSend((&PTR_LAB_01156348)[uVar3] + (int)-(uRam0000000001156358 ^ 0x5a4016dd),uVar5,
                      puVar1);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        puVar1 = PTR_s_parentResponder_0114aef0;
        _objc_msgSend(uVar6,PTR_s_parentResponder_0114aef0);
        uVar7 = _objc_retainAutoreleasedReturnValue();
        if (lRam0000000001225ca0 == 0) {
          lRam0000000001225ca0 =
               _objc_getClass((&PTR_LAB_01156360)[lRam0000000001225ca0 == 0] +
                              (int)-(uRam0000000001156370 ^ 0xc40e5af6),
                              s_YTPlayerViewController_011556b0);
        }
        lVar9 = lRam0000000001225ca0;
        _objc_retainAutorelease(lRam0000000001225ca0);
        uVar3 = FUN_00022658(uVar7,puVar2,lVar9);
        _objc_release(uVar7);
        if (uVar3 != 0) {
          _objc_msgSend((&PTR_LAB_01156380)[uVar3] + (int)-(uRam0000000001156390 ^ 0x7f4db373),uVar6
                        ,puVar1);
          uVar7 = _objc_retainAutoreleasedReturnValue();
          uVar8 = _objc_msgSend(param_1,PTR_s_class_0114ae88);
          lVar9 = _class_getInstanceVariable(uVar8,s__playingProgress_01155670);
          if (lVar9 != 0) {
            _objc_msgSend(param_1,PTR_s_valueForKey__0114ae90,
                          &PTR____CFConstantStringClassReference_01155800);
            uVar8 = _objc_retainAutoreleasedReturnValue();
            puVar1 = PTR_s_segmentablePlayerBarEnabled_0114b2c8;
            uVar3 = FUN_000225d0(param_1,PTR_s_respondsToSelector__0114af58,
                                 PTR_s_segmentablePlayerBarEnabled_0114b2c8);
            puVar2 = PTR_SBPlayerDecorator_0114eb60;
            if (uVar3 == 0) {
              _objc_msgSend(uVar8,PTR_s_layer_0114ae60);
              uVar10 = _objc_retainAutoreleasedReturnValue();
              _objc_msgSend(puVar2,PTR_s_drawSegments_layer_playerVC__0114b2e0,param_1,uVar10,uVar7)
              ;
            }
            else {
              FUN_00022548((&PTR_LAB_011563b0)[uVar3] + (int)-(uRam00000000011563c0 ^ 0xf7960a36),
                           param_1,puVar1);
              puVar1 = PTR_SBPlayerDecorator_0114eb60;
              _objc_msgSend(param_1,PTR_s_segmentablePlayerBar_0114b2d0);
              uVar10 = _objc_retainAutoreleasedReturnValue();
              _objc_msgSend(puVar1,PTR_s_drawSegmentableSegments_playerBa_0114b2d8,param_1,uVar10,
                            uVar7);
            }
            _objc_release(uVar10);
            _objc_release(uVar8);
          }
          _objc_release(uVar7);
        }
        _objc_release(uVar6);
      }
      _objc_release(uVar5);
    }
  }
  (*(code *)PTR__objc_release_01061028)(param_1);
  return;
}


