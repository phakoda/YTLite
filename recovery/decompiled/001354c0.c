/* Decompiled from supplied 5.2.2 arm package. VA 0x1354c0. tableView:targetIndexPathForMoveFromRowAtIndexPath:toProposedIndexPath: */

/* Function Stack Size: 0x28 bytes */

ID TabbarVC::tableView_targetIndexPathForMoveFromRowAtIndexPath_toProposedIndexPath_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  ID IVar1;
  undefined *puVar2;
  long lVar3;
  long lVar4;
  
  _objc_retain(param_4);
  _objc_retain(param_5);
  puVar2 = PTR_s_section_0114af60;
  lVar3 = _objc_msgSend(param_4,PTR_s_section_0114af60);
  lVar4 = _objc_msgSend(param_5,puVar2);
  IVar1 = param_5;
  if (lVar3 != lVar4) {
    IVar1 = param_4;
  }
  _objc_retainAutoreleaseReturnValue(IVar1);
  _objc_release(param_5);
  _objc_release(param_4);
  return IVar1;
}


