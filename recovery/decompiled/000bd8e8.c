/* Decompiled from supplied 5.2.2 arm package. VA 0xbd8e8. FUN_000bd8e8 */

void FUN_000bd8e8(void)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined **local_b8;
  undefined **ppuStack_b0;
  uint uStack_a4;
  undefined **local_a0;
  int iStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint uStack_7c;
  undefined **local_78;
  undefined **ppuStack_70;
  uint local_64;
  undefined **local_60;
  long local_58;
  
  local_58 = *(long *)PTR____stack_chk_guard_01060708;
  local_60 = &PTR_LAB_01182598;
  local_64 = (uint)(DAT_01226f2c == 0);
  local_78 = &PTR_LAB_011825b8;
  ppuStack_70 = &PTR_LAB_01175340;
  local_90 = &PTR_LAB_011825d8;
  ppuStack_88 = &PTR_LAB_01175340;
  local_a0 = &PTR_LAB_011825f0;
  local_b8 = &PTR_LAB_01175340;
  ppuStack_b0 = &PTR_LAB_01175340;
  DAT_01226f2c = 1;
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UINavigationController_0114ece8);
  uVar3 = _objc_alloc(PTR_TabbarVC_0114ecf0);
  uVar3 = _objc_msgSend(uVar3,PTR_s_initForSettings__0114c398,0);
  uVar2 = _objc_msgSend(uVar2,PTR_s_initWithRootViewController__0114c3a0,uVar3);
  _objc_release(uVar3);
  _objc_msgSend(uVar2,PTR_s_setModalPresentationStyle__0114b958,1);
  uStack_7c = (uint)(DAT_01226850 == 0);
  if (DAT_01226850 == 0) {
    DAT_01226850 = _objc_getClass(local_78[uStack_7c] + (int)-(DAT_011825c8 ^ 0x6e159670),
                                  s_YTDefaultTypeStyle_01171cb0);
  }
  _objc_retainAutorelease();
  uVar3 = _objc_alloc_init();
  puVar1 = PTR_s_ytSansFontOfSize_weight__0114c3a8;
  iStack_94 = FUN_000ebc9c(uVar3,PTR_s_respondsToSelector__0114af58,
                           PTR_s_ytSansFontOfSize_weight__0114c3a8);
  if (iStack_94 != 0) {
    uStack_e0 = *(undefined8 *)PTR__NSFontAttributeName_01060368;
    uStack_a4 = (uint)(DAT_01226850 == 0);
    if (DAT_01226850 == 0) {
      DAT_01226850 = _objc_getClass(local_a0[uStack_a4] + (int)-(uRam0000000001182600 ^ 0x4a58025c),
                                    s_YTDefaultTypeStyle_01171cb0);
    }
    _objc_retainAutorelease();
    uVar5 = _objc_alloc();
    _objc_msgSend(0x4034000000000000,*(undefined8 *)PTR__UIFontWeightBold_01060560,uVar5,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uStack_d8 = *(undefined8 *)PTR__NSForegroundColorAttributeName_01060370;
    uStack_d0 = uVar6;
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_labelColor_0114aff8);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uStack_c8 = uVar7;
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                  PTR_s_dictionaryWithObjects_forKeys_co_0114b420,&uStack_d0,&uStack_e0,2);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_navigationBar_0114b7a8);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_setTitleTextAttributes__0114c3b0,uVar8);
    _objc_release(uVar4);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
  }
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_delegate_0114b530);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_window_0114b3b0);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_rootViewController_0114b968);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,PTR_s_presentViewController_animated_c_0114b298,uVar2,1,0);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0x502f);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_58) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}


