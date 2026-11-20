/* Decompiled from supplied 5.2.2 arm package. VA 0x22608c. playbackRateForPlayer: */

/* Function Stack Size: 0x18 bytes */

double YTPSpeedMaster::playbackRateForPlayer_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  float fVar5;
  
  _objc_retain(param_3);
  if (param_3 == 0) {
    _objc_msgSend(param_1,PTR_s_getPlayerIfAvailable_0114c838);
    param_3 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_msgSend(param_3,PTR_s_activeVideo_0114c788);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_playbackRate_0114e6e8;
  uVar2 = FUN_0022792c(uVar3,PTR_s_respondsToSelector__0114af58,PTR_s_playbackRate_0114e6e8);
  if (uVar2 == 0) {
    _objc_msgSend(uVar3,PTR_s_activePlaybackRateModel_0114e6f0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    fVar5 = (float)_objc_msgSend(uVar4,PTR_s_activeRate_0114e6f8);
    _objc_release(uVar4);
  }
  else {
    fVar5 = (float)_objc_msgSend((&PTR_LAB_011cf080)[uVar2] +
                                 (int)-(uRam00000000011cf090 ^ 0x56026800),uVar3,puVar1);
  }
  _objc_release(uVar3);
  _objc_release(param_3);
  return (double)fVar5;
}


