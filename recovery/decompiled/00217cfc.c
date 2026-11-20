/* Decompiled from supplied 5.2.2 arm package. VA 0x217cfc. pausePlayback */

/* Function Stack Size: 0x10 bytes */

bool YTPSleepTimer::pausePlayback(ID param_1,SEL param_2)

{
  undefined *puVar1;
  int iVar2;
  bool bVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  DAT_012281dc = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_delegate_0114b530;
  _objc_msgSend(uVar4,PTR_s_delegate_0114b530);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_msgSend(uVar5,PTR_s_responderRoot_0114dc98);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_class_0114ae88);
  _NSStringFromClass();
  uVar6 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_0021a8fc(uVar6,PTR_s_hasPrefix__0114aea0,
                       &PTR____CFConstantStringClassReference_011cbe10);
  _objc_release(uVar6);
  if (iVar2 == 0) {
    bVar3 = 0;
  }
  else {
    _objc_msgSend(uVar4,PTR_s_appView_0114e498);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    puVar1 = PTR_s_pausePlayback_0114e548;
    bVar3 = FUN_0021a834(uVar7,PTR_s_respondsToSelector__0114af58,PTR_s_pausePlayback_0114e548);
    if (bVar3 != 0) {
      _objc_msgSend(uVar7,PTR_s_performSelector__0114b268,puVar1);
    }
    _objc_release(uVar7);
  }
  _objc_release(uVar4);
  _objc_release(uVar5);
  return bVar3;
}


