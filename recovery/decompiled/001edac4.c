/* Decompiled from supplied 5.2.2 arm package. VA 0x1edac4. exportYtlSettings: */

/* Function Stack Size: 0x18 bytes */

void YTLUserDefaults::exportYtlSettings_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  double in_d2;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 auStack_c0 [3];
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **ppuStack_90;
  uint local_84;
  undefined **local_80;
  long local_78;
  
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  local_80 = &PTR_LAB_011bd210;
  local_84 = (uint)(DAT_01227ed0 == 0);
  local_98 = &PTR_LAB_011bd230;
  ppuStack_90 = &PTR_LAB_011bce10;
  local_a8 = &PTR_LAB_011bce10;
  DAT_01227ed0 = 1;
  _objc_retain(param_3);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_URLsForDirectory_inDomains__0114b248,5,1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_firstObject_0114b748);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(uVar4,PTR_s_URLByAppendingPathComponent__0114b258,
                &PTR____CFConstantStringClassReference_011bcdf0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_alloc(PTR__OBJC_CLASS___UIActivityViewController_0114ede8);
  puVar1 = PTR_s_arrayWithObjects_count__0114b600;
  auStack_c0[0] = uVar2;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,auStack_c0
                ,1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_msgSend(uVar3,PTR_s_initWithActivityItems_applicatio_0114ce38,uVar5,0);
  _objc_release(uVar5);
  uStack_d0 = *(undefined8 *)PTR__UIActivityTypeAssignToContact_01060538;
  uStack_c8 = *(undefined8 *)PTR__UIActivityTypePrint_01060540;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar1,&uStack_d0,2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setExcludedActivityTypes__0114ce40,uVar5);
  _objc_release(uVar5);
  uVar5 = _NSClassFromString(&PTR____CFConstantStringClassReference_011bcdb0);
  _objc_msgSend(uVar5,PTR_s_topViewControllerForPresenting_0114ce48);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_popoverPresentationController_0114ce50;
  _objc_msgSend(uVar3,PTR_s_popoverPresentationController_0114ce50);
  lVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  uStack_9c = (uint)(lVar6 == 0);
  if (lVar6 != 0) {
    _objc_msgSend(local_98[uStack_9c] + (int)-(uRam00000000011bd240 ^ 0x7638df57),uVar3,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_setSourceView__0114b8b8,param_3);
    _objc_release(uVar7);
    _objc_msgSend(param_3,PTR_s_bounds_0114b568);
    _objc_msgSend(uVar3,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(in_d2 + -5.0,0,0x3ff0000000000000,0x3ff0000000000000,uVar7,
                  PTR_s_setSourceRect__0114ce60);
    _objc_release(uVar7);
    _objc_msgSend(uVar3,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_setPermittedArrowDirections__0114d0b8,1);
    _objc_release(uVar7);
  }
  _objc_msgSend(uVar5,PTR_s_presentViewController_animated_c_0114b298,uVar3,1,0);
  _objc_release(uVar5);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(uVar4);
  _objc_release(param_3);
  CallSupervisor(0x3a38);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_78) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}


