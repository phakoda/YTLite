/* Decompiled from supplied 5.2.2 arm package. VA 0xc1994. FUN_000c1994 */

undefined1  [16] FUN_000c1994(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  
  puVar1 = PTR_s_absoluteString_0114c580;
  DAT_01226fa0 = 1;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_absoluteString_0114c580);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar3 = FUN_000ed448(uVar4,PTR_s_containsString__0114af08,
                       &PTR____CFConstantStringClassReference_01172520);
  _objc_release(uVar4);
  uVar4 = *(undefined8 *)(param_1 + 0x20);
  if (uVar3 == 0) {
    _objc_retain(uVar4);
  }
  else {
    _objc_msgSend((&PTR_LAB_01182b80)[uVar3] + (int)-(uRam0000000001182b90 ^ 0xa80ea97b),uVar4,
                  puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    lVar5 = _objc_msgSend(uVar4,PTR_s_rangeOfString__0114b670,
                          &PTR____CFConstantStringClassReference_01172520);
    _objc_release(uVar4);
    puVar2 = PTR__OBJC_CLASS___NSURL_0114eb78;
    if (lVar5 == 0x7fffffffffffffff) {
      uVar4 = 0;
    }
    else {
      _objc_msgSend(*(undefined8 *)(param_1 + 0x20),puVar1);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(*(undefined8 *)(param_1 + 0x20),puVar1);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,PTR_s_substringFromIndex__0114c5f0,lVar5);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,PTR_s_stringByReplacingOccurrencesOfSt_0114b2c0,uVar8,
                    &PTR____CFConstantStringClassReference_011724e0);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puVar2,PTR_s_URLWithString__0114b3d0,uVar9);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar9);
      _objc_release(uVar8);
      _objc_release(uVar7);
      _objc_release(uVar6);
    }
  }
  uVar6 = _objc_alloc_init(PTR_DVNImageViewController_0114ed38);
  puVar1 = PTR__OBJC_CLASS___UIImage_0114ebf8;
  _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,PTR_s_dataWithContentsOfURL__0114c598,uVar4);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_imageWithData__0114c5a0,uVar7);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_setFullImage__0114c5c8,uVar8);
  _objc_release(uVar8);
  _objc_release(uVar7);
  uVar7 = _objc_alloc(PTR__OBJC_CLASS___UINavigationController_0114ece8);
  uVar7 = _objc_msgSend(uVar7,PTR_s_initWithRootViewController__0114c3a0,uVar6);
  _objc_msgSend(uVar7,PTR_s_setModalPresentationStyle__0114b958,2);
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,PTR_s_delegate_0114b530);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,PTR_s_window_0114b3b0);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,PTR_s_rootViewController_0114b968);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_msgSend(uVar11,PTR_s_presentViewController_animated_c_0114b298,uVar7,1,0);
  _objc_release(uVar11);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar4);
  CallSupervisor(0x8518);
  return ZEXT816(0x1f);
}


