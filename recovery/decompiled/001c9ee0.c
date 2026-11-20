/* Decompiled from supplied 5.2.2 arm package. VA 0x1c9ee0. unregisterToast: */

/* Function Stack Size: 0x18 bytes */

void ToastManager::unregisterToast_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  
  _objc_retain(param_3);
  if (param_3 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x10);
    _objc_retain((&PTR_LAB_011b4ed8)[param_3 == 0] + (int)-(DAT_011b4ee8 ^ 0x386a0bb),uVar1);
    _objc_sync_enter();
    _objc_msgSend(*(undefined8 *)(param_1 + 0x10),PTR_s_removeObject__0114cad0,param_3);
    _objc_msgSend(param_1,PTR_s_updateAllToasts_0114c330);
    _objc_sync_exit(uVar1);
    _objc_release(uVar1);
  }
  _objc_release(param_3);
  return;
}


