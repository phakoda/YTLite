/* Decompiled from supplied 5.2.2 arm package. VA 0x135354. tableView:canEditRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

bool TabbarVC::tableView_canEditRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  long lVar3;
  long lVar4;
  bool bVar5;
  long lVar6;
  
  _objc_retain(param_4);
  puVar1 = PTR_s_section_0114af60;
  lVar3 = _objc_msgSend(param_4,PTR_s_section_0114af60);
  puVar2 = PTR_s_indexOfObject__0114b020;
  lVar6 = (long)_sections;
  lVar4 = _objc_msgSend(*(undefined8 *)(param_1 + lVar6),PTR_s_indexOfObject__0114b020,
                        *(undefined8 *)(param_1 + (long)_activeTabs));
  if (lVar3 == lVar4) {
    bVar5 = 1;
  }
  else {
    lVar3 = _objc_msgSend((&PTR_LAB_01190380)[lVar3 == lVar4] + (int)-(DAT_01190390 ^ 0xa61ca204),
                          param_4,puVar1);
    lVar4 = _objc_msgSend(*(undefined8 *)(param_1 + lVar6),puVar2,
                          *(undefined8 *)(param_1 + (long)_inactiveTabs));
    bVar5 = (bool)(lVar3 == lVar4);
  }
  _objc_release(param_4);
  return bVar5;
}


