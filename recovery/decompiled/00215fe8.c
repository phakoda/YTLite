/* Decompiled from supplied 5.2.2 arm package. VA 0x215fe8. removeTapHandlerOnBar: */

/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::removeTapHandlerOnBar_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  long lVar2;
  
  DAT_012281bc = 1;
  _objc_retain(param_3);
  if (param_3 != 0) {
    uVar1 = _objc_msgSend(param_3,PTR_s_class_0114ae88);
    lVar2 = _class_getInstanceVariable(uVar1,s__tapGestureRecognizer_011cb9f0);
    if (lVar2 != 0) {
      _objc_msgSend(param_3,PTR_s_setValue_forKey__0114b208,0,
                    &PTR____CFConstantStringClassReference_011cba30);
    }
  }
  _objc_release(param_3);
  CallSupervisor(0xbac3);
  return;
}


