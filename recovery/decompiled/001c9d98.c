/* Decompiled from supplied 5.2.2 arm package. VA 0x1c9d98. registerToast: */

/* Function Stack Size: 0x18 bytes */

void ToastManager::registerToast_(ID param_1,SEL param_2,ID param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  _objc_retain(param_3);
  if (param_3 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x10);
    _objc_retain((&PTR_LAB_011b4ea0)[param_3 == 0] + (int)-(DAT_011b4eb0 ^ 0x8e0cc28e),uVar2);
    _objc_sync_enter();
    iVar1 = FUN_001ca548(*(undefined8 *)(param_1 + 0x10),PTR_s_containsObject__0114c848,param_3);
    if (iVar1 == 0) {
      _objc_msgSend(*(undefined8 *)(param_1 + 0x10),PTR_s_addObject__0114b3a0,param_3);
      _objc_msgSend(param_1,PTR_s_updateAllToasts_0114c330);
    }
    _objc_sync_exit(uVar2);
    _objc_release(uVar2);
  }
  _objc_release(param_3);
  CallSupervisor(0x37c6);
  return;
}


