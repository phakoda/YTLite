/* Decompiled from supplied 5.2.2 arm package. VA 0x135540. tableView:moveRowAtIndexPath:toIndexPath: */

/* Function Stack Size: 0x28 bytes */

void TabbarVC::tableView_moveRowAtIndexPath_toIndexPath_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  undefined *puVar1;
  undefined8 uVar2;
  ulong uVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  
  _objc_retain(param_5);
  puVar1 = PTR_s_row_0114af70;
  lVar7 = (long)_activeTabs;
  uVar5 = *(undefined8 *)(param_1 + lVar7);
  uVar2 = _objc_retain(param_4);
  uVar2 = _objc_msgSend(uVar2,puVar1);
  _objc_msgSend(uVar5,PTR_s_objectAtIndexedSubscript__0114aeb0,uVar2);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar6 = *(undefined8 *)(param_1 + lVar7);
  uVar5 = _objc_msgSend(param_4,puVar1);
  _objc_release(param_4);
  _objc_msgSend(uVar6,PTR_s_removeObjectAtIndex__0114cdd0,uVar5);
  uVar3 = _objc_msgSend(param_5,puVar1);
  uVar4 = _objc_msgSend(*(undefined8 *)(param_1 + lVar7),PTR_s_count_0114b840);
  uVar5 = *(undefined8 *)(param_1 + lVar7);
  if (uVar3 < uVar4) {
    uVar6 = _objc_msgSend((&PTR_LAB_011903a0)[uVar3 < uVar4] + (int)-(DAT_011903b0 ^ 0xc8af6962),
                          param_5,puVar1);
    _objc_msgSend(uVar5,PTR_s_insertObject_atIndex__0114b028,uVar2,uVar6);
  }
  else {
    _objc_msgSend(uVar5,PTR_s_addObject__0114b3a0,uVar2);
  }
  _objc_msgSend(param_1,PTR_s_saveTabsOrder_0114d6d0);
  _objc_release(uVar2);
  _objc_release(param_5);
  CallSupervisor(0x3ad8);
  return;
}


