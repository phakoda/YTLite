/* Decompiled from supplied 5.2.2 arm package. VA 0x192b40. webView:didFailProvisionalNavigation:withError: */

/* Function Stack Size: 0x28 bytes */

void DVNSupportersVC::webView_didFailProvisionalNavigation_withError_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  puVar1 = PTR_s_stopAnimating_0114da48;
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar22 = *(undefined8 *)(param_1 + (long)_activityIndicator);
  _objc_retain(param_5);
  _objc_msgSend(uVar22,puVar1);
  uVar22 = _objc_alloc_init(PTR__OBJC_CLASS___UILabel_0114ec00);
  _objc_msgSend(param_5,PTR_s_localizedDescription_0114c618);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_5);
  _objc_msgSend(uVar22,PTR_s_setText__0114b388,uVar5);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_secondaryLabelColor_0114d0e8);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar22,PTR_s_setTextColor__0114b5d8,uVar5);
  _objc_release(uVar5);
  _objc_msgSend(uVar22,PTR_s_setTextAlignment__0114b5f8,1);
  _objc_msgSend(uVar22,PTR_s_setNumberOfLines__0114b5f0,0);
  _objc_msgSend(uVar22,PTR_s_setTranslatesAutoresizingMaskInt_0114b590,0);
  puVar1 = PTR_s_view_0114b090;
  _objc_msgSend(param_1,PTR_s_view_0114b090);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_addSubview__0114b0a8,uVar22);
  _objc_release(uVar5);
  puVar4 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  puVar2 = PTR_s_centerXAnchor_0114b628;
  _objc_msgSend(uVar22,PTR_s_centerXAnchor_0114b628);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,puVar2);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_constraintEqualToAnchor__0114b5a0;
  _objc_msgSend(uVar5,PTR_s_constraintEqualToAnchor__0114b5a0,uVar7);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_centerYAnchor_0114b7f8;
  local_88 = uVar8;
  _objc_msgSend(uVar22,PTR_s_centerYAnchor_0114b7f8);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puVar3);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,puVar2,uVar11);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_leadingAnchor_0114b5b8;
  local_80 = uVar12;
  _objc_msgSend(uVar22,PTR_s_leadingAnchor_0114b5b8);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar14,puVar2);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_constraintEqualToAnchor_constant_0114b630;
  _objc_msgSend(0x4040000000000000,uVar13,PTR_s_constraintEqualToAnchor_constant_0114b630,uVar15);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_trailingAnchor_0114b5c0;
  local_78 = uVar16;
  _objc_msgSend(uVar22,PTR_s_trailingAnchor_0114b5c0);
  uVar17 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar18 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar18,puVar2);
  uVar19 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0xc040000000000000,uVar17,puVar3,uVar19);
  uVar20 = _objc_retainAutoreleasedReturnValue();
  local_70 = uVar20;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,&local_88,
                4);
  uVar21 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar4,PTR_s_activateConstraints__0114b650,uVar21);
  _objc_release(uVar21);
  _objc_release(uVar20);
  _objc_release(uVar19);
  _objc_release(uVar18);
  _objc_release(uVar17);
  _objc_release(uVar16);
  _objc_release(uVar15);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar22);
  CallSupervisor(0xc93a);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}


