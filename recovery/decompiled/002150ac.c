/* Decompiled from supplied 5.2.2 arm package. VA 0x2150ac. globalSlimBarVisibilityChange */

/* Function Stack Size: 0x10 bytes */

void YTPSleepTimer::globalSlimBarVisibilityChange(ID param_1,SEL param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_delegate_0114b530);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_msgSend(uVar4,PTR_s_responderRoot_0114dc98);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_slimStatusBarDisplayStatusDidCha_0114e4c0;
  iVar2 = FUN_00219a94(uVar3,PTR_s_respondsToSelector__0114af58,
                       PTR_s_slimStatusBarDisplayStatusDidCha_0114e4c0);
  if (iVar2 != 0) {
    _objc_msgSend(uVar3,PTR_s_performSelector__0114b268,puVar1);
  }
  _objc_release(uVar3);
  _objc_release(uVar4);
  CallSupervisor(0x6055);
  return;
}


