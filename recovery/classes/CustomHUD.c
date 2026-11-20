// Decompiled implementation evidence for CustomHUD. Not compilable source.

// -[CustomHUD init], 0x23fcf8
/* Decompiled from supplied 5.2.2 arm package. VA 0x23fcf8. init */

/* Function Stack Size: 0x10 bytes */

ID CustomHUD::init(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID local_40;
  undefined *puStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011d2b60;
  puStack_38 = PTR_CustomHUD_0114f170;
  local_40 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_40,@selector(init));
  local_2c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    uVar2 = _objc_msgSend(PTR__OBJC_CLASS___MPVolumeController_0114f040,@selector(new));
    uVar3 = *(undefined8 *)(IVar1 + 8);
    *(undefined8 *)(IVar1 + 8) = uVar2;
    _objc_release(uVar3);
  }
  return IVar1;
}



// -[CustomHUD addToController], 0x23fdac
/* Decompiled from supplied 5.2.2 arm package. VA 0x23fdac. addToController */

/* Function Stack Size: 0x10 bytes */

void CustomHUD::addToController(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(PTR__OBJC_CLASS___MPVolumeHUDController_0114f048,@selector(sharedInstance));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(addVolumeDisplay:),param_1);
  _objc_release(uVar1);
  CallSupervisor(0xd0e1);
  return;
}



// -[CustomHUD removeFromController], 0x23fe18
/* Decompiled from supplied 5.2.2 arm package. VA 0x23fe18. removeFromController */

/* Function Stack Size: 0x10 bytes */

void CustomHUD::removeFromController(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(PTR__OBJC_CLASS___MPVolumeHUDController_0114f048,@selector(sharedInstance));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(removeVolumeDisplay:),param_1);
  _objc_release(uVar1);
  CallSupervisor(0xb50f);
  return;
}



// -[CustomHUD setVolumeLevel:], 0x23fe84
/* Decompiled from supplied 5.2.2 arm package. VA 0x23fe84. setVolumeLevel: */

/* Function Stack Size: 0x14 bytes */

void CustomHUD::setVolumeLevel_(ID param_1,SEL param_2,float param_3)

{
  _objc_msgSend(*(undefined8 *)(param_1 + 8),@selector(setVolumeValue:));
  CallSupervisor(0x5797);
  return;
}



// -[CustomHUD volumeLevel], 0x23febc
/* Decompiled from supplied 5.2.2 arm package. VA 0x23febc. volumeLevel */

/* Function Stack Size: 0x10 bytes */

float CustomHUD::volumeLevel(ID param_1,SEL param_2)

{
  float fVar1;
  
  fVar1 = (float)_objc_msgSend(*(undefined8 *)(param_1 + 8),@selector(volumeValue));
  return fVar1;
}



// -[CustomHUD windowSceneForVolumeDisplay], 0x23fecc
/* Decompiled from supplied 5.2.2 arm package. VA 0x23fecc. windowSceneForVolumeDisplay */

/* Function Stack Size: 0x10 bytes */

ID CustomHUD::windowSceneForVolumeDisplay(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(connectedScenes));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(anyObject));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  _objc_release(uVar1);
  IVar4 = _objc_autoreleaseReturnValue(uVar3);
  return IVar4;
}



// -[CustomHUD volumeAudioCategory], 0x23ff50
/* Decompiled from supplied 5.2.2 arm package. VA 0x23ff50. volumeAudioCategory */

/* Function Stack Size: 0x10 bytes */

ID CustomHUD::volumeAudioCategory(ID param_1,SEL param_2)

{
  ID IVar1;
  
  IVar1 = _objc_msgSend(*(undefined8 *)(param_1 + 8),@selector(volumeAudioCategory));
  return IVar1;
}



// -[CustomHUD controller], 0x23ff60
/* Decompiled from supplied 5.2.2 arm package. VA 0x23ff60. controller */

/* Function Stack Size: 0x10 bytes */

ID CustomHUD::controller(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 8);
}



// -[CustomHUD .cxx_destruct], 0x23ff68
/* Decompiled from supplied 5.2.2 arm package. VA 0x23ff68. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void CustomHUD::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 8,0);
  CallSupervisor(0x2242);
  return;
}


