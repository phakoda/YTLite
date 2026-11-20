/* Decompiled from supplied 5.2.2 arm package. VA 0x23fe18. removeFromController */

/* Function Stack Size: 0x10 bytes */

void CustomHUD::removeFromController(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(PTR__OBJC_CLASS___MPVolumeHUDController_0114f048,PTR_s_sharedInstance_0114c418);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_removeVolumeDisplay__0114e918,param_1);
  _objc_release(uVar1);
  CallSupervisor(0xb50f);
  return;
}


