/* Decompiled from supplied 5.2.2 arm package. VA 0x221730. share */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::share(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  double in_d2;
  undefined8 in_d3;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar4 = _objc_alloc(PTR__OBJC_CLASS___UIActivityViewController_0114ede8);
  _objc_msgSend(param_1,PTR_s_fullImage_0114e630);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_arrayWithObjects_count__0114b600;
  local_70 = uVar5;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,&local_70,
                1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uVar4 = _objc_msgSend(uVar4,PTR_s_initWithActivityItems_applicatio_0114ce38,uVar6,0);
  _objc_release(uVar6);
  _objc_release(uVar5);
  local_80 = *(undefined8 *)PTR__UIActivityTypeAssignToContact_01060538;
  uStack_78 = *(undefined8 *)PTR__UIActivityTypePrint_01060540;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar2,&local_80,2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_setExcludedActivityTypes__0114ce40,uVar5);
  _objc_release(uVar5);
  puVar2 = PTR_s_popoverPresentationController_0114ce50;
  _objc_msgSend(uVar4,PTR_s_popoverPresentationController_0114ce50);
  lVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar7 != 0) {
    _objc_msgSend(param_1,PTR_s_view_0114b090);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puVar2);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_setSourceView__0114b8b8,uVar5);
    _objc_release(uVar6);
    _objc_release(uVar5);
    puVar3 = PTR_s_mainScreen_0114b768;
    _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,PTR_s_mainScreen_0114b768);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_bounds_0114b568;
    _objc_msgSend(uVar5,PTR_s_bounds_0114b568);
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,puVar3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar1);
    _objc_release(uVar5);
    _objc_msgSend(uVar4,puVar2);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(in_d2 * 0.5,in_d3,0,0,uVar5,PTR_s_setSourceRect__0114ce60);
    _objc_release(uVar5);
    _objc_msgSend(uVar4,puVar2);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_setPermittedArrowDirections__0114d0b8,0xf);
    _objc_release(uVar5);
  }
  _objc_msgSend(param_1,PTR_s_presentViewController_animated_c_0114b298,uVar4,1,0);
  _objc_release(uVar4);
  CallSupervisor(0x7a9a);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}


