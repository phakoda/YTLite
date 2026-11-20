/* Decompiled from supplied 5.2.2 arm package. VA 0x23c52c. setProgress: */

/* Function Stack Size: 0x18 bytes */

void __thiscall PlayerToast::setProgress_(PlayerToast *this,ID param_1,SEL param_2,double param_3)

{
  undefined *puVar1;
  long lVar2;
  double dVar3;
  double in_d2;
  
  puVar1 = PTR_s_bounds_0114b568;
  lVar2 = (long)_toastProgress;
  _objc_msgSend(*(undefined8 *)(this + lVar2),PTR_s_bounds_0114b568);
  if (0.0 < in_d2) {
    dVar3 = 1.0;
    if (param_3 <= 1.0) {
      dVar3 = param_3;
    }
    if (dVar3 <= 0.0) {
      dVar3 = 0.0;
    }
    _objc_msgSend(PTR__OBJC_CLASS___CATransaction_0114ed20,PTR_s_begin_0114c468);
    _objc_msgSend(PTR__OBJC_CLASS___CATransaction_0114ed20,PTR_s_setDisableActions__0114e8d0,0);
    _objc_msgSend(DAT_00c4c2f0,PTR__OBJC_CLASS___CATransaction_0114ed20,
                  PTR_s_setAnimationDuration__0114c470);
    _objc_msgSend(*(undefined8 *)(this + lVar2),puVar1);
    _objc_msgSend(0,0,dVar3 * in_d2,*(undefined8 *)(this + _progressLayer),PTR_s_setFrame__0114b570)
    ;
    _objc_msgSend(PTR__OBJC_CLASS___CATransaction_0114ed20,PTR_s_commit_0114c478);
  }
  CallSupervisor(0xa550);
  return;
}


