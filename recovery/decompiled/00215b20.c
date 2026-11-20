/* Decompiled from supplied 5.2.2 arm package. VA 0x215b20. attachTapHandlerToBar: */

/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::attachTapHandlerToBar_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  
  DAT_012281b8 = 1;
  _objc_retain(param_3);
  if (param_3 != 0) {
    uVar2 = _objc_msgSend(param_3,PTR_s_class_0114ae88);
    lVar3 = _class_getInstanceVariable(uVar2,s__tapGestureRecognizer_011cb930);
    if (lVar3 != 0) {
      _objc_msgSend(param_3,PTR_s_valueForKey__0114ae90,
                    &PTR____CFConstantStringClassReference_011cb970);
      uVar2 = _objc_retainAutoreleasedReturnValue();
      uVar4 = _objc_alloc_init(PTR__OBJC_CLASS___UITapGestureRecognizer_0114ed98);
      _objc_release(uVar2);
      _objc_msgSend(uVar4,PTR_s_setNumberOfTapsRequired__0114e500,1);
      _objc_msgSend(param_3,PTR_s_setUserInteractionEnabled__0114b820,1);
      _objc_msgSend(param_3,PTR_s_addGestureRecognizer__0114c540,uVar4);
      _objc_msgSend(param_3,PTR_s_setValue_forKey__0114b208,uVar4,
                    &PTR____CFConstantStringClassReference_011cb970);
      puVar1 = PTR_s_onSlimBarTap__0114e508;
      _objc_msgSend(uVar4,PTR_s_removeTarget_action__0114e510,param_1,PTR_s_onSlimBarTap__0114e508);
      _objc_msgSend(uVar4,PTR_s_addTarget_action__0114b9f0,param_1,puVar1);
      _objc_release(uVar4);
    }
  }
  _objc_release(param_3);
  CallSupervisor(0x651a);
  return;
}


