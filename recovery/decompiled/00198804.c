/* Decompiled from supplied 5.2.2 arm package. VA 0x198804. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void SBPlaybackController::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  _objc_destroyWeak(param_1 + 8);
  CallSupervisor(0x3b13);
  return;
}


