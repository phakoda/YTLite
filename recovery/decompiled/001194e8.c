/* Decompiled from supplied 5.2.2 arm package. VA 0x1194e8. _searchClearTapped: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::_searchClearTapped_(ID param_1,SEL param_2,ID param_3)

{
  long lVar1;
  
  lVar1 = (long)_searchBar;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar1),PTR_s_setText__0114b388,&cf___);
  FUN_00127458(*(undefined8 *)(param_1 + lVar1),PTR_s_resignFirstResponder_0114d1e0);
  _objc_msgSend(param_1,PTR_s__performSearch__0114d210,&cf___);
  _objc_msgSend(param_1,PTR_s__removeSearchFieldCornerRadius__0114d1c0,
                *(undefined8 *)(param_1 + lVar1));
  CallSupervisor(0xb727);
  return;
}


