/* Decompiled from supplied 5.2.2 arm package. VA 0x194914. initWithPlayer: */

/* Function Stack Size: 0x18 bytes */

ID SBPlaybackController::initWithPlayer_(ID param_1,SEL param_2,ID param_3)

{
  ID IVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID local_40;
  undefined *puStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR__objc_msgSend_011aaa18;
  _objc_retain(param_3);
  puStack_38 = PTR_SBPlaybackController_0114f0d8;
  local_40 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_40,PTR_s_init_0114d960);
  local_2c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    _objc_storeWeak(local_28[local_2c] + (int)-(DAT_011aaa28 ^ 0x8342a3ce),IVar1 + 8,param_3);
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableSet_0114eee0,PTR_s_set_0114da98);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uVar3 = *(undefined8 *)(IVar1 + 0x18);
    *(undefined8 *)(IVar1 + 0x18) = uVar2;
    _objc_release(uVar3);
    _objc_msgSend(IVar1,PTR_s_requestSbSegments_0114daa0);
  }
  _objc_release(param_3);
  return IVar1;
}


