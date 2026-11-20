/* Decompiled from supplied 5.2.2 arm package. VA 0x19d6c0. drawSegmentsDecorationView: */

/* Function Stack Size: 0x18 bytes */

void SBPlayerDecorator::drawSegmentsDecorationView_(ID param_1,SEL param_2,ID param_3)

{
  long lVar1;
  
  _objc_msgSend(param_1,PTR_s__decorationDataForBarView__0114db78);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  if (lVar1 != 0) {
    _objc_msgSend(param_1,PTR_s__drawSegmentsForData__0114db80,lVar1);
  }
  _objc_release(lVar1);
  CallSupervisor(0x9fa5);
  return;
}


