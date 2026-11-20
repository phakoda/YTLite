/* Decompiled from supplied 5.2.2 arm package. VA 0x19d77c. drawSegmentsOnActiveDecorationView: */

/* Function Stack Size: 0x18 bytes */

void SBPlayerDecorator::drawSegmentsOnActiveDecorationView_(ID param_1,SEL param_2,ID param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  DAT_012278e0 = 1;
  _objc_retain(param_3);
  _objc_msgSend(param_1,PTR_s__decorationDataForBarView__0114db78,param_3);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  if (lVar1 != 0) {
    uVar2 = _objc_msgSend(param_3,PTR_s_class_0114ae88);
    lVar3 = _class_getInstanceVariable(uVar2,s__brandGradient_011abc9d);
    if (lVar3 != 0) {
      _objc_msgSend(param_3,PTR_s_valueForKey__0114ae90,
                    &PTR____CFConstantStringClassReference_011abcd0);
      lVar3 = _objc_retainAutoreleasedReturnValue();
      if (lVar3 != 0) {
        _objc_msgSend(lVar1,PTR_s_setBarView__0114db60,lVar3);
      }
      _objc_release(lVar3);
    }
    _objc_msgSend(param_1,PTR_s__drawSegmentsForData__0114db80,lVar1);
  }
  _objc_release(lVar1);
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}


