/* Decompiled from supplied 5.2.2 arm package. VA 0x10daf0. FUN_0010daf0 */

void FUN_0010daf0(undefined1 param_1 [16],undefined1 param_2 [16],double param_3,long param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 auStack_b0 [3];
  undefined **local_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **ppuStack_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR__objc_msgSend_0118b418;
  local_74 = (uint)(DAT_01227230 == 0);
  local_88 = &PTR_LAB_0118b438;
  ppuStack_80 = &PTR_LAB_011882f0;
  local_98 = &PTR_LAB_011882f0;
  DAT_01227230 = 1;
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIActivityViewController_0114ede8);
  puVar1 = PTR_s_arrayWithObjects_count__0114b600;
  auStack_b0[0] = *(undefined8 *)(param_4 + 0x20);
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,auStack_b0
                ,1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_msgSend(uVar2,PTR_s_initWithActivityItems_applicatio_0114ce38,uVar3,0);
  _objc_release(uVar3);
  uStack_c0 = *(undefined8 *)PTR__UIActivityTypeAssignToContact_01060538;
  uStack_b8 = *(undefined8 *)PTR__UIActivityTypePrint_01060540;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar1,&uStack_c0,2);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setExcludedActivityTypes__0114ce40,uVar3);
  _objc_release(uVar3);
  uVar3 = _NSClassFromString(&PTR____CFConstantStringClassReference_011882d0);
  _objc_msgSend(uVar3,PTR_s_topViewControllerForPresenting_0114ce48);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_popoverPresentationController_0114ce50;
  _objc_msgSend(uVar2,PTR_s_popoverPresentationController_0114ce50);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  uStack_8c = (uint)(lVar4 == 0);
  if (lVar4 != 0) {
    uVar6 = *(undefined8 *)(param_4 + 0x28);
    _objc_msgSend(local_88[uStack_8c] + (int)-(DAT_0118b448 ^ 0xcd5713b8),uVar2,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_setSourceView__0114b8b8,uVar6);
    _objc_release(uVar5);
    _objc_msgSend(*(undefined8 *)(param_4 + 0x28),PTR_s_bounds_0114b568);
    _objc_msgSend(uVar2,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_3 + -5.0,0,0x3ff0000000000000,0x3ff0000000000000,uVar5,
                  PTR_s_setSourceRect__0114ce60);
    _objc_release(uVar5);
    _objc_msgSend(uVar2,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_setPermittedArrowDirections__0114d0b8,1);
    _objc_release(uVar5);
  }
  _objc_msgSend(uVar3,PTR_s_presentViewController_animated_c_0114b298,uVar2,1,0);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0x52c8);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}


