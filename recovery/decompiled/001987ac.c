/* Decompiled from supplied 5.2.2 arm package. VA 0x1987ac. dealloc */

/* Function Stack Size: 0x10 bytes */

void SBPlaybackController::dealloc(ID param_1,SEL param_2)

{
  ID local_30;
  undefined *puStack_28;
  
  _objc_msgSend(PTR__OBJC_CLASS___NSObject_0114ebc0,PTR_s_cancelPreviousPerformRequestsWit_0114db28,
                param_1);
  puStack_28 = PTR_SBPlaybackController_0114f0d8;
  local_30 = param_1;
  _objc_msgSendSuper2(&local_30,PTR_s_dealloc_0114d678);
  return;
}


