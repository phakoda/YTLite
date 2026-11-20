/* Decompiled from supplied 5.2.2 arm package. VA 0x23e2e8. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void PlayerToast::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_volumeHUD,0);
  _objc_storeStrong(param_1 + (long)_progressLayer,0);
  _objc_storeStrong(param_1 + (long)_toastProgress,0);
  _objc_storeStrong(param_1 + (long)_toastSubLabel,0);
  _objc_storeStrong(param_1 + (long)_toastLabel,0);
  _objc_storeStrong(param_1 + (long)_toastImage,0);
  _objc_storeStrong(param_1 + (long)_toastView,0);
  _objc_storeStrong(param_1 + (long)_containerView,0);
  _objc_storeStrong(param_1 + (long)_activeConstraints,0);
  CallSupervisor(0x6362);
  return;
}


