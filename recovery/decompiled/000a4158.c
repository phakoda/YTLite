/* Decompiled from supplied 5.2.2 arm package. VA 0xa4158. FUN_000a4158 */

void FUN_000a4158(undefined8 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  
  puVar2 = PTR_s_activeVideoPlayerOverlay_0114cb50;
  DAT_01226e04 = 1;
  _objc_msgSend(param_1,PTR_s_activeVideoPlayerOverlay_0114cb50);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226890 == 0) {
    DAT_01226890 = _objc_getClass((&PTR_LAB_01180468)[DAT_01226890 == 0] +
                                  (int)-(uRam0000000001180478 ^ 0x5338d20a),
                                  s_YTMainAppVideoPlayerOverlayViewC_0116d2d0);
  }
  lVar7 = DAT_01226890;
  _objc_retainAutorelease(DAT_01226890);
  puVar1 = PTR_s_isKindOfClass__0114ad70;
  uVar4 = FUN_000e5d6c(uVar5,PTR_s_isKindOfClass__0114ad70,lVar7);
  _objc_release(uVar5);
  if (uVar4 != 0) {
    _objc_msgSend((&PTR_LAB_01180488)[uVar4] + (int)-(uRam0000000001180498 ^ 0x38527669),param_1,
                  puVar2);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar4 = FUN_000e5d24(uVar5,PTR_s_respondsToSelector__0114af58,PTR_s_loopMode_0114cb58);
    if (uVar4 != 0) {
      uVar6 = _ytpInt((&PTR_LAB_011804a0)[uVar4] + (int)-(uRam00000000011804b0 ^ 0xaf09b6a8),
                      &PTR____CFConstantStringClassReference_0116d320);
      _objc_msgSend(uVar5,PTR_s_setLoopMode__0114c000,uVar6);
    }
    _objc_release(uVar5);
  }
  puVar3 = PTR_s_activeVideo_0114c788;
  _objc_msgSend(param_1,PTR_s_activeVideo_0114c788);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_delegate_0114b530;
  _objc_msgSend(uVar5,PTR_s_delegate_0114b530);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  if (lRam0000000001226900 == 0) {
    lRam0000000001226900 =
         _objc_getClass((&PTR_LAB_011804c8)[lRam0000000001226900 == 0] +
                        (int)-(uRam00000000011804d8 ^ 0xe4349ad6),
                        s_YTLocalPlaybackController_0116d270);
  }
  lVar7 = lRam0000000001226900;
  _objc_retainAutorelease(lRam0000000001226900);
  uVar4 = FUN_000e5bd4(uVar6,puVar1,lVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  if (uVar4 != 0) {
    _objc_msgSend((&PTR_LAB_011804e8)[uVar4] + (int)-(uRam00000000011804f8 ^ 0xeb9a0c76),param_1,
                  puVar3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar2);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    uVar4 = FUN_000e5cbc(uVar6,PTR_s_respondsToSelector__0114af58,PTR_s_loopingEnabled_0114cb60);
    if ((uVar4 != 0) &&
       (lVar7 = _ytpInt((&PTR_LAB_01180500)[uVar4] + (int)-(uRam0000000001180510 ^ 0xc41b1599),
                        &PTR____CFConstantStringClassReference_0116d320), lVar7 != 0)) {
      _objc_msgSend(uVar6,PTR_s_setLoopingEnabled__0114cb68,1);
    }
    _objc_release(uVar6);
  }
  _canRememberLoopMode = 1;
  return;
}


