/* Decompiled from supplied 5.2.2 arm package. VA 0x225900. currentPlaybackRate */

/* Function Stack Size: 0x10 bytes */

double YTPSpeedMaster::currentPlaybackRate(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  float fVar6;
  
  _objc_msgSend(*(undefined8 *)(param_1 + 0x58),PTR_s_parentViewController_0114ad68);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_activeVideo_0114c788);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_playbackRate_0114e6e8;
  uVar2 = FUN_00227594(uVar4,PTR_s_respondsToSelector__0114af58,PTR_s_playbackRate_0114e6e8);
  if (uVar2 == 0) {
    _objc_msgSend(uVar4,PTR_s_activePlaybackRateModel_0114e6f0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    fVar6 = (float)_objc_msgSend(uVar5,PTR_s_activeRate_0114e6f8);
    _objc_release(uVar5);
  }
  else {
    fVar6 = (float)_objc_msgSend((&PTR_LAB_011cefa0)[uVar2] + (int)-(DAT_011cefb0 ^ 0xe74c8c2e),
                                 uVar4,puVar1);
  }
  _objc_release(uVar4);
  _objc_release(uVar3);
  return (double)fVar6;
}


