/* Decompiled from supplied 5.2.2 arm package. VA 0x11a830. pushController:withTitle: */

/* Function Stack Size: 0x20 bytes */

void DVNTableViewController::pushController_withTitle_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  
  DAT_012272b0 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  puVar1 = PTR_s_parentViewController_0114ad68;
  _objc_msgSend(param_1,PTR_s_parentViewController_0114ad68);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_isKindOfClass__0114ad70;
  if (lVar4 == 0) {
    uVar5 = _objc_getClass((&PTR_LAB_0118d268)[lVar4 == 0] + (int)-(DAT_0118d278 ^ 0x7802c308),
                           s_YTWrapperFlatViewController_0118ba30);
    uVar5 = _objc_msgSend(uVar5,PTR_s_alloc_0114d2b0);
    _objc_msgSend(param_1,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar5 = _objc_msgSend(uVar5,PTR_s_initWithParentResponder__0114afb8,uVar7);
    _objc_release(uVar7);
    _objc_msgSend(uVar5,PTR_s_setTitle__0114afc0,param_4);
    _objc_msgSend(uVar5,PTR_s_setContent__0114afc8,param_3);
    _objc_msgSend(uVar5,PTR_s_headerViewController_0114afd8);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_updateHeaderWithButtonsToDisplay_0114afe0,
                  *(undefined8 *)PTR____NSArray0___01060670);
    _objc_release(uVar7);
    _objc_msgSend(param_1,PTR_s_navigationController_0114afe8);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_pushViewController_animated__0114aff0,uVar5,1);
    _objc_release(uVar7);
    _objc_release(uVar5);
    _objc_release(0);
    _objc_release(0);
    _objc_release(param_4);
    _objc_release(param_3);
    return;
  }
  uVar5 = _objc_getClass(s_YTWrapperSplitViewController_0118ba70);
  uVar3 = FUN_00127d10(lVar4,puVar2,uVar5);
  if (uVar3 == 0) {
    _objc_msgSend(lVar4,puVar1);
    lVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(lVar4);
                    /* WARNING: Could not recover jumptable at 0x0011ad68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_0118d2a0)[lVar6 == 0] + (int)-(uRam000000000118d2b0 ^ 0x460b5ae1)))();
    return;
  }
  uVar5 = _objc_retain((&PTR_LAB_0118d288)[uVar3] + (int)-(uRam000000000118d298 ^ 0x10c1ab32),lVar4)
  ;
  _objc_msgSend(uVar5,PTR_s_secondViewController_0114afb0);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0011adc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0118d2b8)[lVar4 == 0] + (int)-(DAT_0118d2c8 ^ 0x7572c77e)))();
  return;
}


