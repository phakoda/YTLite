/* Decompiled from supplied 5.2.2 arm package. VA 0x118f70. searchBarCancelButtonClicked: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::searchBarCancelButtonClicked_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  
  puVar1 = PTR_s_setText__0114b388;
  _objc_retain(param_3);
  _objc_msgSend(param_3,puVar1,&cf___);
  FUN_00127190(param_3,PTR_s_resignFirstResponder_0114d1e0);
  _objc_release(param_3);
  _objc_msgSend(param_1,PTR_s__performSearch__0114d210,&cf___);
  CallSupervisor(0x2901);
  return;
}


