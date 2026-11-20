/* Decompiled from supplied 5.2.2 arm package. VA 0xfe92c. FUN_000fe92c */

undefined1  [16] FUN_000fe92c(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar2 = _objc_alloc_init(PTR_DVNImageViewController_0114ed38);
  puVar1 = PTR__OBJC_CLASS___UIImage_0114ebf8;
  _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,PTR_s_dataWithContentsOfURL__0114c598,
                *(undefined8 *)(param_1 + 0x20));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_imageWithData__0114c5a0,uVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setFullImage__0114c5c8,uVar4);
  _objc_release(uVar4);
  _objc_release(uVar3);
  uVar3 = _objc_alloc(PTR__OBJC_CLASS___UINavigationController_0114ece8);
  uVar3 = _objc_msgSend(uVar3,PTR_s_initWithRootViewController__0114c3a0,uVar2);
  _objc_msgSend(uVar3,PTR_s_setModalPresentationStyle__0114b958,2);
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_delegate_0114b530);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_window_0114b3b0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_rootViewController_0114b968);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(uVar7,PTR_s_presentViewController_animated_c_0114b298,uVar3,1,0);
  _objc_release(uVar7);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0x76e);
  return ZEXT816(0x1f);
}


