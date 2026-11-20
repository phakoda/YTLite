/* Decompiled from supplied 5.2.2 arm package. VA 0x11a718. viewDidAppear: */

/* Function Stack Size: 0x14 bytes */

void DVNTableViewController::viewDidAppear_(ID param_1,SEL param_2,bool param_3)

{
  undefined *puVar1;
  long lVar2;
  undefined8 uVar3;
  ID local_50;
  undefined *puStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_0118d228;
  puStack_48 = PTR_DVNTableViewController_0114f0a8;
  local_50 = param_1;
  _objc_msgSendSuper2(&local_50,PTR_s_viewDidAppear__0114b138,param_3);
  puVar1 = PTR_s_pendingScrollCell_0114d2a0;
  _objc_msgSend(param_1,PTR_s_pendingScrollCell_0114d2a0);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  local_3c = (uint)(lVar2 == 0);
  if (lVar2 != 0) {
    _objc_msgSend(local_38[local_3c] + (int)-(DAT_0118d238 ^ 0x52c1e8fa),param_1,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,PTR_s_navigateToCell__0114d2a8,uVar3);
    _objc_release(uVar3);
    _objc_msgSend(param_1,PTR_s_setPendingScrollCell__0114d280,0);
  }
  CallSupervisor(0xeb1e);
  return;
}


