/* Decompiled from supplied 5.2.2 arm package. VA 0x1f1050. frameOfPresentedViewInContainerView */

/* Function Stack Size: 0x10 bytes */

CGRect PseudoDetentController::frameOfPresentedViewInContainerView(ID param_1,SEL param_2)

{
  undefined1 auVar1 [32];
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  double dVar5;
  undefined8 in_d2;
  double in_d3;
  
  _objc_msgSend(param_1,PTR_s_containerView_0114e1f0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_bounds_0114b568);
  _objc_release(uVar3);
  dVar5 = (double)_objc_msgSend(param_1,PTR_s_customHeight_0114e1f8);
  puVar2 = PTR_s_heightCalculator_0114e200;
  _objc_msgSend(param_1,PTR_s_heightCalculator_0114e200);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar4 != 0) {
    _objc_msgSend((&PTR_LAB_011bd630)[lVar4 == 0] + (int)-(DAT_011bd640 ^ 0x7820fee0),param_1,puVar2
                 );
    lVar4 = _objc_retainAutoreleasedReturnValue();
    dVar5 = (double)(**(code **)(lVar4 + 0x10))(in_d2,in_d3);
    _objc_release(lVar4);
  }
  auVar1._16_8_ = dVar5;
  auVar1._8_8_ = in_d2;
  auVar1._0_8_ = in_d3 - dVar5;
  auVar1._24_8_ = 0;
  return (CGRect)(auVar1 << 0x40);
}


