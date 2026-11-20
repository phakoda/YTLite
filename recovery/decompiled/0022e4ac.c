/* Decompiled from supplied 5.2.2 arm package. VA 0x22e4ac. shareMedia: */

/* Function Stack Size: 0x18 bytes */

void YTLHelper::shareMedia_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  double in_d2;
  undefined8 in_d3;
  undefined *puStack_100;
  undefined8 uStack_f8;
  code *pcStack_f0;
  undefined *puStack_e8;
  ID IStack_e0;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  ID aIStack_c0 [2];
  ID local_b0;
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **ppuStack_90;
  uint local_84;
  undefined **local_80;
  long local_78;
  
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  local_80 = &PTR_LAB_011d16d0;
  local_84 = (uint)(DAT_012283d0 == 0);
  local_98 = &PTR__objc_msgSend_011d16f0;
  ppuStack_90 = &PTR__objc_msgSend_011d0fe0;
  local_a8 = &PTR__objc_msgSend_011d0fe0;
  DAT_012283d0 = 1;
  local_b0 = param_1;
  _objc_retain(param_3);
  uVar4 = _objc_alloc(PTR__OBJC_CLASS___UIActivityViewController_0114ede8);
  puVar2 = PTR_s_arrayWithObjects_count__0114b600;
  aIStack_c0[0] = param_3;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,aIStack_c0
                ,1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar4 = _objc_msgSend(uVar4,PTR_s_initWithActivityItems_applicatio_0114ce38,uVar5,0);
  _objc_release(uVar5);
  uStack_d0 = *(undefined8 *)PTR__UIActivityTypeAssignToContact_01060538;
  uStack_c8 = *(undefined8 *)PTR__UIActivityTypePrint_01060540;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar2,&uStack_d0,2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_setExcludedActivityTypes__0114ce40,uVar5);
  _objc_release(uVar5);
  puStack_100 = PTR___NSConcreteStackBlock_01060660;
  uStack_f8 = DAT_00c4c228;
  pcStack_f0 = FUN_0022e960;
  puStack_e8 = &UNK_01063200;
  IStack_e0 = local_b0;
  _objc_msgSend(uVar4,PTR_s_setCompletionWithItemsHandler__0114e790,&puStack_100);
  uVar5 = _NSClassFromString(&PTR____CFConstantStringClassReference_011d08a0);
  _objc_msgSend(uVar5,PTR_s_topViewControllerForPresenting_0114ce48);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_popoverPresentationController_0114ce50;
  _objc_msgSend(uVar4,PTR_s_popoverPresentationController_0114ce50);
  lVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  uStack_9c = (uint)(lVar6 == 0);
  if (lVar6 != 0) {
    _objc_msgSend(uVar5,PTR_s_view_0114b090);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puVar2);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,PTR_s_setSourceView__0114b8b8,uVar7);
    _objc_release(uVar8);
    _objc_release(uVar7);
    puVar3 = PTR_s_mainScreen_0114b768;
    _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,PTR_s_mainScreen_0114b768);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_bounds_0114b568;
    _objc_msgSend(uVar7,PTR_s_bounds_0114b568);
    _objc_release(uVar7);
    _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,puVar3);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puVar1);
    _objc_release(uVar7);
    _objc_msgSend(uVar4,puVar2);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(in_d2 * 0.5,in_d3,0,0,uVar7,PTR_s_setSourceRect__0114ce60);
    _objc_release(uVar7);
    _objc_msgSend(uVar4,puVar2);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_setPermittedArrowDirections__0114d0b8,0xf);
    _objc_release(uVar7);
  }
  _objc_msgSend(uVar5,PTR_s_presentViewController_animated_c_0114b298,uVar4,1,0);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(param_3);
  CallSupervisor(0xc038);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_78) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}


