/* Decompiled from supplied 5.2.2 arm package. VA 0x1b9e8c. FUN_001b9e8c */

void FUN_001b9e8c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
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
  undefined8 uVar23;
  undefined8 local_170;
  undefined8 *puStack_168;
  long *plStack_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  uint local_124;
  undefined **local_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined1 auStack_f8 [128];
  long local_78;
  
  puVar1 = PTR_s_sharedApplication_0114b528;
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  local_120 = &PTR_LAB_011b3e48;
  puStack_168 = (undefined8 *)0x0;
  local_170 = 0;
  uStack_158 = 0;
  plStack_160 = (long *)0x0;
  uStack_148 = 0;
  local_150 = 0;
  uStack_138 = 0;
  uStack_140 = 0;
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_connectedScenes_0114dcc8;
  _objc_msgSend();
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  lVar7 = _objc_msgSend(uVar6,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&local_170,auStack_f8,
                        0x10);
  puVar3 = PTR_s_activationState_0114dcd0;
  local_124 = (uint)(lVar7 == 0);
  if (lVar7 != 0) {
    if (*plStack_160 != *plStack_160) {
      _objc_enumerationMutation
                ((&PTR_LAB_011b3e70)[*plStack_160 == *plStack_160] +
                 (int)-(uRam00000000011b3e80 ^ 0x1ca9001f),uVar6);
    }
    lVar7 = _objc_msgSend(*puStack_168,puVar3);
                    /* WARNING: Could not recover jumptable at 0x001ba0e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011b3e90)[lVar7 == 0] + (int)-(uRam00000000011b3ea0 ^ 0xab2b9135)))();
    return;
  }
  _objc_release(local_120[local_124] + (int)-(DAT_011b3e58 ^ 0xb5d644b0),uVar6);
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,puVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_allObjects_0114cac0);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,PTR_s_firstObject_0114b748);
  lVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar8);
  _objc_release(uVar6);
  _objc_release(uVar5);
  if (lVar7 != 0) {
    uVar5 = _objc_alloc(PTR_ToastWindow_0114ef50);
    uVar6 = _objc_msgSend(uVar5,PTR_s_initWithWindowScene__0114dcd8,lVar7);
    uVar5 = DAT_01227ac8;
    DAT_01227ac8 = uVar6;
    _objc_release(uVar5);
    _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,PTR_s_mainScreen_0114b768);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_bounds_0114b568);
    _objc_msgSend(DAT_01227ac8,PTR_s_setFrame__0114b570);
    _objc_release(uVar5);
    uVar5 = _objc_alloc_init(PTR__OBJC_CLASS___UIViewController_0114ebd0);
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_clearColor_0114b680);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_view_0114b090;
    _objc_msgSend(uVar5,PTR_s_view_0114b090);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,PTR_s_setBackgroundColor__0114b550,uVar6);
    _objc_release(uVar8);
    _objc_release(uVar6);
    _objc_msgSend(uVar5,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_setTranslatesAutoresizingMaskInt_0114b590,0);
    _objc_release(uVar6);
    _objc_msgSend(DAT_01227ac8,PTR_s_setRootViewController__0114b780,uVar5);
    _objc_msgSend(DAT_01227ac8,PTR_s_setHidden__0114bfc0,0);
    _dispatch_async(PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_01062a20);
    puVar4 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
    _objc_msgSend(uVar5,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_topAnchor_0114b598;
    _objc_msgSend(uVar6,PTR_s_topAnchor_0114b598);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(DAT_01227ac8,puVar2);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_constraintEqualToAnchor__0114b5a0;
    _objc_msgSend(uVar8,PTR_s_constraintEqualToAnchor__0114b5a0,uVar9);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    uStack_118 = uVar10;
    _objc_msgSend(uVar5,puVar1);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    puVar3 = PTR_s_leadingAnchor_0114b5b8;
    _objc_msgSend(uVar11,PTR_s_leadingAnchor_0114b5b8);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(DAT_01227ac8,puVar3);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar12,puVar2,uVar13);
    uVar14 = _objc_retainAutoreleasedReturnValue();
    uStack_110 = uVar14;
    _objc_msgSend(uVar5,puVar1);
    uVar15 = _objc_retainAutoreleasedReturnValue();
    puVar3 = PTR_s_trailingAnchor_0114b5c0;
    _objc_msgSend(uVar15,PTR_s_trailingAnchor_0114b5c0);
    uVar16 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(DAT_01227ac8,puVar3);
    uVar17 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar16,puVar2,uVar17);
    uVar18 = _objc_retainAutoreleasedReturnValue();
    uStack_108 = uVar18;
    _objc_msgSend(uVar5,puVar1);
    uVar19 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_bottomAnchor_0114b5b0;
    _objc_msgSend(uVar19,PTR_s_bottomAnchor_0114b5b0);
    uVar20 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(DAT_01227ac8,puVar1);
    uVar21 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar20,puVar2,uVar21);
    uVar22 = _objc_retainAutoreleasedReturnValue();
    uStack_100 = uVar22;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  &uStack_118,4);
    uVar23 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar4,PTR_s_activateConstraints__0114b650,uVar23);
    _objc_release(uVar23);
    _objc_release(uVar22);
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
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(lVar7);
  }
  CallSupervisor(0x74cd);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_78) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}


