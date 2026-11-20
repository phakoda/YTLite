/* Decompiled from supplied 5.2.2 arm package. VA 0x1356e4. tableView:editingStyleForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

long_long TabbarVC::tableView_editingStyleForRowAtIndexPath_
                    (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  long lVar2;
  long lVar3;
  long_long lVar4;
  long lVar5;
  
  lVar2 = _objc_msgSend(param_4,PTR_s_section_0114af60);
  puVar1 = PTR_s_indexOfObject__0114b020;
  lVar5 = (long)_sections;
  lVar3 = _objc_msgSend(*(undefined8 *)(param_1 + lVar5),PTR_s_indexOfObject__0114b020,
                        *(undefined8 *)(param_1 + (long)_activeTabs));
  if (lVar2 == lVar3) {
    lVar4 = 1;
  }
  else {
    lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + lVar5),puVar1,
                          *(undefined8 *)(param_1 + (long)_inactiveTabs));
    lVar4 = (ulong)(lVar2 != 0) << 1;
  }
  return lVar4;
}


