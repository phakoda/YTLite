// Decompiled implementation evidence for DVNLongPressDelegate. Not compilable source.

// -[DVNLongPressDelegate isTouchInSpeedZone:], 0x1f21c0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f21c0. isTouchInSpeedZone: */

/* Function Stack Size: 0x20 bytes */

bool DVNLongPressDelegate::isTouchInSpeedZone_(ID param_1,SEL param_2,CGPoint param_3)

{
  bool bVar1;
  long lVar2;
  
  lVar2 = _objc_msgSend(param_3.field0_0x0,param_3.field1_0x8,param_1,@selector(mode));
  if (lVar2 != 0) {
    _objc_msgSend(param_1,@selector(view));
    lVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
                    /* WARNING: Could not recover jumptable at 0x001f22dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    bVar1 = (*(code *)((&PTR_LAB_011bd718)[lVar2 == 0] + (int)-(uRam00000000011bd728 ^ 0x8ec836a3)))
                      ();
    return bVar1;
  }
  return 0;
}



// -[DVNLongPressDelegate gestureRecognizer:shouldReceiveTouch:], 0x1f2444
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f2444. gestureRecognizer:shouldReceiveTouch: */

/* Function Stack Size: 0x20 bytes */

bool DVNLongPressDelegate::gestureRecognizer_shouldReceiveTouch_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 in_d1;
  
  puVar1 = @selector(view);
  _objc_retain(param_4);
  _objc_msgSend(param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar4 = _objc_msgSend(param_4,@selector(locationInView:),uVar3);
  _objc_release(param_4);
  _objc_release(uVar3);
  bVar2 = FUN_001f264c(uVar4,in_d1,param_1,@selector(isTouchInSpeedZone:));
  return bVar2;
}



// -[DVNLongPressDelegate view], 0x1f24dc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f24dc. view */

/* Function Stack Size: 0x10 bytes */

ID DVNLongPressDelegate::view(ID param_1,SEL param_2)

{
  ID IVar1;
  
  _objc_loadWeakRetained(param_1 + 8);
  IVar1 = _objc_autoreleaseReturnValue();
  return IVar1;
}



// -[DVNLongPressDelegate setView:], 0x1f24f4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f24f4. setView: */

/* Function Stack Size: 0x18 bytes */

void DVNLongPressDelegate::setView_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeWeak(param_1 + 8,param_3);
  CallSupervisor(0x8935);
  return;
}



// -[DVNLongPressDelegate mode], 0x1f2528
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f2528. mode */

/* Function Stack Size: 0x10 bytes */

long_long DVNLongPressDelegate::mode(ID param_1,SEL param_2)

{
  return *(long_long *)(param_1 + 0x10);
}



// -[DVNLongPressDelegate setMode:], 0x1f2530
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f2530. setMode: */

/* Function Stack Size: 0x18 bytes */

void DVNLongPressDelegate::setMode_(ID param_1,SEL param_2,long_long param_3)

{
  *(long_long *)(param_1 + 0x10) = param_3;
  CallSupervisor(0x2abf);
  return;
}



// -[DVNLongPressDelegate .cxx_destruct], 0x1f2550
/* Decompiled from supplied 5.2.2 arm package. VA 0x1f2550. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void DVNLongPressDelegate::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_destroyWeak(param_1 + 8);
  return;
}


