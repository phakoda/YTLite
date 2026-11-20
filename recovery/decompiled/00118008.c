/* Decompiled from supplied 5.2.2 arm package. VA 0x118008. viewWillAppear: */

/* Function Stack Size: 0x14 bytes */

void DVNTableViewController::viewWillAppear_(ID param_1,SEL param_2,bool param_3)

{
  ID local_30;
  undefined *puStack_28;
  
  puStack_28 = PTR_DVNTableViewController_0114f0a8;
  local_30 = param_1;
  _objc_msgSendSuper2(&local_30,PTR_s_viewWillAppear__0114d1c8,param_3);
  _objc_msgSend(param_1,PTR_s__removeSearchFieldCornerRadius__0114d1c0,
                *(undefined8 *)(param_1 + (long)_searchBar));
  return;
}


