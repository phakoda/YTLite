/* Decompiled from supplied 5.2.2 arm package. VA 0xc2724. FUN_000c2724 */

void FUN_000c2724(long param_1)

{
  undefined *puVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined **local_d0;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  int iStack_a4;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint uStack_8c;
  undefined **local_88;
  uint uStack_7c;
  undefined **local_78;
  undefined **local_70;
  uint local_64;
  undefined **local_60;
  long local_58;
  
  local_58 = *(long *)PTR____stack_chk_guard_01060708;
  local_60 = &PTR__objc_msgSend_01182c28;
  local_64 = (uint)(DAT_01226fc8 == 0);
  local_78 = &PTR__objc_msgSend_01182c48;
  local_88 = &PTR_LAB_01182c60;
  local_70 = &PTR_LAB_01175340;
  local_a0 = &PTR_LAB_01182c80;
  ppuStack_98 = &PTR_LAB_01175340;
  local_b0 = &PTR_LAB_01182c98;
  local_c8 = &PTR_LAB_01175340;
  ppuStack_c0 = &PTR_LAB_01175340;
  local_d0 = &PTR_LAB_01175340;
  DAT_01226fc8 = 1;
  bVar2 = *(long *)(param_1 + 0x20) == 0;
  uStack_7c = (uint)bVar2;
  if (!bVar2) {
    uVar3 = _objc_alloc(PTR__OBJC_CLASS___UINavigationController_0114ece8);
    uVar4 = _objc_alloc(PTR_TranslatorVC_0114ed40);
    uVar4 = _objc_msgSend(uVar4,PTR_s_initWithText__0114c5d8,*(undefined8 *)(param_1 + 0x20));
    uVar3 = _objc_msgSend(uVar3,PTR_s_initWithRootViewController__0114c3a0,uVar4);
    _objc_release(uVar4);
    uStack_8c = (uint)(DAT_01226850 == 0);
    if (DAT_01226850 == 0) {
      DAT_01226850 = _objc_getClass(local_88[uStack_8c] + (int)-(uRam0000000001182c70 ^ 0x876e69bd),
                                    s_YTDefaultTypeStyle_011726a0);
    }
    _objc_retainAutorelease();
    uVar4 = _objc_alloc_init();
    puVar1 = PTR_s_ytSansFontOfSize_weight__0114c3a8;
    iStack_a4 = FUN_000ed79c(uVar4,PTR_s_respondsToSelector__0114af58,
                             PTR_s_ytSansFontOfSize_weight__0114c3a8);
    if (iStack_a4 != 0) {
      uStack_f0 = *(undefined8 *)PTR__NSFontAttributeName_01060368;
      uStack_b4 = (uint)(DAT_01226850 == 0);
      if (DAT_01226850 == 0) {
        DAT_01226850 = _objc_getClass(local_b0[uStack_b4] +
                                      (int)-(uRam0000000001182ca8 ^ 0xddabfd8b),
                                      s_YTDefaultTypeStyle_011726a0);
      }
      _objc_retainAutorelease();
      uVar9 = _objc_alloc();
      _objc_msgSend(0x4034000000000000,*(undefined8 *)PTR__UIFontWeightBold_01060560,uVar9,puVar1);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      uStack_e8 = *(undefined8 *)PTR__NSForegroundColorAttributeName_01060370;
      uStack_e0 = uVar5;
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_labelColor_0114aff8);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      uStack_d8 = uVar6;
      _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                    PTR_s_dictionaryWithObjects_forKeys_co_0114b420,&uStack_e0,&uStack_f0,2);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar3,PTR_s_navigationBar_0114b7a8);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar8,PTR_s_setTitleTextAttributes__0114c3b0,uVar7);
      _objc_release(uVar8);
      _objc_release(uVar7);
      _objc_release(uVar6);
      _objc_release(uVar5);
      _objc_release(uVar9);
    }
    puVar1 = PTR_DVNSheetPresenter_0114ed48;
    _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s__viewControllerForAncestor_0114ade0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(DAT_00c4c320,puVar1,PTR_s_presentViewController_fromViewCo_0114c5e0,uVar3,uVar9);
    _objc_release(uVar9);
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  CallSupervisor(0xf14c);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_58) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}


