/* Decompiled from supplied 5.2.2 arm package. VA 0x1b9608. gestureRecognizerShouldBegin: */

/* Function Stack Size: 0x18 bytes */

bool DVNHorizontalPanDelegate::gestureRecognizerShouldBegin_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined *puVar6;
  bool bVar7;
  double dVar8;
  double dVar9;
  double in_d1;
  
  DAT_01227ac0 = 1;
  uVar3 = _objc_retain(param_3);
  puVar1 = PTR_s_view_0114b090;
  _objc_msgSend(uVar3,PTR_s_view_0114b090);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar6 = PTR_s__viewControllerForAncestor_0114ade0;
  _objc_msgSend(uVar3,PTR_s__viewControllerForAncestor_0114ade0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar5 = _NSClassFromString(&PTR____CFConstantStringClassReference_011b3090);
  uVar2 = FUN_001b9d14(uVar4,PTR_s_isKindOfClass__0114ad70,uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  if (uVar2 != 0) {
    _objc_msgSend((&PTR_LAB_011b3120)[uVar2] + (int)-(uRam00000000011b3130 ^ 0xe96310ad),param_3,
                  puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,puVar6);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar3);
    puVar6 = PTR_s_videoFreeZoomOverlayController_0114dcb0;
    uVar2 = FUN_001b9bec(uVar4,PTR_s_respondsToSelector__0114af58,
                         PTR_s_videoFreeZoomOverlayController_0114dcb0);
    if (uVar2 != 0) {
      _objc_msgSend((&PTR_LAB_011b3138)[uVar2] + (int)-(DAT_011b3148 ^ 0xfbaa5f66),uVar4,puVar6);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      dVar9 = (double)_objc_msgSend(uVar3,PTR_s_minFreeZoomFactor_0114dcb8);
      dVar8 = (double)_objc_msgSend(uVar3,PTR_s_videoZoomFactor_0114c938);
      puVar6 = (&PTR_LAB_011b3150)[dVar9 < dVar8] + (int)-(uRam00000000011b3160 ^ 0xe9a32029);
      if (dVar9 < dVar8) {
        uVar2 = FUN_001b9d3c(uVar3,PTR_s_isSnappedToFillByDefault_0114dcc0);
        puVar6 = (&PTR_LAB_011b3168)[uVar2] + (int)-(uRam00000000011b3178 ^ 0x5a84bcad);
        if (uVar2 != 0) {
          _objc_release(puVar6,uVar3);
          _objc_release(uVar4);
          bVar7 = 0;
          goto LAB_001b9b58;
        }
      }
      _objc_release(puVar6,uVar3);
    }
    _objc_release(uVar4);
  }
  _objc_msgSend(param_3,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  dVar9 = (double)_objc_msgSend(param_3,PTR_s_velocityInView__0114c880,uVar3);
  _objc_release(uVar3);
  bVar7 = (bool)(ABS(in_d1) < ABS(dVar9));
LAB_001b9b58:
  _objc_release(param_3);
  return bVar7;
}


