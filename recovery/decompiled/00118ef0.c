/* Decompiled from supplied 5.2.2 arm package. VA 0x118ef0. searchBar:textDidChange: */

/* Function Stack Size: 0x20 bytes */

void DVNTableViewController::searchBar_textDidChange_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  
  puVar1 = PTR_s__removeSearchFieldCornerRadius__0114d1c0;
  _objc_retain(param_4);
  _objc_msgSend(param_1,puVar1,param_3);
  _objc_msgSend(param_1,PTR_s__performSearch__0114d210,param_4);
  _objc_release(param_4);
  CallSupervisor(0x1bfc);
  return;
}


