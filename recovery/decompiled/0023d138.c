/* Decompiled from supplied 5.2.2 arm package. VA 0x23d138. clearConstraints */

/* Function Stack Size: 0x10 bytes */

void PlayerToast::clearConstraints(ID param_1,SEL param_2)

{
  long lVar1;
  
  lVar1 = (long)_activeConstraints;
  _objc_msgSend(PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20,PTR_s_deactivateConstraints__0114e8f0,
                *(undefined8 *)(param_1 + lVar1));
  _objc_msgSend(*(undefined8 *)(param_1 + lVar1),PTR_s_removeAllObjects_0114b4e0);
  return;
}


