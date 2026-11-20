/* Decompiled from supplied 5.2.2 arm package. VA 0x221680. hapticFeedback */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::hapticFeedback(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  uVar1 = _objc_alloc(PTR__OBJC_CLASS___UIImpactFeedbackGenerator_0114ec68);
  uVar1 = _objc_msgSend(uVar1,PTR_s_initWithStyle__0114b790,1);
  _objc_msgSend(uVar1,PTR_s_prepare_0114b798);
  _objc_msgSend(uVar1,PTR_s_impactOccurred_0114b918);
  _objc_release(uVar1);
  return;
}


