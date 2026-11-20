/* Decompiled from supplied 5.2.2 arm package. VA 0x1d85d0. tableView:willDisplayHeaderView:forSection: */

/* Function Stack Size: 0x28 bytes */

void SbWhitelistVC::tableView_willDisplayHeaderView_forSection_
               (ID param_1,SEL param_2,ID param_3,ID param_4,long_long param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long_long lVar4;
  long lVar5;
  undefined8 uVar6;
  
  lVar5 = *(long *)PTR____stack_chk_guard_01060708;
  DAT_01227dac = 1;
  _objc_retain(param_4);
  _objc_retain();
  puVar2 = PTR__OBJC_CLASS___UIFont_0114ec08;
  puVar1 = PTR_s_systemFontOfSize_weight__0114d330;
  uVar6 = *(undefined8 *)PTR__UIFontWeightLight_01060568;
  _objc_retain(param_3);
  _objc_msgSend(0x402c000000000000,uVar6,puVar2,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_textLabel_0114b8e0;
  _objc_msgSend(param_4,PTR_s_textLabel_0114b8e0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setFont__0114b5e8,uVar6);
  _objc_release(uVar3);
  _objc_release(uVar6);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_labelColor_0114aff8);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_4,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setTextColor__0114b5d8,uVar6);
  _objc_release(uVar3);
  _objc_release(uVar6);
  _objc_msgSend(param_1,PTR_s_tableView_titleForHeaderInSectio_0114d328,param_3,param_5);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(param_4,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setText__0114b388,uVar6);
  _objc_release(uVar3);
  _objc_release(uVar6);
  _objc_msgSend(param_4,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_setTextAlignment__0114b5f8,4);
  _objc_release(uVar6);
  _objc_msgSend(param_4,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_setNumberOfLines__0114b5f0,0);
  _objc_release(uVar6);
  lVar4 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),PTR_s_indexOfObject__0114b020,
                        *(undefined8 *)(param_1 + (long)_channels));
  if (lVar4 == param_5) {
    _objc_msgSend(param_4,PTR_s_viewWithTag__0114c708,1000);
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
                    /* WARNING: Could not recover jumptable at 0x001d8a50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR__objc_msgSend_011b9118)[lVar5 == 0] + (int)-(uRam00000000011b9128 ^ 0x144915c0)
              ))();
    return;
  }
  _objc_release((&PTR__objc_msgSend_011b9100)[lVar4 == param_5] + (int)-(DAT_011b9110 ^ 0x9e615779),
                param_4);
  _objc_release(param_4);
  CallSupervisor(0x8e68);
  if (*(long *)PTR____stack_chk_guard_01060708 == lVar5) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


