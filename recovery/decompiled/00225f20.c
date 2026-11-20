/* Decompiled from supplied 5.2.2 arm package. VA 0x225f20. currentPlaybackRate */

/* Function Stack Size: 0x10 bytes */

double YTPSpeedMaster::currentPlaybackRate(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  float fVar6;
  double dVar7;
  
  _objc_msgSend(param_1,PTR_s_getPlayerIfAvailable_0114c838);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  if (lVar3 == 0) {
    dVar7 = 1.0;
  }
  else {
    _objc_msgSend(lVar3,PTR_s_activeVideo_0114c788);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_playbackRate_0114e6e8;
    uVar2 = FUN_00227844(uVar4,PTR_s_respondsToSelector__0114af58,PTR_s_playbackRate_0114e6e8);
    if (uVar2 == 0) {
      _objc_msgSend(uVar4,PTR_s_activePlaybackRateModel_0114e6f0);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      fVar6 = (float)_objc_msgSend(uVar5,PTR_s_activeRate_0114e6f8);
      _objc_release(uVar5);
    }
    else {
      fVar6 = (float)_objc_msgSend((&PTR_LAB_011cf030)[uVar2] +
                                   (int)-(uRam00000000011cf040 ^ 0x49ff9fb6),uVar4,puVar1);
    }
    dVar7 = (double)fVar6;
    _objc_release(uVar4);
  }
  _objc_release(lVar3);
  return dVar7;
}


