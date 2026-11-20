/* Decompiled from supplied 5.2.2 arm package. VA 0x135464. tableView:canMoveRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

bool TabbarVC::tableView_canMoveRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  long lVar1;
  long lVar2;
  
  lVar1 = _objc_msgSend(param_4,PTR_s_section_0114af60);
  lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),PTR_s_indexOfObject__0114b020,
                        *(undefined8 *)(param_1 + (long)_activeTabs));
  return (bool)(lVar1 == lVar2);
}


