/* Decompiled from supplied 5.2.2 arm package. VA 0x23decc. setupSubForStyle: */

/* Function Stack Size: 0x18 bytes */

void PlayerToast::setupSubForStyle_(ID param_1,SEL param_2,long_long param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  puVar1 = PTR_s_setAlpha__0114b698;
  uVar2 = 0;
  if (param_3 != 1) {
    uVar2 = 0x3ff0000000000000;
  }
  uVar3 = 0x3ff0000000000000;
  if (param_3 != 1) {
    uVar3 = 0;
  }
  _objc_msgSend(uVar2,*(undefined8 *)(param_1 + (long)_toastProgress),PTR_s_setAlpha__0114b698);
  _objc_msgSend(uVar3,*(undefined8 *)(param_1 + (long)_toastSubLabel),puVar1);
  CallSupervisor(0x1ad4);
  return;
}


